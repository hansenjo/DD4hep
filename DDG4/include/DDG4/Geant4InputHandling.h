// $Id: $
//==========================================================================
//  AIDA Detector description implementation for LCD
//--------------------------------------------------------------------------
// Copyright (C) Organisation europeenne pour la Recherche nucleaire (CERN)
// All rights reserved.
//
// For the licensing terms see $DD4hepINSTALL/LICENSE.
// For the list of contributors see $DD4hepINSTALL/doc/CREDITS.
//
// Author     : M.Frank
//
//==========================================================================

#ifndef DD4HEP_DDG4_GEANT4INPUTHANDLING_H
#define DD4HEP_DDG4_GEANT4INPUTHANDLING_H

// Framework include files
#include "DDG4/Geant4Primary.h"

// Forward declarations
class G4Event;
class G4PrimaryVertex;
class G4PrimaryParticle;


/// Namespace for the AIDA detector description toolkit
namespace DD4hep {

  /// Namespace for the Geant4 based simulation part of the AIDA detector description toolkit
  namespace Simulation {

    // Forward declarations
    class Geant4Action;
    class Geant4Context;

    /** Helpers to import and export G4 records  */

    /// Create a vertex object from it's G4 counterpart
    Geant4Vertex* createPrimary(const G4PrimaryVertex* g4);
    
    /// Create a particle object from it's G4 counterpart
    Geant4Particle* createPrimary(int particle_id, const Geant4Vertex* v, const G4PrimaryParticle* g4p);

    /// Create a DDG4 interaction record from a Geant4 interaction defined by a primary vertex
    Geant4PrimaryInteraction* createPrimary(int mask, Geant4PrimaryMap* pm, const G4PrimaryVertex* gv);

    /// Initialize the generation of one event
    int generationInitialization(const Geant4Action* caller,const Geant4Context* context);

    /// Merge all interactions present in the context
    int mergeInteractions(const Geant4Action* caller,const Geant4Context* context);

    /// Boost particles of one interaction identified by its mask
    int boostInteraction(const Geant4Action* caller,
                         Geant4PrimaryEvent::Interaction* inter,
                         double alpha);

    /// Smear the primary vertex of an interaction
    int smearInteraction(const Geant4Action* caller,
                         Geant4PrimaryEvent::Interaction* inter,
                         double dx, double dy, double dz, double dt);


    /// Generate all primary vertices corresponding to the merged interaction
    int generatePrimaries(const Geant4Action* caller,
                          const Geant4Context* context,
                          G4Event* event);

  }    // End namespace Simulation
}      // End namespace DD4hep
#endif /* DD4HEP_DDG4_GEANT4INPUTHANDLING_H  */
