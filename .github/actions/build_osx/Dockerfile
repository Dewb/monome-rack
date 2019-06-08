FROM debian

LABEL "com.github.actions.name"="VCVRackPluginBuilder-OSX"
LABEL "com.github.actions.description"="Builds a VCV Rack plugin for OS X"
LABEL "com.github.actions.icon"="headphones"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="TBD"
LABEL "homepage"="TBD"
LABEL "maintainer"="dewb"

RUN apt-get update && \
    apt-get upgrade -yy && \
    apt-get install -yy \
    automake            \
    bison               \
    curl                \
    file                \
    flex                \
    git                 \
    libtool             \
    pkg-config          \
    python              \
    texinfo             \
    vim                 \
    wget                \
    zlib1g-dev          \
    build-essential     \
    cmake               \
    make                \
    tar                 \
    unzip               \
    zip                 \
    libgl1-mesa-dev     \
    libglu1-mesa-dev    \
    jq

# Install osxcross
# NOTE: The Docker Hub's build machines run varying types of CPUs, so an image
# built with `-march=native` on one of those may not run on every machine - I
# ran into this problem when the images wouldn't run on my 2013-era Macbook
# Pro.  As such, we remove this flag entirely.
ENV OSXCROSS_SDK_VERSION 10.11
RUN SDK_VERSION=$OSXCROSS_SDK_VERSION                           \
    mkdir /opt/osxcross &&                                      \
    cd /opt &&                                                  \
    git clone https://github.com/tpoechtrager/osxcross.git &&   \
    cd osxcross &&                                              \
    git checkout e0a171828a72a0d7ad4409489033536590008ebf &&    \
    sed -i -e 's|-march=native||g' ./build_clang.sh ./wrapper/build.sh && \
    ./tools/get_dependencies.sh &&                              \
    curl -L -o ./tarballs/MacOSX${OSXCROSS_SDK_VERSION}.sdk.tar.xz \
    https://github.com/apriorit/osxcross-sdks/raw/master/MacOSX${OSXCROSS_SDK_VERSION}.sdk.tar.xz && \
    yes | PORTABLE=true ./build.sh &&                           \
    ./build_compiler_rt.sh

ENV PATH $PATH:/opt/osxcross/target/bin

ADD entrypoint.sh /entrypoint.sh
RUN chmod a+x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]