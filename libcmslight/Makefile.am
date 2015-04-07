
cmslightdir = $(includedir)/cmslight
cmslight_HEADERS = cms.pb.h ServerRunner.h RedisWrapper.h

AM_CXXFLAGS = -std=c++11 -I$(cmslightdir)
AM_LDFLAGS 				= -lgrpc -lgrpc++ -lprotobuf -lhiredis -lm


lib_LIBRARIES			= libcmslight.a

libcmslight_a_SOURCES   = cms.pb.cc ServerRunner.cpp RedisWrapper.cpp

#libcmslight_a_LIBADD = -lgrpc -lgrpc++ -lprotobuf -lhiredis -lm

