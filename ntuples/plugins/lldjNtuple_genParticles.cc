#include "LLDJstandalones/ntuples/interface/lldjNtuple.h"
#include "LLDJstandalones/ntuples/interface/GenParticleParentage.h"
#include <TMath.h>
#include <TLorentzVector.h>
using namespace std;


//Variables for branches
vector<int>   llpId;
vector<int>   llpStatus;
vector<float> llpPt;
vector<float> llpEta;
vector<float> llpPhi;
vector<float> llpMass;
vector<float> llpvx;
vector<float> llpvy;
vector<float> llpvz;
vector<float> Protonvx;
vector<float> Protonvy;
vector<float> Protonvz;
vector<int>   llpDaughterId;
vector<int>   llpDaughterStatus;
vector<float> llpDaughterPt;
vector<float> llpDaughterEta;
vector<float> llpDaughterPhi;
vector<float> llpDaughterMass;
vector<float> llpDaughtervx;
vector<float> llpDaughtervy;
vector<float> llpDaughtervz;
vector<int>   dauId;
vector<float> Decaydist;
vector<float> Simweight;
vector<float> toppts;
vector<int>   daunum;
vector<float> ctauEventWeight;


void lldjNtuple::branchesGenPart(TTree* tree) {

  tree->Branch("llpId",             &llpId);
  tree->Branch("llpStatus",         &llpStatus);
  tree->Branch("llpPt",             &llpPt);
  tree->Branch("llpEta",            &llpEta);
  tree->Branch("llpPhi",            &llpPhi);
  tree->Branch("llpMass",           &llpMass);
  tree->Branch("llpvx",             &llpvx);
  tree->Branch("llpvy",             &llpvy);
  tree->Branch("llpvz",             &llpvz);
  tree->Branch("Protonvx",          &Protonvx);
  tree->Branch("Protonvy",          &Protonvy);
  tree->Branch("Protonvz",          &Protonvz);
  tree->Branch("llpDaughterId",     &llpDaughterId);
  tree->Branch("llpDaughterStatus", &llpDaughterStatus);
  tree->Branch("llpDaughterPt",     &llpDaughterPt);
  tree->Branch("llpDaughterEta",    &llpDaughterEta);
  tree->Branch("llpDaughterPhi",    &llpDaughterPhi);
  tree->Branch("llpDaughterMass",   &llpDaughterMass);
  tree->Branch("llpDaughtervx",     &llpDaughtervx);
  tree->Branch("llpDaughtervy",     &llpDaughtervy);
  tree->Branch("llpDaughtervz",     &llpDaughtervz);
  tree->Branch("dauId",     &dauId);
  tree->Branch("Decaydist",         &Decaydist);
  tree->Branch("Simweight",         &Simweight);
  tree->Branch("toppts",            &toppts);
  tree->Branch("daunum",            &daunum);
  tree->Branch("ctauEventWeight",   &ctauEventWeight);

}

void lldjNtuple::fillGenPart(const edm::Event& e) {
  //std::cout<<"new event"<<std::endl;
  //Initialize -- set numbers to e.g. 0 and clear vectors 
  llpId.clear();
  llpStatus.clear();
  llpPt.clear();
  llpEta.clear();
  llpPhi.clear();
  llpMass.clear();
  llpvx.clear();
  llpvy.clear();
  llpvz.clear();
  Protonvx.clear();
  Protonvy.clear();
  Protonvz.clear();
  llpDaughterId.clear();
  llpDaughterStatus.clear();
  llpDaughterPt.clear();
  llpDaughterEta.clear();
  llpDaughterPhi.clear();
  llpDaughterMass.clear();
  llpDaughtervx.clear();
  llpDaughtervy.clear();
  llpDaughtervz.clear();
  dauId.clear();
  Decaydist.clear();
  Simweight.clear();
  toppts.clear();
  daunum.clear();
  ctauEventWeight.clear();
  //Gen particles handle
  edm::Handle<vector<reco::GenParticle> > genParticlesHandle;
  e.getByToken(genParticlesCollection_, genParticlesHandle);
  //std::cout<<"new event"<<std::endl;
  //Loop over gen particles
  bool count = false;
  int truecount = 0;
  float totEventWeight =1.0;
  for (vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
   
    reco::GenParticleRef partRef = reco::GenParticleRef(genParticlesHandle,
							ip-genParticlesHandle->begin());
    genpartparentage::GenParticleParentage particleHistory(partRef);
    
    //Save top particles
    if( abs(ip->pdgId()) == 6 && ip->isLastCopy() ){
     toppts.push_back( ip->pt() );
    }
    if(ip->pdgId() == 2212){
    Protonvx.push_back(ip->vx());
    Protonvy.push_back(ip->vy());
    Protonvz.push_back(ip->vz());	
			}
    //Save long lived BSM particles
    if( abs(ip->pdgId()) == 9000006 ){
      truecount +=1;	
      llpId.push_back(      ip->pdgId() );
      llpStatus.push_back(  ip->status() );
      llpPt.push_back(      ip->pt()    );
      llpEta.push_back(     ip->eta()   );
      llpPhi.push_back(     ip->phi()   );
      llpMass.push_back(    ip->mass()  );
      llpvx.push_back(    ip->vx()  );
      llpvy.push_back(    ip->vy()  );
      llpvz.push_back(    ip->vz()  );
      daunum.push_back(    ip->numberOfDaughters()  );
      TVector3 mother,daughter,diff;	
      for(size_t j=0; j<ip->numberOfDaughters(); ++j){
	const reco::Candidate* d = ip->daughter(j);
	  dauId.push_back(d->pdgId());	
	  mother.SetXYZ(ip->vx(),ip->vy(),ip->vz());
	  daughter.SetXYZ(d->vx(),d->vy(),d->vz());
   	  diff.SetXYZ(mother.X()-daughter.X(),mother.Y()-daughter.Y(),mother.Z()-daughter.Z());	
	} 

	TLorentzVector scalar;
	scalar.SetPtEtaPhiM(ip->pt(),ip->eta(),ip->phi(),ip->mass());
	float dist = diff.Mag()/(scalar.Gamma()*abs(scalar.Beta()));
        Decaydist.push_back(dist);
        float norm2 = 2*exp(5.18427-2.06778*dist);
        float norm = exp(5.18427-1.03389*dist);	  
	float weight = norm2/norm;
	Simweight.push_back(weight); 
        totEventWeight *= weight;
	//std::cout<<dist<<"and"<<norm2<<"and"<<norm<<"and"<<weight<<"and"<<ctauEventWeight<<std::endl;	
	  }
    else if ( particleHistory.hasRealParent() ) {
      reco::GenParticleRef momRef = particleHistory.parent();
      if ( momRef.isNonnull() && momRef.isAvailable() ) {
	if( abs(momRef->pdgId()) == 9000006&& abs(ip->pdgId())==5 ){
	  llpDaughterId.push_back(     ip->pdgId() );
	  llpDaughterStatus.push_back( ip->status() );
	  llpDaughterPt.push_back(     ip->pt()    );
	  llpDaughterEta.push_back(    ip->eta()   );
	  llpDaughterPhi.push_back(    ip->phi()   );
	  llpDaughterMass.push_back(   ip->mass()  );
	  llpDaughtervx.push_back(   ip->vx()  );
	  llpDaughtervy.push_back(   ip->vy()  );
	  llpDaughtervz.push_back(   ip->vz()  );
	  //TVector3 mother(momRef->vx(),momRef->vy(),momRef->vz());
	  //TVector3 daughter(ip->vx(),ip->vy(),ip->vz());
   	  //TVector3 diff (mother.X()-daughter.X(),mother.Y()-daughter.Y(),mother.Z()-daughter.Z());	
	  //TLorentzVector scalar;
	  //scalar.SetPtEtaPhiM(ip->pt(),ip->eta(),ip->phi(),ip->mass());
	  //float dist = diff.Mag()/(scalar.Gamma()*abs(scalar.Beta()));
          //Decaydist.push_back(dist);
          //float norm = exp(9.35546-13.1714*dist);	  
          //float norm2 = 0.5*exp(9.35546-6.5857*dist);
          //float norm2 = 2*exp(9.58700-2.69388*dist);
          //float norm = exp(9.58700-1.34694*dist);	  
          //float norm2 = 0.5*exp(9.58700-.67347*dist);
          //float norm2 = 2*exp(10.1402-.264756*dist);
          //float norm = exp(10.1402-.132378*dist);	  
          //float norm2 = 0.5*exp(10.1402-.066189*dist);
          //float norm2 = 2*exp(10.1320-.0262712*dist);
          //float norm = exp(10.1320-.0131356*dist);	  
          //float norm2 = 0.5*exp(10.1320-.0065678*dist);
	  //float weight = norm2/norm;
	//if(weight>100){std::cout<<"norm:"<<norm<<"norm2:"<<norm2<<std::endl;
	//std::cout<<dist<<"and"<<norm<<"and"<<norm2<<"and"<<weight<<std::endl;
	  //Simweight.push_back(weight); 
          //double Energy = scalar.Gamma()*ip->mass();
          //scalar2.SetPxPyPzE(ip->px(),ip->py(),ip->pz(),Energy);
	  //double g = scalar2.Gamma();
          //scalar3.SetXYZM(mother.X()-daughter.X(),mother.Y()-daughter.Y(),mother.Z()-daughter.Z(),125);
 	  //std::cout<<g<<"and"<<scalar.Gamma()<<"and"<<scalar3.Gamma()<<std::endl;
	  //Double_t b = scalar.Beta();
	  //Decaydist.push_back(g*diff.Mag());
	  //std::cout<<mother.X()<<daughter.X()<<diff.X()<<std::endl;	  

	}
      }
    }

  }//end gen loop
  //if (truecount ==2) {count = true;}
  //std::cout<<count<<std::endl;
  float TTSF = 1.;
  if(toppts.size() == 2){
   TTSF = TTSF * exp( 0.0615 - 0.0005*toppts.at(0)) * exp( 0.0615 - 0.0005*toppts.at(1));
  }
  hTTSF_->Fill( TTSF );
  //std::cout<<"TTSF   "<<TTSF<<std::endl;
  ctauEventWeight.push_back(totEventWeight);
}
