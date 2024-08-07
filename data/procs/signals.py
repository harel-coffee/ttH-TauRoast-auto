from ttH.TauRoast.processing import BasicProcess, CombinedProcess

# BasicProcess(
#     name="ttH2TT_125_amc",
#     fullname="t#bar{t}H(125) #rightarrow #tau_{h} #tau_{h}",
#     limitname="ttHTT125_amc",
#     paths=['ttH2TT_125', 'ttH2TT_125_ext1', 'ttH2TT_125_ext2', 'ttH2TT_125_ext3'],
#     cross_section=0.5085 * 6.32e-2,
#     events=8378353
#     # split: {hbb: 0, hcc: 1, hww: 2, hzz: 3, htt: 4, hgg: 5, hgluglu: 6, hzg: 7}
#     # split: {htt: 4}
# )

BasicProcess(
    name="ttH2TT_125_real_amc",
    fullname="t#bar{t}H(125) #rightarrow #tau_{h} #tau_{h} gen-match",
    paths=['ttH2TT_125', 'ttH2TT_125_ext1', 'ttH2TT_125_ext2', 'ttH2TT_125_ext3'],
    cross_section=0.5085 * 6.32e-2,
    events=8378353,
    additional_cuts=[('parentage', 'abs(taus[0].parentId()) == 25 and abs(taus[1].parentId()) == 25')]
    # split: {hbb: 0, hcc: 1, hww: 2, hzz: 3, htt: 4, hgg: 5, hgluglu: 6, hzg: 7}
    # split: {htt: 4}
)

BasicProcess(
    name="ttH2bb_125_amc",
    fullname="t#bar{t}H(125)",
    limitname="ttHbb125",
    paths=['ttHJetTobb_M125_13TeV_amcatnloFXFX_madspin_pythia8_ext3_v1'],
    cross_section=0.5085 * 0.577,
    events=9794226,
    cutflow='signal'
)

BasicProcess(
    name="ttH2Nonbb_125_amc",
    fullname="t#bar{t}H(125)",
    limitname="ttH2Nonbb125",
    paths=['ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_ext1_v1'],
    cross_section=0.2151,  # 0.5085 * (1 - 0.577),
    events=10045633,
    cutflow='signal',
    relativesys=[.025, 0.03, 0.02, 0.103, 0.07, 0.036]
)

BasicProcess(
    name="ttH2Nonbb_125_fake_amc",
    fullname="t#bar{t}H(125) fake",
    limitname="ttH2Nonbb125_fake",
    paths=['ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_ext1_v1'],
    cross_section=0.2151,  # 0.5085 * (1 - 0.577),
    events=10045633,
    cutflow='real fake'
)

BasicProcess(
    name="ttH2TT_125_amc",
    fullname="t#bar{t}H(125) #rightarrow b#bar{b}",
    limitname="ttH_htt",
    paths=['ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_ext1_v1'],
    cross_section=0.2151,  # 0.5085 * (1 - 0.577),
    events=10045633,
    cutflow='signal',
    additional_cuts=[
        ('process', 'abs(event.higgsDecay()) == 15')
    ]
)

BasicProcess(
    name="ttH2WW_125_amc",
    fullname="t#bar{t}H(125) #rightarrow b#bar{b}",
    limitname="ttH_hww",
    paths=['ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_ext1_v1'],
    cross_section=0.2151,  # 0.5085 * (1 - 0.577),
    events=10045633,
    cutflow='signal',
    additional_cuts=[
        ('process', 'abs(event.higgsDecay()) == 24')
    ]
)

BasicProcess(
    name="ttH2ZZ_125_amc",
    fullname="t#bar{t}H(125) #rightarrow b#bar{b}",
    limitname="ttH_hzz",
    paths=['ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_ext1_v1'],
    cross_section=0.2151,  # 0.5085 * (1 - 0.577),
    events=10045633,
    cutflow='signal',
    additional_cuts=[
        ('process', 'abs(event.higgsDecay()) == 23')
    ]
)

BasicProcess(
    name="ttH2TT_125_pow",
    fullname="t#bar{t}H(125) #rightarrow #tau_{h} #tau_{h}",
    limitname="ttHTT125",
    paths=['ttHToTT_M125_13TeV_powheg_pythia8_v1'],
    cross_section=0.5085 * 6.32e-2,
    events=2187600
)

BasicProcess(
    name="ttH2TT_125_real_pow",
    fullname="t#bar{t}H(125) #rightarrow #tau_{h} #tau_{h} gen-match",
    paths=['ttHToTT_M125_13TeV_powheg_pythia8_v1'],
    cross_section=0.5085 * 6.32e-2,
    events=2187600,
    additional_cuts=[
        ('parentage', 'abs(taus[0].parentId()) == 25 and abs(taus[1].parentId()) == 25'),
        ('id', 'abs(taus[0].match()) == 5 and abs(taus[1].match()) == 5')
    ]
)

BasicProcess(
    name="ttH2TT_125_realtaus_pow",
    fullname="t#bar{t}H(125) #rightarrow #tau_{h} #tau_{h} gen-match",
    paths=['ttHToTT_M125_13TeV_powheg_pythia8_v1'],
    cross_section=0.5085 * 6.32e-2,
    events=2187600,
    additional_cuts=[
        ('id', 'abs(taus[0].match()) == 5 and abs(taus[1].match()) == 5')
    ]
)

BasicProcess(
    name="ttH2Nonbb_125_real_pow",
    fullname="t#bar{t}H(125) #rightarrow #tau_{h} #tau_{h} gen-match",
    paths=['ttHToNonbb_M125_13TeV_powheg_pythia8_v1'],
    # cross_section=0.5085 * (1 - 0.577),
    cross_section=0.2151,
    events=3860872,
    additional_cuts=[
        (
            'parentage',
            '(abs(taus[0].parentId()) == 25 and abs(taus[1].parentId()) == 25) or ' +
            '(abs(taus[0].parentId()) == 24 and abs(taus[1].parentId()) == 24)'
        ),
        ('id', 'abs(taus[0].match()) == 5 and abs(taus[1].match()) == 5')
    ]
)

BasicProcess(
    name="ttH2Nonbb_125_realtaus_pow",
    fullname="t#bar{t}H(125) #rightarrow #tau_{h} #tau_{h} gen-match",
    paths=['ttHToNonbb_M125_13TeV_powheg_pythia8_v1'],
    # cross_section=0.5085 * (1 - 0.577),
    cross_section=0.2151,
    events=3860872,
    additional_cuts=[('id', 'abs(taus[0].match()) == 5 and abs(taus[1].match()) == 5')]
)

BasicProcess(
    name="ttH2bb_125_signal",
    fullname="t#bar{t}H(125) #rightarrow b#bar{b}",
    paths=['ttHTobb_M125_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_v1'],
    cross_section=0.5085 * 0.577,
    events=3845992,
    cutflow='signal'
)

BasicProcess(
    name="ttH2Nonbb_125_signal",
    fullname="t#bar{t}H(125) #rightarrow b#bar{b}",
    paths=['ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_v1'],
    # cross_section=0.5085 * (1 - 0.577),
    cross_section=0.2151,
    events=3981250,
    cutflow='signal'
)

BasicProcess(
    name="ttH2TT_125_signal",
    fullname="t#bar{t}H(125) #rightarrow #tau#tau",
    limitname="ttH_htt",
    paths=['ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_v1'],
    # cross_section=0.5085 * (1 - 0.577),
    cross_section=0.2151,
    events=3981250,
    cutflow='signal',
    additional_cuts=[
        ('process', 'abs(event.higgsDecay()) == 15')
    ]
)

BasicProcess(
    name="ttH2WW_125_signal",
    fullname="t#bar{t}H(125) #rightarrow WW",
    limitname="ttH_hww",
    paths=['ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_v1'],
    # cross_section=0.5085 * (1 - 0.577),
    cross_section=0.2151,
    events=3981250,
    cutflow='signal',
    additional_cuts=[
        ('process', 'abs(event.higgsDecay()) == 24')
    ]
)

BasicProcess(
    name="ttH2ZZ_125_signal",
    fullname="t#bar{t}H(125) #rightarrow ZZ",
    limitname="ttH_hzz",
    paths=['ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_v1'],
    # cross_section=0.5085 * (1 - 0.577),
    cross_section=0.2151,
    events=3981250,
    cutflow='signal',
    additional_cuts=[
        ('process', 'abs(event.higgsDecay()) == 23')
    ]
)

BasicProcess(
    name="ttH2bb_125_fake",
    fullname="t#bar{t}H(125) #rightarrow b#bar{b}",
    paths=['ttHTobb_M125_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_v1'],
    cross_section=0.5085 * 0.577,
    events=3845992,
    cutflow='fake'
)

BasicProcess(
    name="ttH2Nonbb_125_fake",
    fullname="t#bar{t}H(125) #rightarrow b#bar{b}",
    paths=['ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV_powheg_pythia8_v1'],
    # cross_section=0.5085 * (1 - 0.577),
    cross_section=0.2151,
    events=3981250,
    cutflow='fake'
)

CombinedProcess(
    name="ttH_125_signal",
    fullname="t#bar{t}H(125)",
    limitname="ttH125",
    subprocesses=["ttH2bb_125_signal", "ttH2Nonbb_125_signal"]
)

CombinedProcess(
    name="ttH_125_fake",
    fullname="t#bar{t}H(125)",
    subprocesses=["ttH2bb_125_fake", "ttH2Nonbb_125_fake"]
)

CombinedProcess(
    name="ttH_125",
    fullname="t#bar{t}H(125)",
    limitname="ttH125",
    subprocesses=["ttH_125_signal", "ttH_125_fake"]
)

CombinedProcess(
    name="ttH_125_amc",
    fullname="t#bar{t}H(125)",
    limitname="ttH125",
    subprocesses=["ttH2bb_125_amc", "ttH2Nonbb_125_amc"]
)

CombinedProcess(
    name="ttH_125_pow",
    fullname="t#bar{t}H(125)",
    limitname="ttH125",
    subprocesses=["ttH2bb_125_pow", "ttH2Nonbb_125_pow"]
)
