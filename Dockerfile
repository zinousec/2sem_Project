FROM ubuntu:18.04
COPY ./echoServer /usr/src/serv
WORKDIR /usr/src/serv

RUN apt-get update && apt-get install -y build-essential
RUN apt-get install -y qt5-default
RUN qmake echoServer.pro
RUN make 

ENTRYPOINT ["./echoServer"]
