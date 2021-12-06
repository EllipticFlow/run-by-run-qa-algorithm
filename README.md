# run-by-run-qa-algorithm version-1.1
Developed for the isobar blind analysis

Orignal developed for Isobar-Blind Analysis
Contact: <yuhu@bnl.gov>, <ptribedy@bnl.gov>

############################################
##############   Update log   ##############
############################################
### 2021-12-05
### 1) The updates on 2021-12-03 may lead to some errors when it works on too many negetive values for some quality
###    Fixed with an another shell function. Now it will check:
###    u2>u1+nsigma*(e1^2+e2^2)^0.5 || u2<u1-nsigma*(e1^2+e2^2)^0.5 
############################################
### 2021-12-03
### 1) Updated the <badrunfinder.sh> for badrun identification. It should take the statistical error into account,
###    If one given period has mean(u1) and error(e1); and one given run has mean value(u2) with error(e2)
###    The way to check bad run should be (u1-u2)^2 > nsigma^2*(e1^2+e2^2)
############################################
### 2021-12-01
### 1) Edited the <Global_bardun_BNL.sh>, <badrunfinder.sh>, and <runbyrun_advanced.sh> to save the repeated badruns. The information will be saved in a new file <badruns_allcache.txt>.  
### 2) See the <checkrepeated.sh> about how to find repeated badruns from <badruns_allcache.txt> 


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


2> Run the Global_badrun_BNL.sh, don't forget to change the L3 into your root file name:
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


