from ttH.TauRoast.processing import BasicProcess, CombinedProcess

BasicProcess(
    name="ttH2Nonbb_125_train",
    fullname="t#bar{t}H(125) #rightarrow b#bar{b}",
    paths=[
        "ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p1_v1",
        "ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p2_v1",
        "ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p3_v1",
    ],
    # cross_section=0.5085 * (1 - 0.577),
    cross_section=0.2586,
    events=50 * 1000 * 1000,
    cutflow='signal'
)

BasicProcess(
    name="ttjets_sl_pow_train",
    fullname="t #bar{t} SL",
    paths=[
        "TTToSemilepton_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p1_v1",
        "TTToSemilepton_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p2_v1",
        "TTToSemilepton_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p3_v1",
    ],
    # cross_section=831.76 * wleptonic * (1 - wleptonic),
    cross_section=182 * 2,
    events=500 * 1000 * 1000,
    cutflow='training'
)

BasicProcess(
    name="ttjets_dl_pow_train",
    fullname="t #bar{t} FL",
    paths=[
        "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p1_v1",
        "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p2_v1",
        "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p3_v1",
    ],
    # cross_section=831.76 * wleptonic ** 2,
    cross_section=87.3,
    events=250 * 1000 * 1000,
    cutflow='training'
)

CombinedProcess(
    name="ttjets_pow_train",
    fullname="t#bar{t} (fakes)",
    limitname="ttjets",
    subprocesses=["ttjets_sl_pow_train", "ttjets_dl_pow_train"]
)

BasicProcess(
    name="ttjets_sl_pow_nominal",
    fullname="t #bar{t} SL",
    paths=[
        "TTToSemilepton_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p1_v1",
        "TTToSemilepton_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p2_v1",
        "TTToSemilepton_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p3_v1",
    ],
    # cross_section=831.76 * wleptonic * (1 - wleptonic),
    cross_section=182 * 2,
    events=500 * 1000 * 1000,
    cutflow='nominal'
)

BasicProcess(
    name="ttjets_dl_pow_nominal",
    fullname="t #bar{t} FL",
    paths=[
        "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p1_v1",
        "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p2_v1",
        "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_faster_v8_p3_v1",
    ],
    # cross_section=831.76 * wleptonic ** 2,
    cross_section=87.3,
    events=250 * 1000 * 1000,
    cutflow='nominal'
)

CombinedProcess(
    name="ttjets_pow_nominal",
    fullname="t#bar{t} (nominal)",
    limitname="ttjets",
    subprocesses=["ttjets_sl_pow_nominal", "ttjets_dl_pow_nominal"]
)

BasicProcess(
    name="WZ_train",
    fullname="W + Z",
    paths=["WZTo3LNu_TuneCUETP8M1_13TeV_powheg_pythia8_faster_v9_v1"],
    cross_section=4.102,
    events=250 * 1000 * 1000,
    cutflow='training'
)

BasicProcess(
    name="ttW_train",
    fullname="t#bar{t}W",
    limitname="TTW",
    paths=["TTWJetsToLNu_TuneCUETP8M1_13TeV_amcatnloFXFX_madspin_pythia8_faster_v9_v1"],
    cross_section=0.2043,
    events=250000 * 2000,
    cutflow='training'
)

BasicProcess(
    name="ttZ_train",
    fullname="t#bar{t}Z",
    limitname="TTZ",
    paths=["TTZToLLNuNu_M_10_TuneCUETP8M1_13TeV_amcatnlo_pythia8_faster_v9_v1"],
    cross_section=0.2529,
    events=249761 * 2000,
    cutflow='signal'
)
