#ifndef LARLITE_GEOALGOANATEST_CXX
#define LARLITE_GEOALGOANATEST_CXX

#include "GeoAlgoAnaTest.h"
#include "lardataobj/RecoBase/Hit.h"
#include "DataFormat/wrapper.h"
#include "larcoreobj/GeoAlgo/GeoAlgo.h"
#include "larcoreobj/GeoAlgo/GeoVector.h"

namespace larlite {

  bool GeoAlgoAnaTest::initialize() {
    return true;
  }
  
  bool GeoAlgoAnaTest::analyze(storage_manager* storage) {

    // Use arbitary algorithm from shared repository
    geoalgo::Vector vec_k = geoalgo::Vector(3,4,5);
    
    // Access shared data products
    auto my_larsofthits = storage->get_data<larlite::wrapper<std::vector<recob::Hit> > >("testgeoalgoprod"); 

    auto Hits = my_larsofthits->product();
   
    // Output arbitrary value
    std::cout << "\narb is: " << Hits->at(0).PeakTime() * (vec_k.Length());
 
    return true;
  }

  bool GeoAlgoAnaTest::finalize() {
 
    return true;
  }

}
#endif
