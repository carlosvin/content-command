FROM grpc/cxx 

MAINTAINER Carlos Martin Sanchez "carlosvin@gmail.com"

RUN apt-get update
RUN apt-get install -y scons


#Install cms light

RUN git clone https://github.com/carlosvin/cms-light.git
WORKDIR /cms-light
RUN git pull
RUN scons
ENTRYPOINT ./content_server
