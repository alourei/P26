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

#ifndef p26AnalysisExample_h
#define p26AnalysisExample_h 1

#include "p26AnalysisManager.hh"


class G4VPhysicalVolume;
class G4Event;
class G4Run;
class G4Track;
class G4Step;
class p26AnalysisExampleMessenger;

class p26DetectorConstruction;

#include "G4ClassificationOfNewTrack.hh"
#include "G4ThreeVector.hh"
#include "G4TrackStatus.hh"
#include "G4Types.hh"
#include <time.h>
#include <vector>
#include <iostream>
#include <cctype>
using namespace std;


#if defined (G4UI_USE_ROOT) || defined (G4UI_BUILD_ROOT_SESSION)
#if !defined (G4ANALYSIS_USE_ROOT)
#define G4ANALYSIS_USE_ROOT 1
#endif /* !defined (G4ANALYSIS_USE_ROOT) */
#endif /* defined (G4UI_USE_ROOT) || defined (G4UI_BUILD_ROOT_SESSION) */

#if defined (G4ANALYSIS_USE_ROOT)

class TH1D;
class TH2D;
class TFile;
class TNtuple;
class TStopwatch;
class TTree;

//   struct declare_event //event information
//   {
//     double parent_alpha_E;
//     double alpha1_E;
//   };
//   extern declare_event user_event;

//G4int ex_check;

#endif /* defined (G4ANALYSIS_USE_ROOT) */

class p26AnalysisExample : public p26AnalysisManager {
  
public:
  p26AnalysisExample();
  ~p26AnalysisExample();
  
public:
  // G4VUserDetectorConstruction
  void Construct(const G4VPhysicalVolume*);
  
  // G4VUserPhysicsList
  void ConstructParticle();
  void ConstructProcess();
  void SetCuts();
  
  // G4VUserPrimaryGeneratorAction
  void GeneratePrimaries(const G4Event*, const G4double beam);
  void ResetStartLocation(G4double &, G4double &);

  void DetectorInfo(p26DetectorConstruction*);
  
  // G4UserRunAction
  void BeginOfRunAction(const G4Run*, G4int);
  void EndOfRunAction(const G4Run*, G4int);
  
  // G4UserEventAction
  void BeginOfEventAction(const G4Event*);
  void EndOfEventAction(const G4Event*);
  
  // G4UserStackingAction
  void ClassifyNewTrack(const G4Track*, G4ClassificationOfNewTrack*);
  void NewStage();
  void PrepareNewEvent();
  void PrepareNewRun(G4double, G4double, G4double, G4double, G4int, G4int);
  
  // G4UserTrackingAction
  void PreUserTrackingAction(const G4Track*);
  void PostUserTrackingAction(const G4Track*, G4TrackStatus*);
  
  // G4UserSteppingAction
  void UserSteppingAction(const G4Step*);
  
  // once a while do "something"
  void OnceAWhileDoIt(const G4bool DoItNow = false);

  //void SetparentZ(G4int val) {parentZ = val;};
  //void SetdaughterZ(G4int val) {daughterZ = val;};
  void Setfilename(G4String nam);
  void Setdirname(G4String nam);

  void OpticalPhotons(G4int, G4double);
  void PSF(G4int, G4double, G4double);

private:

  time_t LastDoItTime; // used in OnceAWhileDoIt method
  
  G4int UseGeThickDetector;
  G4int UseGeThinDetector;
  
  G4int UseNaICylinder; //MBB
  G4int UseLaBrDetector;
  G4int UseNaICube;

  G4double GeThickDetectorThickness;
  G4double GeThinDetectorThickness;
  
  G4double NaICylinderThickness; //MBB
  G4double NaICubeThickness;
  G4double LaBrDetectorThickness;

  G4double GeThickDetectorRadius;
  G4double GeThinDetectorRadius;
  
  G4double NaICylinderRadius; //MBB
  G4double NaICubeDepth;
  G4double LaBrDetectorRadius;


  G4double GeThickx;
  G4double GeThicky;
  G4double GeThickz;
  G4double GeThinx;
  G4double GeThiny;
  G4double GeThinz;
  
  G4double LaBrx; //MBB
  G4double LaBry; //MBB
  G4double LaBrz; //MBB
  G4double NaICylx; //MBB
  G4double NaICyly; //MBB
  G4double NaICylz; //MBB
  G4double NaICubex; //MBB
  G4double NaICubey; //MBB
  G4double NaICubez; //MBB
  
  
  G4double GeSpacing;

  G4int pixelhits;
  G4int gmult;
  G4double stripwidthx;
  G4double stripwidthy;
  G4double stripwidthz;

  G4double parent_energy, daughter_energy, p26_energy;

  G4int filecount;
  G4double totE;
  G4double edep;
  G4int ID;
  G4double Z;
  G4String particletype;
  G4String particleName;
  G4String process;
  G4int creatorID;
  G4int StepNo;
  G4double gtime;

    G4String volname;
    G4int volcopyno, p26copyno;

    G4double p26_edep, crystal_edep[68];

  G4int decaycount;

  G4ThreeVector prepos;
  G4ThreeVector postpos;
  G4ThreeVector deltapos;

  G4double beam_energy;


  G4double tedepx[20];
  G4double timex[20];
  G4double tedepy[20];
  //for the full scint array


  G4double pathlength;
  G4double totaledep[3][100][100][2];
  G4double totalelectronedep;
  G4double totalgammaedep;
  G4double p26ap_len;
  G4double psfx;
  G4double psfy;

  G4double segaedep[16];
  G4double segatime[16];

  std::vector<G4double> energyGe;
  std::vector<G4double> timeGe;
  std::vector<G4int> stripX;
  std::vector<G4int> stripY;
  std::vector<G4double> Xpos;
  std::vector<G4double> Ypos;
  std::vector<string> vparentname;
  std::vector<string> vpname;

  G4double goode;
  G4double goodestrip;

  G4int eventcounter;
  G4int particletypebit;
  G4int empty;
  p26AnalysisExampleMessenger* analysisexample;

  //char ch[] = "";
  //const char *cp = ch;
  //char filename[100];
  //const char *filepointer;

  G4String filename;
  G4String dirname;
  //C4Char *filepointer = filename;

#if defined (G4ANALYSIS_USE_ROOT)
  
  TFile *file1; // test file
  TFile *rfile1; //retrieve file
  TNtuple *p26ntup; // p26 ntuple output
  TTree *p26tree;
  TTree *p26info;

  TStopwatch *timer;
  TStopwatch *eventtimer;

  TH1D *hEnergyDeposit;
  TH1D *hEnergyDepositThinDe;

	TH1D *hEnergyDepositThinDeBeta; //MBB
	TH1D *hEDepNaI; //MBB 16 Aug 2013
	TH1D *hEDepNaIBeta; //MBB 16 Aug 2013
	TH1D *hEDepLaBr; //MBB
	TH1D *hEDepLaBrBeta; //MBB

  TH2D *hGammaGamma;


  TH1D *hStepLength; // Step Length
  TH1D *hStepTotELoss; // Step Total Energy Loss
  TH1D *hTotELossNorm; // Total Energy Loss per Step Length Unit
  
  TH1D *hOPWaveLength; // Wavelength of the produced optical photon
  
  TH1D *hAlpha1_energy; // alpha 1 energy deposited in detector
  TH1D *hAlpha2_energy; // alpha 2 energy deposited in detector
  TH1D *hParent_energy; // energy deposited from parent ion (including implantation)
  TH1D *hDaughter_energy; // energy deposited from daughter ion

  TH1D *hTot_energy; // energy deposited in DSSD
  TH1D *hBeam_energy; // energy deposited in DSSD
//  TH2D *hPrimaryPosin; //primary map input from external source
  TH2D *hPrimaryPosXY; //primary position of particle
  TH2D *hPrimaryPosYZ; //primary position of particle
  TH2D *hPrimaryPosXZ; //primary position of particle

  TH1D *hCrystalEdep[68]; //energy deposited in each crystal
    TH1D *hGammaSingle;
    TH1D *hGammaSingleAdd;
  TH1D *hParent_tracklen; //

    TH2D *hScintEdep_xy;
    TH2D *hScintEdep_yz;

  TH2D *hScintPhoton_xy;
  TH2D *htally;
  TH2D *hpsf;

//  TH1D *hgangcortheory;
//  TH1D *hgangcorexper;

  TH1D *hEnergyDepositSega[16];
  TH1D *hSega;
  TH1D *hSegaab;
  TH1D *hEnergyDepositClover[36];
  TH1D *hClover;
  TH1D *hEnergyDepositClover_addback[9];
  TH1D *hClover_addback;
  TH1D *hClover_arrayadd;
//  TH1D *hsega_tigress;
//  TH1D *hsega_tigress_s;


#endif /* defined (G4ANALYSIS_USE_ROOT) */
  



};

#endif
