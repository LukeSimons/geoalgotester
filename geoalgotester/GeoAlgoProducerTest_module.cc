/** ****************************************************************************
* @file   GeoAlgoProducerTest_module.cc
* @brief  Runs GeoAlgo unit GeoAlgoProducerTests
* @author Luke Simons (lsimons@fnal.gov)
* @date   July 1st, 2015
*/

#ifndef GeoAlgoProducerTest_Module
#define GeoAlgoProducerTest_Module

// LArSoft includes
#include "larcoreobj/GeoAlgo/GeoAlgo.h"
#include "larcoreobj/GeoAlgo/GeoVector.h"
#include "lardataobj/RecoBase/Hit.h" // For recob::Hits

// Framework includes
#include "art/Framework/Core/EDProducer.h"
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "fhiclcpp/ParameterSet.h"

namespace art { class Event; } // art::Event declaration

namespace GeoAlgoProducerTest {
  /**
   * @brief Performs GeoAlgoProducerTests on GeoAlgo.
   * 
   * Configuration parameters
   * =========================
   * 
   * See GeometryTestAlg.
   */
  class GeoAlgoProducerTest : public art::EDProducer
  {
  public:
 
    // Standard constructor for an ART module; we don't need a special
    // destructor here.
    /// Default constructor
 
    explicit GeoAlgoProducerTest(fhicl::ParameterSet const& pset);

    virtual void produce (art::Event& event) override;
    virtual void beginJob() override;

  private:
    art::InputTag fHitLabel;
    geoalgo::GeoAlgo GeoAlgoProducerTester;
  }; // class GeoAlgoProducerTest


  //-----------------------------------------------------------------------
  //-----------------------------------------------------------------------
  // class implementation

  //-----------------------------------------------------------------------
  // Constructor
  GeoAlgoProducerTest::GeoAlgoProducerTest(fhicl::ParameterSet const& pset)
    : EDProducer(), fHitLabel (pset.get<art::InputTag>("hitlabel")) //, GeoAlgoProducerTester(new geo::GeometryTestAlg(pset))
  {
    produces<std::vector<recob::Hit>>();
  } //GeoAlgoProducerTest::GeoAlgoProducerTest()

  
  //......................................................................
  void GeoAlgoProducerTest::beginJob()
  {
//    std::cout << "\nIn GeoAlgoProducerTest::beginJob()";    
  } //GeoAlgoProducerTest::beginJob()

   

   void GeoAlgoProducerTest::produce(art::Event& event){

    art::ValidHandle< std::vector<recob::Hit> > hitHandle
      = event.getValidHandle<std::vector<recob::Hit>>
      (fHitLabel);

    std::unique_ptr<std::vector<recob::Hit> > recobhit(new std::vector<recob::Hit>);

    geoalgo::Vector vec_k = geoalgo::Vector(3,4,5);

    for ( auto const& hit : (*hitHandle) ){

      auto hitTime = hit.PeakTime();

      if( hitTime != 0 ){
//        std::cout << "\nhitTime is: " << hitPeak; 
//        std::cout << "\nvec_k.Length() is: " << vec_k.Length();
        double arb = hitTime * (vec_k.Length());
//        std::cout << "\narb is: " << arb;
 
        recobhit->emplace_back(
                hit.Channel(),//ChanID,
		hit.StartTick(),//timetick,
		hit.EndTick(),//timetick,
		arb,
		hit.SigmaPeakTime(),//fl,
		hit.RMS(),//fl,
		hit.PeakAmplitude(),//fl,
		hit.SigmaPeakAmplitude(),//fl,
		hit.SummedADC(),//fl,
		hit.Integral(),//fl,
		hit.SigmaIntegral(),//fl,
		hit.Multiplicity(),//shint,
		hit.LocalIndex(),//shint,
		hit.GoodnessOfFit(),//fl,
	 	hit.DegreesOfFreedom(),//i,
                hit.View(),//geo::View_t(),
 		hit.SignalType(),//geo::SigType_t(), 
		hit.WireID() //geo::WireID()
                );         
      }
    }
    event.put(std::move(recobhit));

//    e.put(std::move(rawdigit_ptr));
//    recobhit->put_into(event); 
  }

  //......................................................................
  DEFINE_ART_MODULE(GeoAlgoProducerTest)

} // namespace GeoAlgoProducerTest

#endif // GeoAlgoProducerTest_Module
