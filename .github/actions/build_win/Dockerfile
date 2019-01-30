FROM multiarch/crossbuild

LABEL "com.github.actions.name"="VCVRackPluginBuilder-Windows"
LABEL "com.github.actions.description"="Builds a VCV Rack plugin for Windows"
LABEL "com.github.actions.icon"="headphones"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="TBD"
LABEL "homepage"="TBD"
LABEL "maintainer"="dewb"

ENV CROSS_TRIPLE=x86_64-w64-mingw32
ENV RACK_DIR=/github/workspace/Rack-SDK
ENV RACK_USER_DIR=/github/workspace

RUN echo ARCH_WIN := 1 > ${RACK_DIR}/arch.mk
RUN echo ARCH := win >> ${RACK_DIR}/arch.mk


ENTRYPOINT ["/usr/bin/crossbuild", "make", "install"]