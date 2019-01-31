FROM multiarch/crossbuild
USER root
WORKDIR ${GITHUB_WORKSPACE}

LABEL "com.github.actions.name"="VCVRackPluginBuilder-OSX"
LABEL "com.github.actions.description"="Builds a VCV Rack plugin for OS X"
LABEL "com.github.actions.icon"="headphones"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="TBD"
LABEL "homepage"="TBD"
LABEL "maintainer"="dewb"

RUN env

ENV CROSS_TRIPLE=x86_64-apple-darwin

RUN curl -L https://vcvrack.com/downloads/Rack-SDK-0.6.2.zip -o rack-sdk.zip && unzip rack-sdk.zip && rm rack-sdk.zip
ENV RACK_DIR=${GITHUB_WORKSPACE}/Rack-SDK
ENV RACK_USER_DIR=${GITHUB_WORKSPACE}

RUN mkdir plugins

ENTRYPOINT ["/usr/bin/crossbuild", "make", "install"]