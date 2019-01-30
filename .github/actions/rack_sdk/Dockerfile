FROM buildpack-deps:jessie-curl

LABEL "com.github.actions.name"="Fetch Rack SDK"
LABEL "com.github.actions.description"="Download and unzip the Rack SDK"
LABEL "com.github.actions.icon"="briefcase"
LABEL "com.github.actions.color"="gray-dark"

RUN yum install unzip

RUN curl -L https://vcvrack.com/downloads/Rack-SDK-0.6.2.zip -o rack-sdk.zip && unzip rack-sdk.zip && rm rack-sdk.zip

RUN mkdir plugins
