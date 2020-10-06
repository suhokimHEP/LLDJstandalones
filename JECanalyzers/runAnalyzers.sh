#!/bin/bash

for sample in \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"  \

do
#  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "-1" -i "../lists" -o "junk" -n 999999999 -a 1 -d -m
  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "-1" -i "../lists" -o "junk" -n 10 -a 1 -d -m

done #for sample in DY50..

for sample in \
 "Data_DoubleEG_H"    \

do
  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "-1" -i "../lists" -o "junk" -n 10 -a 1 -d
done # for datasample               
