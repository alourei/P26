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
#ifndef p26DetectorROGeometry_h
#define p26DetectorROGeometry_h 1

#include "G4VReadOutGeometry.hh"

class p26DetectorROGeometry : public G4VReadOutGeometry
{
public:
  p26DetectorROGeometry();
  p26DetectorROGeometry(G4String);
  ~p26DetectorROGeometry();

private:
  G4VPhysicalVolume* Build();

  //#include "p26DetectorParameterDef.hh"

};

#endif
