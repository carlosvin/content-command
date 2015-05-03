FROM grpc/cxx 

MAINTAINER Carlos Martin Sanchez "carlosvin@gmail.com"


#Install cms light
RUN git clone git@github.com:carlosvin/cms-light.git
RUN cd cms-light
RUN ./gradlew installContent_serverExecutable
RUN ./build/install/content_serverExecutable/content_server