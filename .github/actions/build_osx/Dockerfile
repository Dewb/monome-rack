FROM multiarch/crossbuild

LABEL "com.github.actions.name"="VCVRackPluginBuilder-OSX"
LABEL "com.github.actions.description"="Builds a VCV Rack plugin for OS X"
LABEL "com.github.actions.icon"="headphones"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="TBD"
LABEL "homepage"="TBD"
LABEL "maintainer"="dewb"

ENV CROSS_TRIPLE=x86_64-apple-darwin
ENV RACK_DIR=${GITHUB_WORKSPACE}/Rack-SDK
ENV RACK_USER_DIR=${GITHUB_WORKSPACE}

RUN echo ARCH_MAC := 1 > ${RACK_DIR}/arch.mk
RUN echo ARCH := mac >> ${RACK_DIR}/arch.mk

ENTRYPOINT ["/usr/bin/crossbuild", "make", "install"]