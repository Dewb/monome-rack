workflow "Build on push" {
  on = "push"
  resolves = ["Build Windows"]
}

action "Submodules" {
  uses = "./.github/actions/submodules"
}

action "Build Linux" {
  uses = "./.github/actions/build_linux"
  needs = ["Submodules"]
}

action "Build OS X" {
  uses = "./.github/actions/build_osx"
  needs = ["Build Linux"]
}

action "Build Windows" {
  uses = "./.github/actions/build_win"
  needs = ["Build OS X"]
}
