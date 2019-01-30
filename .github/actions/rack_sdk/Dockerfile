FROM ubuntu:16.04

LABEL "com.github.actions.name"="Fetch Rack SDK"
LABEL "com.github.actions.description"="Download and unzip the Rack SDK"
LABEL "com.github.actions.icon"="briefcase"
LABEL "com.github.actions.color"="gray-dark"

RUN apt-get update
RUN apt-get install -y curl unzip

RUN env

RUN curl -L https://vcvrack.com/downloads/Rack-SDK-0.6.2.zip -o rack-sdk.zip && unzip rack-sdk.zip && rm rack-sdk.zip

RUN mkdir plugins
