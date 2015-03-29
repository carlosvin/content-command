FROM ubuntu

MAINTAINER Carlos Martin Sanchez "carlosvin@gmail.com"

# Update aptitude with new repo
RUN apt-get update

# Install software 
RUN apt-get install build-essential autoconf libtool git redis

# Install grpc lib
RUN cd /tmp
RUN git clone https://github.com/grpc/grpc.git
RUN cd grpc
RUN git submodule update --init
RUN make
RUN sudo make install

# Install hiredis lib
RUN cd /tmp
RUN git clone git@github.com:redis/hiredis.git
RUN cd hiredis
RUN make
RUN sudo make install

#Install cms light
RUN cd /tmp
RUN git clone git@github.com:carlosvin/cms-light.git
RUN cd cms-light
# ?RUN autoreconf -i
RUN ./configure
RUN make all
RUN sudo make install