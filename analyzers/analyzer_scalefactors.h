
#ifndef analyzer_scalefactors_h
#define analyzer_scalefactors_h

#include "analyzer_selections.h"

class analyzer_scalefactors : public analyzer_selections {


public :

                  analyzer_scalefactors();
   virtual        ~analyzer_scalefactors(); 

 // event based weights
 Float_t         makeEventWeight(Float_t crossSec, Float_t lumi,
                                  Float_t nrEvents);
 void            loadPUWeight();
 void 		 loadEleTriggerEffi();
 Float_t         makePUWeight( TString dataset );
 Float_t         makeEleTriggerEffi( std::vector<int> &electron_list );
 TH1F*           PUWeights_DoubleEG     ;
 TH1F*           PUWeights_DoubleMu     ;
 TH1F*           PUWeights_MuonEG       ;
 TH1F*           PUWeights_SinglePhoton ;
 void            loadElectronReco();
 void            loadElectronWeight( TString eleid );
 void            loadMuonWeight( TString muoid );
 void            loadMuonIso( TString muoid );
 Float_t         makeElectronReco( std::vector<int> &electron_list, float &eleID_Unc, std::vector<float> &eleID_ind );
 Float_t         makeElectronWeight( std::vector<int> &electron_list, float &eleID_Unc, std::vector<float> &eleID_ind );
 Float_t         makeMuonWeight( std::vector<int> &muon_list, float &muonID_Unc, std::vector<float> &muonID_ind );
 Float_t         makeMuonIso( std::vector<int> &muon_list, float &muonISO_Unc, std::vector<float> &muonISO_ind );
 Float_t         makeHmumuWeight( Float_t dilep_pt );
 TH2F*           EleRecos;
 TH2F*           EleWeights;
 TH2F*		 Data_Leg1; 
 TH2F*		 MC_Leg1; 
 TH2F*		 Data_Leg2; 
 TH2F*		 MC_Leg2; 
 TH2F*           MuonWeights;
 TH2F*           MuonIso;
 TH2F*		 MuonTrigEffi; 
 TH2F*		 MuonTrigEffi17; 
 TH2F*		 MuonTrigEffi8; 
// Float_t         makeTTWeight( Float_t TTavgweight );

 void               loadMistagRate();
 TH1F*              h_MistagRate_pt;
 std::vector<TH1F*> h_MistagRate_pt_sys;
 TH2F*              h_MistagRate_pteta;
 std::vector<TH2F*> h_MistagRate_pteta_sys;
 float eleReco_Unc,eleID_Unc,muonID_Unc,muonISO_Unc,LeptonSF_Unc,ESF_Unc, MSF_Unc = 0.;
 std::vector<float> eleReco_ind, eleID_ind, muonID_ind, muonISO_ind;

};

#endif
