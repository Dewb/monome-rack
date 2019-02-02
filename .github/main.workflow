workflow "Build on push" {
  on = "push"
  resolves = ["Build Windows"]
}

action "Fetch Submodules" {
  uses = "./.github/actions/submodules"
}

action "Fetch Rack SDK" {
  uses = "./.github/actions/rack_sdk"
}

action "Build Linux" {
  uses = "./.github/actions/build_linux"
  needs = ["Fetch Submodules", "Fetch Rack SDK"]
}

action "Build OS X" {
  uses = "./.github/actions/build_osx"
  needs = ["Build Linux"]
}

action "Build Windows" {
  uses = "./.github/actions/build_win"
  needs = ["Build OS X"]
}
