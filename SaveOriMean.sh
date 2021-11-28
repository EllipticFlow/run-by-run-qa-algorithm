#!/bin/bash

ROOTFILE=$1
NAMELIST=$2

if [ -z $1 ]; then
    echo "Need root file, try: bash SaveOriMean.sh qa.root qa.list"
    exit
fi

if [ -z $2 ]; then
    echo "Need qa list, try: bash SaveOriMean.sh qa.root qa.list"
    exit
fi


if [ -f Original_Global_Value_tmp.txt ]; then
    rm Original_Global_Value_tmp.txt
fi

if [ -f Original_Global_Value.txt ]; then
    rm Original_Global_Value.txt
fi

NR_HISTNAME=$(cat ${NAMELIST} | wc -l)
NR_qalist=1

until [ ${NR_qalist} -gt ${NR_HISTNAME} ]
do
    HISTNAME=$(awk 'NR=='${NR_qalist}' {print($2)}' ${NAMELIST})
    root -l "readoutmean.C("'"'"${ROOTFILE}"'"'","'"'"${HISTNAME}"'"'")" -q | awk '{if ($1 == ($1+0)) print($0)}' >> Original_Global_Value_tmp.txt
    let NR_qalist=NR_qalist+1
done

#### For the Original_Global_Value.txt
#### <histname> <runs> <entries> <mean> <RMS> <error>
paste ${NAMELIST} Original_Global_Value_tmp.txt | awk '{print ($2, $3, $4, $5, $6, $7)}' > Original_Global_Value.txt
rm Original_Global_Value_tmp.txt
