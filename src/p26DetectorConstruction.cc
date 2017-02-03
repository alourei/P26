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
#include "p26DetectorConstruction.hh"
#include "p26DetectorMessenger.hh"
#include "p26DetectorSD.hh"
#include "p26AnalysisManager.hh"
#include "G4UImanager.hh"
#include "G4Tubs.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SDManager.hh"
#include "G4Region.hh"
#include "G4RegionStore.hh"
#include "G4RotationMatrix.hh"
#include "Materials.hh"

#include "p26Material.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4ios.hh"
#include <sstream>






//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
p26DetectorConstruction::p26DetectorConstruction()
:solidWorld(0),  logicWorld(0),  physiWorld(0),
 solidGeThickDetector(0),logicGeThickDetector(0),physiGeThickDetector(0), 
 solidGeThinDetector(0),logicGeThinDetector(0),physiGeThinDetector(0),
 solidLaBrDetector(0),logicLaBrDetector(0),physiLaBrDetector(0), //LaBr Detector -MBB
 solidNaICylinder(0),logicNaICylinder(0),physiNaICylinder(0), //NaI Cylinder MBB
 solidNaICube(0),logicNaICube(0),physiNaICube(0), //NaI Cube -MBB 27 Aug 2013
 
 //solidAlPlate(0),logicAlPlate(0),physiAlPlate(0), //Al Plate for Implant and use w LaBr -- actually we might be able to
 // just make the Al plate a part of the LaBr detector geometry... maybe it's not ideal to make it its own detector.
  
 GeThickDetectorMater(0), GeThinDetectorMater(0), LaBrDetectorMater(0),
 NaICylinderMater(0), NaICubeMater(0), fWorldLength(0) //AlPlateMater(0),
{
	detectorMessenger = new p26DetectorMessenger(this);
	DefineMaterials();

	fGeThickDetectorThickness = 20.00*cm;//0.09*cm; // 2.0*cm; //Hiro's detector
	fGeThinDetectorThickness = 38.1*mm;
	fGeThickDetectorRadius = 2.935*cm;//4.5*cm; // 3.0 * cm; //3.0*cm;Hiro's detector
	fGeThinDetectorRadius = 19.05*mm;
	fSpacing = 5*mm;
	
	fLaBrDetectorThickness = 38.1*mm;  //ostensibly the thickness and radius of the LaBr crystal
	fLaBrDetectorRadius = 19.05*mm;
	
	
	fNaICylinderThickness = 25.00*mm; //height of cylindrical NaI scintillator from Oscar's document
	fNaICylinderRadius = 12.5*mm; // radius of 25-mm-diameter NaI scintillator from Oscar's document
	
	fNaICubeThickness = 25.00*mm; // length of an edge on the face of the NaI cube scintillator
	fNaICubeDepth = 38.00*mm; // depth (z-axis length) of the NaI cube.

	fUseGeThinDetector = false;
	fUseGeThickDetector= true;
	fUseGeThickDetectorCryo= false;
	fUseGeThickDetectorCryoEndCap= false;
	fUseSega = false;
	fUseClover = false;
	fUseNaICylinder = false; //added 16 Aug 2013 MBB
	fUseNaICube = false;
	fUseLaBrDetector = false;


	//--------- Sizes of the principal geometrical components (solids)  ---------
	fWorldLength = fGeThickDetectorThickness + 50*cm;
	fWorldRadius = fGeThickDetectorRadius + 50.*cm;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......










//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
p26DetectorConstruction::~p26DetectorConstruction()
{
	delete detectorMessenger;             
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......












//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void p26DetectorConstruction::DefineMaterials()
{
	//--------- Material definition ---------

	//   Materials* set_of_materials = new Materials();

	//   // define all the materials
	//   set_of_materials->defineAllMaterials();




	materialsManager = new p26Material();
	
	//   //Lead
	//   materialsManager->AddMaterial("Lead","Pb",11.3*g/cm3,"");
	//   //Germanium detector
	//   materialsManager->AddMaterial("Germanium","Ge",5.323*g/cm3,""); 
	//   //CsI
	//   materialsManager->AddMaterial("CsI","Cs-I",4.51*g/cm3,"");
	//   //Be
	//   materialsManager->AddMaterial("Beryllium","Be",1.85*g/cm3,"");
	//   //Si
	//   materialsManager->AddMaterial("Silicon","Si",2.33*g/cm3,"");


	G4cout << G4endl << "The materials defined are : " << G4endl << G4endl;
	G4cout << *(G4Material::GetMaterialTable()) << G4endl;
	  
	DefaultMater = materialsManager->GetMaterial("Air");
	//TargetMater  = materialsManager->GetMaterial("CsI");
	GeThickDetectorMater = materialsManager->GetMaterial("Ge");
	GeThinDetectorMater = materialsManager->GetMaterial("Ge"); //Marco?
	
	LaBrDetectorMater = materialsManager->GetMaterial("LanthanumBromide"); //Marco?
	GeThickDetectorCryoMater = materialsManager->GetMaterial("Al");
	SegaMater = materialsManager->GetMaterial("Ge");
	SegaCryoMater = materialsManager->GetMaterial("Al");
	SegaVacuumMater = materialsManager->GetMaterial("vacuum");
	CloverCrystalMater = materialsManager->GetMaterial("Ge");
	CloverCryoMater = materialsManager->GetMaterial("Al");
	VacuumMater = materialsManager->GetMaterial("vacuum");
	BCSdssdMater = materialsManager->GetMaterial("Si");
	
	NaICylinderMater = materialsManager->GetMaterial("SodiumIodide"); //added 15 Aug 2013 MBB
	NaICubeMater = materialsManager->GetMaterial("SodiumIodide");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......











//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
G4VPhysicalVolume* p26DetectorConstruction::Construct()
{
	//--------- Definitions of Solids, Logical Volumes, Physical Volumes ---------
	//--------- Sizes of the principal geometrical components (solids)  ---------

	fWorldLength = fGeThickDetectorThickness + 400*cm;
	fWorldRadius = fGeThickDetectorRadius + 1500.*cm;
	 
	//------------------------------ 
	// World
	//------------------------------ 

	solidWorld= new G4Tubs("world",0.,fWorldRadius,fWorldLength/2.,0.,twopi);
	logicWorld= new G4LogicalVolume( solidWorld, DefaultMater, "World", 0, 0, 0);
	
	//  Must place the World Physical volume unrotated at (0,0,0).
	// 
	physiWorld = new G4PVPlacement(0,               // no rotation
	                               G4ThreeVector(), // at (0,0,0)
	                               logicWorld,      // its logical volume
				 "World",         // its name
	                               0,               // its mother  volume
	                               false,           // no boolean operations
	                               0);              // no field specific to volume




	// using tigress ----------
//   G4SDManager *SDman = G4SDManager::GetSDMpointer();
//   DetectionSystemTigress *myTigress = new DetectionSystemTigress(SDman,12,0,false);
//   myTigress->Build(logicWorld);
	// ------------------------

	

				 
	//------------------------------
	// Ge Double Sided Strip Detector
	// There are two GeDSSD in the simulation
	// One is a thick 1.5 cm detector
	// the second is a thin 1.5 mm detector
	// The thick detector will be used to determine
	// the ease of detecting an impanted ion and decay
	// in the same detector.
	// If it proves too difficult a thin implantation Ge detector
	// can be used in front of the thick detector.
	//------------------------------

	//------------------------------ 
	// Ge Double Sided Strip Detector
	// create the thick Ge detector
	// pixelation will occur during at end of event during sensitive detector readout
	//------------------------------
	
	//position of the thin detector is in front of the thick detector
	//fGeThinDetectorPos = G4ThreeVector(0,0,-(fGeThickDetectorThickness/2.)-(fGeThinDetectorThickness/2.)-fSpacing);
	fGeThinDetectorPos = G4ThreeVector(0,0,-(fGeThinDetectorThickness/2)-2.5*mm);
			
	//-(fGeThickDetectorThickness/2.)-(fGeThinDetectorThickness/2.)-fSpacing);
	
	solidGeThinDetector = new G4Tubs("GeThinDetectorCrystal",0,fGeThinDetectorRadius,fGeThinDetectorThickness/2.,0.,twopi);
	logicGeThinDetector = new G4LogicalVolume(solidGeThinDetector ,GeThinDetectorMater, "GeThinDetectorCrystal",0,0,0);  


	fLaBrDetectorPos = G4ThreeVector(0,0,-(fLaBrDetectorThickness/2)-2.5*mm);
	solidLaBrDetector = new G4Tubs("LaBrDetectorCrystal",0,fLaBrDetectorRadius,fLaBrDetectorThickness/2.,0.,twopi);
	logicLaBrDetector = new G4LogicalVolume(solidLaBrDetector, LaBrDetectorMater, "LaBrDetectorCrystal",0,0,0); 


	//cylinder
	fNaICylinderPos = G4ThreeVector(0,0,(fNaICylinderThickness/2)-2.4*mm); // We actually want the ions implanted INTO the NaI by about 2.4 mm (according to LISE) MBB
	
	solidNaICylinder = new G4Box("NaICylinderCrystal",(fNaICubeThickness/2),(fNaICubeThickness/2),(fNaICubeDepth/2));
	// trying to just change the cylinder to a cube
	//solidNaICylinder = new G4Tubs("NaICylinderCrystal",0,fNaICylinderRadius,fNaICylinderThickness/2.0,0.,twopi); //MBB
	logicNaICylinder = new G4LogicalVolume(solidNaICylinder ,NaICylinderMater, "NaICylinderCrystal",0,0,0); //MBB
	
	//For now I'm just toggling between the cylinder and the Cube here.  If it becomes a big deal I'll recreate
	// the Cube as well as the cylinder.
	
	//Cube
	fNaICubePos = G4ThreeVector(0,0,0);
	//solidNaICube = new G4Box("NaICubeCrystal",(fNaICubeThickness/2),(fNaICubeThickness/2),(fNaICubeDepth/2)); // MBB
	solidNaICube = new G4Tubs("NaICubeCrystal",0,(fNaICubeThickness/2),fNaICubeDepth/2.0,0.,twopi); //MBB For testing..
	logicNaICube = new G4LogicalVolume(solidNaICube, NaICubeMater, "NaICubeCrystal",0,0,0); //MBB
	
		
	
	////




	fGeThickDetectorCryoPos = G4ThreeVector(0,0,0);
	fGeThickDetectorCryoOutRad = 9.6393*cm; //diagram from Ethan
	fGeThickDetectorCryoInnRad = 7.0*cm; //estimated from Ethan's diagram (in worst case cryo is thick solid Al)
	fGeThickDetectorCryoThickness = 6.35*cm;//estimated from Ethan's digram // 3.0 cm used for p26non
	solidGeThickDetectorCryo = new G4Tubs("GeThickDetectorCryo",fGeThickDetectorCryoInnRad,fGeThickDetectorCryoOutRad,
					fGeThickDetectorCryoThickness/2.,0.,twopi);
	logicGeThickDetectorCryo = new G4LogicalVolume(solidGeThickDetectorCryo,GeThickDetectorCryoMater,
						 "GeThickDetectorCryo",0,0,0);
	fGeCryoEndCapOutRad = fGeThickDetectorCryoInnRad;
	fGeCryoEndCapThickness = 0.5*mm; //use 0.1 cm for p26non

	fGeCryoEndCapPos1 = G4ThreeVector(0,0,fGeThickDetectorCryoThickness/2. - fGeCryoEndCapThickness/2.);
	fGeCryoEndCapPos2 = G4ThreeVector(0,0,-fGeThickDetectorCryoThickness/2. + fGeCryoEndCapThickness/2.);

	solidGeCryoEndCap = new G4Tubs("GeCryoEndCap",0.,fGeCryoEndCapOutRad,fGeCryoEndCapThickness/2.,0.,twopi);
	logicGeCryoEndCap = new G4LogicalVolume(solidGeCryoEndCap,GeThickDetectorCryoMater,"GeCryoEndCap",0,0,0);

	//only place the detector in the world if the user has interactively requested it
	if(fUseGeThinDetector){
	  physiGeThinDetector = new G4PVPlacement(0,              // no rotation
					    fGeThinDetectorPos, // at (x,y,z)
					    logicGeThinDetector,    // its logical volume				  
					    "GeThinDetector",       // its name
	            logicWorld,
//					    logicGeThickDetectorCryo,      // its mother  volume
					    false,           // no boolean operations
					    0);              // no particular field 
					
	}
	

////MBB/////
	if(fUseNaICylinder)
	{
		physiNaICylinder = new G4PVPlacement(0,	// no rotation
						fNaICylinderPos,	// at the detector's logical position
						logicNaICylinder,	// its logical volume
						"NaICylinder",	// its name!
						logicWorld,		// mother volume.  Just put the thing in the world for now
						false,		// no booleans
						0);			// no particular field
	}
	
	
	if(fUseLaBrDetector){
	  physiLaBrDetector = new G4PVPlacement(0,              // no rotation
					    fLaBrDetectorPos, // at (x,y,z)
					    logicLaBrDetector,    // its logical volume				  
					    "LaBrDetector",       // its name
	            logicWorld,
//					    logicGeThickDetectorCryo,      // its mother  volume
					    false,           // no boolean operations
					    0);              // no particular field 
					
	}
	
	
	if(fUseNaICube)
	{
		physiNaICube = new G4PVPlacement(0,	// no rotation
						fNaICubePos,	// at the detector's logical position
						logicNaICube,	// its logical volume
						"NaICube",	// its name!
						logicWorld,		// mother volume.  Just put the thing in the world for now
						false,		// no booleans
						0);			// no particular field
	}
	
	
	
	
////////////



	if(fUseGeThickDetectorCryoEndCap){
	  physiGeCryoEndCap = new G4PVPlacement(0,
					  fGeCryoEndCapPos1,
					  logicGeCryoEndCap,
					  "GeCryoEndCap",
					  logicGeThickDetectorCryo,
					  false,
					  0);
	  physiGeCryoEndCap = new G4PVPlacement(0,
					  fGeCryoEndCapPos2,
					  logicGeCryoEndCap,
					  "GeCryoEndCap",
					  logicGeThickDetectorCryo,
					  false,
					  1);
	}

	//position of thick detector is at origin of world
	fGeThickDetectorPos = G4ThreeVector(0,0,0);
	
	solidGeThickDetector = new G4Tubs("GeThickDetector",0,fGeThickDetectorRadius,fGeThickDetectorThickness/2.,0.,twopi);
	logicGeThickDetector = new G4LogicalVolume(solidGeThickDetector ,GeThickDetectorMater, "GeThickDetector",0,0,0);  
	//only place the detector in the world if the user has interactively requested it
	if(fUseGeThickDetector){
	  physiGeThickDetector = new G4PVPlacement(0,              // no rotation
					     fGeThickDetectorPos, // at (x,y,z)
					     logicGeThickDetector,    // its logical volume				  
					     "GeThickDetector",       // its name
					     logicWorld/*GeThickDetectorCryo*/,      // its mother  volume
					     false,           // no boolean operations
					     0);              // no particular field 
	}

	if(fUseGeThickDetectorCryo){
	  physiGeThickDetectorCryo = new G4PVPlacement(0,
						 fGeThickDetectorCryoPos,
						 logicGeThickDetectorCryo,
						 "GeThickDetectorCryo",
						 logicWorld,
						 false,
						 0);
	}

  //creation of BCS beam pipe
  solidBCSpipe = new G4Tubs("BCSpipe",0,7.62*cm,50.8*cm/2.,0., twopi);
  logicBCSpipe = new G4LogicalVolume(solidBCSpipe,SegaCryoMater,"BCSpipe",0,0,0);
  //physiBCSpipe = new G4PVPlacement(0,
				   // G4ThreeVector(0,0,0),
				   // logicBCSpipe,
				   // "BCSpipe",
				   // logicWorld,
				   // false,
				   // 0);
  //creation of BCS beam vac
  solidBCSvac = new G4Tubs("BCSvac",0,7.47*cm,50.8*cm/2.,0., twopi);
  logicBCSvac = new G4LogicalVolume(solidBCSvac,SegaVacuumMater,"BCSvac",0,0,0);
//physiBCSvac = new G4PVPlacement(0,
				   // G4ThreeVector(0,0,0),
				   // logicBCSvac,
				   // "BCSvac",
				   // logicBCSpipe,
				   // false,
				   // 0);

  // creation of BCS detector
  solidBCSdssd = new G4Box("BCSdssd",4.*cm/2, 4.*cm/2., 1.*cm/2.);
  //solidBCSdssd = new G4Tubs("BCSdssd",0 , 1.*cm , 0.05*cm , 0. , twopi);
  logicBCSdssd = new G4LogicalVolume(solidBCSdssd,BCSdssdMater,"BCSdssd",0,0,0);
//physiBCSdssd = new G4PVPlacement(0,
				   // G4ThreeVector(0,0,0),
				   // logicBCSdssd,
				   // "BCSdssd",
				   // logicWorld,
				   // false,
				   // 0);



	// creation of the SeGA detectors.  From outside to inside the SeGA detector consists of a cryostat
	// followed by a vacuum region, detector holder, vacuum region, crystal, active area of the crystal, and central contact.
	// All positions and thickness are derived from PFM MCNP input file
	fsegacryolength = 8.56*cm;
	fsegacryothick  = 0.15*cm; 
	fsegacryooutrad = 4.35*cm;
	G4cout << " radius " << fsegacryooutrad << G4endl;
	solidSegaCryo = new G4Tubs("SegaCryo",0,fsegacryooutrad,fsegacryolength/2. + 0.05*mm,0.,twopi);
	logicSegaCryo = new G4LogicalVolume(solidSegaCryo,SegaCryoMater,"SegaCryo",0,0,0);

	fsegavac2length = 8.5*cm;
	fsegavac2thick = 0.485*cm;
	G4double foutrad = fsegacryooutrad - fsegacryothick;
	G4cout << " radius1 " << foutrad << G4endl;
	fSegaVac2Pos = G4ThreeVector(0,0,-(fsegacryolength/2. - fsegavac2length/2.));
	solidSegaVac2 = new G4Tubs("SegaVac2",0,foutrad,fsegavac2length/2.,0.,twopi);
	logicSegaVac2 = new G4LogicalVolume(solidSegaVac2,SegaVacuumMater,"SegaVac2",0,0,0);
	physiSegaVac2 = new G4PVPlacement(0,
				    fSegaVac2Pos,
				    logicSegaVac2,
				    "SegaVac2",
				    logicSegaCryo,
				    false,
				    0);

	fsegadetcuplength = 8.1*cm;
	fsegadetcupthick = 0.098*cm;
	foutrad = foutrad - fsegavac2thick;
	G4cout << " radius2 " << foutrad << G4endl;
	fSegaDetCupPos = G4ThreeVector(0,0,-(fsegavac2length/2. - fsegadetcuplength/2.));
	solidSegaDetCup = new G4Tubs("SegaDetCup",0,foutrad,fsegadetcuplength/2.,0.,twopi);
	logicSegaDetCup = new G4LogicalVolume(solidSegaDetCup,SegaCryoMater,"SegaDetCup",0,0,0);
	physiSegaDetCup = new G4PVPlacement(0,
				      fSegaDetCupPos,
				      logicSegaDetCup,
				      "SegaDetCup",
				      logicSegaVac2,
				      false,
				      0);

	fsegavac1length = 8.0*cm;
	fsegavac1thick = 0.152*cm;
	foutrad = foutrad - fsegadetcupthick;
	G4cout << " radius3 " << foutrad << G4endl;
	fSegaVac1Pos = G4ThreeVector(0,0,-(fsegadetcuplength/2. - fsegavac1length/2.));
	solidSegaVac1 = new G4Tubs("SegaVac1",0,foutrad,fsegavac1length/2.,0.,twopi);
	logicSegaVac1 = new G4LogicalVolume(solidSegaVac1,SegaVacuumMater,"SegaVac1",0,0,0);
	physiSegaVac1 = new G4PVPlacement(0,
				    fSegaVac1Pos,
				    logicSegaVac1,
				    "SegaVac1",
				    logicSegaDetCup,
				    false,
				    0);

	fsegacrystallength = 8.0*cm;
	fsegacrystalthick = 0.1*cm;
	foutrad = foutrad - fsegavac1thick;
	G4cout << " radius4 " << foutrad << G4endl;
	fSegaCrystalPos = G4ThreeVector(0,0,-(fsegavac1length/2. - fsegacrystallength/2.));
	solidSegaCrystal = new G4Tubs("SegaCrystal",0,foutrad,fsegacrystallength/2.,0.,twopi);
	logicSegaCrystal = new G4LogicalVolume(solidSegaCrystal,SegaMater,"SegaCrystal",0,0,0);
	physiSegaCrystal = new G4PVPlacement(0,
				       fSegaCrystalPos,
				       logicSegaCrystal,
				       "SegaCrystal",
				       logicSegaVac1,
				       false,
				       0);

	fsegaactivelength = 7.9*cm;
	fsegaactivethick = 2.865*cm;
	foutrad = foutrad - fsegacrystalthick;
	G4cout << " radius5 " << foutrad << G4endl;
	fSegaActivePos = G4ThreeVector(0,0,-(fsegacrystallength/2. - fsegaactivelength/2.));
	solidSegaActiveArea = new G4Tubs("SegaActiveArea",0,foutrad,fsegaactivelength/2.,0.,twopi);
	logicSegaActiveArea = new G4LogicalVolume(solidSegaActiveArea,SegaMater,"SegaActiveArea",0,0,0);
	physiSegaActiveArea = new G4PVPlacement(0,
					  fSegaActivePos,
					  logicSegaActiveArea,
					  "SegaActiveArea",
					  logicSegaCrystal,
					  false,
					  0);
 
	fsegacentralconlength = 7.0*cm;
	fsegacentralconthick = 0.5*cm;
	foutrad = foutrad - fsegaactivethick;
	G4cout << " radius6 " << foutrad << G4endl;
	fSegaCentralConPos = G4ThreeVector(0,0,-(fsegaactivelength/2. - fsegacentralconlength/2.));
	solidSegaCentralCon = new G4Tubs("SegaCentralCon",0,foutrad,fsegacentralconlength/2.,0.,twopi);
	logicSegaCentralCon = new G4LogicalVolume(solidSegaCentralCon,SegaVacuumMater,"SegaCentralCon",0,0,0);
	physiSegaCentralCon = new G4PVPlacement(0,
					  fSegaCentralConPos,
					  logicSegaCentralCon,
					  "SegaCentralCon",
					  logicSegaActiveArea,
					  false,
					  0);

	//place Sega detectors into a ring around GeDSSD if requested by user
	if(fUseSega){

	  //BCS mode nsega = 8, radius = fGeThickDetectorRadius + fsegacryooutrad+7.8cm, fSegazpos = fsegacryolength/2.+0.5mm
	  //90mm ge - nsega = 6, radius = fsegacryooutrad + fsegacryooutrad + 0.5cm, fSegazpos= fsegacryolength/2.+4cm
	  

	  G4int nsega = 8;
	  G4double dtheta = twopi/nsega;
	  G4double theta = 0;
	  G4double radius = fGeThickDetectorRadius + fsegacryooutrad + 4.25*cm; // for BCS mode
	    //fGeThickDetectorRadius + fsegacryooutrad + 1.0*cm;  //use 1.5 for 60 mm detector with 13th Ge, use 0.55 without 13th, use 1 *cm with 90 mm detecotr and 6 sega
	  for(G4int n=0; n < nsega; n++){
	    
	    theta = dtheta * n;
	    G4double fSegaxpos = radius*cos(theta);
	    G4double fSegaypos = radius*sin(theta); 
	    G4double fSegazpos = fsegacryolength/2. + 4.0*cm; //8.0*cm; // use 8 cm for planar Ge
	    G4RotationMatrix *rotatesega = new G4RotationMatrix();
	    rotatesega->rotateX(180.*deg);
	    physiSegaCryo = new G4PVPlacement(rotatesega,
					G4ThreeVector(fSegaxpos,fSegaypos,fSegazpos),
					logicSegaCryo,
					"SegaCryo",
					logicWorld,
					false,
					n);
	  }

	  for(G4int n=nsega; n < nsega+nsega; n++){
	    
	    theta = dtheta * (n-nsega);
	    G4double fSegaxpos = radius*cos(theta);
	    G4double fSegaypos = radius*sin(theta); 
	    G4double fSegazpos = -fsegacryolength/2. - 4*cm; // use  -fsegacryolength/2. - 0.5*mm for BCS //use -8 cm for planar Ge
	    physiSegaCryo = new G4PVPlacement(0,
					G4ThreeVector(fSegaxpos,fSegaypos,fSegazpos),
					logicSegaCryo,
					"SegaCryo",
					logicWorld,
					false,
					n);
	  }
	

//   G4double fSegaxpos = 0;
//   G4double fSegaypos = 0; 
//   G4double fSegazpos = -8.0*cm; 
//   physiSegaCryo = new G4PVPlacement(0,
// 				    G4ThreeVector(fSegaxpos,fSegaypos,fSegazpos),
// 				    logicSegaCryo,
// 				    "SegaCryo",
// 				    logicWorld,
// 				    false,
// 				    12);
	}


	//---------------------
	// Creation of a compact clover array

	// base clover geometry on detectors from Yale 

	// length - , width - , height - ,

	// Cryostat will be a simple shell of Al 2 mm thick all around sides of detector and 1 mm in front
	G4cout << " TIGRESS1 " << G4endl;

	G4double CloverCrystalLength = 80.0*mm;
	//G4double CloverCrystalRadius = 25.0*mm; //union of cylinder and box geom
	G4double CloverCrystalRadius = 22.5*mm; // simple cyclinder geom

	// A clover crystal will be constructed from two boolean solids.
	// Boolean1 will be a large simple cylinder of Ge
	// Boolean2 will be a retangular box
	// The crystal will be constructed from the intersection of the cylinder with the box providing a cylinder with flat edges.

	//start Clover construction with a simple cylinder
	solidCloverBool1 = new G4Tubs("CloverBool1",0,CloverCrystalRadius,CloverCrystalLength/2.,0,twopi);
	
	// continue with box
	G4double CloverCrystalBoxx = 45.*mm;
	G4double CloverCrystalBoxy = 45.*mm;
	G4double CloverCrystalBoxz = CloverCrystalLength;
	solidCloverBool2 = new G4Box("CloverBool2",CloverCrystalBoxx/2.,CloverCrystalBoxy/2.,CloverCrystalBoxz/2.);

	//solidCloverCrystal = new G4IntersectionSolid("CloverCrystal",solidCloverBool2,solidCloverBool1);


	//per V.W. clover is  a collection of simple cylinders not as drawn on documentation
	solidCloverCrystal = new G4Tubs("",0,CloverCrystalRadius,CloverCrystalLength/2.,0,twopi);
	logicCloverCrystal = new G4LogicalVolume(solidCloverCrystal,CloverCrystalMater,"CloverCrystal",0,0,0);

	// create the central core
	G4double CloverCoreRadius = 5.0*mm;
	G4double CloverCoreLength = CloverCrystalLength;
	solidCloverCore = new G4Tubs("CloverCore",0,CloverCoreRadius,CloverCoreLength/2.,0,twopi);
	logicCloverCore = new G4LogicalVolume(solidCloverCore,VacuumMater,"CloverCore",0,0,0);
	G4ThreeVector CloverCorePos = G4ThreeVector(0,0,0);
	physiCloverCore = new G4PVPlacement(0,
				      CloverCorePos,
				      logicCloverCore,
				      "CloverCore",
				      logicCloverCrystal,
				      false,
				      0);

	//create clover cryostat
	G4double CloverCryox = 101.0*mm;
	G4double CloverCryoy = 101.0*mm;
	G4double CloverCryoz = CloverCrystalLength + 20.0*mm;

	solidCloverCryo = new G4Box("CloverCryo",CloverCryox/2.,CloverCryoy/2.,CloverCryoz/2.);
	logicCloverCryo = new G4LogicalVolume(solidCloverCryo,CloverCryoMater, "CloverCryo",0,0,0);

	//create interior vacuum region in cryostat.  Assume wall thickness of 2mm Al for sides and 1 mm Al for face
	G4double CloverCryoVacx = CloverCryox - 4.0*mm;
	G4double CloverCryoVacy = CloverCryoy - 4.0*mm;
	G4double CloverCryoVacz = CloverCryoz - 2.0*mm;
	
	solidCloverCryoVac = new G4Box("CloverCryoVac",CloverCryoVacx/2.,CloverCryoVacy/2.,CloverCryoVacz/2.);
	logicCloverCryoVac = new G4LogicalVolume(solidCloverCryoVac,VacuumMater,"CloverCryoVac",0,0,0);

	//place the vacuum into the cryostat
	CloverCryoVacuumPos = G4ThreeVector(0,0,0);
	physiCloverCryoVac = new G4PVPlacement(0,
					 CloverCryoVacuumPos,
					 logicCloverCryoVac,
					 "CloverCryoVac",
					 logicCloverCryo,
					 false,
					 0);

	//place four crystals into the vacuum region of the cryostat
	CloverCrystalPos = G4ThreeVector(CloverCrystalBoxx/2., CloverCrystalBoxy/2.,0);
	physiCloverCrystal = new G4PVPlacement(0,
					 CloverCrystalPos,
					 logicCloverCrystal,
					 "CloverCrystal",
					 logicCloverCryoVac,
					 false,
					 0);

	CloverCrystalPos = G4ThreeVector(-CloverCrystalBoxx/2., CloverCrystalBoxy/2.,0);
	physiCloverCrystal = new G4PVPlacement(0,
					 CloverCrystalPos,
					 logicCloverCrystal,
					 "CloverCrystal",
					 logicCloverCryoVac,
					 false,
					 1);

	CloverCrystalPos = G4ThreeVector(-CloverCrystalBoxx/2., -CloverCrystalBoxy/2.,0);
	physiCloverCrystal = new G4PVPlacement(0,
					 CloverCrystalPos,
					 logicCloverCrystal,
					 "CloverCrystal",
					 logicCloverCryoVac,
					 false,
					 2);

	CloverCrystalPos = G4ThreeVector(CloverCrystalBoxx/2., -CloverCrystalBoxy/2.,0);
	physiCloverCrystal = new G4PVPlacement(0,
					 CloverCrystalPos,
					 logicCloverCrystal,
					 "CloverCrystal",
					 logicCloverCryoVac,
					 false,
					 3);



	G4cout << " TIGRESS2 " << G4endl;

	
	if(fUseClover)
	{

	  //place nine clover detectors around the GeDSSD

	  //G4RotationMatrix *rotatetemp = new G4RotationMatrix();
	  //rotatetemp->rotateY(90.*deg);

	  
	  // first clover directly behind the GeDSSD
	  CloverCryoPos = G4ThreeVector(0,0,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.5*cm);
	  //CloverCryoPos = G4ThreeVector(CloverCryox/2.,CloverCryoy/2.,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.5*cm);
	  physiCloverCryo = new G4PVPlacement(0,
					CloverCryoPos,
					logicCloverCryo,
					"CloverCryo",
					logicWorld,
					false,
					0);



	  /**** cross ****/
	  G4RotationMatrix *rotateCloverx = new G4RotationMatrix();
	  rotateCloverx->rotateX(90.*deg);
	  G4RotationMatrix *rotateClovery = new G4RotationMatrix();
	  rotateClovery->rotateY(90.*deg);
	  
	  CloverCryoPos = G4ThreeVector(0,CloverCryoy/2.+ CloverCryoz/2.,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm);
	  physiCloverCryo = new G4PVPlacement(rotateCloverx,
					 CloverCryoPos,
					 logicCloverCryo,
					 "CloverCryo",
					 logicWorld,
					 false,
					 1);

	  CloverCryoPos = G4ThreeVector(0,-CloverCryoy/2.- CloverCryoz/2.,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm);
	  physiCloverCryo = new G4PVPlacement(rotateCloverx,
					 CloverCryoPos,
					 logicCloverCryo,
					 "CloverCryo",
					 logicWorld,
					 false,
					 3);
 
	  CloverCryoPos = G4ThreeVector(CloverCryox/2.+ CloverCryoz/2.,0,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm);
	  physiCloverCryo = new G4PVPlacement(rotateClovery,
					 CloverCryoPos,
					 logicCloverCryo,
					 "CloverCryo",
					 logicWorld,
					 false,
					 2);

	  CloverCryoPos = G4ThreeVector(-CloverCryox/2.-CloverCryoz/2.,0,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm);
	  physiCloverCryo = new G4PVPlacement(rotateClovery,
					 CloverCryoPos,
					 logicCloverCryo,
					 "CloverCryo",
					 logicWorld,
					 false,
					 4);
	  /**** end cross ****/  


	  CloverCryoPos = G4ThreeVector(0,CloverCryoy/2.+ CloverCryoz/2.+1*mm,-(CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm));
	  physiCloverCryo = new G4PVPlacement(rotateCloverx,
					 CloverCryoPos,
					 logicCloverCryo,
					 "CloverCryo",
					 logicWorld,
					 false,
					 5);

	  CloverCryoPos = G4ThreeVector(0,-CloverCryoy/2.- CloverCryoz/2.-1*mm,-(CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm));
	  physiCloverCryo = new G4PVPlacement(rotateCloverx,
					 CloverCryoPos,
					 logicCloverCryo,
					 "CloverCryo",
					 logicWorld,
					 false,
					 7);
 
	  CloverCryoPos = G4ThreeVector(2.*cm + CloverCryoz/2.,0,-(CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm));
	  physiCloverCryo = new G4PVPlacement(rotateClovery,
					 CloverCryoPos,
					 logicCloverCryo,
					 "CloverCryo",
					 logicWorld,
					 false,
					 6);

	  CloverCryoPos = G4ThreeVector(-2.*cm - CloverCryoz/2.,0,-(CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm));
	  physiCloverCryo = new G4PVPlacement(rotateClovery,
					 CloverCryoPos,
					 logicCloverCryo,
					 "CloverCryo",
					 logicWorld,
					 false,
					 8);
					 
					 
					 
	  //squared geometry
//     CloverCryoPos = G4ThreeVector(-CloverCryox/2.,CloverCryoy/2.,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.5*cm);
//     physiCloverCryo = new G4PVPlacement(0,
// 					 CloverCryoPos,
// 					 logicCloverCryo,
// 					 "CloverCryo",
// 					 logicWorld,
// 					 false,
// 					 1);

//     CloverCryoPos = G4ThreeVector(-CloverCryox/2.,-CloverCryoy/2.,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.5*cm);
//     physiCloverCryo = new G4PVPlacement(0,
// 					 CloverCryoPos,
// 					 logicCloverCryo,
// 					 "CloverCryo",
// 					 logicWorld,
// 					 false,
// 					 3);
 
//     CloverCryoPos = G4ThreeVector(CloverCryox/2.,-CloverCryoy/2.,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.5*cm);
//     physiCloverCryo = new G4PVPlacement(0,
// 					 CloverCryoPos,
// 					 logicCloverCryo,
// 					 "CloverCryo",
// 					 logicWorld,
// 					 false,
// 					 2);
	  //end square geometry

//     /**** explode geometry ****/
//     G4RotationMatrix *rotateCloverex1 = new G4RotationMatrix();
//     rotateCloverex1->rotateX(-6.*deg);
//     G4RotationMatrix *rotateCloverex2 = new G4RotationMatrix();
//     rotateCloverex2->rotateX(6.*deg);
//     G4RotationMatrix *rotateCloverey1 = new G4RotationMatrix();
//     rotateCloverey1->rotateY(-6.*deg);
//     G4RotationMatrix *rotateCloverey2 = new G4RotationMatrix();
//     rotateCloverey2->rotateY(6.*deg);
	  
//     CloverCryoPos = G4ThreeVector(0,CloverCryoy/2.+ CloverCryoz/2.+1.2*cm,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm);
//     physiCloverCryo = new G4PVPlacement(rotateCloverex1,
// 					 CloverCryoPos,
// 					 logicCloverCryo,
// 					 "CloverCryo",
// 					 logicWorld,
// 					 false,
// 					 1);

//     CloverCryoPos = G4ThreeVector(0,-CloverCryoy/2.- CloverCryoz/2.-1.2*cm,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm);
//     physiCloverCryo = new G4PVPlacement(rotateCloverex2,
// 					 CloverCryoPos,
// 					 logicCloverCryo,
// 					 "CloverCryo",
// 					 logicWorld,
// 					 false,
// 					 3);
 
//     CloverCryoPos = G4ThreeVector(CloverCryox/2.+ CloverCryoz/2.+1.2*cm,0,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm);
//     physiCloverCryo = new G4PVPlacement(rotateCloverey1,
// 					 CloverCryoPos,
// 					 logicCloverCryo,
// 					 "CloverCryo",
// 					 logicWorld,
// 					 false,
// 					 2);

//     CloverCryoPos = G4ThreeVector(-CloverCryox/2.-CloverCryoz/2.-1.2*cm,0,CloverCryoz/2. + fGeThickDetectorCryoThickness/2. + 0.8*cm);
//     physiCloverCryo = new G4PVPlacement(rotateCloverey2,
// 					 CloverCryoPos,
// 					 logicCloverCryo,
// 					 "CloverCryo",
// 					 logicWorld,
// 					 false,
// 					 4);
//     /**** end explode geometry ****/  




	}




	//---------------------



	//------------------------------------------------ 
	// Sensitive detectors
	//------------------------------------------------ 
	G4cout << "sensitive 1 " << G4endl;
	G4SDManager* SDman = G4SDManager::GetSDMpointer();

	//G4String detectorSDname = "p26/DetectorSD";
	G4String detectorSDname = "GeThickDetectorCollection";
	p26DetectorSD* aDetectorSD = new p26DetectorSD( detectorSDname );
	SDman->AddNewDetector( aDetectorSD );
	//logicTarget->SetSensitiveDetector( aDetectorSD );
	logicGeThickDetector->SetSensitiveDetector( aDetectorSD );
	G4cout << "sensitive 2 " << G4endl;



	detectorSDname = "GeThinDetectorCollection";
	p26DetectorSD* athinDetectorSD = new p26DetectorSD( detectorSDname );
	SDman->AddNewDetector( athinDetectorSD );
	logicGeThinDetector->SetSensitiveDetector( athinDetectorSD );


////// MBB ///////

	//NaI cylindrical scintillator as a senstive detector? -MBB
	detectorSDname = "NaICylinderCollection";
	p26DetectorSD* aNaICylinderSD = new p26DetectorSD( detectorSDname );
	SDman->AddNewDetector( aNaICylinderSD );
	logicNaICylinder->SetSensitiveDetector( aNaICylinderSD );
	G4cout << "sensitive 3 " << G4endl;
	
	//NaI cube scintillator as a senstive detector? -MBB
	detectorSDname = "NaICubeCollection";
	p26DetectorSD* aNaICubeSD = new p26DetectorSD( detectorSDname );
	SDman->AddNewDetector( aNaICubeSD );
	//logicNaICube->SetSensitiveDetector( aNaICubeSD );
	G4cout << "sensitive 3.5 " << G4endl;

	
	
	// LaBr detector is sensitive too -MBB
	detectorSDname = "LaBrDetectorCollection";
	p26DetectorSD* aLaBrDetectorSD = new p26DetectorSD( detectorSDname );
	SDman->AddNewDetector( aLaBrDetectorSD );
	logicLaBrDetector->SetSensitiveDetector( aLaBrDetectorSD );
	

//////////////////

	//add Sega as sensitive detector
	detectorSDname = "SegaCollection";
	p26DetectorSD* aSegaDetectorSD = new p26DetectorSD( detectorSDname );
	SDman->AddNewDetector( aSegaDetectorSD );
	logicSegaActiveArea->SetSensitiveDetector( aSegaDetectorSD );
	G4cout << "sensitive 3 " << G4endl;

	//add Clover as sensistive detector
	detectorSDname = "CloverCollection";
	p26DetectorSD* aCloverDetectorSD = new p26DetectorSD( detectorSDname);
	SDman->AddNewDetector( aCloverDetectorSD);
	logicCloverCrystal->SetSensitiveDetector( aCloverDetectorSD);

	//
	//-------------------------------------------------
	// regions
	//
	//  if(targetRegion) delete targetRegion;
	// if(detectorRegion) delete detectorRegion;
	//targetRegion = new G4Region("Target"); //snl
	GeThickDetectorRegion   = new G4Region("GeThickDetector");
	//targetRegion->AddRootLogicalVolume(logicTarget);//snl
	GeThickDetectorRegion->AddRootLogicalVolume(logicGeThickDetector);

	//--------- Visualization attributes -------------------------------
	logicWorld->SetVisAttributes(G4VisAttributes::Invisible);
	//G4VisAttributes* TargetVisAtt= new G4VisAttributes(G4Colour(1.0,1.0,1.0));
	//logicTarget ->SetVisAttributes(TargetVisAtt);
	G4VisAttributes* DetectorVisAtt= new G4VisAttributes(G4Colour(1.0,1.0,.0));
	logicGeThickDetector->SetVisAttributes(DetectorVisAtt);

	G4VisAttributes* DetectorVisAtt1 = new G4VisAttributes(G4Colour::Blue());
	//logicBCSpipe->SetVisAttributes(G4VisAttributes::Invisible);
	//logicBCSvac->SetVisAttributes(G4VisAttributes::Invisible);
	logicSegaCryo->SetVisAttributes(DetectorVisAtt1);
	logicGeThickDetector->SetVisAttributes(DetectorVisAtt1);
	logicCloverCryo->SetVisAttributes(G4Colour::Green());
	logicCloverCrystal->SetVisAttributes(G4Colour::Green());

	logicGeCryoEndCap->SetVisAttributes(G4VisAttributes::Invisible);
	//logicBCSdssd->SetVisAttributes(G4Colour::Green());

	//------------ set the incident position ------
	G4cout << "sensitive 4 " << G4endl;

 // get the pointer to the User Interface manager 
	  
//   G4UImanager* UI = G4UImanager::GetUIpointer();  
//   //      UI->ApplyCommand("/run/verbose 1");
//   //      UI->ApplyCommand("/event/verbose 2");
//   //      UI->ApplyCommand("/tracking/verbose 1");  

//   G4double zpos = -fWorldLength/2.;
//   G4String command = "/gps/pos/centre ";
//   std::ostringstream os;
//   os << zpos ; 
//   G4String xs = os.str();
//   UI->ApplyCommand(command+"0. 0. "+xs+" mm");
//   UI->ApplyCommand("/gps/pos/type Point");
//   command = "/gps/position ";
//   //  UI->ApplyCommand(command+"0. 0. "+xs+" mm");
//   UI->ApplyCommand("/gps/particle proton");
//   UI->ApplyCommand("/gps/direction 0 0 1");
//   UI->ApplyCommand("/gps/energy 100 MeV");
//   //       

	if(gp26AnalysisManager) gp26AnalysisManager->DetectorInfo(this);
	G4cout << "sensitive 5 " << G4endl;
	
	return physiWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
// void p26DetectorConstruction::setTargetMaterial(G4String materialName)
// {
//   // search the material by its name 
//   G4Material* pttoMaterial = G4Material::GetMaterial(materialName);  
//   if (pttoMaterial)
//      {TargetMater = pttoMaterial;
//       if (logicTarget) logicTarget->SetMaterial(pttoMaterial); 
//       G4cout << "\n----> The target has been changed to " << fTargetLength/cm << " cm of "
//              << materialName << G4endl;
//      }             
// }
 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void p26DetectorConstruction::setGeThickDetectorMaterial(G4String materialName)
{
	// search the material by its name 
	G4Material* pttoMaterial = G4Material::GetMaterial(materialName);  
	if (pttoMaterial)
	   {GeThickDetectorMater = pttoMaterial;
	    if (logicGeThickDetector) logicGeThickDetector->SetMaterial(pttoMaterial); 
	    G4cout << "\n----> The Thick Deetctor has been changed to" << fGeThickDetectorThickness/cm << " cm of "
	           << materialName << G4endl;
	   }             
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

void p26DetectorConstruction::setGeThinDetectorMaterial(G4String materialName)
{
	// search the material by its name 
	G4Material* pttoMaterial = G4Material::GetMaterial(materialName);  
	if (pttoMaterial)
	   {GeThinDetectorMater = pttoMaterial;
	    if (logicGeThinDetector) logicGeThinDetector->SetMaterial(pttoMaterial); 
	    G4cout << "\n----> The Thin Deetctor has been changed to" << fGeThinDetectorThickness/cm << " cm of "
	           << materialName << G4endl;
	   }             
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....


void p26DetectorConstruction::setLaBrDetectorMaterial(G4String materialName)
{
	// search the material by its name 
	G4Material* pttoMaterial = G4Material::GetMaterial(materialName);  
	if (pttoMaterial)
	   {LaBrDetectorMater = pttoMaterial;
	    if (logicLaBrDetector) logicLaBrDetector->SetMaterial(pttoMaterial); 
	    G4cout << "\n----> The LaBr Deetctor has been changed to" << fLaBrDetectorThickness/cm << " cm of "
	           << materialName << G4endl;
	   }             
}






//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

void p26DetectorConstruction::setNaICylinderMaterial(G4String materialName)
{
	//search the material by its name
	G4Material* pttoMaterial = G4Material::GetMaterial(materialName);
	if (pttoMaterial)
	{
		NaICylinderMater = pttoMaterial;
		if (logicNaICylinder) logicNaICylinder->SetMaterial(pttoMaterial);
		G4cout << "\n----> The NaI Cylinder has been changed to" << fNaICylinderThickness/cm << "cm of "
			 << materialName << G4endl;
	}
	
}

void p26DetectorConstruction::setNaICubeMaterial(G4String materialName)
{
	//search the material by its name
	G4Material* pttoMaterial = G4Material::GetMaterial(materialName);
	if (pttoMaterial)
	{
		NaICubeMater = pttoMaterial;
		if (logicNaICube) logicNaICube->SetMaterial(pttoMaterial);
		G4cout << "\n----> The NaI Cube has been changed to" << fNaICubeThickness/cm << "cm of "
			 << materialName << G4endl;
	}
	
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....
