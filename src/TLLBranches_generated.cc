// vim: ts=4:sw=4:et:sta
#include "../interface/TLLBranches.h"

using namespace roast;

void
tll::Branches::Clear()
{
    roast::Branches::Clear();

    // >>> Begin clear <<<
    J_Lepton1DeltaR->clear();
    J_Lepton2DeltaR->clear();
    J_TauDeltaR->clear();
    TLL_Lepton1Charge->clear();
    TLL_Lepton1CorrectedD0->clear();
    TLL_Lepton1CorrectedDZ->clear();
    TLL_Lepton1Eta->clear();
    TLL_Lepton1EventWeight->clear();
    TLL_Lepton1GenMatchDaughter0Id->clear();
    TLL_Lepton1GenMatchDaughter0Status->clear();
    TLL_Lepton1GenMatchDaughter1Id->clear();
    TLL_Lepton1GenMatchDaughter1Status->clear();
    TLL_Lepton1GenMatchGrandmother00Id->clear();
    TLL_Lepton1GenMatchGrandmother00Status->clear();
    TLL_Lepton1GenMatchGrandmother01Id->clear();
    TLL_Lepton1GenMatchGrandmother01Status->clear();
    TLL_Lepton1GenMatchGrandmother10Id->clear();
    TLL_Lepton1GenMatchGrandmother10Status->clear();
    TLL_Lepton1GenMatchGrandmother11Id->clear();
    TLL_Lepton1GenMatchGrandmother11Status->clear();
    TLL_Lepton1GenMatchId->clear();
    TLL_Lepton1GenMatchMother0Id->clear();
    TLL_Lepton1GenMatchMother0Status->clear();
    TLL_Lepton1GenMatchMother1Id->clear();
    TLL_Lepton1GenMatchMother1Status->clear();
    TLL_Lepton1GenMatchStatus->clear();
    TLL_Lepton1ImpactParameter->clear();
    TLL_Lepton1IsElectron->clear();
    TLL_Lepton1IsLoose->clear();
    TLL_Lepton1IsMuon->clear();
    TLL_Lepton1IsTight->clear();
    TLL_Lepton1Lepton2CosDeltaPhi->clear();
    TLL_Lepton1Lepton2DeltaR->clear();
    TLL_Lepton1Lepton2VisibleMass->clear();
    TLL_Lepton1Mt->clear();
    TLL_Lepton1Mt2->clear();
    TLL_Lepton1P->clear();
    TLL_Lepton1Phi->clear();
    TLL_Lepton1Pt->clear();
    TLL_Lepton1RelIso->clear();
    TLL_Lepton2Charge->clear();
    TLL_Lepton2CorrectedD0->clear();
    TLL_Lepton2CorrectedDZ->clear();
    TLL_Lepton2Eta->clear();
    TLL_Lepton2EventWeight->clear();
    TLL_Lepton2GenMatchDaughter0Id->clear();
    TLL_Lepton2GenMatchDaughter0Status->clear();
    TLL_Lepton2GenMatchDaughter1Id->clear();
    TLL_Lepton2GenMatchDaughter1Status->clear();
    TLL_Lepton2GenMatchGrandmother00Id->clear();
    TLL_Lepton2GenMatchGrandmother00Status->clear();
    TLL_Lepton2GenMatchGrandmother01Id->clear();
    TLL_Lepton2GenMatchGrandmother01Status->clear();
    TLL_Lepton2GenMatchGrandmother10Id->clear();
    TLL_Lepton2GenMatchGrandmother10Status->clear();
    TLL_Lepton2GenMatchGrandmother11Id->clear();
    TLL_Lepton2GenMatchGrandmother11Status->clear();
    TLL_Lepton2GenMatchId->clear();
    TLL_Lepton2GenMatchMother0Id->clear();
    TLL_Lepton2GenMatchMother0Status->clear();
    TLL_Lepton2GenMatchMother1Id->clear();
    TLL_Lepton2GenMatchMother1Status->clear();
    TLL_Lepton2GenMatchStatus->clear();
    TLL_Lepton2ImpactParameter->clear();
    TLL_Lepton2IsElectron->clear();
    TLL_Lepton2IsLoose->clear();
    TLL_Lepton2IsMuon->clear();
    TLL_Lepton2IsTight->clear();
    TLL_Lepton2Mt->clear();
    TLL_Lepton2Mt2->clear();
    TLL_Lepton2P->clear();
    TLL_Lepton2Phi->clear();
    TLL_Lepton2Pt->clear();
    TLL_Lepton2RelIso->clear();
    TLL_PassZMask->clear();
    TLL_PassZMask2->clear();
    TLL_TauCharge->clear();
    TLL_TauDecayMode->clear();
    TLL_TauEmFraction->clear();
    TLL_TauEta->clear();
    TLL_TauGenMatchDaughter0Id->clear();
    TLL_TauGenMatchDaughter0Status->clear();
    TLL_TauGenMatchDaughter1Id->clear();
    TLL_TauGenMatchDaughter1Status->clear();
    TLL_TauGenMatchGrandmother00Id->clear();
    TLL_TauGenMatchGrandmother00Status->clear();
    TLL_TauGenMatchGrandmother01Id->clear();
    TLL_TauGenMatchGrandmother01Status->clear();
    TLL_TauGenMatchGrandmother10Id->clear();
    TLL_TauGenMatchGrandmother10Status->clear();
    TLL_TauGenMatchGrandmother11Id->clear();
    TLL_TauGenMatchGrandmother11Status->clear();
    TLL_TauGenMatchId->clear();
    TLL_TauGenMatchMother0Id->clear();
    TLL_TauGenMatchMother0Status->clear();
    TLL_TauGenMatchMother1Id->clear();
    TLL_TauGenMatchMother1Status->clear();
    TLL_TauGenMatchStatus->clear();
    TLL_TauHPSagainstElectronDeadECAL->clear();
    TLL_TauHPSagainstElectronLoose->clear();
    TLL_TauHPSagainstElectronLooseMVA2->clear();
    TLL_TauHPSagainstElectronLooseMVA3->clear();
    TLL_TauHPSagainstElectronMVA->clear();
    TLL_TauHPSagainstElectronMVA2category->clear();
    TLL_TauHPSagainstElectronMVA2raw->clear();
    TLL_TauHPSagainstElectronMVA3category->clear();
    TLL_TauHPSagainstElectronMVA3raw->clear();
    TLL_TauHPSagainstElectronMedium->clear();
    TLL_TauHPSagainstElectronMediumMVA2->clear();
    TLL_TauHPSagainstElectronMediumMVA3->clear();
    TLL_TauHPSagainstElectronTight->clear();
    TLL_TauHPSagainstElectronTightMVA2->clear();
    TLL_TauHPSagainstElectronTightMVA3->clear();
    TLL_TauHPSagainstElectronVLooseMVA2->clear();
    TLL_TauHPSagainstElectronVTightMVA3->clear();
    TLL_TauHPSagainstMuonLoose->clear();
    TLL_TauHPSagainstMuonLoose2->clear();
    TLL_TauHPSagainstMuonMedium->clear();
    TLL_TauHPSagainstMuonMedium2->clear();
    TLL_TauHPSagainstMuonTight->clear();
    TLL_TauHPSagainstMuonTight2->clear();
    TLL_TauHPSbyCombinedIsolationDeltaBetaCorrRaw->clear();
    TLL_TauHPSbyCombinedIsolationDeltaBetaCorrRaw3Hits->clear();
    TLL_TauHPSbyIsolationMVA2raw->clear();
    TLL_TauHPSbyIsolationMVAraw->clear();
    TLL_TauHPSbyLooseCombinedIsolationDeltaBetaCorr->clear();
    TLL_TauHPSbyLooseCombinedIsolationDeltaBetaCorr3Hits->clear();
    TLL_TauHPSbyLooseIsolationMVA->clear();
    TLL_TauHPSbyLooseIsolationMVA2->clear();
    TLL_TauHPSbyMediumCombinedIsolationDeltaBetaCorr->clear();
    TLL_TauHPSbyMediumCombinedIsolationDeltaBetaCorr3Hits->clear();
    TLL_TauHPSbyMediumIsolationMVA->clear();
    TLL_TauHPSbyMediumIsolationMVA2->clear();
    TLL_TauHPSbyTightCombinedIsolationDeltaBetaCorr->clear();
    TLL_TauHPSbyTightCombinedIsolationDeltaBetaCorr3Hits->clear();
    TLL_TauHPSbyTightIsolationMVA->clear();
    TLL_TauHPSbyTightIsolationMVA2->clear();
    TLL_TauHPSbyVLooseCombinedIsolationDeltaBetaCorr->clear();
    TLL_TauHPSdecayModeFinding->clear();
    TLL_TauIsInTheCracks->clear();
    TLL_TauLTIpVtdxy->clear();
    TLL_TauLTIpVtdxyError->clear();
    TLL_TauLTIpVtdz->clear();
    TLL_TauLTIpVtdzError->clear();
    TLL_TauLTNormChiSqrd->clear();
    TLL_TauLTPt->clear();
    TLL_TauLTValidHits->clear();
    TLL_TauLTvalid->clear();
    TLL_TauLTvx->clear();
    TLL_TauLTvy->clear();
    TLL_TauLTvz->clear();
    TLL_TauLepton1CosDeltaPhi->clear();
    TLL_TauLepton1DeltaR->clear();
    TLL_TauLepton1METMass->clear();
    TLL_TauLepton1VisibleMass->clear();
    TLL_TauLepton2CosDeltaPhi->clear();
    TLL_TauLepton2DeltaR->clear();
    TLL_TauLepton2METMass->clear();
    TLL_TauLepton2VisibleMass->clear();
    TLL_TauMomentumRank->clear();
    TLL_TauNProngs->clear();
    TLL_TauNSignalGammas->clear();
    TLL_TauNSignalNeutrals->clear();
    TLL_TauP->clear();
    TLL_TauPhi->clear();
    TLL_TauPt->clear();
    TLL_TriggerEventWeight->clear();
    // >>> End clear <<<
}

void
tll::Branches::Delete()
{
    roast::Branches::Delete();

    // >>> Begin delete <<<
    delete J_Lepton1DeltaR;
    delete J_Lepton2DeltaR;
    delete J_TauDeltaR;
    delete TLL_Lepton1Charge;
    delete TLL_Lepton1CorrectedD0;
    delete TLL_Lepton1CorrectedDZ;
    delete TLL_Lepton1Eta;
    delete TLL_Lepton1EventWeight;
    delete TLL_Lepton1GenMatchDaughter0Id;
    delete TLL_Lepton1GenMatchDaughter0Status;
    delete TLL_Lepton1GenMatchDaughter1Id;
    delete TLL_Lepton1GenMatchDaughter1Status;
    delete TLL_Lepton1GenMatchGrandmother00Id;
    delete TLL_Lepton1GenMatchGrandmother00Status;
    delete TLL_Lepton1GenMatchGrandmother01Id;
    delete TLL_Lepton1GenMatchGrandmother01Status;
    delete TLL_Lepton1GenMatchGrandmother10Id;
    delete TLL_Lepton1GenMatchGrandmother10Status;
    delete TLL_Lepton1GenMatchGrandmother11Id;
    delete TLL_Lepton1GenMatchGrandmother11Status;
    delete TLL_Lepton1GenMatchId;
    delete TLL_Lepton1GenMatchMother0Id;
    delete TLL_Lepton1GenMatchMother0Status;
    delete TLL_Lepton1GenMatchMother1Id;
    delete TLL_Lepton1GenMatchMother1Status;
    delete TLL_Lepton1GenMatchStatus;
    delete TLL_Lepton1ImpactParameter;
    delete TLL_Lepton1IsElectron;
    delete TLL_Lepton1IsLoose;
    delete TLL_Lepton1IsMuon;
    delete TLL_Lepton1IsTight;
    delete TLL_Lepton1Lepton2CosDeltaPhi;
    delete TLL_Lepton1Lepton2DeltaR;
    delete TLL_Lepton1Lepton2VisibleMass;
    delete TLL_Lepton1Mt;
    delete TLL_Lepton1Mt2;
    delete TLL_Lepton1P;
    delete TLL_Lepton1Phi;
    delete TLL_Lepton1Pt;
    delete TLL_Lepton1RelIso;
    delete TLL_Lepton2Charge;
    delete TLL_Lepton2CorrectedD0;
    delete TLL_Lepton2CorrectedDZ;
    delete TLL_Lepton2Eta;
    delete TLL_Lepton2EventWeight;
    delete TLL_Lepton2GenMatchDaughter0Id;
    delete TLL_Lepton2GenMatchDaughter0Status;
    delete TLL_Lepton2GenMatchDaughter1Id;
    delete TLL_Lepton2GenMatchDaughter1Status;
    delete TLL_Lepton2GenMatchGrandmother00Id;
    delete TLL_Lepton2GenMatchGrandmother00Status;
    delete TLL_Lepton2GenMatchGrandmother01Id;
    delete TLL_Lepton2GenMatchGrandmother01Status;
    delete TLL_Lepton2GenMatchGrandmother10Id;
    delete TLL_Lepton2GenMatchGrandmother10Status;
    delete TLL_Lepton2GenMatchGrandmother11Id;
    delete TLL_Lepton2GenMatchGrandmother11Status;
    delete TLL_Lepton2GenMatchId;
    delete TLL_Lepton2GenMatchMother0Id;
    delete TLL_Lepton2GenMatchMother0Status;
    delete TLL_Lepton2GenMatchMother1Id;
    delete TLL_Lepton2GenMatchMother1Status;
    delete TLL_Lepton2GenMatchStatus;
    delete TLL_Lepton2ImpactParameter;
    delete TLL_Lepton2IsElectron;
    delete TLL_Lepton2IsLoose;
    delete TLL_Lepton2IsMuon;
    delete TLL_Lepton2IsTight;
    delete TLL_Lepton2Mt;
    delete TLL_Lepton2Mt2;
    delete TLL_Lepton2P;
    delete TLL_Lepton2Phi;
    delete TLL_Lepton2Pt;
    delete TLL_Lepton2RelIso;
    delete TLL_PassZMask;
    delete TLL_PassZMask2;
    delete TLL_TauCharge;
    delete TLL_TauDecayMode;
    delete TLL_TauEmFraction;
    delete TLL_TauEta;
    delete TLL_TauGenMatchDaughter0Id;
    delete TLL_TauGenMatchDaughter0Status;
    delete TLL_TauGenMatchDaughter1Id;
    delete TLL_TauGenMatchDaughter1Status;
    delete TLL_TauGenMatchGrandmother00Id;
    delete TLL_TauGenMatchGrandmother00Status;
    delete TLL_TauGenMatchGrandmother01Id;
    delete TLL_TauGenMatchGrandmother01Status;
    delete TLL_TauGenMatchGrandmother10Id;
    delete TLL_TauGenMatchGrandmother10Status;
    delete TLL_TauGenMatchGrandmother11Id;
    delete TLL_TauGenMatchGrandmother11Status;
    delete TLL_TauGenMatchId;
    delete TLL_TauGenMatchMother0Id;
    delete TLL_TauGenMatchMother0Status;
    delete TLL_TauGenMatchMother1Id;
    delete TLL_TauGenMatchMother1Status;
    delete TLL_TauGenMatchStatus;
    delete TLL_TauHPSagainstElectronDeadECAL;
    delete TLL_TauHPSagainstElectronLoose;
    delete TLL_TauHPSagainstElectronLooseMVA2;
    delete TLL_TauHPSagainstElectronLooseMVA3;
    delete TLL_TauHPSagainstElectronMVA;
    delete TLL_TauHPSagainstElectronMVA2category;
    delete TLL_TauHPSagainstElectronMVA2raw;
    delete TLL_TauHPSagainstElectronMVA3category;
    delete TLL_TauHPSagainstElectronMVA3raw;
    delete TLL_TauHPSagainstElectronMedium;
    delete TLL_TauHPSagainstElectronMediumMVA2;
    delete TLL_TauHPSagainstElectronMediumMVA3;
    delete TLL_TauHPSagainstElectronTight;
    delete TLL_TauHPSagainstElectronTightMVA2;
    delete TLL_TauHPSagainstElectronTightMVA3;
    delete TLL_TauHPSagainstElectronVLooseMVA2;
    delete TLL_TauHPSagainstElectronVTightMVA3;
    delete TLL_TauHPSagainstMuonLoose;
    delete TLL_TauHPSagainstMuonLoose2;
    delete TLL_TauHPSagainstMuonMedium;
    delete TLL_TauHPSagainstMuonMedium2;
    delete TLL_TauHPSagainstMuonTight;
    delete TLL_TauHPSagainstMuonTight2;
    delete TLL_TauHPSbyCombinedIsolationDeltaBetaCorrRaw;
    delete TLL_TauHPSbyCombinedIsolationDeltaBetaCorrRaw3Hits;
    delete TLL_TauHPSbyIsolationMVA2raw;
    delete TLL_TauHPSbyIsolationMVAraw;
    delete TLL_TauHPSbyLooseCombinedIsolationDeltaBetaCorr;
    delete TLL_TauHPSbyLooseCombinedIsolationDeltaBetaCorr3Hits;
    delete TLL_TauHPSbyLooseIsolationMVA;
    delete TLL_TauHPSbyLooseIsolationMVA2;
    delete TLL_TauHPSbyMediumCombinedIsolationDeltaBetaCorr;
    delete TLL_TauHPSbyMediumCombinedIsolationDeltaBetaCorr3Hits;
    delete TLL_TauHPSbyMediumIsolationMVA;
    delete TLL_TauHPSbyMediumIsolationMVA2;
    delete TLL_TauHPSbyTightCombinedIsolationDeltaBetaCorr;
    delete TLL_TauHPSbyTightCombinedIsolationDeltaBetaCorr3Hits;
    delete TLL_TauHPSbyTightIsolationMVA;
    delete TLL_TauHPSbyTightIsolationMVA2;
    delete TLL_TauHPSbyVLooseCombinedIsolationDeltaBetaCorr;
    delete TLL_TauHPSdecayModeFinding;
    delete TLL_TauIsInTheCracks;
    delete TLL_TauLTIpVtdxy;
    delete TLL_TauLTIpVtdxyError;
    delete TLL_TauLTIpVtdz;
    delete TLL_TauLTIpVtdzError;
    delete TLL_TauLTNormChiSqrd;
    delete TLL_TauLTPt;
    delete TLL_TauLTValidHits;
    delete TLL_TauLTvalid;
    delete TLL_TauLTvx;
    delete TLL_TauLTvy;
    delete TLL_TauLTvz;
    delete TLL_TauLepton1CosDeltaPhi;
    delete TLL_TauLepton1DeltaR;
    delete TLL_TauLepton1METMass;
    delete TLL_TauLepton1VisibleMass;
    delete TLL_TauLepton2CosDeltaPhi;
    delete TLL_TauLepton2DeltaR;
    delete TLL_TauLepton2METMass;
    delete TLL_TauLepton2VisibleMass;
    delete TLL_TauMomentumRank;
    delete TLL_TauNProngs;
    delete TLL_TauNSignalGammas;
    delete TLL_TauNSignalNeutrals;
    delete TLL_TauP;
    delete TLL_TauPhi;
    delete TLL_TauPt;
    delete TLL_TriggerEventWeight;
    // >>> End delete <<<
}

void
tll::Branches::Null()
{
    roast::Branches::Null();

    // >>> Begin null <<<
    J_Lepton1DeltaR = 0;
    J_Lepton2DeltaR = 0;
    J_TauDeltaR = 0;
    TLL_Lepton1Charge = 0;
    TLL_Lepton1CorrectedD0 = 0;
    TLL_Lepton1CorrectedDZ = 0;
    TLL_Lepton1Eta = 0;
    TLL_Lepton1EventWeight = 0;
    TLL_Lepton1GenMatchDaughter0Id = 0;
    TLL_Lepton1GenMatchDaughter0Status = 0;
    TLL_Lepton1GenMatchDaughter1Id = 0;
    TLL_Lepton1GenMatchDaughter1Status = 0;
    TLL_Lepton1GenMatchGrandmother00Id = 0;
    TLL_Lepton1GenMatchGrandmother00Status = 0;
    TLL_Lepton1GenMatchGrandmother01Id = 0;
    TLL_Lepton1GenMatchGrandmother01Status = 0;
    TLL_Lepton1GenMatchGrandmother10Id = 0;
    TLL_Lepton1GenMatchGrandmother10Status = 0;
    TLL_Lepton1GenMatchGrandmother11Id = 0;
    TLL_Lepton1GenMatchGrandmother11Status = 0;
    TLL_Lepton1GenMatchId = 0;
    TLL_Lepton1GenMatchMother0Id = 0;
    TLL_Lepton1GenMatchMother0Status = 0;
    TLL_Lepton1GenMatchMother1Id = 0;
    TLL_Lepton1GenMatchMother1Status = 0;
    TLL_Lepton1GenMatchStatus = 0;
    TLL_Lepton1ImpactParameter = 0;
    TLL_Lepton1IsElectron = 0;
    TLL_Lepton1IsLoose = 0;
    TLL_Lepton1IsMuon = 0;
    TLL_Lepton1IsTight = 0;
    TLL_Lepton1Lepton2CosDeltaPhi = 0;
    TLL_Lepton1Lepton2DeltaR = 0;
    TLL_Lepton1Lepton2VisibleMass = 0;
    TLL_Lepton1Mt = 0;
    TLL_Lepton1Mt2 = 0;
    TLL_Lepton1P = 0;
    TLL_Lepton1Phi = 0;
    TLL_Lepton1Pt = 0;
    TLL_Lepton1RelIso = 0;
    TLL_Lepton2Charge = 0;
    TLL_Lepton2CorrectedD0 = 0;
    TLL_Lepton2CorrectedDZ = 0;
    TLL_Lepton2Eta = 0;
    TLL_Lepton2EventWeight = 0;
    TLL_Lepton2GenMatchDaughter0Id = 0;
    TLL_Lepton2GenMatchDaughter0Status = 0;
    TLL_Lepton2GenMatchDaughter1Id = 0;
    TLL_Lepton2GenMatchDaughter1Status = 0;
    TLL_Lepton2GenMatchGrandmother00Id = 0;
    TLL_Lepton2GenMatchGrandmother00Status = 0;
    TLL_Lepton2GenMatchGrandmother01Id = 0;
    TLL_Lepton2GenMatchGrandmother01Status = 0;
    TLL_Lepton2GenMatchGrandmother10Id = 0;
    TLL_Lepton2GenMatchGrandmother10Status = 0;
    TLL_Lepton2GenMatchGrandmother11Id = 0;
    TLL_Lepton2GenMatchGrandmother11Status = 0;
    TLL_Lepton2GenMatchId = 0;
    TLL_Lepton2GenMatchMother0Id = 0;
    TLL_Lepton2GenMatchMother0Status = 0;
    TLL_Lepton2GenMatchMother1Id = 0;
    TLL_Lepton2GenMatchMother1Status = 0;
    TLL_Lepton2GenMatchStatus = 0;
    TLL_Lepton2ImpactParameter = 0;
    TLL_Lepton2IsElectron = 0;
    TLL_Lepton2IsLoose = 0;
    TLL_Lepton2IsMuon = 0;
    TLL_Lepton2IsTight = 0;
    TLL_Lepton2Mt = 0;
    TLL_Lepton2Mt2 = 0;
    TLL_Lepton2P = 0;
    TLL_Lepton2Phi = 0;
    TLL_Lepton2Pt = 0;
    TLL_Lepton2RelIso = 0;
    TLL_PassZMask = 0;
    TLL_PassZMask2 = 0;
    TLL_TauCharge = 0;
    TLL_TauDecayMode = 0;
    TLL_TauEmFraction = 0;
    TLL_TauEta = 0;
    TLL_TauGenMatchDaughter0Id = 0;
    TLL_TauGenMatchDaughter0Status = 0;
    TLL_TauGenMatchDaughter1Id = 0;
    TLL_TauGenMatchDaughter1Status = 0;
    TLL_TauGenMatchGrandmother00Id = 0;
    TLL_TauGenMatchGrandmother00Status = 0;
    TLL_TauGenMatchGrandmother01Id = 0;
    TLL_TauGenMatchGrandmother01Status = 0;
    TLL_TauGenMatchGrandmother10Id = 0;
    TLL_TauGenMatchGrandmother10Status = 0;
    TLL_TauGenMatchGrandmother11Id = 0;
    TLL_TauGenMatchGrandmother11Status = 0;
    TLL_TauGenMatchId = 0;
    TLL_TauGenMatchMother0Id = 0;
    TLL_TauGenMatchMother0Status = 0;
    TLL_TauGenMatchMother1Id = 0;
    TLL_TauGenMatchMother1Status = 0;
    TLL_TauGenMatchStatus = 0;
    TLL_TauHPSagainstElectronDeadECAL = 0;
    TLL_TauHPSagainstElectronLoose = 0;
    TLL_TauHPSagainstElectronLooseMVA2 = 0;
    TLL_TauHPSagainstElectronLooseMVA3 = 0;
    TLL_TauHPSagainstElectronMVA = 0;
    TLL_TauHPSagainstElectronMVA2category = 0;
    TLL_TauHPSagainstElectronMVA2raw = 0;
    TLL_TauHPSagainstElectronMVA3category = 0;
    TLL_TauHPSagainstElectronMVA3raw = 0;
    TLL_TauHPSagainstElectronMedium = 0;
    TLL_TauHPSagainstElectronMediumMVA2 = 0;
    TLL_TauHPSagainstElectronMediumMVA3 = 0;
    TLL_TauHPSagainstElectronTight = 0;
    TLL_TauHPSagainstElectronTightMVA2 = 0;
    TLL_TauHPSagainstElectronTightMVA3 = 0;
    TLL_TauHPSagainstElectronVLooseMVA2 = 0;
    TLL_TauHPSagainstElectronVTightMVA3 = 0;
    TLL_TauHPSagainstMuonLoose = 0;
    TLL_TauHPSagainstMuonLoose2 = 0;
    TLL_TauHPSagainstMuonMedium = 0;
    TLL_TauHPSagainstMuonMedium2 = 0;
    TLL_TauHPSagainstMuonTight = 0;
    TLL_TauHPSagainstMuonTight2 = 0;
    TLL_TauHPSbyCombinedIsolationDeltaBetaCorrRaw = 0;
    TLL_TauHPSbyCombinedIsolationDeltaBetaCorrRaw3Hits = 0;
    TLL_TauHPSbyIsolationMVA2raw = 0;
    TLL_TauHPSbyIsolationMVAraw = 0;
    TLL_TauHPSbyLooseCombinedIsolationDeltaBetaCorr = 0;
    TLL_TauHPSbyLooseCombinedIsolationDeltaBetaCorr3Hits = 0;
    TLL_TauHPSbyLooseIsolationMVA = 0;
    TLL_TauHPSbyLooseIsolationMVA2 = 0;
    TLL_TauHPSbyMediumCombinedIsolationDeltaBetaCorr = 0;
    TLL_TauHPSbyMediumCombinedIsolationDeltaBetaCorr3Hits = 0;
    TLL_TauHPSbyMediumIsolationMVA = 0;
    TLL_TauHPSbyMediumIsolationMVA2 = 0;
    TLL_TauHPSbyTightCombinedIsolationDeltaBetaCorr = 0;
    TLL_TauHPSbyTightCombinedIsolationDeltaBetaCorr3Hits = 0;
    TLL_TauHPSbyTightIsolationMVA = 0;
    TLL_TauHPSbyTightIsolationMVA2 = 0;
    TLL_TauHPSbyVLooseCombinedIsolationDeltaBetaCorr = 0;
    TLL_TauHPSdecayModeFinding = 0;
    TLL_TauIsInTheCracks = 0;
    TLL_TauLTIpVtdxy = 0;
    TLL_TauLTIpVtdxyError = 0;
    TLL_TauLTIpVtdz = 0;
    TLL_TauLTIpVtdzError = 0;
    TLL_TauLTNormChiSqrd = 0;
    TLL_TauLTPt = 0;
    TLL_TauLTValidHits = 0;
    TLL_TauLTvalid = 0;
    TLL_TauLTvx = 0;
    TLL_TauLTvy = 0;
    TLL_TauLTvz = 0;
    TLL_TauLepton1CosDeltaPhi = 0;
    TLL_TauLepton1DeltaR = 0;
    TLL_TauLepton1METMass = 0;
    TLL_TauLepton1VisibleMass = 0;
    TLL_TauLepton2CosDeltaPhi = 0;
    TLL_TauLepton2DeltaR = 0;
    TLL_TauLepton2METMass = 0;
    TLL_TauLepton2VisibleMass = 0;
    TLL_TauMomentumRank = 0;
    TLL_TauNProngs = 0;
    TLL_TauNSignalGammas = 0;
    TLL_TauNSignalNeutrals = 0;
    TLL_TauP = 0;
    TLL_TauPhi = 0;
    TLL_TauPt = 0;
    TLL_TriggerEventWeight = 0;
    // >>> End null <<<
}

void
tll::Branches::SetBranchAddresses()
{
    roast::Branches::SetBranchAddresses();

    // >>> Begin address <<<
    fChain->SetBranchAddress("J_Lepton1DeltaR", &J_Lepton1DeltaR);
    fChain->SetBranchAddress("J_Lepton2DeltaR", &J_Lepton2DeltaR);
    fChain->SetBranchAddress("J_TauDeltaR", &J_TauDeltaR);
    fChain->SetBranchAddress("TLL_CSVeventWeight", &CSVeventWeight);
    fChain->SetBranchAddress("TLL_CSVeventWeightCErr1down", &CSVeventWeightCErr1down);
    fChain->SetBranchAddress("TLL_CSVeventWeightCErr1up", &CSVeventWeightCErr1up);
    fChain->SetBranchAddress("TLL_CSVeventWeightCErr2down", &CSVeventWeightCErr2down);
    fChain->SetBranchAddress("TLL_CSVeventWeightCErr2up", &CSVeventWeightCErr2up);
    fChain->SetBranchAddress("TLL_CSVeventWeightHFStats1down", &CSVeventWeightHFStats1down);
    fChain->SetBranchAddress("TLL_CSVeventWeightHFStats1up", &CSVeventWeightHFStats1up);
    fChain->SetBranchAddress("TLL_CSVeventWeightHFStats2down", &CSVeventWeightHFStats2down);
    fChain->SetBranchAddress("TLL_CSVeventWeightHFStats2up", &CSVeventWeightHFStats2up);
    fChain->SetBranchAddress("TLL_CSVeventWeightHFdown", &CSVeventWeightHFdown);
    fChain->SetBranchAddress("TLL_CSVeventWeightHFup", &CSVeventWeightHFup);
    fChain->SetBranchAddress("TLL_CSVeventWeightLFStats1down", &CSVeventWeightLFStats1down);
    fChain->SetBranchAddress("TLL_CSVeventWeightLFStats1up", &CSVeventWeightLFStats1up);
    fChain->SetBranchAddress("TLL_CSVeventWeightLFStats2down", &CSVeventWeightLFStats2down);
    fChain->SetBranchAddress("TLL_CSVeventWeightLFStats2up", &CSVeventWeightLFStats2up);
    fChain->SetBranchAddress("TLL_CSVeventWeightLFdown", &CSVeventWeightLFdown);
    fChain->SetBranchAddress("TLL_CSVeventWeightLFup", &CSVeventWeightLFup);
    fChain->SetBranchAddress("TLL_CleanJetCSVMIndices", &CleanJetCSVMIndices);
    fChain->SetBranchAddress("TLL_CleanJetIndices", &CleanJetIndices);
    fChain->SetBranchAddress("TLL_CleanJetNonCSVMIndices", &CleanJetNonCSVMIndices);
    fChain->SetBranchAddress("TLL_HT", &HT);
    fChain->SetBranchAddress("TLL_Lepton1Charge", &TLL_Lepton1Charge);
    fChain->SetBranchAddress("TLL_Lepton1CorrectedD0", &TLL_Lepton1CorrectedD0);
    fChain->SetBranchAddress("TLL_Lepton1CorrectedDZ", &TLL_Lepton1CorrectedDZ);
    fChain->SetBranchAddress("TLL_Lepton1Eta", &TLL_Lepton1Eta);
    fChain->SetBranchAddress("TLL_Lepton1EventWeight", &TLL_Lepton1EventWeight);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchDaughter0Id", &TLL_Lepton1GenMatchDaughter0Id);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchDaughter0Status", &TLL_Lepton1GenMatchDaughter0Status);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchDaughter1Id", &TLL_Lepton1GenMatchDaughter1Id);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchDaughter1Status", &TLL_Lepton1GenMatchDaughter1Status);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchGrandmother00Id", &TLL_Lepton1GenMatchGrandmother00Id);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchGrandmother00Status", &TLL_Lepton1GenMatchGrandmother00Status);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchGrandmother01Id", &TLL_Lepton1GenMatchGrandmother01Id);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchGrandmother01Status", &TLL_Lepton1GenMatchGrandmother01Status);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchGrandmother10Id", &TLL_Lepton1GenMatchGrandmother10Id);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchGrandmother10Status", &TLL_Lepton1GenMatchGrandmother10Status);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchGrandmother11Id", &TLL_Lepton1GenMatchGrandmother11Id);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchGrandmother11Status", &TLL_Lepton1GenMatchGrandmother11Status);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchId", &TLL_Lepton1GenMatchId);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchMother0Id", &TLL_Lepton1GenMatchMother0Id);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchMother0Status", &TLL_Lepton1GenMatchMother0Status);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchMother1Id", &TLL_Lepton1GenMatchMother1Id);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchMother1Status", &TLL_Lepton1GenMatchMother1Status);
    fChain->SetBranchAddress("TLL_Lepton1GenMatchStatus", &TLL_Lepton1GenMatchStatus);
    fChain->SetBranchAddress("TLL_Lepton1ImpactParameter", &TLL_Lepton1ImpactParameter);
    fChain->SetBranchAddress("TLL_Lepton1IsElectron", &TLL_Lepton1IsElectron);
    fChain->SetBranchAddress("TLL_Lepton1IsLoose", &TLL_Lepton1IsLoose);
    fChain->SetBranchAddress("TLL_Lepton1IsMuon", &TLL_Lepton1IsMuon);
    fChain->SetBranchAddress("TLL_Lepton1IsTight", &TLL_Lepton1IsTight);
    fChain->SetBranchAddress("TLL_Lepton1Lepton2CosDeltaPhi", &TLL_Lepton1Lepton2CosDeltaPhi);
    fChain->SetBranchAddress("TLL_Lepton1Lepton2DeltaR", &TLL_Lepton1Lepton2DeltaR);
    fChain->SetBranchAddress("TLL_Lepton1Lepton2VisibleMass", &TLL_Lepton1Lepton2VisibleMass);
    fChain->SetBranchAddress("TLL_Lepton1Mt", &TLL_Lepton1Mt);
    fChain->SetBranchAddress("TLL_Lepton1Mt2", &TLL_Lepton1Mt2);
    fChain->SetBranchAddress("TLL_Lepton1P", &TLL_Lepton1P);
    fChain->SetBranchAddress("TLL_Lepton1Phi", &TLL_Lepton1Phi);
    fChain->SetBranchAddress("TLL_Lepton1Pt", &TLL_Lepton1Pt);
    fChain->SetBranchAddress("TLL_Lepton1RelIso", &TLL_Lepton1RelIso);
    fChain->SetBranchAddress("TLL_Lepton2Charge", &TLL_Lepton2Charge);
    fChain->SetBranchAddress("TLL_Lepton2CorrectedD0", &TLL_Lepton2CorrectedD0);
    fChain->SetBranchAddress("TLL_Lepton2CorrectedDZ", &TLL_Lepton2CorrectedDZ);
    fChain->SetBranchAddress("TLL_Lepton2Eta", &TLL_Lepton2Eta);
    fChain->SetBranchAddress("TLL_Lepton2EventWeight", &TLL_Lepton2EventWeight);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchDaughter0Id", &TLL_Lepton2GenMatchDaughter0Id);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchDaughter0Status", &TLL_Lepton2GenMatchDaughter0Status);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchDaughter1Id", &TLL_Lepton2GenMatchDaughter1Id);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchDaughter1Status", &TLL_Lepton2GenMatchDaughter1Status);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchGrandmother00Id", &TLL_Lepton2GenMatchGrandmother00Id);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchGrandmother00Status", &TLL_Lepton2GenMatchGrandmother00Status);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchGrandmother01Id", &TLL_Lepton2GenMatchGrandmother01Id);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchGrandmother01Status", &TLL_Lepton2GenMatchGrandmother01Status);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchGrandmother10Id", &TLL_Lepton2GenMatchGrandmother10Id);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchGrandmother10Status", &TLL_Lepton2GenMatchGrandmother10Status);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchGrandmother11Id", &TLL_Lepton2GenMatchGrandmother11Id);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchGrandmother11Status", &TLL_Lepton2GenMatchGrandmother11Status);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchId", &TLL_Lepton2GenMatchId);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchMother0Id", &TLL_Lepton2GenMatchMother0Id);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchMother0Status", &TLL_Lepton2GenMatchMother0Status);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchMother1Id", &TLL_Lepton2GenMatchMother1Id);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchMother1Status", &TLL_Lepton2GenMatchMother1Status);
    fChain->SetBranchAddress("TLL_Lepton2GenMatchStatus", &TLL_Lepton2GenMatchStatus);
    fChain->SetBranchAddress("TLL_Lepton2ImpactParameter", &TLL_Lepton2ImpactParameter);
    fChain->SetBranchAddress("TLL_Lepton2IsElectron", &TLL_Lepton2IsElectron);
    fChain->SetBranchAddress("TLL_Lepton2IsLoose", &TLL_Lepton2IsLoose);
    fChain->SetBranchAddress("TLL_Lepton2IsMuon", &TLL_Lepton2IsMuon);
    fChain->SetBranchAddress("TLL_Lepton2IsTight", &TLL_Lepton2IsTight);
    fChain->SetBranchAddress("TLL_Lepton2Mt", &TLL_Lepton2Mt);
    fChain->SetBranchAddress("TLL_Lepton2Mt2", &TLL_Lepton2Mt2);
    fChain->SetBranchAddress("TLL_Lepton2P", &TLL_Lepton2P);
    fChain->SetBranchAddress("TLL_Lepton2Phi", &TLL_Lepton2Phi);
    fChain->SetBranchAddress("TLL_Lepton2Pt", &TLL_Lepton2Pt);
    fChain->SetBranchAddress("TLL_Lepton2RelIso", &TLL_Lepton2RelIso);
    fChain->SetBranchAddress("TLL_MHT", &MHT);
    fChain->SetBranchAddress("TLL_MomentumRank", &MomentumRank);
    fChain->SetBranchAddress("TLL_NumCSVLbtagJets", &NumCSVLbtagJets);
    fChain->SetBranchAddress("TLL_NumCSVMbtagJets", &NumCSVMbtagJets);
    fChain->SetBranchAddress("TLL_NumCSVTbtagJets", &NumCSVTbtagJets);
    fChain->SetBranchAddress("TLL_NumCleanCSVLbtagJets", &NumCleanCSVLbtagJets);
    fChain->SetBranchAddress("TLL_NumCleanCSVMbtagJets", &NumCleanCSVMbtagJets);
    fChain->SetBranchAddress("TLL_NumCleanCSVTbtagJets", &NumCleanCSVTbtagJets);
    fChain->SetBranchAddress("TLL_NumCleanNonCSVLbtagJets", &NumCleanNonCSVLbtagJets);
    fChain->SetBranchAddress("TLL_NumCleanNonCSVMbtagJets", &NumCleanNonCSVMbtagJets);
    fChain->SetBranchAddress("TLL_NumCleanNonCSVTbtagJets", &NumCleanNonCSVTbtagJets);
    fChain->SetBranchAddress("TLL_NumCombos", &NumCombos);
    fChain->SetBranchAddress("TLL_NumExLooseElectrons", &NumExLooseElectrons);
    fChain->SetBranchAddress("TLL_NumExLooseMuons", &NumExLooseMuons);
    fChain->SetBranchAddress("TLL_NumLooseElectrons", &NumLooseElectrons);
    fChain->SetBranchAddress("TLL_NumLooseMuons", &NumLooseMuons);
    fChain->SetBranchAddress("TLL_NumNonCSVLbtagJets", &NumNonCSVLbtagJets);
    fChain->SetBranchAddress("TLL_NumNonCSVMbtagJets", &NumNonCSVMbtagJets);
    fChain->SetBranchAddress("TLL_NumNonCSVTbtagJets", &NumNonCSVTbtagJets);
    fChain->SetBranchAddress("TLL_NumTaus", &NumTaus);
    fChain->SetBranchAddress("TLL_NumTightElectrons", &NumTightElectrons);
    fChain->SetBranchAddress("TLL_NumTightMuons", &NumTightMuons);
    fChain->SetBranchAddress("TLL_PassZMask", &TLL_PassZMask);
    fChain->SetBranchAddress("TLL_PassZMask2", &TLL_PassZMask2);
    fChain->SetBranchAddress("TLL_TauCharge", &TLL_TauCharge);
    fChain->SetBranchAddress("TLL_TauDecayMode", &TLL_TauDecayMode);
    fChain->SetBranchAddress("TLL_TauEmFraction", &TLL_TauEmFraction);
    fChain->SetBranchAddress("TLL_TauEta", &TLL_TauEta);
    fChain->SetBranchAddress("TLL_TauGenMatchDaughter0Id", &TLL_TauGenMatchDaughter0Id);
    fChain->SetBranchAddress("TLL_TauGenMatchDaughter0Status", &TLL_TauGenMatchDaughter0Status);
    fChain->SetBranchAddress("TLL_TauGenMatchDaughter1Id", &TLL_TauGenMatchDaughter1Id);
    fChain->SetBranchAddress("TLL_TauGenMatchDaughter1Status", &TLL_TauGenMatchDaughter1Status);
    fChain->SetBranchAddress("TLL_TauGenMatchGrandmother00Id", &TLL_TauGenMatchGrandmother00Id);
    fChain->SetBranchAddress("TLL_TauGenMatchGrandmother00Status", &TLL_TauGenMatchGrandmother00Status);
    fChain->SetBranchAddress("TLL_TauGenMatchGrandmother01Id", &TLL_TauGenMatchGrandmother01Id);
    fChain->SetBranchAddress("TLL_TauGenMatchGrandmother01Status", &TLL_TauGenMatchGrandmother01Status);
    fChain->SetBranchAddress("TLL_TauGenMatchGrandmother10Id", &TLL_TauGenMatchGrandmother10Id);
    fChain->SetBranchAddress("TLL_TauGenMatchGrandmother10Status", &TLL_TauGenMatchGrandmother10Status);
    fChain->SetBranchAddress("TLL_TauGenMatchGrandmother11Id", &TLL_TauGenMatchGrandmother11Id);
    fChain->SetBranchAddress("TLL_TauGenMatchGrandmother11Status", &TLL_TauGenMatchGrandmother11Status);
    fChain->SetBranchAddress("TLL_TauGenMatchId", &TLL_TauGenMatchId);
    fChain->SetBranchAddress("TLL_TauGenMatchMother0Id", &TLL_TauGenMatchMother0Id);
    fChain->SetBranchAddress("TLL_TauGenMatchMother0Status", &TLL_TauGenMatchMother0Status);
    fChain->SetBranchAddress("TLL_TauGenMatchMother1Id", &TLL_TauGenMatchMother1Id);
    fChain->SetBranchAddress("TLL_TauGenMatchMother1Status", &TLL_TauGenMatchMother1Status);
    fChain->SetBranchAddress("TLL_TauGenMatchStatus", &TLL_TauGenMatchStatus);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronDeadECAL", &TLL_TauHPSagainstElectronDeadECAL);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronLoose", &TLL_TauHPSagainstElectronLoose);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronLooseMVA2", &TLL_TauHPSagainstElectronLooseMVA2);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronLooseMVA3", &TLL_TauHPSagainstElectronLooseMVA3);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronMVA", &TLL_TauHPSagainstElectronMVA);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronMVA2category", &TLL_TauHPSagainstElectronMVA2category);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronMVA2raw", &TLL_TauHPSagainstElectronMVA2raw);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronMVA3category", &TLL_TauHPSagainstElectronMVA3category);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronMVA3raw", &TLL_TauHPSagainstElectronMVA3raw);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronMedium", &TLL_TauHPSagainstElectronMedium);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronMediumMVA2", &TLL_TauHPSagainstElectronMediumMVA2);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronMediumMVA3", &TLL_TauHPSagainstElectronMediumMVA3);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronTight", &TLL_TauHPSagainstElectronTight);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronTightMVA2", &TLL_TauHPSagainstElectronTightMVA2);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronTightMVA3", &TLL_TauHPSagainstElectronTightMVA3);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronVLooseMVA2", &TLL_TauHPSagainstElectronVLooseMVA2);
    fChain->SetBranchAddress("TLL_TauHPSagainstElectronVTightMVA3", &TLL_TauHPSagainstElectronVTightMVA3);
    fChain->SetBranchAddress("TLL_TauHPSagainstMuonLoose", &TLL_TauHPSagainstMuonLoose);
    fChain->SetBranchAddress("TLL_TauHPSagainstMuonLoose2", &TLL_TauHPSagainstMuonLoose2);
    fChain->SetBranchAddress("TLL_TauHPSagainstMuonMedium", &TLL_TauHPSagainstMuonMedium);
    fChain->SetBranchAddress("TLL_TauHPSagainstMuonMedium2", &TLL_TauHPSagainstMuonMedium2);
    fChain->SetBranchAddress("TLL_TauHPSagainstMuonTight", &TLL_TauHPSagainstMuonTight);
    fChain->SetBranchAddress("TLL_TauHPSagainstMuonTight2", &TLL_TauHPSagainstMuonTight2);
    fChain->SetBranchAddress("TLL_TauHPSbyCombinedIsolationDeltaBetaCorrRaw", &TLL_TauHPSbyCombinedIsolationDeltaBetaCorrRaw);
    fChain->SetBranchAddress("TLL_TauHPSbyCombinedIsolationDeltaBetaCorrRaw3Hits", &TLL_TauHPSbyCombinedIsolationDeltaBetaCorrRaw3Hits);
    fChain->SetBranchAddress("TLL_TauHPSbyIsolationMVA2raw", &TLL_TauHPSbyIsolationMVA2raw);
    fChain->SetBranchAddress("TLL_TauHPSbyIsolationMVAraw", &TLL_TauHPSbyIsolationMVAraw);
    fChain->SetBranchAddress("TLL_TauHPSbyLooseCombinedIsolationDeltaBetaCorr", &TLL_TauHPSbyLooseCombinedIsolationDeltaBetaCorr);
    fChain->SetBranchAddress("TLL_TauHPSbyLooseCombinedIsolationDeltaBetaCorr3Hits", &TLL_TauHPSbyLooseCombinedIsolationDeltaBetaCorr3Hits);
    fChain->SetBranchAddress("TLL_TauHPSbyLooseIsolationMVA", &TLL_TauHPSbyLooseIsolationMVA);
    fChain->SetBranchAddress("TLL_TauHPSbyLooseIsolationMVA2", &TLL_TauHPSbyLooseIsolationMVA2);
    fChain->SetBranchAddress("TLL_TauHPSbyMediumCombinedIsolationDeltaBetaCorr", &TLL_TauHPSbyMediumCombinedIsolationDeltaBetaCorr);
    fChain->SetBranchAddress("TLL_TauHPSbyMediumCombinedIsolationDeltaBetaCorr3Hits", &TLL_TauHPSbyMediumCombinedIsolationDeltaBetaCorr3Hits);
    fChain->SetBranchAddress("TLL_TauHPSbyMediumIsolationMVA", &TLL_TauHPSbyMediumIsolationMVA);
    fChain->SetBranchAddress("TLL_TauHPSbyMediumIsolationMVA2", &TLL_TauHPSbyMediumIsolationMVA2);
    fChain->SetBranchAddress("TLL_TauHPSbyTightCombinedIsolationDeltaBetaCorr", &TLL_TauHPSbyTightCombinedIsolationDeltaBetaCorr);
    fChain->SetBranchAddress("TLL_TauHPSbyTightCombinedIsolationDeltaBetaCorr3Hits", &TLL_TauHPSbyTightCombinedIsolationDeltaBetaCorr3Hits);
    fChain->SetBranchAddress("TLL_TauHPSbyTightIsolationMVA", &TLL_TauHPSbyTightIsolationMVA);
    fChain->SetBranchAddress("TLL_TauHPSbyTightIsolationMVA2", &TLL_TauHPSbyTightIsolationMVA2);
    fChain->SetBranchAddress("TLL_TauHPSbyVLooseCombinedIsolationDeltaBetaCorr", &TLL_TauHPSbyVLooseCombinedIsolationDeltaBetaCorr);
    fChain->SetBranchAddress("TLL_TauHPSdecayModeFinding", &TLL_TauHPSdecayModeFinding);
    fChain->SetBranchAddress("TLL_TauIsInTheCracks", &TLL_TauIsInTheCracks);
    fChain->SetBranchAddress("TLL_TauLTIpVtdxy", &TLL_TauLTIpVtdxy);
    fChain->SetBranchAddress("TLL_TauLTIpVtdxyError", &TLL_TauLTIpVtdxyError);
    fChain->SetBranchAddress("TLL_TauLTIpVtdz", &TLL_TauLTIpVtdz);
    fChain->SetBranchAddress("TLL_TauLTIpVtdzError", &TLL_TauLTIpVtdzError);
    fChain->SetBranchAddress("TLL_TauLTNormChiSqrd", &TLL_TauLTNormChiSqrd);
    fChain->SetBranchAddress("TLL_TauLTPt", &TLL_TauLTPt);
    fChain->SetBranchAddress("TLL_TauLTValidHits", &TLL_TauLTValidHits);
    fChain->SetBranchAddress("TLL_TauLTvalid", &TLL_TauLTvalid);
    fChain->SetBranchAddress("TLL_TauLTvx", &TLL_TauLTvx);
    fChain->SetBranchAddress("TLL_TauLTvy", &TLL_TauLTvy);
    fChain->SetBranchAddress("TLL_TauLTvz", &TLL_TauLTvz);
    fChain->SetBranchAddress("TLL_TauLepton1CosDeltaPhi", &TLL_TauLepton1CosDeltaPhi);
    fChain->SetBranchAddress("TLL_TauLepton1DeltaR", &TLL_TauLepton1DeltaR);
    fChain->SetBranchAddress("TLL_TauLepton1METMass", &TLL_TauLepton1METMass);
    fChain->SetBranchAddress("TLL_TauLepton1VisibleMass", &TLL_TauLepton1VisibleMass);
    fChain->SetBranchAddress("TLL_TauLepton2CosDeltaPhi", &TLL_TauLepton2CosDeltaPhi);
    fChain->SetBranchAddress("TLL_TauLepton2DeltaR", &TLL_TauLepton2DeltaR);
    fChain->SetBranchAddress("TLL_TauLepton2METMass", &TLL_TauLepton2METMass);
    fChain->SetBranchAddress("TLL_TauLepton2VisibleMass", &TLL_TauLepton2VisibleMass);
    fChain->SetBranchAddress("TLL_TauMomentumRank", &TLL_TauMomentumRank);
    fChain->SetBranchAddress("TLL_TauNProngs", &TLL_TauNProngs);
    fChain->SetBranchAddress("TLL_TauNSignalGammas", &TLL_TauNSignalGammas);
    fChain->SetBranchAddress("TLL_TauNSignalNeutrals", &TLL_TauNSignalNeutrals);
    fChain->SetBranchAddress("TLL_TauP", &TLL_TauP);
    fChain->SetBranchAddress("TLL_TauPhi", &TLL_TauPhi);
    fChain->SetBranchAddress("TLL_TauPt", &TLL_TauPt);
    fChain->SetBranchAddress("TLL_TriggerEventWeight", &TLL_TriggerEventWeight);
    // >>> End address <<<
}
