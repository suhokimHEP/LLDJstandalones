#!/bin/bash

# just calls the checker scripts automatically generated
# submission time in ${basedir}/submitters/gitignore/${aversion}/${sample}/checker.sh

printf "Files checked for completion after condor submition : \n"
printf "%50s %4s %4s \n" Sample Tot  Left

samples=( \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-2"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-20"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-200"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-2"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-20"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-200"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-2"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-20"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-200"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-2"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-20"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-200"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-2"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-20"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-200"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-2"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-20"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-200"  \ 
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-3"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-30"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-300"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-3"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-30"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-300"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-3"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-30"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-300"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-3"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-30"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-300"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-3"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-30"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-300"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-3"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-30"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-300"  \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-5"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-50"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-500"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-5"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-50"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-500"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-5"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-50"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-500"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-5"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-50"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-500"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-5"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-50"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-500"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-5"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-50"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-500"  \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"   \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"      \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"     \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"    \
 "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000" \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000" \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"    \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"   \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"  \
 "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000" \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-2"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-20"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-200"    \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-2"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-20"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-200"    \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-2"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-20"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-200"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-2"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-20"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-200"  \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-2"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-20"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-200"  \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-2"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-20"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-200"  \ 
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-3"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-30"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-300"    \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-3"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-30"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-300"    \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-3"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-30"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-300"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-3"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-30"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-300"  \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-3"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-30"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-300"  \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-3"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-30"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-300"  \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-5"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-50"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-500"    \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-5"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-50"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-500"    \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-5"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-50"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-500"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-5"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-50"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-500"  \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-5"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-50"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-500"  \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-5"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-50"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-500"  \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-1"    \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-10"   \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-100"  \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-1000" \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-1"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-10"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-100"    \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-1000"   \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-1"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-10"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-100"    \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-1000"   \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-1"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-10"     \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-100"    \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-1000"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-1"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-10"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-100"  \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-1000" \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-1"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-10"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-100"  \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-15_ctauS-1000" \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-1"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-10"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-100"  \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-40_ctauS-1000" \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-1"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-10"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-100"  \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-55_ctauS-1000" \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-1"      \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-10"     \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-100"    \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-1000"   \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-1"      \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-10"     \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-100"    \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-1000"   \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-1"      \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-10"     \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-100"    \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-1000"   \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-1"      \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-10"     \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-100"    \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-1000"   \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-1"      \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-10"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-100"    \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-1000"   \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-1"      \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-10"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-100"    \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-1000"   \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-1"      \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-10"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-100"    \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-1000"   \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-1"      \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-10"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-100"    \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-1000"   \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-1"      \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-10"     \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-100"    \
 "ggZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-1000"   \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-1"        \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-10"       \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-100"      \
 "ZH_HToSSTodddd_ZToLL_MH-125_MS-7_ctauS-1000"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-1"      \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-10"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-100"    \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-1000"   \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-1"        \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-10"       \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-100"      \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-7_ctauS-1000"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-1"      \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-10"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-100"    \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-1000"   \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-1"        \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-10"       \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-100"      \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-15_ctauS-1000"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-1"      \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-10"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-100"    \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-1000"   \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-1"        \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-10"       \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-100"      \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-40_ctauS-1000"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-1"      \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-10"     \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-100"    \
 "ggZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-1000"   \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-1"        \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-10"       \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-100"      \
 "ZH_HToSSTo4Tau_ZToLL_MH-125_MS-55_ctauS-1000"     \
### Data
## DoubleMu
# "Data_DoubleMu_H_3"      \
# "Data_DoubleMu_H_2"      \
# "Data_DoubleMu_G"        \
## DoubleEG
# "Data_DoubleEG_H_3"      \
# "Data_DoubleEG_H_2"      \
# "Data_DoubleEG_G"        \
## MuonEG
# "Data_MuonEG_H_3"        \
# "Data_MuonEG_H_2"        \
# "Data_MuonEG_G"          \
## SinglePhoton
## "Data_SinglePhoton_H_3"  \
## "Data_SinglePhoton_H_2"  \
## "Data_SinglePhoton_G"    \
#
### MC backgrounds
## DY
## "DYJetsToLL_M-5to50_HT-70to100"   \
# "DYJetsToLL_M-5to50_HT-100to200"  \
# "DYJetsToLL_M-5to50_HT-200to400"  \
# "DYJetsToLL_M-5to50_HT-400to600"  \
# "DYJetsToLL_M-5to50_HT-600toInf"  \
# "DYJetsToLL_M-10to50"             \
# "DYJetsToLL_M-50"                 \
# "mad_DYJetsToLL_M-50"                 \
## WJets
# "WJetsToLNu"     \
## TTbar
# "TTJets"         \
# "TTtoLL"         \
# "TTtoLfromTbar"  \
# "TTtoLfromT"     \
#
## Single Top
# "ST_s-channel_4f_leptonDecays"             \
# "ST_t-channel_antitop_4f_inclusiveDecays"  \
# "ST_t-channel_top_4f_inclusiveDecays"      \
# "ST_tW_antitop_5f_NoFullyHadronicDecays"   \
# "ST_tW_top_5f_NoFullyHadronicDecays"       \
## GJets
# "GJets_HT-40To100"   \
# "GJets_HT-100To200"  \
# "GJets_HT-200To400"  \
# "GJets_HT-400To600"  \
# "GJets_HT-600ToInf"  \
## Diboson
# "WW"               \
# "WZ"               \
# "ZZ"               \
# "WWTo2L2Nu"        \
# "WWToLNuQQ"        \
# "WZTo1L3Nu"        \
# "WZTo3LNu"         \
# "WZToLNu2QorQQ2L"  \
# "ZZTo2L2Nu"        \
# "ZZTo2L2Q"         \
# "ZZTo2Q2Nu"        \
# "ZZTo4L"           \
## VGamma
# "ZGTo2LG"  \
# "WGToLNuG" \
## ZH
# "ggZH_HToBB_ZToLL"  \
# "ZH_HToBB_ZToLL"    \
## WH
## "WminusH_HToBB_WToLNu" \
## "WplusH_HToBB_WToLNu"  \
## QCD 
# "QCD_HT100to200"    \
# "QCD_HT200to300"    \
# "QCD_HT300to500"    \
# "QCD_HT500to700"    \
# "QCD_HT700to1000"   \
# "QCD_HT1000to1500"  \
# "QCD_HT1500to2000"  \
# "QCD_HT2000toInf"   \
## Signal Samples
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"      \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"     \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"    \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"   \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1"        \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-10"       \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-100"      \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-15_ctauS-1000"     \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"      \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"     \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"    \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"   \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1"        \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-10"       \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-100"      \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-40_ctauS-1000"     \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"      \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"     \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"    \
# "ggZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"   \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1"        \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-10"       \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-100"      \
# "ZH_HToSSTobbbb_ZToLL_MH-125_MS-55_ctauS-1000"     \
# "h250_llp50_ct1_100k"     \
# "h250_llp50_ct10_100k"     \
# "h250_llp50_ct100_100k"     \
# "h250_llp50_ct1000_100k"     \
# "h500_llp200_ct1_100k"     \
# "h500_llp200_ct10_100k"     \
# "h500_llp200_ct100_100k"     \
# "h500_llp200_ct1000_100k"     \
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-55_ctauS-1"     \
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-55_ctauS-10"    \
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-55_ctauS-100"   \
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-55_ctauS-1000"  \
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-40_ctauS-1"     \ 
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-40_ctauS-10"    \
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-40_ctauS-100"   \
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-40_ctauS-1000"  \
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-15_ctauS-1"     \
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-15_ctauS-10"    \
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-15_ctauS-100"   \
## "WplusH_HToSSTobbbb_WToLNu_MH-125_MS-15_ctauS-1000"  \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-55_ctauS-1"    \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-55_ctauS-10"   \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-55_ctauS-100"  \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-55_ctauS-1000" \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-40_ctauS-1"    \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-40_ctauS-10"   \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-40_ctauS-100"  \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-40_ctauS-1000" \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-15_ctauS-1"    \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-15_ctauS-10"   \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-15_ctauS-100"  \
## "WminusH_HToSSTobbbb_WToLNu_MH-125_MS-15_ctauS-1000" \
)

totin=0
totleft=0

for sample in ${samples[@]}
do

 left=$(bash "${basedir}/submitters/gitignore/${aversion}/${sample}/checker.sh" | wc -l )
 lc=$( cat "${basedir}/submitters/gitignore/${aversion}/${sample}/checker.sh" | wc -l )

 totin=$(($totin+$lc))
 totleft=$(($totleft+$left))

 printf "%50s %4s %4s \n" ${sample} ${lc}  ${left}
 
done
 printf " --------------------------------------------------\n"
 printf "%50s %4s %4s \n" Total  $totin $totleft
