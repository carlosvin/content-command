FROM grpc/cxx 

MAINTAINER Carlos Martin Sanchez "carlosvin@gmail.com"


#Install cms light
RUN cd /tmp
RUN git clone git@github.com:carlosvin/cms-light.git
RUN cd cms-light

