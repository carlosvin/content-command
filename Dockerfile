FROM debian:latest

MAINTAINER Carlos Martin Sanchez "carlosvin@gmail.com"

RUN apt-get update && apt-get install -y \
  autoconf \
  autotools-dev \
  build-essential \
  curl \
  gcc \
  git \
  libc6-dbg \
  libc6-dev \
  libgtest-dev \
  libgflags-dev \
  libtool \
  make \
  scons \
  unzip && apt-get clean

RUN git clone https://github.com/grpc/grpc.git /var/local/git/grpc
RUN cd /var/local/git/grpc && \
  git submodule update --init --recursive

RUN cd /var/local/git/grpc/third_party/protobuf && \
  ./autogen.sh && \
  ./configure --prefix=/usr && \
  make -j12 && make check && make install && make clean

RUN cd /var/local/git/grpc && make install

#Install cms light

RUN git clone https://github.com/carlosvin/cms-light.git
WORKDIR /cms-light
RUN git pull
RUN scons

ENV port 10002

EXPOSE $port:$port

ENTRYPOINT ./content_server $port
