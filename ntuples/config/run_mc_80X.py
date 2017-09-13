import FWCore.ParameterSet.Config as cms

##########################################################################################
# Setup

# this is the process run by cmsRun
process = cms.Process('LLDJ')
#process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(True) )

# log output
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )  ## number of events -1 does all
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
#process.Tracer = cms.Service("Tracer")

# input files
process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
 #'/store/mc/RunIISummer16MiniAODv2/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1/100000/00099D43-77ED-E611-8889-5065F381E1A1.root',

  #/ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-100_TuneCUETP8M1_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM
   #'file:/uscms_data/d3/tmperry/LLDJ_slc6_530_CMSSW_8_0_26_patch2/src/LLDJstandalones/roots/08BA365D-40E5-E611-955F-00266CF89498.root'


  #'/store/mc/RunIISummer16MiniAODv2/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/110000/08BA365D-40E5-E611-955F-00266CF89498.root'
  #'/store/mc/RunIISpring16MiniAODv2/TT_TuneCUETP8M1_13TeV-powheg-pythia8/MINIAODSIM/PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0_ext4-v1/00000/004A0552-3929-E611-BD44-0025905A48F0.root'
  #'/store/mc/RunIISummer16MiniAODv2/WWTo2L2Nu_13TeV-powheg/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/80000/08E155A9-FAB6-E611-92BF-00259073E45E.root'

   #'file:/afs/hep.wisc.edu/cms/tperry/LLDJ_slc6_530_CMSSW_8_0_26_patch2/src/LLDJstandalones/roots/miniAOD/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10_787B82F9-0ECB-E611-A5CD-1866DAEA7EA8.root',
   #'file:/afs/hep.wisc.edu/cms/tperry/LLDJ_slc6_530_CMSSW_8_0_26_patch2/src/LLDJstandalones/roots/miniAOD/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_EA59D0D0-5CCB-E611-B501-002590207C28.root',


#  # MS40-CT1,0p05
   #'file:/uscms_data/d3/tmperry/LLDJ_slc6_530_CMSSW_8_0_26_patch2/src/LLDJstandalones/roots/miniAOD/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-0p05_52134309-19CF-E611-AD86-0CC47A4D7604.root',
#   'file:/uscms_data/d3/tmperry/LLDJ_slc6_530_CMSSW_8_0_26_patch2/src/LLDJstandalones/roots/miniAOD/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_2CA15029-73CB-E611-8315-02163E019C53.root',
   #'file:/uscms_data/d3/tmperry/LLDJ_slc6_530_CMSSW_8_0_26_patch2/src/LLDJstandalones/roots/miniAOD/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1_62211E56-2EC9-E611-95F3-02163E019C8F.root'

#  # MS40-CT100
  #'/store/mc/RunIISummer16MiniAODv2/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_TuneCUETP8M1_13TeV-powheg-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/120000/54C6A127-05CA-E611-AAD2-0CC47A1DF1A4.root',
  #'/store/mc/RunIISummer16MiniAODv2/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_TuneCUETP8M1_13TeV-powheg-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/120000/70576F21-CDC9-E611-BC72-001E675047A5.root',
  #'/store/mc/RunIISummer16MiniAODv2/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_TuneCUETP8M1_13TeV-powheg-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/120000/EA59D0D0-5CCB-E611-B501-002590207C28.root'

  'file:/uscms_data/d3/tmperry/LLDJ_slc6_530_CMSSW_8_0_26_patch2/src/LLDJstandalones/roots/miniAOD/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_54C6A127-05CA-E611-AAD2-0CC47A1DF1A4.root'
 ),
   secondaryFileNames= cms.untracked.vstring(
  #'/store/mc/RunIISummer16DR80Premix/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_TuneCUETP8M1_13TeV-powheg-pythia8/AODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/120000/D6822833-FEC8-E611-8CD1-002590E7D7DE.root',
  'file:/uscms_data/d3/tmperry/LLDJ_slc6_530_CMSSW_8_0_26_patch2/src/LLDJstandalones/roots/AOD/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100_D6822833-FEC8-E611-8CD1-002590E7D7DE.root'
 ),
)


# output name
process.TFileService = cms.Service("TFileService", fileName = cms.string('lldjntuple_mc.root'));

#process.out = cms.OutputModule(
#"PoolOutputModule",
#     fileName = cms.untracked.string("output6.root"),
#     outputCommands = cms.untracked.vstring( 
#      "keep *", )  
#)

# cms geometry
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff")

# global tag
process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = '80X_mcRun2_asymptotic_2016_TrancheIV_v8'

##########################################################################################
# Jet Energy Corrections
# https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookJetEnergyCorrections#CorrPatJets
# just take from global tag, no need to update collections

##########################################################################################
# Electron / Photon Corrections
# https://twiki.cern.ch/twiki/bin/view/CMS/EGMRegression

### EGM 80X regression
from EgammaAnalysis.ElectronTools.regressionWeights_cfi import regressionWeights
process = regressionWeights(process)
process.load('EgammaAnalysis.ElectronTools.regressionApplication_cff')

# Some proesses need random numbers, calculate using TRandom3 - Mersenne Twister
process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
 calibratedPatElectrons  = cms.PSet( initialSeed = cms.untracked.uint32(8675389),
                                     engineName = cms.untracked.string('TRandom3'),
                                     ),
 calibratedPatPhotons    = cms.PSet( initialSeed = cms.untracked.uint32(8675389),
                                     engineName = cms.untracked.string('TRandom3'),
                                     ),
 lldjNtuple              = cms.PSet( initialSeed = cms.untracked.uint32(67890),
                                     engineName = cms.untracked.string('TRandom3')
                                     )
)
process.load('EgammaAnalysis.ElectronTools.calibratedPatElectronsRun2_cfi')
process.load('EgammaAnalysis.ElectronTools.calibratedPatPhotonsRun2_cfi')

# correct scale (data) or smear resolution (MC) 
process.calibratedPatElectrons.isMC = cms.bool(True)
process.calibratedPatPhotons.isMC = cms.bool(True)


##########################################################################################
# Electron / Photon Versioned ID

from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
dataFormat = DataFormat.MiniAOD
switchOnVIDElectronIdProducer(process, dataFormat)
switchOnVIDPhotonIdProducer(process, dataFormat)

# define which IDs we want to produce
eleid_modules = ['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Summer16_80X_V1_cff',
                 'RecoEgamma.ElectronIdentification.Identification.cutBasedElectronHLTPreselecition_Summer16_V1_cff',
                 #'RecoEgamma.ElectronIdentification.Identification.heepElectronID_HEEPV70_cff',
                 'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring16_GeneralPurpose_V1_cff',
                 'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring16_HZZ_V1_cff']
    
phoid_modules = ['RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Spring16_V2p2_cff',
                 'RecoEgamma.PhotonIdentification.Identification.mvaPhotonID_Spring16_nonTrig_V1_cff']

#add them to the VID producer
for idmod in eleid_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection)

for idmod in phoid_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDPhotonSelection)

# hack recommended by https://twiki.cern.ch/twiki/bin/view/CMS/EGMRegression#VIDAnchor
process.selectedElectrons = cms.EDFilter("PATElectronSelector",
    src = cms.InputTag("calibratedPatElectrons",'','LLDJ'),
    cut = cms.string("pt>5 && abs(superCluster.eta)<2.5")
)

process.selectedPhotons = cms.EDFilter("PATPhotonSelector",
    src = cms.InputTag("calibratedPatPhotons",'','LLDJ'),
    cut = cms.string("pt>5 && abs(superCluster.eta)<2.5")
)

# say which collections to run on 
process.load("RecoEgamma.ElectronIdentification.ElectronIDValueMapProducer_cfi")
process.load("RecoEgamma.PhotonIdentification.PhotonIDValueMapProducer_cfi")

# 
process.egmGsfElectronIDs.physicsObjectSrc = cms.InputTag('selectedElectrons','','LLDJ')
process.egmPhotonIDs.physicsObjectSrc = cms.InputTag('selectedPhotons','','LLDJ')

process.electronIDValueMapProducer.srcMiniAOD = cms.InputTag('selectedElectrons','','LLDJ')
process.electronMVAValueMapProducer.srcMiniAOD = cms.InputTag('selectedElectrons','','LLDJ')
process.photonIDValueMapProducer.srcMiniAOD = cms.InputTag('selectedPhotons','','LLDJ')
process.photonMVAValueMapProducer.srcMiniAOD = cms.InputTag('selectedPhotons','','LLDJ')

process.electronIDValueMapProducer.src = cms.InputTag('selectedElectrons','','LLDJ')
process.electronMVAValueMapProducer.src = cms.InputTag('selectedElectrons','','LLDJ')
process.photonIDValueMapProducer.src = cms.InputTag('selectedPhotons','','LLDJ')
process.photonMVAValueMapProducer.src = cms.InputTag('selectedPhotons','','LLDJ')

### ##process.electronRegressionValueMapProducer.srcMiniAOD = cms.InputTag('selectedElectrons','','LLDJ')
### ##process.photonRegressionValueMapProducer.srcMiniAOD = cms.InputTag('selectedPhotons','','LLDJ')
### ##process.electronRegressionValueMapProducer.src = cms.InputTag('selectedElectrons','','LLDJ')
### ##process.photonRegressionValueMapProducer.src = cms.InputTag('selectedPhotons','','LLDJ')

process.egmPhotonIsolation.srcToIsolate = cms.InputTag('selectedPhotons','','LLDJ')


# be explicit to avoid AOD / miniAOD overlap
# # ##process.photonIDValueMapProducer.ebReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"),
# # ##process.photonIDValueMapProducer.ebReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedEBRecHits"),
# # ##process.photonIDValueMapProducer.eeReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsEE"),
# # ##process.photonIDValueMapProducer.eeReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedEERecHits"),
# # ##process.photonIDValueMapProducer.esReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsES"),
# # ##process.photonIDValueMapProducer.esReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedESRecHits"),
# # ##process.photonIDValueMapProducer.particleBasedIsolation = cms.InputTag("particleBasedIsolation","gedPhotons"),
# # ##process.photonIDValueMapProducer.pfCandidates = cms.InputTag("packedPFCandidates"),
# # ##process.photonIDValueMapProducer.pfCandidatesMiniAOD = cms.InputTag("packedPFCandidates"),
# # ##process.photonIDValueMapProducer.src = cms.InputTag("selectedPhotons","","LLDJ"),
# # ##process.photonIDValueMapProducer.srcMiniAOD = cms.InputTag("selectedPhotons","","LLDJ"),
# # ##process.photonIDValueMapProducer.vertices = cms.InputTag("offlinePrimaryVertices"),
# # ##process.photonIDValueMapProducer.verticesMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")

#process.photonIDValueMapProducer.ebReducedRecHitCollection = cms.InputTag("reducedEgamma","reducedEBRecHits"),
#process.photonIDValueMapProducer.ebReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedEBRecHits"),
#process.photonIDValueMapProducer.eeReducedRecHitCollection = cms.InputTag("reducedEgamma","reducedEERecHits"),
#process.photonIDValueMapProducer.eeReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedEERecHits"),
#process.photonIDValueMapProducer.esReducedRecHitCollection = cms.InputTag("reducedEgamma","reducedESRecHits"),
#process.photonIDValueMapProducer.esReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedESRecHits"),
#process.photonIDValueMapProducer.particleBasedIsolation = cms.InputTag("particleBasedIsolation","gedPhotons"),
#process.photonIDValueMapProducer.pfCandidates = cms.InputTag("packedPFCandidates"),
#process.photonIDValueMapProducer.pfCandidatesMiniAOD = cms.InputTag("packedPFCandidates"),
#process.photonIDValueMapProducer.src = cms.InputTag("selectedPhotons","","LLDJ"),
#process.photonIDValueMapProducer.srcMiniAOD = cms.InputTag("selectedPhotons","","LLDJ"),
#process.photonIDValueMapProducer.vertices = cms.InputTag("offlineSlimmedPrimaryVertices"),
#process.photonIDValueMapProducer.verticesMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")

##########################################################################################
# Now update MET
# 

# uncomment this and comment out MET and you can
# uncomment plugins/lldjNtuple_jets.cc L1210-L1215
#process.load("Configuration.StandardSequences.Reconstruction_cff")

 ## "standard sequence from dump_python
##  from RecoLuminosity.LumiProducer.lumiProducer_cff import *
##  from RecoLuminosity.LumiProducer.bunchSpacingProducer_cfi import *
##  from RecoLocalMuon.Configuration.RecoLocalMuon_cff import *
##  from RecoLocalCalo.Configuration.RecoLocalCalo_cff import *
##  #from RecoLocalFastTime.Configuration.RecoLocalFastTime_cff import *
##  from RecoTracker.Configuration.RecoTracker_cff import *
##  from RecoParticleFlow.PFClusterProducer.particleFlowCluster_cff import *
##  from TrackingTools.Configuration.TrackingTools_cff import *
##  from RecoTracker.MeasurementDet.MeasurementTrackerEventProducer_cfi import *
##  from RecoPixelVertexing.PixelLowPtUtilities.siPixelClusterShapeCache_cfi import *
##  siPixelClusterShapeCachePreSplitting = siPixelClusterShapeCache.clone(
##      src = 'siPixelClustersPreSplitting'
##      )
##  
##  # Global  reco
##  from RecoEcal.Configuration.RecoEcal_cff import *
##  from RecoJets.Configuration.CaloTowersRec_cff import *
##  from RecoMET.Configuration.RecoMET_cff import *
##  from RecoMuon.Configuration.RecoMuon_cff import *
##  # Higher level objects
##  from RecoVertex.Configuration.RecoVertex_cff import *
##  from RecoEgamma.Configuration.RecoEgamma_cff import *
##  from RecoPixelVertexing.Configuration.RecoPixelVertexing_cff import *
##  
##  
##  from RecoJets.Configuration.RecoJetsGlobal_cff import *
##  from RecoMET.Configuration.RecoPFMET_cff import *
##  from RecoBTag.Configuration.RecoBTag_cff import *
##  #
##  # please understand that division global,highlevel is completely fake !
##  #
##  #local reconstruction
##  from RecoLocalTracker.Configuration.RecoLocalTracker_cff import *
##  from RecoParticleFlow.Configuration.RecoParticleFlow_cff import *
##  from RecoCTPPS.Configuration.recoCTPPS_cff import *
##  #
##  # new tau configuration
##  #
##  from RecoTauTag.Configuration.RecoPFTauTag_cff import *
##  # Also BeamSpot
##  from RecoVertex.BeamSpotProducer.BeamSpot_cff import *
##  
##  from RecoLocalCalo.CastorReco.CastorSimpleReconstructor_cfi import *
##  
##  # Cosmic During Collisions
##  from RecoTracker.SpecialSeedGenerators.cosmicDC_cff import *
##  
##  localreco = cms.Sequence(bunchSpacingProducer+trackerlocalreco+muonlocalreco+calolocalreco+castorreco)
##  localreco_HcalNZS = cms.Sequence(bunchSpacingProducer+trackerlocalreco+muonlocalreco+calolocalrecoNZS+castorreco)
##  
##  #_run3_localreco = localreco.copyAndExclude([castorreco])
##  #_run3_localreco_HcalNZS = localreco_HcalNZS.copyAndExclude([castorreco])
##  #from Configuration.Eras.Modifier_run3_common_cff import run3_common
##  #run3_common.toReplaceWith(localreco, _run3_localreco)
##  #run3_common.toReplaceWith(localreco_HcalNZS, _run3_localreco_HcalNZS)
##  
##  #from Configuration.Eras.Modifier_phase2_timing_layer_cff import phase2_timing_layer
##  #_phase2_timing_layer_localreco = _run3_localreco.copy()
##  #_phase2_timing_layer_localreco += fastTimingLocalReco
##  #_phase2_timing_layer_localreco_HcalNZS = _run3_localreco_HcalNZS.copy()
##  #_phase2_timing_layer_localreco_HcalNZS += fastTimingLocalReco
##  #phase2_timing_layer.toReplaceWith(localreco,_phase2_timing_layer_localreco)
##  #phase2_timing_layer.toReplaceWith(localreco_HcalNZS,_phase2_timing_layer_localreco_HcalNZS)
##  #
##  #_ctpps_2016_localreco = localreco.copy()
##  #_ctpps_2016_localreco += recoCTPPS
##  #from Configuration.Eras.Modifier_ctpps_2016_cff import ctpps_2016
##  #ctpps_2016.toReplaceWith(localreco, _ctpps_2016_localreco)
##  #
##  #_ctpps_2016_localreco_HcalNZS = localreco_HcalNZS.copy()
##  #_ctpps_2016_localreco_HcalNZS += recoCTPPS
##  #ctpps_2016.toReplaceWith(localreco_HcalNZS, _ctpps_2016_localreco_HcalNZS)
##  
##  #
##  # temporarily switching off recoGenJets; since this are MC and wil be moved to a proper sequence
##  #
##  
##  from RecoLocalCalo.Castor.Castor_cff import *
##  from RecoLocalCalo.Configuration.hcalGlobalReco_cff import *
##  
##  globalreco_tracking = cms.Sequence(offlineBeamSpot*
##                            MeasurementTrackerEventPreSplitting* # unclear where to put this
##                            siPixelClusterShapeCachePreSplitting* # unclear where to put this
##                            standalonemuontracking*
##                            trackingGlobalReco*
##                            hcalGlobalRecoSequence*
##                            vertexreco)
##  _globalreco_tracking_LowPU = globalreco_tracking.copy()
##  _globalreco_tracking_LowPU.replace(trackingGlobalReco, recopixelvertexing+trackingGlobalReco)
##  #from Configuration.Eras.Modifier_trackingLowPU_cff import trackingLowPU
##  #trackingLowPU.toReplaceWith(globalreco_tracking, _globalreco_tracking_LowPU)
##  
##  globalreco = cms.Sequence(globalreco_tracking*
##                            particleFlowCluster*
##                            ecalClusters*
##                            caloTowersRec*                          
##                            egammaGlobalReco*
##                            jetGlobalReco*
##                            muonGlobalReco*
##                            pfTrackingGlobalReco*
##                            muoncosmicreco*
##                            CastorFullReco)
##  
##  _run3_globalreco = globalreco.copyAndExclude([CastorFullReco])
##  #run3_common.toReplaceWith(globalreco, _run3_globalreco)
##  
##  globalreco_plusPL= cms.Sequence(globalreco*ctfTracksPixelLess)
##  
##  reducedRecHits = cms.Sequence ( reducedEcalRecHitsSequence * reducedHcalRecHitsSequence )
##  
##  highlevelreco = cms.Sequence(egammaHighLevelRecoPrePF*
##                               particleFlowReco*
##                               egammaHighLevelRecoPostPF*
##                               muoncosmichighlevelreco*
##                               muonshighlevelreco *
##                               particleFlowLinks*
##                               jetHighLevelReco*
##                               metrecoPlusHCALNoise*
##                               btagging*
##                               recoPFMET*
##                               PFTau*
##                               reducedRecHits*
##                               cosmicDCTracksSeq
##                               )
##  
##  
##  from FWCore.Modules.logErrorHarvester_cfi import *
##  
##  # "Export" Section
##  reconstruction         = cms.Sequence(localreco*globalreco*highlevelreco*logErrorHarvester)
##  
##  reconstruction_trackingOnly = cms.Sequence(localreco*globalreco_tracking)
##  
##  #need a fully expanded sequence copy
##  modulesToRemove = list() # copy does not work well
##  noTrackingAndDependent = list()
##  noTrackingAndDependent.append(siPixelClustersPreSplitting)
##  noTrackingAndDependent.append(siStripZeroSuppression)
##  noTrackingAndDependent.append(siStripClusters)
##  noTrackingAndDependent.append(initialStepSeedLayersPreSplitting)
##  #noTrackingAndDependent.append(trackerClusterCheckPreSplitting)
##  #noTrackingAndDependent.append(initialStepTrackingRegionsPreSplitting)
##  #noTrackingAndDependent.append(initialStepHitDoubletsPreSplitting)
##  #noTrackingAndDependent.append(initialStepHitTripletsPreSplitting)
##  noTrackingAndDependent.append(initialStepSeedsPreSplitting)
##  noTrackingAndDependent.append(initialStepTrackCandidatesPreSplitting)
##  noTrackingAndDependent.append(initialStepTracksPreSplitting)
##  noTrackingAndDependent.append(firstStepPrimaryVerticesPreSplitting)
##  noTrackingAndDependent.append(initialStepTrackRefsForJetsPreSplitting)
##  noTrackingAndDependent.append(caloTowerForTrkPreSplitting)
##  noTrackingAndDependent.append(ak4CaloJetsForTrkPreSplitting)
##  noTrackingAndDependent.append(jetsForCoreTrackingPreSplitting)
##  noTrackingAndDependent.append(siPixelClusterShapeCachePreSplitting)
##  noTrackingAndDependent.append(siPixelClusters)
##  noTrackingAndDependent.append(clusterSummaryProducer)
##  noTrackingAndDependent.append(siPixelRecHitsPreSplitting)
##  noTrackingAndDependent.append(MeasurementTrackerEventPreSplitting)
##  noTrackingAndDependent.append(PixelLayerTriplets)
##  noTrackingAndDependent.append(pixelTracks)
##  noTrackingAndDependent.append(pixelVertices)
##  modulesToRemove.append(dt1DRecHits)
##  modulesToRemove.append(dt1DCosmicRecHits)
##  modulesToRemove.append(csc2DRecHits)
##  modulesToRemove.append(rpcRecHits)
##  #modulesToRemove.append(ecalGlobalUncalibRecHit)
##  modulesToRemove.append(ecalMultiFitUncalibRecHit)
##  modulesToRemove.append(ecalDetIdToBeRecovered)
##  modulesToRemove.append(ecalRecHit)
##  modulesToRemove.append(ecalCompactTrigPrim)
##  modulesToRemove.append(ecalTPSkim)
##  modulesToRemove.append(ecalPreshowerRecHit)
##  modulesToRemove.append(selectDigi)
##  modulesToRemove.append(hbheprereco)
##  modulesToRemove.append(hbhereco)
##  modulesToRemove.append(hfreco)
##  modulesToRemove.append(horeco)
##  modulesToRemove.append(hcalnoise)
##  modulesToRemove.append(zdcreco)
##  modulesToRemove.append(castorreco)
##  ##it's OK according to Ronny modulesToRemove.append(CSCHaloData)#needs digis
##  reconstruction_fromRECO = reconstruction.copyAndExclude(modulesToRemove+noTrackingAndDependent)
##  noTrackingAndDependent.append(siPixelRecHitsPreSplitting)
##  noTrackingAndDependent.append(siStripMatchedRecHits)
##  noTrackingAndDependent.append(pixelTracks)
##  noTrackingAndDependent.append(ckftracks)
##  reconstruction_fromRECO_noTrackingTest = reconstruction.copyAndExclude(modulesToRemove+noTrackingAndDependent)
##  ##requires generalTracks trajectories
##  noTrackingAndDependent.append(trackerDrivenElectronSeeds)
##  noTrackingAndDependent.append(ecalDrivenElectronSeeds)
##  noTrackingAndDependent.append(uncleanedOnlyElectronSeeds)
##  noTrackingAndDependent.append(uncleanedOnlyElectronCkfTrackCandidates)
##  noTrackingAndDependent.append(uncleanedOnlyElectronGsfTracks)
##  noTrackingAndDependent.append(uncleanedOnlyGeneralConversionTrackProducer)
##  noTrackingAndDependent.append(uncleanedOnlyGsfConversionTrackProducer)
##  noTrackingAndDependent.append(uncleanedOnlyPfTrackElec)
##  noTrackingAndDependent.append(uncleanedOnlyGsfElectronCores)
##  noTrackingAndDependent.append(uncleanedOnlyPfTrack)
##  noTrackingAndDependent.append(uncleanedOnlyGeneralInOutOutInConversionTrackMerger)#can live with
##  noTrackingAndDependent.append(uncleanedOnlyGsfGeneralInOutOutInConversionTrackMerger)#can live with
##  noTrackingAndDependent.append(uncleanedOnlyAllConversions)
##  noTrackingAndDependent.append(uncleanedOnlyGsfElectrons)#can live with
##  noTrackingAndDependent.append(electronMergedSeeds)
##  noTrackingAndDependent.append(electronCkfTrackCandidates)
##  noTrackingAndDependent.append(electronGsfTracks)
##  noTrackingAndDependent.append(generalConversionTrackProducer)
##  noTrackingAndDependent.append(generalInOutOutInConversionTrackMerger)
##  noTrackingAndDependent.append(gsfGeneralInOutOutInConversionTrackMerger)
##  noTrackingAndDependent.append(ecalDrivenGsfElectrons)
##  noTrackingAndDependent.append(gsfConversionTrackProducer)
##  noTrackingAndDependent.append(allConversions)
##  noTrackingAndDependent.append(gsfElectrons)
##  reconstruction_fromRECO_noTracking = reconstruction.copyAndExclude(modulesToRemove+noTrackingAndDependent)
##  reconstruction_noTracking = reconstruction.copyAndExclude(noTrackingAndDependent)
##  
##  
##  #sequences with additional stuff
##  reconstruction_withPixellessTk  = cms.Sequence(localreco        *globalreco_plusPL*highlevelreco*logErrorHarvester)
##  reconstruction_HcalNZS = cms.Sequence(localreco_HcalNZS*globalreco       *highlevelreco*logErrorHarvester)
##  
##  #sequences without some stuffs
##  #
##  reconstruction_woCosmicMuons = cms.Sequence(localreco*globalreco*highlevelreco*logErrorHarvester)
##  
##  
##  # define a standard candle. please note I am picking up individual
##  # modules instead of sequences
##  #
##  reconstruction_standard_candle = cms.Sequence(localreco*globalreco*vertexreco*recoJetAssociations*btagging*electronSequence*photonSequence)




#from PhysicsTools.PatUtils.tools.runMETCorrectionsAndUncertainties import runMetCorAndUncFromMiniAOD
#runMetCorAndUncFromMiniAOD(process,
#                           isData=False
#                           )
## MET Filters
#from RecoMET.METFilters.BadPFMuonFilter_cfi import *
#BadPFMuonFilter.muons = cms.InputTag("slimmedMuons", "", "PAT")
#BadPFMuonFilter.PFCandidates = cms.InputTag("packedPFCandidates", "", "PAT")
#
#from RecoMET.METFilters.BadChargedCandidateFilter_cfi import *
#BadChargedCandidateFilter.muons = cms.InputTag("slimmedMuons", "", "PAT")
#BadChargedCandidateFilter.PFCandidates = cms.InputTag("packedPFCandidates", "", "PAT")
#
#process.lldjMETFiltersSequence = cms.Sequence(
#     BadPFMuonFilter *
#     BadChargedCandidateFilter 
#)


jecLevels = [
  'Summer16_23Sep2016V4_MC_L2Relative_AK8PFchs.txt',
  'Summer16_23Sep2016V4_MC_L3Absolute_AK8PFchs.txt'
]
























#NTuplizer
process.lldjNtuple = cms.EDAnalyzer("lldjNtuple",

 electronSrc               = cms.InputTag("selectedElectrons",'','LLDJ'),
 rhoLabel                  = cms.InputTag("fixedGridRhoFastjetAll"),
 eleVetoIdMap              = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-veto"),
 eleLooseIdMap             = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-loose"),
 eleMediumIdMap            = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-medium"),
 eleTightIdMap             = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-tight"),
 eleHLTIdMap               = cms.InputTag("egmGsfElectronIDs:cutBasedElectronHLTPreselection-Summer16-V1"),
 #eleMVAValuesMap           = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring16GeneralPurposeV1Values"),
 #eleMVAHZZValuesMap        = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring16HZZV1Values"),
 #elePFClusEcalIsoProducer  = cms.InputTag("electronEcalPFClusterIsolationProducer"),
 #elePFClusHcalIsoProducer  = cms.InputTag("electronHcalPFClusterIsolationProducer"),

 rhoCentralLabel           = cms.InputTag("fixedGridRhoFastjetCentralNeutral"),
 pileupCollection          = cms.InputTag("slimmedAddPileupInfo"),
 VtxLabel                  = cms.InputTag("offlineSlimmedPrimaryVertices"),
 triggerResults            = cms.InputTag("TriggerResults", "", "HLT"),

 ak4JetSrc                 = cms.InputTag("slimmedJets"),
 AODak4CaloJetsSrc         = cms.InputTag("ak4CaloJets" , "", "RECO"),
 AODak4PFJetsSrc           = cms.InputTag("ak4PFJets"   , "", "RECO"),
 AODak4PFJetsCHSSrc        = cms.InputTag("ak4PFJetsCHS", "", "RECO"),
 AODVertexSrc              = cms.InputTag("offlinePrimaryVertices", "", "RECO"),
 AODTrackSrc               = cms.InputTag("generalTracks", "", "RECO"),

 patTriggerResults         = cms.InputTag("TriggerResults", "", "PAT"),
 BadChargedCandidateFilter = cms.InputTag("BadChargedCandidateFilter"),
 BadPFMuonFilter           = cms.InputTag("BadPFMuonFilter"),
 pfMETLabel                = cms.InputTag("slimmedMETs"),

 muonSrc                   = cms.InputTag("slimmedMuons"),

 photonSrc                 = cms.InputTag("selectedPhotons",'','LLDJ'),

)

process.load("LLDJstandalones.ntuples.lldjMETFilters_cff")

#builds Ntuple
process.p = cms.Path(
    process.regressionApplication*  # e/gamma energy correction/resolution regression
    process.calibratedPatElectrons*
    process.calibratedPatPhotons*
    process.selectedElectrons*
    process.selectedPhotons*
    process.egmGsfElectronIDSequence*
    #process.egmPhotonIDSequence
    #process.lldjMETFiltersSequence*
    process.lldjNtuple
    )

#process.ep = cms.EndPath(process.out)
#print process.dumpPython()
#print process.egmGsfElectronIDSequence.dumpPython()
