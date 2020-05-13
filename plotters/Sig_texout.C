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
  for(int i=1; i<=h->GetNbinsX(); i++){
    TString toprint = ", ";
    toprint += h->GetBinContent(i);
    fprintf(file, "%s", toprint.Data());
  }
  fprintf(file,"\n");

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

void Sig_texout(TString region, Bool_t dolog, Bool_t HIP, Bool_t doctau, Bool_t useEOS, TString description)
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

 std::vector<TString> MSbins;
 MSbins.push_back("Sig_MS-55_ctauS-1_"); 
 MSbins.push_back("Sig_MS-55_ctauS-10_"); 
 MSbins.push_back("Sig_MS-55_ctauS-100_"); 
 MSbins.push_back("Sig_MS-55_ctauS-1000_"); 
 MSbins.push_back("Sig_MS-40_ctauS-1_"); 
 MSbins.push_back("Sig_MS-40_ctauS-10_"); 
 MSbins.push_back("Sig_MS-40_ctauS-100_"); 
 MSbins.push_back("Sig_MS-40_ctauS-1000_"); 
 MSbins.push_back("Sig_MS-15_ctauS-1_"); 
 MSbins.push_back("Sig_MS-15_ctauS-10_"); 
 MSbins.push_back("Sig_MS-15_ctauS-100_"); 
 MSbins.push_back("Sig_MS-15_ctauS-1000_"); 
 std::vector<TString> uncbins;
 uncbins.clear();
 uncbins.push_back(""             ); 

 int loopEnd;
 if (doUncPlots) loopEnd=uncbins.size(); else loopEnd=1;
//if(drawSignal){extraname+="_wsig";}
//if(drawWHSignal){extraname+="_wWHsig";}
// variables to plot
 std::vector<TString> variables;
 variables.clear();

variables.push_back("nSelectedAODCaloJetTag");
//variables.push_back("nSelectedAODCaloJetTag_varbinunit");

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
 TFile* file_Data_MuonEG_H_3         ; 
 TFile* file_Data_MuonEG_H_2         ; 
 TFile* file_Data_MuonEG_G           ; 
 TFile* file_Data_SinglePhoton_H_3   ; 
 TFile* file_Data_SinglePhoton_H_2   ; 
 TFile* file_Data_SinglePhoton_G     ; 
 TFile* file_Data_DoubleMu_H_3       ; 
 TFile* file_Data_DoubleMu_H_2       ; 
 TFile* file_Data_DoubleMu_G         ; 
 TFile* file_Data_DoubleEG_H_3       ; 
 TFile* file_Data_DoubleEG_H_2       ; 
 TFile* file_Data_DoubleEG_G         ; 
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

 TH1F* h_Sig_ZH_MS55ct100_EGSUp      ;
 TH1F* h_Sig_ZH_MS55ct100_EGSDown      ;
 TH1F* h_Sig_ZH_MS55ct100_MESUp      ;
 TH1F* h_Sig_ZH_MS55ct100_MESDown      ;
 TH1F* h_Sig_ZH_MS55ct100_LeptonSFUp      ;
 TH1F* h_Sig_ZH_MS55ct100_LeptonSFDown      ;
 TH1F* h_Sig_ZH_MS55ct100_AMaxUp      ;
 TH1F* h_Sig_ZH_MS55ct100_AMaxDown      ;
 TH1F* h_Sig_ZH_MS55ct100_IPSigUp      ;
 TH1F* h_Sig_ZH_MS55ct100_IPSigDown      ;
 TH1F* h_Sig_ZH_MS55ct100_TAUp      ;
 TH1F* h_Sig_ZH_MS55ct100_TADown      ;
 TH1F* h_Sig_ZH_MS55ct100_TagVarsUp      ;
 TH1F* h_Sig_ZH_MS55ct100_TagVarsDown      ;
 TH1F* h_Sig_ggZH_MS55ct100_EGSUp      ;
 TH1F* h_Sig_ggZH_MS55ct100_EGSDown      ;
 TH1F* h_Sig_ggZH_MS55ct100_MESUp      ;
 TH1F* h_Sig_ggZH_MS55ct100_MESDown      ;
 TH1F* h_Sig_ggZH_MS55ct100_LeptonSFUp      ;
 TH1F* h_Sig_ggZH_MS55ct100_LeptonSFDown      ;
 TH1F* h_Sig_ggZH_MS55ct100_AMaxUp      ;
 TH1F* h_Sig_ggZH_MS55ct100_AMaxDown      ;
 TH1F* h_Sig_ggZH_MS55ct100_IPSigUp      ;
 TH1F* h_Sig_ggZH_MS55ct100_IPSigDown      ;
 TH1F* h_Sig_ggZH_MS55ct100_TAUp      ;
 TH1F* h_Sig_ggZH_MS55ct100_TADown      ;
 TH1F* h_Sig_ggZH_MS55ct100_TagVarsUp      ;
 TH1F* h_Sig_ggZH_MS55ct100_TagVarsDown      ;

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

 TH1F* h_Data_MuonEG_H_3       ;
 TH1F* h_Data_MuonEG_H_2       ;
 TH1F* h_Data_MuonEG_G         ;
 TH1F* h_Data_SinglePhoton_H_3 ;
 TH1F* h_Data_SinglePhoton_H_2 ;
 TH1F* h_Data_SinglePhoton_G   ;
 TH1F* h_Data_DoubleMu_H_3     ;
 TH1F* h_Data_DoubleMu_H_2     ;
 TH1F* h_Data_DoubleMu_G       ;
 TH1F* h_Data_DoubleEG_H_3     ;
 TH1F* h_Data_DoubleEG_H_2     ;
 TH1F* h_Data_DoubleEG_G       ;
 TH1F* h_ratio ;
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

 TH1F* h_Sig_MS55ct100_EGSUp  ;
 TH1F* h_Sig_MS55ct100_EGSDown  ;
 TH1F* h_Sig_MS55ct100_MESUp  ;
 TH1F* h_Sig_MS55ct100_MESDown  ;
 TH1F* h_Sig_MS55ct100_LeptonSFUp  ;
 TH1F* h_Sig_MS55ct100_LeptonSFDown  ;
 TH1F* h_Sig_MS55ct100_AMaxUp  ;
 TH1F* h_Sig_MS55ct100_AMaxDown  ;
 TH1F* h_Sig_MS55ct100_IPSigUp  ;
 TH1F* h_Sig_MS55ct100_IPSigDown  ;
 TH1F* h_Sig_MS55ct100_TAUp  ;
 TH1F* h_Sig_MS55ct100_TADown  ;
 TH1F* h_Sig_MS55ct100_TagVarsUp  ;
 TH1F* h_Sig_MS55ct100_TagVarsDown  ;



 TFile* file_Sig     ;

 TH1F* h_Sig  			;
 TH1F* h_Sig_EGSUp  		;
 TH1F* h_Sig_EGSDown  		;
 TH1F* h_Sig_MESUp  		;
 TH1F* h_Sig_MESDown  		;
 TH1F* h_Sig_LeptonSFUp  	;
 TH1F* h_Sig_LeptonSFDown  	;
 TH1F* h_Sig_AMaxUp  		;
 TH1F* h_Sig_AMaxDown  		;
 TH1F* h_Sig_IPSigUp  		;
 TH1F* h_Sig_IPSigDown  	;
 TH1F* h_Sig_TAUp  		;
 TH1F* h_Sig_TADown  		;
 TH1F* h_Sig_TagVarsUp  	;
 TH1F* h_Sig_TagVarsDown  	;

 TH1F* h_Data   ;
 // load histogram files
 //file_DY10to50                = TFile::Open( inpath + "DYJetsToLL_M-10to50_"+region+"_histograms.root"             ) ; 
 //file_Sig                    = TFile::Open( inpath + "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100_"+region+"_histograms.root"                 ) ;

for(unsigned int k=0; k<MSbins.size(); ++k){
 //file_Sig                    = TFile::Open( inpath + "Sig_MS-55_ctauS-100_"+region+".root"                 ) ;
 TString MSsample = MSbins[k];
 file_Sig                    = TFile::Open( inpath + MSsample+region+".root"                 ) ;




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
      drawData=false;
    }
    if(variable.Contains("Raw")){
     drawData=false;
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
     //h_Sig_ZH10to50                        = (TH1F*)file_DY10to50                         ->Get("h_"+varname+uncbin)->Clone( "DY10to50"                        +uncbin ) ;
     h_Sig                            = (TH1F*)file_Sig                             ->Get("h_"+varname+uncbin)->Clone( "Sig"                            +uncbin ) ;
     h_Sig_EGSUp       = (TH1F*)file_Sig    ->Get("h_"+varname+"_EGSUp" )->Clone( "Sig_EGSUp" ) ;
     h_Sig_EGSDown     = (TH1F*)file_Sig    ->Get("h_"+varname+"_EGSDown" )->Clone( "Sig_EGSDown" ) ;
     h_Sig_MESUp       = (TH1F*)file_Sig    ->Get("h_"+varname+"_MESUp" )->Clone( "Sig_MESUP" ) ;
     h_Sig_MESDown     = (TH1F*)file_Sig    ->Get("h_"+varname+"_MESDown" )->Clone( "Sig_MESDown" ) ;
     h_Sig_LeptonSFUp  = (TH1F*)file_Sig    ->Get("h_"+varname+"_LeptonSFUp" )->Clone( "Sig_LeptonSFUp" ) ;
     h_Sig_LeptonSFDown= (TH1F*)file_Sig    ->Get("h_"+varname+"_LeptonSFDown" )->Clone( "Sig_LeptonSFDown" ) ;
     h_Sig_AMaxUp       = (TH1F*)file_Sig    ->Get("h_"+varname+"_AMaxUp" )->Clone( "Sig_AMaxUP" ) ;
     h_Sig_AMaxDown     = (TH1F*)file_Sig    ->Get("h_"+varname+"_AMaxDown" )->Clone( "Sig_AMaxDown" ) ;
     h_Sig_IPSigUp       = (TH1F*)file_Sig    ->Get("h_"+varname+"_IPSigUp" )->Clone( "Sig_IPSigUP" ) ;
     h_Sig_IPSigDown     = (TH1F*)file_Sig    ->Get("h_"+varname+"_IPSigDown" )->Clone( "Sig_IPSigDown" ) ;
     h_Sig_TAUp       = (TH1F*)file_Sig    ->Get("h_"+varname+"_TAUp" )->Clone( "Sig_TAUP" ) ;
     h_Sig_TADown     = (TH1F*)file_Sig    ->Get("h_"+varname+"_TADown" )->Clone( "Sig_TADown" ) ;
     h_Sig_TagVarsUp       = (TH1F*)file_Sig    ->Get("h_"+varname+"_TagVarsUp" )->Clone( "Sig_TagVarsUP" ) ;
     h_Sig_TagVarsDown     = (TH1F*)file_Sig    ->Get("h_"+varname+"_TagVarsDown" )->Clone( "Sig_TagVarsDown" ) ;

     // rescale MC to match eras used
     h_Sig         ->Scale(MCSF); 
     h_Sig_EGSUp  ->Scale(MCSF);
     h_Sig_EGSDown  ->Scale(MCSF);
     h_Sig_MESUp  ->Scale(MCSF);
     h_Sig_MESDown  ->Scale(MCSF);
     h_Sig_LeptonSFUp  ->Scale(MCSF);
     h_Sig_LeptonSFDown  ->Scale(MCSF);
     h_Sig_AMaxUp  ->Scale(MCSF);
     h_Sig_AMaxDown  ->Scale(MCSF);
     h_Sig_IPSigUp  ->Scale(MCSF);
     h_Sig_IPSigDown  ->Scale(MCSF);
     h_Sig_TAUp  ->Scale(MCSF);
     h_Sig_TADown  ->Scale(MCSF);
     h_Sig_TagVarsUp  ->Scale(MCSF);
     h_Sig_TagVarsDown  ->Scale(MCSF);
     Float_t int_Sig_1             		= h_Sig              ->GetBinContent(1);
     Float_t int_Sig_1_EGSUp  	              	= h_Sig_EGSUp  	    ->GetBinContent(1);
     Float_t int_Sig_1_EGSDown  	        = h_Sig_EGSDown      ->GetBinContent(1);
     Float_t int_Sig_1_MESUp  	                = h_Sig_MESUp  	    ->GetBinContent(1);
     Float_t int_Sig_1_MESDown  	        = h_Sig_MESDown      ->GetBinContent(1);
     Float_t int_Sig_1_LeptonSFUp               = h_Sig_LeptonSFUp   ->GetBinContent(1);
     Float_t int_Sig_1_LeptonSFDown             = h_Sig_LeptonSFDown ->GetBinContent(1);
     Float_t int_Sig_1_AMaxUp  	              	= h_Sig_AMaxUp  	    ->GetBinContent(1);
     Float_t int_Sig_1_AMaxDown  	        = h_Sig_AMaxDown     ->GetBinContent(1);
     Float_t int_Sig_1_IPSigUp  	        = h_Sig_IPSigUp      ->GetBinContent(1);
     Float_t int_Sig_1_IPSigDown                = h_Sig_IPSigDown    ->GetBinContent(1);
     Float_t int_Sig_1_TAUp  	              	= h_Sig_TAUp  	    ->GetBinContent(1);
     Float_t int_Sig_1_TADown  	              	= h_Sig_TADown  	    ->GetBinContent(1);
     Float_t int_Sig_1_TagVarsUp                = h_Sig_TagVarsUp    ->GetBinContent(1);
     Float_t int_Sig_1_TagVarsDown              = h_Sig_TagVarsDown  ->GetBinContent(1);
     Float_t int_Sig_2             		= h_Sig              ->GetBinContent(2);
     Float_t int_Sig_2_EGSUp  	              	= h_Sig_EGSUp  	    ->GetBinContent(2);
     Float_t int_Sig_2_EGSDown  	        = h_Sig_EGSDown      ->GetBinContent(2);
     Float_t int_Sig_2_MESUp  	                = h_Sig_MESUp  	    ->GetBinContent(2);
     Float_t int_Sig_2_MESDown  	        = h_Sig_MESDown      ->GetBinContent(2);
     Float_t int_Sig_2_LeptonSFUp               = h_Sig_LeptonSFUp   ->GetBinContent(2);
     Float_t int_Sig_2_LeptonSFDown             = h_Sig_LeptonSFDown ->GetBinContent(2);
     Float_t int_Sig_2_AMaxUp  	              	= h_Sig_AMaxUp  	    ->GetBinContent(2);
     Float_t int_Sig_2_AMaxDown  	        = h_Sig_AMaxDown     ->GetBinContent(2);
     Float_t int_Sig_2_IPSigUp  	        = h_Sig_IPSigUp      ->GetBinContent(2);
     Float_t int_Sig_2_IPSigDown                = h_Sig_IPSigDown    ->GetBinContent(2);
     Float_t int_Sig_2_TAUp  	              	= h_Sig_TAUp  	    ->GetBinContent(2);
     Float_t int_Sig_2_TADown  	              	= h_Sig_TADown  	    ->GetBinContent(2);
     Float_t int_Sig_2_TagVarsUp                = h_Sig_TagVarsUp    ->GetBinContent(2);
     Float_t int_Sig_2_TagVarsDown              = h_Sig_TagVarsDown  ->GetBinContent(2);
     Float_t int_Sig_3             		= h_Sig              ->GetBinContent(3);
     Float_t int_Sig_3_EGSUp  	              	= h_Sig_EGSUp  	    ->GetBinContent(3);
     Float_t int_Sig_3_EGSDown  	        = h_Sig_EGSDown      ->GetBinContent(3);
     Float_t int_Sig_3_MESUp  	                = h_Sig_MESUp  	    ->GetBinContent(3);
     Float_t int_Sig_3_MESDown  	        = h_Sig_MESDown      ->GetBinContent(3);
     Float_t int_Sig_3_LeptonSFUp               = h_Sig_LeptonSFUp   ->GetBinContent(3);
     Float_t int_Sig_3_LeptonSFDown             = h_Sig_LeptonSFDown ->GetBinContent(3);
     Float_t int_Sig_3_AMaxUp  	              	= h_Sig_AMaxUp  	    ->GetBinContent(3);
     Float_t int_Sig_3_AMaxDown  	        = h_Sig_AMaxDown     ->GetBinContent(3);
     Float_t int_Sig_3_IPSigUp  	        = h_Sig_IPSigUp      ->GetBinContent(3);
     Float_t int_Sig_3_IPSigDown                = h_Sig_IPSigDown    ->GetBinContent(3);
     Float_t int_Sig_3_TAUp  	              	= h_Sig_TAUp  	    ->GetBinContent(3);
     Float_t int_Sig_3_TADown  	              	= h_Sig_TADown  	    ->GetBinContent(3);
     Float_t int_Sig_3_TagVarsUp                = h_Sig_TagVarsUp    ->GetBinContent(3);
     Float_t int_Sig_3_TagVarsDown              = h_Sig_TagVarsDown  ->GetBinContent(3);


     Float_t int_SigUnc_1_EGSUp  	        = int_Sig_1_EGSUp  	/int_Sig_1   ;
     Float_t int_SigUnc_1_EGSDown  	        = int_Sig_1_EGSDown     /int_Sig_1;
     Float_t int_SigUnc_1_MESUp  	        = int_Sig_1_MESUp  	/int_Sig_1   ;
     Float_t int_SigUnc_1_MESDown  	        = int_Sig_1_MESDown     /int_Sig_1;
     Float_t int_SigUnc_1_LeptonSFUp            = int_Sig_1_LeptonSFUp  /int_Sig_1;
     Float_t int_SigUnc_1_LeptonSFDown          = int_Sig_1_LeptonSFDown/int_Sig_1;
     Float_t int_SigUnc_1_AMaxUp  	        = int_Sig_1_AMaxUp  	/int_Sig_1   ;
     Float_t int_SigUnc_1_AMaxDown  	        = int_Sig_1_AMaxDown    /int_Sig_1;
     Float_t int_SigUnc_1_IPSigUp  	        = int_Sig_1_IPSigUp     /int_Sig_1;
     Float_t int_SigUnc_1_IPSigDown             = int_Sig_1_IPSigDown   /int_Sig_1;
     Float_t int_SigUnc_1_TAUp  	        = int_Sig_1_TAUp  	/int_Sig_1   ;
     Float_t int_SigUnc_1_TADown  	        = int_Sig_1_TADown  	/int_Sig_1   ;
     Float_t int_SigUnc_1_TagVarsUp             = int_Sig_1_TagVarsUp   /int_Sig_1;
     Float_t int_SigUnc_1_TagVarsDown           = int_Sig_1_TagVarsDown /int_Sig_1;
     Float_t int_SigUnc_2_EGSUp  	        = int_Sig_2_EGSUp  	/int_Sig_2    ;
     Float_t int_SigUnc_2_EGSDown  	        = int_Sig_2_EGSDown     /int_Sig_2 ;
     Float_t int_SigUnc_2_MESUp  	        = int_Sig_2_MESUp  	/int_Sig_2    ;
     Float_t int_SigUnc_2_MESDown  	        = int_Sig_2_MESDown     /int_Sig_2 ;
     Float_t int_SigUnc_2_LeptonSFUp            = int_Sig_2_LeptonSFUp  /int_Sig_2 ;
     Float_t int_SigUnc_2_LeptonSFDown          = int_Sig_2_LeptonSFDown/int_Sig_2 ;
     Float_t int_SigUnc_2_AMaxUp  	        = int_Sig_2_AMaxUp  	/int_Sig_2    ;
     Float_t int_SigUnc_2_AMaxDown  	        = int_Sig_2_AMaxDown    /int_Sig_2 ;
     Float_t int_SigUnc_2_IPSigUp  	        = int_Sig_2_IPSigUp     /int_Sig_2 ;
     Float_t int_SigUnc_2_IPSigDown             = int_Sig_2_IPSigDown   /int_Sig_2 ;
     Float_t int_SigUnc_2_TAUp  	        = int_Sig_2_TAUp  	/int_Sig_2    ;
     Float_t int_SigUnc_2_TADown  	        = int_Sig_2_TADown  	/int_Sig_2    ;
     Float_t int_SigUnc_2_TagVarsUp             = int_Sig_2_TagVarsUp   /int_Sig_2 ;
     Float_t int_SigUnc_2_TagVarsDown           = int_Sig_2_TagVarsDown /int_Sig_2 ;
     Float_t int_SigUnc_3_EGSUp  	        = int_Sig_3_EGSUp  	/int_Sig_3;
     Float_t int_SigUnc_3_EGSDown  	        = int_Sig_3_EGSDown     /int_Sig_3;
     Float_t int_SigUnc_3_MESUp  	        = int_Sig_3_MESUp  	/int_Sig_3;
     Float_t int_SigUnc_3_MESDown  	        = int_Sig_3_MESDown     /int_Sig_3;
     Float_t int_SigUnc_3_LeptonSFUp            = int_Sig_3_LeptonSFUp  /int_Sig_3;
     Float_t int_SigUnc_3_LeptonSFDown          = int_Sig_3_LeptonSFDown/int_Sig_3;
     Float_t int_SigUnc_3_AMaxUp  	        = int_Sig_3_AMaxUp  	/int_Sig_3;
     Float_t int_SigUnc_3_AMaxDown  	        = int_Sig_3_AMaxDown    /int_Sig_3;
     Float_t int_SigUnc_3_IPSigUp  	        = int_Sig_3_IPSigUp     /int_Sig_3;
     Float_t int_SigUnc_3_IPSigDown             = int_Sig_3_IPSigDown   /int_Sig_3;
     Float_t int_SigUnc_3_TAUp  	        = int_Sig_3_TAUp  	/int_Sig_3;
     Float_t int_SigUnc_3_TADown  	        = int_Sig_3_TADown  	/int_Sig_3;
     Float_t int_SigUnc_3_TagVarsUp             = int_Sig_3_TagVarsUp   /int_Sig_3;
     Float_t int_SigUnc_3_TagVarsDown           = int_Sig_3_TagVarsDown /int_Sig_3;






     
     if(domaketable){
      FILE * outfulltable;
      outfulltable = fopen (fulllogname+MSsample+"original.tex","w");
       fprintf (outfulltable, "\\documentclass{standalone}\n\n");
       fprintf (outfulltable, "\\begin{document}\n\n");
       fprintf (outfulltable, "\\begin{tabular}{rl}\n\n");
       //fprintf (outfulltable, " \\Huge %s & \\Huge %s   \\\\\n", lepton.Data(), region.Data()); 
       fprintf (outfulltable, " \\Huge %s   \\\\\n", region.Data()); 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "\\Large  Backgrounds \\\\\n");
       fprintf (outfulltable, " \\hline \n");

  
      
       fprintf (outfulltable, "Sig       	& %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1	       ,int_Sig_2		, int_Sig_3	           ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "Sig EGSUp  	& %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_EGSUp         ,int_Sig_2_EGSUp  	, int_Sig_3_EGSUp             ) ; 
       fprintf (outfulltable, "SigUnc EGSUp  	& %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_EGSUp         ,int_SigUnc_2_EGSUp  	, int_SigUnc_3_EGSUp             ) ; 
       fprintf (outfulltable, "Sig EGSDown      & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_EGSDown       ,int_Sig_2_EGSDown       , int_Sig_3_EGSDown          ) ; 
       fprintf (outfulltable, "SigUnc EGSDown      & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_EGSDown       ,int_SigUnc_2_EGSDown       , int_SigUnc_3_EGSDown          ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "Sig MESUp  	& %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_MESUp         ,int_Sig_2_MESUp  	, int_Sig_3_MESUp             ) ; 
       fprintf (outfulltable, "SigUnc MESUp  	& %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_MESUp         ,int_SigUnc_2_MESUp  	, int_SigUnc_3_MESUp             ) ; 
       fprintf (outfulltable, "Sig MESDown      & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_MESDown       ,int_Sig_2_MESDown       , int_Sig_3_MESDown          ) ; 
       fprintf (outfulltable, "SigUnc MESDown      & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_MESDown       ,int_SigUnc_2_MESDown       , int_SigUnc_3_MESDown          ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "Sig LeptonSFUp   & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_LeptonSFUp    ,int_Sig_2_LeptonSFUp    , int_Sig_3_LeptonSFUp       ) ; 
       fprintf (outfulltable, "SigUnc LeptonSFUp   & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_LeptonSFUp    ,int_SigUnc_2_LeptonSFUp    , int_SigUnc_3_LeptonSFUp       ) ; 
       fprintf (outfulltable, "Sig LeptonSFDown & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_LeptonSFDown  ,int_Sig_2_LeptonSFDown  , int_Sig_3_LeptonSFDown      ) ; 
       fprintf (outfulltable, "SigUnc LeptonSFDown & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_LeptonSFDown  ,int_SigUnc_2_LeptonSFDown  , int_SigUnc_3_LeptonSFDown      ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "Sig AMaxUp  	& %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_AMaxUp        ,int_Sig_2_AMaxUp  	, int_Sig_3_AMaxUp            ) ; 
       fprintf (outfulltable, "SigUnc AMaxUp  	& %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_AMaxUp        ,int_SigUnc_2_AMaxUp  	, int_SigUnc_3_AMaxUp            ) ; 
       fprintf (outfulltable, "Sig AMaxDown     & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_AMaxDown      ,int_Sig_2_AMaxDown      , int_Sig_3_AMaxDown         ) ; 
       fprintf (outfulltable, "SigUnc AMaxDown     & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_AMaxDown      ,int_SigUnc_2_AMaxDown      , int_SigUnc_3_AMaxDown         ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "Sig IPSigUp      & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_IPSigUp       ,int_Sig_2_IPSigUp       , int_Sig_3_IPSigUp          ) ; 
       fprintf (outfulltable, "SigUnc IPSigUncUp      & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_IPSigUp       ,int_SigUnc_2_IPSigUp       , int_SigUnc_3_IPSigUp          ) ; 
       fprintf (outfulltable, "Sig IPSigDown    & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_IPSigDown     ,int_Sig_2_IPSigDown     , int_Sig_3_IPSigDown        ) ; 
       fprintf (outfulltable, "SigUnc IPSigUncDown    & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_IPSigDown     ,int_SigUnc_2_IPSigDown     , int_SigUnc_3_IPSigDown        ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "Sig TAUp  	& %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_TAUp  	       ,int_Sig_2_TAUp  	, int_Sig_3_TAUp              ) ; 
       fprintf (outfulltable, "SigUnc TAUp  	& %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_TAUp  	       ,int_SigUnc_2_TAUp  	, int_SigUnc_3_TAUp              ) ; 
       fprintf (outfulltable, "Sig TADown  	& %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_TADown        ,int_Sig_2_TADown  	, int_Sig_3_TADown            ) ; 
       fprintf (outfulltable, "SigUnc TADown  	& %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_TADown        ,int_SigUnc_2_TADown  	, int_SigUnc_3_TADown            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "Sig TagVarsUp    & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_TagVarsUp     ,int_Sig_2_TagVarsUp     , int_Sig_3_TagVarsUp        ) ; 
       fprintf (outfulltable, "SigUnc TagVarsUp    & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_TagVarsUp     ,int_SigUnc_2_TagVarsUp     , int_SigUnc_3_TagVarsUp        ) ; 
       fprintf (outfulltable, "Sig TagVarsDown  & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_TagVarsDown   ,int_Sig_2_TagVarsDown   , int_Sig_3_TagVarsDown      ) ; 
       fprintf (outfulltable, "SigUnc TagVarsDown  & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_TagVarsDown   ,int_SigUnc_2_TagVarsDown   , int_SigUnc_3_TagVarsDown      ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "\\end{tabular}\n\n");
       fprintf (outfulltable, "\\end{document}\n\n");
      fclose (outfulltable);

     }


     // Integrals

     
   } 
  }
 } 
}
