FROM ubuntu:22.04

# Load required packages and libraries
RUN apt-get update \
  && apt-get install -y \
    libboost-all-dev \
    libssl-dev \
    telnet \
  && rm -rf /var/lib/apt/lists/*

# Create a user to own the services
RUN useradd -d /vme -m -U -s /bin/bash dikumud
USER dikumud:dikumud

# Copy in all the required files for the server
COPY --chown=dikumud:dikumud vme /vme
WORKDIR /vme

# This doesn't come out of the repositry executable
RUN chmod 755 /vme/entrypoint.sh

EXPOSE 4242/tcp
ENTRYPOINT [ "/vme/entrypoint.sh" ]
