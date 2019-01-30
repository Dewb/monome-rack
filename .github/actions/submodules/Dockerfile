FROM alpine/git

LABEL "com.github.actions.name"="Submodules"
LABEL "com.github.actions.description"="Fetch submodules"
LABEL "com.github.actions.icon"="briefcase"
LABEL "com.github.actions.color"="gray-dark"

ENTRYPOINT ["git", "submodule", "update", "--init", "--recursive"]