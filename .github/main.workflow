workflow "Build on push" {
  on = "push"
  resolves = ["VCVRackPluginBuilder"]
}

action "Submodules" {
  uses = "./.github/actions/submodules"
}

action "VCVRackPluginBuilder" {
  uses = "./.github/actions/build"
  needs = ["Submodules"]
}
