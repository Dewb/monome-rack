FROM ubuntu:16.04

LABEL "com.github.actions.name"="Submodules"
LABEL "com.github.actions.description"="Fetch submodules"
LABEL "com.github.actions.icon"="briefcase"
LABEL "com.github.actions.color"="gray-dark"

RUN apt-get update
RUN apt-get install -y git

ENTRYPOINT ["git", "submodule", "update", "--init", "--recursive"]