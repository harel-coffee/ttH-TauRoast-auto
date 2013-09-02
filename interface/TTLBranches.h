// vim: ts=4:sw=4:et:sta
#ifndef TTLBranches_h
#define TTLBranches_h

#include "Branches.h"

namespace roast {
    namespace ttl {
        class Branches : public roast::Branches {
            private:
                void	Null();
                void	Delete();
                void	Clear();
                void	SetBranchAddresses();

            public:
                Branches();
                Branches(const std::string&, const std::vector<std::string>&);
                ~Branches();

                virtual bool IsGoodGenMatch(const int&) const;

                unsigned int	GetTau1IsolationIndex(const unsigned int) const;
                unsigned int	GetTau2IsolationIndex(const unsigned int) const;
                unsigned int	GetTau1IsolationIndexMVA(const unsigned int) const;
                unsigned int	GetTau2IsolationIndexMVA(const unsigned int) const;
                unsigned int	GetTau1IsolationIndexMVA2(const unsigned int) const;
                unsigned int	GetTau2IsolationIndexMVA2(const unsigned int) const;
                unsigned int	GetTau1IsolationIndex3Hits(const unsigned int) const;
                unsigned int	GetTau2IsolationIndex3Hits(const unsigned int) const;
                unsigned int	GetTau1AntiElectronIndex(const unsigned int) const;
                unsigned int	GetTau2AntiElectronIndex(const unsigned int) const;
                unsigned int	GetTau1AntiElectronIndexMVA2(const unsigned int) const;
                unsigned int	GetTau2AntiElectronIndexMVA2(const unsigned int) const;
                unsigned int	GetTau1AntiElectronIndexMVA3(const unsigned int) const;
                unsigned int	GetTau2AntiElectronIndexMVA3(const unsigned int) const;
                unsigned int	GetTau1AntiMuonIndex(const unsigned int) const;
                unsigned int	GetTau2AntiMuonIndex(const unsigned int) const;
                unsigned int	GetTau1AntiMuonIndex2(const unsigned int) const;
                unsigned int	GetTau2AntiMuonIndex2(const unsigned int) const;
                unsigned int    GetTau1MatchIndex(const unsigned int) const;
                unsigned int    GetTau2MatchIndex(const unsigned int) const;
                // float GetMVAResponse(const unsigned int) const;

                // >>> Begin declarations <<<
                std::vector<float>* TTL_DitauCosDeltaPhi;
                std::vector<float>* TTL_DitauDeltaR;
                std::vector<float>* TTL_DitauMETMass;
                std::vector<float>* TTL_DitauVisibleMass;
                std::vector<int>* TTL_ElectronMomentumRank;
                std::vector<float>* TTL_LeptonEta;
                std::vector<float>* TTL_LeptonEventWeight;
                std::vector<int>* TTL_LeptonGenMatchDaughter0Id;
                std::vector<int>* TTL_LeptonGenMatchDaughter0Status;
                std::vector<int>* TTL_LeptonGenMatchDaughter1Id;
                std::vector<int>* TTL_LeptonGenMatchDaughter1Status;
                std::vector<int>* TTL_LeptonGenMatchGrandmother00Id;
                std::vector<int>* TTL_LeptonGenMatchGrandmother00Status;
                std::vector<int>* TTL_LeptonGenMatchGrandmother01Id;
                std::vector<int>* TTL_LeptonGenMatchGrandmother01Status;
                std::vector<int>* TTL_LeptonGenMatchGrandmother10Id;
                std::vector<int>* TTL_LeptonGenMatchGrandmother10Status;
                std::vector<int>* TTL_LeptonGenMatchGrandmother11Id;
                std::vector<int>* TTL_LeptonGenMatchGrandmother11Status;
                std::vector<int>* TTL_LeptonGenMatchId;
                std::vector<int>* TTL_LeptonGenMatchMother0Id;
                std::vector<int>* TTL_LeptonGenMatchMother0Status;
                std::vector<int>* TTL_LeptonGenMatchMother1Id;
                std::vector<int>* TTL_LeptonGenMatchMother1Status;
                std::vector<int>* TTL_LeptonGenMatchStatus;
                std::vector<float>* TTL_LeptonIsElectron;
                std::vector<bool>* TTL_LeptonIsLoose;
                std::vector<float>* TTL_LeptonIsMuon;
                std::vector<bool>* TTL_LeptonIsTight;
                std::vector<int>* TTL_LeptonMomentumRank;
                std::vector<float>* TTL_LeptonPhi;
                std::vector<float>* TTL_LeptonPt;
                std::vector<float>* TTL_LeptonRelIso;
                std::vector<int>* TTL_MuonMomentumRank;
                UInt_t TTL_NumElectrons;
                UInt_t TTL_NumLeptons;
                UInt_t TTL_NumMuons;
                std::vector<float>* TTL_Tau1Charge;
                std::vector<unsigned int>* TTL_Tau1DecayMode;
                std::vector<float>* TTL_Tau1EmFraction;
                std::vector<float>* TTL_Tau1Eta;
                std::vector<int>* TTL_Tau1GenMatchDaughter0Id;
                std::vector<int>* TTL_Tau1GenMatchDaughter0Status;
                std::vector<int>* TTL_Tau1GenMatchDaughter1Id;
                std::vector<int>* TTL_Tau1GenMatchDaughter1Status;
                std::vector<int>* TTL_Tau1GenMatchGrandmother00Id;
                std::vector<int>* TTL_Tau1GenMatchGrandmother00Status;
                std::vector<int>* TTL_Tau1GenMatchGrandmother01Id;
                std::vector<int>* TTL_Tau1GenMatchGrandmother01Status;
                std::vector<int>* TTL_Tau1GenMatchGrandmother10Id;
                std::vector<int>* TTL_Tau1GenMatchGrandmother10Status;
                std::vector<int>* TTL_Tau1GenMatchGrandmother11Id;
                std::vector<int>* TTL_Tau1GenMatchGrandmother11Status;
                std::vector<int>* TTL_Tau1GenMatchId;
                std::vector<int>* TTL_Tau1GenMatchMother0Id;
                std::vector<int>* TTL_Tau1GenMatchMother0Status;
                std::vector<int>* TTL_Tau1GenMatchMother1Id;
                std::vector<int>* TTL_Tau1GenMatchMother1Status;
                std::vector<int>* TTL_Tau1GenMatchStatus;
                std::vector<bool>* TTL_Tau1HPSagainstElectronDeadECAL;
                std::vector<bool>* TTL_Tau1HPSagainstElectronLoose;
                std::vector<bool>* TTL_Tau1HPSagainstElectronLooseMVA2;
                std::vector<bool>* TTL_Tau1HPSagainstElectronLooseMVA3;
                std::vector<bool>* TTL_Tau1HPSagainstElectronMVA;
                std::vector<bool>* TTL_Tau1HPSagainstElectronMVA2category;
                std::vector<float>* TTL_Tau1HPSagainstElectronMVA2raw;
                std::vector<bool>* TTL_Tau1HPSagainstElectronMVA3category;
                std::vector<float>* TTL_Tau1HPSagainstElectronMVA3raw;
                std::vector<bool>* TTL_Tau1HPSagainstElectronMedium;
                std::vector<bool>* TTL_Tau1HPSagainstElectronMediumMVA2;
                std::vector<bool>* TTL_Tau1HPSagainstElectronMediumMVA3;
                std::vector<bool>* TTL_Tau1HPSagainstElectronTight;
                std::vector<bool>* TTL_Tau1HPSagainstElectronTightMVA2;
                std::vector<bool>* TTL_Tau1HPSagainstElectronTightMVA3;
                std::vector<bool>* TTL_Tau1HPSagainstElectronVLooseMVA2;
                std::vector<bool>* TTL_Tau1HPSagainstElectronVTightMVA3;
                std::vector<bool>* TTL_Tau1HPSagainstMuonLoose;
                std::vector<bool>* TTL_Tau1HPSagainstMuonLoose2;
                std::vector<bool>* TTL_Tau1HPSagainstMuonMedium;
                std::vector<bool>* TTL_Tau1HPSagainstMuonMedium2;
                std::vector<bool>* TTL_Tau1HPSagainstMuonTight;
                std::vector<bool>* TTL_Tau1HPSagainstMuonTight2;
                std::vector<float>* TTL_Tau1HPSbyCombinedIsolationDeltaBetaCorrRaw;
                std::vector<float>* TTL_Tau1HPSbyCombinedIsolationDeltaBetaCorrRaw3Hits;
                std::vector<float>* TTL_Tau1HPSbyIsolationMVA2raw;
                std::vector<float>* TTL_Tau1HPSbyIsolationMVAraw;
                std::vector<bool>* TTL_Tau1HPSbyLooseCombinedIsolationDeltaBetaCorr;
                std::vector<bool>* TTL_Tau1HPSbyLooseCombinedIsolationDeltaBetaCorr3Hits;
                std::vector<bool>* TTL_Tau1HPSbyLooseIsolationMVA;
                std::vector<bool>* TTL_Tau1HPSbyLooseIsolationMVA2;
                std::vector<bool>* TTL_Tau1HPSbyMediumCombinedIsolationDeltaBetaCorr;
                std::vector<bool>* TTL_Tau1HPSbyMediumCombinedIsolationDeltaBetaCorr3Hits;
                std::vector<bool>* TTL_Tau1HPSbyMediumIsolationMVA;
                std::vector<bool>* TTL_Tau1HPSbyMediumIsolationMVA2;
                std::vector<bool>* TTL_Tau1HPSbyTightCombinedIsolationDeltaBetaCorr;
                std::vector<bool>* TTL_Tau1HPSbyTightCombinedIsolationDeltaBetaCorr3Hits;
                std::vector<bool>* TTL_Tau1HPSbyTightIsolationMVA;
                std::vector<bool>* TTL_Tau1HPSbyTightIsolationMVA2;
                std::vector<bool>* TTL_Tau1HPSbyVLooseCombinedIsolationDeltaBetaCorr;
                std::vector<bool>* TTL_Tau1HPSdecayModeFinding;
                std::vector<bool>* TTL_Tau1IsInTheCracks;
                std::vector<float>* TTL_Tau1LTIpVtdxy;
                std::vector<float>* TTL_Tau1LTIpVtdxyError;
                std::vector<float>* TTL_Tau1LTIpVtdz;
                std::vector<float>* TTL_Tau1LTIpVtdzError;
                std::vector<float>* TTL_Tau1LTNormChiSqrd;
                std::vector<float>* TTL_Tau1LTPt;
                std::vector<unsigned int>* TTL_Tau1LTValidHits;
                std::vector<bool>* TTL_Tau1LTvalid;
                std::vector<float>* TTL_Tau1LTvx;
                std::vector<float>* TTL_Tau1LTvy;
                std::vector<float>* TTL_Tau1LTvz;
                std::vector<float>* TTL_Tau1LeptonDeltaR;
                std::vector<int>* TTL_Tau1MomentumRank;
                std::vector<unsigned int>* TTL_Tau1NProngs;
                std::vector<unsigned int>* TTL_Tau1NSignalGammas;
                std::vector<unsigned int>* TTL_Tau1NSignalNeutrals;
                std::vector<float>* TTL_Tau1Phi;
                std::vector<float>* TTL_Tau1Pt;
                std::vector<float>* TTL_Tau2Charge;
                std::vector<unsigned int>* TTL_Tau2DecayMode;
                std::vector<float>* TTL_Tau2EmFraction;
                std::vector<float>* TTL_Tau2Eta;
                std::vector<int>* TTL_Tau2GenMatchDaughter0Id;
                std::vector<int>* TTL_Tau2GenMatchDaughter0Status;
                std::vector<int>* TTL_Tau2GenMatchDaughter1Id;
                std::vector<int>* TTL_Tau2GenMatchDaughter1Status;
                std::vector<int>* TTL_Tau2GenMatchGrandmother00Id;
                std::vector<int>* TTL_Tau2GenMatchGrandmother00Status;
                std::vector<int>* TTL_Tau2GenMatchGrandmother01Id;
                std::vector<int>* TTL_Tau2GenMatchGrandmother01Status;
                std::vector<int>* TTL_Tau2GenMatchGrandmother10Id;
                std::vector<int>* TTL_Tau2GenMatchGrandmother10Status;
                std::vector<int>* TTL_Tau2GenMatchGrandmother11Id;
                std::vector<int>* TTL_Tau2GenMatchGrandmother11Status;
                std::vector<int>* TTL_Tau2GenMatchId;
                std::vector<int>* TTL_Tau2GenMatchMother0Id;
                std::vector<int>* TTL_Tau2GenMatchMother0Status;
                std::vector<int>* TTL_Tau2GenMatchMother1Id;
                std::vector<int>* TTL_Tau2GenMatchMother1Status;
                std::vector<int>* TTL_Tau2GenMatchStatus;
                std::vector<bool>* TTL_Tau2HPSagainstElectronDeadECAL;
                std::vector<bool>* TTL_Tau2HPSagainstElectronLoose;
                std::vector<bool>* TTL_Tau2HPSagainstElectronLooseMVA2;
                std::vector<bool>* TTL_Tau2HPSagainstElectronLooseMVA3;
                std::vector<bool>* TTL_Tau2HPSagainstElectronMVA;
                std::vector<bool>* TTL_Tau2HPSagainstElectronMVA2category;
                std::vector<float>* TTL_Tau2HPSagainstElectronMVA2raw;
                std::vector<bool>* TTL_Tau2HPSagainstElectronMVA3category;
                std::vector<float>* TTL_Tau2HPSagainstElectronMVA3raw;
                std::vector<bool>* TTL_Tau2HPSagainstElectronMedium;
                std::vector<bool>* TTL_Tau2HPSagainstElectronMediumMVA2;
                std::vector<bool>* TTL_Tau2HPSagainstElectronMediumMVA3;
                std::vector<bool>* TTL_Tau2HPSagainstElectronTight;
                std::vector<bool>* TTL_Tau2HPSagainstElectronTightMVA2;
                std::vector<bool>* TTL_Tau2HPSagainstElectronTightMVA3;
                std::vector<bool>* TTL_Tau2HPSagainstElectronVLooseMVA2;
                std::vector<bool>* TTL_Tau2HPSagainstElectronVTightMVA3;
                std::vector<bool>* TTL_Tau2HPSagainstMuonLoose;
                std::vector<bool>* TTL_Tau2HPSagainstMuonLoose2;
                std::vector<bool>* TTL_Tau2HPSagainstMuonMedium;
                std::vector<bool>* TTL_Tau2HPSagainstMuonMedium2;
                std::vector<bool>* TTL_Tau2HPSagainstMuonTight;
                std::vector<bool>* TTL_Tau2HPSagainstMuonTight2;
                std::vector<float>* TTL_Tau2HPSbyCombinedIsolationDeltaBetaCorrRaw;
                std::vector<float>* TTL_Tau2HPSbyCombinedIsolationDeltaBetaCorrRaw3Hits;
                std::vector<float>* TTL_Tau2HPSbyIsolationMVA2raw;
                std::vector<float>* TTL_Tau2HPSbyIsolationMVAraw;
                std::vector<bool>* TTL_Tau2HPSbyLooseCombinedIsolationDeltaBetaCorr;
                std::vector<bool>* TTL_Tau2HPSbyLooseCombinedIsolationDeltaBetaCorr3Hits;
                std::vector<bool>* TTL_Tau2HPSbyLooseIsolationMVA;
                std::vector<bool>* TTL_Tau2HPSbyLooseIsolationMVA2;
                std::vector<bool>* TTL_Tau2HPSbyMediumCombinedIsolationDeltaBetaCorr;
                std::vector<bool>* TTL_Tau2HPSbyMediumCombinedIsolationDeltaBetaCorr3Hits;
                std::vector<bool>* TTL_Tau2HPSbyMediumIsolationMVA;
                std::vector<bool>* TTL_Tau2HPSbyMediumIsolationMVA2;
                std::vector<bool>* TTL_Tau2HPSbyTightCombinedIsolationDeltaBetaCorr;
                std::vector<bool>* TTL_Tau2HPSbyTightCombinedIsolationDeltaBetaCorr3Hits;
                std::vector<bool>* TTL_Tau2HPSbyTightIsolationMVA;
                std::vector<bool>* TTL_Tau2HPSbyTightIsolationMVA2;
                std::vector<bool>* TTL_Tau2HPSbyVLooseCombinedIsolationDeltaBetaCorr;
                std::vector<bool>* TTL_Tau2HPSdecayModeFinding;
                std::vector<bool>* TTL_Tau2IsInTheCracks;
                std::vector<float>* TTL_Tau2LTIpVtdxy;
                std::vector<float>* TTL_Tau2LTIpVtdxyError;
                std::vector<float>* TTL_Tau2LTIpVtdz;
                std::vector<float>* TTL_Tau2LTIpVtdzError;
                std::vector<float>* TTL_Tau2LTNormChiSqrd;
                std::vector<float>* TTL_Tau2LTPt;
                std::vector<unsigned int>* TTL_Tau2LTValidHits;
                std::vector<bool>* TTL_Tau2LTvalid;
                std::vector<float>* TTL_Tau2LTvx;
                std::vector<float>* TTL_Tau2LTvy;
                std::vector<float>* TTL_Tau2LTvz;
                std::vector<float>* TTL_Tau2LeptonDeltaR;
                std::vector<int>* TTL_Tau2MomentumRank;
                std::vector<unsigned int>* TTL_Tau2NProngs;
                std::vector<unsigned int>* TTL_Tau2NSignalGammas;
                std::vector<unsigned int>* TTL_Tau2NSignalNeutrals;
                std::vector<float>* TTL_Tau2Phi;
                std::vector<float>* TTL_Tau2Pt;
                // >>> End declarations <<<

                ClassDef(Branches, 1);
        };
    }
}

#endif
