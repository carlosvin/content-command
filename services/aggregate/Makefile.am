AM_CXXFLAGS = -std=c++11 -I../../libcmslight -I../../libaggregaterepo
AM_LDFLAGS = -L../../libcmslight -L../../libaggregaterepo

bin_PROGRAMS	= server

server_SOURCES	= server.cpp AggregateRepositoryImpl.cpp AggregateRepositoryImpl.h

server_LDADD 	= -lcmslight -laggregaterepo -lgrpc -lgrpc++ -lprotobuf -lhiredis -lm
