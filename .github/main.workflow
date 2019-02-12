workflow "Build on push" {
  on = "push"
  resolves = ["Tag Latest"]
}

action "Fetch Submodules" {
  uses = "./.github/actions/submodules"
}

action "Fetch Rack SDK" {
  uses = "./.github/actions/rack_sdk"
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

action "Tag Latest" {
  uses = "./.github/actions/tag_latest"
  needs = ["Build Linux"]
  secrets = ["GITHUB_TOKEN"]
}
