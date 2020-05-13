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
#include <cmath>     /* getenv */

void print_hist(TH1F* h, TString name, FILE* file){

  fprintf(file, "%s", name.Data());
  for(int i=1; i<=h->GetNbinsX(); i++){
    TString toprint = ", ";
    toprint += h->GetBinContent(i);
    fprintf(file, "%s", toprint.Data());
  }
  fprintf(file,"\n");
}


std::vector<float> cal_0u(Float_t unc){
  std::vector<float> value;
  float Tag0 = 1-unc;
  float Tag1 = unc;
  value.push_back(Tag0);
  value.push_back(Tag1);
  return value;
}

std::vector<float> cal_1u(Float_t unc){
  std::vector<float> value;
  float fail = 1-unc;
  float Tag0 = fail*fail;
  float Tag1 = 2*unc*fail;
  float Tag2 = unc*unc;
  value.push_back(Tag0);
  value.push_back(Tag1);
  value.push_back(Tag2);

  return value;
}

std::vector<float> cal_2u(Float_t unc){
  std::vector<float> value;
  float fail = 1-unc;
  float Tag0 = fail*fail*fail;;
  float Tag1 = 3*unc*fail*fail;
  float Tag2 = 3*unc*unc*fail;
  float Tag3 = unc*unc*unc;
  value.push_back(Tag0);
  value.push_back(Tag1);
  value.push_back(Tag2);
  value.push_back(Tag3);


  return value;
}


std::vector<float> fill_vec(std::vector<float> vec1, std::vector<float> vec2, std::vector<float> vec3, std::vector<float> dist){
  std::vector<float> value;
  float Tag0 = vec1.at(0)*dist.at(0)+vec2.at(0)*dist.at(1)+vec3.at(0)*dist.at(2);
  float Tag1 = vec1.at(1)*dist.at(0)+vec2.at(1)*dist.at(1)+vec3.at(1)*dist.at(2);
  float Tag2 = vec2.at(2)*dist.at(1)+vec3.at(2)*dist.at(2);
  float Tag3 = vec3.at(3)*dist.at(2);
  value.push_back(Tag0);
  value.push_back(Tag1);
  value.push_back(Tag2);
  value.push_back(Tag3);


  return value;
}

std::vector<float> calc_vec(std::vector<float> vec1, std::vector<float> vec2){
  std::vector<float> value;
  float Tag0 = vec2.at(0)/vec1.at(0);
  float Tag1 = vec2.at(1)/vec1.at(1);
  float Tag2 = vec2.at(2)/vec1.at(2);
  float Tag3 = vec2.at(3)/vec1.at(3);
  value.push_back(Tag0);
  value.push_back(Tag1);
  value.push_back(Tag2);
  value.push_back(Tag3);


  return value;
}





void Sig_model(TString region, Bool_t dolog, Bool_t HIP, Bool_t doctau, Bool_t useEOS, TString description)
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
 //MSbins.push_back("Sig_MS-55_ctauS-1_"); 
 //MSbins.push_back("Sig_MS-55_ctauS-10_"); 
 MSbins.push_back("Sig_MS-55_ctauS-100_"); 
 //MSbins.push_back("Sig_MS-55_ctauS-1000_"); 
 //MSbins.push_back("Sig_MS-40_ctauS-1_"); 
 //MSbins.push_back("Sig_MS-40_ctauS-10_"); 
 //MSbins.push_back("Sig_MS-40_ctauS-100_"); 
 //MSbins.push_back("Sig_MS-40_ctauS-1000_"); 
 //MSbins.push_back("Sig_MS-15_ctauS-1_"); 
 //MSbins.push_back("Sig_MS-15_ctauS-10_"); 
 //MSbins.push_back("Sig_MS-15_ctauS-100_"); 
 //MSbins.push_back("Sig_MS-15_ctauS-1000_"); 










 std::vector<TString> uncbins;
 uncbins.clear();
 uncbins.push_back(""             ); 
// uncbins.push_back("_EGSUp"       ); 
// uncbins.push_back("_EGSDown"     );    
// uncbins.push_back("_MESUp"       );    
// uncbins.push_back("_MESDown"     );    
// uncbins.push_back("_AMaxUp"      );    
// uncbins.push_back("_AMaxDown"    );    
//// uncbins.push_back("_IPSigUp"     );    
//// uncbins.push_back("_IPSigDown"   );    
//// uncbins.push_back("_TAUp"        );    
//// uncbins.push_back("_TADown"      );    
//// uncbins.push_back("_TagVarsUp"   ); 
//// uncbins.push_back("_TagVarsDown" );  
// uncbins.push_back("_LeptonSFUp"       );    
// uncbins.push_back("_LeptonSFDown"     );    

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


 // initialize histos
 TH1F*  h_nSelectedAODCaloJet                           ;
 TH1F*  h_AODCaloJetAlphaMax_Pass                       ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_Pass               ;
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_Pass          ;
 TH1F*  h_AODCaloJetAlphaMax_UpPass                     ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_UpPass             ;
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_UpPass        ;
 TH1F*  h_AODCaloJetAlphaMax_DownPass                   ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_DownPass           ;
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_DownPass      ;

 TH1F*  h_AODCaloJetAlphaMax_alsoPass                   ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_alsoPass           ;
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_alsoPass      ;
 TH1F*  h_AODCaloJetAlphaMax_UpalsoPass                 ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_UpalsoPass         ;
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_UpalsoPass    ;
 TH1F*  h_AODCaloJetAlphaMax_DownalsoPass               ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_DownalsoPass       ;
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_DownalsoPass  ;

 TH1F*  h_AODCaloJetAlphaMax_Pass_wWeight               ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_Pass_wWeight       ;
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_Pass_wWeight  ;
 TH1F*  h_AODCaloJetAlphaMax_UpPass_wWeight             ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_UpPass_wWeight     ;
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_UpPass_wWeight;
 TH1F*  h_AODCaloJetAlphaMax_DownPass_wWeight           ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_DownPass_wWeight   ;         
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_DownPass_wWeight;       

 TH1F*  h_AODCaloJetAlphaMax_alsoPass_wWeight                    ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_alsoPass_wWeight            ;
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_alsoPass_wWeight       ;
 TH1F*  h_AODCaloJetAlphaMax_UpalsoPass_wWeight                  ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_UpalsoPass_wWeight          ;
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_UpalsoPass_wWeight     ;
 TH1F*  h_AODCaloJetAlphaMax_DownalsoPass_wWeight                ;
 TH1F*  h_AODCaloJetMedianLog10IPSig_DownalsoPass_wWeight        ;
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_DownalsoPass_wWeight   ;
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


 // (combined) histos to be made

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
 //file_Sig                    = TFile::Open( inpath + MSsample+region+".root"                 ) ;
 file_Sig                = TFile::Open( inpath + "DYJetsToLL_M-50_"+region+"_histograms.root"             ) ; 


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
cout<<"where"<<endl;
     h_nSelectedAODCaloJet                          	= (TH1F*)file_Sig->Get("h_"+region+"_nSelectedAODCaloJet")->Clone("h_nSelectedAODCaloJet"); 
     h_AODCaloJetAlphaMax_Pass                          	= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_Pass")->Clone("h_AODCaloJetAlphaMax_Pass"); 
     h_AODCaloJetMedianLog10IPSig_Pass               		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_Pass")->Clone("h_AODCaloJetMedianLog10IPSig_Pass"); 
     h_AODCaloJetMedianLog10TrackAngle_Pass          		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_Pass")->Clone("h_AODCaloJetMedianLog10TrackAngle_Pass");
     h_AODCaloJetAlphaMax_UpPass                     		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_UpPass")->Clone("h_AODCaloJetAlphaMax_Pass");
     h_AODCaloJetMedianLog10IPSig_UpPass             		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_UpPass")->Clone("h_AODCaloJetMedianLog10IPSig_UpPass");	
     h_AODCaloJetMedianLog10TrackAngle_UpPass        		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_UpPass")->Clone("h_AODCaloJetMedianLog10TrackAngle_UpPass");	
     h_AODCaloJetAlphaMax_DownPass                   		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_DownPass")->Clone("h_AODCaloJetAlphaMax_Pass");	
     h_AODCaloJetMedianLog10IPSig_DownPass           		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_DownPass")->Clone("h_AODCaloJetMedianLog10IPSig_DownPass");	
     h_AODCaloJetMedianLog10TrackAngle_DownPass      		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_DownPass")->Clone("h_AODCaloJetMedianLog10TrackAngle_DownPass");

     h_AODCaloJetAlphaMax_alsoPass                          	= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_alsoPass")->Clone("h_AODCaloJetAlphaMax_alsoPass"); 
     h_AODCaloJetMedianLog10IPSig_alsoPass               		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_alsoPass")->Clone("h_AODCaloJetMedianLog10IPSig_alsoPass"); 
     h_AODCaloJetMedianLog10TrackAngle_alsoPass          		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_alsoPass")->Clone("h_AODCaloJetMedianLog10TrackAngle_alsoPass");
     h_AODCaloJetAlphaMax_UpalsoPass                     		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_UpalsoPass")->Clone("h_AODCaloJetAlphaMax_alsoPass");
     h_AODCaloJetMedianLog10IPSig_UpalsoPass             		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_UpalsoPass")->Clone("h_AODCaloJetMedianLog10IPSig_UpalsoPass");	
     h_AODCaloJetMedianLog10TrackAngle_UpalsoPass        		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_UpalsoPass")->Clone("h_AODCaloJetMedianLog10TrackAngle_UpalsoPass");	
     h_AODCaloJetAlphaMax_DownalsoPass                   		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_DownalsoPass")->Clone("h_AODCaloJetAlphaMax_alsoPass");	
     h_AODCaloJetMedianLog10IPSig_DownalsoPass           		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_DownalsoPass")->Clone("h_AODCaloJetMedianLog10IPSig_DownalsoPass");	
     h_AODCaloJetMedianLog10TrackAngle_DownalsoPass      		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_DownalsoPass")->Clone("h_AODCaloJetMedianLog10TrackAngle_DownalsoPass");

     h_AODCaloJetAlphaMax_Pass_wWeight                          	= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_Pass_wWeight")->Clone("h_AODCaloJetAlphaMax_Pass_wWeight"); 
     h_AODCaloJetMedianLog10IPSig_Pass_wWeight               		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_Pass_wWeight")->Clone("h_AODCaloJetMedianLog10IPSig_Pass_wWeight"); 
     h_AODCaloJetMedianLog10TrackAngle_Pass_wWeight          		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_Pass_wWeight")->Clone("h_AODCaloJetMedianLog10TrackAngle_Pass_wWeight");
     h_AODCaloJetAlphaMax_UpPass_wWeight                     		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_UpPass_wWeight")->Clone("h_AODCaloJetAlphaMax_Pass_wWeight");
     h_AODCaloJetMedianLog10IPSig_UpPass_wWeight             		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_UpPass_wWeight")->Clone("h_AODCaloJetMedianLog10IPSig_UpPass_wWeight");	
     h_AODCaloJetMedianLog10TrackAngle_UpPass_wWeight        		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_UpPass_wWeight")->Clone("h_AODCaloJetMedianLog10TrackAngle_UpPass_wWeight");	
     h_AODCaloJetAlphaMax_DownPass_wWeight                   		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_DownPass_wWeight")->Clone("h_AODCaloJetAlphaMax_Pass_wWeight");	
     h_AODCaloJetMedianLog10IPSig_DownPass_wWeight           		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_DownPass_wWeight")->Clone("h_AODCaloJetMedianLog10IPSig_DownPass_wWeight");	
     h_AODCaloJetMedianLog10TrackAngle_DownPass_wWeight      		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_DownPass_wWeight")->Clone("h_AODCaloJetMedianLog10TrackAngle_DownPass_wWeight");

     h_AODCaloJetAlphaMax_alsoPass_wWeight                          	= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_alsoPass_wWeight")->Clone("h_AODCaloJetAlphaMax_alsoPass_wWeight"); 
     h_AODCaloJetMedianLog10IPSig_alsoPass_wWeight               		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_alsoPass_wWeight")->Clone("h_AODCaloJetMedianLog10IPSig_alsoPass_wWeight"); 
     h_AODCaloJetMedianLog10TrackAngle_alsoPass_wWeight          		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_alsoPass_wWeight")->Clone("h_AODCaloJetMedianLog10TrackAngle_alsoPass_wWeight");
     h_AODCaloJetAlphaMax_UpalsoPass_wWeight                     		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_UpalsoPass_wWeight")->Clone("h_AODCaloJetAlphaMax_alsoPass_wWeight");
     h_AODCaloJetMedianLog10IPSig_UpalsoPass_wWeight             		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_UpalsoPass_wWeight")->Clone("h_AODCaloJetMedianLog10IPSig_UpalsoPass_wWeight");	
     h_AODCaloJetMedianLog10TrackAngle_UpalsoPass_wWeight        		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_UpalsoPass_wWeight")->Clone("h_AODCaloJetMedianLog10TrackAngle_UpalsoPass_wWeight");	
     h_AODCaloJetAlphaMax_DownalsoPass_wWeight                   		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetAlphaMax_DownalsoPass_wWeight")->Clone("h_AODCaloJetAlphaMax_alsoPass_wWeight");	
     h_AODCaloJetMedianLog10IPSig_DownalsoPass_wWeight           		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10IPSig_DownalsoPass_wWeight")->Clone("h_AODCaloJetMedianLog10IPSig_DownalsoPass_wWeight");	
     h_AODCaloJetMedianLog10TrackAngle_DownalsoPass_wWeight      		= (TH1F*)file_Sig->Get("h_"+region+"_AllJets_AODCaloJetMedianLog10TrackAngle_DownalsoPass_wWeight")->Clone("h_AODCaloJetMedianLog10TrackAngle_DownalsoPass_wWeight");


std::vector<float> dist;
dist.push_back(h_nSelectedAODCaloJet->GetBinContent(2));
dist.push_back(h_nSelectedAODCaloJet->GetBinContent(3));
dist.push_back(h_nSelectedAODCaloJet->GetBinContent(4));
cout<<h_nSelectedAODCaloJet->GetBinContent(2)<<endl;
cout<<h_nSelectedAODCaloJet->GetBinContent(3)<<endl;
cout<<h_nSelectedAODCaloJet->GetBinContent(4)<<endl;


 Float_t n_AM_Pass             	      =h_AODCaloJetAlphaMax_Pass                 ->GetMean();
 Float_t n_IPSig_Pass        		      	  =h_AODCaloJetMedianLog10IPSig_Pass         ->GetMean();
 Float_t n_TA_Pass                 		  =h_AODCaloJetMedianLog10TrackAngle_Pass    ->GetMean();
 Float_t n_AM_UpPass           	      =h_AODCaloJetAlphaMax_UpPass               ->GetMean();
 Float_t n_IPSig_UpPass        	=h_AODCaloJetMedianLog10IPSig_UpPass       ->GetMean();
 Float_t n_TA_UpPass                   =h_AODCaloJetMedianLog10TrackAngle_UpPass  ->GetMean();
 Float_t n_AM_DownPass                   =h_AODCaloJetAlphaMax_DownPass             ->GetMean();
 Float_t n_IPSig_DownPass           =h_AODCaloJetMedianLog10IPSig_DownPass     ->GetMean();
 Float_t n_TA_DownPass               	 =h_AODCaloJetMedianLog10TrackAngle_DownPass->GetMean();

 Float_t n_AM_alsoPass             	      =h_AODCaloJetAlphaMax_alsoPass                 ->GetMean();
 Float_t n_IPSig_alsoPass        		      	  =h_AODCaloJetMedianLog10IPSig_alsoPass         ->GetMean();
 Float_t n_TA_alsoPass                 		  =h_AODCaloJetMedianLog10TrackAngle_alsoPass    ->GetMean();
 Float_t n_AM_UpalsoPass           	      =h_AODCaloJetAlphaMax_UpalsoPass               ->GetMean();
 Float_t n_IPSig_UpalsoPass        	=h_AODCaloJetMedianLog10IPSig_UpalsoPass       ->GetMean();
 Float_t n_TA_UpalsoPass                   =h_AODCaloJetMedianLog10TrackAngle_UpalsoPass  ->GetMean();
 Float_t n_AM_DownalsoPass                   =h_AODCaloJetAlphaMax_DownalsoPass             ->GetMean();
 Float_t n_IPSig_DownalsoPass           =h_AODCaloJetMedianLog10IPSig_DownalsoPass     ->GetMean();
 Float_t n_TA_DownalsoPass               	 =h_AODCaloJetMedianLog10TrackAngle_DownalsoPass->GetMean();

 Float_t n_AM_Pass_wWeight             	      =h_AODCaloJetAlphaMax_Pass_wWeight                 ->GetMean();
 Float_t n_IPSig_Pass_wWeight        		      	  =h_AODCaloJetMedianLog10IPSig_Pass_wWeight         ->GetMean();
 Float_t n_TA_Pass_wWeight                 		  =h_AODCaloJetMedianLog10TrackAngle_Pass_wWeight    ->GetMean();
 Float_t n_AM_UpPass_wWeight           	      =h_AODCaloJetAlphaMax_UpPass_wWeight               ->GetMean();
 Float_t n_IPSig_UpPass_wWeight        	=h_AODCaloJetMedianLog10IPSig_UpPass_wWeight       ->GetMean();
 Float_t n_TA_UpPass_wWeight                   =h_AODCaloJetMedianLog10TrackAngle_UpPass_wWeight  ->GetMean();
 Float_t n_AM_DownPass_wWeight                   =h_AODCaloJetAlphaMax_DownPass_wWeight             ->GetMean();
 Float_t n_IPSig_DownPass_wWeight           =h_AODCaloJetMedianLog10IPSig_DownPass_wWeight     ->GetMean();
 Float_t n_TA_DownPass_wWeight               	 =h_AODCaloJetMedianLog10TrackAngle_DownPass_wWeight->GetMean();

 Float_t n_AM_alsoPass_wWeight             	      =h_AODCaloJetAlphaMax_alsoPass_wWeight                 ->GetMean();
 Float_t n_IPSig_alsoPass_wWeight        		      	  =h_AODCaloJetMedianLog10IPSig_alsoPass_wWeight         ->GetMean();
 Float_t n_TA_alsoPass_wWeight                 		  =h_AODCaloJetMedianLog10TrackAngle_alsoPass_wWeight    ->GetMean();
 Float_t n_AM_UpalsoPass_wWeight           	      =h_AODCaloJetAlphaMax_UpalsoPass_wWeight               ->GetMean();
 Float_t n_IPSig_UpalsoPass_wWeight        	=h_AODCaloJetMedianLog10IPSig_UpalsoPass_wWeight       ->GetMean();
 Float_t n_TA_UpalsoPass_wWeight                   =h_AODCaloJetMedianLog10TrackAngle_UpalsoPass_wWeight  ->GetMean();
 Float_t n_AM_DownalsoPass_wWeight                   =h_AODCaloJetAlphaMax_DownalsoPass_wWeight             ->GetMean();
 Float_t n_IPSig_DownalsoPass_wWeight           =h_AODCaloJetMedianLog10IPSig_DownalsoPass_wWeight     ->GetMean();
 Float_t n_TA_DownalsoPass_wWeight               	 =h_AODCaloJetMedianLog10TrackAngle_DownalsoPass_wWeight->GetMean();

cout<<"where"<<endl;
std::vector<float> unc_1_AM  	        = cal_0u(n_AM_alsoPass);
std::vector<float> unc_1_AMUp  	        = cal_0u(n_AM_UpalsoPass);
std::vector<float> unc_1_AMDown  	        = cal_0u(n_AM_DownalsoPass);
std::vector<float> unc_1_IPSig  	        = cal_0u(n_IPSig_alsoPass);
std::vector<float> unc_1_IPSigUp  	        = cal_0u(n_IPSig_UpalsoPass);
std::vector<float> unc_1_IPSigDown  	= cal_0u(n_IPSig_DownalsoPass);
std::vector<float> unc_1_TA  	        = cal_0u(n_TA_alsoPass);
std::vector<float> unc_1_TAUp  	        = cal_0u(n_TA_UpalsoPass);
std::vector<float> unc_1_TADown  	        = cal_0u(n_TA_DownalsoPass);
std::vector<float> unc_2_AM  	        = cal_1u(n_AM_alsoPass);
std::vector<float> unc_2_AMUp  	        = cal_1u(n_AM_UpalsoPass);
std::vector<float> unc_2_AMDown  	        = cal_1u(n_AM_DownalsoPass);
std::vector<float> unc_2_IPSig  	        = cal_1u(n_IPSig_alsoPass);
std::vector<float> unc_2_IPSigUp  	        = cal_1u(n_IPSig_UpalsoPass);
std::vector<float> unc_2_IPSigDown  	= cal_1u(n_IPSig_DownalsoPass);
std::vector<float> unc_2_TA  	        = cal_1u(n_TA_alsoPass);
std::vector<float> unc_2_TAUp  	        = cal_1u(n_TA_UpalsoPass);
std::vector<float> unc_2_TADown  	        = cal_1u(n_TA_DownalsoPass);
std::vector<float> unc_3_AM  	        = cal_2u(n_AM_alsoPass);
std::vector<float> unc_3_AMUp  	        = cal_2u(n_AM_UpalsoPass);
std::vector<float> unc_3_AMDown  	        = cal_2u(n_AM_DownalsoPass);
std::vector<float> unc_3_IPSig  	        = cal_2u(n_IPSig_alsoPass);
std::vector<float> unc_3_IPSigUp  	        = cal_2u(n_IPSig_UpalsoPass);
std::vector<float> unc_3_IPSigDown  	= cal_2u(n_IPSig_DownalsoPass);
std::vector<float> unc_3_TA  	        = cal_2u(n_TA_alsoPass);
std::vector<float> unc_3_TAUp  	        = cal_2u(n_TA_UpalsoPass);
std::vector<float> unc_3_TADown  	        = cal_2u(n_TA_DownalsoPass);

std::vector<float> unc_AM  	        = fill_vec(unc_1_AM, unc_2_AM, unc_3_AM, dist);
std::vector<float> unc_AMUp  	        = fill_vec(unc_1_AMUp, unc_2_AMUp, unc_3_AMUp, dist);
std::vector<float> unc_AMDown  	        = fill_vec(unc_1_AMDown, unc_2_AMDown, unc_3_AMDown, dist);
std::vector<float> unc_IPSig  	        = fill_vec(unc_1_IPSig, unc_2_IPSig, unc_3_IPSig, dist);
std::vector<float> unc_IPSigUp  	= fill_vec(unc_1_IPSigUp, unc_2_IPSigUp, unc_3_IPSigUp, dist);
std::vector<float> unc_IPSigDown  	= fill_vec(unc_1_IPSigDown, unc_2_IPSigDown, unc_3_IPSigDown, dist);
std::vector<float> unc_TA  	        = fill_vec(unc_1_TA, unc_2_TA, unc_3_TA, dist);
std::vector<float> unc_TAUp  	        = fill_vec(unc_1_TAUp, unc_2_TAUp, unc_3_TAUp, dist);
std::vector<float> unc_TADown  	        = fill_vec(unc_1_TADown, unc_2_TADown, unc_3_TADown, dist);

std::vector<float> ratio_AMUp  	        = calc_vec(unc_AM, unc_AMUp);
std::vector<float> ratio_AMDown  	= calc_vec(unc_AM, unc_AMDown);
std::vector<float> ratio_IPSigUp  	= calc_vec(unc_IPSig, unc_IPSigUp);
std::vector<float> ratio_IPSigDown  	= calc_vec(unc_IPSig, unc_IPSigDown);
std::vector<float> ratio_TAUp  	        = calc_vec(unc_TA, unc_TAUp);
std::vector<float> ratio_TADown  	= calc_vec(unc_TA, unc_TADown);


//Float_t alsounc_1_AMUp  	        = cal_0u(n_AM_alsoPass,n_AM_UpalsoPass);
//Float_t alsounc_1_AMDown  	        = cal_0d(n_AM_alsoPass,n_AM_DownalsoPass);
//Float_t alsounc_1_IPSigUp  	        = cal_0u(n_IPSig_alsoPass,n_IPSig_UpalsoPass);
//Float_t alsounc_1_IPSigDown  		= cal_0d(n_IPSig_alsoPass,n_IPSig_DownalsoPass);
//Float_t alsounc_1_TAUp  	        = cal_0u(n_TA_alsoPass,n_TA_UpalsoPass);
//Float_t alsounc_1_TADown  	        = cal_0d(n_TA_alsoPass,n_TA_DownalsoPass);
//Float_t alsounc_2_AMUp  	        = cal_1u(n_AM_alsoPass,n_AM_UpalsoPass);
//Float_t alsounc_2_AMDown  	        = cal_1d(n_AM_alsoPass,n_AM_DownalsoPass);
//Float_t alsounc_2_IPSigUp  	        = cal_1u(n_IPSig_alsoPass,n_IPSig_UpalsoPass);
//Float_t alsounc_2_IPSigDown  		= cal_1d(n_IPSig_alsoPass,n_IPSig_DownalsoPass);
//Float_t alsounc_2_TAUp  	        = cal_1u(n_TA_alsoPass,n_TA_UpalsoPass);
//Float_t alsounc_2_TADown  	        = cal_1d(n_TA_alsoPass,n_TA_DownalsoPass);
//Float_t alsounc_3_AMUp  	        = cal_2u(n_AM_alsoPass,n_AM_UpalsoPass);
//Float_t alsounc_3_AMDown  	        = cal_2d(n_AM_alsoPass,n_AM_DownalsoPass);
//Float_t alsounc_3_IPSigUp  	        = cal_2u(n_IPSig_alsoPass,n_IPSig_UpalsoPass);
//Float_t alsounc_3_IPSigDown  		= cal_2d(n_IPSig_alsoPass,n_IPSig_DownalsoPass);
//Float_t alsounc_3_TAUp  	        = cal_2u(n_TA_alsoPass,n_TA_UpalsoPass);
//Float_t alsounc_3_TADown  	        = cal_2d(n_TA_alsoPass,n_TA_DownalsoPass);

//Float_t unc_wWeight_1_AMUp  	        = cal_0u(n_AM_Pass_wWeight,n_AM_UpPass_wWeight);
//Float_t unc_wWeight_1_AMDown  	        = cal_0d(n_AM_Pass_wWeight,n_AM_DownPass_wWeight);
//Float_t unc_wWeight_1_IPSigUp  	        = cal_0u(n_IPSig_Pass_wWeight,n_IPSig_UpPass_wWeight);
//Float_t unc_wWeight_1_IPSigDown  	= cal_0d(n_IPSig_Pass_wWeight,n_IPSig_DownPass_wWeight);
//Float_t unc_wWeight_1_TAUp  	        = cal_0u(n_TA_Pass_wWeight,n_TA_UpPass_wWeight);
//Float_t unc_wWeight_1_TADown  	        = cal_0d(n_TA_Pass_wWeight,n_TA_DownPass_wWeight);
//Float_t unc_wWeight_2_AMUp  	        = cal_1u(n_AM_Pass_wWeight,n_AM_UpPass_wWeight);
//Float_t unc_wWeight_2_AMDown  	        = cal_1d(n_AM_Pass_wWeight,n_AM_DownPass_wWeight);
//Float_t unc_wWeight_2_IPSigUp  	        = cal_1u(n_IPSig_Pass_wWeight,n_IPSig_UpPass_wWeight);
//Float_t unc_wWeight_2_IPSigDown  	= cal_1d(n_IPSig_Pass_wWeight,n_IPSig_DownPass_wWeight);
//Float_t unc_wWeight_2_TAUp  	        = cal_1u(n_TA_Pass_wWeight,n_TA_UpPass_wWeight);
//Float_t unc_wWeight_2_TADown  	        = cal_1d(n_TA_Pass_wWeight,n_TA_DownPass_wWeight);
//Float_t unc_wWeight_3_AMUp  	        = cal_2u(n_AM_Pass_wWeight,n_AM_UpPass_wWeight);
//Float_t unc_wWeight_3_AMDown  	        = cal_2d(n_AM_Pass_wWeight,n_AM_DownPass_wWeight);
//Float_t unc_wWeight_3_IPSigUp  	        = cal_2u(n_IPSig_Pass_wWeight,n_IPSig_UpPass_wWeight);
//Float_t unc_wWeight_3_IPSigDown  	= cal_2d(n_IPSig_Pass_wWeight,n_IPSig_DownPass_wWeight);
//Float_t unc_wWeight_3_TAUp  	        = cal_2u(n_TA_Pass_wWeight,n_TA_UpPass_wWeight);
//Float_t unc_wWeight_3_TADown  	        = cal_2d(n_TA_Pass_wWeight,n_TA_DownPass_wWeight);

//Float_t alsounc_wWeight_1_AMUp  	        = cal_0u(n_AM_alsoPass_wWeight,n_AM_UpalsoPass_wWeight);
//Float_t alsounc_wWeight_1_AMDown  	        = cal_0d(n_AM_alsoPass_wWeight,n_AM_DownalsoPass_wWeight);
//Float_t alsounc_wWeight_1_IPSigUp  	        = cal_0u(n_IPSig_alsoPass_wWeight,n_IPSig_UpalsoPass_wWeight);
//Float_t alsounc_wWeight_1_IPSigDown  	= cal_0d(n_IPSig_alsoPass_wWeight,n_IPSig_DownalsoPass_wWeight);
//Float_t alsounc_wWeight_1_TAUp  	        = cal_0u(n_TA_alsoPass_wWeight,n_TA_UpalsoPass_wWeight);
//Float_t alsounc_wWeight_1_TADown  	        = cal_0d(n_TA_alsoPass_wWeight,n_TA_DownalsoPass_wWeight);
//Float_t alsounc_wWeight_2_AMUp  	        = cal_1u(n_AM_alsoPass_wWeight,n_AM_UpalsoPass_wWeight);
//Float_t alsounc_wWeight_2_AMDown  	        = cal_1d(n_AM_alsoPass_wWeight,n_AM_DownalsoPass_wWeight);
//Float_t alsounc_wWeight_2_IPSigUp  	        = cal_1u(n_IPSig_alsoPass_wWeight,n_IPSig_UpalsoPass_wWeight);
//Float_t alsounc_wWeight_2_IPSigDown  	= cal_1d(n_IPSig_alsoPass_wWeight,n_IPSig_DownalsoPass_wWeight);
//Float_t alsounc_wWeight_2_TAUp  	        = cal_1u(n_TA_alsoPass_wWeight,n_TA_UpalsoPass_wWeight);
//Float_t alsounc_wWeight_2_TADown  	        = cal_1d(n_TA_alsoPass_wWeight,n_TA_DownalsoPass_wWeight);
//Float_t alsounc_wWeight_3_AMUp  	        = cal_2u(n_AM_alsoPass_wWeight,n_AM_UpalsoPass_wWeight);
//Float_t alsounc_wWeight_3_AMDown  	        = cal_2d(n_AM_alsoPass_wWeight,n_AM_DownalsoPass_wWeight);
//Float_t alsounc_wWeight_3_IPSigUp  	        = cal_2u(n_IPSig_alsoPass_wWeight,n_IPSig_UpalsoPass_wWeight);
//Float_t alsounc_wWeight_3_IPSigDown  	= cal_2d(n_IPSig_alsoPass_wWeight,n_IPSig_DownalsoPass_wWeight);
//Float_t alsounc_wWeight_3_TAUp  	        = cal_2u(n_TA_alsoPass_wWeight,n_TA_UpalsoPass_wWeight);
//Float_t alsounc_wWeight_3_TADown  	        = cal_2d(n_TA_alsoPass_wWeight,n_TA_DownalsoPass_wWeight);

















     if(domaketable){
      FILE * outfulltable;
      outfulltable = fopen (fulllogname+MSsample+"toy.tex","w");
       fprintf (outfulltable, "\\documentclass{article}\n\n");
       fprintf (outfulltable, "\\begin{document}\n\n");
       fprintf (outfulltable, "\\begin{tabular}{rlll}\n\n");
       //fprintf (outfulltable, " \\Huge %s & \\Huge %s   \\\\\n", lepton.Data(), region.Data()); 
       fprintf (outfulltable, " \\Huge %s   \\\\\n", region.Data()); 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, " \\hline \n");

  
      
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, " \\Category 1 \n");
       fprintf (outfulltable, "nCaloJet BinContent & 1Jet:%6.2f & 2Jet:%6.2f& 3Jet:%6.2f\\\\\n", dist.at(0)        ,dist.at(1)  	, dist.at(2)            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "AM PassEff & Eff:%2.8f & UpEff:%2.8f& DownEff:%2.8f\\\\\n", n_AM_alsoPass        ,n_AM_UpalsoPass  	, n_AM_DownalsoPass            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "AM BinContent & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_AM.at(0)        ,unc_AM.at(1)  	, unc_AM.at(2)            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "AMUp BinContent & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_AMUp.at(0)        ,unc_AMUp.at(1)  	, unc_AMUp.at(2)            ) ; 
       fprintf (outfulltable, "AMUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", ratio_AMUp.at(0)        ,ratio_AMUp.at(1)  	, ratio_AMUp.at(2)            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "AMDown BinContent & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_AMDown.at(0)        ,unc_AMDown.at(1)  	, unc_AMDown.at(2)            ) ; 
       fprintf (outfulltable, "AMDown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", ratio_AMDown.at(0)        ,ratio_AMDown.at(1)  	, ratio_AMDown.at(2)            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "IPSig PassEff & Eff:%2.8f & UpEff:%2.8f& DownEff:%2.8f\\\\\n", n_IPSig_alsoPass        ,n_IPSig_UpalsoPass  	, n_IPSig_DownalsoPass            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "IPSig BinContent & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_IPSig.at(0)        ,unc_IPSig.at(1)  	, unc_IPSig.at(2)            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "IPSigUp BinContent & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_IPSigUp.at(0)        ,unc_IPSigUp.at(1)  	, unc_IPSigUp.at(2)            ) ; 
       fprintf (outfulltable, "IPSigUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", ratio_IPSigUp.at(0)        ,ratio_IPSigUp.at(1)  	, ratio_IPSigUp.at(2)            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "IPSigDown BinContent & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_IPSigDown.at(0)        ,unc_IPSigDown.at(1)  	, unc_IPSigDown.at(2)            ) ; 
       fprintf (outfulltable, "IPSigDown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", ratio_IPSigDown.at(0)        ,ratio_IPSigDown.at(1)  	, ratio_IPSigDown.at(2)            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "TA PassEff & Eff:%2.8f & UpEff:%2.8f& DownEff:%2.8f\\\\\n", n_TA_alsoPass        ,n_TA_UpalsoPass  	, n_TA_DownalsoPass            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "TA BinContent & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_TA.at(0)        ,unc_TA.at(1)  	, unc_TA.at(2)            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "TAUp BinContent & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_TAUp.at(0)        ,unc_TAUp.at(1)  	, unc_TAUp.at(2)            ) ; 
       fprintf (outfulltable, "TAUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", ratio_TAUp.at(0)        ,ratio_TAUp.at(1)  	, ratio_TAUp.at(2)            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "TADown BinContent & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_TADown.at(0)        ,unc_TADown.at(1)  	, unc_TADown.at(2)            ) ; 
       fprintf (outfulltable, "TADown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", ratio_TADown.at(0)        ,ratio_TADown.at(1)  	, ratio_TADown.at(2)            ) ; 
       fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, " \\Category 1 \n");
       //fprintf (outfulltable, "AMaxUp Eff & cen:%2.8f & up:%2.8f& down:%2.8f\\\\\n", n_AM_alsoPass        ,n_AM_UpalsoPass  	, n_AM_DownalsoPass            ) ; 
       //fprintf (outfulltable, "AMaxUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_1_AMUp        ,alsounc_2_AMUp  	, alsounc_3_AMUp            ) ; 
       //fprintf (outfulltable, "AMaxDown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_1_AMDown        ,alsounc_2_AMDown  	, alsounc_3_AMDown            ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, "IPSigUp Eff & cen:%2.8f & up:%2.8f& down:%2.8f\\\\\n", n_IPSig_alsoPass        ,n_IPSig_UpalsoPass  	, n_IPSig_DownalsoPass            ) ; 
       //fprintf (outfulltable, "IPSigUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_1_IPSigUp        ,alsounc_2_IPSigUp  	, alsounc_3_IPSigUp            ) ; 
       //fprintf (outfulltable, "IPSigDown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_1_IPSigDown        ,alsounc_2_IPSigDown  	, alsounc_3_IPSigDown            ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, "TAUp Eff & cen:%2.8f & up:%2.8f& down:%2.8f\\\\\n", n_TA_alsoPass        ,n_TA_UpalsoPass  	, n_TA_DownalsoPass            ) ; 
       //fprintf (outfulltable, "TAUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_1_TAUp        ,alsounc_2_TAUp  	, alsounc_3_TAUp            ) ; 
       //fprintf (outfulltable, "TADown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_1_TADown        ,alsounc_2_TADown  	, alsounc_3_TADown            ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, " \\Category 2 w/Weight \n");
       //fprintf (outfulltable, "AMaxUp Eff & cen:%2.8f & up:%2.8f& down:%2.8f\\\\\n", n_AM_Pass_wWeight        ,n_AM_UpPass_wWeight  	, n_AM_DownPass_wWeight            ) ; 
       //fprintf (outfulltable, "AMaxUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_wWeight_1_AMUp        ,unc_wWeight_2_AMUp  	, unc_wWeight_3_AMUp            ) ; 
       //fprintf (outfulltable, "AMaxDown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_wWeight_1_AMDown        ,unc_wWeight_2_AMDown  	, unc_wWeight_3_AMDown            ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, "IPSigUp Eff & cen:%2.8f & up:%2.8f& down:%2.8f\\\\\n", n_IPSig_Pass_wWeight        ,n_IPSig_UpPass_wWeight  	, n_IPSig_DownPass_wWeight            ) ; 
       //fprintf (outfulltable, "IPSigUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_wWeight_1_IPSigUp        ,unc_wWeight_2_IPSigUp  	, unc_wWeight_3_IPSigUp            ) ; 
       //fprintf (outfulltable, "IPSigDown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_wWeight_1_IPSigDown        ,unc_wWeight_2_IPSigDown  	, unc_wWeight_3_IPSigDown            ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, "TAUp Eff & cen:%2.8f & up:%2.8f& down:%2.8f\\\\\n", n_TA_Pass_wWeight        ,n_TA_UpPass_wWeight  	, n_TA_DownPass_wWeight            ) ; 
       //fprintf (outfulltable, "TAUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_wWeight_1_TAUp        ,unc_wWeight_2_TAUp  	, unc_wWeight_3_TAUp            ) ; 
       //fprintf (outfulltable, "TADown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", unc_wWeight_1_TADown        ,unc_wWeight_2_TADown  	, unc_wWeight_3_TADown            ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, " \\Category 1 w/Weight\n");
       //fprintf (outfulltable, "AMaxUp Eff & cen:%2.8f & up:%2.8f& down:%2.8f\\\\\n", n_AM_alsoPass_wWeight        ,n_AM_UpalsoPass_wWeight  	, n_AM_DownalsoPass_wWeight            ) ; 
       //fprintf (outfulltable, "AMaxUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_wWeight_1_AMUp        ,alsounc_wWeight_2_AMUp  	, alsounc_wWeight_3_AMUp            ) ; 
       //fprintf (outfulltable, "AMaxDown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_wWeight_1_AMDown        ,alsounc_wWeight_2_AMDown  	, alsounc_wWeight_3_AMDown            ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, "IPSigUp Eff & cen:%2.8f & up:%2.8f& down:%2.8f\\\\\n", n_IPSig_alsoPass_wWeight        ,n_IPSig_UpalsoPass_wWeight  	, n_IPSig_DownalsoPass_wWeight            ) ; 
       //fprintf (outfulltable, "IPSigUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_wWeight_1_IPSigUp        ,alsounc_wWeight_2_IPSigUp  	, alsounc_wWeight_3_IPSigUp            ) ; 
       //fprintf (outfulltable, "IPSigDown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_wWeight_1_IPSigDown        ,alsounc_wWeight_2_IPSigDown  	, alsounc_wWeight_3_IPSigDown            ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, "TAUp Eff & cen:%2.8f & up:%2.8f& down:%2.8f\\\\\n", n_TA_alsoPass_wWeight        ,n_TA_UpalsoPass_wWeight  	, n_TA_DownalsoPass_wWeight            ) ; 
       //fprintf (outfulltable, "TAUp Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_wWeight_1_TAUp        ,alsounc_wWeight_2_TAUp  	, alsounc_wWeight_3_TAUp            ) ; 
       //fprintf (outfulltable, "TADown Unc & 0Tag:%2.8f & 1Tag:%2.8f& 2Tag:%2.8f\\\\\n", alsounc_wWeight_1_TADown        ,alsounc_wWeight_2_TADown  	, alsounc_wWeight_3_TADown            ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, "SigUnc AMaxUp  	& %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_AMaxUp        ,int_SigUnc_2_AMaxUp  	, int_SigUnc_3_AMaxUp            ) ; 
       //fprintf (outfulltable, "Sig AMaxDown     & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_AMaxDown      ,int_Sig_2_AMaxDown      , int_Sig_3_AMaxDown         ) ; 
       //fprintf (outfulltable, "SigUnc AMaxDown     & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_AMaxDown      ,int_SigUnc_2_AMaxDown      , int_SigUnc_3_AMaxDown         ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, "Sig IPSigUp      & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_IPSigUp       ,int_Sig_2_IPSigUp       , int_Sig_3_IPSigUp          ) ; 
       //fprintf (outfulltable, "SigUnc IPSigUncUp      & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_IPSigUp       ,int_SigUnc_2_IPSigUp       , int_SigUnc_3_IPSigUp          ) ; 
       //fprintf (outfulltable, "Sig IPSigDown    & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_IPSigDown     ,int_Sig_2_IPSigDown     , int_Sig_3_IPSigDown        ) ; 
       //fprintf (outfulltable, "SigUnc IPSigUncDown    & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_IPSigDown     ,int_SigUnc_2_IPSigDown     , int_SigUnc_3_IPSigDown        ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, "Sig TAUp  	& %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_TAUp  	       ,int_Sig_2_TAUp  	, int_Sig_3_TAUp              ) ; 
       //fprintf (outfulltable, "SigUnc TAUp  	& %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_TAUp  	       ,int_SigUnc_2_TAUp  	, int_SigUnc_3_TAUp              ) ; 
       //fprintf (outfulltable, "Sig TADown  	& %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_TADown        ,int_Sig_2_TADown  	, int_Sig_3_TADown            ) ; 
       //fprintf (outfulltable, "SigUnc TADown  	& %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_TADown        ,int_SigUnc_2_TADown  	, int_SigUnc_3_TADown            ) ; 
       //fprintf (outfulltable, " \\hline \n");
       //fprintf (outfulltable, "Sig TagVarsUp    & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_TagVarsUp     ,int_Sig_2_TagVarsUp     , int_Sig_3_TagVarsUp        ) ; 
       //fprintf (outfulltable, "SigUnc TagVarsUp    & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_TagVarsUp     ,int_SigUnc_2_TagVarsUp     , int_SigUnc_3_TagVarsUp        ) ; 
       //fprintf (outfulltable, "Sig TagVarsDown  & %2.8f & %2.8f& %2.8f\\\\\n", int_Sig_1_TagVarsDown   ,int_Sig_2_TagVarsDown   , int_Sig_3_TagVarsDown      ) ; 
       //fprintf (outfulltable, "SigUnc TagVarsDown  & %2.8f & %2.8f& %2.8f\\\\\n", int_SigUnc_1_TagVarsDown   ,int_SigUnc_2_TagVarsDown   , int_SigUnc_3_TagVarsDown      ) ; 
       //fprintf (outfulltable, " \\hline \n");
       fprintf (outfulltable, "\\end{tabular}\n\n");
       fprintf (outfulltable, "\\end{document}\n\n");
      fclose (outfulltable);

     }


     // Integrals

     
   } 
  }
 } 
}
