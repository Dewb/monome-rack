FROM alpine/curl

LABEL "com.github.actions.name"="Tag latest"
LABEL "com.github.actions.description"="Delete and recreate the 'latest' tag on the head revision"
LABEL "com.github.actions.icon"="briefcase"
LABEL "com.github.actions.color"="gray-dark"

ADD entrypoint.sh /entrypoint.sh
RUN chmod a+x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]