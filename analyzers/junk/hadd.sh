#!/bin/bash

regions=( \ 
 "TwoEleZH"      \
 "TwoMuZH"       \
) 

dosamples=( \
 "MS-15_ctauS-1"      \
 "MS-15_ctauS-10"     \
 "MS-15_ctauS-100"    \
 "MS-15_ctauS-1000"   \
 "MS-40_ctauS-1"      \
 "MS-40_ctauS-10"     \
 "MS-40_ctauS-100"    \
 "MS-40_ctauS-1000"   \
 "MS-55_ctauS-1"      \
 "MS-55_ctauS-10"     \
 "MS-55_ctauS-100"    \
 "MS-55_ctauS-1000"   \
# "ZGTo2LG" \
# "DYJetsToLL_M-50" \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"      \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"     \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"    \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"   \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"      \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"     \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"    \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"   \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"      \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"     \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"    \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"   \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"      \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"     \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"    \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"   \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"      \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"     \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"    \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"   \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"      \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"     \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"    \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"   \
)
where="/uscms/home/skim2/nobackup"

for region in ${regions[@]}
do
 for sample in ${dosamples[@]}
 do
  hadd -f Sig_${sample}_${region}_histograms.root ZH_HToSSTobbbb_ZToLL_MH-125_${sample}_${region}_histograms.root   ggZH_HToSSTobbbb_ZToLL_MH-125_${sample}_${region}_histograms.root
 done
done
