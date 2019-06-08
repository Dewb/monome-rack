#!/bin/sh

set -eu

export RACK_DIR=${GITHUB_WORKSPACE}/Rack-SDK
export RACK_USER_DIR=${GITHUB_WORKSPACE}

export CC=x86_64-apple-darwin15-clang
export CXX=x86_64-apple-darwin15-clang++
export STRIP=x86_64-apple-darwin15-strip

make clean
make install