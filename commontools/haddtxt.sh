#!/bin/bash

# just calls the hadd scripts automatically generated
# submission time in ${basedir}/submitters/gitignore/${aversion}/${sample}/haddit.sh
mkdir -p "${rootdir}/${aversion}"
mkdir -p "${plotdir}/${aversion}"
mkdir -p "${plotdir}/${aversion}/logs"
thedasmap="${listdir}/ntuple/Analyzername.list"
# sample names to run over
samples=( \
##### Data
### DoubleMu
## "Data_DoubleMu_H_3"      \
## "Data_DoubleMu_H_2"      \
## "Data_DoubleMu_G"        \
### DoubleEG
## "Data_DoubleEG_H_3"      \
## "Data_DoubleEG_H_2"      \
## "Data_DoubleEG_G"        \
### MuonEG
## "Data_MuonEG_H_3"        \
## "Data_MuonEG_H_2"        \
## "Data_MuonEG_G"          \
### SinglePhoton
## "Data_SinglePhoton_H_3"  \
## "Data_SinglePhoton_H_2"  \
## "Data_SinglePhoton_G"    \
#### Monte Carlo Samples
## Signal
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"      \
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"     \
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"    \
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"   \
## "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"        \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"       \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"      \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"     \
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"      \
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"     \
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"    \
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"   \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"        \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"       \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"      \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"     \
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"      \
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"     \
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"    \
## "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"   \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"        \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"       \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"      \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"     \
### DY
### "DYJetsToLL_M-5to50_HT-70to100"   \
### "DYJetsToLL_M-5to50_HT-100to200"  \
### "DYJetsToLL_M-5to50_HT-200to400"  \
### "DYJetsToLL_M-5to50_HT-400to600"  \
### "DYJetsToLL_M-5to50_HT-600toInf"  \
# "DYJetsToLL_M-10to50"             \
# "DYJetsToLL_M-50"                 \
### WJets
## "WJetsToLNu"     \
### TTbar
##"QCD_HT100to200"    \
## "QCD_HT200to300"    \
## "QCD_HT300to500"    \
## "QCD_HT500to700"    \
## "QCD_HT700to1000"   \
## "QCD_HT1000to1500"  \
## "QCD_HT1500to2000"  \
## "QCD_HT2000toInf"   \
)

for sample in ${samples[@]}
do

 mkdir -p "${rootdir}/${aversion}/${sample}/TwoEleZH"
 mkdir -p "${rootdir}/${aversion}/${sample}/TwoMuZH"
 mkdir -p "${rootdir}/${aversion}/${sample}/TwoEleDY"
 mkdir -p "${rootdir}/${aversion}/${sample}/TwoMuDY"

 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_edmEventPick.sh"    


 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_edmEventPick.sh"    

 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_IPSigUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_IPSigUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_IPSigUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_IPSigUp_edmEventPick.sh"    

 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_IPSigUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_IPSigUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_IPSigUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_IPSigUp_edmEventPick.sh"    

 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_IPSigDown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_IPSigDown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_IPSigDown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_IPSigDown_edmEventPick.sh"    

 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_IPSigDown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_IPSigDown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_IPSigDown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_IPSigDown_edmEventPick.sh"    

 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_AMaxUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_AMaxUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_AMaxUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_AMaxUp_edmEventPick.sh"    

 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_AMaxUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_AMaxUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_AMaxUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_AMaxUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_AMaxDown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_AMaxDown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_AMaxDown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_AMaxDown_edmEventPick.sh"    

 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_AMaxDown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_AMaxDown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_AMaxDown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_AMaxDown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_TAUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_TAUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_TAUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_TAUp_edmEventPick.sh"    

 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_TAUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_TAUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_TAUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_TAUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_TADown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_TADown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_TADown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_TADown_edmEventPick.sh"    

 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_TADown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_TADown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_TADown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_TADown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_TagVarsUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_TagVarsUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_TagVarsUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_TagVarsUp_edmEventPick.sh"    

 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_TagVarsUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_TagVarsUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_TagVarsUp_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_TagVarsUp_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_TagVarsDown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_TagVarsDown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_TagVarsDown_edmEventPick.sh"    
 chmod +x "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_TagVarsDown_edmEventPick.sh"    

 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleZH_TagVarsDown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuZH_TagVarsDown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoEleDY_TagVarsDown_edmEventPick.sh"    
 bash "${basedir}/submitters/gitignore/${aversion}/${sample}/cat_TwoMuDY_TagVarsDown_edmEventPick.sh"    
done



#for samplename in ${samples[@]}
#do
# datasetname=$(grep -P ${samplename} ${thedasmap} | sed -n -e "s@ ${samplename}    @@p")
# echo "hello"
# echo ${thedasmap}
# echo ${samplename}
# echo ${datasetname}
#
# DATASET="${datasetname}"
# echo ${DATASET}
# cd "${rootdir}/${aversion}/${sample}/TwoEleZH"
# edmPickEvents.py ${DATASET} ${sample}_cat_TwoEleZH_edmEventPick.txt  
# crab submit -c pickevents_crab.py
# cd "${rootdir}/${aversion}/${sample}/TwoMuZH"
# edmPickEvents.py ${DATASET} ${sample}_cat_TwoMuZH_edmEventPick.txt  
# crab submit -c pickevents_crab.py
#
#done
