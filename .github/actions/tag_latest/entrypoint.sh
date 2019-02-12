#!/bin/sh

set -eu

GITHUB_API_URL=https://api.github.com/

# If the action was triggered on a branch other than master, terminate with neutral status
if ["${GITHUB_REF}" != "refs/heads/master"]; then
    exit 78
fi

# Update the "latest" tag
TAG=latest
REF=refs/heads/master
curl \
    --header "Authorization: token ${GITHUB_TOKEN}" \
    --header "Content-Type: application/json" \
    --request PATCH \
    --data '{ "force":"false", "sha":"${GITHUB_SHA}" }' \
    ${GITHUB_API_URL}/repos/${GITHUB_REPOSITORY}/git/refs/${TAG}

