workflow "Build Latest" {
  on = "push"
  resolves = ["Upload Linux Release"]
}

action "Fetch Submodules" {
  uses = "./.github/actions/submodules"
}

action "Fetch Rack SDK" {
  uses = "./.github/actions/rack_sdk"
  env = {
    RACK_SDK_VERSION = "0.6.2"
  }
}

action "Build Linux" {
  uses = "./.github/actions/build_linux"
  needs = ["Fetch Rack SDK", "Fetch Submodules"]
}

action "Build OS X" {
  uses = "./.github/actions/build_osx"
  needs = ["Fetch Rack SDK", "Fetch Submodules"]
}

action "Build Windows" {
  uses = "./.github/actions/build_win"
  needs = ["Fetch Rack SDK", "Fetch Submodules"]
}

action "Tag Head as Latest" {
  uses = "./.github/actions/update_tag"
  needs = ["Build Linux"]
  secrets = ["GITHUB_TOKEN"]
  env = {
    TAG = "latest"
    REF = "refs/heads/master"
  }
}

action "Upload Linux Release" {
  uses = "./.github/actions/update_asset"
  needs = ["Tag Head as Latest"]
  secrets = ["GITHUB_TOKEN"]
  env = {
    ASSET_PATH = "plugins/monome-0.6.0-lin.zip"
    RELEASE_TAG = "latest"
  }
}