import math
import os
import ROOT as r

from collections import namedtuple

from ttH.TauRoast.heavy import calculate_weights

Config = namedtuple('Config', ['taus', 'leptons', 'generator'])
config = None

def setup(channel, generator):
    global config
    config = Config(taus=channel.lower().count("t"), leptons=channel.lower().count("l"), generator=generator)

def load_python():
    import imp
    from glob import glob

    from ttH.TauRoast.processing import Process

    datadir = os.path.join(os.environ["LOCALRT"], 'src', 'ttH', 'TauRoast', 'data')
    magic = os.path.join(datadir, 'plots', '*.py')
    for n, file in enumerate(glob(magic)):
        imp.load_source("plots{0}".format(n), file)
    magic = os.path.join(datadir, 'procs', '*.py')
    for n, file in enumerate(glob(magic)):
        imp.load_source("procs{0}".format(n), file)

    global config
    for p in Process.procs():
        if str(p).startswith('ttH') and str(p).endswith(config.generator):
            p.copy(lambda s: s.replace('_' + config.generator, ''))

def R(p4):
    return math.sqrt(p4.Eta()**2 + p4.Phi()**2)

def dR(one, two):
    return R(one.p4() - two.p4())

def btag(jet):
    return jet.csv() > 0.89

__mva = None
def mva():
    global __mva
    if __mva is None:
        from variation import principal
        if principal is None:
            return -666.
        __mva = principal
    return __mva.evaluate()

class Snippet(object):
    def __init__(self, code):
        self.__code = code

    def _execute(self, event, combo, locals=None, globals=None, systematics="NA", use_exec=True):
        if not locals:
            locals = {}
        if not globals:
            globals = {}
            Snippet.prepare_globals(globals, event, combo, systematics=systematics)
        if use_exec:
            exec self.__code in locals, globals
            if 'result' in globals:
                return globals['result']
        else:
            return eval(self.__code, globals, locals)

    @classmethod
    def prepare_globals(cls, globals, event, combo, systematics="NA", tagging=False):
        globals.update({
                'superslim': r.superslim,
                'event': event,
                'btag': btag,
                'dR': dR,
                'mva': mva,
                'r': R,
                'taus': combo.taus(),
                'leptons': combo.leptons(),
                'jets': combo.jets(systematics),
                'pv': event.pv(),
                'met': combo.met(systematics)
        })
        if tagging:
            globals.update({
                'tags': filter(btag, combo.jets(systematics)),
                'notags': [j for j in combo.jets(systematics) if not btag(j)]
            })
