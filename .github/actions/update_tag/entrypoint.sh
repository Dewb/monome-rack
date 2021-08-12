#!/bin/sh

# expects TAG and REF environment variables set in workflow

set -eu

GITHUB_API_URL=https://api.github.com
REPO=${GITHUB_REPOSITORY#"https://github.com/"} # work around url parsing bug in act for local testing

# If the action was triggered on a different ref than specified, terminate with neutral status
if [ ${GITHUB_REF} != ${REF} ] ; then
    echo ref "${GITHUB_REF}" does not match expected "${REF}"
    exit 78
fi

# Update the tag to point to the ref
curl -i \
    --header "Authorization: token ${GITHUB_TOKEN}" \
    --header "Content-Type: application/json" \
    --request PATCH \
    --data "{ \"sha\": \"${GITHUB_SHA}\" }" \
    ${GITHUB_API_URL}/repos/${REPO}/git/refs/tags/${TAG}

