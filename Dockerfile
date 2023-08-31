FROM ubuntu:latest

# Create a user to own the services
RUN useradd -d /vme -m -U -s /bin/bash dikumud
USER dikumud:dikumud

# Copy in all the required files for the server
COPY --chown=dikumud:dikumud vme vme
WORKDIR /vme

# This doesn't come out of the repositry executable
RUN chmod 755 entrypoint.sh

EXPOSE 4242/tcp
ENTRYPOINT [ "entrypoint.sh" ]
#ENTRYPOINT [ "bash", "-c", "while true ; do sleep 600 ; done" ]