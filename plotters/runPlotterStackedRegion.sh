#!/bin/bash

regions=( \ 
# "EleMuOSOF"     \
# "EleMuOSOFL"    \
# "OnePho"        \
# "TwoEleDY"      \
# "TwoEleSig"     \
# "TwoEleZH"      \
# "TwoMuDY"       \
# "TwoMuSig"      \
# "TwoMuZH"       \
 "EleWHSig"  \
 "MuWHSig"   \
 "EleWH"     \
 "MuWH"      \
 "EleLowPtWH" \
 "MuLowPtWH"  \
) 

dologs=( \
# "kFALSE" \
 "kTRUE" \
)

doHIPs=( \
 "kFALSE" \
 #"kTRUE" \
)

useEOS="kFALSE"
#useEOS="kTRUE"
description=""

for region in ${regions[@]}
do
 for dolog in ${dologs[@]}
 do
  for doHIP in ${doHIPs[@]}
  do
   root -l -b -q  'plotter_stackedRegion.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${useEOS}"', '\""${description}"\"')'
  done
 done
done
