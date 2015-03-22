

AM_CXXFLAGS = -std=c++11 -I../libcmslight
AM_LDFLAGS = -L../libcmslight

bin_PROGRAMS	= client

client_SOURCES	= client.cpp

client_LDADD 	= -lcmslight -lgrpc -lgrpc++ -lprotobuf
