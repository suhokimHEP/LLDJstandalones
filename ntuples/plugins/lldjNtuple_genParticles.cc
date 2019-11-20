#include "LLDJstandalones/ntuples/interface/lldjNtuple.h"
#include "LLDJstandalones/ntuples/interface/GenParticleParentage.h"
#include <TMath.h>
#include <TLorentzVector.h>

using namespace std;
bool ctauWeight = false; //Determine whether to weight or not weight the SigMC
float targetdist = 300; //To weight it, determine the target distance
//Recommended targetdist range : 10mm sample->1mm<ct<10mm
			//	 100mm sample->10mm<ct<100mm
			//	 1000mm	samplet->100mm<ct<1000mm


//Variables for branches
vector<int>   llpId;
vector<int>   llpStatus;
vector<float> llpPt;
vector<float> llpEta;
vector<float> llpPhi;
vector<float> llpMass;
vector<int>   llpDaughterId;
vector<int>   llpDaughterStatus;
vector<float> llpDaughterPt;
vector<float> llpDaughterEta;
vector<float> llpDaughterPhi;
vector<float> llpDaughterMass;
vector<float> toppts;
vector<float> Decaydist;
vector<float> Simweight;
vector<float> ctauEventWeight;

vector<float> Zpt;
vector<float> Zmass;
vector<vector<int>>   Z_daughterID;
vector<vector<int>>   Z_daughterPt;
vector<vector<int>>   Z_daughterEta;
vector<vector<int>>   Z_daughterPhi;

vector<float> llpvX;
vector<float> llpvY;
vector<float> llpvZ;
vector<float> llpDaughtervX;
vector<float> llpDaughtervY;
vector<float> llpDaughtervZ;
void lldjNtuple::branchesGenPart(TTree* tree) {

  tree->Branch("llpId",             &llpId);
  tree->Branch("llpStatus",         &llpStatus);
  tree->Branch("llpPt",             &llpPt);
  tree->Branch("llpEta",            &llpEta);
  tree->Branch("llpPhi",            &llpPhi);
  tree->Branch("llpMass",           &llpMass);
  tree->Branch("llpDaughterId",     &llpDaughterId);
  tree->Branch("llpDaughterStatus", &llpDaughterStatus);
  tree->Branch("llpDaughterPt",     &llpDaughterPt);
  tree->Branch("llpDaughterEta",    &llpDaughterEta);
  tree->Branch("llpDaughterPhi",    &llpDaughterPhi);
  tree->Branch("llpDaughterMass",   &llpDaughterMass);
  tree->Branch("toppts",            &toppts);
  if (ctauWeight) {tree->Branch("Decaydist",         &Decaydist);
  tree->Branch("Simweight",         &Simweight);
  tree->Branch("ctauEventWeight",   &ctauEventWeight);
}
  tree->Branch("Zpt",    &Zpt);
  tree->Branch("Zmass",  &Zmass);
  tree->Branch("Z_daughterID",   &Z_daughterID);
  tree->Branch("Z_daughterPt",   &Z_daughterPt);
  tree->Branch("Z_daughterEta",  &Z_daughterEta);
  tree->Branch("Z_daughterPhi",  &Z_daughterPhi);

  tree->Branch("llpvX",             &llpvX);
  tree->Branch("llpvY",             &llpvY);
  tree->Branch("llpvZ",             &llpvZ);
  tree->Branch("llpDaughtervX",             &llpDaughtervX);
  tree->Branch("llpDaughtervY",             &llpDaughtervY);
  tree->Branch("llpDaughtervZ",             &llpDaughtervZ);

}

void lldjNtuple::fillGenPart(const edm::Event& e) {

  //Initialize -- set numbers to e.g. 0 and clear vectors 
  llpId.clear();
  llpStatus.clear();
  llpPt.clear();
  llpEta.clear();
  llpPhi.clear();
  llpMass.clear();
  llpDaughterId.clear();
  llpDaughterStatus.clear();
  llpDaughterPt.clear();
  llpDaughterEta.clear();
  llpDaughterPhi.clear();
  llpDaughterMass.clear();
  toppts.clear();
  if (ctauWeight){Decaydist.clear();
  Simweight.clear();
  ctauEventWeight.clear();
}
  Zpt.clear();
  Zmass.clear();
  Z_daughterID.clear();
  Z_daughterPt.clear();
  Z_daughterEta.clear();
  Z_daughterPhi.clear();

  llpvX.clear();
  llpvY.clear();
  llpvZ.clear();
  llpDaughtervX.clear();
  llpDaughtervY.clear();
  llpDaughtervZ.clear();

  //Gen particles handle
  edm::Handle<vector<reco::GenParticle> > genParticlesHandle;
  e.getByToken(genParticlesCollection_, genParticlesHandle);
  float totEventWeight =1.0;

  //Loop over gen particles
  for (vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
  
    reco::GenParticleRef partRef = reco::GenParticleRef(genParticlesHandle,
							ip-genParticlesHandle->begin());
    genpartparentage::GenParticleParentage particleHistory(partRef);
    
    //Save top particles
    if( abs(ip->pdgId()) == 6 && ip->isLastCopy() ){
     toppts.push_back( ip->pt() );
    }
    //Save Z particles
    vector<int> Z_daughterID_;
    vector<int> Z_daughterPt_;
    vector<int> Z_daughterEta_;
    vector<int> Z_daughterPhi_;
    if( ip->pdgId() == 23 && ip->isLastCopy() && ip->status()==62 ){
     Zpt.push_back  ( ip->pt() );
     Zmass.push_back( ip->mass() );
     for(size_t i=0; i<ip->numberOfDaughters(); ++i){
       const reco::Candidate* Z_d = ip->daughter(i);
       Z_daughterID_.push_back(Z_d->pdgId());
       Z_daughterPt_.push_back(Z_d->pt());
       Z_daughterEta_.push_back(Z_d->eta());
       Z_daughterPhi_.push_back(Z_d->phi());
     }
     Z_daughterID.push_back(Z_daughterID_);
     Z_daughterPt.push_back(Z_daughterPt_);
     Z_daughterEta.push_back(Z_daughterEta_);
     Z_daughterPhi.push_back(Z_daughterPhi_);
    }

    //Save long lived BSM particles
    if( abs(ip->pdgId()) == 9000006 ){
      llpId.push_back(      ip->pdgId() );
      llpStatus.push_back(  ip->status() );
      llpPt.push_back(      ip->pt()    );
      llpEta.push_back(     ip->eta()   );
      llpPhi.push_back(     ip->phi()   );
      llpMass.push_back(    ip->mass()  );
      llpvX.push_back(    ip->vx()  );
      llpvY.push_back(    ip->vy()  );
      llpvZ.push_back(    ip->vz()  );
      TVector3 mother,daughter,diff;	
      for(size_t j=0; j<ip->numberOfDaughters(); ++j){
	const reco::Candidate* d = ip->daughter(j);
	  llpDaughtervX.push_back(d->vx());
	  llpDaughtervY.push_back(d->vy());
	  llpDaughtervZ.push_back(d->vz());
	  mother.SetXYZ(ip->vx(),ip->vy(),ip->vz());
	  daughter.SetXYZ(d->vx(),d->vy(),d->vz());
   	  diff.SetXYZ(mother.X()-daughter.X(),mother.Y()-daughter.Y(),mother.Z()-daughter.Z());	
	} 

	TLorentzVector scalar;
	scalar.SetPtEtaPhiM(ip->pt(),ip->eta(),ip->phi(),ip->mass());
	float dist = diff.Mag()/(scalar.Gamma()*abs(scalar.Beta()));
        if(ctauWeight){Decaydist.push_back(dist);
	float weight = calculatectauEventWeight(dist);
	Simweight.push_back(weight); 
        totEventWeight *= weight;}
    }
    else if ( particleHistory.hasRealParent() ) {
      reco::GenParticleRef momRef = particleHistory.parent();
      if ( momRef.isNonnull() && momRef.isAvailable() ) {
	if( abs(momRef->pdgId()) == 9000006 ){
	  llpDaughterId.push_back(     ip->pdgId() );
	  llpDaughterStatus.push_back( ip->status() );
	  llpDaughterPt.push_back(     ip->pt()    );
	  llpDaughterEta.push_back(    ip->eta()   );
	  llpDaughterPhi.push_back(    ip->phi()   );
	  llpDaughterMass.push_back(   ip->mass()  );
	}
      }
    }

  }//end gen loop
  float TTSF = 1.;
  if(toppts.size() == 2){
   TTSF = TTSF * exp( 0.0615 - 0.0005*toppts.at(0)) * exp( 0.0615 - 0.0005*toppts.at(1));
  }
  hTTSF_->Fill( TTSF );
  if(ctauWeight) ctauEventWeight.push_back(totEventWeight);
  //std::cout<<"TTSF   "<<TTSF<<std::endl;

}

Float_t lldjNtuple::calculatectauEventWeight( float dist )
{
 float weight, factor;
if (targetdist<10 && 1 < targetdist) {
	factor = 10./targetdist;
        weight = factor*exp(-1*(factor-1)*dist);
}
else if (targetdist<100 && 10 < targetdist) {
	factor = 100./targetdist;
        weight = factor*exp(-0.1*(factor-1)*dist);
}

else if (targetdist<1000 && 100< targetdist) {
	factor = 1000./targetdist;
        weight = factor*exp(-0.01*(factor-1)*dist);
}
else  {   
    std::cerr << "Targetdist out of range. Please read insturction for targetdist range for each SigMC sample." <<std::endl;
   abort(); 	
	}
 return weight;
 }


