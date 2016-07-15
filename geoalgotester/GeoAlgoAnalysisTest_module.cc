/** ****************************************************************************
* @file   GeoAlgoAnalysisTest_module.cc
* @brief  Runs GeoAlgo unit GeoAlgoAnalysisTests
* @author Luke Simons (lsimons@fnal.gov)
* @date   July 1st, 2015
*/

#ifndef GeoAlgoAnalysisTest_Module
#define GeoAlgoAnalysisTest_Module

// LArSoft includes
#include "larcoreobj/GeoAlgo/GeoAlgo.h"
#include "larcoreobj/GeoAlgo/GeoVector.h"
#include "lardataobj/RecoBase/Hit.h" // For recob::Hits

// Framework includes
#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "fhiclcpp/ParameterSet.h"

namespace art { class Event; } // art::Event declaration

namespace GeoAlgoAnalysisTest {
  /**
   * @brief Performs GeoAlgoAnalysisTests on GeoAlgo.
   * 
   * Configuration parameters
   * =========================
   * 
   * See GeometryTestAlg.
   */
  class GeoAlgoAnalysisTest : public art::EDAnalyzer
  {
  public:
 
    // Standard constructor for an ART module; we don't need a special
    // destructor here.
    /// Default constructor
 
    explicit GeoAlgoAnalysisTest(fhicl::ParameterSet const& pset);

    virtual void analyze (const art::Event& event) override;
    virtual void beginJob() override;

  private:
    art::InputTag fHitLabel;
    geoalgo::GeoAlgo GeoAlgoAnalysisTester;
  }; // class GeoAlgoAnalysisTest


  //-----------------------------------------------------------------------
  //-----------------------------------------------------------------------
  // class implementation

  //-----------------------------------------------------------------------
  // Constructor
  GeoAlgoAnalysisTest::GeoAlgoAnalysisTest(fhicl::ParameterSet const& pset)
    : EDAnalyzer(pset), fHitLabel (pset.get<art::InputTag>("hitlabel"))//, GeoAlgoAnalysisTester(new geo::GeometryTestAlg(pset))
  { 
  } //GeoAlgoAnalysisTest::GeoAlgoAnalysisTest()

  
  //......................................................................
  void GeoAlgoAnalysisTest::beginJob()
  {  
  } //GeoAlgoAnalysisTest::beginJob()

   

   void GeoAlgoAnalysisTest::analyze(const art::Event& event){

    art::ValidHandle< std::vector<recob::Hit> > hitHandle
      = event.getValidHandle<std::vector<recob::Hit>>
      (fHitLabel);

    for ( auto const& hit : (*hitHandle) ){

      auto hitTime = hit.PeakTime();

      if( hitTime != 0 ){
//        std::cout << "\narb is: " << hitTime;
      }
    }
  }

  //......................................................................
  DEFINE_ART_MODULE(GeoAlgoAnalysisTest)

} // namespace GeoAlgoAnalysisTest

#endif // GeoAlgoAnalysisTest_Module
