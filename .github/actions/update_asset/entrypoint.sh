#!/bin/sh

# expects RELEASE_TAG and ASSET_PATH environment variables

set -eu

GITHUB_API_URL=https://api.github.com
GITHUB_UPLOAD_URL=https://uploads.github.com

REPO=${GITHUB_REPOSITORY#"https://github.com/"} # work around url parsing bug in act for local testing

# If the action was triggered on a branch other than master, terminate with neutral status
if [ ${GITHUB_REF} != "refs/heads/master" ] ; then
    exit 78
fi

FILENAME=$(basename ${ASSET_PATH})

# Get information about the release
response=$(curl -i --header "Authorization: token ${GITHUB_TOKEN}" ${GITHUB_API_URL}/repos/${REPO}/releases/tags/${RELEASE_TAG})
eval $(echo "${response}" | grep -m 1 "id.:" | grep -w id | tr : = | tr -cd '[[:alnum:]]=')
[ "${id}" ] || { echo "Error: Failed to get release id for tag: ${RELEASE_TAG}"; exit 1; }
RELEASE_ID="${id}"

# If the release already has a file asset with this name, delete it
id=""
eval $(echo "${response}" | grep -C2 "name.:.\+${FILENAME}" | grep -m 1 "id.:" | grep -w id | tr : = | tr -cd '[[:alnum:]]=')
ASSET_ID="${id}"

if [ "${ASSET_ID}" != "" ]; then
    echo "Deleting existin asset ${ASSET_ID}"
    curl -i \
        --fail \
        --header "Authorization: token ${GITHUB_TOKEN}" \
        --header "Content-Type: application/octet-stream" \
        --request DELETE \
        ${GITHUB_API_URL}/repos/${REPO}/releases/assets/${ASSET_ID}
fi

# Upload the new asset to the release
curl -i \
    --header "Authorization: token ${GITHUB_TOKEN}" \
    --header "Content-Type: application/octet-stream" \
    --request POST \
    --data-binary @"${ASSET_PATH}" \
    ${GITHUB_UPLOAD_URL}/repos/${REPO}/releases/${RELEASE_ID}/assets?name=${FILENAME}

