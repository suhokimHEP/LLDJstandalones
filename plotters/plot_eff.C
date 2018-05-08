#include <iostream>

#include "TFile.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TCanvas.h"
#include "TMath.h"


void plot_a_eff(TH1F* h_num, TH1F* h_den, TString name){

  const int nbins = h_sig->GetNbinsX();

  TGraphAsymmErrors* gr_eff = new TGraphAsymmErrors();
  gr_eff->SetName("gr_"+name);
  gr_eff->Divide(h_num, h_den, "cl=0.683 b(1,1) mode");

  TH1F* h_eff = (TH1F*)h_num->Clone();
  h_eff->Divide(h_den);
  h_eff->SetName("h_"+name);

  gr_eff->SetLineWidth(2);
  gr_eff->SetMarkerSize(1);
  gr_eff->SetMarkerStyle(8);
  gr_eff->SetMarkerColor(kGreen+1);

  gr_eff->SetTitle("Mistag rate " + name);
  gr_eff->GetXaxis()->SetTitle("");
  gr_eff->GetYaxis()->SetTitle("Mistag rate");

  TCanvas* c_eff = new TCanvas("c_eff", "c_eff", 640, 480);
  gr_eff->Draw("AP");
  c_eff->Print("gr_eff_"+name+".pdf");

  f_out->cd();
  gr_eff->Write();
  h_num->Write()
  h_den->Write()
  h_eff->Write();
  
}


void plot_eff(){

  //Note: this needs to be generalized to multidimensional histograms

  TFile* f_in  = TFile::Open("fout.root", "READ");
  TFile* f_out = TFile::Open("feff.root", "READ");

  std::vector<TString> num_name;
  std::vector<TString> den_name;

  //Pt
  num_name.push_back("");
  den_name.push_back("");

  //dR
  num_name.push_back("");
  den_name.push_back("");

  //Nt
  num_name.push_back("");
  den_name.push_back("");

  for(unsigned int i=0; i<num_name.size(); i++){
    
    TH1F* h_num = (TH1F*)f_num->Get(num_name.at(i));
    TH1F* h_den = (TH1F*)f_den->Get(den_name.at(i));
    
    TString name = "";
    plot_a_eff(h_num, h_den, name, f_out);

  }
  
  f_in->Close();
  f_out->Close();

}
