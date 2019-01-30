FROM multiarch/crossbuild

LABEL "com.github.actions.name"="VCVRackPluginBuilder-Windows"
LABEL "com.github.actions.description"="Builds a VCV Rack plugin for Windows"
LABEL "com.github.actions.icon"="headphones"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="TBD"
LABEL "homepage"="TBD"
LABEL "maintainer"="dewb"

ENV CROSS_TRIPLE=x86_64-w64-mingw32

RUN curl -L https://vcvrack.com/downloads/Rack-SDK-0.6.2.zip -o rack-sdk.zip && unzip rack-sdk.zip && rm rack-sdk.zip
ENV RACK_DIR=${GITHUB_WORKSPACE}/Rack-SDK
ENV RACK_USER_DIR=${GITHUB_WORKSPACE}

RUN mkdir plugins

ENTRYPOINT ["/usr/bin/crossbuild", "make", "install"]