
## Edited By Raman Khurana
##
## CRAB documentation : https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideCrab
##
## CRAB 3 parameters : https://twiki.cern.ch/twiki/bin/view/CMSPublic/CRAB3ConfigurationFile#CRAB_configuration_parameters
##
## Once you are happy with this file, please run
## crab submit

## In CRAB3 the configuration file is in Python language. It consists of creating a Configuration object imported from the WMCore library: 

from WMCore.Configuration import Configuration
config = Configuration()

##  Once the Configuration object is created, it is possible to add new sections into it with corresponding parameters
config.section_("General")
config.General.requestName = 'pickEvents'
config.General.workArea = 'crab_pickevents_20190922_232550'


config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/cvmfs/cms.cern.ch/slc6_amd64_gcc530/cms/cmssw-patch/CMSSW_8_0_26_patch1/src/PhysicsTools/Utilities/configuration/copyPickMerge_cfg.py'
config.JobType.pyCfgParams = ['eventsToProcess_load=pickevents_runEvents.txt', 'outputFile=pickevents.root']

config.section_("Data")
config.Data.inputDataset = '/ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_TuneCUETP8M1_13TeV-powheg-pythia8/RunIISummer16DR80Premix-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/AODSIM'

config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 5
config.Data.lumiMask = 'pickevents.json'
#config.Data.publication = True
#config.Data.publishDbsUrl = 'phys03'
#config.Data.publishDataName = 'CRAB3_CSA_DYJets'
#config.JobType.allowNonProductionCMSSW=True

config.section_("Site")
## Change site name accordingly
config.Site.storageSite = "T2_US_Wisconsin"

