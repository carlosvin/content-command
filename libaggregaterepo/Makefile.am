AM_CXXFLAGS = -std=c++11
AM_LDFLAGS 				= -lprotobuf -lgrpc -lgrpc++ 

lib_LIBRARIES			= libaggregaterepo.a

libaggregaterepo_a_SOURCES   = Aggregate.cpp Uuid.cpp

libaggregaterepo_a_dir = $(includedir)/aggregaterepo
libaggregaterepo_a__HEADERS = Aggregate.h Uuid.h

server_LADD 	= -lhiredis -lm

# TESTS

TESTS =  uuidTests aggregateTests

check_PROGRAMS = $(TESTS)

uuidTests_SOURCES 		= tests/uuid.cpp
uuidTests_CPPFLAGS		= -I$(top_srcdir)/bandit-1.1.4
uuidTests_LDADD = -laggregaterepo
uuidTests_LDFLAGS = -L.

aggregateTests_SOURCES 	= tests/aggregate.cpp
aggregateTests_CPPFLAGS		= -I$(top_srcdir)/bandit-1.1.4
aggregateTests_LDADD = -laggregaterepo
aggregateTests_LDFLAGS = -L.
