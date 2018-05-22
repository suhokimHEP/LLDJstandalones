#include <iostream>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end

#include "TRandom3.h"
#include "TH1D.h"
#include "TCanvas.h"

//Global
int njets;
TH1D* h_bkgest;
bool debug = false;


void print(TH1D* h){

  cout << h->GetName() << endl;
  for(int i=1; i<=h->GetNbinsX(); i++){
    cout << h->GetBinContent(i) << endl;
  }

}

//https://helloacm.com/cc-coding-exercise-recursive-combination-algorithm-implementation/
void comb(int n, int r, int *arr, int sz, Double_t weight) {

  for (int i = n; i >= r; i --) {

    // choose the first element
    arr[r - 1] = i;
    if (r > 1) { // if still needs to choose
      // recursive into smaller problem
      comb(i - 1, r - 1, arr, sz, weight);
    } 
    else {
      
      //*********************//
      // have one combo here
      //*********************//         
      
      if(debug){
	std::cout << "    Combo: ";
	for (int b = 0; b < sz; b++) {
	  std::cout << arr[b] << " ";
	}
	std::cout << std::endl;
      }
      
      double p=1;
      for(int j=1; j<=njets; j++){

	//j-1 because index from 1
	double jetprob = 0.1;
	if(debug) std::cout << "      Prob: " << jetprob << std::endl;

	bool found = false;
	for(int t=0; t<sz; t++){//probably really slow
	  if(j==arr[t]){
	    p*=jetprob;
	    found = true;
	    if(debug) std::cout << "      Tagged jet: " << j << std::endl;
	    break;
	  }
	}
	if(!found){
	  p*=(1-jetprob); 
	  if(debug) std::cout << "      Didn't tag jet: " << j << std::endl;
	}
	if(debug) std::cout << "      Updated prob: " << p << std::endl;
      }//loop over jets
      h_bkgest->Fill(sz,p*weight);//need event weight
      
    }//else in combo
  }//for loop
}



void toy(){

  double weight = 1;

  int ntoys = 100000;
  h_bkgest = new TH1D("h_bkgest", "h_bkgest", 6, -0.5, 5.5);
  TH1D* h_bkg = new TH1D("h_bkg", "h_bkg", 6, -0.5, 5.5);

  TRandom3* rand = new TRandom3(12345);
  
  for(int i=0; i<ntoys; i++){

    //number of jets
    njets = (int) (rand->Rndm()*10); //flat between 0 and 10
    if(debug) std::cout << "NJets: " << njets << std::endl;

    //loop over jets to get number of tags
    int ntags=0;
    for(int j=0; j<njets; j++){
      if(rand->Rndm()<.1) ntags++;
    }
    h_bkg->Fill(ntags);
    
    //number of tags prediction
    int N = njets;
    for(int i=1; i<6; i++){
      if(N<i) continue; //code is safe anyway, but this migh save time
      if(debug) std::cout << "  NTags: " << i << std::endl;
      const int M = i;
      int *arr = new int[M];
      comb(N, M, arr, M, weight);
    }//estimate ntag bin
    
  }//ntoys
  
  print(h_bkg);
  print(h_bkgest);
  
  h_bkg->SetLineWidth(2);
  h_bkgest->SetLineWidth(2);
  h_bkg->SetLineColor(kBlack);
  h_bkgest->SetLineColor(kRed);

  TCanvas* myC = new TCanvas("c", "c", 640, 480);
  h_bkg->Draw("HIST E");
  h_bkgest->Draw("HIST E SAMES");
  myC->SaveAs("c.pdf");
    

}//toy main
