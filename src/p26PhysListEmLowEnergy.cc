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

#include "p26PhysListEmLowEnergy.hh"
#include "G4ParticleDefinition.hh"
#include "G4ProcessManager.hh"

// gamma
//#include "G4LowEnergyRayleigh.hh" 
//#include "G4LowEnergyPhotoElectric.hh"
//#include "G4LowEnergyCompton.hh"  
//#include "G4LowEnergyGammaConversion.hh" 

#include "G4PhotoElectricEffect.hh"
#include "G4LivermorePhotoElectricModel.hh"

#include "G4ComptonScattering.hh"
#include "G4LivermoreComptonModel.hh"

#include "G4GammaConversion.hh"
#include "G4LivermoreGammaConversionModel.hh"

#include "G4RayleighScattering.hh" 
#include "G4LivermoreRayleighModel.hh"

// Penelope Low Energy EM Models
#include "G4PenelopeIonisationModel.hh"
#include "G4PenelopeBremsstrahlungModel.hh"
#include "G4PenelopeAnnihilationModel.hh"
#include "G4PenelopeComptonModel.hh"
#include "G4PenelopePhotoElectricModel.hh"
#include "G4PenelopeGammaConversionModel.hh"
#include "G4PenelopeRayleighModel.hh"

// e-
#include "G4eMultipleScattering.hh"

#include "G4eIonisation.hh"
#include "G4LivermoreIonisationModel.hh"

#include "G4eBremsstrahlung.hh"
#include "G4LivermoreBremsstrahlungModel.hh"

//#include "G4hLowEnergyIonisation.hh"  //REMOVED BY MBB 12 Aug 2013
//#include "G4LowEnergyBremsstrahlung.hh" 

// e+
#include "G4eIonisation.hh" 
#include "G4eBremsstrahlung.hh" 
#include "G4eplusAnnihilation.hh"

#include "G4eMultipleScattering.hh"
#include "G4MuMultipleScattering.hh"
#include "G4hMultipleScattering.hh"

#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"

#include "G4ionIonisation.hh"
#include "G4hIonisation.hh"
#include "G4ionIonisation.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

p26PhysListEmLowEnergy::p26PhysListEmLowEnergy(const G4String& name)
   :  G4VPhysicsConstructor(name)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

p26PhysListEmLowEnergy::~p26PhysListEmLowEnergy()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void p26PhysListEmLowEnergy::ConstructProcess()
{
  // Add low EM Processes from Livermore model, use default parameters

	/*I UPDATED THIS WHOLE BLOCK TO REFELCT THE CHANGE TO GEANT 4.9.6 AS LISTED 
	    HERE: https://twiki.cern.ch/twiki/bin/view/Geant4/LoweMigration 
	 But it looks like protons shouldn't even be part of the former 
	  G4hLowEnergyIonisation package?  Not sure what that's about...  */


	
	theParticleIterator->reset();
	while( (*theParticleIterator)() )
	{
		G4ParticleDefinition* particle = theParticleIterator->value();
		G4ProcessManager* pmanager = particle->GetProcessManager();
		G4String particleName = particle->GetParticleName();
 
		if (particleName == "gamma")
		{
     
			G4PhotoElectricEffect* thePhotoElectricEffect = new G4PhotoElectricEffect();
			G4PenelopePhotoElectricModel* thePenelopePhotoElectricModel = new G4PenelopePhotoElectricModel();
			thePhotoElectricEffect->SetEmModel(thePenelopePhotoElectricModel); //changed to SetEmModel 22 Aug 2013 MBB
			pmanager->AddDiscreteProcess(thePhotoElectricEffect);

			G4ComptonScattering* theComptonScattering = new G4ComptonScattering();
			G4PenelopeComptonModel* thePenelopeComptonModel = new G4PenelopeComptonModel();
			theComptonScattering->SetEmModel(thePenelopeComptonModel); //changed to SetEmModel 22 Aug 2013 MBB
			pmanager->AddDiscreteProcess(theComptonScattering);

			G4GammaConversion* theGammaConversion = new G4GammaConversion();
			G4PenelopeGammaConversionModel* thePenelopeGammaConversionModel = new G4PenelopeGammaConversionModel();
			theGammaConversion->SetEmModel(thePenelopeGammaConversionModel); //changed to SetEmModel 22 Aug 2013 MBB
			pmanager->AddDiscreteProcess(theGammaConversion);
	
			G4RayleighScattering* theRayleigh = new G4RayleighScattering();
			G4PenelopeRayleighModel* theRayleighModel = new G4PenelopeRayleighModel();
			theRayleigh->SetEmModel(theRayleighModel); //changed to SetEmModel 22 Aug 2013 MBB
			pmanager->AddDiscreteProcess(theRayleigh);
			
		} else if (particleName == "e-") {
  			
  			
  			//G4cout << "********** ELECTRON ********** " << G4endl;
  			
			// process ordering: AddProcess(name, at rest, along step, post step)
			// Multiple scattering
			G4eMultipleScattering* msc = new G4eMultipleScattering();
			pmanager->AddProcess(msc,-1, 1, 1);
			
			// Penelope Low Energy EM processes ======================================
			G4eIonisation* eIoni = new G4eIonisation();
			G4PenelopeIonisationModel* thePenelopeIonisationModel = new G4PenelopeIonisationModel();
			eIoni->SetEmModel(thePenelopeIonisationModel);
			eIoni->SetStepFunction(0.2, 100*um); //     
			pmanager->AddProcess(eIoni,                 -1, 2, 2);
			
			G4eBremsstrahlung* eBrem = new G4eBremsstrahlung();
			eBrem->SetEmModel(new G4PenelopeBremsstrahlungModel());
			pmanager->AddProcess(eBrem,         -1,-3, 3);
			
			G4cout << " what particle - " << particle->GetParticleName() << G4endl;

		} else if (particleName == "e+") {
      
			//G4cout << "----------------- POSITRON -------------" << G4endl;
			
			//positron      
			G4eMultipleScattering* msc = new G4eMultipleScattering();
			pmanager->AddProcess(msc,-1, 1, 1);
			
			// Penelope Low Energy EM processes ======================================
			G4eIonisation* eIoni = new G4eIonisation();
			G4PenelopeIonisationModel* thePenelopeIonisationModel = new G4PenelopeIonisationModel();
			eIoni->SetEmModel(thePenelopeIonisationModel);
			eIoni->SetStepFunction(0.2, 100*um); //     
			pmanager->AddProcess(eIoni,                 -1, 2, 2);
			
			G4eBremsstrahlung* eBrem = new G4eBremsstrahlung();
			eBrem->SetEmModel(new G4PenelopeBremsstrahlungModel());
			pmanager->AddProcess(eBrem,         -1,-3, 3);
			
			G4eplusAnnihilation* eplusAn = new G4eplusAnnihilation();
			eplusAn->SetEmModel(new G4PenelopeAnnihilationModel()); //changed to SetEmModel 22 Aug 2013 MBB
			pmanager->AddProcess(eplusAn,         0,-1, 4);
			
			G4cout << " what particle - " << particle->GetParticleName() << G4endl;
     
		} else if( particleName == "mu+" 
		  || particleName == "mu-" ) {

			pmanager->AddProcess(new G4MuMultipleScattering,-1, 1,1);
			//       pmanager->AddProcess(new G4MuIonisation,      -1, 2,2);
			//       pmanager->AddProcess(new G4MuBremsstrahlung,  -1, 3,3);
			//       pmanager->AddProcess(new G4MuPairProduction,  -1, 4,4);       

		/*} else if (particleName == "proton"){
		
			// proton
			pmanager->AddProcess(new G4hMultipleScattering(), -1, 1, 1);
			G4LivermoreIonisationModel* lowEnerIon = new G4LivermoreIonisationModel(); //Changed 12 Aug 2013 by MBB
			lowEnerIon->SetElectronicStoppingPowerModel(particle,"ICRU_R49He");
			lowEnerIon->SetNuclearStoppingOn();
			lowEnerIon->SetNuclearStoppingPowerModel("ICRU_R49");
			lowEnerIon->SetFluorescence(true);
			lowEnerIon->ActivateAugerElectronProduction(true);
			pmanager->AddProcess(lowEnerIon, -1, 2, 2);
		/**/	
		
			G4cout << " what particle - " << particle->GetParticleName() << G4endl;
			
		} else if (particleName == "alpha" || particleName == "He3" 
		  || particleName == "deuteron" || particleName == "triton" 
		  || particleName == "GenericIon") {

			pmanager->AddProcess(new G4hMultipleScattering, -1, 1,1);
			pmanager->AddProcess(new G4ionIonisation,       -1,2,2);
			//      pmanager->AddProcess(new G4ionIonisation,      -1, 2,2);
			// it dose not work here
			
			G4cout << " what particle - " << particle->GetParticleName() << G4endl;
			
		} else if ((!particle->IsShortLived()) && (particle->GetPDGCharge() != 0.0) 
		  && (particle->GetParticleName() != "chargedgeantino")) {

			G4cout << " what particle - " << particle->GetParticleName() << G4endl;

			pmanager->AddProcess(new G4hMultipleScattering,-1,1,1);
			//pmanager->AddProcess(new G4ionIonisation,       -1,2,2);
		}
	}

	G4cout << "finished low EM" << G4endl;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

