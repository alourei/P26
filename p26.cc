//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#ifdef G4UI_USE_GAG
#include "G4UIGAG.hh"
#endif
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"
#ifdef G4UI_USE_XM
#include "G4UIXm.hh"
#endif 
#include "G4UIExecutive.hh"

#include "p26DetectorConstruction.hh"
#include "p26PhysicsList.hh"
#include "p26EventAction.hh"
#include "p26RunAction.hh"
#include "p26TrackingAction.hh"
#include "p26SteppingAction.hh"
#include "p26PrimaryGeneratorAction.hh"
#include "p26AnalysisManager.hh"
#include "p26AnalysisExample.hh"
#include "Randomize.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

int main(int argc,char** argv)
{
  // random engine
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);

  // Construct the default run manager
  G4RunManager* runManager = new G4RunManager;

  // Creation of the analysis 
  p26AnalysisExample* analysis = new p26AnalysisExample();
  //p26AnalysisManager* analysis = p26AnalysisManager::getInstance();

  // set mandatory initialization classes

  p26DetectorConstruction* Detector = new p26DetectorConstruction;
  runManager->SetUserInitialization(Detector);
  runManager->SetUserInitialization(new p26PhysicsList);

  G4cout << "driver done 1"  << G4endl;

  // set mandatory user action class
  runManager->SetUserAction(new p26PrimaryGeneratorAction);
  G4cout << "driver done 2"  << G4endl;
  runManager->SetUserAction(new p26RunAction);
  G4cout << "driver done 3"  << G4endl;
  runManager->SetUserAction(new p26EventAction);
  G4cout << "driver done 4"  << G4endl;
  runManager->SetUserAction(new p26TrackingAction); //added SNL
  G4cout << "driver done 5"  << G4endl;
  runManager->SetUserAction(new p26SteppingAction);
  G4cout << "driver done 6"  << G4endl;
  //
  //
   //G4UIsession* session=0;
   G4UIExecutive* session=0;
  
   if (argc==1)   // Define UI session for interactive mode.
     {
#ifdef G4UI_USE_QT
      session = new G4UIExecutive(argc,argv);
#else           
#ifdef G4UI_USE_TCSH
      session = new G4UIterminal(new G4UItcsh);      
#else
      session = new G4UIterminal();
#endif
#endif
    }
 
#ifdef G4VIS_USE
  // visualization manager
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
#endif

  // Initialize G4 kernel
  // do this at run time so the geometry/physics can be changed
  //  runManager->Initialize();

  // get the pointer to the User Interface manager 
  G4UImanager* UI = G4UImanager::GetUIpointer();  
  if (session)   // Define UI session for interactive mode.
    {
      session->SessionStart();
      UI->ApplyCommand("/control/execute vis.mac");
      delete session;
    }
  else           // Batch mode
    { 
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UI->ApplyCommand(command+fileName);
    }
  
  // job termination
#ifdef G4VIS_USE
  delete visManager;
#endif
  delete analysis;
  delete runManager;

  G4cout << "This is the DPL's in the simulation space"  << G4endl;

  return 0;
}








