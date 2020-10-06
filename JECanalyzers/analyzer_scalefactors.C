#include "analyzer_scalefactors.h"
#include <iostream>
#include <numeric>

//----------------------------analyzer_scalefactors
analyzer_scalefactors::analyzer_scalefactors() 
{
}

//----------------------------~analyzer_scalefactors
analyzer_scalefactors::~analyzer_scalefactors()
{
}

//----------------------------makeEventWeight
Float_t analyzer_scalefactors::makeEventWeight(Float_t crossSec,
                                        Float_t lumi,
                                        Float_t nrEvents)
{
  // 1.0 for real data
  event_weight=1.0;
  Float_t crossSecScl = crossSec;
  //if(isMC){ event_weight=lumi*crossSecScl/nrEvents; }
  //if(isMC){ event_weight=lumi*crossSecScl*AODGenEventWeight*.7323/nrEvents; }
  if(isMC){ event_weight=lumi*crossSecScl*AODGenEventWeight/nrEvents; }
  //printf("isMC: %i lumi: %0.9f crossSec: %0.9f nrEvents: %0.9f",isMC,lumi,crossSecScl,nrEvents);
  //printf("  event_weight: %0.9f\n",event_weight);

  return event_weight;
}

//----------------------------makePUWeight
Float_t analyzer_scalefactors::makePUWeight( TString dataset ){
 Int_t tmpbin;
 Float_t tmpweight;
 if( dataset.EqualTo("DoubleEG") ){
  tmpbin    = PUWeights_DoubleEG->GetBin(AODnTruePU);
  tmpweight = PUWeights_DoubleEG->GetBinContent(tmpbin);
 }
 else if( dataset.EqualTo("DoubleMu") ){
  tmpbin    = PUWeights_DoubleMu->GetBin(AODnTruePU);
  tmpweight = PUWeights_DoubleMu->GetBinContent(tmpbin);
 }
 else if( dataset.EqualTo("MuonEG") ){
  tmpbin    = PUWeights_MuonEG->GetBin(AODnTruePU);
  tmpweight = PUWeights_MuonEG->GetBinContent(tmpbin);
 }
 else if( dataset.EqualTo("SinglePhoton") ){
  tmpbin    = PUWeights_SinglePhoton->GetBin(AODnTruePU);
  tmpweight = PUWeights_SinglePhoton->GetBinContent(tmpbin);
 }
 //printf("making PU weight for %i , %i, %f \n", AODnTruePU,tmpbin,tmpweight);
 return tmpweight;
}



//----------------------------makeElectronReco
Float_t analyzer_scalefactors::makeElectronReco( std::vector<int> &electron_list, float &eleReco_Unc, std::vector<float> &eleReco_ind ){
 Float_t eleReco = 1.;
 eleReco_Unc=0.;
 eleReco_ind.clear();

 std::vector<float> eleReco_Unc_ind;
 eleReco_Unc_ind.clear();

 //check overlap with electrons
 if(electron_list.size()>0){
  for(int d=0; d<electron_list.size(); ++d){
   int eleindex = electron_list[d];
   Float_t eeta = AOD_eleEta->at(eleindex);//<------changed; don't have SCEta right now
   Float_t ept  = AOD_elePt->at(eleindex);
   if(ept<20){ept=20.1;}//SF root files lowest bin is 20. Our ePt cut is 15 for lagging lepton. Bincontent is 0 for pT<20
   Int_t tmpbinx       = EleRecos->GetXaxis()->FindBin( eeta );
   Int_t tmpbiny       = EleRecos->GetYaxis()->FindBin( ept  );
   Int_t tmpbin        = EleRecos->GetBin( tmpbinx, tmpbiny );
   eleReco_ind.push_back(EleRecos->GetBinContent(tmpbin));
   eleReco_Unc_ind.push_back(EleRecos->GetBinError(tmpbin));
  }//end electrons
  eleReco = std::accumulate( eleReco_ind.begin(), eleReco_ind.end(), 1., std::multiplies<float>());
  //std::cout<<"eleReco:"<<eleReco<<std::endl;
  eleReco_Unc = TMath::Sqrt(std::inner_product( eleReco_Unc_ind.begin(), eleReco_Unc_ind.end(), eleReco_Unc_ind.begin(), 0.));
 } // if electrons

 //printf(" done making Electron weight\n");

 return eleReco;
}



//----------------------------makeElectronWeight
Float_t analyzer_scalefactors::makeElectronWeight( std::vector<int> &electron_list, float &eleID_Unc, std::vector<float> &eleID_ind ){
 Float_t eleID = 1.;
 eleID_Unc=0.;
 eleID_ind.clear();

 std::vector<float> eleID_Unc_ind;
 eleID_Unc_ind.clear();

 //check overlap with electrons
 if(electron_list.size()>0){
  for(int d=0; d<electron_list.size(); ++d){
   int eleindex = electron_list[d];
   Float_t eeta = AOD_eleEta->at(eleindex);//<------changed; don't have SCEta right now
   Float_t ept  = AOD_elePt->at(eleindex);
   Int_t tmpbinx       = EleWeights->GetXaxis()->FindBin( eeta );
   Int_t tmpbiny       = EleWeights->GetYaxis()->FindBin( ept  );
   Int_t tmpbin        = EleWeights->GetBin( tmpbinx, tmpbiny );
   eleID_ind.push_back(EleWeights->GetBinContent(tmpbin));
   eleID_Unc_ind.push_back(EleWeights->GetBinError(tmpbin));
  }//end electrons
  eleID = std::accumulate( eleID_ind.begin(), eleID_ind.end(), 1., std::multiplies<float>());
  //std::cout<<"eleID:"<<eleID<<std::endl;
  eleID_Unc = TMath::Sqrt(std::inner_product( eleID_Unc_ind.begin(), eleID_Unc_ind.end(), eleID_Unc_ind.begin(), 0.));
 } // if electrons

 //printf(" done making Electron weight\n");

 return eleID;
}

//----------------------------makeMuonWeight ----MuonID weight
Float_t analyzer_scalefactors::makeMuonWeight( std::vector<int> &muon_list, float &muonID_Unc, std::vector<float> &muonID_ind ){
 Float_t muonID = 1.;
 muonID_Unc=0.;
 muonID_ind.clear();

 std::vector<float> muonID_Unc_ind;
 muonID_Unc_ind.clear();

 //check overlap with electrons
 if(muon_list.size()>0){
  for(int d=0; d<muon_list.size(); ++d){
   int muindex = muon_list[d];
   Float_t mueta = AOD_muEta->at(muindex);//<------changed; don't have SCEta right now
   Float_t mupt  = AOD_muPt->at(muindex);
   if(mupt>120){mupt=119.9;}//SF root files highest bin is 120. Bincontent is 0 pT>120
   Int_t tmpbiny       = MuonWeights->GetYaxis()->FindBin( mupt );
   Int_t tmpbinx       = MuonWeights->GetXaxis()->FindBin( abs(mueta)  );
   //printf(" bins %i %i\n",tmpbinx,tmpbiny);
   Int_t tmpbin        = MuonWeights->GetBin( tmpbinx, tmpbiny );
   muonID_ind.push_back(MuonWeights->GetBinContent(tmpbin));
   muonID_Unc_ind.push_back(MuonWeights->GetBinError(tmpbin));
  }//end Muons
  muonID = std::accumulate( muonID_ind.begin(), muonID_ind.end(), 1., std::multiplies<float>());
  //std::cout<<"muonID:"<<muonID<<std::endl;
  muonID_Unc = TMath::Sqrt(std::inner_product( muonID_Unc_ind.begin(), muonID_Unc_ind.end(), muonID_Unc_ind.begin(), 0.));
 } // if Muons
 return muonID;
}

//----------------------------makeMuonIso ----MuonISO weight
Float_t analyzer_scalefactors::makeMuonIso( std::vector<int> &muon_list, float &muonISO_Unc, std::vector<float> &muonISO_ind ){
 Float_t muonISO = 1.;
 muonISO_Unc=0.;
 muonISO_ind.clear();

 std::vector<float> muonISO_Unc_ind;
 muonISO_Unc_ind.clear();

 //check overlap with electrons
 if(muon_list.size()>0){
  for(int d=0; d<muon_list.size(); ++d){
   int muindex = muon_list[d];
   Float_t mueta = AOD_muEta->at(muindex);//<------changed; don't have SCEta right now
   Float_t mupt  = AOD_muPt->at(muindex);
   if(mupt>120){mupt=119.9;}//SF root files highest bin is 120. Bincontent is 0 pT>120
   Int_t tmpbiny       = MuonIso->GetYaxis()->FindBin( mupt );
   Int_t tmpbinx       = MuonIso->GetXaxis()->FindBin( abs(mueta)  );
   //printf(" bins %i %i\n",tmpbinx,tmpbiny);
   Int_t tmpbin        = MuonIso->GetBin( tmpbinx, tmpbiny );
   muonISO_ind.push_back(MuonIso->GetBinContent(tmpbin));
   muonISO_Unc_ind.push_back(MuonIso->GetBinError(tmpbin));
  }//end Muons
  muonISO = std::accumulate( muonISO_ind.begin(), muonISO_ind.end(), 1., std::multiplies<float>());
  //std::cout<<"muonISO:"<<muonISO<<std::endl;
  muonISO_Unc = TMath::Sqrt(std::inner_product( muonISO_Unc_ind.begin(), muonISO_Unc_ind.end(), muonISO_Unc_ind.begin(), 0.));
 } // if Muons
 return muonISO;
  // if Muons
}
//----------------------------makeHmumuWeight 
Float_t analyzer_scalefactors::makeHmumuWeight(Float_t dilept_pt ){
 Float_t HmumuWeight = 1.;


if(dilep_pt<10.)HmumuWeight=1.05817;
else if(dilep_pt<20.)HmumuWeight=0.994488;
else if(dilep_pt<30.)HmumuWeight=0.930056;
else if(dilep_pt<40.)HmumuWeight=0.925206;
else if(dilep_pt<50.)HmumuWeight=0.946403;
else if(dilep_pt<60.)HmumuWeight=0.962136;
else if(dilep_pt<70.)HmumuWeight= 0.965316;
else if(dilep_pt<80.)HmumuWeight=0.978209;
else if(dilep_pt<100.)HmumuWeight=0.988761;
else if(dilep_pt<150.)HmumuWeight=0.982497;
else if(dilep_pt<200.)HmumuWeight= 0.971749;
else if(dilep_pt<1000.)HmumuWeight=0.914429;
 return HmumuWeight;


}


   
//----------------------------makeMuonTriggerEffi
Float_t analyzer_scalefactors::makeMuonTriggerEffi( std::vector<int> &muon_list ){

 Float_t tmpsf,tmpweight;
 tmpsf = 1.;

 if(muon_list.size()>0){
  for(int d=0; d<muon_list.size(); ++d){
   int muindex = muon_list[d];
   Float_t mueta = AOD_muEta->at(muindex);//<------changed; don't have SCEta right now
   Float_t mupt  = AOD_muPt->at(muindex);
   if(d==0) { //pt>17GeV leading leg's Muon Trig SF
   Int_t tmpbinx       = MuonTrigEffi17->GetXaxis()->FindBin( mueta );
   Int_t tmpbiny       = MuonTrigEffi17->GetYaxis()->FindBin( mupt  );
   Int_t tmpbin        = MuonTrigEffi17->GetBin( tmpbinx, tmpbiny );
   tmpweight = MuonTrigEffi17->GetBinContent(tmpbin);}
   else { //pt<17GeV lagging leg's Muon Trig SF
   Int_t tmpbinx       = MuonTrigEffi8->GetXaxis()->FindBin( mueta );
   Int_t tmpbiny       = MuonTrigEffi8->GetYaxis()->FindBin( mupt  );
   Int_t tmpbin        = MuonTrigEffi8->GetBin( tmpbinx, tmpbiny );
   tmpweight = MuonTrigEffi8->GetBinContent(tmpbin);}
   tmpsf *= tmpweight; 
  }//end Muons
 } // if Muons


 return tmpsf;
}
////----------------------------makeTTWeight
//Float_t analyzer_scalefactors::makeTTWeight( Float_t TTavgweight){
//  Float_t TTSF = 1.; 
//  if(toppts->size() == 2){ 
//   TTSF =  ( exp( 0.0615 - 0.0005*toppts->at(0)) * exp( 0.0615 - 0.0005*toppts->at(1)) ) / TTavgweight ;
//   //std::cout<<" doing TTSF: "<<TTSF<<std::endl;
//  }
// return TTSF;
//}


//----------------------------loadPUWeight
void analyzer_scalefactors::loadPUWeight(){
 std::cout << "loading PU weight" << std::endl;
 TString filename_DoubleEG     = "puWeights_DoubleEG_69200.root" ;
 TString filename_DoubleMu     = "puWeights_DoubleMu_69200.root" ;
 TString filename_MuonEG       = "puWeights_MuonEG_69200.root" ;
 TString filename_SinglePhoton = "puWeights_SinglePhoton_69200.root" ;
 TFile* file_puweights_DoubleEG     = new TFile( filename_DoubleEG     ) ;
 TFile* file_puweights_DoubleMu     = new TFile( filename_DoubleMu     ) ;
 TFile* file_puweights_MuonEG       = new TFile( filename_MuonEG       ) ;
 TFile* file_puweights_SinglePhoton = new TFile( filename_SinglePhoton ) ;
 //std::cout <<" filename: " << filename << std::endl;
 PUWeights_DoubleEG     = (TH1F*)file_puweights_DoubleEG    ->Get("h_PUweight")->Clone("PUWeights_DoubleEG"    );
 PUWeights_DoubleMu     = (TH1F*)file_puweights_DoubleMu    ->Get("h_PUweight")->Clone("PUWeights_DoubleMu"    );
 PUWeights_MuonEG       = (TH1F*)file_puweights_MuonEG      ->Get("h_PUweight")->Clone("PUWeights_MuonEG"      );
 PUWeights_SinglePhoton = (TH1F*)file_puweights_SinglePhoton->Get("h_PUweight")->Clone("PUWeights_SinglePhoton");
 return ;
}


//----------------------------loadElectronReco
void analyzer_scalefactors::loadElectronReco(){
 std::cout << "loading Electron Reco" << std::endl;
 TString filename = "egammaEffi.txt_EGM2D_updatedAll.root" ;
 TFile* file_eleweights = new TFile( filename ) ;
 std::cout << " filename: " << filename << std::endl;
 EleRecos = (TH2F*)file_eleweights->Get("EGamma_SF2D")->Clone("EleRecos");
 return ;
}


//----------------------------loadElectronWeight
void analyzer_scalefactors::loadElectronWeight(TString eleid){
 std::cout << "loading Electron weight" << std::endl;
 TString filename = "egammaEffi_MoriondBH_ele"+eleid+".root" ;
 TFile* file_eleweights = new TFile( filename ) ;
 std::cout << " filename: " << filename << std::endl;
 EleWeights = (TH2F*)file_eleweights->Get("EGamma_SF2D")->Clone("EleWeights");
 return ;
}

//----------------------------loadMuonWeight
void analyzer_scalefactors::loadMuonWeight(TString muoid){
 std::cout << "loading Muon weight" << std::endl;
 TString filename = "Run_SF_ID.root" ;
 TFile* file_muonweights = new TFile( filename ) ;
 std::cout << " filename: " << filename << std::endl;
 TString histname = "NUM_"+muoid+"ID_DEN_genTracks_eta_pt" ;
 MuonWeights = (TH2F*)file_muonweights->Get(histname)->Clone("MuonWeights");
 return ;
}

//----------------------------loadMuonIso
void analyzer_scalefactors::loadMuonIso(TString muoid){
 std::cout << "loading Muon Iso" << std::endl;
 TString filename = "Run_SF_ISO.root" ;
 TFile* file_muoniso = new TFile( filename ) ;
 std::cout << " filename: " << filename << std::endl;
 TString histname;
 if (muoid.EqualTo("Loose")) histname = "NUM_LooseRelIso_DEN_LooseID_eta_pt" ; //ISO criteria always given as Loose
 if (muoid.EqualTo("Medium")) histname = "NUM_LooseRelIso_DEN_MediumID_eta_pt" ;
 if (muoid.EqualTo("Tight")) histname = "NUM_LooseRelIso_DEN_TightIDandIPCut_eta_pt" ;
 MuonIso = (TH2F*)file_muoniso->Get(histname)->Clone("MuonIso");
 return ;
}


//----------------------------loadMuonTrigEffi
void analyzer_scalefactors::loadMuonTriggerEffi(){
 std::cout << "loading Muon Trigger Efficiency" << std::endl;
 TString filename_Muon17     = "Muon17.root" ;
 TString filename_Muon8     = "Muon8.root" ;
 TFile* file_Muon17     = new TFile( filename_Muon17    ) ;
 TFile* file_Muon8     = new TFile(  filename_Muon8  ) ;
 MuonTrigEffi17     = (TH2F*)file_Muon17    ->Get("TrigEffi")->Clone("MuonTrigEffi17"    );
 MuonTrigEffi8     = (TH2F*)file_Muon8    ->Get("TrigEffi")->Clone("MuonTrigEffi8"    );
 //TString filename = "Muon17.root" ;
 //TFile* file_muontrig = new TFile( filename ) ;
 //MuonTrigEffi = (TH2F*)file_muontrig->Get("TrigEffi")->Clone("MuonTrigEffi");
 return ;
}
//----------------------------loadMistagRate
void analyzer_scalefactors::loadMistagRate(){

  TFile* fMistagRate = TFile::Open("feff_ZH.root", "READ");

  h_MistagRate_pt = (TH1F*)fMistagRate->Get("h_eff_mu_ZH_AllJets_AODCaloJetPtVar");
  //Systematics
  for(int i=0; i<6; i++){
    TString num = ""; num+= i;
    TString name = h_MistagRate_pt->GetName(); name+= "_sys_"; name += num;
    TH1F* temp = (TH1F*)h_MistagRate_pt->Clone();
    temp->SetName( name );
    temp->Reset();
    h_MistagRate_pt_sys.push_back( temp );
  }

  h_MistagRate_pteta = (TH2F*)fMistagRate->Get("h_eff_mu_ZH_AllJets_AODCaloJetPtVarAbsEtaVar");
  //Systematics
  for(int i=0; i<6; i++){
    TString num = ""; num+= i;
    TString name = h_MistagRate_pteta->GetName(); name+= "_sys_"; name += num;

    //TH2F* temp = (TH2F*)h_MistagRate_pteta->Clone();
    //temp->SetName( name );
    //temp->Reset();

    //For some reason the normal way leads to bizarre seg faults.  
    //Recreate from scratch:
    const int Pt_n_xbins = 10;
    float Pt_xbins[Pt_n_xbins+1] = {0, 10, 20, 30, 40, 50, 75, 100, 150, 250, 500};
    const int AbsEta_n_bins = 2;
    float AbsEta_bins[AbsEta_n_bins+1] = {0, 1.5, 2.4};
    TH2F* temp = new TH2F(name, name, Pt_n_xbins, Pt_xbins, AbsEta_n_bins, AbsEta_bins);

    h_MistagRate_pteta_sys.push_back( temp );
  }
  return;
}


