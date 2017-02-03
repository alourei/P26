//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
// Comments
//
//                  Underground Advanced
//               by A. Howard and H. Araujo 
//                    (27th November 2001)
//
// AnalysisExampleMessenger program
// --------------------------------------------------------------

#include "p26AnalysisExampleMessenger.hh"

#include "p26AnalysisExample.hh"
#include "p26EventActionMessenger.hh"

#include "globals.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithAString.hh"

p26AnalysisExampleMessenger::p26AnalysisExampleMessenger
   (p26AnalysisExample* SA):analysisexample(SA) {

     analysisDir = new G4UIdirectory("/p26/analysis/");
     analysisDir->SetGuidance("event control");

     trackparentCmd = new G4UIcmdWithAnInteger("/p26/analysis/trackparent",this);
     trackparentCmd->SetGuidance("Z of parent ion to be tracked");
     trackparentCmd->SetParameterName("parentZ",false);
     trackparentCmd->SetRange("parentZ>=0");
     trackparentCmd->AvailableForStates(G4State_Idle);

     trackdaughterCmd = new G4UIcmdWithAnInteger("/p26/analysis/trackdaughter",this);
     trackdaughterCmd->SetGuidance("Z of daughter ion to be tracked");
     trackdaughterCmd->SetParameterName("daughterZ",false);
     trackdaughterCmd->SetRange("daughterZ>=0");
     trackdaughterCmd->AvailableForStates(G4State_Idle);

     filenameCmd = new G4UIcmdWithAString("/p26/analysis/filename",this);
     filenameCmd->SetGuidance("Analysis file name");
     filenameCmd->SetParameterName("choice",false);
     filenameCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

     dirnameCmd = new G4UIcmdWithAString("/p26/analysis/dirname",this);
     dirnameCmd->SetGuidance("Directory for output files");
     dirnameCmd->SetParameterName("dirname",false);
     dirnameCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
}


//ooooooooooooooooooooooooooooooooooooooooo
p26AnalysisExampleMessenger::~p26AnalysisExampleMessenger() {

  delete trackparentCmd;
  delete trackdaughterCmd;
  delete filenameCmd;
  delete dirnameCmd;
}


//ooooooooooooooooooooooooooooooooooooooooo
void p26AnalysisExampleMessenger::SetNewValue(G4UIcommand* command, 
  G4String newValue) {

//   if(command == trackparentCmd)
//     analysisexample->SetparentZ(trackparentCmd->GetNewIntValue(newValue));

//    if(command == trackdaughterCmd)
//      analysisexample->SetdaughterZ(trackdaughterCmd->GetNewIntValue(newValue));

   if(command == filenameCmd)
     analysisexample->Setfilename(newValue);

   if(command == dirnameCmd)
     analysisexample->Setdirname(newValue);
}



