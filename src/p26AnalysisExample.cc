//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#include "p26DetectorConstruction.hh"
#include "p26AnalysisExample.hh"
#include "p26AnalysisExampleMessenger.hh"

#include "p26DetectorHit.hh"
//#include "p26scintHit.hh"
//#include "p26PMTHit.hh"

#include "G4ios.hh"

#include "G4RunManager.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Event.hh"
#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Run.hh"
#include "G4Track.hh"
#include "G4ClassificationOfNewTrack.hh"
#include "G4TrackStatus.hh"
#include "G4Step.hh"
#include "G4Types.hh"
#include "G4SDManager.hh"

#include <sstream>
#include <iostream>
#include <time.h>
#include <cstring>
#include <cstdlib>
#include <string.h>

static const G4double LambdaE = 2.0 * 3.14159265358979323846 * 1.973269602e-16 * m * GeV;

#if defined (G4ANALYSIS_USE_ROOT)

#include "TROOT.h"
#include "TApplication.h"
#include "TSystem.h"
#include "TH1.h"
#include "TH2.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TStopwatch.h"
#include "TTree.h"
#include "TRandom.h"

#endif /* defined (G4ANALYSIS_USE_ROOT) */


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

p26AnalysisExample::p26AnalysisExample()
{
	analysisexample = new p26AnalysisExampleMessenger(this);
	
	filecount = 0;  
	
	LastDoItTime = (time_t)0;
	
		#if defined (G4ANALYSIS_USE_ROOT)
	
	if (gSystem) gSystem->ProcessEvents();
	
	p26tree = (TTree *)0; // p26 out tree
	
	hEnergyDeposit = (TH1D*)0;
	
	hEnergyDepositThinDe = (TH1D*)0;	 // CL
	hEnergyDepositThinDeBeta = (TH1D*)0; // MBB
	
	hEDepLaBr = (TH1D*)0;			 // MBB
	hEDepLaBrBeta = (TH1D*)0; //MBB
	hEDepNaI = (TH1D*)0;		//MBB
	hEDepNaIBeta = (TH1D*)0;		 // MBB
	
	////////////////////




	hBeam_energy = (TH1D *)0; // beam energy
	hPrimaryPosXY  = (TH2D *)0; // primary position  
	
	//hGammaSingle = (TH1D*)0;
	//hGammaSingleAdd = (TH1D*)0;
	//for(int i=0; i<68;i++){
	//    hCrystalEdep[i] = (TH1D*)0;
	//}
	
	//hScintEdep_xy = (TH2D*)0; 
	//hScintEdep_yz = (TH2D*)0; 
	
	
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
  
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

p26AnalysisExample::~p26AnalysisExample()
{
	//OnceAWhileDoIt();
	
	delete analysisexample;
	
	#if defined (G4ANALYSIS_USE_ROOT)
	
	if (gSystem) gSystem->ProcessEvents();
	
	
	
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::Construct(const G4VPhysicalVolume */*theWorldWolume*/)
{
	#if defined (G4ANALYSIS_USE_ROOT)
	if (gSystem) gSystem->ProcessEvents();
	
	
	
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
	
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::ConstructParticle()
{
	#if defined (G4ANALYSIS_USE_ROOT)
	
	if (gSystem) gSystem->ProcessEvents();
	
	
	
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
	
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::ConstructProcess()
{
	#if defined (G4ANALYSIS_USE_ROOT)
	
	if (gSystem) gSystem->ProcessEvents();
	
	
	
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
	
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::SetCuts()
{
	#if defined (G4ANALYSIS_USE_ROOT)
	
	if (gSystem) gSystem->ProcessEvents();
	
	
	
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
	
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::GeneratePrimaries(const G4Event *anEvent,G4double beam)
{
	#if defined (G4ANALYSIS_USE_ROOT)
	if (gSystem) gSystem->ProcessEvents();
	
	//G4cout << "beam energy is " << beam << G4endl;
		
	beam_energy = 0;
	beam_energy = beam;
	//cout << "beam energy is now " << beam << endl;
	
	if (hBeam_energy) hBeam_energy->Fill(beam_energy / keV, 1.); // Step Length
	
	
	G4ThreeVector startpos = anEvent->GetPrimaryVertex()->GetPosition();
	
	//G4cout << "prim pos " << startpos.x()/micrometer << " " <<startpos.y()/micrometer << " " << startpos.z()/micrometer << G4endl;
	
	// I changed the units of the histogram axes by a factor of ten so as to have a meaningful distribution.
	
	
	hPrimaryPosXY->Fill(startpos.x()/mm,startpos.y()/mm);
	hPrimaryPosYZ->Fill(startpos.y()/mm,startpos.z()/mm);
	hPrimaryPosXZ->Fill(startpos.x()/mm,startpos.z()/mm);
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
	
	OnceAWhileDoIt();
	//cout << "end of the Generate Primary loop... " << endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::ResetStartLocation(G4double &newx, G4double &newy)
{
	// #if defined (G4ANALYSIS_USE_ROOT)
	//   if (gSystem) gSystem->ProcessEvents();
	
	//   hPrimaryPosin->GetRandom2(newx,newy);
	//   G4cout << " random start value " << newx << " " << newy << G4endl;
	
	//   //hPrimaryPos->Fill(startpos.x()/micrometer,startpos.y()/micrometer);
	// #endif /* defined (G4ANALYSIS_USE_ROOT) */
	
	//   OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::DetectorInfo(p26DetectorConstruction* myDet)
{
	
	cout << "go the detector and the Ge detectors are " << myDet->GetUseGeThickDetector() << " and "
	<< myDet->GetUseGeThinDetector() << G4endl;
	
	
	UseGeThickDetector = Int_t(myDet->GetUseGeThickDetector());
	UseGeThinDetector = Int_t(myDet->GetUseGeThinDetector());
	UseLaBrDetector = Int_t(myDet->GetUseLaBrDetector()); //MBB
	UseNaICylinder = Int_t(myDet->GetUseNaICylinder()); //MBB
	UseNaICube = Int_t(myDet->GetUseNaICube()); //MBB
	
	GeThickDetectorThickness = myDet->GetGeThickDetectorThickness();
	GeThinDetectorThickness = myDet->GetGeThinDetectorThickness();
	LaBrDetectorThickness = myDet->GetLaBrDetectorThickness(); //MBB
	NaICylinderThickness = myDet->GetNaICylinderThickness(); //MBB
	NaICubeThickness = myDet->GetNaICubeThickness(); //MBB
	
	GeThickDetectorRadius = myDet->GetGeThickDetectorRadius();
	GeThinDetectorRadius = myDet->GetGeThinDetectorRadius();
	LaBrDetectorRadius = myDet->GetLaBrDetectorRadius(); //MBB
	NaICylinderRadius = myDet->GetNaICylinderRadius(); //MBB
	NaICubeDepth = myDet->GetNaICubeDepth(); //MBB
	
	GeThickx = myDet->GetGeThickDetectorPos().x();
	GeThicky = myDet->GetGeThickDetectorPos().y();
	GeThickz = myDet->GetGeThickDetectorPos().z();
	GeThinx = myDet->GetGeThinDetectorPos().x();
	GeThiny = myDet->GetGeThinDetectorPos().y();
	GeThinz = myDet->GetGeThinDetectorPos().z();
	
	
	LaBrx = myDet->GetLaBrDetectorPos().x();
	LaBry = myDet->GetLaBrDetectorPos().y();
	LaBrz = myDet->GetLaBrDetectorPos().z();
	
	NaICylx = myDet->GetNaICylinderPos().x(); //MBB
	NaICyly = myDet->GetNaICylinderPos().y(); //MBB
	NaICylz = myDet->GetNaICylinderPos().z(); //MBB
	
	NaICubex = myDet->GetNaICubePos().x(); //MBB
	NaICubey = myDet->GetNaICubePos().y(); //MBB
	NaICubez = myDet->GetNaICubePos().z(); //MBB
	
	
	
	GeSpacing = myDet->GetGeSpacing();
	
	p26info = (TTree *)gROOT->FindObject("p26info");
	if(p26info);
	else
	{
		
		p26info = new TTree("p26info","p26info variables");
		p26info->Branch("UseGeThickDetector",&UseGeThickDetector,"UseGeThickDetector/I");
		p26info->Branch("UseGeThinDetector",&UseGeThinDetector,"UseGeThinDetector/I");
		
		p26info->Branch("UseLaBrDetector",&UseLaBrDetector,"UseLaBrDetector/I"); //MBB
		p26info->Branch("UseNaICylinder",&UseNaICylinder,"UseNaICylinder/I"); //MBB
		p26info->Branch("UseNaICube",&UseNaICube,"UseNaICube/I"); //MBB
		
		
		p26info->Branch("GeThickDetectorThickness",&GeThickDetectorThickness,"GeThickDetectorThickness/D");
		p26info->Branch("GeThinDetectorThickness",&GeThinDetectorThickness,"GeThinDetectorThickness/D");
		
		p26info->Branch("LaBrDetectorThickness",&LaBrDetectorThickness,"LaBrDetectorThickness/D");
		p26info->Branch("NaICylinderThickness",&NaICylinderThickness,"NaICylinderThickness/D"); //MBB
		p26info->Branch("NaICubeThickness",&NaICubeThickness,"NaICubeThickness/D"); //MBB
		
		
		p26info->Branch("GeThickDetectorRadius",&GeThickDetectorRadius,"GeThickDetectorRadius/D");
		p26info->Branch("GeThinDetectorRadius",&GeThinDetectorRadius,"GeThinDetectorRadius/D");
		
		p26info->Branch("LaBrDetectorRadius",&LaBrDetectorRadius,"LaBrDetectorRadius/D");
		p26info->Branch("NaICylinderRadius",&NaICylinderRadius,"NaICylinderRadius/D");
		p26info->Branch("NaICubeDepth",&NaICubeDepth,"NaICubeDepth/D");
		
		
		p26info->Branch("GeThickx",&GeThickx,"GeThickx/D");
		p26info->Branch("GeThicky",&GeThicky,"GeThicky/D");
		p26info->Branch("GeThickz",&GeThickz,"GeThickz/D");
		p26info->Branch("GeThinx",&GeThinx,"GeThinx/D");
		p26info->Branch("GeThiny",&GeThiny,"GeThiny/D");
		p26info->Branch("GeThinz",&GeThinz,"GeThinz/D");
		
		p26info->Branch("LaBrx",&LaBrx,"LaBrx/D"); //MBB
		p26info->Branch("LaBry",&LaBry,"LaBry/D"); //MBB
		p26info->Branch("LaBrz",&LaBrz,"LaBrz/D"); //MBB
		p26info->Branch("NaICylx",&NaICylx,"NaICylx/D"); //MBB
		p26info->Branch("NaICyly",&NaICyly,"NaICyly/D"); //MBB
		p26info->Branch("NaICylz",&NaICylz,"NaICylz/D"); //MBB
		p26info->Branch("NaICubex",&NaICubex,"NaICubex/D"); //MBB
		p26info->Branch("NaICubey",&NaICubey,"NaICubey/D"); //MBB
		p26info->Branch("NaICubez",&NaICubez,"NaICubez/D"); //MBB
		
		
		p26info->Branch("GeSpacing",&GeSpacing,"GeSpacing/D");
	
	}
	p26info->Fill();
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::BeginOfRunAction(const G4Run */*aRun*/, G4int rank)
{
	
	eventcounter = 0;
	stripwidthx = 5; //units of mm //3 mm for 60 mm diameter
	stripwidthy = 5; //untis of mm //3 mm for 60 mm diameter
	stripwidthz = (GeThickDetectorThickness/mm)/2.;
	decaycount = 0;
	
	goode = 0;
	goodestrip = 0;
	
	#if defined (G4ANALYSIS_USE_ROOT)
	
	stringstream fil;
	fil << dirname << filename << "_" << rank << ".root";
	G4String filenam = fil.str();
	file1 = new TFile(filenam.c_str(),"RECREATE");
	
	filecount++;
	G4cout << "starting run " << filenam << " " << filecount << G4endl;
	
	//scint_zpixel = 25.; //length of a pixel in the z direction in mm.  Currently a 25 mm pixel length
	
	if (gSystem) gSystem->ProcessEvents();
	
	
	timer = new TStopwatch();
	
	
	//  G4cout << "starting run 2" << G4endl;
	
	p26tree = (TTree *)gROOT->FindObject("p26tree");
	if(p26tree);
	else
	{
		p26tree = new TTree("p26tree","DSSD hit variables");
		p26tree->Branch("p26_energy",&p26_energy,"p26_energy/D");
		p26tree->Branch("totE",&totE,"totE/D");
		p26tree->Branch("beam_energy",&beam_energy,"beam_energy/D");
		p26tree->Branch("pathlength",&pathlength,"pathlength/D");
		p26tree->Branch("totaledep",&totaledep,"totaledep[3][100][100][2]/D");
		p26tree->Branch("tedepx",&tedepx,"tedepx[20]/D");
		p26tree->Branch("timex[20]",&timex,"timex[20]/D");
		p26tree->Branch("tedepy",&tedepy,"tedepy[20]/D");
		p26tree->Branch("totalelectronedep",&totalelectronedep,"dEpe/D");
		p26tree->Branch("totalgammaedep",&totalgammaedep,"dEpg/D");
		p26tree->Branch("time",&gtime,"time/D");
		p26tree->Branch("segaedep[16]",&segaedep,"sega[16]/D");
		p26tree->Branch("segatime[16]",&segatime,"segatime[16]/D");
		p26tree->Branch("venergyGe",&energyGe);
		p26tree->Branch("vtimeGe",&timeGe);
		p26tree->Branch("vstripX",&stripX);
		p26tree->Branch("vXpos",&Xpos);
		p26tree->Branch("vstripY",&stripY);
		p26tree->Branch("vYpos",&Ypos);
		p26tree->Branch("vparentname",&vparentname);
		p26tree->Branch("vpname",&vpname);

	}
	
	
	if(hEnergyDeposit) hEnergyDeposit->Reset();
	else 
	{
		hEnergyDeposit = new TH1D("hEnergyDeposit","hEnergyDeposit",15000,0,15000); //5000,0,15000
	}
	/////// CL
	if(hEnergyDepositThinDe) hEnergyDepositThinDe->Reset();
	else 
	{
		hEnergyDepositThinDe = new
		TH1D("hEnergyDepositThinDe","hEnergyDepositThinDe",15000,0,15000); //5000,0,15000
	}
	/////// CL
	
	
	///////////////////// MBB //////

	if(hEDepLaBr) hEDepLaBr->Reset();
	else 
	{
		hEDepLaBr = new
		TH1D("hEDepLaBr","hEDepLaBr",15000,0,15000); //5000,0,15000
	}
	
	if(hEDepLaBrBeta) hEDepLaBrBeta->Reset();
	else
	{
		hEDepLaBrBeta = new TH1D("hEDepLaBrBeta","hEDepLaBrBeta",15000,0,15000);
	}
	
	
	if(hEnergyDepositThinDeBeta) hEnergyDepositThinDeBeta->Reset();
	else
	{
		hEnergyDepositThinDeBeta = new TH1D("hEnergyDepositThinDeBeta","hEnergyDepositThinDeBeta",15000,0,15000);
	}
		
	if(hEDepNaI) hEDepNaI->Reset();
	else
	{
		hEDepNaI = new TH1D("hEDepNaI","hEDepNaI",100000,0,100000);
	}
	if(hEDepNaIBeta) hEDepNaIBeta->Reset();
	else
	{
		hEDepNaIBeta = new TH1D("hEDepNaIBeta","hEDepNaIBeta",100000,0,100000);
	}
		
	
////////////////////////////////


	// beam energy 
	hBeam_energy = (TH1D *)gROOT->FindObject("hBeam_energy");
	if (hBeam_energy) hBeam_energy->Reset();
	else
	{
		hBeam_energy = new TH1D("hBeam_energy","Beam energy", 100000, 0.0, 100000.0); // in keV
		if (hBeam_energy) hBeam_energy->SetXTitle("[keV]");
	}
	
	// beam X-Y position (i.e. looking down the beamline)
	hPrimaryPosXY = (TH2D *)gROOT->FindObject("hPrimaryPosXY");
	if (hPrimaryPosXY) hPrimaryPosXY->Reset();
	else
	{
		hPrimaryPosXY = new TH2D("hPrimaryPosXY","hPrimaryPosXY",400,-200,200,400,-200,200);
	}
	
	// Y-Z position (looking at the beam from the side)
	hPrimaryPosYZ = (TH2D *)gROOT->FindObject("hPrimaryPosYZ");
	if (hPrimaryPosYZ) hPrimaryPosYZ->Reset();
	else
	{
		hPrimaryPosYZ = new TH2D("hPrimaryPosYZ","hPrimaryPosYZ",400,-200,200,100,-500,500);
	}
	
	// X-Z position (looking down on the beam from the top)
	hPrimaryPosXZ = (TH2D *)gROOT->FindObject("hPrimaryPosXZ");
	if (hPrimaryPosXZ) hPrimaryPosXZ->Reset();
	else
	{
		hPrimaryPosXZ = new TH2D("hPrimaryPosXZ","hPrimaryPosXZ",400,-2000,2000,100,-500,500);
	}
	
	// A spectrum for gamma-gamma coincidences
	hGammaGamma = (TH2D *)gROOT->FindObject("hGammaGamma");
	if (hGammaGamma) hGammaGamma->Reset();
	else
	{
		hGammaGamma = new TH2D("hGammaGamma","hGammaGamma",2000,0,2000,2000,0,2000);
	}
	
	      
	
	// A spectrum for the energy deposited in each SeGA detector.
	for(G4int x=0;x<16;x++)
	{
		stringstream temptitle;
		temptitle << "hEnergyDepositSega_" << x;
		string title = temptitle.str();
		if(hEnergyDepositSega[x]) hEnergyDepositSega[x]->Reset();
		else 
		{
			hEnergyDepositSega[x] = new TH1D(title.c_str(),title.c_str(),5500,0,5500);
		}
	}
	
	
	// A combined spectrum for all sixteen SeGA detectors
	hSega = (TH1D *)gROOT->FindObject("hSega");
	if (hSega) hSega->Reset();
	else
	{
	  //hSega = new TH1D("hSega","hSega", 8000, 0.0, 8000); // in degrees
		hSega = new TH1D("hSega","hSega", 10000, 0.0, 10000); // in degrees
	}
	
	// sega addback
	hSegaab = (TH1D *)gROOT->FindObject("hSegaab");
	if (hSegaab) hSegaab->Reset();
	else
	{
		hSegaab = new TH1D("hSegaab","hSegaab", 5500, 0.0, 5500); // in degrees
	}
	
	//A spectrum for each of the individual Ge crystals inside the nine clover detectors.
	for(G4int x=0;x<36;x++)
	{
		stringstream temptitle;
		temptitle << "hEnergyDepositClover_" << x;
		string title = temptitle.str();
		if(hEnergyDepositClover[x]) hEnergyDepositClover[x]->Reset();
		else
		{
			hEnergyDepositClover[x] = new TH1D(title.c_str(),title.c_str(),12000,0,12000);
		}
	}
	
	// A combined spectrum for all of the clover detectors
	hClover = (TH1D *)gROOT->FindObject("hClover");
	if (hClover) hClover->Reset();
	else
	{
		hClover = new TH1D("hClover","hClover",12000, 0.0,12000); // in degrees
	}
	
	// clover addback
	for(G4int x=0;x<9;x++)
	{
		stringstream temptitle;
		temptitle << "hEnergyDepositClover_addback_" << x;
		string title = temptitle.str();
		if(hEnergyDepositClover_addback[x]) hEnergyDepositClover_addback[x]->Reset();
		else 
		{
		hEnergyDepositClover_addback[x] = new TH1D(title.c_str(),title.c_str(),12000,0,12000);
		}
	}
	
	// more clover addback
	hClover_addback = (TH1D *)gROOT->FindObject("hClover_addback");
	if (hClover_addback) hClover_addback->Reset();
	else
	{
		hClover_addback = new TH1D("hClover_addback","hClover_addback", 5500, 0.0, 5500); // in degrees
	}
	
	// not sure what this is but I didn't want to just discard it -MBB
	hClover_arrayadd = (TH1D *)gROOT->FindObject("hClover_arrayadd");
	if (hClover_arrayadd) hClover_arrayadd->Reset();
	else
	{
		hClover_arrayadd = new TH1D("hClover_arrayadd","hClover_arrayadd", 5500, 0.0, 5500); // in degrees
	}
	
	
	eventtimer = new TStopwatch();
	
	OnceAWhileDoIt(true); // do it now
	
#endif /* defined (G4ANALYSIS_USE_ROOT) */

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::EndOfRunAction(const G4Run */*aRun*/, G4int rank)
{
	#if defined (G4ANALYSIS_USE_ROOT)
	if (gSystem) gSystem->ProcessEvents();
	
	stringstream fil;
	fil << dirname << filename << "_" << rank << ".root";
	G4String filenam = fil.str();
	file1=gROOT->GetFile(filenam.c_str());
	//file1=(TFile*)gROOT->FindObject(filenam.c_str());
	//file1 = new TFile(filenam.c_str(),"RECREATE");
	//p26info->SetDirectory(file1);
	file1->cd();
	p26info->Write();
	
	//p26tree->SetDirectory(file1);
	p26tree->Write();
	
	hEnergyDeposit->Write();
	hEnergyDepositThinDe->Write();
	
	hEnergyDepositThinDeBeta->Write(); //MBB
	
	hEDepLaBr->Write(); //MBB
	hEDepLaBrBeta->Write(); //MBB
	hEDepNaI->Write(); //MBB
	hEDepNaIBeta->Write(); //MBB
	
	hBeam_energy->Write();
	hPrimaryPosXY->Write();
	hPrimaryPosYZ->Write();
	hPrimaryPosXZ->Write();
	
	file1->Write();
	file1->Close();
	timer->Stop();
	timer->Print();
	
	G4cout << "rank " << rank << G4endl;
	G4cout << " there were " << decaycount << " decays detected " << endl;
	G4cout << goode << " gamma rays of 202 keV were found and " << goodestrip << " were found in strips " << G4endl;
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
  
	OnceAWhileDoIt(true); // do it now
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::BeginOfEventAction(const G4Event */*anEvent*/)
{
  //G4cout << " p26AnalysisExample::BeginOfEventAction()->********** starting event *********" << G4endl;
	
	
	#if defined (G4ANALYSIS_USE_ROOT)
	if (gSystem) gSystem->ProcessEvents();
	//G4cout << "here at root" << G4endl;
	
	if(eventcounter%1000==0)
	{
		eventtimer->Stop();
		//eventtimer->Print();
		eventtimer->Start();
		G4cout << eventcounter << " done " << G4endl;
	}
	
	eventcounter++;
	
	
	//   pixelhits = 0;
	//   pmthits = 0;
	gmult = 0;
	
	p26_energy           = 0;
	
	totE          = 0;
	edep          = 0;
	ID            = 0;
	Z             = 0;
	particletype  = "";
	particleName  = "";
	process       = "";
	creatorID     = 0;
	StepNo        = 0;
	gtime         = 0;
	
	volname       = "";
	volcopyno     = -1;
	p26copyno   = -1;
	p26_edep = 0;
	
	//   psfx = 0;
	//   psfy = 0;
	p26ap_len = 0;
	
	pathlength = 0;
	
	particletypebit = 0;
	totalelectronedep=0;
	totalgammaedep=0;
	empty = 0;
	for(Int_t k=0;k<20;k++)
	  timex[k]=-10;

	energyGe.clear();
	timeGe.clear();
	stripX.clear();
	Xpos.clear();
	stripY.clear();
	Ypos.clear();
	vparentname.clear();
	vpname.clear();
	
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
	
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::EndOfEventAction(const G4Event *evt)
{    

	// At the end of an event take the collection of hits
	// inside the DSSD and track individual particles.
	
	#if defined (G4ANALYSIS_USE_ROOT)
	//G4cout << "USE ROOT defined " << G4endl;
	if (gSystem) gSystem->ProcessEvents();
	//   G4SDManager * SDman = G4SDManager::GetSDMpointer();
	//     G4String colNam;
	
	//     G4int scintColID = SDman->GetCollectionID(colNam="scintCollection");
	//     G4int PMTColID = SDman->GetCollectionID(colNam="pmtHitCollection");
	
	
	//     //G4int  p26ColID = SDman->GetCollectionID(colNam="p26Collection");
	//   G4HCofThisEvent * HCE = evt->GetHCofThisEvent();
	//   p26DetectorHitsCollection *DHC = 0;
	// //   p26scintHitsCollection *SHC = 0;
	// //   p26PMTHitsCollection *PHC = 0;
	
	G4SDManager *SDman = G4SDManager::GetSDMpointer();
	G4String colNam;
	//G4int DetectorColID = SDman->GetCollectionID(colNam="DetectorCollection");
	G4int DetectorColID = SDman->GetCollectionID(colNam="GeThickDetectorCollection");
	G4int GeThinDetectorColID = SDman->GetCollectionID(colNam="GeThinDetectorCollection");
	G4int SegaDetectorID = SDman->GetCollectionID(colNam="SegaCollection");
	G4int CloverColID = SDman->GetCollectionID(colNam="CloverCollection");
	
	G4int LaBrColID = SDman->GetCollectionID(colNam="LaBrDetectorCollection"); //MBB
	G4int NaIColID = SDman->GetCollectionID(colNam="NaICylinderCollection"); //MBB
	G4int NaICubeColID = SDman->GetCollectionID(colNam="NaICubeCollection"); //MBB
	
	
	G4HCofThisEvent *HCE = evt->GetHCofThisEvent();
	p26DetectorHitsCollection *DHC = 0;
	p26DetectorHitsCollection *DHCthin = 0;
	p26DetectorHitsCollection *DHCsega = 0;
	p26DetectorHitsCollection *DHCClover = 0;
	
	p26DetectorHitsCollection *DHCLaBr = 0; //MBB
	p26DetectorHitsCollection *DHCNaI = 0; //MBB
	p26DetectorHitsCollection *DHCNaICube = 0; //MBB
	
	
	G4int gammaincenter;
	gammaincenter = 0;
	
	if(HCE)
	{
		DHC = (p26DetectorHitsCollection*)(HCE->GetHC(DetectorColID));
		DHCthin = (p26DetectorHitsCollection*)(HCE->GetHC(GeThinDetectorColID));
		DHCsega = (p26DetectorHitsCollection*)(HCE->GetHC(SegaDetectorID));
		DHCClover = (p26DetectorHitsCollection*)(HCE->GetHC(CloverColID));
		
		DHCLaBr = (p26DetectorHitsCollection*)(HCE->GetHC(LaBrColID)); //MBB
		DHCNaI = (p26DetectorHitsCollection*)(HCE->GetHC(NaIColID)); //MBB
		DHCNaICube = (p26DetectorHitsCollection*)(HCE->GetHC(NaICubeColID)); //MBB
	}
	
	G4double totEThin;		//total energy deposited in a detector
	G4double totEThinRes;		//corrected for resolution of that detector
	G4double totEThinBeta;		//total energy deposited JUST by positrons (beta-plus!)
	G4double totEThinBetaRes;	//corrected for resolution of the Thin detector.
	
	G4double totELaBr;		//The same four variables for the LaBr 
	G4double totELaBrRes;
	G4double totELaBrBeta;
	G4double totELaBrBetaRes;
	
	G4double totENaI;			//The same four variables for the sodium iodide detector
	G4double totENaIBeta; 
	G4double totENaIRes;
	G4double totENaIBetaRes;
		
	////////////////////////////////////////////////////////////////////////////////////////


	G4double totaledep_stripx[100];
	G4double totaledep_stripy[100];
	G4double totaledep_xy[100][100];
	
	for(int i=0;i<100;i++)
	{
		totaledep_stripx[i] = totaledep_stripy[i] = 0;
		for(int j=0;j<100;j++)
		{
			totaledep_xy[i][j] = 0;
		}
	}
	
	for(G4int type=0;type<3;type++)
	{
		for(G4int x=0;x<100;x++)
		{
			for(G4int y=0;y<100;y++)
			{
				for(G4int z=0;z<2;z++)
				{
					totaledep[type][x][y][z]=0;
				}
			}
		}
	}
	
	
	G4ThreeVector gamma1modir;
	G4ThreeVector gamma2modir;
	

	
	
////////////////////  DHC LOOP -- Ostensibly for the Thick Detector? /////////////////
 
	if(DHC)
	{
	
	//	cout << "In the DHC loop!" << endl;
	
	  int n_hit = DHC->entries();
	
	  //cout << "n_hit = " << n_hit << endl;
	
		for(int i=0; i<n_hit; i++)
		{
			// for every particle that deposited energy in the GeDSSD determine
			// its name, what beta decay product it came from and the beta decay
			// product's energy.
	
			//G4cout << "in the DHC for loop!" << G4endl;
	
			G4String name = (*DHC)[i]->GetParticlename();
			G4String parentname = (*DHC)[i]->GetParentName();
			G4double parentenergy = (*DHC)[i]->GetParentEnergy();
			G4ThreeVector parmodir = (*DHC)[i]->GetParentMoDir();
	
	
	
			// retrieve the energy deposited in this step, the position and the step number
			G4double edep = (*DHC)[i]->GetEdep()/ keV;
			G4ThreeVector pos = (*DHC)[i]->GetPostPosition();
			G4int stepno = (*DHC)[i]->GetStepno();
			G4double globaltime = (*DHC)[i]->GetGtime()/second;
			G4double getime=(*DHC)[i]->GetGtime()/ns;
	
	
			// determine the strip number
			// center strip is centered around 0 [-0.5,0.5)
			// detector is centered around x,y = 0,0.  position must be offset by one
			// radius to ensure that the stripnumx and stripnumy variables are non-negative
			
			G4int stripx = G4int((pos.x()/mm + (GeThickDetectorRadius/mm)+ (stripwidthx/2.))/(stripwidthx));
			G4int stripy = G4int((pos.y()/mm + (GeThickDetectorRadius/mm)+ (stripwidthy/2.))/(stripwidthy));
	
			energyGe.push_back(edep);
			timeGe.push_back(getime);
			stripX.push_back(stripx);	
			Xpos.push_back(pos.x()/mm);
			stripY.push_back(stripy);	
			Ypos.push_back(pos.y()/mm);
			timex[stripx]=getime;
			vparentname.push_back(parentname);
			vpname.push_back(name);
	
	
			// technically there are no physical strips in the z direction but
			// this is included to see if there is an advantage of trying to determine
			// z position
			//G4int stripz = G4int((pos.z()/mm + ((GeThickDetectorThickness/mm)/2.))/(stripwidthz));
	
			// This definition of stripz will be used for 2 cm detectors an will devide the GeDSSD into
			// the first 2 mm and then everything else.  Applicable for p26non project.
			G4int stripz = -1;
			if( (pos.z()/mm + ((GeThickDetectorThickness/mm)/2.)) < 0.5)
			{
				stripz = 0;
			} else {
				stripz = 1;
			}
	
	
	
	
			//      G4cout << "zpos calc " << pos.z()/mm << " " << (GeThickDetectorThickness/mm)/2. << " " << stripwidthz
			//	     << " " << stripz << G4endl;
	
	
			if(name == "gamma" && parentname == "gamma" && stepno == 1)
			{
				//G4cout << "what is happening " << parentenergy/keV << G4endl;
	
				if((parentenergy/keV) > 201.99 && (parentenergy/keV) < 202.01)
				{
					gamma1modir = parmodir;
					//G4cout << "found 202 " <<" " << parentenergy << " " << parmodir.mag() << G4endl;
				} else if((parentenergy/keV) > 197.99 && (parentenergy/keV) < 198.01) {
					gamma2modir = parmodir;
					//G4cout << " found 198 " << G4endl;
				}	
			}
	
	
			if(name == "gamma" && parentname == "gamma")
			{
				//found a gamma ray - don't think this is a good multiplicity
				gmult++;
			}
	
			if(name == "P26[0.0]" && stepno == 1)
			{
				//sanity check
				decaycount++;
			}
		
			//G4cout << "edep and location " << stepno<< " " << name << " " << parentname << " " << parentenergy
			//<< " " << edep << " " << stripx << " " << stripy << " " << stripz << G4endl;
	
			totE+=edep;
			gtime=globaltime*1e3;
			
			//if(getime<=2000){ //select 2us events

                         if (parentname == "e-" )
			{
				totaledep[0][stripx][stripy][stripz] += edep;
				totalelectronedep+=edep;
			} else if (parentname == "gamma") {
				totaledep[1][stripx][stripy][stripz] += edep;
				totalgammaedep+=edep;
			} else {
				totaledep[2][stripx][stripy][stripz] += edep;
                        }
			 //}
                     }
	
	
         } else {
		G4cout << "no decay empty event " << empty++ << G4endl;
	}
	
	//////////////////     END OF DHC LOOP     ///////////////////////////////////////
	
	
	// hits in the Sega detectors
	if(DHCsega)
	  {
		
	  G4double segaE[16];
		for(int x=0;x<16;x++)
		  {
		  segaE[x]=0;
		  segatime[x]=0;
		}
		
		int n_hit = DHCsega->entries();
		for(int i=0; i<n_hit; i++)
		  {
		  G4String name = (*DHCsega)[i]->GetParticlename();
			G4String parentname = (*DHCsega)[i]->GetParentName();
			G4double parentenergy = (*DHCsega)[i]->GetParentEnergy();
			G4double edep = (*DHCsega)[i]->GetEdep()/keV;
			G4double time= (*DHCsega)[i]->GetGtime()/ns;
			G4ThreeVector pos = (*DHCsega)[i]->GetPostPosition();
			G4int copyno = (*DHCsega)[i]->GetVolCopyNo();
			//if(time<2000){	
			segaE[copyno] += edep;
			segatime[copyno]=time;
                        //}
			//       G4cout << "particle - " << name << " - came from " 
			// 	     << parentname << " " << parentenergy  
			// 	     << " and deposited " << edep/keV << " keV at " 
			// 	     << G4int(pos.x()/mm + 50.5) << " " << G4int(pos.y()/mm + 50.5) << G4endl;
		}
		
		G4double segaadd = 0;
       
		for(int x=0;x<16;x++)
		  {
		  if(segaE[x] > 0)
			  {
			  G4double rando = ((G4UniformRand() * 0.002) -0.001);
				//G4cout << "rand " << rando << " " << segaE[x] << " " << segaE[x] +  rando * segaE[x] << G4endl;
				segaE[x] = segaE[x] +  rando * segaE[x];
				
				
				hEnergyDepositSega[x]->Fill(segaE[x]);
			segaE[x] = gRandom->Gaus(segaE[x],(0.003*segaE[x]/2.35));
			/*if(G4UniformRand() < 0.35)*/
			}
		        hSega->Fill(segaE[x]);
			
			segaedep[x]=segaE[x];
               
			//      hsega_tigress->Fill(segaE[x]);
			//      hsega_tigress_s->Fill(segaE[x]);
			segaadd = segaadd+segaE[x];
		
		}
		
		/*if(G4UniformRand() < 0.35 ) */ hSegaab->Fill(segaadd);
	
	} // end sega
	
	

	//calculate angle between vectors
	//check if vectors are unit vectors
	if(gamma1modir.mag() != 0 && gamma2modir.mag() != 0)
	{
		//G4cout << "unit vector ? " << gamma1modir.mag() << " " << gamma2modir.mag() << G4endl;
		//G4cout << "gamma1 " << gamma1modir.x() << " " <<gamma1modir.y() << " " << gamma1modir.z() << G4endl;
		//G4cout << "gamma2 " << gamma2modir.x() << " " <<gamma2modir.y() << " " << gamma2modir.z() << G4endl;
		G4double dotprod;
		dotprod= (gamma1modir/gamma1modir.mag()) * (gamma2modir/gamma2modir.mag());
		G4double angle;
		angle = acos(dotprod)/CLHEP::degree;
		//G4cout << " angle " << angle << G4endl;
	
	//    hgangcortheory->Fill(angle);
	}

	//hEnergyDepositElectron2D->Fill(pos.x()/mm + 0.5,pos.y()/mm + 0.5,edep/keV);
	//hEnergyDepositGamma2D->Fill(pos.x()/mm + 0.5,pos.y()/mm + 0.5,edep/keV);
	
	
	// define variables
	G4double tedep, tedepe, tedepg, tedepo, tedeplowz, tedephiz;
	tedep = tedepe = tedepg = tedepo = tedeplowz = tedephiz = 0;
	
	
	//	cout << "tedepe = " << tedepe << endl;
	// strips in x and z
	G4int tedepx_size = 20;
	for(G4int i=0;i<tedepx_size;i++) tedepx[i] = tedepy[i] = 0;
	
	//fill spectra
	
	// loop over the totaledep array and fill the appropriate spectra
	for(G4int type=0; type<3; type++)
	  {
	    
	    for(G4int x=0;x<tedepx_size;x++)
	      {
		
		for(G4int y=0;y<tedepx_size;y++)
		  {
		    
		    G4double tempsum = 0;
		    
		    for(G4int z=0;z<2;z++)
		      {
			tedepx[x] += totaledep[type][x][y][z];
			tedepy[y] += totaledep[type][x][y][z];
			
			tempsum +=totaledep[type][x][y][z];
			
			// accuulate total energy deposited, treat GeDSSD as one crystal calorimeter
			tedep += totaledep[type][x][y][z];
			if(z==0) tedeplowz += totaledep[type][x][y][z];
			else tedephiz += totaledep[type][x][y][z];
			

			// accumulate total energy deposited for electron
			if(type == 0)
			  {
			    tedepe += totaledep[type][x][y][z];
			    //cout << " *********************************** TYPE = 0 **************** " << endl;
			    //cout << " tedepe = " << tedepe << endl; //" = " 
			    
			    //cout << "totaledep = " << totaledep[type][x][y][z] << endl;
			  }
					// accumulate total energy deposited for gamma
			if(type == 1)
			  {
			    tedepg += totaledep[type][x][y][z];
			    //cout << " ================================= TYPE = 1 ================== " << endl;
						//cout << "tedepg = " << tedepg << endl;
			    
						//cout << "totaledep = " << totaledep[type][x][y][z] << endl;
			    
			  }
			// accumulate total energy deposited for other
			if(type == 2)
			  {
			    tedepo += totaledep[type][x][y][z];
			    //cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TYPE = 2 >>>>>>>>>>>>>>>> " << endl;
			    //cout << "tedepo = " << tedepo << endl;
			    
			    //cout << "totaledep = " << totaledep[type][x][y][z] << endl;
			    
			  }
		      }

		    // 	if(tempsum > 0){
		    // 	  G4cout << "pixel E " << tempsum << " " << x << " " << y << " " << G4endl;
		    // 	}
		  }
	      }
	}
	
	//G4cout << "total E" << tedep << " " << tedepe << " " <<tedepg << " " << tedepo << G4endl;
	
	tedep = gRandom->Gaus(tedep,tedep*0.004/2.35);
	hEnergyDeposit->Fill(tedep);
	
	
	if(tedepg < 162 && tedepg < 165) goode++;
	
	G4int stripmultx, stripmulty;
	stripmultx = stripmulty = 0;
	
	G4double maxEstripx = 0;
	G4int maxEstriplocx = 0;
	G4double maxEstripy = 0;
	G4int maxEstriplocy = 0;
	
	G4bool xval =false;
	G4bool yval =false;
	for(G4int i=0;i<tedepx_size;i++)
	{
	
		if(tedepx[i] > maxEstripx)
		{
			maxEstripx = tedepx[i];
			maxEstriplocx = i;
		}
	
		if(tedepx[i] > 0)
		{
			stripmultx++;
	
			//perform simple gamma-gamma
			for(G4int j=i+1;j<tedepx_size;j++)
			{
				if(tedepx[j] > 0)
				{
					hGammaGamma->Fill(tedepx[i],tedepx[j]);
					hGammaGamma->Fill(tedepx[j],tedepx[i]);
				}
	
			}
	
			//G4cout << "stripx " << i << " " << tedepx[i] << G4endl;
			if(tedepx[i]>201 && tedepx[i]<203) xval = true;
			
		}
			
		if(tedepy[i] > maxEstripy)
		{
			maxEstripy = tedepy[i];
			maxEstriplocy = i;
		}
		
		if(tedepy[i] > 0)
		{
			stripmulty++;
			//G4cout << "stripy " << i << " " << tedepy[i] << G4endl;
			if(tedepy[i]>201 && tedepy[i]<203) yval = true;
			
		}
			
	}
			
			
	if(xval || yval) goodestrip++;
	
	//G4cout << " ** end event ** "<< G4endl;
	G4int gamma1x, gamma1y;
	G4int gamma2x, gamma2y;
	
	gamma1x = gamma1y = gamma2x = gamma2y = 0;
			
			
	/*
	for(G4int x=0;x<tedepx_size;x++){
	//find an x strip with some energy
	if(tedepx[x] > 0){
		//match this x strip to a corresponding y strip within a 1% energy difference
		for(G4int y=0;y<tedepx_size;y++){
		if(tedepy[y] > 0){
		G4double diff = abs(tedepx[x] - tedepy[y]);
		G4double perdiff = diff / tedepx[x];
		G4double avg = (tedepx[x] + tedepy[y])/2.;
		if(perdiff < 0.01){
		//match found zero values and put into 2D array
		//G4cout << "energy in DSSD " << x << " " << y << " " << avg/keV <<G4endl;
		totaledep_xy[x][y] = avg;
	//	    hEnergyDepositPixel->Fill(avg);
		//if(x!=9 && y!=9) hEnergyDepositGamma_nocenter->Fill(avg);
	
		if(avg>201 && avg < 203){
			gamma1x = x; gamma1y = y;
		}
		if(avg > 197 && avg < 199){
			gamma2x = x; gamma2y = y;
		}
		}
		}
		}
	}
	}
	/**/

	if(gamma1x != 0 && gamma2x != 0)
	{
		G4ThreeVector gamma1(gamma1x-9,gamma1y-9,0);
		G4ThreeVector gamma2(gamma2x-9,gamma2y-9,0);
		G4double dotprod;
		dotprod= (gamma1/gamma1.mag()) * (gamma2/gamma2.mag());
		G4double angle;
		angle = acos(dotprod)/CLHEP::degree;
		//G4cout << "dotprod " << dotprod << " angle " << angle << G4endl;
		
		//    hgangcorexper->Fill(angle);
	}

	//  hStripMultx->Fill(stripmultx);


	if (p26tree)
	{
		p26tree->Fill();
	}



	#endif /* defined (G4ANALYSIS_USE_ROOT) */
  
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::ClassifyNewTrack(
			     const G4Track *aTrack,
			     G4ClassificationOfNewTrack */*classification_ptr*/)
{
	// G4ClassificationOfNewTrack &classification = (*classification_ptr);
	
	#if defined (G4ANALYSIS_USE_ROOT)
	
	if (gSystem) gSystem->ProcessEvents();
	
	G4String particleName = aTrack->GetDefinition()->GetParticleName();
	
	if (particleName == "opticalphoton")
	{
		Double_t aWaveLength = 0.0; // will be in [nanometer]
		aWaveLength = (LambdaE / aTrack->GetTotalEnergy()) / nanometer; // in [nanometer]
		// aWaveLength = (LambdaE / aTrack->GetKineticEnergy()) / nanometer; // in [nanometer]
		if (hOPWaveLength) hOPWaveLength->Fill(aWaveLength, aTrack->GetWeight()); // Wavelength of the produced optical photon
	}
	
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
  
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::NewStage()
{
	#if defined (G4ANALYSIS_USE_ROOT)
  
	if (gSystem) gSystem->ProcessEvents();
  
  
  
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
  
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::PrepareNewEvent()
{
	#if defined (G4ANALYSIS_USE_ROOT)
  
	if (gSystem) gSystem->ProcessEvents();
  
  
  
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
  
	OnceAWhileDoIt();
}

void p26AnalysisExample::PrepareNewRun(G4double x, G4double y, G4double z, G4double zpos,
				       G4int r, G4int c)
{
	#if defined (G4ANALYSIS_USE_ROOT)
  
	if (gSystem) gSystem->ProcessEvents();
	
	//set up detector parameters
	
	//position of the scint fiber, the scint fiber length
	//   scint_fiber_x = x;
	//   scint_fiber_y = y;
	//   scint_fiber_z = z;
	//   scint_fiber_zpos = zpos;
	//   scint_rows = r;
	//   scint_columns = c;
	
	//set up the dimensions of the scint energy deposition array
	// intialize all elements to zero
	//   for(G4int i=0; i<scint_rows; i++){
	//     for(G4int j=0; j<scint_columns; j++){
	//       for(G4int k=0; k<int((scint_fiber_z/mm)/scint_zpixel)+1; k++){
	// 	temp1d.push_back(0);
	//       }
	//       temp2d.push_back(temp1d);
	//       temp2dzero.push_back(temp1d);
	//       temp1d.clear();
	//     }
	//     scint_fiber_edep.push_back(temp2d);
	//     scint_fiber_edep_zero.push_back(temp2d);
	//     temp2d.clear();
	//   }
	
	
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
  
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::PreUserTrackingAction(const G4Track */*aTrack*/)
{
	#if defined (G4ANALYSIS_USE_ROOT)
	if (gSystem) gSystem->ProcessEvents();
  
  
  
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
  
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::PostUserTrackingAction(const G4Track */*aTrack*/,
						G4TrackStatus */*status_ptr*/)
{
	// G4TrackStatus &status = (*status_ptr);
  
	#if defined (G4ANALYSIS_USE_ROOT)
	if (gSystem) gSystem->ProcessEvents();
  
  
  
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
  
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::UserSteppingAction(const G4Step *aStep)
{
	#if defined (G4ANALYSIS_USE_ROOT)
  

	//Double_t aStepLength = (aStep->GetStepLength() / cm); // in [cm]
	// Double_t aTotalEnergyLoss = (aStep->GetTotalEnergyDeposit() / MeV); // in [MeV]
	//Double_t aTotalEnergyLoss = -(aStep->GetDeltaEnergy() / MeV); // in [MeV]
	//Double_t aTotalEnergyLossPerLengthUnit = -1.0; // will be in [MeV/cm]
	//Double_t aWeight = aStep->GetTrack()->GetWeight();
	
	//if (hStepLength) hStepLength->Fill(aStepLength, aWeight); // Step Length
	
	//if (hStepTotELoss) hStepTotELoss->Fill(aTotalEnergyLoss, aWeight); // Step Total Energy Loss
	
	//if (aStepLength != 0.0) aTotalEnergyLossPerLengthUnit = aTotalEnergyLoss / aStepLength;
	//else aTotalEnergyLossPerLengthUnit = aTotalEnergyLoss / 1.0e-7; // in [MeV/cm]
	//if (hTotELossNorm) hTotELossNorm->Fill(aTotalEnergyLossPerLengthUnit, aWeight); // Total Energy Loss per Step Length Unit
	
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
  
	OnceAWhileDoIt();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void p26AnalysisExample::OnceAWhileDoIt(const G4bool DoItNow)
{
	time_t Now = time(0); // get the current time (measured in seconds)
	if ( (!DoItNow) && (LastDoItTime > (Now - 10)) ) return; // every 10 seconds
	LastDoItTime = Now;
	
	#if defined (G4ANALYSIS_USE_ROOT)
  
	TVirtualPad *CurrentPad = gPad;
	
	const char OnceAWhileCanvas[] = "p26AnalysisExampleCanvas";
	
	TCanvas *c = (TCanvas *)gROOT->GetListOfCanvases()->FindObject(OnceAWhileCanvas);
	
	if ( DoItNow && (!c) && ((G4RunManager::GetRunManager())->GetVerboseLevel() > 1) )
	{
		// first, try to make sure we do not run in batch mode
		if (!gApplication)
		new TApplication("Application", ((int *)0), ((char **)0));
		// then, create the TCanvas
		c = new TCanvas(OnceAWhileCanvas, OnceAWhileCanvas);
		if (c)
		{
			c->Divide(2,2);
			c->cd(1); if (hStepLength) hStepLength->Draw();
			c->cd(2); if (hStepTotELoss) hStepTotELoss->Draw();
			c->cd(3); if (hOPWaveLength) hOPWaveLength->Draw();
			c->cd(4); if (hTotELossNorm) hTotELossNorm->Draw();
			c->cd(0);
		}
	}
  
	if (c)
	{
		//c->cd(0);
		c->Draw();
		c->Update();
	}
	
	if (CurrentPad) CurrentPad->cd();
	
	if (gSystem) gSystem->ProcessEvents();
	
	#endif /* defined (G4ANALYSIS_USE_ROOT) */
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

// end of file p26AnalysisExample.cc by Jacek M. Holeczek

void p26AnalysisExample::Setfilename(G4String nam)
{
	filename = nam;
}

void p26AnalysisExample::Setdirname(G4String nam)
{
	dirname = nam;
}

void p26AnalysisExample::OpticalPhotons(G4int status, G4double val)
{
	//   if(status == 1){
	//     opticalphoton++;
	//   }
	//   else if(status == 9){
	//     opticalkill++;
	//   }
	//   else{
	//     G4cout << "wandering gamma" << G4endl;
	//   }
}

void p26AnalysisExample::PSF(G4int status, G4double val1, G4double val2)
{
  
	//   if(status == 0){
	//     p26ap_len = p26ap_len + val1;
	//   }
	//   else if(status == 1){
	//     psfx = val1;
	//     psfy = val2;
	//     htally->Fill(psfx,psfy);
	//     hpsf->Fill(psfx,psfy,exp(-p26ap_len/5));
	//   }

}
