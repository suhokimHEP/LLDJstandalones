#include <iostream>
#include "TString.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLegend.h"
#include "TPad.h"
#include "TStyle.h"
#include "TText.h"
#include <fstream>
#include "TFile.h"
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib> /* mkdir */
#include <stdlib.h>     /* getenv */

using namespace std;

void SignalCheck(TString mass, TString ct, TString mode){
  //Float_t MCSF_2016 =1.0; 
  //Float_t MCSF_2017 =1.0; 
  Float_t MCSF_2016 =0.878917; 
  Float_t MCSF_2017 =0.7388745; 

  TString s_NoGenWeight_2016 ="/uscms/home/ddiaz/nobackup/ZDark_LLDJ_slc6_530_CMSSW_8_0_26_patch1/src/LLDJstandalones/roots/SigTestNoGenWeight/"+mode+"_HToSSTobbbb_ZToLL_MH-125_MS-"+mass+"_ctauS-"+ct+"_TwoMuZH_histograms.root";
  TString   s_GenWeight_2016 ="/uscms/home/ddiaz/nobackup/ZDark_LLDJ_slc6_530_CMSSW_8_0_26_patch1/src/LLDJstandalones/roots/SigTestNormal/"+mode+"_HToSSTobbbb_ZToLL_MH-125_MS-"+mass+"_ctauS-"+ct+"_TwoMuZH_histograms.root";
  TString s_NoGenWeight_2017 ="/uscms/home/ddiaz/nobackup/ANComments/2017-LLDJ_slc7_630_CMSSW_9_4_10/src/2017lldj/roots/SigTestNoGenWeight/"+mode+"_HToSSTobbbb_ZToLL_MH-125_MS-"+mass+"_ctauS-"+ct+"_TwoMuZH_histograms.root";
  TString   s_GenWeight_2017 ="/uscms/home/ddiaz/nobackup/ANComments/2017-LLDJ_slc7_630_CMSSW_9_4_10/src/2017lldj/roots/SigTestNormal/"+mode+"_HToSSTobbbb_ZToLL_MH-125_MS-"+mass+"_ctauS-"+ct+"_TwoMuZH_histograms.root";
  
  TFile* NoGenWeight_2016 = new TFile(s_NoGenWeight_2016,"read");
  TFile*   GenWeight_2016 = new TFile(  s_GenWeight_2016,"read");
  TFile* NoGenWeight_2017 = new TFile(s_NoGenWeight_2017,"read");
  TFile*   GenWeight_2017 = new TFile(  s_GenWeight_2017,"read");
  
  TH1F* h_NoGenWeight_2016 =(TH1F*) NoGenWeight_2016->Get("h_TwoMuZH_nSelectedAODCaloJetTag_orig");
  TH1F*   h_GenWeight_2016 =(TH1F*)   GenWeight_2016->Get("h_TwoMuZH_nSelectedAODCaloJetTag_orig");
  TH1F* h_NoGenWeight_2017 =(TH1F*) NoGenWeight_2017->Get("h_TwoMuZH_nSelectedAODCaloJetTag_orig");
  TH1F*   h_GenWeight_2017 =(TH1F*)   GenWeight_2017->Get("h_TwoMuZH_nSelectedAODCaloJetTag_orig");

  cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
  cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
  cout << "h_NoGenWeight_2016(1):  "<< h_NoGenWeight_2016->GetBinContent(1)<<endl;
  cout << "h_NoGenWeight_2016(2):  "<< h_NoGenWeight_2016->GetBinContent(2)<<endl;
  cout << "h_NoGenWeight_2016(3):  "<< h_NoGenWeight_2016->GetBinContent(3)<<endl;
  cout << "h_GenWeight_2016(1):  "  << h_GenWeight_2016->GetBinContent(1)<<endl;
  cout << "h_GenWeight_2016(2):  "  << h_GenWeight_2016->GetBinContent(2)<<endl;
  cout << "h_GenWeight_2016(3):  "  << h_GenWeight_2016->GetBinContent(3)<<endl;
  cout << "h_NoGenWeight_2017(1):  "<< h_NoGenWeight_2017->GetBinContent(1)<<endl;
  cout << "h_NoGenWeight_2017(2):  "<< h_NoGenWeight_2017->GetBinContent(2)<<endl;
  cout << "h_NoGenWeight_2017(3):  "<< h_NoGenWeight_2017->GetBinContent(3)<<endl;
  cout << "h_GenWeight_2017(1):  "  << h_GenWeight_2017->GetBinContent(1)<<endl;
  cout << "h_GenWeight_2017(2):  "  << h_GenWeight_2017->GetBinContent(2)<<endl;
  cout << "h_GenWeight_2017(3):  "  << h_GenWeight_2017->GetBinContent(3)<<endl;
  cout << endl;
 
  cout<<"#-------------2016 Ratios NoGenEventWeight/withGenEventWeight (should be ~1)"<<endl;
  cout<<"Bin 1:  "<< h_NoGenWeight_2016->GetBinContent(1)/h_GenWeight_2016->GetBinContent(1)<<endl;
  cout<<"Bin 2:  "<< h_NoGenWeight_2016->GetBinContent(2)/h_GenWeight_2016->GetBinContent(2)<<endl;
  cout<<"Bin 3:  "<< h_NoGenWeight_2016->GetBinContent(3)/h_GenWeight_2016->GetBinContent(3)<<endl;
  cout << endl;
 
  cout<<"#-------------2017 Ratios NoGenEventWeight/withGenEventWeight (should be ~1)"<<endl;
  cout<<"Bin 1:  "<< h_NoGenWeight_2017->GetBinContent(1)/h_GenWeight_2017->GetBinContent(1)<<endl;
  cout<<"Bin 2:  "<< h_NoGenWeight_2017->GetBinContent(2)/h_GenWeight_2017->GetBinContent(2)<<endl;
  cout<<"Bin 3:  "<< h_NoGenWeight_2017->GetBinContent(3)/h_GenWeight_2017->GetBinContent(3)<<endl;

  cout <<endl;
  cout <<"#-------------Ratio (2016 scaled to 41fb^-1/2017)  With NoGenEventWeights (NO Z SF)"<<endl;
  cout <<"Bin 1:  "<<(41./16.2262)*h_NoGenWeight_2016->GetBinContent(1)/h_NoGenWeight_2017->GetBinContent(1)<<endl;
  cout <<"Bin 2:  "<<(41./16.2262)*h_NoGenWeight_2016->GetBinContent(2)/h_NoGenWeight_2017->GetBinContent(2)<<endl;
  cout <<"Bin 3:  "<<(41./16.2262)*h_NoGenWeight_2016->GetBinContent(3)/h_NoGenWeight_2017->GetBinContent(3)<<endl;
 
  cout <<endl;
  cout <<"#-------------Ratio (2016 scaled to 41fb^-1/2017)  With GenEventWeights (No Z SF)"<<endl;
  cout <<"Bin 1:  "<<(41./16.2262)*h_GenWeight_2016->GetBinContent(1)/h_GenWeight_2017->GetBinContent(1)<<endl;
  cout <<"Bin 2:  "<<(41./16.2262)*h_GenWeight_2016->GetBinContent(2)/h_GenWeight_2017->GetBinContent(2)<<endl;
  cout <<"Bin 3:  "<<(41./16.2262)*h_GenWeight_2016->GetBinContent(3)/h_GenWeight_2017->GetBinContent(3)<<endl;
 
  cout <<endl;
  cout <<"#-------------Ratio (2016 scaled to 41fb^-1/2017)  With NoGenEventWeights (should be ~1)"<<endl;
  cout <<"Bin 1:  "<<((41./16.2262)*MCSF_2016*h_NoGenWeight_2016->GetBinContent(1))/(MCSF_2017*h_NoGenWeight_2017->GetBinContent(1))<<endl;
  cout <<"Bin 2:  "<<((41./16.2262)*MCSF_2016*h_NoGenWeight_2016->GetBinContent(2))/(MCSF_2017*h_NoGenWeight_2017->GetBinContent(2))<<endl;
  cout <<"Bin 3:  "<<((41./16.2262)*MCSF_2016*h_NoGenWeight_2016->GetBinContent(3))/(MCSF_2017*h_NoGenWeight_2017->GetBinContent(3))<<endl;
 
  cout <<endl;
  cout <<"#-------------Ratio (2016 scaled to 41fb^-1/2017)  With GenEventWeights (should be ~1)"<<endl;
  cout <<"Bin 1:  "<<((41./16.2262)*MCSF_2016*h_GenWeight_2016->GetBinContent(1))/(MCSF_2017*h_GenWeight_2017->GetBinContent(1))<<endl;
  cout <<"Bin 2:  "<<((41./16.2262)*MCSF_2016*h_GenWeight_2016->GetBinContent(2))/(MCSF_2017*h_GenWeight_2017->GetBinContent(2))<<endl;
  cout <<"Bin 3:  "<<((41./16.2262)*MCSF_2016*h_GenWeight_2016->GetBinContent(3))/(MCSF_2017*h_GenWeight_2017->GetBinContent(3))<<endl;
  
 cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
}
