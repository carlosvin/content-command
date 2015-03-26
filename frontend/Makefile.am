

AM_CXXFLAGS = -std=c++11 -I../libcmslight
AM_LDFLAGS = -L../libcmslight

bin_PROGRAMS	= client_aggregate client_content_cmd

client_aggregate_SOURCES	= client_aggregate.cpp 
client_content_cmd_SOURCES	= client_content_cmd.cpp

client_aggregate_LDADD 		= -lcmslight -lgrpc -lgrpc++ -lprotobuf
client_content_cmd_LDADD 	= -lcmslight -lgrpc -lgrpc++ -lprotobuf
