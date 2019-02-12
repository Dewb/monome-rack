#!/bin/sh

set -eu

# Update the "latest" tag
git tag -d latest
git push origin :refs/tags/latest
git tag latest
git push origin latest

