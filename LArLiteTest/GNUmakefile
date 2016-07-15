#
# This is an example GNUmakefile for my packages
#

# specific names for this package
DICT  = geoalgotester_LArLiteTestDict
SHLIB = libgeoalgotester_LArLiteTest.so
SOURCES = $(filter-out $(DICT).cxx, $(wildcard *.cxx))
FMWK_HEADERS = LinkDef.h $(DICT).h
HEADERS = $(filter-out $(FMWK_HEADERS), $(wildcard *.h))
OBJECTS = $(SOURCES:.cxx=.o)

# include options for this package
INCFLAGS  = -I.                       #Include itself
INCFLAGS += -I$(LARLITE_USERDEVDIR)/larcoreobj/
INCFLAGS += -I$(LARDATAOBJ_INC)
INCFLAGS += -I$(LARCOREOBJ_INC)
INCFLAGS += $(shell larlite-config --includes)

INCLUDE_DIRS += $(LARLITE_USERDEVDIR)/larcoreobj/

# platform-specific options
OSNAME          = $(shell uname -s)
HOST            = $(shell uname -n)
OSNAMEMODE      = $(OSNAME)

# call kernel specific compiler setup
include $(LARLITE_BASEDIR)/Makefile/Makefile.${OSNAME}

# call the common GNUmakefile
LDFLAGS += $(shell larlite-config --libs)
include $(LARLITE_BASEDIR)/Makefile/GNUmakefile.CORE


