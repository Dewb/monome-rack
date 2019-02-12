FROM jess/curl

LABEL "com.github.actions.name"="Update tag"
LABEL "com.github.actions.description"="Sets a tag to the head of a ref"
LABEL "com.github.actions.icon"="tag"
LABEL "com.github.actions.color"="gray-dark"

ADD entrypoint.sh /entrypoint.sh
RUN chmod a+x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]