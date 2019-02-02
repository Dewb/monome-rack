FROM ubuntu:16.04

LABEL "com.github.actions.name"="Fetch Rack SDK"
LABEL "com.github.actions.description"="Download and unzip the Rack SDK"
LABEL "com.github.actions.icon"="briefcase"
LABEL "com.github.actions.color"="gray-dark"

RUN apt-get update
RUN apt-get install -y curl unzip

ADD entrypoint.sh /entrypoint.sh
RUN chmod a+x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
