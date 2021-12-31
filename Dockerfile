# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
ARG DEBIAN_FRONTEND=noninteractive
FROM ubuntu:latest
FROM gcc:latest
RUN apt-get -y update && apt-get install -y
RUN DEBIAN_FRONTEND=noninteractive apt-get -y install cmake \
        git \
        build-essential \
		pkg-config \
		libgtest-dev \
		valgrind 
		
# These commands copy your files into the specified directory in the image
# and set that as the working location
#COPY . /usr/src/myapp
#WORKDIR /workspaces/Algorithms/build
LABEL Name=algorithms Version=0.0.1

