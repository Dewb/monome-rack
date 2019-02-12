#!/bin/sh

# Expects RACK_SDK_VERSION environment variable to be set in workflow

set -eu

curl -L https://vcvrack.com/downloads/Rack-SDK-${RACK_SDK_VERSION}.zip -o rack-sdk.zip
unzip -o rack-sdk.zip
rm rack-sdk.zip

mkdir -p plugins
