#!/bin/bash

for sample in \
 "DYJetsToLL_M-50"  

do
#  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "-1" -i "../lists" -o "junk" -n 999999999 -a 1 -d -m
  ./runanalyzer.exe -s ${sample} -l "16200" -x "" -e "500000" -i "../lists" -o "Zmass" -n 50 -a 1 -d -m

done #for sample in DY50..

for sample in \
 "Data_DoubleEG_G"  
# "Data_DoubleMu_G"

do
  ./runanalyzer.exe -s ${sample} -l "20000" -x "" -e "500000" -i "../lists" -o "Zmass" -n 50 -a 1 -d
done # for datasample               
