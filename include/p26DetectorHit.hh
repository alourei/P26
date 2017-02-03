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

#ifndef p26DetectorHit_h
#define p26DetectorHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"

class G4AttDef;

class p26DetectorHit : public G4VHit
{
  public:

      p26DetectorHit();
      ~p26DetectorHit();
      p26DetectorHit(const p26DetectorHit &right);
      const p26DetectorHit& operator=(const p26DetectorHit &right);
      G4int operator==(const p26DetectorHit &right) const;


      inline void *operator new(size_t);
      inline void operator delete(void *aHit);

      void Draw();
      const std::map<G4String,G4AttDef>* GetAttDefs() const;
      std::vector<G4AttValue>* CreateAttValues() const;
      void Print();

  private:
      G4double edep;
      G4ThreeVector pos;
      G4double gtime;
      G4int stepno;
      G4int parentno;
      G4int trackno;
      G4String particletype;
      G4String particlename;
      G4String parentname;
      G4String processname;
      G4String volname;
      G4int volcopyno;
      G4ThreeVector prepos;
      G4ThreeVector postpos;
      G4ThreeVector deltapos;
      G4double fulldis;
      G4double parentenergy;
      G4ThreeVector parentmodir;

      static std::map<G4String,G4AttDef> fAttDefs;

  public:
      inline void SetEdep(G4double de)
      { edep = de; }
      inline void AddEdep(G4double de)
      { edep += de; }
      inline G4double GetEdep()
      { return edep; }
      inline void SetPos(G4ThreeVector xyz)
      { pos = xyz; }
      inline G4ThreeVector GetPos()
      { return pos; }
      inline void SetGtime(G4double gt)
      {gtime = gt;}
      inline G4double GetGtime()
      {return gtime;}
    inline void SetStepno(G4int st)
        {stepno = st;}
    inline G4int GetStepno()
        {return stepno;}
  inline void SetParentno(G4int pa)
  {parentno = pa;}
  inline G4int GetParentno()
  {return parentno;}
  inline void SetParticletype(G4String ty)
  {particletype = ty;}
  inline G4String GetParticletype()
  {return particletype;}
  inline void SetProcessname(G4String pr)
  {processname = pr;}
  inline G4String GetProcessname()
  {return processname;}
  inline void SetParticlename(G4String nam)
  {particlename = nam;}
  inline G4String GetParticlename()
  {return particlename;}
  inline void SetParentName(G4String nam)
  {parentname = nam;}
  inline G4String GetParentName()
  {return parentname;}
  inline void SetParentEnergy(G4double paren)
  {parentenergy = paren;}
  inline G4double GetParentEnergy()
  {return parentenergy;}
  inline void SetParentMoDir(G4ThreeVector parmodir)
  {parentmodir = parmodir;}
  inline G4ThreeVector GetParentMoDir()
  {return parentmodir;}
   
  inline void SetVolName(G4String nam)
  {volname = nam;}
  inline G4String GetVolName()
  {return volname;}
  inline void SetVolCopyNo(G4int num)
  {volcopyno = num;}
  inline G4int GetVolCopyNo()
  {return volcopyno;}
  inline void SetTrackno(G4int tr)
  {trackno = tr;}
  inline G4int GetTrackno()
  {return trackno;}
  inline void SetPrePosition(G4ThreeVector pre)
  {prepos = pre;};
  inline G4ThreeVector GetPrePosition()
  {return prepos;};
  inline void SetPostPosition(G4ThreeVector post)
  {postpos = post;};
  inline G4ThreeVector GetPostPosition()
  {return postpos;};
  inline void SetDeltaPosition(G4ThreeVector del)
  {deltapos = del;};
  inline G4ThreeVector GetDeltaPosition()
  {return deltapos;};

  inline void SetDeltaLength(G4double dlen)
  {fulldis = dlen;};
  inline G4double GetDeltaLength()
  {return fulldis;};

};

typedef G4THitsCollection<p26DetectorHit> p26DetectorHitsCollection;

extern G4Allocator<p26DetectorHit> p26DetectorHitAllocator;

inline void* p26DetectorHit::operator new(size_t)
{
  void *aHit;
  aHit = (void *) p26DetectorHitAllocator.MallocSingle();
  return aHit;
}

inline void p26DetectorHit::operator delete(void *aHit)
{
  p26DetectorHitAllocator.FreeSingle((p26DetectorHit*) aHit);
}

#endif


