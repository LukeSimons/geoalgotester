# basic source code CMakeLists.txt

#art_make( )

art_make(
  MODULE_LIBRARIES
    larcoreobj_GeoAlgo
    lardataobj_RecoBase
    art_Framework_Core
    art_Framework_Services_Registry
    art_Framework_Principal
    art_Utilities
    ${MF_MESSAGELOGGER}
    ${MF_UTILITIES}
    ${FHICLCPP}
  )

install_headers()
install_source()
install_fhicl()
