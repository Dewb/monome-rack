FROM multiarch/crossbuild

LABEL "com.github.actions.name"="VCVRackPluginBuilder-Windows"
LABEL "com.github.actions.description"="Builds a VCV Rack plugin for Windows"
LABEL "com.github.actions.icon"="headphones"
LABEL "com.github.actions.color"="purple"

LABEL "repository"="TBD"
LABEL "homepage"="TBD"
LABEL "maintainer"="dewb"

ADD entrypoint.sh /entrypoint.sh
RUN chmod a+x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]