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

#include "p26DetectorMessenger.hh"

#include "p26DetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithABool.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

p26DetectorMessenger::p26DetectorMessenger(p26DetectorConstruction* myDet)
:myDetector(myDet)
{ 
  p26Dir = new G4UIdirectory("/p26/");
  p26Dir->SetGuidance("UI commands specific to this example.");
  
  detDir = new G4UIdirectory("/p26/det/");
  detDir->SetGuidance("detector control.");
  
  
  
  
  GeThickDetectorThicknessCmd = new G4UIcmdWithADoubleAndUnit("/p26/det/setGeThickDetectorThickness",this);
  GeThickDetectorThicknessCmd->SetGuidance("Set the Thick Ge Detector Thickness.");
  GeThickDetectorThicknessCmd->SetUnitCategory("Length");
  GeThickDetectorThicknessCmd->SetParameterName("choice",false);
  GeThickDetectorThicknessCmd->AvailableForStates(G4State_PreInit);

  GeThickDetectorRadiusCmd = new G4UIcmdWithADoubleAndUnit("/p26/det/setGeThickDetectorRadius",this);
  GeThickDetectorRadiusCmd->SetGuidance("Set the Thick Ge Detector Radius.");
  GeThickDetectorRadiusCmd->SetUnitCategory("Length");
  GeThickDetectorRadiusCmd->SetParameterName("choice",false);
  GeThickDetectorRadiusCmd->AvailableForStates(G4State_PreInit);
  
  GeThickDetectorMatCmd = new G4UIcmdWithAString("/p26/det/setGeThickDetectorMate",this);
  GeThickDetectorMatCmd->SetGuidance("Select Material of the Thick Ge Detector.");
  GeThickDetectorMatCmd->SetParameterName("choice",false);
  GeThickDetectorMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);  




  GeThinDetectorThicknessCmd = new G4UIcmdWithADoubleAndUnit("/p26/det/setGeThinDetectorThickness",this);
  GeThinDetectorThicknessCmd->SetGuidance("Set the Thin Ge Detector Thickness.");
  GeThinDetectorThicknessCmd->SetUnitCategory("Length");
  GeThinDetectorThicknessCmd->SetParameterName("choice",false);
  GeThinDetectorThicknessCmd->AvailableForStates(G4State_PreInit);

  GeThinDetectorRadiusCmd = new G4UIcmdWithADoubleAndUnit("/p26/det/setGeThinDetectorRadius",this);
  GeThinDetectorRadiusCmd->SetGuidance("Set the Thin Ge Detector Radius.");
  GeThinDetectorRadiusCmd->SetUnitCategory("Length");
  GeThinDetectorRadiusCmd->SetParameterName("choice",false);
  GeThinDetectorRadiusCmd->AvailableForStates(G4State_PreInit);
  
  GeThinDetectorMatCmd = new G4UIcmdWithAString("/p26/det/setGeThinDetectorMate",this);
  GeThinDetectorMatCmd->SetGuidance("Select Material of the Thin Ge Detector.");
  GeThinDetectorMatCmd->SetParameterName("choice",false);
  GeThinDetectorMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);  
  
  /////////MBB /////////////
  
  LaBrDetectorThicknessCmd = new G4UIcmdWithADoubleAndUnit("/p26/det/setLaBrDetectorThickness",this);
  LaBrDetectorThicknessCmd->SetGuidance("Set the LaBr Detector Thickness.");
  LaBrDetectorThicknessCmd->SetUnitCategory("Length");
  LaBrDetectorThicknessCmd->SetParameterName("choice",false);
  LaBrDetectorThicknessCmd->AvailableForStates(G4State_PreInit);

  LaBrDetectorRadiusCmd = new G4UIcmdWithADoubleAndUnit("/p26/det/setLaBrDetectorRadius",this);
  LaBrDetectorRadiusCmd->SetGuidance("Set the Thin LaBr Radius.");
  LaBrDetectorRadiusCmd->SetUnitCategory("Length");
  LaBrDetectorRadiusCmd->SetParameterName("choice",false);
  LaBrDetectorRadiusCmd->AvailableForStates(G4State_PreInit);
  
  LaBrDetectorMatCmd = new G4UIcmdWithAString("/p26/det/setLaBrDetectorMate",this);
  LaBrDetectorMatCmd->SetGuidance("Select Material of the LaBr Detector.");
  LaBrDetectorMatCmd->SetParameterName("choice",false);
  LaBrDetectorMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);  
  
  //////////////////////////
  
/////////// MBB ///////////////
// This stuff goes into the options you can set in the .mac file

  NaICylinderThicknessCmd = new G4UIcmdWithADoubleAndUnit("/p26/det/setNaICylinderThickness",this);
  NaICylinderThicknessCmd->SetGuidance("Set the NaI Cylinder Thickness.");
  NaICylinderThicknessCmd->SetUnitCategory("Length");
  NaICylinderThicknessCmd->SetParameterName("choice",false);
  NaICylinderThicknessCmd->AvailableForStates(G4State_PreInit);
  
  NaICylinderRadiusCmd = new G4UIcmdWithADoubleAndUnit("/p26/det/setNaICylinderRadius",this);
  NaICylinderRadiusCmd->SetGuidance("Set the NaI Cylinder Radius.");
  NaICylinderRadiusCmd->SetUnitCategory("Length");
  NaICylinderRadiusCmd->SetParameterName("choice",false);
  NaICylinderRadiusCmd->AvailableForStates(G4State_PreInit);
  
  NaICylinderMatCmd = new G4UIcmdWithAString("/p26/det/setNaICylinderMate",this);
  NaICylinderMatCmd->SetGuidance("Select Material of the NaI Cylinder.");
  NaICylinderMatCmd->SetParameterName("choice",false);
  NaICylinderMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  NaICubeThicknessCmd = new G4UIcmdWithADoubleAndUnit("/p26/det/setNaICubeThickness",this);
  NaICubeThicknessCmd->SetGuidance("Set the NaI Cube Thickness.");
  NaICubeThicknessCmd->SetUnitCategory("Length");
  NaICubeThicknessCmd->SetParameterName("choice",false);
  NaICubeThicknessCmd->AvailableForStates(G4State_PreInit);
  
  NaICubeDepthCmd = new G4UIcmdWithADoubleAndUnit("/p26/det/setNaICubeDepth",this);
  NaICubeDepthCmd->SetGuidance("Set the NaI Cube Depth.");
  NaICubeDepthCmd->SetUnitCategory("Length");
  NaICubeDepthCmd->SetParameterName("choice",false);
  NaICubeDepthCmd->AvailableForStates(G4State_PreInit);
  
  NaICubeMatCmd = new G4UIcmdWithAString("/p26/det/setNaICubeMate",this);
  NaICubeMatCmd->SetGuidance("Select Material of the NaI Cube.");
  NaICubeMatCmd->SetParameterName("choice",false);
  NaICubeMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

//////////////////////////////
   

  DetectorSpacingCmd = new G4UIcmdWithADoubleAndUnit("/p26/det/setDetectororSpacing",this);
  DetectorSpacingCmd->SetGuidance("Set the inter-Detector Spacing.");
  DetectorSpacingCmd->SetUnitCategory("Length");
  DetectorSpacingCmd->SetParameterName("choice",false);
  DetectorSpacingCmd->AvailableForStates(G4State_PreInit);

  UseGeThickDetectorCmd = new G4UIcmdWithABool("/p26/det/UseGeThickDetector",this);
  UseGeThickDetectorCmd->SetGuidance("activate the thick detector");
  UseGeThickDetectorCmd->SetParameterName("choice",false);
  UseGeThickDetectorCmd->AvailableForStates(G4State_PreInit);

  UseGeThinDetectorCmd = new G4UIcmdWithABool("/p26/det/UseGeThinDetector",this);
  UseGeThinDetectorCmd->SetGuidance("activate the thin detector");
  UseGeThinDetectorCmd->SetParameterName("choice",false);
  UseGeThinDetectorCmd->AvailableForStates(G4State_PreInit);
  
  

//////// MBB 16 Aug 2013 /////

	UseLaBrDetectorCmd = new G4UIcmdWithABool("/p26/det/UseLaBrDetector",this);
	UseLaBrDetectorCmd->SetGuidance("activate the LaBr detector");
	UseLaBrDetectorCmd->SetParameterName("choice",false);
	UseLaBrDetectorCmd->AvailableForStates(G4State_PreInit);
	
	UseNaICylinderCmd = new G4UIcmdWithABool("/p26/det/UseNaICylinder",this);
	UseNaICylinderCmd->SetGuidance("activate the sodium iodide cylinder");
	UseNaICylinderCmd->SetParameterName("choice",false);
	UseNaICylinderCmd->AvailableForStates(G4State_PreInit);
	
	UseNaICubeCmd = new G4UIcmdWithABool("/p26/det/UseNaICube",this);
	UseNaICubeCmd->SetGuidance("activate the sodium iodide cylinder");
	UseNaICubeCmd->SetParameterName("choice",false);
	UseNaICubeCmd->AvailableForStates(G4State_PreInit);

//////////////////////////////
  

  UseGeThickDetectorCryoCmd = new G4UIcmdWithABool("/p26/det/UseGeThickDetectorCryo",this);
  UseGeThickDetectorCryoCmd->SetGuidance("activate the thick detector Cryo");
  UseGeThickDetectorCryoCmd->SetParameterName("choice",false);
  UseGeThickDetectorCryoCmd->AvailableForStates(G4State_PreInit);

  UseGeThickDetectorCryoEndCapCmd = new G4UIcmdWithABool("/p26/det/UseGeThickDetectorCryoEndCap",this);
  UseGeThickDetectorCryoEndCapCmd->SetGuidance("activate the thick detectorCryo EndCap");
  UseGeThickDetectorCryoEndCapCmd->SetParameterName("choice",false);
  UseGeThickDetectorCryoEndCapCmd->AvailableForStates(G4State_PreInit);

  UseSegaCmd = new G4UIcmdWithABool("/p26/det/UseSega",this);
  UseSegaCmd->SetGuidance("activate Sega");
  UseSegaCmd->SetParameterName("choice",false);
  UseSegaCmd->AvailableForStates(G4State_PreInit);

  UseCloverCmd = new G4UIcmdWithABool("/p26/det/UseClover",this);
  UseCloverCmd->SetGuidance("activate Clover");
  UseCloverCmd->SetParameterName("choice",false);
  UseCloverCmd->AvailableForStates(G4State_PreInit);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

p26DetectorMessenger::~p26DetectorMessenger()
{
  delete GeThickDetectorMatCmd;
  delete GeThickDetectorRadiusCmd;
  delete GeThickDetectorThicknessCmd;
  delete GeThinDetectorMatCmd;
  delete GeThinDetectorRadiusCmd;
  delete GeThinDetectorThicknessCmd;
  
  delete LaBrDetectorMatCmd;
  delete LaBrDetectorRadiusCmd;
  delete LaBrDetectorThicknessCmd;
  
  delete NaICylinderMatCmd;		//MBB
  delete NaICylinderRadiusCmd;	//MBB
  delete NaICylinderThicknessCmd;	//MBB
  
  delete NaICubeMatCmd;		//MBB
  delete NaICubeDepthCmd;	//MBB
  delete NaICubeThicknessCmd;
  
  delete DetectorSpacingCmd;
  delete UseGeThickDetectorCmd;
  delete UseGeThinDetectorCmd;
  
  delete UseLaBrDetectorCmd; //MBB
  delete UseNaICylinderCmd;		//MBB
  delete UseNaICubeCmd; //MBB
  
  delete UseGeThickDetectorCryoCmd;
  delete UseGeThickDetectorCryoEndCapCmd;
  delete UseSegaCmd;
  delete UseCloverCmd;
  delete detDir;
  delete p26Dir;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void p26DetectorMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if ( command == GeThickDetectorRadiusCmd ) 
    { myDetector->setGeThickDetectorRadius(GeThickDetectorRadiusCmd->GetNewDoubleValue(newValue));}
    
  else if( command == GeThickDetectorMatCmd )
    { myDetector->setGeThickDetectorMaterial(newValue);} 
    
  else if (command == GeThickDetectorThicknessCmd ) 
    { myDetector->setGeThickDetectorThickness(GeThickDetectorThicknessCmd->GetNewDoubleValue(newValue));}
    
    
    
  else if ( command == GeThinDetectorRadiusCmd ) 
    { myDetector->setGeThinDetectorRadius(GeThinDetectorRadiusCmd->GetNewDoubleValue(newValue));}
    
  else if( command == GeThinDetectorMatCmd )
    { myDetector->setGeThinDetectorMaterial(newValue);} 
    
  else if (command == GeThinDetectorThicknessCmd ) 
    { myDetector->setGeThinDetectorThickness(GeThickDetectorThicknessCmd->GetNewDoubleValue(newValue));}
    
    
    
  else if ( command == LaBrDetectorRadiusCmd ) //MBB
    { myDetector->setLaBrDetectorRadius(LaBrDetectorRadiusCmd->GetNewDoubleValue(newValue));}
    
  else if( command == LaBrDetectorMatCmd ) //MBB
    { myDetector->setLaBrDetectorMaterial(newValue);} 
    
  else if (command == LaBrDetectorThicknessCmd ) //MBB
    { myDetector->setLaBrDetectorThickness(GeThickDetectorThicknessCmd->GetNewDoubleValue(newValue));}
    
    
    
  else if (command == DetectorSpacingCmd ) 
    { myDetector->setDetectorSpacing(DetectorSpacingCmd->GetNewDoubleValue(newValue));}
    
  else if (command == UseGeThickDetectorCmd ) 
    { myDetector->setUseGeThickDetector(UseGeThickDetectorCmd->GetNewBoolValue(newValue));}
  else if (command == UseGeThickDetectorCryoCmd ) 
    { myDetector->setUseGeThickDetectorCryo(UseGeThickDetectorCryoCmd->GetNewBoolValue(newValue));}
  else if (command == UseGeThickDetectorCryoEndCapCmd ) 
    { myDetector->setUseGeThickDetectorCryoEndCap(UseGeThickDetectorCryoEndCapCmd->GetNewBoolValue(newValue));}
  else if (command == UseGeThinDetectorCmd ) 
    { myDetector->setUseGeThinDetector(UseGeThinDetectorCmd->GetNewBoolValue(newValue));}
    
    
  else if (command == UseLaBrDetectorCmd ) //MBB
    { myDetector->setUseLaBrDetector(UseLaBrDetectorCmd->GetNewBoolValue(newValue));}
    
    
  else if (command == UseNaICylinderCmd ) //MBB
    { myDetector->setUseNaICylinder(UseNaICylinderCmd->GetNewBoolValue(newValue));} //MBB
    
    
  else if (command == UseNaICubeCmd ) //MBB
    { myDetector->setUseNaICube(UseNaICubeCmd->GetNewBoolValue(newValue));} //MBB
    
    
  else if (command == UseSegaCmd ) 
    { myDetector->setUseSega(UseSegaCmd->GetNewBoolValue(newValue));}
  else if (command == UseCloverCmd ) 
    { myDetector->setUseClover(UseCloverCmd->GetNewBoolValue(newValue));}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
