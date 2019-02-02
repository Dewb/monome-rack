#!/bin/sh

set -eu

curl -L https://vcvrack.com/downloads/Rack-SDK-0.6.2.zip -o rack-sdk.zip
unzip -o rack-sdk.zip
rm rack-sdk.zip

mkdir -p plugins
