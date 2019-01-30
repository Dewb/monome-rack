FROM multiarch/crossbuild

LABEL "com.github.actions.name"="VCVRackPluginBuilder-Windows"
LABEL "com.github.actions.description"="Builds a VCV Rack plugin for Windows"
LABEL "com.github.actions.icon"="headphones"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="TBD"
LABEL "homepage"="TBD"
LABEL "maintainer"="dewb"

ENV CROSS_TRIPLE=x86_64-w64-mingw32
ENV RACK_DIR=${GITHUB_WORKSPACE}/Rack-SDK
ENV RACK_USER_DIR=${GITHUB_WORKSPACE}

ENTRYPOINT ["/usr/bin/crossbuild", "make", "install"]