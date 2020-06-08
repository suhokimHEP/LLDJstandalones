
#ifndef analyzer_globalvalues_h
#define analyzer_globalvalues_h

#include "analyzer_base.h"
#include <TLorentzVector.h>

class analyzer_globalvalues : public analyzer_base {

public :

                  analyzer_globalvalues();
   virtual        ~analyzer_globalvalues(); 
   virtual void   clearglobalcounters();
   virtual void   cleareventcounters();

   // vectors of ints
   // each int is an entry in vector
   // associated with object passing
   // some selection
   std::vector<int> photon_list;
   std::vector<int> electron_list;
   std::vector<int> muon_list ;
   std::vector<int> aodcalojet_list;
   std::vector<int> aodcalojet_L1PF_list;
   std::vector<int> aodpfjet_list;
   std::vector<int> aodpfchsjet_list;
   std::vector<int> taggedjet_list;
   std::vector<int> taggedjet_list_L1PF;
   std::vector<int> taggedjetSB1_list;
   std::vector<int> taggedjetSB2_list;
   std::vector<int> taggedjetSB3_list;
   std::vector<int> taggedjetSB4_list;
   std::vector<int> taggedjetSB5_list;
   std::vector<int> taggedjetSB6_list;
   std::vector<int> taggedjetSB7_list;
   std::vector<int> taggedjetSBL1_list;
   std::vector<int> taggedjetSBL2_list;
   std::vector<int> taggedjetSBL3_list;
   std::vector<int> taggedjetSBL4_list;
   std::vector<int> taggedjetSBL5_list;
   std::vector<int> taggedjetSBL6_list;
   std::vector<int> taggedjetSBL7_list;
   std::vector<int> taggedjetSB2a_list;
   std::vector<int> taggedjetSB2b_list;
   std::vector<int> taggedjetSB2c_list;
   std::vector<int> taggedjetIP_list;
   std::vector<int> taggedjetSBIPa_list;
   std::vector<int> taggedjetSBIPb_list;
   std::vector<int> taggedjetSBIPc_list;

   std::vector<int> taggedjet_h150_llp20_ct100_list;
   std::vector<int> taggedjet_h150_llp50_ct100_list;
   std::vector<int> taggedjet_h175_llp20_ct100_list;
   std::vector<int> taggedjet_h175_llp50_ct100_list;
   std::vector<int> taggedjet_h200_llp20_ct100_list;
   std::vector<int> taggedjet_h200_llp50_ct100_list;
   std::vector<int> taggedjet_h250_llp50_ct100_list;
   std::vector<int> taggedjet_h500_llp200_ct100_list;

   std::vector<int> calomatchedPF_list;
   std::vector<int> PFmatchedCalo_list;
   std::vector<int> calomatchedPFchs_list;
   std::vector<int> PFchsmatchedCalo_list;

   std::vector<float> aodcalojet_minDR_list;
   std::vector<float> aodcalojet_matchedCSV_list;
   std::vector<int>   aodcalojet_matchedPartonFlavour_list;

   int nBPartonFlavour;

   // for dilepton
   TLorentzVector fourVec_ee, fourVec_mm, fourVec_ll, fourVec_em;
   TLorentzVector fourVec_l1, fourVec_l2, fourVec_l3, fourVec_l4;
   TLorentzVector fourVec_met;
   Float_t dilep_mass, OSOF_mass;
   Float_t dilep_pt, OSOF_pt;

   // personal variables
   Float_t themet;
   Float_t themephi;
   Float_t htall;
   Float_t htaodcalojets;
   Float_t transversemass; 
   Float_t Wpt; 	  
   Float_t SummedGenWeight;

   // Uncertainty shifted collections
   std::vector<float>   Shifted_CaloJetPt;
   std::vector<float>   Shifted_CaloJetAlphaMax;
   std::vector<float>   Shifted_CaloJetMedianLog10IPSig;
   std::vector<float>   Shifted_CaloJetMedianLog10TrackAngle;
   std::vector<float>   Shifted_muPt;
   std::vector<float>   Shifted_phoPt;
   std::vector<float>   Shifted_elePt;
 
   // AOD
   float jetmatchdRcut ;
   float objcleandRcut ;
   float sum_AODGenEventWeight;

   // ID bits for collections
   TString phoid;
   TString eleid;
   TString muoid;
   TString jetid;

   int phoidbit;
   int eleidbit;
   int muoidbit;
   int aodcalojetidbit;
   float muoisoval;

   // full cut bitsets
   Int_t bitsPassOneEleSig   ;
   Int_t bitsPassTwoEleSig   ;
   Int_t bitsPassOneMuSig    ;
   Int_t bitsPassTwoMuSig    ;
   Int_t bitsPassOneEleDY    ;
   Int_t bitsPassTwoEleDY    ;
   Int_t bitsPassOneMuDY     ;
   Int_t bitsPassTwoMuDY     ;
   Int_t bitsPassOneEleZH    ;
   Int_t bitsPassTwoEleZH    ;
   Int_t bitsPassOneMuZH     ;
   Int_t bitsPassTwoMuZH     ;
   Int_t bitsPassOneEleOffZ  ;
   Int_t bitsPassTwoEleOffZ  ;
   Int_t bitsPassOneMuOffZ   ;
   Int_t bitsPassTwoMuOffZ   ;
   Int_t bitsPassOneEleNoPair;
   Int_t bitsPassOneMuNoPair ;
   Int_t bitsPassEleMuOSOF   ;
   Int_t bitsPassEleMuOSOFL  ;
   Int_t bitsPassOnePho      ;
   Int_t bitsPassEleWH       ;
   Int_t bitsPassMuWH        ;
   Int_t bitsPassEleWHSig    ; 
   Int_t bitsPassMuWHSig     ;
   Int_t bitsPassEleLowPtWH  ;
   Int_t bitsPassMuLowPtWH   ;


   // key all pass bitsets
   Int_t keyPassOneEleSig   ;
   Int_t keyPassTwoEleSig   ;
   Int_t keyPassOneMuSig    ;
   Int_t keyPassTwoMuSig    ;
   Int_t keyPassOneEleDY    ;
   Int_t keyPassTwoEleDY    ;
   Int_t keyPassOneMuDY     ;
   Int_t keyPassTwoMuDY     ;
   Int_t keyPassOneEleZH    ;
   Int_t keyPassTwoEleZH    ;
   Int_t keyPassOneMuZH     ;
   Int_t keyPassTwoMuZH     ;
   Int_t keyPassOneEleOffZ  ;
   Int_t keyPassTwoEleOffZ  ;
   Int_t keyPassOneMuOffZ   ;
   Int_t keyPassTwoMuOffZ   ;
   Int_t keyPassOneEleNoPair;
   Int_t keyPassOneMuNoPair ;
   Int_t keyPassEleMuOSOF   ;
   Int_t keyPassEleMuOSOFL  ;
   Int_t keyPassOnePho      ;
   Int_t keyPassEleWH       ;
   Int_t keyPassMuWH        ;
   Int_t keyPassEleWHSig    ;
   Int_t keyPassMuWHSig     ;
   Int_t keyPassEleLowPtWH  ;
   Int_t keyPassMuLowPtWH   ;


   // selection counters (how many events pass)
   Int_t n_tot;

   Int_t n_passOneEleSig   ;
   Int_t n_passTwoEleSig   ;
   Int_t n_passOneMuSig    ;
   Int_t n_passTwoMuSig    ;
   Int_t n_passOneEleDY    ;
   Int_t n_passTwoEleDY    ;
   Int_t n_passOneMuDY     ;
   Int_t n_passTwoMuDY     ;
   Int_t n_passOneEleZH    ;
   Int_t n_passTwoEleZH    ;
   Int_t n_passOneMuZH     ;
   Int_t n_passTwoMuZH     ;
   Int_t n_passOneEleOffZ  ;
   Int_t n_passTwoEleOffZ  ;
   Int_t n_passOneMuOffZ   ;
   Int_t n_passTwoMuOffZ   ;
   Int_t n_passOneEleNoPair;
   Int_t n_passOneMuNoPair ;
   Int_t n_passEleMuOSOF   ;
   Int_t n_passEleMuOSOFL  ;
   Int_t n_passOnePho      ;
   Int_t n_passEleWH       ;
   Int_t n_passMuWH        ;
   Int_t n_passEleWHSig	   ;
   Int_t n_passMuWHSig 	   ;
   Int_t n_passEleLowPtWH  ;
   Int_t n_passMuLowPtWH   ;


   Int_t nSelectedPho;
   Int_t nSelectedEle;
   Int_t nSelectedMuo;
   Int_t nSelectedSlimmedJet;
   Int_t nSelectedAODCaloJet;
   Int_t nSelectedAODCaloJet_L1PF;

   Int_t n_totalPF;
   Int_t n_totalPFchs;
   Int_t n_totalCalo;
   Int_t n_matchedPFCalo;
   Int_t n_matchedPFchsCalo;

   Bool_t L1PFremoved;
};

#endif
