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

#ifndef p26AnalysisManager_h
#define p26AnalysisManager_h 1


class G4VPhysicalVolume;
class G4Event;
class G4Run;
class G4Track;
class G4Step;
class p26DetectorConstruction;

#include "G4ClassificationOfNewTrack.hh"
#include "G4TrackStatus.hh"
#include "G4Types.hh"
#include "globals.hh"


class p26AnalysisManager;
extern p26AnalysisManager *gp26AnalysisManager; // global p26AnalysisManager

class p26AnalysisManager {
  
public:
  p26AnalysisManager() {
    if (gp26AnalysisManager)
      delete gp26AnalysisManager;
    gp26AnalysisManager = this;
  }
  
  virtual ~p26AnalysisManager() {
    if (gp26AnalysisManager == this)
      gp26AnalysisManager = (p26AnalysisManager *)0;
  }
  
  static p26AnalysisManager *GetAnalysisManager() {
    return gp26AnalysisManager;
  }
  
public:


  // G4VUserDetectorConstruction
  virtual void Construct(const G4VPhysicalVolume */*theWorldWolume*/) {;}
  
  // G4VUserPhysicsList
  virtual void ConstructParticle() {;}
  virtual void ConstructProcess() {;}
  virtual void SetCuts() {;}
  
  // G4VUserPrimaryGeneratorAction
  virtual void GeneratePrimaries(const G4Event */*anEvent*/, const G4double /*beam*/) {;} //added the asterisk
  virtual void ResetStartLocation(G4double &, G4double &) {;}
  
  virtual void DetectorInfo(p26DetectorConstruction*) {;}

  // G4UserRunAction
  virtual void BeginOfRunAction(const G4Run */*aRun*/, G4int) {;}
  virtual void EndOfRunAction(const G4Run */*aRun*/, G4int) {;}
  
  // G4UserEventAction
  virtual void BeginOfEventAction(const G4Event */*anEvent*/) {;}
  virtual void EndOfEventAction(const G4Event */*anEvent*/) {;}
  
  // G4UserStackingAction
  virtual void ClassifyNewTrack(
		   const G4Track */*aTrack*/,
		   G4ClassificationOfNewTrack */*classification*/) {;}
  virtual void NewStage() {;}
  virtual void PrepareNewEvent() {;}
  virtual void PrepareNewRun(G4double, G4double, G4double, G4double, G4int, G4int) {;}
  
  // G4UserTrackingAction
  virtual void PreUserTrackingAction(const G4Track */*aTrack*/) {;}
  virtual void PostUserTrackingAction(const G4Track */*aTrack*/,
				      G4TrackStatus */*status*/) {;}
  
  // G4UserSteppingAction
  virtual void UserSteppingAction(const G4Step */*aStep*/) {;}
  
  virtual void OpticalPhotons(G4int, G4double){;}
  virtual void PSF(G4int, G4double, G4double){;}
};

#endif

