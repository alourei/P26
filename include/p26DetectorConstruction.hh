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
#ifndef p26DetectorConstruction_h
#define p26DetectorConstruction_h 1

#include "globals.hh"
#include "G4ThreeVector.hh"
#include "G4VUserDetectorConstruction.hh"
//#include "p26MagneticField.hh"
#include "DetectionSystemTigress.hh"

class G4Tubs;
class G4Box;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
class G4Region;
class p26DetectorMessenger;
class p26Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class p26DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
     p26DetectorConstruction();
    ~p26DetectorConstruction();

  public:
  
     G4VPhysicalVolume* Construct();
     
     const 
     G4VPhysicalVolume* GetDetector() {return physiGeThickDetector;};

  //   G4double GetDetectoFullLength() {return fDetectorLength;};
  //G4double GetTargetFullLength()  {return fTargetLength;};

  // get world paramters
     G4double GetWorldFullLength()   {return fWorldLength;}; 
     G4double GetWorldRadius()   {return fWorldRadius;}; 

  // get thick ge detector parameters
     G4double GetGeThickDetectorThickness() {return fGeThickDetectorThickness;};
     G4double GetGeThickDetectorRadius()  {return fGeThickDetectorRadius;};

  // get thin ge detector parameters
     G4double GetGeThinDetectorThickness() {return fGeThinDetectorThickness;};
     G4double GetGeThinDetectorRadius()  {return fGeThinDetectorRadius;};
     
     
///////// MBB added 16 Aug 2013 ///////////

  // get NaI Cylinder parameters
	G4double GetNaICylinderThickness() {return fNaICylinderThickness;};
	G4double GetNaICylinderRadius() {return fNaICylinderRadius;};
	
  // get NaI Cube parameters
  	G4double GetNaICubeThickness() {return fNaICubeThickness;};
  	G4double GetNaICubeDepth() {return fNaICubeDepth;};
  	
  // get LaBr Detector parameters
  	G4double GetLaBrDetectorThickness() {return fLaBrDetectorThickness;};
  	G4double GetLaBrDetectorRadius() {return fLaBrDetectorRadius;};

///////////////////////////////////////////

     
  // get the boolean values to determine which detector(s) is being used
     G4bool GetUseGeThickDetector() {return fUseGeThickDetector;};
     G4bool GetUseGeThinDetector() {return fUseGeThinDetector;};

	G4bool GetUseNaICylinder() {return fUseNaICylinder;}; //MBB 
	G4bool GetUseNaICube() {return fUseNaICube;}; //MBB
	G4bool GetUseLaBrDetector() {return fUseLaBrDetector;}; //MBB


  // get the inter detector spacing
     G4double GetGeSpacing() {return fSpacing;};

  // get the position of the thick and thin detector
     G4ThreeVector GetGeThickDetectorPos() {return fGeThickDetectorPos;};
     G4ThreeVector GetGeThinDetectorPos() {return fGeThinDetectorPos;};
     
     G4ThreeVector GetNaICylinderPos() {return fNaICylinderPos;}; //MBB
     G4ThreeVector GetNaICubePos() {return fNaICylinderPos;}; //MBB
     G4ThreeVector GetLaBrDetectorPos() {return fLaBrDetectorPos;}; //MBB
     

  // set the detector material for the thick detector
     void setGeThickDetectorMaterial(G4String);
  // set the detector material for the thin detector
     void setGeThinDetectorMaterial(G4String);
     
  // set the detector material for the NaI cylinder --- MBB
	void setNaICylinderMaterial(G4String);    
  // set the detector material for the NaI cube --- MBB
	void setNaICubeMaterial(G4String);    
  // set the detector material for the LaBr detector --- MBB
	void setLaBrDetectorMaterial(G4String);    
     

  // set the thick ge detector parameters
     void setGeThickDetectorRadius (G4double value) { fGeThickDetectorRadius = value; };
     void setGeThickDetectorThickness(G4double value){ fGeThickDetectorThickness = value;};  

  // set the thin ge detector parameters
     void setGeThinDetectorRadius (G4double value) { fGeThinDetectorRadius = value; };
     void setGeThinDetectorThickness(G4double value){ fGeThinDetectorThickness = value;};  
     

///// MBB Added 16 Aug 2013 //////////////

	//set LaBr Parameters
	
	void setLaBrDetectorRadius (G4double value) { fLaBrDetectorRadius = value; };
	void setLaBrDetectorThickness(G4double value) {fLaBrDetectorThickness = value;};
	
	
	//set the NaI Cylinder Parameters
	
	void setNaICylinderRadius (G4double value) { fNaICylinderRadius = value; };
	void setNaICylinderThickness(G4double value) {fNaICylinderThickness = value;};
	
	//set NaI Cube Parameters
	
	void setNaICubeDepth (G4double value) { fNaICubeDepth = value; };
	void setNaICubeThickness(G4double value) {fNaICubeThickness = value;};

//////////////////////////////////////////
     

  // set the inter detector spacing
     void setDetectorSpacing( G4double value) {fSpacing = value;};

  // set which Ge detector(s) will be used
     void setUseGeThickDetector( G4bool value) {fUseGeThickDetector = value;};
     void setUseGeThinDetector( G4bool value) {fUseGeThinDetector = value;};
     
  // set whether the NaI cylinder will be used -- MBB
	void setUseNaICylinder( G4bool value) {fUseNaICylinder = value;};
	
 // set whether the LaBr will be used -- MBB
	void setUseLaBrDetector( G4bool value) {fUseLaBrDetector = value;};
	
 // set whether the NaI cube will be used -- MBB
	void setUseNaICube( G4bool value) {fUseNaICube = value;};	

  // set which aspects of the planar Ge crystat will be used
     void setUseGeThickDetectorCryo( G4bool value) {fUseGeThickDetectorCryo = value;};
     void setUseGeThickDetectorCryoEndCap( G4bool value) {fUseGeThickDetectorCryoEndCap = value;};

  // set which external Ge array will be used
     void setUseSega( G4bool value) {fUseSega = value;};
     void setUseClover( G4bool value) {fUseClover = value;};

  //void setDetectorLength(G4double value){ fDetectorLength = value;};  
     
  private:
     void DefineMaterials();
     
  private: 

     p26DetectorMessenger* detectorMessenger;  // pointer to the Messenger
     p26Material* materialsManager;            // material manager

     G4Tubs*             solidWorld;              // pointer to the solid envelope 
     G4LogicalVolume*   logicWorld;               // pointer to the logical envelope
     G4VPhysicalVolume* physiWorld;               // pointer to the physical envelope
                  
     G4Tubs*             solidGeThickDetector;    // pointer to the solid Detector
     G4LogicalVolume*   logicGeThickDetector;     // pointer to the logical Detector
     G4VPhysicalVolume* physiGeThickDetector;     // pointer to the physical Detector

     G4Tubs*            solidGeThinDetector;      // pointer to the solid Detector
     G4LogicalVolume*   logicGeThinDetector;      // pointer to the logical Detector
     G4VPhysicalVolume* physiGeThinDetector;      // pointer to the physical Detector
     

////////////// MBB //////////////////

	//G4Tubs*		solidNaICylinder;
	G4Box*		solidNaICylinder;		// pointer to the solid NaI cylinder
	G4LogicalVolume*	logicNaICylinder;		// pointer to the logical NaI cylinder
	G4VPhysicalVolume* physiNaICylinder;	// pointer to the physical NaI cylinder
	
	G4Tubs*		solidLaBrDetector;		// pointer to the solid LaBr Detector
	G4LogicalVolume*	logicLaBrDetector;		// pointer to the logical LaBr Detector
	G4VPhysicalVolume* physiLaBrDetector;	// pointer to the physical LaBr Detector
	
	//G4Box*		solidNaICube;		// pointer to the solid NaI cube
	G4Tubs*		solidNaICube;
	G4LogicalVolume*	logicNaICube;		// pointer to the logical NaI cube
	G4VPhysicalVolume* physiNaICube;	// pointer to the physical NaI cube

/////////////////////////////////////     
     
     
     G4Tubs*            solidGeThickDetectorCryo; // pointer to the solid Detector cryostat
     G4LogicalVolume*   logicGeThickDetectorCryo; // pointer to the logical Detector cryostat
     G4VPhysicalVolume* physiGeThickDetectorCryo; // pointer to the physical Detector cryostat

     G4Tubs*            solidGeCryoEndCap;        // pointer to the solid Detector end cap
     G4LogicalVolume*   logicGeCryoEndCap;        // pointer to the logical Detector end cap
     G4VPhysicalVolume* physiGeCryoEndCap;        // pointer to the physical Detector end cap

     G4Tubs*            solidSegaCryo;            // pointer to the solid Sega cryostat
     G4LogicalVolume*   logicSegaCryo;            // pointer to the logical Sega cryostat
     G4VPhysicalVolume* physiSegaCryo;            // pointer to the physical Sega cryostat

     G4Tubs*            solidSegaVac2;            // pointer to the solid Sega vacuum inside the cryo
     G4LogicalVolume*   logicSegaVac2;            // pointer to the logical Sega vacuum inside the cryo
     G4VPhysicalVolume* physiSegaVac2;            // pointer to the physical Sega vacuum inside the cryo
 
     G4Tubs*            solidSegaDetCup;          // pointer to the solid Sega detector cup
     G4LogicalVolume*   logicSegaDetCup;          // pointer to the logical Sega detector cup
     G4VPhysicalVolume* physiSegaDetCup;          // pointer to the physical Sega detector cup

     G4Tubs*            solidSegaVac1;            // pointer to the solid Sega vacuum inside the det cup
     G4LogicalVolume*   logicSegaVac1;            // pointer to the logical Sega vacuum inside the det cup
     G4VPhysicalVolume* physiSegaVac1;            // pointer to the physical Sega vacuum inside the det cup

     G4Tubs*            solidSegaCrystal;         // pointer to the solid Sega crystal
     G4LogicalVolume*   logicSegaCrystal;         // pointer to the logical Sega crystal
     G4VPhysicalVolume* physiSegaCrystal;         // pointer to the physical Sega crystal

     G4Tubs*            solidSegaActiveArea;      // pointer to the solid Sega active area
     G4LogicalVolume*   logicSegaActiveArea;      // pointer to the logical Sega active area
     G4VPhysicalVolume* physiSegaActiveArea;      // pointer to the physical Sega active area

     G4Tubs*            solidSegaCentralCon;      // pointer to the solid Sega central contact
     G4LogicalVolume*   logicSegaCentralCon;      // pointer to the logical Sega central contact
     G4VPhysicalVolume* physiSegaCentralCon;      // pointer to the physical Sega central contact
      
//      G4Box*             solidTIGRESSCrystal;      // pointer to the solid TIGRESS Crystal     
//      G4LogicalVolume*   logicTIGRESSCrystal;      // pointer to the logical TIGRESS Crystal     
//      G4VPhysicalVolume* physiTIGRESSCrystal;      // pointer to the physical TIGRESS Crystal     

//      G4Box*             solidTIGRESSVacuum;       // pointer to the solid TIGRESS Vacuum     
//      G4LogicalVolume*   logicTIGRESSVacuum;       // pointer to the logical TIGRESS Vacuum     
//      G4VPhysicalVolume* physiTIGRESSVacuum;       // pointer to the physical TIGRESS Vacuum     

//      G4Box*             solidTIGRESSCryo;         // pointer to the solid TIGRESS Cryo
//      G4LogicalVolume*   logicTIGRESSCryo;         // pointer to the logical TIGRESS Cryo     
//      G4VPhysicalVolume* physiTIGRESSCryo;         // pointer to the physical TIGRESS Cryo     

     G4Tubs* solidCloverBool1;                    // pointer to the solid boolean clover
     G4Box* solidCloverBool2;                     // pointer to the solid boolean clover

  //     G4IntersectionSolid* solidCloverCrystal;     // pointer to the solid clover crystal
     G4Tubs* solidCloverCrystal;                  // pointer to the solid clover crystal
     G4LogicalVolume* logicCloverCrystal;         // pointer to the logical clover crystal
     G4VPhysicalVolume* physiCloverCrystal;       // pointer to the physical clover crystal

     G4Tubs* solidCloverCore;                     // pointer to the solid clover core
     G4LogicalVolume* logicCloverCore;            // pointer to the logical clover core
     G4VPhysicalVolume* physiCloverCore;          // pointer to the physical clover core

     G4Box* solidCloverCryo;                      // pointer to the solid clover cryostat
     G4LogicalVolume* logicCloverCryo;            // pointer to the logical clover cryostat
     G4VPhysicalVolume* physiCloverCryo;          // pointer to the physical clover cryostat
  
     G4Box *solidCloverCryoVac;                   // pointer to the solid clover cryostat vacuum
     G4LogicalVolume *logicCloverCryoVac;          // pointer to the logical cryostat vacuum
     G4VPhysicalVolume* physiCloverCryoVac;       // pointer to the physical cryostat vacuum

     G4Tubs*            solidBCSpipe;            // pointer to the solid BCSpipe
     G4LogicalVolume*   logicBCSpipe;            // pointer to the logical BCS pipe
     G4VPhysicalVolume* physiBCSpipe;            // pointer to the physical BCS pipe

     G4Tubs*            solidBCSvac;            // pointer to the solid BCSvac
     G4LogicalVolume*   logicBCSvac;            // pointer to the logical BCS vac
     G4VPhysicalVolume* physiBCSvac;            // pointer to the physical BCS vac

     G4Box*            solidBCSdssd;            // pointer to the solid BCS dssd
     G4LogicalVolume*   logicBCSdssd;            // pointer to the logical BCS dssd
     G4VPhysicalVolume* physiBCSdssd;            // pointer to the physical BCS dssd

      
     G4Material* DefaultMater;                    // Default material
     G4Material* GeThickDetectorMater;            // Thick Ge Detector material
     G4Material* GeThickDetectorCryoMater;        // Cryostat material around Ge detector
     G4Material* GeThinDetectorMater;             // Thick Ge Detector material
     
     G4Material* NaICylinderMater;	//MBB		//NaI Cylinder material
     G4Material* NaICubeMater; //MBB
     G4Material* LaBrDetectorMater; //MBB
     
     G4Material* SegaCryoMater;                   // SeGA cryostat material
     G4Material* SegaVacuumMater;                 // SeGA vacuum material
     G4Material* SegaMater;                       // SeGA material
     G4Material* CloverCryoMater;                 // Clover cryostat material
     G4Material* VacuumMater;                     // vacuum material
     G4Material* CloverCrystalMater;             // CLover crystal material
     G4Material* BCSdssdMater;                    // DSSD material

     G4double fWorldLength;                       // Full length the world volume
     G4double fWorldRadius;                       // Radius of  the world volume

     G4double fGeThickDetectorThickness;          // Thickness of thick Ge detector
     G4double fGeThinDetectorThickness;           // Thickness of thin Ge detector
     
     G4double fNaICylinderThickness;	//MBB	//Thickness of the NaI Cylinder
     G4double fNaICubeThickness;		//MBB
     G4double fLaBrDetectorThickness;	//MBB
     
     
     G4double fGeThickDetectorCryoThickness;      // Thickness of the cryostat
     G4double fGeCryoEndCapThickness;             // Thickness of the end caps

     G4double fGeThickDetectorRadius;             // Radius of the thick Ge detector
     G4double fGeThinDetectorRadius;              // Radius of the thin Ge detector
     
     G4double fNaICylinderRadius;	//MBB		//Radius of the NaI cylinder
     G4double fNaICubeDepth;		//MBB
     G4double fLaBrDetectorRadius;	//MBB
     
     
     
     G4double fGeThickDetectorCryoOutRad;         // Outer radius of the detector cryostat
     G4double fGeThickDetectorCryoInnRad;         // Inner radius of the detector cryostat
     G4double fGeCryoEndCapOutRad;                // Thickness of the cryostat endcap
  

     G4double fSpacing;                           //Interdetector spacing

     G4bool fUseGeThinDetector;                   //flag to determine if thin detector is used
     
     G4bool fUseNaICylinder;		//MBB		//flag to determine whether the NaI cylinder is used
     G4bool fUseNaICube;		//MBB
     G4bool fUseLaBrDetector;		//MBB
     
     
     G4bool fUseGeThickDetector;                  //flag to determine if thick detector is used
     G4bool fUseGeThickDetectorCryo;               //flag to determine if detector cryostat is used
     G4bool fUseGeThickDetectorCryoEndCap;       //flag to determine if detector endcapis used
     G4bool fUseSega;                             //flag to determine if SeGA is used
     G4bool fUseClover;                          //flag to determine if Clover is used

     G4ThreeVector fGeThickDetectorPos;           //location in cryostat of thick detector
     G4ThreeVector fGeThinDetectorPos;            //location in cryostat of thin detector
     
     G4ThreeVector fNaICylinderPos;	//MBB		//location of the NaICylinder (no cryostat I think)
     G4ThreeVector fNaICubePos;	//MBB
     G4ThreeVector fLaBrDetectorPos;		//MBB
     
     
     
     G4ThreeVector fGeThickDetectorCryoPos;       // location of the cryostat in the world
     G4ThreeVector fGeCryoEndCapPos1;             // location of the endcap in the cryostat
     G4ThreeVector fGeCryoEndCapPos2;             // location of the other endcap in the cryostat

     G4ThreeVector fSegaCryoPos;                  //location of the sega cryo
     G4ThreeVector fSegaVac2Pos;                  // location of the vacuum region inside the sega cryo
     G4ThreeVector fSegaDetCupPos;                // location of the detector cup inside the vacuum region
     G4ThreeVector fSegaVac1Pos;                  // location of the vacuum region inside the detector cup
     G4ThreeVector fSegaCrystalPos;               // location of the crystal inside the vacuum region
     G4ThreeVector fSegaActivePos;                // location of the active area inside the crystal
     G4ThreeVector fSegaCentralConPos;            // location of the central contact inside the active area

     G4double fsegacryolength;                    // The length of the SeGA cryostat
     G4double fsegacryothick;                     // The thickness of the cryostat wall
     G4double fsegacryooutrad;                    // The outer radius of the cryostat
     G4double fsegavac2length;                    // The length of the vacuum inside the SeGA cryostat
     G4double fsegavac2thick;                     // The thickness of the vacuum inside the SeGA cryostat
     G4double fsegadetcuplength;                  // The length of the detector cup surounding the crystal
     G4double fsegadetcupthick;                   // The thickness of the detector cup
     G4double fsegavac1length;                    // The length of the vacuum inside the SeGA detector cup
     G4double fsegavac1thick;                     // The thickness of the vacuum inside the SeGA detector cup
     G4double fsegacrystallength;                 // The length of the detector crystal
     G4double fsegacrystalthick;                  // The thickness of the crystal
     G4double fsegaactivelength;                  // The length of the active area
     G4double fsegaactivethick;                   // The thickness of the active area
     G4double fsegacentralconlength;              // The length of the central contact
     G4double fsegacentralconthick;               // The thickness of the central contact

     G4ThreeVector CloverCrystalPos;              // location of the Clover crystal inside the vacuum
     G4ThreeVector CloverCryoPos;                 // location of the Clover cry in the world
     G4ThreeVector CloverCryoVacuumPos;           // location of the CloverSS vacuum inside the cryostat


  //G4Region*   targetRegion;
     G4Region*   GeThickDetectorRegion;

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
