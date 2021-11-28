# run-by-run-qa-algorithm
Developed for the isobar blind analysis

Orignal developed for Isobar-Blind Analysis
Contact: <yuhu@bnl.gov>, <ptribedy@bnl.gov>

############################################
######   Necessary in this package   #######
############################################

runbyrun_advanced.sh	#Mean logic script, full version
runbyrun.sh		#Simple version of run-by-run script
jumpcheck.sh		#Script to check the jump
badrunfinder.sh		#Script to find the badruns in a region
SaveOriMean.sh		#Save the <mean> for the given TProfiles 
Global_bardun_BNL.sh	#Complex script to do the Global badruns remove

readoutdata.C		
readoutmean.C
readoutnrms.C
readoutroot.C
Cleanbadrun_BNL.C	#To clean the badruns from a given root file

------------------------------------------------------------------------------------
#############################################
##########  change before you run  ##########
#############################################

1> Prepare a root file, save the run-by-run quanlities into a TProfile;
   Put the runid as X-axis.

2> Change the <Final_regions_BE.list> with the index of the first-run and the last-run
   in your root file; 
      e.g  19085038 #Firstrun
   	   19129014 #Lastrun
   Or if you put 1 as your first run in your TProfile, and you have 200 runs, then it will be:
   	   1 #Firstrun
	   200 #Lastrun
	   
3> Change <Global_bardun_BNL.sh> L3, "INPUTROOTFILE=QA_BNL.root" into your root file name

4> Change the quanlities you interested inside the <qa_BNL.list> with the name of the TProfiles 

5> The <Cleanbadrun_BNL.C> is just an example file, change the name of the TProfiles into yours

6> You need to have "gnuplot" newer than 5.0 installed to run this package,
   if you want to run on rcf, replace the "gnuplot << EOF" in <jumpcheck.sh> L206
   with "/star/u/jdb/.exodus/bin/gnuplot <<EOF" 


#############################################
#####  How to run the run-by-run Code  ######
#############################################

Use QA_BNL.root file as an example:

1> Run the SaveOriMean.sh to get the global value:
   e.g: bash SaveOriMean.sh QA_BNL.root qa_BNL.list


2> Run the Global_badrun_BNL.sh:
   e.g: bash Global_badrun_BNL.sh


After you removed the global badruns, use the latest root file, QA_BNL_r3.root 


3> Run the SaveOriMean.sh:
   e.g: bash SaveOriMean.sh QA_BNL_r3.root qa_BNL.list


4> Run the <runbyrun_advanced.sh> get the regions and badruns.
   e.g: bash runbyrun_advanced.sh  QA_BNL_r3.root qa_BNL.list


5> Check the <Final_badruns.list>, use the micro <Cleanbadrun_BNL.C> to remove the run listed in this file.
   e.g: root -l "Cleanbadrun_BNL.C("'"'"QA_BNL_r3.root"'"'", "'"'"QA_BNL_r4.root"'"'","'"'"Final_badruns.list"'"'")" -q



6> Save a copy of the badruns you found in this round
   e.g: cp Final_badruns.list Final_badruns_unblind_r1.list


7> Repeat <3> <4> <5> and <6>, until get no badruns in the <Final_badruns.list>.
   (Run the <runbyrun_advanced.sh>, get the regions, badruns; If there is a bad run, remove by using the <Cleanbadrun_BNL.C> code, if no more bad run be founded, then it's the final region)


