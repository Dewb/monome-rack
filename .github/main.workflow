workflow "Build Latest" {
  resolves = ["Upload Windows Release", "Upload Linux Release"]
  on = "push"
}

action "Fetch Submodules" {
  uses = "./.github/actions/submodules"
}

action "Fetch Rack SDK" {
  uses = "./.github/actions/rack_sdk"
  env = {
    RACK_SDK_VERSION = "1.dev.b4bd09a"
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
  needs = ["Build Linux"]
}

action "Tag Head as Latest" {
  uses = "./.github/actions/update_tag"
  needs = ["Build Linux", "Build Windows"]
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
    ASSET_PATH = "plugins/monome-1.0.0-pre-lin.zip"
    RELEASE_TAG = "latest"
  }
}

action "Upload Windows Release" {
  uses = "./.github/actions/update_asset"
  needs = ["Tag Head as Latest"]
  secrets = ["GITHUB_TOKEN"]
  env = {
    ASSET_PATH = "plugins/monome-1.0.0-pre-win.zip"
    RELEASE_TAG = "latest"
  }
}
