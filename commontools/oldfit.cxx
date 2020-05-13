#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iostream>
 
void inter_fit(TString Tsample){
 
 Double_t ntotal = 0;
 Double_t nevents = 0;

 char* listdir;
 listdir = getenv ("listdir");
 TString Tlistdir = TString(listdir);
 TString fulllistname = Tlistdir+"/"+Tsample+".list";
 TString fulloutname   = Tlistdir+"/"+Tsample+".info";

 printf("Tsample : %s \n",fulllistname.Data());

 std::fstream inputfile;
 inputfile.open(fulllistname);
 if( !inputfile.good() ) { 
   std::cerr << "Cannot open the file: \"" << fulllistname+"\""<<std::endl;
   abort();
 }

 // lines read from file variables to count number of events
 std::string inputline = ""; 
 TString Tinputline = ""; 



 TH1F* h_inter_decaydist;

 int count = 0;
 while( std::getline(inputfile, inputline) ) { 
  if( inputfile.fail() ) continue;

  count++;
  if( count>1 ) continue;

  Tinputline = inputline;
  if( Tinputline.Contains("/store/group") ){  // if filename

   // open file
   TFile* theFile;
   theFile = TFile::Open("root://cmseos.fnal.gov/"+Tinputline);

   // get histogram
   TH1F* h_inter_temp;
   TTree *oldtree = (TTree*)theFile->Get("lldjNtuple/EventTree");
   //oldtree->Draw("Decay_dist","ctau_eventweight");
   //float ctau_eventweight;
   //std::vector<float> Decay_dist;
   //oldtree->Branch("ctau_eventweight", &ctau_eventweight);   
   //oldtree->Branch("Decay_dist", &Decay_dist);   
   oldtree->Draw("Decay_dist");
   h_inter_temp = (TH1F*)oldtree->GetHistogram();
   cout<<"where"<<endl;
	if(count==1){h_inter_decaydist = (TH1F*) h_inter_temp   ->Clone( "h_inter_decaydist" ) ;}
   	else{h_inter_decaydist->Add(h_inter_temp);}
   cout<<"where"<<endl;
   //h_nevents = (TH1F*)theFile->Get("noCutSignature_COUNT");

   // add bin contents to total count
   //nevents=h_nevents->GetBinContent(1);
   //ntotal+=nevents;
   if(count%1 == 0) printf("Print every files: root://cmseos.fnal.gov/%s \n events: \n",Tinputline.Data());

   theFile->Close();
   cout<<h_inter_temp->GetMean()<<endl;
   cout<<h_inter_decaydist->GetMean()<<endl;

  } // if line contains /store/group
 } //while getline
 inputfile.close();
   cout<<"where"<<endl;
TCanvas* c1 = new TCanvas( "c1", "Histogram Drawing Options", 800,800 );
c1->SetGrid();
gStyle->SetHistLineWidth(3);
gStyle->SetLineWidth(3);
gPad->SetTickx();
gPad->SetTicky();
gStyle->SetLineWidth(3);
gStyle->SetPalette(kBird);
c1->Clear();
   cout<<h_inter_decaydist->GetMean()<<endl;
 h_inter_decaydist->Draw("hist");
c1->Modified();
c1->Update();
c1->SaveAs(Tsample+".pdf");

 // append nrevents to list file
 //FILE * outfile;
 //outfile = fopen (fulloutname,"w");
 //fprintf (outfile, "nrevents: %.1f \n",ntotal);
 //fclose (outfile);

 //printf("--total: %.1f\n",ntotal);
 //return ntotal;
 
}
