#ifndef __SuperSlim_h
#define __SuperSlim_h

#include <map>
#include <vector>

#include "Math/LorentzVector.h"
#include "TObject.h"

#ifndef __CINT__
namespace edm {
   class TriggerNames;
   class TriggerResults;
}

namespace pat {
   class Electron;
   class Jet;
   class Muon;
   class Tau;
}

namespace reco {
   class BeamSpot;
   class Candidate;
   class GenParticle;
   typedef std::vector<GenParticle> GenParticleCollection;
   class Vertex;
}
#endif

namespace superslim {
   namespace id {
      enum value {
         None = 0,
         Preselected = 1,
         VLoose = 2,
         Loose = 3,
         Medium = 4,
         Tight = 5,
         VTight = 6
      };

      extern const std::vector<std::pair<std::string, id::value>> values;
   }

   typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVector;

   class Vertex {
      public:
         Vertex() {};
#ifndef __CINT__
         Vertex(const reco::Vertex&);
#endif
         virtual ~Vertex() {};

         float x() const { return x_; };
         float y() const { return y_; };
         float z() const { return z_; };

         float xError() const { return x_error_; };
         float yError() const { return y_error_; };
         float zError() const { return z_error_; };

         float rho() const { return rho_; };
         float normalizedChi2() const { return normalized_chi2_; };
         int ndof() const { return ndof_; };

      private:
         float x_;
         float y_;
         float z_;

         float x_error_;
         float y_error_;
         float z_error_;

         float rho_;
         float normalized_chi2_;
         int ndof_;

         ClassDef(Vertex, 2);
   };

   class PhysObject {
      public:
         PhysObject() : p_() {};
#ifndef __CINT__
         PhysObject(const reco::Candidate*);
#endif
         virtual ~PhysObject() {};

         const float
            eta() const { return p_.eta(); };
         const float
            phi() const { return p_.phi(); };
         const LorentzVector&
            p4() const { return p_; };
         const LorentzVector&
            genP4() const { return gen_p_; };
         const std::vector<superslim::PhysObject>&
            parents() const { return parents_; };
         int
            parentId() const;
         int
            grandParentId() const;
         int
            charge() const { return charge_; };
         int
            pdgId() const { return pdg_id_; };
         int
            genPdgId() const { return gen_pdg_id_; };
         // As per https://twiki.cern.ch/twiki/bin/viewauth/CMS/HiggsToTauTauWorking2015#MC_Matching
         // 1: prompt e
         // 2: prompt μ
         // 3: τ → e
         // 4: τ → μ
         // 5: τ → τ had
         // 6: jet/pu fake
         int
            match() const { return match_; };

      protected:
#ifndef __CINT__
         const reco::Candidate*
            getFinal(const reco::Candidate* c);
         const reco::GenParticle*
            getMatch(const reco::Candidate& c, const reco::GenParticleCollection& coll);
         void
            setGenInfo(const reco::GenParticle* p, int level=2);
#endif
         int charge_;

      private:
         LorentzVector p_;
         LorentzVector gen_p_;
         std::vector<superslim::PhysObject> parents_;

         int match_;
         int pdg_id_;
         int gen_pdg_id_;

         ClassDef(PhysObject, 3);
   };

   class Jet : public PhysObject {
      public:
         Jet() {};
#ifndef __CINT__
         Jet(const pat::Jet& j, const reco::GenParticleCollection& particles);
#endif
         virtual ~Jet() {};

         float csv() const { return csv_; };
         int flavor() const { return flavor_; };
      private:
         float csv_;
         int flavor_;
         ClassDef(Jet, 2);
   };

   class Lepton : public PhysObject {
      public:
         enum id { All, Cut, MVA, LJ };

         Lepton() {};
#ifndef __CINT__
         Lepton(const pat::Electron& e, float rel_iso, const reco::Vertex& pv, const reco::BeamSpot& bs, const reco::GenParticleCollection& particles);
         Lepton(const pat::Muon& m, float rel_iso, const reco::Vertex& pv, const reco::BeamSpot& bs, const reco::GenParticleCollection& particles);
#endif
         virtual ~Lepton() {};

         bool electron() const { return type_ == e; };
         bool muon() const { return type_ == mu; };

         bool chargeConsistent() const { return charge_check_; };

         float correctedD0() const { return corrected_d0_; };
         float correctedDZ() const { return corrected_dz_; };
         float impactParameter() const { return impact_parameter_; };
         float impactParameterError() const { return impact_parameter_error_; };
         float relativeIsolation() const { return rel_iso_; };

         int cut() const { return cut_; };
         int mva() const { return mva_; };
         int lj() const { return lj_; };

         bool selected(Lepton::id id_=Lepton::All, superslim::id::value min=superslim::id::Preselected) const;
         bool loose(Lepton::id id_=Lepton::All) const { return selected(id_, superslim::id::Loose); };
         bool preselected(Lepton::id id_=Lepton::All) const { return selected(id_, superslim::id::Preselected); };

      private:
#ifndef __CINT__
         template<typename T>
         superslim::id::value getID(const std::string&, const T&) const;
#endif

         enum kind { e, mu } type_;

         bool charge_check_;

         superslim::id::value cut_;
         superslim::id::value mva_;
         superslim::id::value lj_;

         float corrected_d0_ = 0.;
         float corrected_dz_ = 0.;
         float impact_parameter_;
         float impact_parameter_error_;
         float rel_iso_;

         ClassDef(Lepton, 3);
   };

   class Tau : public PhysObject {
      public:
         Tau() {};
#ifndef __CINT__
         Tau(const pat::Tau& t, const reco::GenParticleCollection& particles);
#endif
         virtual ~Tau() {};

         bool loose() const { return
            isolation_3hits03_ > id::None or
            isolation_3hits05_ > id::None or
            isolation_mva03_ > id::None or
            isolation_mva05_ > id::None; };

         int decayMode() const { return decay_mode_; };
         int isolation3Hits03() const { return isolation_3hits03_; };
         int isolation3Hits05() const { return isolation_3hits05_; };
         int isolationMVA03() const { return isolation_mva03_; };
         int isolationMVA05() const { return isolation_mva05_; };
         int prongs() const { return prongs_; };
         int vetoElectron() const { return veto_electron_; };
         int vetoMuon() const { return veto_muon_; };

         float leadingTrackPt() const { return leading_track_pt_; };
         float rawIsolation3Hits03() const { return raw_isolation_3hits03_; };
         float rawIsolation3Hits05() const { return raw_isolation_3hits05_; };
         float rawIsolationMVA03() const { return raw_isolation_mva03_; };
         float rawIsolationMVA05() const { return raw_isolation_mva05_; };

         LorentzVector genVisibleP4() const { return gen_vis_p_; };
      private:
#ifndef __CINT__
         id::value getID(const std::string&, const std::string&, const pat::Tau&) const;
#endif

         int decay_mode_;
         int prongs_;

         id::value isolation_3hits03_;
         id::value isolation_3hits05_;
         id::value isolation_mva03_;
         id::value isolation_mva05_;
         id::value veto_electron_;
         id::value veto_muon_;

         float leading_track_pt_;
         float raw_isolation_3hits03_;
         float raw_isolation_3hits05_;
         float raw_isolation_mva03_;
         float raw_isolation_mva05_;

         LorentzVector gen_vis_p_;

         ClassDef(Tau, 2);
   };

   class Combination {
      public:
         Combination() {};
         Combination(
               const std::vector<superslim::Tau>&,
               const std::vector<superslim::Lepton>&,
               const std::map<std::string, std::vector<superslim::Jet>>&,
               const std::map<std::string, LorentzVector>& met);
         virtual ~Combination() {};

         const std::vector<superslim::Jet>& jets(const std::string& s="NA") const { return jets_.find(s)->second; };
         const std::vector<superslim::Lepton>& leptons() const { return leptons_; };
         const std::vector<superslim::Tau>& taus() const { return taus_; };
         const LorentzVector& met(const std::string& s="NA") const { return met_.find(s)->second; };
         const std::map<std::string, float>& weights() const { return weights_; };

         void setWeight(const std::string& s, float f) { weights_[s] = f; };
      private:
         std::map<std::string, std::vector<superslim::Jet>> jets_;
         std::vector<superslim::Lepton> leptons_;
         std::vector<superslim::Tau> taus_;
         std::map<std::string, LorentzVector> met_;

         std::map<std::string, float> weights_;

         ClassDef(Combination, 3);
   };

   class Trigger {
      public:
         Trigger() {};
#ifndef __CINT__
         Trigger(const edm::TriggerResults&, const edm::TriggerNames&);
#endif
         virtual ~Trigger() {};

         const bool single_e() const { return single_e_; };
         const bool single_mu() const { return single_mu_; };
         const bool double_e() const { return double_e_; };
         const bool double_mu() const { return double_mu_; };
         const bool mixed() const { return mixed_; };

         static void set_single_e_triggers(const std::vector<std::string>& v) { triggers_single_e_ = v; };
         static void set_single_mu_triggers(const std::vector<std::string>& v) { triggers_single_mu_ = v; };
         static void set_double_e_triggers(const std::vector<std::string>& v) { triggers_double_e_ = v; };
         static void set_double_mu_triggers(const std::vector<std::string>& v) { triggers_double_mu_ = v; };
         static void set_mixed_triggers(const std::vector<std::string>& v) { triggers_mixed_ = v; };

         static std::string get_selection();
      private:
#ifndef __CINT__
         bool fired(const edm::TriggerResults&, const edm::TriggerNames&, const std::vector<std::string>&);
#endif
         bool single_e_;
         bool single_mu_;
         bool double_e_;
         bool double_mu_;
         bool mixed_;

         static std::vector<std::string> triggers_single_e_;
         static std::vector<std::string> triggers_single_mu_;
         static std::vector<std::string> triggers_double_e_;
         static std::vector<std::string> triggers_double_mu_;
         static std::vector<std::string> triggers_mixed_;

         ClassDef(Trigger, 2);
   };

   class Event {
      public:
         Event() {};
#ifndef __CINT__
         Event(const std::vector<superslim::Combination>& cs,
               long run, long lumi, long event,
               int npv, int ntv,
               const std::vector<superslim::Vertex>& pv,
               int catergory,
               const superslim::Trigger& trigger,
               const reco::GenParticleCollection& genparticles);
#endif
         virtual ~Event() {};

         const std::vector<superslim::Combination>& combos() const { return combos_; };
         const std::map<std::string, float>& weights() const { return weights_; };

         long run() const { return run_; };
         long lumi() const { return lumi_; };
         long event() const { return event_; };

         // primary vertices
         int npv() const { return npv_; };
         // true vertices
         int ntv() const { return ntv_; };

         int hfCategory() const { return hfcat_; };
         int higgsDecay() const { return hdecay_; };

         const std::vector<superslim::Vertex>& pv() const { return pv_; };
         const Trigger& trigger() const { return trigger_; };

         void setWeight(const std::string& s, float f) { weights_[s] = f; };
      private:
         std::vector<superslim::Combination> combos_;
         std::map<std::string, float> weights_;

         long run_;
         long lumi_;
         long event_;

         int npv_;
         int ntv_;

         int hfcat_;
         int hdecay_;

         std::vector<superslim::Vertex> pv_;
         superslim::Trigger trigger_;

         ClassDef(Event, 5);
   };

   bool operator<(const PhysObject& lhs, const PhysObject& rhs);
}

#endif
