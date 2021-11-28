#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#include "TProfile.h"
#include "TProfile2D.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TFitResultPtr.h"

using namespace std;


void readoutmean(char const * inputfile, char const * histname){

  char * infile0 = new char[400];
  sprintf(infile0,"%s",inputfile);
  TFile *f = new TFile(infile0);
  sprintf(infile0,"%s",histname);

  TProfile *myHist = (TProfile *)f->Get(infile0);
  //  fprintf(stdout,"## %s %s \n",myHist->GetXaxis()->GetTitle(),myHist->GetYaxis()->GetTitle());

  int goodrunno=1;
  int goodrunno2=1;

  for(int i=1;i<=myHist->GetNbinsX();i++){if(myHist->GetBinContent(i)!=0)goodrunno++;}

  fprintf(stdout,"%d %g %g %g %g \n",goodrunno,myHist->GetEntries(),myHist->GetMean(2),myHist->GetRMS(2),myHist->GetMeanError(2)*sqrt(goodrunno));
  

  f->Close();  


}  






