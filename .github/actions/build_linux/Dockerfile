FROM ubuntu:16.04

LABEL "com.github.actions.name"="VCVRackPluginBuilder-Linux"
LABEL "com.github.actions.description"="Builds a VCV Rack plugin for Linux"
LABEL "com.github.actions.icon"="headphones"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="TBD"
LABEL "homepage"="TBD"
LABEL "maintainer"="dewb"

RUN apt-get update
RUN apt-get install -y build-essential cmake curl gcc g++ git make tar unzip zip libgl1-mesa-dev libglu1-mesa-dev

ENV RACK_DIR=${GITHUB_WORKSPACE}/Rack-SDK
ENV RACK_USER_DIR=${GITHUB_WORKSPACE}

RUN env

RUN echo ARCH_LIN := 1 > ${RACK_DIR}/arch.mk
RUN echo ARCH := lin >> ${RACK_DIR}/arch.mk

RUN curl -L https://vcvrack.com/downloads/Rack-SDK-0.6.2.zip -o rack-sdk.zip && unzip rack-sdk.zip && rm rack-sdk.zip

ENTRYPOINT ["make", "install"]