#!/bin/sh

set -eu

export RACK_DIR=${GITHUB_WORKSPACE}/Rack-SDK
export RACK_USER_DIR=${GITHUB_WORKSPACE}

git submodule update --init --recursive

curl -L https://vcvrack.com/downloads/Rack-SDK-${RACK_SDK_VERSION}.zip -o rack-sdk.zip
unzip -o rack-sdk.zip
rm rack-sdk.zip

mkdir -p plugins

make clean
make install
