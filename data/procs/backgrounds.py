from ttH.TauRoast.processing import BasicProcess, CombinedProcess

BasicProcess(
    name="ttW",
    fullname="t#bar{t}W",
    limitname="TTW",
    paths=[
        "TTWJetsToLNu_TuneCUETP8M1_13TeV_amcatnloFXFX_madspin_pythia8_ext1_v3",
        "TTWJetsToLNu_TuneCUETP8M1_13TeV_amcatnloFXFX_madspin_pythia8_ext2_v1"
    ],
    cross_section=0.2043,
    events=2160168 + 3120397,
    cutflow='signal',
    relativesys=[.025, 0.03, 0.02, 0.103, 0.12, 0.04]
)

BasicProcess(
    name="ttZ",
    fullname="t#bar{t}Z",
    limitname="TTZ",
    paths=["TTZToLLNuNu_M_10_TuneCUETP8M1_13TeV_amcatnlo_pythia8_ext1_v1"],
    cross_section=0.2529,
    events=1992438,
    cutflow='signal',
    relativesys=[.025, 0.03, 0.02, 0.103, 0.11, 0.034]
)

BasicProcess(
    name="tttt",
    fullname="tttt",
    paths=["TTTT_TuneCUETP8M1_13TeV_amcatnlo_pythia8_v1"],
    cross_section=0.009103,
    events=250000,
    cutflow='signal'
)

BasicProcess(
    name="tZq",
    fullname="tZq",
    paths=["tZq_ll_4f_13TeV_amcatnlo_pythia8_ext1_v1"],
    cross_section=0.0758,
    events=14509520,
    cutflow='signal'
)

BasicProcess(
    name="wwds",
    fullname="WW Double Scattering",
    paths=["WW_DoubleScattering_13TeV_pythia8_v1"],
    cross_section=1.64,
    events=844954,
    cutflow='signal'
)

BasicProcess(
    name="wzz",
    fullname="WZZ",
    paths=["WZZ_TuneCUETP8M1_13TeV_amcatnlo_pythia8_v1"],
    cross_section=0.05565,
    events=246800,
    cutflow='signal'
)

BasicProcess(
    name="wwz",
    fullname="WWZ",
    paths=["WWZ_TuneCUETP8M1_13TeV_amcatnlo_pythia8_v1"],
    cross_section=0.165,
    events=250000,
    cutflow='signal'
)

BasicProcess(
    name="wwpp",
    fullname="WWpp",
    paths=["WpWpJJ_EWK_QCD_TuneCUETP8M1_13TeV_madgraph_pythia8_v1"],
    cross_section=0.03711,
    events=149681,
    cutflow='signal'
)

BasicProcess(
    name="zzz",
    fullname="ZZZ",
    paths=["ZZZ_TuneCUETP8M1_13TeV_amcatnlo_pythia8_v1"],
    cross_section=0.0140,
    events=249237,
    cutflow='signal'
)

BasicProcess(
    name="www",
    fullname="WWW",
    paths=["WWW_4F_TuneCUETP8M1_13TeV_amcatnlo_pythia8_v1"],
    cross_section=0.209,
    events=240000,
    cutflow='signal'
)

CombinedProcess(
    name="rares",
    fullname="Rares",
    limitname="Rares",
    subprocesses=["tttt", "tZq", "wzz", "wwz", "www", "zzz"],
    # subprocesses=["tttt", "tZq", "wwds", "wzz"]
    relativesys=[.025, 0.03, 0.02, 0.103, .5]
)

BasicProcess(
    name="st",
    fullname="t",
    paths=["ST_tW_top_5f_inclusiveDecays_13TeV_powheg_pythia8_TuneCUETP8M1_ext1_v1"],
    cross_section=35.6,
    events=6952830
)

BasicProcess(
    name="stbar",
    fullname="#bar{t}",
    paths=["ST_tW_antitop_5f_inclusiveDecays_13TeV_powheg_pythia8_TuneCUETP8M1_ext1_v1"],
    cross_section=35.6,
    events=6933094
)

BasicProcess(
    name="st_s",
    fullname="t s-channel",
    paths=["ST_s_channel_4f_leptonDecays_13TeV_amcatnlo_pythia8_TuneCUETP8M1_v1"],
    cross_section=3.75,
    events=1000000
)

CombinedProcess(
    name="singletop",
    fullname="single t/#bar{t}",
    limitname="singlet",
    subprocesses=["st", "stbar", "st_s"]
)

BasicProcess(
    name="dyjets_10_50",
    fullname="Z + jets M10-50",
    paths=["DYJetsToLL_M_10to50_TuneCUETP8M1_13TeV_madgraphMLM_pythia8_v1"],
    # cross_section=3 * 7545.03,
    cross_section=18610,
    events=35291566,
    cutflow='signal'
)

BasicProcess(
    name="dyjets_50",
    fullname="Z + jets M50+",
    paths=["DYJetsToLL_M_50_TuneCUETP8M1_13TeV_madgraphMLM_pythia8_ext1_v2"],
    cross_section=6025.2,
    events=49144274,
    cutflow='signal'
)

CombinedProcess(
    name="dyjets",
    fullname="Z + jets",
    subprocesses=["dyjets_10_50", "dyjets_50"]
)

BasicProcess(
    name="wjets",
    fullname="W + jets",
    paths=["WJetsToLNu_TuneCUETP8M1_13TeV_amcatnloFXFX_pythia8_v1"],
    cross_section=61526.7,
    events=24120319,
    cutflow='signal'
)

BasicProcess(
    name="ww",
    fullname="W + W",
    paths=["WWTo2L2Nu_13TeV_powheg_v1"],
    cross_section=10.481,
    events=1999000,
    cutflow='signal'
)

BasicProcess(
    name="wz",
    fullname="W + Z",
    paths=["WZTo3LNu_TuneCUETP8M1_13TeV_powheg_pythia8_v1"],
    cross_section=4.430,
    events=1993200,
    cutflow='signal'
)

BasicProcess(
    name="zz",
    fullname="Z + Z",
    paths=["ZZTo4L_13TeV_powheg_pythia8_v1"],
    cross_section=1.256,
    events=6669988,
    cutflow='signal'
)

CombinedProcess(
    name="diboson",
    fullname="ww, wz, zz",
    limitname="diboson",
    # subprocesses=["ww", "wwds", "wwpp", "wz", "zz"]
    subprocesses=["ww", "wz", "zz"]
)

CombinedProcess(
    name="ewk",
    fullname="EWK",
    limitname="EWK",
    subprocesses=["dyjets", "wjets", "diboson"],
    relativesys=[.025, 0.03, 0.02, 0.103, 1.]
)
