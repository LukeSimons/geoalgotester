#ifndef LARLITE_GEOALGOANATEST_CXX
#define LARLITE_GEOALGOANATEST_CXX

#include "GeoAlgoAnaTest.h"

namespace larlite {

  bool GeoAlgoAnaTest::initialize() {
    return true;
  }
  
  bool GeoAlgoAnaTest::analyze(storage_manager* storage) {

    

//    auto my_larsofthits = (::larlite::wrapper<std::vector<recob::Hit> >*)(my_storage.get_data(larlite::data::kLarSoftHit,"test"));
    auto my_larsofthits = storage->get_data<larlite::wrapper<std::vector<recob::Hit> > >("test");
    
//    std::cout << "\n 0 RMS = " << my_larsofthits->product()->at(0).RMS() << ", 1 RMS = " << my_larsofthits->product()->at(1).RMS() << std::endl;

//    auto hit = storage->get_data<larsofthit>("Hit");

//    if ( !(ev_mct) ){ std::cout << "\n\nError! Storage manager failed to retrieve data."; return true; }

    std::cout << "\narb is: " << my_larsofthits->product()->at(0).PeakTime();
 
    return true;
  }

  bool GeoAlgoAnaTest::finalize() {
 
    return true;
  }

}
#endif
