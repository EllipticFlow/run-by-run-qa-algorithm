##This code is writing to remove the global badruns 

INPUTROOTFILE=QA_BNL.root

echo "##################################################"
echo "###### REMOVE GLOBAL BADRUNS FOR BNL GROUP ######"
echo "################ Aug 24, 2020 ####################"
echo "########## Yu, Pritwish, Yicheng, Gang ###########"
echo "##################################################"

if [ ! -f qa_BNL.list ]; then
    echo "Error, need the <qa_BNL.list> in the path, will exit."
    exit
fi

if [ ! -f onlybadruns.sh ]; then
    echo "Error, need the <onlybadruns.sh> in the path, will exit."
    exit
fi

if [ ! -f Final_regions_BE.list ]; then
    echo "Error, need the <Final_regions_BE.list> in the path, will exit."
    exit
fi

if [ ! -f Cleanbadrun_BNL.C ]; then
    echo "Error, need the <Cleanbadrun_BNL.C> in the path, will exit."
    exit
fi


if [ -f Final_badruns_sum_global.list ]; then
 rm Final_badruns_sum_global.list
fi

bash onlybadruns.sh ${INPUTROOTFILE} qa_BNL.list Final_regions_BE.list
cat Final_badruns.list | awk '{print($1)}' > Final_badruns_1.list
root -l -b -q Cleanbadrun_BNL.C\(\"${INPUTROOTFILE}\",\"QA_BNL_r2.root\",\"Final_badruns_1.list\"\)

cat Final_badruns_1.list >> Final_badruns_sum_global.list


for i in 2 3 4 5 
do
    j=$((i+1))
    bash onlybadruns.sh QA_BNL_r${i}.root qa_BNL.list Final_regions_BE.list
    NR_Gbad=$(cat Final_badruns.list | wc -l)
    if [ ${NR_Gbad} -eq 0 ]; then
	echo "Gobal Badruns Rejection, done."
	rm badrunlist_*list
	exit
    fi
    if [ -f Final_badruns_${i}.list ]; then
	echo "Notice, you already had the Final_badruns_${i}.list, will over write it"
	rm Final_badruns_${i}.list
    fi
    cat Final_badruns.list | awk '{print($1)}' > Final_badruns_${i}.list

    INPUTFILE=QA_BNL_r${i}.root
    OUTPUTFILE=QA_BNL_r${j}.root
    BADRUNFILE=Final_badruns_${i}.list
    root -l -b -q Cleanbadrun_BNL.C\(\"${INPUTFILE}\",\"${OUTPUTFILE}\",\"${BADRUNFILE}\"\)

    cat ${BADRUNFILE} >> Final_badruns_sum_global.list

done


