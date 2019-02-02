#!/bin/sh

set -eu

export RACK_DIR=${GITHUB_WORKSPACE}/Rack-SDK
export RACK_USER_DIR=${GITHUB_WORKSPACE}
export CROSS_TRIPLE=x86_64-apple-darwin

/usr/bin/crossbuild make clean
/usr/bin/crossbuild make install