#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/VertexReco/interface/Vertex.h"

#include "ttH/TauRoast/interface/SuperSlim.h"

namespace id {
   const std::vector<std::pair<std::string, id::value>> values = {
      {"VTight", VTight},
      {"Tight", Tight},
      {"Medium", Medium},
      {"Loose", Loose},
      {"VLoose", VLoose}
   };
}

namespace superslim {
   Vertex::Vertex(const reco::Vertex& v) :
      x_(v.x()),
      y_(v.y()),
      z_(v.z()),
      x_error_(v.xError()),
      y_error_(v.yError()),
      z_error_(v.zError()),
      rho_(v.position().rho()),
      normalized_chi2_(v.normalizedChi2()),
      ndof_(v.ndof())
   {
   }

   PhysObject::PhysObject(const reco::Candidate* c) :
      charge_(c->charge()),
      p_(c->p4()),
      match_(6),
      pdg_id_(c->pdgId()),
      gen_pdg_id_(0)
   {
   }

   const reco::Candidate *
   PhysObject::getFinal(const reco::Candidate * c)
   {
      auto id = c->pdgId();

      const reco::Candidate *radstate = 0;
      for (unsigned int i = 0; i < c->numberOfDaughters(); ++i) {
         if (c->daughter(i) and c->daughter(i)->pdgId() == id) {
            radstate = c->daughter(i);
            break;
         }
      }

      if (radstate)
         return getFinal(radstate);

      return c;
   }

   const reco::GenParticle*
   PhysObject::getMatch(const reco::Candidate& c, const reco::GenParticleCollection& coll)
   {
      static const auto veto = {11, 12, 13, 14, 16};

      typedef std::pair<double, const reco::GenParticle*> Match;
      std::vector<Match> cands;

      for (auto& p: coll) {
         reco::Candidate::LorentzVector p4;
         if (abs(p.pdgId()) == 15) {
            for (unsigned int i = 0; i < p.numberOfDaughters(); ++i) {
               auto d = getFinal(p.daughter(i));
               if (std::find(veto.begin(), veto.end(), abs(d->pdgId())) != veto.end())
                  continue;
               p4 += d->p4();
            }
         } else {
            p4 = p.p4();
         }
         auto dR = deltaR(p4, c.p4());
         if (dR > 0.2)
            continue;

         if (abs(p.pdgId()) == 11 and p.statusFlags().isPrompt())
            match_ = 1;
         else if (abs(p.pdgId()) == 13 and p.isPromptFinalState())
            match_ = 2;
         else if (abs(p.pdgId()) == 11 and p.statusFlags().isDirectPromptTauDecayProduct())
            match_ = 3;
         else if (abs(p.pdgId()) == 13 and p.isDirectPromptTauDecayProductFinalState())
            match_ = 4;
         else if (abs(p.pdgId()) == 15)
            match_ = 5;
         else
            continue;

         cands.push_back(std::make_pair(dR, &p));
      }
      auto min = std::min_element(cands.begin(), cands.end(), [](const Match& a, const Match& b) { return a.first < b.first; });
      if (min != cands.end() and min->first < 0.5)
         return min->second;
      return 0;
   }


   int
   PhysObject::parentId() const
   {
      int id = 0;
      if (parents_.size() == 0)
         return id;
      for (const auto& p: parents_) {
         if (id > 0) {
            id *= -1;
            break;
         }
         id = std::abs(p.pdgId());
      }
      return id;
   }

   int
   PhysObject::grandParentId() const
   {
      int id = 0;
      if (parents_.size() == 0)
         return id;
      for (const auto& p: parents_) {
         if (id > 0) {
            id *= -1;
            break;
         }
         id = std::abs(p.parentId());
      }
      return id;
   }

   void
   PhysObject::setGenInfo(const reco::GenParticle* p, int level)
   {
      if (!p)
         return;

      gen_p_ = p->p4();
      gen_pdg_id_ = p->pdgId();

      if (level <= 0)
         return;

      for (unsigned int i = 0; i < p->numberOfMothers(); ++i) {
         auto mother = dynamic_cast<const reco::GenParticle*>(p->mother(i));

         while (mother and mother->pdgId() == p->pdgId()) {
            if (mother->numberOfMothers() > 0) {
               mother = dynamic_cast<const reco::GenParticle*>(mother->mother(0));
            } else {
               mother = 0;
               break;
            }
         }

         if (!mother)
            continue;

         PhysObject o(mother);
         o.setGenInfo(mother, level - 1);
         parents_.push_back(o);
      }
   }

   Jet::Jet(const pat::Jet& j, const reco::GenParticleCollection& particles) :
      PhysObject(&j),
      csv_(j.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags")),
      flavor_(j.hadronFlavour())
   {
      getMatch(j, particles);
      setGenInfo(j.genParton());
   }

   Lepton::Lepton(const pat::Electron& e, float rel_iso, const reco::Vertex& pv, const reco::BeamSpot& bs, const reco::GenParticleCollection& particles) :
      PhysObject(&e),
      type_(Lepton::e),
      charge_check_(e.isGsfCtfScPixChargeConsistent()),
      impact_parameter_(e.dB(pat::Electron::PV3D)),
      impact_parameter_error_(e.edB(pat::Electron::PV3D)),
      rel_iso_(rel_iso)
   {
      getMatch(e, particles);
      setGenInfo(e.genParticle());

      if (e.gsfTrack().isAvailable()) {
         corrected_d0_ = e.gsfTrack()->dxy(bs.position());
         corrected_dz_ = e.gsfTrack()->dz(pv.position());
      }

      if (e.hasUserFloat("idTightCut") and e.hasUserFloat("idLooseCut") and
            e.hasUserFloat("idTightMVA") and e.hasUserFloat("idLooseMVA")) {
         cut_ = (e.userFloat("idTightCut") > .5) + (e.userFloat("idLooseCut") > .5);
         mva_ = (e.userFloat("idTightMVA") > .5) + (e.userFloat("idLooseMVA") > .5);
      } else {
         cut_ = 0;
         mva_ = 0;
      }
   }

   Lepton::Lepton(const pat::Muon& m, float rel_iso, const reco::Vertex& pv, const reco::BeamSpot& bs, const reco::GenParticleCollection& particles) :
      PhysObject(&m),
      type_(Lepton::mu),
      charge_check_(false),
      impact_parameter_(m.dB(pat::Muon::PV3D)),
      impact_parameter_error_(m.edB(pat::Muon::PV3D)),
      rel_iso_(rel_iso)
   {
      getMatch(m, particles);
      setGenInfo(m.genParticle());

      if (m.innerTrack().isAvailable()) {
         charge_check_ = m.innerTrack()->ptError() / m.innerTrack()->pt() < .2;
         corrected_d0_ = m.innerTrack()->dxy(bs.position());
         corrected_dz_ = m.innerTrack()->dz(pv.position());
      }

      if (m.hasUserFloat("idTightCut") and m.hasUserFloat("idLooseCut") and
            m.hasUserFloat("idTightMVA") and m.hasUserFloat("idLooseMVA")) {
         cut_ = (m.userFloat("idTightCut") > .5) + (m.userFloat("idLooseCut") > .5);
         mva_ = (m.userFloat("idTightMVA") > .5) + (m.userFloat("idLooseMVA") > .5);
      } else {
         cut_ = 0;
         mva_ = 0;
      }
   }

   Tau::Tau(const pat::Tau& t, const reco::GenParticleCollection& particles) :
      PhysObject(&t),
      decay_mode_(t.decayMode()),
      prongs_(t.signalChargedHadrCands().size()),
      leading_track_pt_(-1.0)
   {
      auto match = getMatch(t, particles);
      if (match) {
         for (unsigned int i = 0; i < match->numberOfDaughters(); ++i) {
            auto d = getFinal(match->daughter(i));
            if (abs(d->pdgId()) % 2 == 0 and abs(d->pdgId()) > 10 and abs(d->pdgId()) < 20)
               continue;
            gen_vis_p_ = d->p4();
         }
         setGenInfo(match);
      }

      // for (auto& pair: t.tauIDs()) {
      //    std::cout << pair.first << std::endl;
      // }
      // std::cout << "=== THE END ===" << std::endl;

      if (t.leadChargedHadrCand().isNonnull()) {
         leading_track_pt_ = t.leadChargedHadrCand()->pt();
         charge_ = t.leadChargedHadrCand()->charge();
      }

      raw_isolation_3hits03_ = 0.; // NOT PRESENT: t.tauID("byCombinedIsolationDeltaBetaCorrRaw3HitsdR03");
      raw_isolation_3hits05_ = t.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits");

      isolation_3hits03_ = getID("by", "CombinedIsolationDeltaBetaCorr3HitsdR03", t);
      isolation_3hits05_ = getID("by", "CombinedIsolationDeltaBetaCorr3Hits", t);
      isolation_mva03_ = getID("by", "IsolationMVArun2v1DBdR03oldDMwLT", t);
      isolation_mva05_ = getID("by", "IsolationMVArun2v1DBoldDMwLT", t);

      veto_electron_ = getID("againstElectron", "MVA6", t);
      veto_muon_ = getID("againstMuon", "3", t);
   }

   id::value Tau::getID(const std::string& prefix, const std::string& suffix, const pat::Tau& t) const {
      for (const auto& _id: id::values) {
         std::string name = prefix + _id.first + suffix;
         if (t.isTauIDAvailable(name) and t.tauID(name) > .5)
            return _id.second;
      }
      return id::None;
   };

   Combination::Combination(
         const std::vector<Tau>& taus,
         const std::vector<Lepton>& leptons,
         const std::map<std::string, std::vector<Jet>>& jets,
         const std::map<std::string, LorentzVector>& met) :
      jets_(jets),
      leptons_(leptons),
      taus_(taus),
      met_(met)
   {
   }

   bool
   operator<(const PhysObject& lhs, const PhysObject& rhs)
   {
      return rhs.p4().Pt() < lhs.p4().Pt();
   }

   std::vector<std::string> Trigger::triggers_single_e_ = {};
   std::vector<std::string> Trigger::triggers_single_mu_= {};

   std::string
   Trigger::get_selection()
   {
      std::vector<std::string> vs;
      std::copy(triggers_single_e_.begin(), triggers_single_e_.end(), std::back_inserter(vs));
      std::copy(triggers_single_mu_.begin(), triggers_single_mu_.end(), std::back_inserter(vs));

      std::ostringstream os;
      for (auto& s: vs) {
         if (os.str().size() > 0)
            os << " OR ";
         os << s << "*";
      }

      return os.str();
   }

   Trigger::Trigger(const edm::TriggerResults& trig, const edm::TriggerNames& names) :
      single_e_(false),
      single_mu_(false),
      double_e_(false),
      double_mu_(false),
      mixed_(false)
   {
      single_e_ = fired(trig, names, triggers_single_e_);
      single_mu_ = fired(trig, names, triggers_single_mu_);
   }

   bool
   Trigger::fired(const edm::TriggerResults& res, const edm::TriggerNames& names, const std::vector<std::string>& paths)
   {
      for (auto& name: names.triggerNames()) {
         for (auto& path: paths) {
            // returns <>1 if strings don't match
            if (name.compare(0, path.size(), path))
               continue;
            auto idx = names.triggerIndex(name);
            if (idx < res.size() and res.accept(idx))
               return true;
         }
      }
      return false;
   }

   Event::Event(const std::vector<superslim::Combination>& cs,
         long run, long lumi, long event,
         int npv, int ntv,
         const std::vector<superslim::Vertex>& pv,
         int category,
         const superslim::Trigger& trigger,
         const reco::GenParticleCollection& genparticles) :
      combos_(cs),
      run_(run), lumi_(lumi), event_(event),
      npv_(npv), ntv_(ntv),
      hfcat_(category),
      hdecay_(-1),
      pv_(pv),
      trigger_(trigger)
   {
      for (const auto& p: genparticles) {
         if (abs(p.pdgId()) == 25) {
            bool use = true;
            int id = -1;
            for (unsigned int i = 0; i < p.numberOfDaughters() and use; ++i) {
               int did = abs(p.daughter(i)->pdgId());
               if (did == 25) {
                  use = false;
               } else if (id > 0 and id != did) {
                  if (did > id) {
                     id = (id * 1000) + did;
                  } else {
                     id = (did * 1000) + id;
                  }
               } else {
                  id = did;
               }
            }

            if (id > 0 and use) {
               hdecay_ = id;
               break;
            }
         }
      }
   }
}

ClassImp(superslim::Vertex);
ClassImp(superslim::PhysObject);
ClassImp(superslim::Jet);
ClassImp(superslim::Lepton);
ClassImp(superslim::Tau);
ClassImp(superslim::Combination);
ClassImp(superslim::Trigger);
ClassImp(superslim::Event);
