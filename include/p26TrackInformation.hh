/*
attemp to add trakcing information to individual tracks - snl

*/


#ifndef p26TrackInformation_h
#define p26TrackInformation_h 1

#include "globals.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleDefinition.hh"
#include "G4Track.hh"
#include "G4Allocator.hh"
#include "G4VUserTrackInformation.hh"

class p26TrackInformation : public G4VUserTrackInformation 
{
  public:
    p26TrackInformation();
    p26TrackInformation(const G4Track* aTrack);
    p26TrackInformation(const p26TrackInformation* aTrackInfo);
    virtual ~p26TrackInformation();
   
    inline void *operator new(size_t);
    inline void operator delete(void *aTrackInfo);
    inline int operator ==(const p26TrackInformation& right) const
    {return (this==&right);}

    void Print() const;

  private:
    G4int                 originalTrackID;
    G4ParticleDefinition* particleDefinition;
    G4ThreeVector         originalPosition;
    G4ThreeVector         originalMomentum;
    G4double              originalEnergy;
    G4double              originalTime;

  public:
    inline G4int GetOriginalTrackID() const {return originalTrackID;}
    inline G4ParticleDefinition* GetOriginalParticle() const {return particleDefinition;}
    inline G4ThreeVector GetOriginalPosition() const {return originalPosition;}
    inline G4ThreeVector GetOriginalMomentum() const {return originalMomentum;}
    inline G4double GetOriginalEnergy() const {return originalEnergy;}
    inline G4double GetOriginalTime() const {return originalTime;}
};

extern G4Allocator<p26TrackInformation> aTrackInformationAllocator;

inline void* p26TrackInformation::operator new(size_t)
{ void* aTrackInfo;
  aTrackInfo = (void*)aTrackInformationAllocator.MallocSingle();
  return aTrackInfo;
}

inline void p26TrackInformation::operator delete(void *aTrackInfo)
{ aTrackInformationAllocator.FreeSingle((p26TrackInformation*)aTrackInfo);}

#endif
