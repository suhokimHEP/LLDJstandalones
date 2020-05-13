#include <iostream>
#include "TString.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLegend.h"
#include "TPad.h"
#include "TStyle.h"
#include "TText.h"
#include "TFile.h"
#include <stdio.h>
#include <cstdlib> /* mkdir */

#include <stdlib.h>     /* getenv */

void print_hist(TH1F* h, TString name, FILE* file){

  fprintf(file, "%s", name.Data());
  for(int i=1; i<=2; i++){
    TString toprint = ", ";
    if(i==2){toprint += h->Integral(2,-1);}
    else{toprint += h->GetBinContent(i);}
    fprintf(file, "%s", toprint.Data());
  }
  fprintf(file,"\n");

  //fprintf(file, "%s", name.Data());
  //for(int i=1; i<=h->GetNbinsX(); i++){
  //  TString toprint = ", ";
  //  toprint += h->GetBinContent(i);
  //  fprintf(file, "%s", toprint.Data());
  //}
  //fprintf(file,"\n");
  //name += " err";
  //fprintf(file, "%s", name.Data());
  ////Error
  //for(int i=1; i<=h->GetNbinsX(); i++){
  //  TString toprint = ", ";
  //  toprint += h->GetBinError(i);
  //  fprintf(file, "%s", toprint.Data());
  //}
  //fprintf(file,"\n");

}

void DY_stackedRegion(TString region, Bool_t dolog, Bool_t HIP, Bool_t doctau, Bool_t useEOS, TString description)
{

// // Draw signal as lines
Bool_t drawSignal = kTRUE; //kTRUE; //kFALSE
//Bool_t drawWHSignal = kTRUE;
// Bool_t drawRatio = kTRUE;

 // Setup running configuration: IO, naming, SFs, ..
 /////////////////////////////////////////////////////

 bool drawData = true;
 bool useAlt = false; 
 bool doUncPlots = true;

 TString outpath = TString("../plots/");
 TString aversion = TString(getenv("aversion"));
 TString nversion = TString(getenv("nversion"));
 TString depot = TString(getenv("depot2"));
 TString inpath  = TString("../roots/");
 if(useEOS){
  inpath = "root://cmsxrootd.fnal.gov/"+depot+"/"+nversion+"/analyzed/"; 
}

 inpath = inpath+aversion+"/";
 outpath = outpath+aversion+"/"+region+"/";

 TString extraname = "";
 if(HIP){
  extraname+="_BCDEF";
  outpath = outpath+"BCDEF/";
 }
 if(!HIP){
  outpath = outpath+"GH/";
  extraname+="_GH";
 }

 // lumi scaling by era
 Float_t MCSF = 1.;
 Float_t lumiBCDEF = 19691. ;
 Float_t lumiGH = 16226.5 ;

// if(HIP){ MCSF=lumiBCDEF/10000.; }
// else{ MCSF=lumiGH/10000.; }
 
 //TString extraname = "";
 if(dolog){
  extraname+="_log";
  outpath = outpath+"log/";
 }

 TString mdcommand = (TString)"mkdir -p "+outpath.Data();
 const int dir_err = system(mdcommand);
 TString mdcommandtable = (TString)"mkdir -p "+outpath.Data()+"tables/";
 const int dir_err2 = system(mdcommandtable);

 std::vector<TString> uncbins;
 uncbins.clear();
 uncbins.push_back("_EGSUp"       ); 
// //uncbins.push_back("_EGSDown"     );    
 uncbins.push_back("_MESUp"       );    
// //uncbins.push_back("_MESDown"     );    
 uncbins.push_back("_AMaxUp"      );    
//// uncbins.push_back("_AMaxDown"    );    
 uncbins.push_back("_IPSigUp"     );    
////// uncbins.push_back("_IPSigDown"   );    
 uncbins.push_back("_TAUp"        );    
////// uncbins.push_back("_TADown"      );    
 uncbins.push_back("_TagVarsUp"   ); 
////// uncbins.push_back("_TagVarsDown" );  
 uncbins.push_back("_LeptonSFUp"       );    
//// uncbins.push_back("_LeptonSFDown"     );    

 int loopEnd;
 if (doUncPlots) loopEnd=uncbins.size(); else loopEnd=1;
//if(drawSignal){extraname+="_wsig";}
//if(drawWHSignal){extraname+="_wWHsig";}
// variables to plot
 std::vector<TString> variables;
 variables.clear();

variables.push_back("nSelectedAODCaloJetTag_varbin");
//variables.push_back("AOD_dilepton_Pt");
//variables.push_back("AllJets_AODCaloJetMedianLog10IPSig");
//variables.push_back("AllJets_AODCaloJetMedianLog10TrackAngle");
//variables.push_back("AllJets_AODCaloJetAlphaMax");

 //variables.push_back("nSelectedAODCaloJet_L1PFTag");
 //variables.push_back("AllJets_AODCaloJet_L1PFMedianLog10IPSig");
 //variables.push_back("AllJets_AODCaloJet_L1PFMedianLog10TrackAngle");
 //variables.push_back("AllJets_AODCaloJet_L1PFAlphaMax");

// variables.push_back("nVtx");                   
// variables.push_back("nGoodVtx");               
// variables.push_back("nTrksPV");                
 //variables.push_back("rho");                    
 //variables.push_back("pfMET");                  
 //variables.push_back("pfMETPhi");               
 //variables.push_back("pfMETsumEt");             
 //variables.push_back("nPho");                   
 //variables.push_back("phoE");                   
 //variables.push_back("phoEt");                  
 //variables.push_back("AOD_MET_pt");                 
 //variables.push_back("AOD_MET_phi");                 
///// variables.push_back("AOD_phoPt");                 
///// variables.push_back("AOD_phoEta");                 
///// variables.push_back("AOD_phoPhi");                 
///// variables.push_back("AOD_nEle");                   
///// variables.push_back("AOD_elePt");                  
///// variables.push_back("AOD_eleEta");                 
///// variables.push_back("AOD_elePhi");                 
///// variables.push_back("AOD_nMu");                    
///// variables.push_back("AOD_muPt");                   
///// variables.push_back("AOD_muEta");                  
///// variables.push_back("AOD_muPhi");                  
///// variables.push_back("AOD_nEle");                  

 //variables.push_back("htall"); 
 //variables.push_back("htaodcalojets");
 //variables.push_back("AOD_nSelectedPho");
 //variables.push_back("AOD_nSelectedEle");
 //variables.push_back("AOD_nSelectedMu");
 //variables.push_back("nSelectedAODCaloJet");
 //variables.push_back("LeadingJet_AODCaloJetPt");                      
 //variables.push_back("LeadingJet_jetEn");                      
 //variables.push_back("LeadingJet_AODCaloJetEta");                     
 //variables.push_back("LeadingJet_AODCaloJetPhi");                     
 //variables.push_back("AllJets_AODCaloJetPtVar");
 //variables.push_back("AllJets_AODCaloJetPtVar_Tag0");
 //variables.push_back("AllJets_AODCaloJetdR");
 //variables.push_back("AllJets_AODCaloJetdR_Tag0");
 //variables.push_back("AllJets_AODCaloJetNCleanMatchedTracks");
 //variables.push_back("AllJets_AODCaloJetNCleanMatchedTracks_Tag0");
///// variables.push_back("AllJets_AODCaloJetPt");                      
///// //variables.push_back("AllJets_AODCaloJetEn");                      
///// variables.push_back("AllJets_AODCaloJetEta");                     
///// variables.push_back("AllJets_AODCaloJetPhi");                     
 //-----all variables after NMinus will have dolog=true, sorry
 //variables.push_back("NMinus");                   
 //variables.push_back("Onecut");                   
 //variables.push_back("Cutflow");                   
 //variables.push_back("RawNMinus");                   
 //variables.push_back("RawOnecut");                   
 //variables.push_back("RawCutflow");                   

 // canvas and text attributes
 int canx = 1100;
 int cany = 900;
 float lmarg = 0.12;
 float rmarg = 0.05;
 if(drawData) cany = 1200;

 TCanvas* canvas = new TCanvas("canvas","canvas",canx,cany); 

 gStyle->SetOptStat(0);
 gPad->SetLogy(dolog);
 gPad->SetTickx();
 gPad->SetTicky();
 gStyle->SetLineWidth(3);
 gStyle->SetPalette(kBird);

 canvas->Clear();
 canvas->cd();

 float pad_bottom = 0;
 if(drawData) pad_bottom = 0.25;
 TPad *plotpad  = new TPad("plotpad", "plotpad", 0, pad_bottom, 1, 1);
 plotpad->SetBottomMargin(0.12);
 if(drawData) plotpad->SetBottomMargin(0.04);
 plotpad->SetLeftMargin(lmarg);
 plotpad->SetRightMargin(rmarg);
 plotpad->SetFrameLineWidth(3);
 plotpad->SetLogy(dolog);
 plotpad->Draw();

 canvas->cd();
 TPad *ratiopad = new TPad("ratiopad", "ratiopad", 0, 0, 1, 0.25);
 ratiopad->SetTopMargin(0.04);
 ratiopad->SetBottomMargin(0.4);
 ratiopad->SetFrameLineWidth(3);
 ratiopad->SetLeftMargin(lmarg);
 ratiopad->SetRightMargin(rmarg);
 ratiopad->SetLogy(0);
 ratiopad->SetGrid();
 if(drawData) ratiopad->Draw();
 canvas->cd();

 TText* title = new TText(1,1,"") ;
 title->SetTextSize(0.06);
 title->SetTextColor(kBlack);
 title->SetTextAlign(11);
 title->SetTextFont(62);
 
 TText* extra = new TText(1,1,"") ;
 extra->SetTextSize(0.05);
 extra->SetTextColor(kBlack);
 extra->SetTextAlign(11);
 //extra->SetTextAlign(13);
 extra->SetTextFont(52);
 
 TText* extra2 = new TText(1,1,"") ;
 extra2->SetTextSize(0.03);
 extra2->SetTextColor(kBlack);
 extra2->SetTextAlign(11);
 //extra2->SetTextAlign(13);
 extra2->SetTextFont(62);
 
 TText* lumi = new TText(1,1,"") ;
 lumi->SetTextSize(0.05);
 lumi->SetTextColor(kBlack);
 lumi->SetTextAlign(31);
 lumi->SetTextFont(42);

 // initialize histogram files
// TFile* file_Data_SingleMu_H_3       ; 
// TFile* file_Data_SingleMu_H_2       ; 
// TFile* file_Data_SingleMu_G         ; 
// //TFile* file_Data_SingleMu_F         ; 
// //TFile* file_Data_SingleMu_E         ; 
// //TFile* file_Data_SingleMu_D         ; 
// //TFile* file_Data_SingleMu_C         ; 
// //TFile* file_Data_SingleMu_B_2       ; 
// TFile* file_Data_SingleEle_H_3      ; 
// TFile* file_Data_SingleEle_H_2      ; 
// TFile* file_Data_SingleEle_G        ; 
// //TFile* file_Data_SingleEle_F        ; 
// //TFile* file_Data_SingleEle_E        ; 
// //TFile* file_Data_SingleEle_D        ; 
// //TFile* file_Data_SingleEle_C        ; 
// //TFile* file_Data_SingleEle_B_2      ; 
 TFile* file_Data_MuonEG_H_3         ; 
 TFile* file_Data_MuonEG_H_2         ; 
 TFile* file_Data_MuonEG_G           ; 
 //TFile* file_Data_MuonEG_F           ; 
 //TFile* file_Data_MuonEG_E           ; 
 //TFile* file_Data_MuonEG_D           ; 
 //TFile* file_Data_MuonEG_C           ; 
 //TFile* file_Data_MuonEG_B_2         ; 
 TFile* file_Data_SinglePhoton_H_3   ; 
 TFile* file_Data_SinglePhoton_H_2   ; 
 TFile* file_Data_SinglePhoton_G     ; 
 //TFile* file_Data_SinglePhoton_F     ; 
 //TFile* file_Data_SinglePhoton_E     ; 
 //TFile* file_Data_SinglePhoton_D     ; 
 //TFile* file_Data_SinglePhoton_C     ; 
 //TFile* file_Data_SinglePhoton_B_2   ; 
 TFile* file_Data_DoubleMu_H_3       ; 
 TFile* file_Data_DoubleMu_H_2       ; 
 TFile* file_Data_DoubleMu_G         ; 
 //TFile* file_Data_DoubleMu_F         ; 
 //TFile* file_Data_DoubleMu_E         ; 
 //TFile* file_Data_DoubleMu_D         ; 
 //TFile* file_Data_DoubleMu_C         ; 
 //TFile* file_Data_DoubleMu_B_2       ; 
 TFile* file_Data_DoubleEG_H_3       ; 
 TFile* file_Data_DoubleEG_H_2       ; 
 TFile* file_Data_DoubleEG_G         ; 
 //TFile* file_Data_DoubleEG_F         ; 
 //TFile* file_Data_DoubleEG_E         ; 
 //TFile* file_Data_DoubleEG_D         ; 
 //TFile* file_Data_DoubleEG_C         ; 
 //TFile* file_Data_DoubleEG_B_2       ; 
 TFile* file_DY50                                ;
 TFile* file_DY5to50_HT100To200                  ; 
 TFile* file_DY5to50_HT200To400                  ; 
 TFile* file_DY5to50_HT400To600                  ; 
 TFile* file_DY5to50_HT600ToInf                  ; 
 TFile* file_DY10to50                            ; 
 TFile* file_ggZH_HToBB_ZToLL                    ;
 TFile* file_GJets_HT40To100                     ;
 TFile* file_GJets_HT100To200                    ;
 TFile* file_GJets_HT200To400                    ;
 TFile* file_GJets_HT400To600                    ;
 TFile* file_GJets_HT600ToInf                    ;
 TFile* file_ST_s                                ;
 TFile* file_STbar_t                             ;
 TFile* file_ST_t                                ;
 TFile* file_STbar_tW                            ;
 TFile* file_ST_tW                               ;
 TFile* file_TTtoLL                              ;
 TFile* file_TTJets                              ;
 TFile* file_TTtoLfromTbar                       ;
 TFile* file_TTtoLfromT                          ;
 TFile* file_WG                                  ;
 TFile* file_WJetsToLNu                        ;
 TFile* file_WW                                ;
 TFile* file_WZ                                ;
 TFile* file_WWTo2L2Nu                         ;
 TFile* file_WWToLNuQQ                         ;
 TFile* file_WZTo1L3Nu                         ;
 TFile* file_WZTo3LNu                          ;
 TFile* file_WZToLNu2QorQQ2L                   ;
 TFile* file_ZGTo2LG                           ;
 TFile* file_ZH_HToBB_ZToLL                    ;
 TFile* file_ZZ                                ;
 TFile* file_ZZTo2L2Nu                         ;
 TFile* file_ZZTo2L2Q                          ;
 TFile* file_ZZTo2Q2Nu                         ;
 TFile* file_ZZTo4L                            ;
 TFile* file_QCD_HT100to200                    ;
 TFile* file_QCD_HT200to300                    ;
 TFile* file_QCD_HT300to500                    ;
 TFile* file_QCD_HT500to700                    ;
 TFile* file_QCD_HT700to1000                   ;
 TFile* file_QCD_HT1000to1500                  ;
 TFile* file_QCD_HT1500to2000                  ;
 TFile* file_QCD_HT2000toInf                   ;
 TFile* file_Sig_ZH_MS15ct1000     ;
 TFile* file_Sig_ZH_MS15ct100      ;
 TFile* file_Sig_ZH_MS15ct10       ;
 TFile* file_Sig_ZH_MS15ct1        ;
 TFile* file_Sig_ZH_MS40ct1000     ;
 TFile* file_Sig_ZH_MS40ct100      ;
 TFile* file_Sig_ZH_MS40ct10       ;
 TFile* file_Sig_ZH_MS40ct1        ;
 TFile* file_Sig_ZH_MS55ct1000     ;
 TFile* file_Sig_ZH_MS55ct100      ;
 TFile* file_Sig_ZH_MS55ct10       ;
 TFile* file_Sig_ZH_MS55ct1        ;
 TFile* file_Sig_ggZH_MS15ct1000   ;
 TFile* file_Sig_ggZH_MS15ct100    ;
 TFile* file_Sig_ggZH_MS15ct10     ;
 TFile* file_Sig_ggZH_MS15ct1      ;
 TFile* file_Sig_ggZH_MS40ct1000   ;
 TFile* file_Sig_ggZH_MS40ct100    ;
 TFile* file_Sig_ggZH_MS40ct10     ;
 TFile* file_Sig_ggZH_MS40ct1      ;
 TFile* file_Sig_ggZH_MS55ct1000   ;
 TFile* file_Sig_ggZH_MS55ct100    ;
 TFile* file_Sig_ggZH_MS55ct10     ;
 TFile* file_Sig_ggZH_MS55ct1      ;
 TFile* file_Sig_ZH_MS15ct300     ;
 TFile* file_Sig_ZH_MS15ct30      ;
 TFile* file_Sig_ZH_MS15ct3       ;
 TFile* file_Sig_ZH_MS40ct300     ;
 TFile* file_Sig_ZH_MS40ct30      ;
 TFile* file_Sig_ZH_MS40ct3       ;
 TFile* file_Sig_ZH_MS55ct300     ;
 TFile* file_Sig_ZH_MS55ct30      ;
 TFile* file_Sig_ZH_MS55ct3       ;
 TFile* file_Sig_ggZH_MS15ct300   ;
 TFile* file_Sig_ggZH_MS15ct30    ;
 TFile* file_Sig_ggZH_MS15ct3     ;
 TFile* file_Sig_ggZH_MS40ct300   ;
 TFile* file_Sig_ggZH_MS40ct30    ;
 TFile* file_Sig_ggZH_MS40ct3     ;
 TFile* file_Sig_ggZH_MS55ct300   ;
 TFile* file_Sig_ggZH_MS55ct30    ;
 TFile* file_Sig_ggZH_MS55ct3     ;

 /*
 TFile* file_WminusH_HToBB_WToLNu	       ;
 TFile* file_WplusH_HToBB_WToLNu	       ; 

 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS1    ;
 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS10   ;
 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS100  ;
 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS1000 ;
 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS1    ;
 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS10   ;
 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS100  ;
 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS1000 ;
 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS1    ;
 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS10   ;
 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS100  ;
 TFile* file_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS1000 ;

 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS1    ;
 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS10   ;
 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS100  ;
 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS1000 ;
 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS1    ;
 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS10   ;
 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS100  ;
 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS1000 ;
 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS1    ;
 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS10   ;
 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS100  ;
 TFile* file_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS1000 ;
 */

 // initialize histos
 TH1F* h_DY50                                ;
 TH1F* h_DY5to50_HT100To200                  ; 
 TH1F* h_DY5to50_HT200To400                  ; 
 TH1F* h_DY5to50_HT400To600                  ; 
 TH1F* h_DY5to50_HT600ToInf                  ; 
 TH1F* h_DY10to50                            ; 
 TH1F* h_ggZH_HToBB_ZToLL                    ;
 TH1F* h_GJets_HT40To100                     ;
 TH1F* h_GJets_HT100To200                    ;
 TH1F* h_GJets_HT200To400                    ;
 TH1F* h_GJets_HT400To600                    ;
 TH1F* h_GJets_HT600ToInf                    ;
 TH1F* h_ST_s                                ;
 TH1F* h_STbar_t                             ;
 TH1F* h_ST_t                                ;
 TH1F* h_STbar_tW                            ;
 TH1F* h_ST_tW                               ;
 TH1F* h_TTtoLL                              ;
 TH1F* h_TTJets                              ;
 TH1F* h_TTtoLfromTbar                       ;
 TH1F* h_TTtoLfromT                          ;
 TH1F* h_WG                                  ;
 TH1F* h_WJetsToLNu                          ;
 TH1F* h_WW                                  ;
 TH1F* h_WZ                                  ;
 TH1F* h_WWTo2L2Nu                           ;
 TH1F* h_WWToLNuQQ                           ;
 TH1F* h_WZTo1L3Nu                           ;
 TH1F* h_WZTo3LNu                            ;
 TH1F* h_WZToLNu2QorQQ2L                     ;
 TH1F* h_ZG                                  ;
 TH1F* h_ZH_HToBB_ZToLL                      ;
 TH1F* h_ZZ                                  ;
 TH1F* h_ZZTo2L2Nu                           ;
 TH1F* h_ZZTo2L2Q                            ;
 TH1F* h_ZZTo2Q2Nu                           ;
 TH1F* h_ZZTo4L                              ;
 TH1F* h_QCD_HT100to200                      ;
 TH1F* h_QCD_HT200to300                      ;
 TH1F* h_QCD_HT300to500                      ;
 TH1F* h_QCD_HT500to700                      ;
 TH1F* h_QCD_HT700to1000                     ;
 TH1F* h_QCD_HT1000to1500                    ;
 TH1F* h_QCD_HT1500to2000                    ;
 TH1F* h_QCD_HT2000toInf                     ; 
 TH1F* h_Sig_ZH_MS15ct1000     ;
 TH1F* h_Sig_ZH_MS15ct100      ;
 TH1F* h_Sig_ZH_MS15ct10       ;
 TH1F* h_Sig_ZH_MS15ct1        ;
 TH1F* h_Sig_ZH_MS40ct1000     ;
 TH1F* h_Sig_ZH_MS40ct100      ;
 TH1F* h_Sig_ZH_MS40ct10       ;
 TH1F* h_Sig_ZH_MS40ct1        ;
 TH1F* h_Sig_ZH_MS55ct1000     ;
 TH1F* h_Sig_ZH_MS55ct100      ;
 TH1F* h_Sig_ZH_MS55ct10       ;
 TH1F* h_Sig_ZH_MS55ct1        ;
 TH1F* h_Sig_ggZH_MS15ct1000   ;
 TH1F* h_Sig_ggZH_MS15ct100    ;
 TH1F* h_Sig_ggZH_MS15ct10     ;
 TH1F* h_Sig_ggZH_MS15ct1      ;
 TH1F* h_Sig_ggZH_MS40ct1000   ;
 TH1F* h_Sig_ggZH_MS40ct100    ;
 TH1F* h_Sig_ggZH_MS40ct10     ;
 TH1F* h_Sig_ggZH_MS40ct1      ;
 TH1F* h_Sig_ggZH_MS55ct1000   ;
 TH1F* h_Sig_ggZH_MS55ct100    ;
 TH1F* h_Sig_ggZH_MS55ct10     ;
 TH1F* h_Sig_ggZH_MS55ct1      ;

 TH1F* h_DY50_NoUnc      ;

 TH1F* h_DY50_MESDown      ;
 TH1F* h_DY50_EGSDown      ;
 TH1F* h_DY50_LeptonSFDown      ;
 TH1F* h_DY50_AMaxDown      ;
 TH1F* h_DY50_IPSigDown      ;
 TH1F* h_DY50_TADown      ;
 TH1F* h_DY50_TagVarsDown      ;
 TH1F* h_Sig_ZH_MS15ct300     ;
 TH1F* h_Sig_ZH_MS15ct30      ;
 TH1F* h_Sig_ZH_MS15ct3       ;
 TH1F* h_Sig_ZH_MS40ct300     ;
 TH1F* h_Sig_ZH_MS40ct30      ;
 TH1F* h_Sig_ZH_MS40ct3       ;
 TH1F* h_Sig_ZH_MS55ct300     ;
 TH1F* h_Sig_ZH_MS55ct30      ;
 TH1F* h_Sig_ZH_MS55ct3       ;
 TH1F* h_Sig_ggZH_MS15ct300   ;
 TH1F* h_Sig_ggZH_MS15ct30    ;
 TH1F* h_Sig_ggZH_MS15ct3     ;
 TH1F* h_Sig_ggZH_MS40ct300   ;
 TH1F* h_Sig_ggZH_MS40ct30    ;
 TH1F* h_Sig_ggZH_MS40ct3     ;
 TH1F* h_Sig_ggZH_MS55ct300   ;
 TH1F* h_Sig_ggZH_MS55ct30    ;
 TH1F* h_Sig_ggZH_MS55ct3     ;


 /*
 TH1F* h_WminusH_HToBB_WToLNu 		     ;
 TH1F* h_WplusH_HToBB_WToLNu		     ;


 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS1    ;
 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS10   ;
 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS100  ;
 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS1000 ;
 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS1    ;
 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS10   ;
 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS100  ;
 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS1000 ;
 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS1    ;
 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS10   ;
 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS100  ;
 TH1F* h_Sig_WplusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS1000 ;

 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS1    ;
 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS10   ;
 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS100  ;
 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS55_ctauS1000 ;
 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS1    ;
 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS10   ;
 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS100  ;
 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS40_ctauS1000 ;
 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS1    ;
 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS10   ;
 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS100  ;
 TH1F* h_Sig_WminusH_HToSSTobbbb_WToLNu_MH125_MS15_ctauS1000 ;
 */

 //TH1F* h_Data_SingleMu_H_3     ;
 //TH1F* h_Data_SingleMu_H_2     ;
 //TH1F* h_Data_SingleMu_G       ;
 ////TH1F* h_Data_SingleMu_F       ;
 ////TH1F* h_Data_SingleMu_E       ;
 ////TH1F* h_Data_SingleMu_D       ;
 ////TH1F* h_Data_SingleMu_C       ;
 ////TH1F* h_Data_SingleMu_B_2     ;
 //TH1F* h_Data_SingleEle_H_3    ;
 //TH1F* h_Data_SingleEle_H_2    ;
 //TH1F* h_Data_SingleEle_G      ;
 ////TH1F* h_Data_SingleEle_F      ;
 ////TH1F* h_Data_SingleEle_E      ;
 ////TH1F* h_Data_SingleEle_D      ;
 ////TH1F* h_Data_SingleEle_C      ;
 ////TH1F* h_Data_SingleEle_B_2    ;
 TH1F* h_Data_MuonEG_H_3       ;
 TH1F* h_Data_MuonEG_H_2       ;
 TH1F* h_Data_MuonEG_G         ;
 //TH1F* h_Data_MuonEG_F         ;
 //TH1F* h_Data_MuonEG_E         ;
 //TH1F* h_Data_MuonEG_D         ;
 //TH1F* h_Data_MuonEG_C         ;
 //TH1F* h_Data_MuonEG_B_2       ;
 TH1F* h_Data_SinglePhoton_H_3 ;
 TH1F* h_Data_SinglePhoton_H_2 ;
 TH1F* h_Data_SinglePhoton_G   ;
 //TH1F* h_Data_SinglePhoton_F   ;
 //TH1F* h_Data_SinglePhoton_E   ;
 //TH1F* h_Data_SinglePhoton_D   ;
 //TH1F* h_Data_SinglePhoton_C   ;
 //TH1F* h_Data_SinglePhoton_B_2 ;
 TH1F* h_Data_DoubleMu_H_3     ;
 TH1F* h_Data_DoubleMu_H_2     ;
 TH1F* h_Data_DoubleMu_G       ;
 //TH1F* h_Data_DoubleMu_F       ;
 //TH1F* h_Data_DoubleMu_E       ;
 //TH1F* h_Data_DoubleMu_D       ;
 //TH1F* h_Data_DoubleMu_C       ;
 //TH1F* h_Data_DoubleMu_B_2     ;
 TH1F* h_Data_DoubleEG_H_3     ;
 TH1F* h_Data_DoubleEG_H_2     ;
 TH1F* h_Data_DoubleEG_G       ;
 //TH1F* h_Data_DoubleEG_F       ;
 //TH1F* h_Data_DoubleEG_E       ;
 //TH1F* h_Data_DoubleEG_D       ;
 //TH1F* h_Data_DoubleEG_C       ;
 //TH1F* h_Data_DoubleEG_B_2     ;
 TH1F* h_ratio ;
 TH1F* h_ratio2 ;
 TH1F* h_ratiostaterr ;


 // (combined) histos to be made
 TH1F* h_DY     ;
 TH1F* h_GJets  ;
 TH1F* h_ST     ;
 TH1F* h_VV     ;
 TH1F* h_VG     ;
 TH1F* h_ZH     ;
 TH1F* h_WH     ;
 TH1F* h_TT     ;
 TH1F* h_QCD    ;
 TH1F* h_bkgtotal ;
 TH1F* h_light ;
 TH1F* h_heavy ;
 TH1F* h_other ;
 TH1F* h_light_alt ;
 TH1F* h_heavy_alt ;
 TH1F* h_other_alt ;

 TH1F* h_altDY ;
 TH1F* h_altVV ;
 TH1F* h_altTT ;



 TH1F* h_Sig_MS15ct1000 ;
 TH1F* h_Sig_MS15ct100  ;
 TH1F* h_Sig_MS15ct10   ;
 TH1F* h_Sig_MS15ct1    ;
 TH1F* h_Sig_MS40ct1000 ;
 TH1F* h_Sig_MS40ct100  ;
 TH1F* h_Sig_MS40ct10   ;
 TH1F* h_Sig_MS40ct1    ;
 TH1F* h_Sig_MS55ct1000 ;
 TH1F* h_Sig_MS55ct100  ;
 TH1F* h_Sig_MS55ct10   ;
 TH1F* h_Sig_MS55ct1    ;
 TH1F* h_Sig_MS15ct300 ;
 TH1F* h_Sig_MS15ct30  ;
 TH1F* h_Sig_MS15ct3   ;
 TH1F* h_Sig_MS40ct300 ;
 TH1F* h_Sig_MS40ct30  ;
 TH1F* h_Sig_MS40ct3   ;
 TH1F* h_Sig_MS55ct300 ;
 TH1F* h_Sig_MS55ct30  ;
 TH1F* h_Sig_MS55ct3   ;

 TH1F* h_DY_NoUnc  ;
 TH1F* h_DY_MESDown  ;
 TH1F* h_DY_EGSDown  ;
 TH1F* h_DY_LeptonSFDown  ;
 TH1F* h_DY_AMaxDown      ;
 TH1F* h_DY_IPSigDown      ;
 TH1F* h_DY_TADown      ;
 TH1F* h_DY_TagVarsDown      ;
 /*
 TH1F* h_Sig_WH_MS15ct1000;  
 TH1F* h_Sig_WH_MS15ct100 ;  
 TH1F* h_Sig_WH_MS15ct10  ;  
 TH1F* h_Sig_WH_MS15ct1   ;  
 TH1F* h_Sig_WH_MS40ct1000;  
 TH1F* h_Sig_WH_MS40ct100 ;  
 TH1F* h_Sig_WH_MS40ct10  ;  
 TH1F* h_Sig_WH_MS40ct1   ;  
 TH1F* h_Sig_WH_MS55ct1000; 
 TH1F* h_Sig_WH_MS55ct100 ;
 TH1F* h_Sig_WH_MS55ct10  ; 
 TH1F* h_Sig_WH_MS55ct1   ;
 */

 TH1F* h_Data   ;
 // load histogram files
 //file_DY10to50                = TFile::Open( inpath + "DYJetsToLL_M-10to50_"+region+"_histograms.root"             ) ; 
 file_DY50                    = TFile::Open( inpath + "DYJetsToLL_M-50_"+region+"_histograms.root"                 ) ;
cout<<"where"<<endl;

 // Start looping over variables, systematic uncertainty bins, make plots / tables / root files
  for(unsigned int j=0; j<variables.size(); ++j){
   TString variable = variables[j];

   for(unsigned int tt=0; tt<loopEnd; ++tt){
    TString uncbin = uncbins[tt];
    //Override drawData for nTag signal region
    if(region.Contains("ZH") && 
       (variable=="nSelectedAODCaloJetTag" || 
	variable.Contains("Log10IPSig") || 
	variable.Contains("Log10TrackAngle") || 
	variable.Contains("AlphaMax")) ) {
      drawData=true;
    }
    if(variable.Contains("Raw")){
     drawData=true;
    }
    if( variable.Contains("NMinus")   ||
	variable.Contains("Onecut")   ||               
	variable.Contains("Cutflow") ) {
     dolog=true;
    }

    Bool_t domaketable = kTRUE;
    if(j==0){
     domaketable = kTRUE;
    }
     TString varname = region+"_"+variable;

     printf("plotting  h_%s \n",varname.Data());

     TString outname = outpath+varname+extraname+uncbin; 
     TString fulllogname = outpath+"tables/full_"+varname+extraname+uncbin; 
     TString smalllogname = outpath+"tables/small_"+varname+extraname+uncbin; 
     TString tinylogname = outpath+"tables/tiny_"+varname+extraname+uncbin; 
     //cout << "logname: " << logname << endl;
     // get histograms from files
     //h_DY10to50                        = (TH1F*)file_DY10to50                         ->Get("h_"+varname+uncbin)->Clone( "DY10to50"                        +uncbin ) ;
     h_DY50                            = (TH1F*)file_DY50                             ->Get("h_"+varname+uncbin)->Clone( "DY50"                            +uncbin ) ;
     h_DY50_NoUnc       = (TH1F*)file_DY50    ->Get("h_"+varname )->Clone( "DY50_NoUnc" ) ;
     h_DY50_MESDown       = (TH1F*)file_DY50    ->Get("h_"+varname+"_MESDown" )->Clone( "DY50_MESDown" ) ;
     h_DY50_EGSDown       = (TH1F*)file_DY50    ->Get("h_"+varname+"_EGSDown" )->Clone( "DY50_EGSDown" ) ;
     h_DY50_LeptonSFDown       = (TH1F*)file_DY50    ->Get("h_"+varname+"_LeptonSFDown" )->Clone( "DY50_LeptonSFDown" ) ;
     h_DY50_AMaxDown       = (TH1F*)file_DY50    ->Get("h_"+varname+"_AMaxDown" )->Clone( "DY50_AMaxDown" ) ;
     h_DY50_IPSigDown       = (TH1F*)file_DY50    ->Get("h_"+varname+"_IPSigDown" )->Clone( "DY50_IPSigDown" ) ;
     h_DY50_TADown       = (TH1F*)file_DY50    ->Get("h_"+varname+"_TADown" )->Clone( "DY50_TADown" ) ;
     h_DY50_TagVarsDown       = (TH1F*)file_DY50    ->Get("h_"+varname+"_TagVarsDown" )->Clone( "DY50_TagVarsDown" ) ;

	cout<<"here"<<endl;
     h_DY = (TH1F*)h_DY50->Clone("DY");
     // h_DY->Add(h_DY10to50           ); 

     h_DY_NoUnc   = (TH1F*) h_DY50_NoUnc    ->Clone( "DY_NoUnc " ) ;
     h_DY_MESDown   = (TH1F*) h_DY50_MESDown    ->Clone( "DY_MESDown " ) ;
     h_DY_EGSDown   = (TH1F*) h_DY50_EGSDown    ->Clone( "DY_EGSDown " ) ;
     h_DY_LeptonSFDown   = (TH1F*) h_DY50_LeptonSFDown    ->Clone( "DY_LeptonSFDown " ) ;
     h_DY_AMaxDown   = (TH1F*) h_DY50_AMaxDown    ->Clone( "DY_AMaxDown " ) ;
     h_DY_IPSigDown   = (TH1F*) h_DY50_IPSigDown    ->Clone( "DY_IPSigDown " ) ;
     h_DY_TADown   = (TH1F*) h_DY50_TADown    ->Clone( "DY_TADown " ) ;
     h_DY_TagVarsDown   = (TH1F*) h_DY50_TagVarsDown    ->Clone( "DY_TagVarsDown " ) ;
     // rescale MC to match eras used
     h_DY         ->Scale(MCSF); 
     h_DY_NoUnc  ->Scale(MCSF);
     h_DY_MESDown  ->Scale(MCSF);
     h_DY_EGSDown  ->Scale(MCSF);
     h_DY_LeptonSFDown  ->Scale(MCSF);
     h_DY_AMaxDown  ->Scale(MCSF);
     h_DY_IPSigDown  ->Scale(MCSF);
     h_DY_TADown  ->Scale(MCSF);
     h_DY_TagVarsDown  ->Scale(MCSF);

     h_bkgtotal= (TH1F*)h_DY->Clone("bkgtotal");

     // Integrals
     //Float_t  int_DY10to50                 = h_DY10to50                        ->Integral(0,-1); 
     Float_t  int_DY50                     = h_DY50                            ->Integral(0,-1); 

// integrals of summed histograms
     Float_t int_DY        = h_DY       ->Integral(0,-1); 
     // set attributes
     h_DY         -> SetLineColor(kBlack); 
     h_DY        ->SetFillStyle(1001);
     h_DY        ->SetLineColor(kBlack); 
     h_DY        ->SetLineWidth(0);
     h_bkgtotal->SetFillColorAlpha(kYellow+1, 0.7);
     h_bkgtotal->SetFillStyle(1001);

     std::vector<TH1F *> v;
     if(useAlt){
       v.push_back(h_DY);
     }
     else {
       v.push_back(h_DY);
     }
     
     // make stack
     THStack *bgstack = new THStack("bgstack","");
     if(dolog){
      std::sort(v.begin(), v.end(),
		[](TH1F *a, TH1F *b) { return a->Integral() < b->Integral(); });
      for(int zz=0; zz<v.size(); zz++)
      {
       bgstack->Add(v[zz]);
       //cout <<v[zz]->Integral()<<std::endl;
      }
     }
     else{
       if(useAlt){
	 bgstack->Add(h_DY      ); 
       }
       else {
	 bgstack->Add(h_DY         ); 
       }

     }
      double tot = 0.0; 
     // make legend
     TLegend *leg;
     leg = new TLegend(0.2,0.73,0.88,0.89);
     leg->SetBorderSize(0);
     leg->SetNColumns(2);
     leg->SetFillColor(kWhite);
     if(useAlt){
       leg->AddEntry(h_DY        , " Drell-Yan", "f"); 
       leg->AddEntry(h_bkgtotal     , "MC bkg. stat. err.", "f");
     }
     else {
       leg->AddEntry(h_DY           , "Drell-Yan", "f"); 
       leg->AddEntry(h_bkgtotal     , "MC bkg. stat. err.", "f");
     }
	char charlegendprint[80];
     TLegend *sigleg = new TLegend(0.54,0.6,0.88,0.8);
     if(drawSignal){
       sigleg->SetBorderSize(0);
       sigleg->SetFillColor(kWhite);
	string legendprint = "DY50";
	legendprint += uncbin;
	strcpy(charlegendprint,legendprint.c_str());	
       //sigleg->AddEntry(h_Sig_MS55ct100   , "no", "l" ) ;
       sigleg->AddEntry(h_DY   , charlegendprint, "l" ) ;
       sigleg->AddEntry(h_DY_NoUnc   , "DY50 NoUnc  ", "l" ) ;
	if(uncbin=="_MESUp") sigleg->AddEntry(h_DY_MESDown   , "DY50 MESDown", "l" ) ;
	if(uncbin=="_EGSUp") sigleg->AddEntry(h_DY_EGSDown   , "DY50 EGSDown", "l" ) ;
	if(uncbin=="_LeptonSFUp") sigleg->AddEntry(h_DY_LeptonSFDown   , "DY50 LeptonSFDown", "l" ) ;
	if(uncbin=="_AMaxUp") sigleg->AddEntry(h_DY_AMaxDown   , "DY50 AMaxDown", "l" ) ;
	if(uncbin=="_IPSigUp") sigleg->AddEntry(h_DY_IPSigDown   , "DY50 IPSigDown", "l" ) ;
	if(uncbin=="_TAUp") sigleg->AddEntry(h_DY_TADown   , "DY50 TADown", "l" ) ;
	if(uncbin=="_TagVarsUp") sigleg->AddEntry(h_DY_TagVarsDown   , "DY50 TagVarsDown", "l" ) ;
     }

	/*
    TLegend *WHsigleg = new TLegend(0.54,0.6,0.88,0.7);
    if(drawWHSignal){
	WHsigleg->SetBorderSize(0);
	WHsigleg->SetFillColor(kWhite);
//	WHsigleg->SetHeader("W(H#rightarrow SS#rightarrow bbbb)","C");
	WHsigleg->AddEntry(h_Sig_WH_MS40ct100 , "W(H#rightarrow SS#rightarrow bbbb) M_{S}=40 c#tau_{S}=100 ", "l" );

}
*/
 //    std::cout << drawSignal <<std::endl;
     // set max and draw
     double_t ymax;
     ymax = std::max(h_DY->GetMaximum(), h_bkgtotal->GetMaximum() );
     if(dolog){
      //bgstack->SetMaximum(50000*ymax); 
      //bgstack->SetMinimum(1.0e-6);
      bgstack->SetMaximum(1000000); 
      bgstack->SetMinimum(1.0e-1);
     } 
     else {
      bgstack->SetMaximum(ymax*2);
     }
      
     plotpad->cd();
     bgstack->Draw("hist");
     //bgstack->Draw("hist e");
     bgstack->GetYaxis()->SetTitle("Events");
     //bgstack->GetYaxis()->SetTitleOffset(1.85);
     bgstack->GetYaxis()->SetTitleSize(40);
     bgstack->GetYaxis()->SetTitleFont(43);
     bgstack->GetYaxis()->SetTitleOffset(1.75);
     bgstack->GetXaxis()->SetTitle(region+"_"+varname + "    "+description);
     if(!drawData){
       bgstack->GetXaxis()->SetTitleSize(40);
       bgstack->GetXaxis()->SetTitleFont(43);
       bgstack->GetXaxis()->SetTitle(varname + "    "+description);
       //bgstack->GetXaxis()->SetTitle((TString)h_Data->GetTitle()+description);
       bgstack->GetXaxis()->SetTitleOffset(1);
       bgstack->GetXaxis()->SetLabelFont(43); //43 Absolute font size in pixel (precision 3)
       bgstack->GetXaxis()->SetLabelSize(40);//20
       bgstack->GetYaxis()->SetTitleOffset(1);
     }
     
     //h_bkgtotal->Draw("e2 sames");
     if(drawData){
       //h_Data->Draw("sames E"); 
     }

     if(drawSignal){

       h_DY->SetLineColor(kRed);
       h_DY->SetLineWidth(4);
       h_DY->SetLineStyle(2);
       h_DY->Draw("hist") ;
       h_DY->SetMaximum(10000000) ;
       h_DY->SetMinimum(.1) ;
       h_DY_NoUnc->SetLineColor(kBlack);
       h_DY_NoUnc->SetLineWidth(4);
       h_DY_NoUnc->Draw("hist sames") ;
	if(uncbin == "_MESUp"){
       h_DY_MESDown->SetLineColor(kBlue);
       h_DY_MESDown->SetLineWidth(4);
       h_DY_MESDown->SetLineStyle(2);
       h_DY_MESDown->Draw("hist sames") ;
	}
	
	if(uncbin == "_EGSUp"){
       h_DY_EGSDown->SetLineColor(kBlue);
       h_DY_EGSDown->SetLineWidth(4);
       h_DY_EGSDown->SetLineStyle(2);
       h_DY_EGSDown->Draw("hist sames") ;
	}
	
	if(uncbin == "_LeptonSFUp"){
       h_DY_LeptonSFDown->SetLineColor(kBlue);
       h_DY_LeptonSFDown->SetLineWidth(4);
       h_DY_LeptonSFDown->SetLineStyle(2);
       h_DY_LeptonSFDown->Draw("hist sames") ;
	}
	if(uncbin == "_AMaxUp"){
       h_DY_AMaxDown->SetLineColor(kBlue);
       h_DY_AMaxDown->SetLineWidth(4);
       h_DY_AMaxDown->SetLineStyle(2);
       h_DY_AMaxDown->Draw("hist sames") ;
	}
	if(uncbin == "_IPSigUp"){
       h_DY_IPSigDown->SetLineColor(kBlue);
       h_DY_IPSigDown->SetLineWidth(4);
       h_DY_IPSigDown->SetLineStyle(2);
       h_DY_IPSigDown->Draw("hist sames") ;
	}
	if(uncbin == "_TAUp"){
       h_DY_TADown->SetLineColor(kBlue);
       h_DY_TADown->SetLineWidth(4);
       h_DY_TADown->SetLineStyle(2);
       h_DY_TADown->Draw("hist sames") ;
	}
	if(uncbin == "_TagVarsUp"){
       h_DY_TagVarsDown->SetLineColor(kBlue);
       h_DY_TagVarsDown->SetLineWidth(4);
       h_DY_TagVarsDown->SetLineStyle(2);
       h_DY_TagVarsDown->Draw("hist sames") ;
	}
       sigleg->Draw();
 }
	/*	
      if(drawWHSignal){	
	h_Sig_WH_MS40ct100->SetLineColor(kBlack);
	h_Sig_WH_MS40ct100->SetLineWidth(2);
	h_Sig_WH_MS40ct100   ->Draw("hist sames") ;
	WHsigleg->Draw();
     }*/
     //leg->Draw();
 
     char lumistring [50];
     int dummy; 

     // add titles
     title->DrawTextNDC(0.2,0.91,"CMS");
     extra->DrawTextNDC(0.3,0.91,"Preliminary");
     if(HIP){
      extra2->DrawTextNDC(0.51,0.91,"Eras B-F");
      dummy=sprintf (lumistring, "%0.1f", lumiBCDEF/1000.);
     }
     else{
      extra2->DrawTextNDC(0.51,0.91,"Eras GH");
      dummy=sprintf (lumistring, "%0.1f", lumiGH/1000.);
     }
     //lumi->DrawTextNDC(0.9,0.91,"35.9 /fb (13 TeV)");
     lumi->DrawTextNDC(0.9,0.91,(TString)lumistring+" /fb (13 TeV)");
     
     if(drawData){
       ratiopad->cd();
       h_ratio = (TH1F*)h_DY->Clone("ratio");
       if(h_DY->Integral(-1,-1)>0){
	 h_ratio->Divide(h_DY_NoUnc);
       }
	if(uncbin == "_MESUp"){
        h_ratio2 = (TH1F*)h_DY_MESDown->Clone("ratio");
	h_ratio2->Divide(h_DY_NoUnc);
	}
	if(uncbin == "_EGSUp"){
        h_ratio2 = (TH1F*)h_DY_EGSDown->Clone("ratio");
  	h_ratio2->Divide(h_DY_NoUnc);
	}
	if(uncbin == "_LeptonSFUp"){
        h_ratio2 = (TH1F*)h_DY_LeptonSFDown->Clone("ratio");
	h_ratio2->Divide(h_DY_NoUnc);
	}
	if(uncbin == "_AMaxUp"){
        h_ratio2 = (TH1F*)h_DY_AMaxDown->Clone("ratio");
	h_ratio2->Divide(h_DY_NoUnc);
	}
	if(uncbin == "_IPSigUp"){
        h_ratio2 = (TH1F*)h_DY_IPSigDown->Clone("ratio");
	h_ratio2->Divide(h_DY_NoUnc);
	}
	if(uncbin == "_TAUp"){
        h_ratio2 = (TH1F*)h_DY_TADown->Clone("ratio");
	h_ratio2->Divide(h_DY_NoUnc);
	}
	if(uncbin == "_TagVarsUp"){
        h_ratio2 = (TH1F*)h_DY_TagVarsDown->Clone("ratio");
	h_ratio2->Divide(h_DY_NoUnc);
	}
       h_ratio->SetTitle(" ");
       // Y axis ratio plot settings
       h_ratio->GetYaxis()->SetTitleSize(30);
       h_ratio->GetYaxis()->SetTitleFont(43);
       h_ratio->GetYaxis()->SetTitleOffset(1.55);
       h_ratio->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
       h_ratio->GetYaxis()->SetLabelSize(20);
       h_ratio->GetYaxis()->SetNdivisions(-105);
       h_ratio->GetYaxis()->SetTitle(uncbin+"/NoUnc");
       // X axis ratio plot settings
       h_ratio->GetXaxis()->SetTitleSize(40);
       h_ratio->GetXaxis()->SetTitleFont(43);
       //h_ratio->GetXaxis()->SetTitle((TString)h_Data->GetTitle()+description);
       //h_ratio->GetXaxis()->SetTitle(region+"_"+(TString)h_Data->GetTitle()+description);
       h_ratio->GetXaxis()->SetTitleOffset(4.0);
       h_ratio->GetXaxis()->SetLabelFont(43); //43 Absolute font size in pixel (precision 3)
       h_ratio->GetXaxis()->SetLabelSize(30);//20
       h_ratio->SetMarkerStyle(20);
       h_ratio->SetMarkerColor(kRed);
       h_ratio->SetMarkerSize(1);
       h_ratio->GetYaxis()->SetRangeUser(0.8,1.2);
	if(uncbin == "_AMaxUp"|| uncbin == "_IPSigUp" || uncbin == "_TAUp" || uncbin == "_TagVarsUp"){h_ratio->GetYaxis()->SetRangeUser(0.0,2.0);}
       h_ratio->Draw("HIST p");  // draw first to get ranges set internally inside root
       h_ratio2->SetMarkerStyle(20);
       h_ratio2->SetMarkerColor(kBlue);
       h_ratio2->SetMarkerSize(1);
              
       h_ratiostaterr = (TH1F*)h_bkgtotal->Clone("ratiostaterr");
       h_ratiostaterr->Divide(h_bkgtotal);
       
       ratiopad->Update();       // need to update pad to get X min/max
       TLine *line = new TLine(ratiopad->GetUxmin(),1,ratiopad->GetUxmax(),1);
       line->SetLineColor(kBlue);
       line->SetLineWidth(3);
       line->SetLineStyle(9);
       //h_ratiostaterr->Draw("e2 same");

       line->Draw();
       h_ratio->Draw("HIST p same"); // draw points above line
       h_ratio2->Draw("HIST p same");  // draw first to get ranges set internally inside root
     }
     else{
      // ratiopad->Clear();
     }

     // save canvas
     canvas->SaveAs(outname+description+"_DY.png");
     canvas->SaveAs(outname+description+"_DY.pdf");
  
// save histograms into single root file
     TFile *outfile = TFile::Open(outname+"_DY.root","RECREATE");
     h_DY          ->Write();
     h_bkgtotal    ->Write();
   
  if( drawData ){
      h_ratio       ->Write();
      //h_ratiostaterr->Write();
     }
     bgstack       ->Write();
   } 
  }
  
}
