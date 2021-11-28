/// This code original copies form Gang and uses Yicheng's CleanBadruns as a ref
/// Modified on Aug24,2020
#include <iostream>
#include <fstream>

void Cleanbadrun_BNL(const char *inputfile, const char *outputfile, const char *badname) {
   
  char * badrunfile0 = new char[400];
  sprintf(badrunfile0,"%s",badname);

  int badRun[500];
  int j=0;  
  ifstream myfile;
  myfile.open (badrunfile0);
  if (myfile.is_open())
    {
      while(!myfile.eof())
	{
	  string number;
	  int data;
	  getline (myfile,number);
	  data = atoi(number.c_str());
	  if (data!=0)
	    {
	      badRun[j]=data;
	      j++;
	    }
	}
      myfile.close();
    }
  
  
  char * infile0 = new char[400];
  sprintf(infile0,"%s",inputfile);
  TFile *f = new TFile(infile0,"READ");

  TProfile *runidvstofmult = (TProfile *)f->Get("runidvstofmult");
  TProfile *runidvsavgpt = (TProfile *)f->Get("runidvsavgpt");
  TProfile *runidvsrefmult = (TProfile *)f->Get("runidvsrefmult");
  TProfile *runidvszdcand = (TProfile *)f->Get("runidvszdcand");
  TProfile *runidvsavgeta = (TProfile *)f->Get("runidvsavgeta");
  TProfile *runidvsavgdca = (TProfile *)f->Get("runidvsavgdca");
  TProfile *runidvsavgvz = (TProfile *)f->Get("runidvsavgvz");
  TProfile *runidvsavgphi = (TProfile *)f->Get("runidvsavgphi");
  TProfile *runidvsavgQ1x = (TProfile *)f->Get("runidvsavgQ1x");
  TProfile *runidvsavgQ1y = (TProfile *)f->Get("runidvsavgQ1y");
  TProfile *runidvsavgQ1xp = (TProfile *)f->Get("runidvsavgQ1xp");
  TProfile *runidvsavgQ1yp = (TProfile *)f->Get("runidvsavgQ1yp");
  TProfile *runidvsavgQ1xn = (TProfile *)f->Get("runidvsavgQ1xn");
  TProfile *runidvsavgQ1yn = (TProfile *)f->Get("runidvsavgQ1yn");
  TProfile *runidvsavgQ2x = (TProfile *)f->Get("runidvsavgQ2x");
  TProfile *runidvsavgQ2y = (TProfile *)f->Get("runidvsavgQ2y");
  TProfile *runidvsavgEpdQ1x = (TProfile *)f->Get("runidvsavgEpdQ1x");
  TProfile *runidvsavgEpdQ1y = (TProfile *)f->Get("runidvsavgEpdQ1y");
  TProfile *runidvsavgEpdQ2x = (TProfile *)f->Get("runidvsavgEpdQ2x");
  TProfile *runidvsavgEpdQ2y = (TProfile *)f->Get("runidvsavgEpdQ2y");
  TProfile *runidvsv1epd = (TProfile *)f->Get("runidvsv1epd");
  TProfile *runidvsv2epd = (TProfile *)f->Get("runidvsv2epd");
  TProfile *runidvsv3epd = (TProfile *)f->Get("runidvsv3epd");
  TProfile *runidvsv12tpc = (TProfile *)f->Get("runidvsv12tpc");
  TProfile *runidvsv22tpc = (TProfile *)f->Get("runidvsv22tpc");
  TProfile *runidvsv32tpc = (TProfile *)f->Get("runidvsv32tpc");
  TProfile *runidvsepdEhits = (TProfile *)f->Get("runidvsepdEhits");
  TProfile *runidvsepdWhits = (TProfile *)f->Get("runidvsepdWhits");
  TProfile *runidvstofmatched = (TProfile *)f->Get("runidvstofmatched");
  TProfile *runidvsbemcmatched = (TProfile *)f->Get("runidvsbemcmatched");

  for(int i=0;i<j;i++) {
  int Day3    = (int)(badRun[i]);
  int n = runidvstofmult->FindBin(Day3);
  runidvstofmult->SetBinContent(n,0);
  runidvsavgpt->SetBinContent(n,0);
  runidvsrefmult->SetBinContent(n,0);
  runidvszdcand->SetBinContent(n,0);
  runidvsavgeta->SetBinContent(n,0); 
  runidvsavgdca->SetBinContent(n,0); 
  runidvsavgvz->SetBinContent(n,0);
  runidvsavgphi->SetBinContent(n,0); 
  runidvsavgQ1x->SetBinContent(n,0); 
  runidvsavgQ1y->SetBinContent(n,0); 
  runidvsavgQ1xp->SetBinContent(n,0);
  runidvsavgQ1yp->SetBinContent(n,0);
  runidvsavgQ1xn->SetBinContent(n,0);
  runidvsavgQ1yn->SetBinContent(n,0);
  runidvsavgQ2x->SetBinContent(n,0);
  runidvsavgQ2y->SetBinContent(n,0); 
  runidvsavgEpdQ1x->SetBinContent(n,0);
  runidvsavgEpdQ1y->SetBinContent(n,0);
  runidvsavgEpdQ2x->SetBinContent(n,0);
  runidvsavgEpdQ2y->SetBinContent(n,0);
  runidvsv1epd->SetBinContent(n,0);
  runidvsv2epd->SetBinContent(n,0);
  runidvsv3epd->SetBinContent(n,0);
  runidvsv12tpc->SetBinContent(n,0); 
  runidvsv22tpc->SetBinContent(n,0); 
  runidvsv32tpc->SetBinContent(n,0); 
  runidvsepdEhits->SetBinContent(n,0); 
  runidvsepdWhits->SetBinContent(n,0); 
  runidvstofmatched->SetBinContent(n,0);
  runidvsbemcmatched->SetBinContent(n,0);

    runidvstofmult->SetBinEntries(n,0);
  runidvsavgpt->SetBinEntries(n,0);
  runidvsrefmult->SetBinEntries(n,0);
  runidvszdcand->SetBinEntries(n,0);
  runidvsavgeta->SetBinEntries(n,0); 
  runidvsavgdca->SetBinEntries(n,0); 
  runidvsavgvz->SetBinEntries(n,0);
  runidvsavgphi->SetBinEntries(n,0); 
  runidvsavgQ1x->SetBinEntries(n,0); 
  runidvsavgQ1y->SetBinEntries(n,0); 
  runidvsavgQ1xp->SetBinEntries(n,0);
  runidvsavgQ1yp->SetBinEntries(n,0);
  runidvsavgQ1xn->SetBinEntries(n,0);
  runidvsavgQ1yn->SetBinEntries(n,0);
  runidvsavgQ2x->SetBinEntries(n,0);
  runidvsavgQ2y->SetBinEntries(n,0); 
  runidvsavgEpdQ1x->SetBinEntries(n,0);
  runidvsavgEpdQ1y->SetBinEntries(n,0);
  runidvsavgEpdQ2x->SetBinEntries(n,0);
  runidvsavgEpdQ2y->SetBinEntries(n,0);
  runidvsv1epd->SetBinEntries(n,0);
  runidvsv2epd->SetBinEntries(n,0);
  runidvsv3epd->SetBinEntries(n,0);
  runidvsv12tpc->SetBinEntries(n,0); 
  runidvsv22tpc->SetBinEntries(n,0); 
  runidvsv32tpc->SetBinEntries(n,0); 
  runidvsepdEhits->SetBinEntries(n,0); 
  runidvsepdWhits->SetBinEntries(n,0); 
  runidvstofmatched->SetBinEntries(n,0);
  runidvsbemcmatched->SetBinEntries(n,0);

    runidvstofmult->SetBinError(n,0);
  runidvsavgpt->SetBinError(n,0);
  runidvsrefmult->SetBinError(n,0);
  runidvszdcand->SetBinError(n,0);
  runidvsavgeta->SetBinError(n,0); 
  runidvsavgdca->SetBinError(n,0); 
  runidvsavgvz->SetBinError(n,0);
  runidvsavgphi->SetBinError(n,0); 
  runidvsavgQ1x->SetBinError(n,0); 
  runidvsavgQ1y->SetBinError(n,0); 
  runidvsavgQ1xp->SetBinError(n,0);
  runidvsavgQ1yp->SetBinError(n,0);
  runidvsavgQ1xn->SetBinError(n,0);
  runidvsavgQ1yn->SetBinError(n,0);
  runidvsavgQ2x->SetBinError(n,0);
  runidvsavgQ2y->SetBinError(n,0); 
  runidvsavgEpdQ1x->SetBinError(n,0);
  runidvsavgEpdQ1y->SetBinError(n,0);
  runidvsavgEpdQ2x->SetBinError(n,0);
  runidvsavgEpdQ2y->SetBinError(n,0);
  runidvsv1epd->SetBinError(n,0);
  runidvsv2epd->SetBinError(n,0);
  runidvsv3epd->SetBinError(n,0);
  runidvsv12tpc->SetBinError(n,0); 
  runidvsv22tpc->SetBinError(n,0); 
  runidvsv32tpc->SetBinError(n,0); 
  runidvsepdEhits->SetBinError(n,0); 
  runidvsepdWhits->SetBinError(n,0); 
  runidvstofmatched->SetBinError(n,0);
  runidvsbemcmatched->SetBinError(n,0);
  }

  char * outfile0 = new char[400];
  sprintf(outfile0,"%s",outputfile);
  TFile *ff = new TFile(outfile0,"RECREATE");
  runidvstofmult->Write();
  runidvsavgpt->Write();
  runidvsrefmult->Write();
  runidvszdcand->Write();
  runidvsavgeta->Write(); 
  runidvsavgdca->Write(); 
  runidvsavgvz->Write();
  runidvsavgphi->Write(); 
  runidvsavgQ1x->Write(); 
  runidvsavgQ1y->Write(); 
  runidvsavgQ1xp->Write();
  runidvsavgQ1yp->Write();
  runidvsavgQ1xn->Write();
  runidvsavgQ1yn->Write();
  runidvsavgQ2x->Write();
  runidvsavgQ2y->Write(); 
  runidvsavgEpdQ1x->Write();
  runidvsavgEpdQ1y->Write();
  runidvsavgEpdQ2x->Write();
  runidvsavgEpdQ2y->Write();
  runidvsv1epd->Write();
  runidvsv2epd->Write();
  runidvsv3epd->Write();
  runidvsv12tpc->Write(); 
  runidvsv22tpc->Write(); 
  runidvsv32tpc->Write(); 
  runidvsepdEhits->Write(); 
  runidvsepdWhits->Write(); 
  runidvstofmatched->Write();
  runidvsbemcmatched->Write();
  
  ff->Close();

}
