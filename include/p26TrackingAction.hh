#ifndef p26TrackingAction_h
#define p26TrackingAction_h 1

#include "G4UserTrackingAction.hh"


class p26TrackingAction : public G4UserTrackingAction {

  public:
    p26TrackingAction(){};
    virtual ~p26TrackingAction(){};
   
    virtual void PreUserTrackingAction(const G4Track*);
    virtual void PostUserTrackingAction(const G4Track*);

};

#endif
