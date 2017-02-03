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
//
#include "p26DetectorROGeometry.hh"
#include "p26DummySD.hh"

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4SDManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4ThreeVector.hh"
#include "G4Material.hh"
 

p26DetectorROGeometry::p26DetectorROGeometry()
  : G4VReadOutGeometry()
{
//   G4double fDetectorThickness = 1.3* cm;
//   G4double fDetectorRadius = 0.5 * cm;
//   //fDetectorLength = 5.0 * cm;      
//   //fTargetLength  = 1.0 * cm;         
// //--------- Sizes of the principal geometrical components (solids)  ---------
//   G4double fWorldLength = fDetectorThickness + 1*cm;
//   G4double fWorldRadius = fDetectorRadius + 1.*cm;

  //#include "p26DetectorParameterDef.icc"
}


p26DetectorROGeometry::p26DetectorROGeometry(G4String aString)
  : G4VReadOutGeometry(aString)
{
  //#include "p26DetectorParameterDef.icc"
}

p26DetectorROGeometry::~p26DetectorROGeometry()
{
}

G4VPhysicalVolume* p26DetectorROGeometry::Build()
{
  G4double fDetectorThickness = 1.3* cm;
  G4double fDetectorRadius = 0.5 * cm;
  //fDetectorLength = 5.0 * cm;      
  //fTargetLength  = 1.0 * cm;         
//--------- Sizes of the principal geometrical components (solids)  ---------
  G4double fWorldLength = fDetectorThickness + 1*cm;
  G4double fWorldRadius = fDetectorRadius + 1.*cm;

  // A dummy material is used to fill the volumes of the readout geometry.
  // ( It will be allowed to set a NULL pointer in volumes of such virtual
  // division in future, since this material is irrelevant for tracking.)
  G4Material* dummyMat  = new G4Material(name="dummyMat", 1., 1.*g/mole, 1.*g/cm3);

  //Builds the ReadOut World:
  G4Tubs *ROWorldTubs = new G4Tubs("ROWorldTubs", 0,fWorldRadius,fWorldLength/2.,0.,twopi);
  G4LogicalVolume *ROWorldLog = new G4LogicalVolume(ROWorldTubs, dummyMat,
						    "ROWorldLogical", 0, 0, 0);
  G4PVPlacement *ROWorldPhys = new G4PVPlacement(0,G4ThreeVector(),
						 "ROWorldPhysical",
						 ROWorldLog,
						 0,false,0);
  // DSSD volume:
  G4VSolid * p26ROsol
    = new G4Tubs("p26RO",0,fDetectorRadius,fDetectorThickness/2.,0.,twopi);
  G4LogicalVolume * p26ROlog
    = new G4LogicalVolume(p26ROsol,dummyMat,"p26ROlogical",0,0,0);
  G4VPhysicalVolume * p26ROphys
    = new G4PVPlacement(0,G4ThreeVector(),"p26ROphysical",p26ROlog,
			ROWorldPhys,false,0);



  // DSSD readout pixels

//   //Flags the cells as sensitive .The pointer here serves
//   // as a flag only to check for sensitivity.
//   // (Could we make it by a simple cast of a non-NULL value ?)
  p26DummySD * dummySensi = new p26DummySD;
  p26ROlog->SetSensitiveDetector(dummySensi);
  
  return ROWorldPhys;
}
