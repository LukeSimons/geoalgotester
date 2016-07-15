/**
 * \file GeoAlgoAnaTest.h
 *
 * \ingroup LArLiteTest
 * 
 * \brief Class def header for a class GeoAlgoAnaTest
 *
 * @author Luke Simons
 */

/** \addtogroup LArLiteTest

    @{*/

#ifndef LARLITE_GEOALGOANATEST_H
#define LARLITE_GEOALGOANATEST_H

// LArSoft includes
#include "larcoreobj/GeoAlgo/GeoAlgo.h"
#include "larcoreobj/GeoAlgo/GeoVector.h"
#include "lardataobj/RecoBase/Hit.h" // For recob::Hits

// LArLite includes
#include "Analysis/ana_base.h"

// C++ includes
#include <iostream>

namespace larlite {
  /**
     \class GeoAlgoAnaTest
     User custom analysis class made by Luke Simons
   */
  class GeoAlgoAnaTest : public ana_base{
  
  public:

    /// Default constructor
    GeoAlgoAnaTest(){ _name="GeoAlgoAnaTest"; _fout=0;}

    /// Default destructor
    virtual ~GeoAlgoAnaTest(){}

    /** IMPLEMENT in GeoAlgoAnaTest.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in GeoAlgoAnaTest.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in GeoAlgoAnaTest.cc! 
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();

  protected:

  private:
    geoalgo::GeoAlgo GeoAlgoAnalysisTester; 
  };
}
#endif

//**************************************************************************
// 
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */ // end of doxygen group 
