# vim: ts=4:sw=4:et:sta
import logging
import math
import os
import yaml
import ROOT as r
import sys

r.gROOT.SetBatch()
r.gSystem.Load("libttHTauRoast")

try:
    from ROOT import roast
except:
    sys.stderr.write("Failed to import 'roast'!\n")
    sys.exit(1)

def train_mva(config, processes, module):
    cfg = config['analysis']['final mva']

    mvadir = config['paths']['mva output'].format(m='final mva')

    if not os.path.exists(mvadir):
        os.makedirs(mvadir)

    vars = []
    err = False
    for (name, type) in cfg['variables']:
        try:
            vars.append(roast.MVABase.Var(name, type))
        except:
            logging.error("undefined variable %s", name)
            err = True
    if err:
        sys.exit(1)

    mva = roast.MVABase(mvadir, vectorize(vars), module.Get(), 1)

    sig = get_process(cfg['signal'], processes)
    bkg = vectorize(
            map(lambda p: get_process(p, processes), cfg['background']),
            'roast::Process*')
    mva.CreateTrainingSample(sig, bkg)

    m = r.std.map('string,string')()
    for k, v in cfg['methods'].items():
        m[k] = v

    mva.TrainMVA(m)

def book_mva(config, processes, module):
    cfg = config['analysis']['final mva']
    mvadir = config['paths']['mva output'].format(m='final mva')

    vars = []
    err = False
    for (name, type) in cfg['variables']:
        try:
            vars.append(roast.MVABase.Var(name, type))
        except:
            logging.error("undefined variable %s", name)
            err = True

    for method, opts in cfg['methods'].items():
        mva = roast.MVABase(mvadir, vectorize(vars), module.Get(), 1)
        if mva.BookMVA(method):
            roast.register_mva('Final' + method, mva);

def print_mva_ranking(config):
    mvadir = config['paths']['mva output'].format(m='final mva')
    logfile = os.path.join(mvadir, 'tmva.log')

    first = True
    prefix = None

    with open(logfile) as f:
        for l in f.readlines():
            if 'Ranking result' in l:
                prefix = l.split()[1]
                if not first:
                    print
                else:
                    first = False
                print '# ' + prefix
            elif prefix:
                if l.split()[1] == prefix:
                    idx = l.index(':') + 2
                    print l[idx:-1]
                else:
                    prefix = None

def split_processes(config, ps):
    split_fct = {}

    # split signal by decay modes
    for p in get_signals(ps):
        cfg = config['processes'][p.GetShortName()]

        if 'split' not in cfg:
            continue

        for (mode, val) in cfg['split'].items():
            newname = p.GetShortName() + "_" + mode
            logging.info("creating new split process %s", newname)
            split_fct[newname] = roast.InclusiveSignalSplitter(val)

            splitp = roast.Process(p)
            splitp.SetShortName(newname)
            splitp.SetNiceName(p.GetNiceName() + " (" + mode + ")")
            ps.append(splitp)

            if p.GetShortName() in config['analysis']['process']:
                config['analysis']['process'].append(newname)
            # if p.GetShortName() in config['analysis']['plot']:
                # config['analysis']['plot'].append(newname)

    config['analysis']['split'] = split_fct

def combine_processes(config, ps):
    cfgs = filter(lambda (k, v): 'combine' in v, config['processes'].items())
    for (alias, cfg) in cfgs:
        to_combine = cfg['combine']
        res = roast.Process(get_process(to_combine[0], ps))

        for other in to_combine[1:]:
            res.Add(get_process(other, ps))

        res.SetShortName(alias)
        res.SetNiceName(cfg['niceName'])
        res.SetLabelForLegend(cfg['labelForLegend'])
        res.SetColor(cfg['color'])

        ps.append(res)

get_signals = lambda ps: filter(lambda p: p.IsSignal(), ps)
get_backgrounds = lambda ps: filter(lambda p: p.IsBackground(), ps)

def get_collisions(ps):
    res = filter(lambda p: p.IsCollisions(), ps)
    if len(res) != 1:
        if len(res) > 1:
            logging.critical("more than one collision process found")
        else:
            logging.critical("no collisions present")
        raise LookupError
    return res[0]

def get_process(name, processes):
    res = filter(lambda p: p.GetShortName() == name, processes)
    if len(res) != 1:
        if len(res) > 1:
            logging.critical("more than one process with name %s", name)
        else:
            logging.critical("no process with name %s found", name)
        raise LookupError
    return res[0]

def normalize_processes(config, processes):
    lumi = config['physics']['lumi']

    try:
        coll = get_collisions(processes)
        if coll.GetNOEanalyzed() != coll.GetNOEinNtuple():
            lumi *= coll.GetNOEanalyzed() / float(coll.GetNOEinNtuple())
        coll.GetCutFlow().RegisterCutFromLast("Lumi norm", 2, 1)
        coll.BuildNormalizedCutFlow()
    except:
        pass

    for p in processes:
        if p.IsCollisions():
            continue

        est_lumi = lumi * p.GetCrossSection() * p.GetBranchingRatio()
        if p.GetNOEinNtuple() == 0:
            scale = 0
        else:
            raw_events = p.GetNOEinDS() * p.GetNOEanalyzed() / float(p.GetNOEinNtuple())
            scale = est_lumi / raw_events

        p.ScaleHistograms(scale)
        p.GetCutFlow().RegisterCutFromLast("Lumi norm", 2, scale)
        p.BuildNormalizedCutFlow()

def print_cutflow(config, processes):
    procs = map(lambda n: get_process(n, processes), config['analysis']['plot'])
    cuts = map(lambda p: p.GetCutFlow().GetCuts(), procs)

    out = sys.stdout

    out.write(" " * 20)
    for p in procs:
        out.write("{0:^15}".format(p.GetShortName()))
    out.write("\n")

    for i in range(len(cuts[0])):
        out.write("{0:20}".format(cuts[0][i].name))
        for c in cuts:
            logging.debug("%s", c[i].name)
            out.write("{0:15}".format(c[i].passedSignalEvents))
        out.write("\n")

    bkg_sum = 0.
    for p in procs:
        if p.IsBackground():
            bkg_sum += p.GetCutFlow().GetCuts()[-1].passedSignalEvents

    out.write("{0:20}".format("s / sqrt{s + b}"))
    for p in procs:
        if p.IsSignal():
            count = p.GetCutFlow().GetCuts()[-1].passedSignalEvents
            sig = count / math.sqrt(count + bkg_sum)
            out.write("{0:15}".format(sig))
        else:
            out.write(" " * 15)
    out.write("\n")

    out.write(" " * 20)
    for p in procs:
        out.write("{0:^15}".format(p.GetShortName()))
    out.write("\n")

def vectorize(items, cls=None):
    """Create a vector of class `cls` and fill it with the object in the
    list `items`."""
    if cls is None:
        cls = type(items[0])
    res = r.std.vector(cls)()
    for i in items:
        res.push_back(i)
    return res

def save(items, name, file):
    """Save a list of objects to a `file` with the key `name`."""
    if not os.path.isdir(os.path.dirname(file)):
        os.makedirs(os.path.dirname(file))
    f = r.TFile(file, "RECREATE")
    f.WriteObject(vectorize(items, "roast::Process*"), name)
    f.Close()

def load_config(filename, basedir, overrides):
    config = yaml.load(open(filename))

    if overrides:
        for setting in overrides:
            try:
                (path, value) = setting.split("=", 1)
                obj = config
                keys = path.split('.')
                while len(keys) > 1 and keys[0] in obj:
                    obj = obj[keys.pop(0)]
                if len(keys) != 1:
                    raise KeyError
                obj[keys[0]] = value
            except ValueError:
                logging.error("cannot override path %s without a value", setting)
            except KeyError:
                logging.error("cannot override path %s", path)

    processconfig = yaml.load(open(os.path.join(basedir, config['processes'])))
    histogramconfig = yaml.load(open(os.path.join(basedir, config['histograms'])))

    channel = config['analysis']['channel']
    for (name, cfg) in histogramconfig.items():
        if 'channels' in cfg and channel not in cfg['channels']:
            del histogramconfig[name]

    config['processes'] = processconfig
    config['histograms'] = histogramconfig

    config['processes']['Collisions'] = config['processes']['Collisions'][channel]

    if 'root' in config['paths']:
        basedir = config['paths']['root']
        for (k, v) in config['paths'].items():
            if k == 'root':
                continue
            config['paths'][k] = v.replace('{root}', basedir)
    return config

def load(name, file):
    """Load an object with key `name` from `file`, which can either be a
    filename or ROOT file object."""
    if isinstance(file, r.TFile):
        f = file
    else:
        f = r.TFile(file)
    obj = r.std.vector("roast::Process*")()
    f.GetObject(name, obj)
    f.Close()
    items = []
    for o in obj:
        items.append(o)
    return items
