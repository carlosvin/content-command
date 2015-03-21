AM_CXXFLAGS = -std=c++11

bin_PROGRAMS	= client server
lib_LIBRARIES = libcms.a



client_SOURCES		= client.cpp

server_SOURCES		= cms.pb.h cms.pb.cc server.cpp

libcms_a_SOURCES 	= ReportResponse.cpp ReportResponse.h

AM_LDFLAGS = -lgrpc -lgrpc++ -lprotobuf

