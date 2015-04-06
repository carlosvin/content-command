AM_CXXFLAGS = -std=c++11 -I../../libcmslight
AM_LDFLAGS = -L../../libcmslight

bin_PROGRAMS	= server

server_SOURCES	= server.cpp ContentCmdHandlerImpl.cpp ContentCmdHandlerImpl.h

server_LDADD 	= -lcmslight -lgrpc -lgrpc++ -lprotobuf -lhiredis -lm
