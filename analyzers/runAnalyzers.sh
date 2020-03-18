#!/bin/bash


for sample in \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"  \

do
#  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "-1" -i "../lists" -o "junk" -n 999999999 -a 1 -d -m
  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "-1" -i "../lists" -o "varbin" -n 5 -a 1 -d -m


done #for sample in DY50..

#for sample in \
# "Data_DoubleMu_G"
#
#do
#  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "100000" -i "../lists" -o "SF" -n 30 -a 1 -d
#done # for datasample               
