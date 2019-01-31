FROM ubuntu:16.04

LABEL "com.github.actions.name"="VCVRackPluginBuilder-Linux"
LABEL "com.github.actions.description"="Builds a VCV Rack plugin for Linux"
LABEL "com.github.actions.icon"="headphones"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="TBD"
LABEL "homepage"="TBD"
LABEL "maintainer"="dewb"

RUN env

RUN apt-get update
RUN apt-get install -y build-essential cmake curl gcc g++ git make tar unzip zip libgl1-mesa-dev libglu1-mesa-dev

RUN curl -L https://vcvrack.com/downloads/Rack-SDK-0.6.2.zip -o rack-sdk.zip && unzip rack-sdk.zip && rm rack-sdk.zip
ENV RACK_DIR=${GITHUB_WORKSPACE}/Rack-SDK
ENV RACK_USER_DIR=${GITHUB_WORKSPACE}

RUN mkdir plugins

ENTRYPOINT ["make", "install"]