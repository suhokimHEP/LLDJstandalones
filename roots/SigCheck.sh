#!/bin/bash

mass=( \ 
 "15"  \
 "40"  \
 "55"  \
) 

dologs=( \
 "1" \
 "3" \
 "10" \
 "30" \
 "100" \
 "300" \
 "1000" \
)

doHIPs=( \
 "ZH" \
 "ggZH" \
)

for massp in ${mass[@]}
do
 for dolog in ${dologs[@]}
 do
  for doHIP in ${doHIPs[@]}
  do
   root -l -b -q  'SignalCheck.C('\""${massp}"\"', '\""${dolog}"\"', '\""${doHIP}"\"')'
  done
 done
done
