AM_CXXFLAGS = -std=c++11 -I$(top_srcdir)/libaggregaterepo -I$(top_srcdir)/test
AM_LDFLAGS  = -lprotobuf -lgrpc -lgrpc++ -L$(top_srcdir)/libaggregaterepo


# TESTS

TESTS =  uuidTests aggregateTests

check_PROGRAMS = $(TESTS)

uuidTests_SOURCES 		= uuid.cpp
uuidTests_LDADD 		= -laggregaterepo

aggregateTests_SOURCES 	= aggregate.cpp
aggregateTests_LDADD 	= -laggregaterepo
