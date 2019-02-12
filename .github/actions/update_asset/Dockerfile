FROM ellerbrock/alpine-bash-curl-ssl

LABEL "com.github.actions.name"="Update Release Asset"
LABEL "com.github.actions.description"="Post a file as an asset in an existing release"
LABEL "com.github.actions.icon"="briefcase"
LABEL "com.github.actions.color"="gray-dark"

ADD entrypoint.sh /entrypoint.sh
RUN chmod a+x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]