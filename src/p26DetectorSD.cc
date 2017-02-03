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

#include "p26DetectorSD.hh"
#include "p26DetectorHit.hh"
#include "p26TrackInformation.hh"
#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4ios.hh"
#include "G4VProcess.hh"

p26DetectorSD::p26DetectorSD(G4String name)
  :G4VSensitiveDetector(name), HCID(-1)
{  
  G4String HCname;
  //collectionName.insert(HCname="DetectorCollection");
  collectionName.insert(HCname=name);
  positionResolution = 5*cm;
}

p26DetectorSD::~p26DetectorSD(){;}

void p26DetectorSD::Initialize(G4HCofThisEvent*HCE)
{
  //static int HCID = -1;
  scintCollection = new p26DetectorHitsCollection
    (GetName()/*SensitiveDetectorName*/,collectionName[0]); 
  if(HCID<0)
  { HCID = GetCollectionID(0); }
  HCE->AddHitsCollection(HCID,scintCollection);
}

G4bool p26DetectorSD::ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist)
{

  G4double edep = aStep->GetTotalEnergyDeposit();

  //G4VPhysicalVolume *physVol = ROhist->GetVolume();
  
  if(edep==0.) return true; //snl changed

  p26DetectorHit* aHit;
  int nHit = scintCollection->entries();
  //G4cout << " processing hit with entries " << nHit << G4endl;
  G4ThreeVector hitpos = aStep->GetPreStepPoint()->GetPosition();
//   for(int i=0;i<nHit;i++)
//   {
//    aHit = (*scintCollection)[i];
//    G4ThreeVector pos = aHit->GetPos();
//    G4double dist2 = sqr(pos.x()-hitpos.x())
//                    +sqr(pos.y()-hitpos.y())+sqr(pos.z()-hitpos.z());
//    if(dist2<=sqr(positionResolution))
//    aHit->AddEdep(edep);
//    return true;
//   }

    aHit = new p26DetectorHit();

    if(aStep->GetTrack()->GetParentID()!=0){
      p26TrackInformation *info = (p26TrackInformation*)(aStep->GetTrack()->GetUserInformation());
      G4String pnam = info->GetOriginalParticle()->GetParticleName();
      aHit->SetParentName(pnam);
      G4double paren = info->GetOriginalEnergy();
      aHit->SetParentEnergy(paren);
      G4ThreeVector parmodir = info->GetOriginalMomentum();
      aHit->SetParentMoDir(parmodir);
    }
    else{
      aHit->SetParentName("decayingnucleus");
    }

    G4double gt = aStep->GetPreStepPoint()->GetGlobalTime();
    aHit->SetGtime( gt );
    G4int st = aStep->GetTrack()->GetCurrentStepNumber();
    aHit->SetStepno( st );
    G4int tr = aStep->GetTrack()->GetTrackID();
    aHit->SetTrackno( tr );
    G4int pa = aStep->GetTrack()->GetParentID();
    aHit->SetParentno( pa );
    G4String ty = aStep->GetTrack()->GetDefinition()->GetParticleType();
    aHit->SetParticletype( ty );
    G4String nam = aStep->GetTrack()->GetDefinition()->GetParticleName();
    aHit->SetParticlename( nam );

    G4String volname = aStep->GetTrack()->GetVolume()->GetName();
    aHit->SetVolName( volname );
    //G4int volcopyno = aStep->GetTrack()->GetVolume()->GetCopyNo();
    if(volname == "SegaActiveArea"){
      //only the prestep point is certain to be in appropriate SD volume
      G4int volcopyno = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume(5)->GetCopyNo();
      aHit->SetVolCopyNo( volcopyno );
    }
    else if(volname == "CloverCrystal"){
      G4int crystalcopyno = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume(0)->GetCopyNo();
      G4int Cloverno = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume(2)->GetCopyNo();
      G4int volcopyno = Cloverno * 4 + crystalcopyno;
      aHit->SetVolCopyNo( volcopyno );

    }

    G4ThreeVector pre = aStep->GetPreStepPoint()->GetPosition();
    aHit->SetPrePosition( pre );
    G4ThreeVector post =aStep->GetPostStepPoint()->GetPosition();
    aHit->SetPostPosition( post );
    G4ThreeVector del = aStep->GetDeltaPosition();
    aHit->SetDeltaPosition( del );

    G4double dlen = aStep->GetStepLength();
    aHit->SetDeltaLength( dlen );

    //     G4Track *fTrack = aStep->GetTrack();
//    const G4VProcess *proc = aStep->GetTrack()->GetCreatorProcess();
//    G4String pr = proc->GetProcessName();
//    G4String pr = aStep->GetTrack()->GetCreatorProcess()->GetProcessName();
//     aHit->SetProcessname( pr );

  aHit->SetEdep( edep );

  //aHit->SetPos( aStep->GetPreStepPoint()->GetPosition() );
  scintCollection->insert( aHit );

  return true;
}

void p26DetectorSD::EndOfEvent(G4HCofThisEvent*)
{;}

void p26DetectorSD::clear()
{
} 

void p26DetectorSD::DrawAll()
{
} 

void p26DetectorSD::PrintAll()
{
} 

