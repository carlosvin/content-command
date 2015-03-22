AM_CXXFLAGS = -std=c++11
AM_LDFLAGS 				= -lprotobuf -lgrpc -lgrpc++ 

lib_LIBRARIES			= libcmslight.a

libcmslight_a_SOURCES   = cms.pb.cc ServerRunner.cpp ServerRunner.h

#libcmslight_a_LIBADD = -lgrpc -lgrpc++ -lprotobuf

cmslightdir = $(includedir)/cmslight
cmslight_HEADERS = cms.pb.h

