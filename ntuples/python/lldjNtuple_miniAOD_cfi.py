import FWCore.ParameterSet.Config as cms
from HiggsAnalysis.HiggsTo2photons.hggPhotonIDCuts_cfi import *
#from PhysicsTools.SelectorUtils.pfJetIDSelector_cfi import pfJetIDSelector
#from CMGTools.External.pujetidproducer_cfi import stdalgos, chsalgos

lldjNtuple = cms.EDAnalyzer("lldjNtuple",
                             doGenParticles       = cms.bool(True),
                             dumpPhotons          = cms.bool(True), 
                             dumpJets             = cms.bool(False),
                             dumpSubJets          = cms.bool(False),
                             dumpTaus             = cms.bool(False),
                             dumpPDFSystWeight    = cms.bool(False),

                             triggerEvent         = cms.InputTag("selectedPatTrigger", "", ""),
                             triggerResults       = cms.InputTag("TriggerResults", "", "HLT"),

                             genParticleSrc       = cms.InputTag("prunedGenParticles"),
                             LHEEventLabel        = cms.InputTag("externalLHEProducer"),
                             pileupCollection     = cms.InputTag("slimmedAddPileupInfo"),
                             VtxLabel             = cms.InputTag("offlineSlimmedPrimaryVertices"),
                             VtxBSLabel           = cms.InputTag("offlinePrimaryVerticesWithBS"),
                             rhoLabel             = cms.InputTag("fixedGridRhoFastjetAll"),
                             rhoCentralLabel      = cms.InputTag("fixedGridRhoFastjetCentralNeutral"),
                             pfMETLabel           = cms.InputTag("slimmedMETs"),

                             electronSrc          = cms.InputTag("selectedElectrons"),
                             photonSrc            = cms.InputTag("selectedPhotons"),
                             muonSrc              = cms.InputTag("slimmedMuons"),

                             #isAOD                = cms.bool(False), #### actually configured through run_data_74x.py


                             hggPhotonIDConfiguration = hggPhotonIDCuts,
                             runOnParticleGun     = cms.bool(False),
                             runOnSherpa          = cms.bool(False),
                             runHFElectrons       = cms.bool(True),
                             #development          = cms.bool(False),
                             #addFilterInfoAOD     = cms.bool(False),
                             addFilterInfoMINIAOD = cms.bool(True),
                             #doNoHFMET            = cms.bool(False),

                             trgFilterDeltaPtCut  = cms.double(0.5),
                             trgFilterDeltaRCut   = cms.double(0.3),

                             #patTriggerResults = cms.InputTag("TriggerResults", "", "PAT"),
                             patTriggerResults    = cms.InputTag("TriggerResults", "", "RECO"),
                             generatorLabel       = cms.InputTag("generator"),
                             newParticles         = cms.vint32(4000011, 4000013, 1000006, 1000021, 1000022, 1000024, 1000025, 35),
                             #gsfTrackSrc          = cms.InputTag("electronGsfTracks"),
                             ebReducedRecHitCollection = cms.InputTag("reducedEgamma", "reducedEBRecHits"),
                             eeReducedRecHitCollection = cms.InputTag("reducedEgamma", "reducedEERecHits"),
                             esReducedRecHitCollection = cms.InputTag("reducedEgamma", "reducedESRecHits"),
                             recoPhotonSrc             = cms.InputTag("reducedEgamma", "reducedGedPhotonCores"),
                             TrackLabel                = cms.InputTag("generalTracks"),
                             #gsfElectronLabel          = cms.InputTag("gsfElectrons"),
                             PFAllCandidates           = cms.InputTag("particleFlow"),

                             ak4JetSrc                 = cms.InputTag("slimmedJets"),
                             ak8JetSrc                 = cms.InputTag("slimmedJetsAK8"),
                             #ak4JetSrc                 = cms.InputTag("selectedUpdatedPatJetsUpdatedJEC"),
                             #ak8JetSrc                 = cms.InputTag("selectedUpdatedPatJetsUpdatedJECAK8"),

                             #boostedDoubleSVLabel      = cms.InputTag("pfBoostedDoubleSecondaryVertexAK8BJetTags"),
                             tauSrc                    = cms.InputTag("slimmedTaus"),
                             #pfLooseId                 = pfJetIDSelector.clone(),

                             phoLooseIdMap   = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring16-V2p2-loose"),
                             phoMediumIdMap  = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring16-V2p2-medium"),
                             phoTightIdMap   = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring16-V2p2-tight"),
                             phoMVAValuesMap = cms.InputTag("photonMVAValueMapProducer:PhotonMVAEstimatorRun2Spring16NonTrigV1Values"),
                             phoChargedIsolation       = cms.InputTag("photonIDValueMapProducer:phoChargedIsolation"),
                             phoNeutralHadronIsolation = cms.InputTag("photonIDValueMapProducer:phoNeutralHadronIsolation"),
                             phoPhotonIsolation        = cms.InputTag("photonIDValueMapProducer:phoPhotonIsolation"),
                             phoWorstChargedIsolation  = cms.InputTag("photonIDValueMapProducer:phoWorstChargedIsolation"),
                             #phoChargedIsolation_CITK        = cms.InputTag("egmPhotonIsolationMiniAOD:h+-DR030-"),
                             #phoPhotonIsolation_CITK         = cms.InputTag("egmPhotonIsolationMiniAOD:gamma-DR030-"),
                             #phoNeutralHadronIsolation_CITK  = cms.InputTag("egmPhotonIsolationMiniAOD:h0-DR030-"),
                             #phoChargedIsolation_PUPPI       = cms.InputTag("egmPhotonIsolationMiniAODPUPPI:h+-DR030-"),
                             #phoPhotonIsolation_PUPPI        = cms.InputTag("egmPhotonIsolationMiniAODPUPPI:gamma-DR030-"),
                             #phoNeutralHadronIsolation_PUPPI = cms.InputTag("egmPhotonIsolationMiniAODPUPPI:h0-DR030-"),
                             packedPFCands   = cms.InputTag("packedPFCandidates"),
                             eleVetoIdMap    = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-veto"),
                             eleLooseIdMap   = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-loose"),
                             eleMediumIdMap  = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-medium"),
                             eleTightIdMap   = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-tight"),
                             eleHLTIdMap     = cms.InputTag("egmGsfElectronIDs:cutBasedElectronHLTPreselection-Summer16-V1"),
                             eleHEEPIdMap    = cms.InputTag("egmGsfElectronIDs:heepElectronID-HEEPV70"),
                             eleMVAValuesMap = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring16GeneralPurposeV1Values"),
                             eleMVAHZZValuesMap = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring16HZZV1Values"),
                             elePFClusEcalIsoProducer = cms.InputTag("electronEcalPFClusterIsolationProducer"),
                             elePFClusHcalIsoProducer = cms.InputTag("electronHcalPFClusterIsolationProducer"),
                             BadChargedCandidateFilter = cms.InputTag("BadChargedCandidateFilter"),
                             BadPFMuonFilter           = cms.InputTag("BadPFMuonFilter"),

                             irrelevent = cms.InputTag("3."),
)