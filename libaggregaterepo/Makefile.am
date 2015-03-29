AM_CXXFLAGS = -std=c++11
AM_LDFLAGS 				= -lprotobuf -lgrpc -lgrpc++ 

lib_LIBRARIES			= libaggregaterepo.a

libaggregaterepo_a_SOURCES   = Aggregate.cpp Uuid.cpp

libaggregaterepo_a_dir = $(includedir)/aggregaterepo
libaggregaterepo_a__HEADERS = Aggregate.h Uuid.h

server_LADD 	= -lhiredis -lm
