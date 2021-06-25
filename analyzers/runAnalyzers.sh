#!/bin/bash

for sample in \
 "mad_DYJetsToLL_M-50"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"  \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"  \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"  \

do
  ./runanalyzer.exe -s ${sample} -l "12226" -x "" -e "-1" -i "../lists" -o "junk" -n 5 -a 1 -d -m

done #for sample in DY50..

#for sample in \
# "Data_DoubleEG_H"    \
#
#do
#  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "-1" -i "../lists" -o "junk" -n 10 -a 1 -d
#done # for datasample               
