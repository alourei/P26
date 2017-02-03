//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jan 30 19:04:59 2017 by ROOT version 5.34/36
// from TTree p26tree/DSSD hit variables
// found on file: Isomer_test_all_0.root
//////////////////////////////////////////////////////////

#ifndef e10034Sim_h
#define e10034Sim_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TRandom.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class e10034Sim {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   TFile          *fOut;

   // Declaration of leaf types
   Double_t        p26_energy;
   Double_t        totE;
   Double_t        beam_energy;
   Double_t        pathlength;
   Double_t        totaledep[3][100][100][2];
   Double_t        tedepx[20];
   Double_t        tedepy[20];
   Double_t        totalelectronedep;
   Double_t        totalgammaedep;
   Double_t        time;
   Double_t        segaedep[16];

   //Histograms
   TH1F* fSega;
   TH1F* fGeDSSD_gammas;
   TH1F* fGeDSSD_sumx;
   TH1F** fGeDSSD_x;
   TH1F* fGeDSSD_sumy;
   TH1F* fGeDSSD_electrons;
   TH1F* fGeDSSD_beam;
   TH1F* fTime;

   // List of branches
   TBranch        *b_p26_energy;   //!
   TBranch        *b_totE;   //!
   TBranch        *b_beam_energy;   //!
   TBranch        *b_pathlength;   //!
   TBranch        *b_totaledep;   //!
   TBranch        *b_tedepx;   //!
   TBranch        *b_tedepy;   //!
   TBranch        *b_dEpe;   //!
   TBranch        *b_dEpg;   //!
   TBranch        *b_time;   //!
   TBranch        *b_sega;   //!

   e10034Sim(TTree *tree=0);
   virtual ~e10034Sim();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
           void     DefineHistograms();
           void     FillSega();
           void     FillGeDSSD();
           void     WriteOutput();
};

#endif

#ifdef e10034Sim_cxx
e10034Sim::e10034Sim(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Isomer_test_all_0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Isomer_test_all_0.root");
      }
      f->GetObject("p26tree",tree);

   }
   Init(tree);
}

e10034Sim::~e10034Sim()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
   delete fOut;
}

Int_t e10034Sim::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t e10034Sim::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void e10034Sim::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("p26_energy", &p26_energy, &b_p26_energy);
   fChain->SetBranchAddress("totE", &totE, &b_totE);
   fChain->SetBranchAddress("beam_energy", &beam_energy, &b_beam_energy);
   fChain->SetBranchAddress("pathlength", &pathlength, &b_pathlength);
   fChain->SetBranchAddress("totaledep", totaledep, &b_totaledep);
   fChain->SetBranchAddress("tedepx", tedepx, &b_tedepx);
   fChain->SetBranchAddress("tedepy", tedepy, &b_tedepy);
   fChain->SetBranchAddress("totalelectronedep", &totalelectronedep, &b_dEpe);
   fChain->SetBranchAddress("totalgammaedep", &totalgammaedep, &b_dEpg);
   fChain->SetBranchAddress("time", &time, &b_time);
   fChain->SetBranchAddress("segaedep[16]", segaedep, &b_sega);
   Notify();
}

Bool_t e10034Sim::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void e10034Sim::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t e10034Sim::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void e10034Sim::DefineHistograms(){
  
  Char_t hname[256];
  Char_t htitle[256];
  sprintf(hname,"hSega");
  sprintf(htitle,"Total Energy deposited SeGA");
  Int_t bins=4000;
  Int_t xf=8000;
  fSega=new TH1F(hname,htitle,bins,0,8000);
  
  sprintf(hname,"hGeDSSDg");
  sprintf(htitle,"Total Energy deposited GeDSSD gammas");
  fGeDSSD_gammas=new TH1F(hname,htitle,bins,0,8000);
  
  sprintf(hname,"hGeDSSDe");
  sprintf(htitle,"Total Energy deposited GeDSSD electrons");
  fGeDSSD_electrons=new TH1F(hname,htitle,bins,0,8000);
  
  sprintf(hname,"hGeDSSDb");
  sprintf(htitle,"Total Energy deposited GeDSSD beam");
  fGeDSSD_beam=new TH1F(hname,htitle,bins,0,8000);
 
  sprintf(hname,"hGeDSSDx");
  sprintf(htitle,"Added Energy deposited GeDSSD X Strips [0-8]");
  fGeDSSD_sumx=new TH1F(hname,htitle,bins,0,4000);
 
  sprintf(hname,"hGeDSSDy");
  sprintf(htitle,"Added Energy deposited GeDSSD y");
  fGeDSSD_sumy=new TH1F(hname,htitle,bins,0,8000);

  fGeDSSD_x=new TH1F*[20];

  for(Int_t t=0;t<20;t++){
    sprintf(hname,"hGeDSSDx_%d",t);
    sprintf(htitle,"Added Energy deposited GeDSSD X strip %d",t);
    fGeDSSD_x[t]=new TH1F(hname,htitle,bins,0,8000);
  }
  
  fTime=new TH1F("hTime","Time distribution;time [#mus]",200,0,1);
  
  return;
}


void e10034Sim::FillSega(){

  for(Int_t j=0;j<16;j++){
    if(segaedep[j]>0)
    fSega->Fill(segaedep[j]);
  }

  fTime->Fill(time*1000);

  return;
}


void  e10034Sim::FillGeDSSD(){

  if(1000*time<=2){
  
  for(Int_t i=0;i<3;i++){

    for(Int_t j=0;j<100;j++){

      for(Int_t k=0;k<100;k++){
	for(Int_t l=0;l<2;l++){
	  if(i==0){
	    if(totaledep[i][j][k][l]>0)
	      fGeDSSD_electrons->Fill(gRandom->Gaus(totaledep[i][j][k][l],0.005/2.35*totaledep[i][j][k][l]));
	  }
	  else if(i==1){
	    if(totaledep[i][j][k][l]>0)
	      fGeDSSD_gammas->Fill(gRandom->Gaus(totaledep[i][j][k][l],0.005/2.35*totaledep[i][j][k][l]));
	  }
	  else{
	    if(totaledep[i][j][k][l]>0)
	      fGeDSSD_beam->Fill(gRandom->Gaus(totaledep[i][j][k][l],0.005/2.35*totaledep[i][j][k][l]));
	  }

	}
	
      }
    }
    
  }
  }
  Double_t sumx=0;
  Double_t sumy=0;

  for(Int_t strip=0;strip<20;strip++){

    if(1000*time<=2){
      if(strip>8 && strip<=12)
      sumx+=gRandom->Gaus(tedepx[strip],0.005/2.35*tedepx[strip]);
      if(tedepx[strip]>0)
	fGeDSSD_x[strip]->Fill(gRandom->Gaus(tedepx[strip],0.005/2.35*tedepx[strip]));
    sumy+=gRandom->Gaus(tedepy[strip],0.005/2.35*tedepy[strip]);
    }
  }
    if(sumx>0)
      fGeDSSD_sumx->Fill(sumx);
    if(sumy>0)
    fGeDSSD_sumy->Fill(sumy);
    
  return;
  }

void e10034Sim::WriteOutput(){
  fSega->Write();
  fGeDSSD_electrons->Write();
  fGeDSSD_gammas->Write();
  fGeDSSD_beam->Write();
  fGeDSSD_sumx->Write();
  for(Int_t t=0;t<20;t++)
    fGeDSSD_x[t]->Write();
  fGeDSSD_sumy->Write();
  fTime->Write();

  //fOut->Close();
}
#endif // #ifdef e10034Sim_cxx
