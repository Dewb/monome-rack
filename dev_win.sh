#!/bin/sh

export DIR=$(realpath "$(dirname "${BASH_SOURCE[0]}")")
export RACK_DIR=${DIR}/Rack-SDK 
export RACK_USER_DIR=/c/Users/${USERNAME}/OneDrive/Documents/Rack 
export STRIP=echo 

echo RACK_DIR: ${RACK_DIR}
echo RACK_USER_DIR: ${RACK_USER_DIR}

make -j4 install

