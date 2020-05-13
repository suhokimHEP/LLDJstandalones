#!/bin/bash

regions=( \ 
# "EleMuOSOF"     \
# "EleMuOSOFL"    \
# "OnePho"        \
 "TwoEleDY"      \
# "TwoEleSig"     \
 "TwoEleZH"      \
 "TwoMuDY"       \
# "TwoMuSig"      \
 "TwoMuZH"       \
# "EleWHSig"  \
# "MuWHSig"   \
# "EleWH"     \
# "MuWH"      \
# "EleLowPtWH" \
# "MuLowPtWH"  \
) 

dologs=( \
# "kFALSE" \
 "kTRUE" \
)

doHIPs=( \
 "kFALSE" \
 #"kTRUE" \
)

doctaus=( \
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
   for doctau in ${doctaus[@]}
   do 
    root -l -b -q  'Sig_model.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${doctau}"', '"${useEOS}"', '\""${description}"\"')'
    #root -l -b -q  'Sig_texout.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${doctau}"', '"${useEOS}"', '\""${description}"\"')'
    #root -l -b -q  'Sig_calcout.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${doctau}"', '"${useEOS}"', '\""${description}"\"')'
    #root -l -b -q  'Zdark_stackedRegion.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${useEOS}"', '\""${description}"\"')'
    #root -l -b -q  'Sig_CSVout.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${doctau}"', '"${useEOS}"', '\""${description}"\"')'
    #root -l -b -q  'DY_CSVout.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${doctau}"', '"${useEOS}"', '\""${description}"\"')'
    #root -l -b -q  'Sig_stackedRegion.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${doctau}"', '"${useEOS}"', '\""${description}"\"')'
    #root -l -b -q  'DY_stackedRegion.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${doctau}"', '"${useEOS}"', '\""${description}"\"')'
    #root -l -b -q  'oldsignal.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${doctau}"', '"${useEOS}"', '\""${description}"\"')'
    #root -l -b -q  'plotter_signalstackedRegion.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${doctau}"', '"${useEOS}"', '\""${description}"\"')'
    #root -l -b -q  'plotter_stackedRegion.C('\""${region}"\"', '"${dolog}"', '"${doHIP}"', '"${doctau}"', '"${useEOS}"', '\""${description}"\"')'
   done
  done
 done
done
