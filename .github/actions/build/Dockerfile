FROM ubuntu:16.04

LABEL "com.github.actions.name"="VCVRackPluginBuilder"
LABEL "com.github.actions.description"="Builds a VCV Rack plugin"
LABEL "com.github.actions.icon"="headphones"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="TBD"
LABEL "homepage"="TBD"
LABEL "maintainer"="dewb"

RUN apt-get update
RUN apt-get install -y cmake curl gcc g++ git make tar unzip zip

RUN curl -L https://vcvrack.com/downloads/Rack-SDK-0.6.2.zip -o rack-sdk.zip && unzip rack-sdk.zip && rm rack-sdk.zip
ENV RACK_DIR=${GITHUB_WORKSPACE}/Rack-SDK

ENTRYPOINT ["make", "dist"]