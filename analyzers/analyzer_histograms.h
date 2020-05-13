#ifndef analyzer_histograms_h
#define analyzer_histograms_h

#include "TMath.h"
#include "TH1F.h"
#include "TH2F.h"

#include "analyzer_scalefactors.h"

class analyzer_histograms : public analyzer_scalefactors {


public :


                  analyzer_histograms();
   virtual        ~analyzer_histograms(); 



 static const int PhoPtBin      = 50;
 static const int MuPtBin       = 33;
 static const int ElePtBin      = 33;
 static const int PhoPtBinMax   = 400;
 static const int MuPtBinMax    = 99;
 static const int ElePtBinMax   = 99;
 static const int PhoPtBinMin   = 0;
 static const int MuPtBinMin    = 0;
 static const int ElePtBinMin   = 0;
 static const int PhoEtaBin     = 30;
 static const int MuEtaBin      = 30;
 static const int EleEtaBin     = 30;
 static const int PhoEtaBinMax  = 5;
 static const int MuEtaBinMax   = 5;
 static const int EleEtaBinMax  = 5;
 static const int PhoEtaBinMin  = -5;
 static const int MuEtaBinMin   = -5;
 static const int EleEtaBinMin  = -5;
 Float_t x_bins[25]={150.0,170.0,200.0,230.0,260.0,290.0,320.0,350.0,390.0,430.0,470.0,510.0,550.0,590.0,640.0,690.0,740.0,790.0,840.0,900.0,960.0,1020.0,1090.0,1160.0,1250.0};
 Float_t ntag_x_bins[4]={0,1,2,4};
 float sf_qcd[24]={ 1.47528, 1.5428, 1.49376, 1.39119, 1.40538, 1.44661, 1.38176, 1.37381, 1.29145, 1.33452, 1.25765, 1.24265, 1.24331, 1.16187, 1.07349, 1.10748, 1.06617, 1.05616, 1.1149, 1.03164, 1.06872, 0.981645, 0.81729, 0.924246};
 float sf_ewk[24]={ 1.4319, 1.48791, 1.42907, 1.31989, 1.32353, 1.35149, 1.28102, 1.26278, 1.17513, 1.20228, 1.12253, 1.09894, 1.08927, 1.00814, 0.921107, 0.940267, 0.895919, 0.878745, 0.918173, 0.84037, 0.861633, 0.783389, 0.645409, 0.721987};
 Int_t AM_Pass;
 Int_t AMUp_Pass;
 Int_t AMDown_Pass;
 Int_t IPSig_Pass;
 Int_t IPSigUp_Pass;
 Int_t IPSigDown_Pass;
 Int_t TA_Pass;
 Int_t TAUp_Pass;
 Int_t TADown_Pass;
 

 // Histograms

 // make 1D,2D histograms (helper function)
 TH2F*          initSingleHistogramTH2F(TString hnamex, TString htitley,
                                   Int_t nbinsx, Float_t xmin, Float_t xmax,
                                   Int_t nbinsy, Float_t ymin, Float_t ymax);
 TH2F*          initSingleHistogramTH2F(TString hname, TString htitle,
					int nbinsx, Float_t xbins[],
					int nbinsy, Float_t ybins[]);
 TH1F*          initSingleHistogramTH1F(TString hname, TString htitle,
                                   Int_t nbins, Float_t xmin,
                                   Float_t xmax);
 TH1F*          initSingleHistogramTH1F(TString hname, TString htitle, 
				      int nbins, Float_t xbins[]);

 // Cutflow histograms
 Bool_t        initCutflowHistograms( TString uncbin );
 Bool_t        fillCutflowHistograms(Float_t weight, int selbin, Int_t localselint, Int_t localselkey);
 Bool_t        writeCutflowHistograms(int selbin);
 Bool_t        deleteCutflowHistograms(int selbin);

 // 2D Histograms 
 Bool_t        init2DHistograms( TString uncbin );
 Bool_t        fill2DHistograms(Float_t weight, int selbin);
 Bool_t        write2DHistograms(int selbin);
 Bool_t        delete2DHistograms(int selbin);

 
 // Electron Variables
 Bool_t        initEleHistograms( TString uncbin );
 Bool_t        fillEleHistograms(Float_t weight, int selbin );
 Bool_t        writeEleHistograms(int selbin);
 Bool_t        deleteEleHistograms(int selbin);


 // Muon Variables
 Bool_t        initMuHistograms( TString uncbin );
 Bool_t        fillMuHistograms(Float_t weight, int selbin);
 Bool_t        writeMuHistograms(int selbin);
 Bool_t        deleteMuHistograms(int selbin);
 // Lepton Variables
 Bool_t        initLepHistograms( TString uncbin );
 Bool_t        fillLepHistograms(Float_t weight, int selbin);
 Bool_t        writeLepHistograms(int selbin);
 Bool_t        deleteLepHistograms(int selbin);
 // Photon Variables
 Bool_t        initPhoHistograms( TString uncbin );
 Bool_t        fillPhoHistograms(Float_t weight, int selbin);
 Bool_t        writePhoHistograms(int selbin);
 Bool_t        deletePhoHistograms(int selbin);
 // MET/HT Variables
 Bool_t        initMETHTHistograms( TString uncbin );
 Bool_t        fillMETHTHistograms(Float_t weight, int selbin);
 Bool_t        writeMETHTHistograms(int selbin);
 Bool_t        deleteMETHTHistograms(int selbin);
 // Weight Variables
 Bool_t        initWeightHistograms( TString uncbin );
 Bool_t        fillWeightHistograms(Float_t weight, int selbin);
 Bool_t        writeWeightHistograms(int selbin);
 Bool_t        deleteWeightHistograms(int selbin);
// Transverse Mass histograms
 Bool_t        initTransverseMassHistograms( TString uncbin );	
 Bool_t        fillTransverseMassHistograms(Float_t weight, int selbin);
 Bool_t        writeTransverseMassHistograms(int selbin);
 Bool_t        deleteTransverseMassHistograms(int selbin);
// Wboson Transverse Momentum histograms 
 Bool_t        initWbosonPtHistograms( TString uncbin );	
 Bool_t        fillWbosonPtHistograms(Float_t weight, int selbin);
 Bool_t        writeWbosonPtHistograms(int selbin);
 Bool_t        deleteWbosonPtHistograms(int selbin);

 // Trigger Turn On Curves
 Bool_t        initTTOCHistograms( TString uncbin );
 Bool_t        fillTTOCHistograms(Float_t weight, int selbin);
 Bool_t        writeTTOCHistograms(int selbin);
 Bool_t        deleteTTOCHistograms(int selbin);

 // AODCaloJet Basic Variables
 Bool_t        initAODCaloJetBasicHistograms( TString uncbin );
 Bool_t        fillAODCaloJetBasicHistograms(Float_t weight, int selbin, int jetbin);
 Bool_t        writeAODCaloJetBasicHistograms(int selbin, int jetbin);
 Bool_t        deleteAODCaloJetBasicHistograms(int selbin);
 Bool_t        deleteAODCaloJetBasicHistograms(int selbin, int jetbin);
 // AODCaloJet Study Variables
 Bool_t        initAODCaloJetStudyHistograms( TString uncbin );
 Bool_t        fillAODCaloJetStudyHistograms(Float_t weight, int selbin, int jetbin);
 Bool_t        writeAODCaloJetStudyHistograms(int selbin, int jetbin);
 //Bool_t        deleteAODCaloJetStudyHistograms(int selbin);
 Bool_t        deleteAODCaloJetStudyHistograms(int selbin, int jetbin);
 // AODCaloJet _L1PF Variables
 Bool_t        initAODCaloJet_L1PFHistograms( TString uncbin );
 Bool_t        fillAODCaloJet_L1PFHistograms(Float_t weight, int selbin, int jetbin);
 Bool_t        writeAODCaloJet_L1PFHistograms(int selbin, int jetbin);
 Bool_t        deleteAODCaloJet_L1PFHistograms(int selbin);
 Bool_t        deleteAODCaloJet_L1PFHistograms(int selbin, int jetbin);
 // AODCaloJet Extra Variables
 Bool_t        initAODCaloJetExtraHistograms( TString uncbin );
 Bool_t        fillAODCaloJetExtraHistograms(Float_t weight, int selbin, int jetbin);
 Bool_t        writeAODCaloJetExtraHistograms(int selbin, int jetbin);
 Bool_t        deleteAODCaloJetExtraHistograms(int selbin, int jetbin);
 // AODCaloJetTag Basic Variables
 Bool_t        initAODCaloJetTagHistograms( TString uncbin );
 Bool_t        fillAODCaloJetTagHistograms(Float_t weight, int selbin, int tagbin);
 Bool_t        writeAODCaloJetTagHistograms(int selbin, int tagbin);
 Bool_t        deleteAODCaloJetTagHistograms(int selbin, int tagbin);
 // Jet Multiplicity
 Bool_t        initAODCaloJetMultHistograms( TString uncbin );
 Bool_t        fillAODCaloJetMultHistograms(Float_t weight, int selbin);
 Bool_t        writeAODCaloJetMultHistograms(int selbin);
 Bool_t        deleteAODCaloJetMultHistograms(int selbin);
 Bool_t        initAODCaloJetTagMultHistograms( TString uncbin );
 Bool_t        fillAODCaloJetTagMultHistograms(Float_t weight, int selbin);
 Bool_t        writeAODCaloJetTagMultHistograms(int selbin);
 Bool_t        deleteAODCaloJetTagMultHistograms(int selbin);

 // Extra histograms
 Bool_t        initExtraHistograms(TString uncbin );
 Bool_t        fillExtraHistograms(Float_t weight, int selbin);
 Bool_t        writeExtraHistograms(int selbin);
 Bool_t        deleteExtraHistograms(int selbin);

 //For variable binning
 Bool_t        scaleVariableBinHistograms(int selbin);

 // Set up which histograms to fill 
 Bool_t        fillSelectedHistograms(Float_t weight, int selbin);
 Bool_t        fillSelectedJetHistograms(Float_t weight, int selbin, int jetbin);
 Bool_t        fillSelectedTagHistograms(Float_t weight, int selbin, int tagbin);
 Bool_t        writeSelectedHistograms(int selbin);
 Bool_t        writeSelectedJetHistograms(int selbin, int jetbin);
 Bool_t        writeSelectedTagHistograms(int selbin, int tagbin);

 Bool_t dofillselbin    [SELBINNAMESIZE];

 
 //------------------Trigger turn on curve
 
 //basic histograms
 TH1F*  h_TTOCMu1Pt                [SELBINNAMESIZE];
 TH1F*  h_TTOCMu2Pt                [SELBINNAMESIZE];
 TH2F*  h_TTOCMuPt                 [SELBINNAMESIZE];
 TH1F*  h_TTOCMu1Eta               [SELBINNAMESIZE];
 TH1F*  h_TTOCMu2Eta               [SELBINNAMESIZE];
 TH2F*  h_TTOCMuEta                [SELBINNAMESIZE];
 TH1F*  h_TTOCEle1Pt               [SELBINNAMESIZE];
 TH1F*  h_TTOCEle2Pt               [SELBINNAMESIZE];
 TH2F*  h_TTOCElePt                [SELBINNAMESIZE];
 TH1F*  h_TTOCEle1Eta              [SELBINNAMESIZE];
 TH1F*  h_TTOCEle2Eta              [SELBINNAMESIZE];
 TH2F*  h_TTOCEleEta               [SELBINNAMESIZE];
 //EMu->leadElectronPt>leadMuonPt, MuE->leadMuonPt>leadElectronPt
 TH1F*  h_TTOCEMu_ElePt            [SELBINNAMESIZE];
 TH1F*  h_TTOCEMu_MuPt             [SELBINNAMESIZE];
 TH2F*  h_TTOCEMuPt                [SELBINNAMESIZE];
 TH1F*  h_TTOCEMu_EleEta           [SELBINNAMESIZE];
 TH1F*  h_TTOCEMu_MuEta            [SELBINNAMESIZE];
 TH2F*  h_TTOCEMuEta               [SELBINNAMESIZE];
 TH1F*  h_TTOCMuE_ElePt            [SELBINNAMESIZE];
 TH1F*  h_TTOCMuE_MuPt             [SELBINNAMESIZE];
 TH2F*  h_TTOCMuEPt                [SELBINNAMESIZE];
 TH1F*  h_TTOCMuE_EleEta           [SELBINNAMESIZE];
 TH1F*  h_TTOCMuE_MuEta            [SELBINNAMESIZE];
 TH2F*  h_TTOCMuEEta               [SELBINNAMESIZE];
 TH1F*  h_TTOCPhoPt                [SELBINNAMESIZE];
 TH1F*  h_TTOCPhoEta               [SELBINNAMESIZE];
 
 //--Double Muon
 TH1F*  h_TTOCTriggerDMu1Pt        [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerDMu2Pt        [SELBINNAMESIZE];
 TH2F*  h_TTOCTriggerDMuPt         [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerDMu1Eta       [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerDMu2Eta       [SELBINNAMESIZE];
 TH2F*  h_TTOCTriggerDMuEta        [SELBINNAMESIZE];//here
 TH1F*  h_TTOCTriggerDTkMu1Eta     [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerDTkMu2Eta     [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerDTkMu1Pt      [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerDTkMu2Pt      [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerNoDZMu1Eta    [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerNoDZMu2Eta    [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerNoDZMu1Pt     [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerNoDZMu2Pt     [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerNoDZTkMu1Eta  [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerNoDZTkMu2Eta  [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerNoDZTkMu1Pt   [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerNoDZTkMu2Pt   [SELBINNAMESIZE];
 //--Single Muon
 TH1F*  h_TTOCTrigger22MuEta       [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger22MuPt        [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger22TkMuEta     [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger22TkMuPt      [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger24MuEta       [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger24MuPt        [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger24TkMuEta     [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger24TkMuPt      [SELBINNAMESIZE];
 
//Double Electron
 TH1F*  h_TTOCTrigger23DEle1Eta    [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger23DEle2Eta    [SELBINNAMESIZE];
 TH2F*  h_TTOCTrigger23DEleEta     [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger23DEle1Pt     [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger23DEle2Pt     [SELBINNAMESIZE];
 TH2F*  h_TTOCTrigger23DElePt      [SELBINNAMESIZE];//here
 TH1F*  h_TTOCTrigger17DEle1Eta    [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger17DEle2Eta    [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger17DEle1Pt     [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger17DEle2Pt     [SELBINNAMESIZE];
 //Single Electron
 TH1F*  h_TTOCTrigger23EleEta      [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger23ElePt       [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger27EleEta      [SELBINNAMESIZE];
 TH1F*  h_TTOCTrigger27ElePt       [SELBINNAMESIZE];
 //Single Photon
 TH1F*  h_TTOCTriggerPhoEta        [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerPhoPt         [SELBINNAMESIZE];
 //--EMu
 TH1F*  h_TTOCTriggerEMu_ElePt     [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerEMu_MuPt      [SELBINNAMESIZE];
 TH2F*  h_TTOCTriggerEMuPt         [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerEMu_EleEta    [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerEMu_MuEta     [SELBINNAMESIZE];
 TH2F*  h_TTOCTriggerEMuEta        [SELBINNAMESIZE];
 //--MuE
 TH1F*  h_TTOCTriggerMuE_ElePt     [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerMuE_MuPt      [SELBINNAMESIZE];
 TH2F*  h_TTOCTriggerMuEPt         [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerMuE_EleEta    [SELBINNAMESIZE];
 TH1F*  h_TTOCTriggerMuE_MuEta     [SELBINNAMESIZE];
 TH2F*  h_TTOCTriggerMuEEta        [SELBINNAMESIZE];
 

 // Cutflow histograms
 TH1F* h_Cutflow                       [SELBINNAMESIZE];
 TH1F* h_Onecut                        [SELBINNAMESIZE];
 TH1F* h_NMinus                        [SELBINNAMESIZE];
 TH1F* h_RawCutflow                    [SELBINNAMESIZE];
 TH1F* h_RawOnecut                     [SELBINNAMESIZE];
 TH1F* h_RawNMinus                     [SELBINNAMESIZE];
 

 // Electron
 TH1F*  h_AOD_nEle                     [SELBINNAMESIZE]; //;
 TH1F*  h_AOD_nSelectedEle             [SELBINNAMESIZE]; //;
 TH1F*  h_AOD_elePt                    [SELBINNAMESIZE]; //;
 TH1F*  h_AOD_eleEn                    [SELBINNAMESIZE]; //;
 TH1F*  h_AOD_eleEta                   [SELBINNAMESIZE]; //;
 TH1F*  h_AOD_elePhi                   [SELBINNAMESIZE]; //;
 TH1F*  h_AOD_eleCharge                [SELBINNAMESIZE]; //;

 // Muon
 TH1F*  h_AOD_nMu                     [SELBINNAMESIZE];
 TH1F*  h_AOD_nSelectedMu             [SELBINNAMESIZE];
 TH1F*  h_AOD_muPt                    [SELBINNAMESIZE];
 TH1F*  h_AOD_muEn                    [SELBINNAMESIZE];
 TH1F*  h_AOD_muEta                   [SELBINNAMESIZE];
 TH1F*  h_AOD_muPhi                   [SELBINNAMESIZE];
 TH1F*  h_AOD_muCharge                [SELBINNAMESIZE];
 TH1F*  h_AOD_muPFdBetaIsolation      [SELBINNAMESIZE];
 
 // Generic Lepton
 TH1F*  h_AOD_dilepton_Mass           [SELBINNAMESIZE];
 TH1F*  h_AOD_dilepton_Pt             [SELBINNAMESIZE];
 TH1F*  h_AOD_dileptonNewB_Pt             [SELBINNAMESIZE];
 TH1F*  h_AOD_OSOFdilepton_Mass       [SELBINNAMESIZE];
 TH1F*  h_AOD_OSOFdilepton_Pt         [SELBINNAMESIZE];

 // Photon
 TH1F*  h_AOD_nPho                     [SELBINNAMESIZE];
 TH1F*  h_AOD_nSelectedPho             [SELBINNAMESIZE];
 TH1F*  h_AOD_phoEn                    [SELBINNAMESIZE];
 TH1F*  h_AOD_phoPt                    [SELBINNAMESIZE];
 TH1F*  h_AOD_phoEta                   [SELBINNAMESIZE];
 TH1F*  h_AOD_phoPhi                   [SELBINNAMESIZE];

 // MET / HT
 TH1F*  h_AOD_MET_phi              [SELBINNAMESIZE];
 TH1F*  h_AOD_MET_pt               [SELBINNAMESIZE];
 TH1F*  h_htall                    [SELBINNAMESIZE];
 TH1F*  h_htaodcalojets            [SELBINNAMESIZE];
 TH1F*  h_AODnGoodVtx              [SELBINNAMESIZE];
 TH1F*  h_AODnVtx                  [SELBINNAMESIZE];
 TH1F*  h_AODnTruePU               [SELBINNAMESIZE];

 // Weight
 TH2F*  h_eleID              [SELBINNAMESIZE];
 TH2F*  h_muonID             [SELBINNAMESIZE];
 TH2F*  h_muonISO            [SELBINNAMESIZE];
 TH1F*  h_LeptonSF            [SELBINNAMESIZE];

 TH1F*  h_eleID_Unc               [SELBINNAMESIZE];
 TH1F*  h_muonID_Unc               [SELBINNAMESIZE];
 TH1F*  h_muonISO_Unc               [SELBINNAMESIZE];
 TH1F*  h_LeptonSF_Unc               [SELBINNAMESIZE];

 TH1F*  h_LumiWeight              [SELBINNAMESIZE];
 TH1F*  h_PUWeight                  [SELBINNAMESIZE];
 TH1F*  h_GenEventWeight               [SELBINNAMESIZE];
 TH1F*  h_OtherWeight               [SELBINNAMESIZE];
 TH1F*  h_FullWeight               [SELBINNAMESIZE];

 //WH mode
 TH1F*  h_TransverseMass       [SELBINNAMESIZE]; 
 TH1F*  h_Wboson_pt	       [SELBINNAMESIZE]; 
 
 // nJets
 TH1F*  h_nSelectedAODCaloJet_L1PFTag    [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJet            [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTag         [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTag_varbin  [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTag_varbinunit  [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB1      [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB2      [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB3      [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB4      [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB5      [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB6      [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB7      [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSBL1     [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSBL2     [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSBL3     [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSBL4     [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSBL5     [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSBL6     [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSBL7     [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB2a     [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB2b     [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB2c     [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagIP       [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSBIPa    [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSBIPb    [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSBIPc    [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTag_0b      [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB1_0b   [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB2_0b   [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB3_0b   [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTag_1b      [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB1_1b   [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB2_1b   [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB3_1b   [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTag_2b      [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB1_2b   [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB2_2b   [SELBINNAMESIZE];
 TH1F*  h_nSelectedAODCaloJetTagSB3_2b   [SELBINNAMESIZE];
 TH1F*  h_nCaloJet                       [SELBINNAMESIZE]; // AODnCaloJet; 
 TH1F*  h_nCaloJet_L1PF                  [SELBINNAMESIZE]; // AODnCaloJet_L1PF; 
 TH1F*  h_nPFJet                         [SELBINNAMESIZE]; // AODnPFJet; 
 TH1F*  h_nPFchsJet                      [SELBINNAMESIZE]; // AODnPFchsJet; 

 // AODCaloJetBasicHistograms
 TH1F*  h_AODCaloJetPt                             [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetPtVar                          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetEta                            [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetPhi                            [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax2                      [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMaxPrime                  [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMaxPrime2                 [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetBeta                           [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetBeta2                          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetSumIP                          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetSumIPSig                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianIP                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetTrackAngle                     [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetLogTrackAngle                  [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetTotalTrackAngle                [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMinDR                          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetCSV                            [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetPartonFlavour                  [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAbsEta                         [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH2F*  h_AODCaloJetPtVarAbsEtaVar                 [SELBINNAMESIZE][JETMULTNAMESIZE];

 TH1F*  h_AODCaloJetAlphaMax_0Tag                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_0Tag               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_0Tag          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax_1Tag                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_1Tag               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_1Tag          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax_2Tag                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_2Tag               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_2Tag          [SELBINNAMESIZE][JETMULTNAMESIZE];

 TH1F*  h_AODCaloJetAlphaMax_Pass                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_Pass               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_Pass          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax_UpPass                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_UpPass               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_UpPass          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax_DownPass                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_DownPass               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_DownPass          [SELBINNAMESIZE][JETMULTNAMESIZE];

 TH1F*  h_AODCaloJetAlphaMax_alsoPass                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_alsoPass               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_alsoPass          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax_UpalsoPass                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_UpalsoPass               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_UpalsoPass          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax_DownalsoPass                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_DownalsoPass               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_DownalsoPass          [SELBINNAMESIZE][JETMULTNAMESIZE];

 TH1F*  h_AODCaloJetAlphaMax_Pass_wWeight                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_Pass_wWeight               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_Pass_wWeight          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax_UpPass_wWeight                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_UpPass_wWeight               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_UpPass_wWeight          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax_DownPass_wWeight                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_DownPass_wWeight               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_DownPass_wWeight          [SELBINNAMESIZE][JETMULTNAMESIZE];

 TH1F*  h_AODCaloJetAlphaMax_alsoPass_wWeight                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_alsoPass_wWeight               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_alsoPass_wWeight          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax_UpalsoPass_wWeight                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_UpalsoPass_wWeight               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_UpalsoPass_wWeight          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAlphaMax_DownalsoPass_wWeight                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10IPSig_DownalsoPass_wWeight               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMedianLog10TrackAngle_DownalsoPass_wWeight          [SELBINNAMESIZE][JETMULTNAMESIZE];



 // Study tag var shift necessity
 TH1F*  h_AODCaloJet_Study_trk0_AlphaMax                [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJet_Study_trk0_MedianLog10IPSig        [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJet_Study_trk0_MedianLog10TrackAngle   [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJet_Study_ptG0p5_AlphaMax              [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJet_Study_ptG0p5_MedianLog10IPSig      [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJet_Study_ptG0p5_MedianLog10TrackAngle [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJet_Study_ptG10_AlphaMax               [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJet_Study_ptG10_MedianLog10IPSig       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJet_Study_ptG10_MedianLog10TrackAngle  [SELBINNAMESIZE][JETMULTNAMESIZE];

 TH2F*  h_AODCaloJet_Study_n_v_AlphaMax                 [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH2F*  h_AODCaloJet_Study_n_v_MedianLog10IPSig         [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH2F*  h_AODCaloJet_Study_n_v_MedianLog10TrackAngle    [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH2F*  h_AODCaloJet_Study_pt_v_AlphaMax                [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH2F*  h_AODCaloJet_Study_pt_v_MedianLog10IPSig        [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH2F*  h_AODCaloJet_Study_pt_v_MedianLog10TrackAngle   [SELBINNAMESIZE][JETMULTNAMESIZE];
 
 
 // AODCaloJetL1PFHistograms
 TH1F*  h_AODCaloJet_L1PFPt                             [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFPtVar                          [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFEta                            [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFPhi                            [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJet_L1PFAlphaMax                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFAlphaMax2                      [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFAlphaMaxPrime                  [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFAlphaMaxPrime2                 [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFBeta                           [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFBeta2                          [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFSumIP                          [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFSumIPSig                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFMedianIP                       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJet_L1PFMedianLog10IPSig               [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFTrackAngle                     [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFLogTrackAngle                  [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJet_L1PFMedianLog10TrackAngle          [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFTotalTrackAngle                [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH1F*  h_AODCaloJet_L1PFAbsEta                         [SELBINNAMESIZE][JETMULTNAMESIZE];
 //TH2F*  h_AODCaloJet_L1PFPtVarAbsEtaVar                 [SELBINNAMESIZE][JETMULTNAMESIZE];

 // AODCaloJetExtraHistograms
 TH1F*  h_AODCaloJetAvfVx                          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVy                          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVz                          [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexTotalChiSquared       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexDegreesOfFreedom      [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexChi2NDoF              [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexDistanceToBeam        [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexTransverseError       [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexTransverseSig         [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexDeltaEta              [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexDeltaPhi              [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexRecoilPt              [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexTrackMass             [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexTrackEnergy           [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfBeamSpotDeltaPhi            [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfBeamSpotRecoilPt            [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfBeamSpotMedianDeltaPhi      [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfBeamSpotLog10MedianDeltaPhi [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetNCleanMatchedTracks            [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetSumHitsInFrontOfVert           [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetSumMissHitsAfterVert           [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetHitsInFrontOfVertPerTrack      [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetMissHitsAfterVertPerTrack      [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfDistToPV                    [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexDeltaZtoPV            [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH1F*  h_AODCaloJetAvfVertexDeltaZtoPV2           [SELBINNAMESIZE][JETMULTNAMESIZE];

 // AODCaloJetTagHistograms
 TH1F*  h_AODCaloJetPt_Tag0                       [SELBINNAMESIZE][TAGMULTNAMESIZE];
 TH1F*  h_AODCaloJetPtVar_Tag0                    [SELBINNAMESIZE][TAGMULTNAMESIZE];
 TH1F*  h_AODCaloJetMinDR_Tag0                    [SELBINNAMESIZE][TAGMULTNAMESIZE];
 TH1F*  h_AODCaloJetCSV_Tag0                      [SELBINNAMESIZE][TAGMULTNAMESIZE];
 TH1F*  h_AODCaloJetPartonFlavour_Tag0            [SELBINNAMESIZE][TAGMULTNAMESIZE];
 TH1F*  h_AODCaloJetAbsEta_Tag0                   [SELBINNAMESIZE][TAGMULTNAMESIZE];
 TH1F*  h_AODCaloJetNCleanMatchedTracks_Tag0      [SELBINNAMESIZE][TAGMULTNAMESIZE];
 TH2F*  h_AODCaloJetPtVarAbsEtaVar_Tag0           [SELBINNAMESIZE][TAGMULTNAMESIZE];
 

 // // 2D
 TH2F* h_IpVAlpha                  [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH2F* h_IpVjetPt                  [SELBINNAMESIZE][JETMULTNAMESIZE];
 TH2F* h_AlphaVjetPt               [SELBINNAMESIZE][JETMULTNAMESIZE];
 

 // Background Estimate
 int getMistagRateBin(int j, TString mistag_name);
 float getMistagRateByBin(int j, TString mistag_name);
 float getMistagRate(int j, TString mistag_name);
 float computeTerm(int b, std::vector<int> mistagBins_tagged, std::vector<int> mistagBins_untagged, TString mistag_name);
 void comb(int n, int r, int *arr, int sz, Float_t weight, TString mistag_name);
 TH1F* h_bkgest_pt = NULL;
 TH1F* h_bkgest_pteta = NULL;
 Bool_t initBackgroundEstimateHistograms();
 Bool_t fillBackgroundEstimateHistograms(Float_t weight);
 Bool_t writeBackgroundEstimateHistograms(TFile* outfile);


};

#endif
