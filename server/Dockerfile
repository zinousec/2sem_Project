FROM ubuntu:20.04
ENV TZ=Europe/Kiev
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp



RUN apt update
RUN DEBIAN_FRONTEND=noninteractive apt-get -y install qt5-default
RUN apt-get -y install build-essential

RUN qmake echoServer.pro
RUN make

ENTRYPOINT ["./echoServer"]