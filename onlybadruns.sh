#!/bin/bash

ROOTFILE=$1
NAMELIST=$2
RUNREGION=$3

if [ -z $1 ]; then
    echo "Need root file, try: bash onlybadruns.sh qa.root qa.list run_regions"
    exit
fi

if [ -z $2 ]; then
    echo "Need qa list, try: bash onlybadruns.sh qa.root qa.list run_regions"
    exit
fi

if [ -z $3 ]; then
    echo "Need run regions, try: bash onlybadruns.sh qa.root qa.list run_regions"
    exit
fi

if [ -f onlybadruns ]; then
    rm onlybadruns
fi

if [ -f Final_badruns.list ]; then
    rm Final_badruns.list
fi

NR_HISTNAME=$(cat ${NAMELIST} | wc -l)
NR_qalist=1

until [ ${NR_qalist} -gt ${NR_HISTNAME} ]
do
    HISTNAME=$(awk 'NR=='${NR_qalist}' {print($2)}' ${NAMELIST})
    bash badrunfinder.sh ${ROOTFILE} ${HISTNAME} ${RUNREGION} 1 >> onlybadruns
    let NR_qalist=NR_qalist+1
done


cat onlybadruns | awk '{if($1+0==$1){print($0)}}' | sort -n -u -k1,1 > Final_badruns.list

rm onlybadruns
