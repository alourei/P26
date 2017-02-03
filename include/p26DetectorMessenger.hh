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
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef p26DetectorMessenger_h
#define p26DetectorMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class p26DetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithABool;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class p26DetectorMessenger: public G4UImessenger
{
  public:
    p26DetectorMessenger(p26DetectorConstruction*);
   ~p26DetectorMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
    p26DetectorConstruction* myDetector;
    
    G4UIdirectory*             p26Dir;
    G4UIdirectory*             detDir;

    G4UIcmdWithAString*        GeThickDetectorMatCmd;
    G4UIcmdWithADoubleAndUnit* GeThickDetectorRadiusCmd;
    G4UIcmdWithADoubleAndUnit* GeThickDetectorThicknessCmd;

    G4UIcmdWithAString*        GeThinDetectorMatCmd;
    G4UIcmdWithADoubleAndUnit* GeThinDetectorRadiusCmd;
    G4UIcmdWithADoubleAndUnit* GeThinDetectorThicknessCmd;
    
////// MBB added 16 Aug 2013 ///////

	G4UIcmdWithAString*		NaICylinderMatCmd;
	G4UIcmdWithADoubleAndUnit*	NaICylinderRadiusCmd;
	G4UIcmdWithADoubleAndUnit*	NaICylinderThicknessCmd;
	
	G4UIcmdWithAString*		NaICubeMatCmd;
	G4UIcmdWithADoubleAndUnit*	NaICubeDepthCmd;
	G4UIcmdWithADoubleAndUnit*	NaICubeThicknessCmd;
	
	G4UIcmdWithAString*		LaBrDetectorMatCmd;
	G4UIcmdWithADoubleAndUnit*	LaBrDetectorRadiusCmd;
	G4UIcmdWithADoubleAndUnit*	LaBrDetectorThicknessCmd;

////////////////////////////////////

    G4UIcmdWithADoubleAndUnit* DetectorSpacingCmd;
   
    G4UIcmdWithABool*          UseGeThickDetectorCmd;
    G4UIcmdWithABool*          UseGeThinDetectorCmd;
    
    G4UIcmdWithABool*		UseNaICylinderCmd; //MBB
    G4UIcmdWithABool*		UseNaICubeCmd; //MBB
    G4UIcmdWithABool*		UseLaBrDetectorCmd; //MBB
            
    
    G4UIcmdWithABool*          UseGeThickDetectorCryoCmd;
    G4UIcmdWithABool*          UseGeThickDetectorCryoEndCapCmd;
    G4UIcmdWithABool*          UseSegaCmd;
    G4UIcmdWithABool*          UseCloverCmd;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

