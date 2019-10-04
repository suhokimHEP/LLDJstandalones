#!/bin/bash

# DAS client API to get dataset info

# get the DAS name mapping
thedasmap="${listdir}/ntuple/dasmap.list"

samples=( \
 "WJetsToLNu"                       \
 
# "WplusH_HToSSTobbbb_MS-55_ctauS-1"    \
# "WplusH_HToSSTobbbb_MS-55_ctauS-10"   \
# "WplusH_HToSSTobbbb_MS-55_ctauS-100"  \
# "WplusH_HToSSTobbbb_MS-55_ctauS-1000" \
# "WplusH_HToSSTobbbb_MS-40_ctauS-1"    \
# "WplusH_HToSSTobbbb_MS-40_ctauS-10"   \
# "WplusH_HToSSTobbbb_MS-40_ctauS-100"  \
# "WplusH_HToSSTobbbb_MS-40_ctauS-1000" \
# "WplusH_HToSSTobbbb_MS-15_ctauS-1"    \
# "WplusH_HToSSTobbbb_MS-15_ctauS-10"   \
# "WplusH_HToSSTobbbb_MS-15_ctauS-100"  \
# "WplusH_HToSSTobbbb_MS-15_ctauS-1000" \
# "WminusH_HToSSTobbbb_MS-55_ctauS-1"    \
# "WminusH_HToSSTobbbb_MS-55_ctauS-10"   \
# "WminusH_HToSSTobbbb_MS-55_ctauS-100"  \
# "WminusH_HToSSTobbbb_MS-55_ctauS-1000" \
# "WminusH_HToSSTobbbb_MS-40_ctauS-1"    \
# "WminusH_HToSSTobbbb_MS-40_ctauS-10"   \
# "WminusH_HToSSTobbbb_MS-40_ctauS-100"  \
# "WminusH_HToSSTobbbb_MS-40_ctauS-1000" \
# "WminusH_HToSSTobbbb_MS-15_ctauS-1"    \
# "WminusH_HToSSTobbbb_MS-15_ctauS-10"   \
# "WminusH_HToSSTobbbb_MS-15_ctauS-100"  \
# "WminusH_HToSSTobbbb_MS-15_ctauS-1000" \
 
 "QCD_HT100to200"    \
 "QCD_HT200to300"    \
 "QCD_HT300to500"    \
 "QCD_HT500to700"    \
 "QCD_HT700to1000"   \
 "QCD_HT1000to1500"  \
 "QCD_HT1500to2000"  \
 "QCD_HT2000toInf"   \
)

# "ggZH_HToSSTobbbb_MS40_ctauS0"     \
# "ggZH_HToSSTobbbb_MS40_ctauS0p05"  \
# "ggZH_HToSSTobbbb_MS40_ctauS1"     \
# "ggZH_HToSSTobbbb_MS40_ctauS10"    \
# "ggZH_HToSSTobbbb_MS40_ctauS100"   \
# "ggZH_HToSSTobbbb_MS40_ctauS1000"  \
# "ggZH_HToSSTobbbb_MS40_ctauS10000" \
   
# "DoubleEG"                            \
# "DoubleMuon"                          \
# "MuonEG"                              \

# "DY5to50_HT70To100"                \
# "DY5to50_HT100To200"               \
# "DY5to50_HT200To400"               \
# "DY5to50_HT400To600"               \
# "DY5to50_HT600ToInf"               \
# "DY50"                             \
# "ggZH_HToBB_ZToLL"                 \
# "GJets_HT40To100"                  \
# "GJets_HT100To200"                 \
# "GJets_HT200To400"                 \
# "GJets_HT400To600"                 \
# "GJets_HT600ToInf"                 \
# "ST_s"                             \
# "STbar_t"                          \
# "ST_t"                             \
# "STbar_tW"                         \
# "ST_tW"                            \
# "TTtoLL"                           \
# "TTtoLfromTbar"                    \
# "TTtoLfromT"                       \
# "WG"                               \
# "WJetsToLNu"                       \
# "WWToLNuLNu"                       \
# "WWToLNuQQ"                        \
# "WZToL3Nu"                         \
# "WZTo3LNu"                         \
# "WZToLNu2QorQQ2L"                  \
# "ZG"                               \
# "ZH_HToBB_ZToLL"                   \
# "ZZToLLNuNu"                       \
# "ZZToLLQQ"                         \
# "ZZToNuNuQQ"                       \
# "ZZToLLLL"                         \
# "SingleElectron"                   \
# "SingleMuon"                       \


for sample in ${samples[@]}
do

 #python dascli.py --query="dataset dataset=/ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1_TuneCUETP8M1_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM | grep dataset.size, dataset.nevents"
printf "%s\n---------------------------\n" ${sample}

datasetname="$(grep -P ${sample} ${thedasmap} | sed -n -e "s@ ${sample}    @@p")"

parent="$(python dascli.py --query='parent dataset='"${datasetname}")"
sevts="$(python dascli.py --query='dataset dataset='"${datasetname}"' | grep dataset.size, dataset.nevents')"
pevts="$(python dascli.py --query='dataset dataset='"${parent}"' | grep dataset.size, dataset.nevents')"

printf "%s \n%s \n" ${datasetname} ${parent} 
printf "%s \n" ${sevts}
printf "%s \n\n" ${pevts}


#dasgoclient -query="lumi,file dataset=/EphemeralHLTPhysics1/Run2017F-v1/RAW run=305183"

# lc=$( cat  "/nfs_scratch/tperry/gitignore/${aversion}/${sample}/checker.sh" | grep "root" | wc -l )
# left=$(bash "/nfs_scratch/tperry/gitignore/${aversion}/${sample}/checker.sh" | wc -l )
 
done
 # printf " --------------------------------------------------\n"
 # printf "%40s %4s %4s \n" Total  $totin $totleft
