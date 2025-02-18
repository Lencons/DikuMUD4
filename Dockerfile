FROM debian:bookworm

# Configure DikuMUD installation variables.
ENV VME_ROOT=/vme

RUN apt-get update && \
    apt-get -y upgrade

# Install required shared libraries.
RUN apt-get install -y libboost-all-dev

# The following packages are included to help manage the operational server.
RUN apt-get install -y inetutils-telnet less vim curl wget procps

WORKDIR $VME_ROOT

# Copy DikuMUD server binaries and data into the continer.
COPY vme/bin/           bin/
COPY vme/etc/           etc/
COPY vme/include/       include/
COPY vme/lib/           lib/
COPY vme/zone/*.zon     zone/

# Compile the Zone files.
RUN cd zone && \
    ../bin/vmc -I../include/ -d../etc/ *.zon

# Create directories to which persistent storage will be mounted
RUN mkdir -p $VME_ROOT/data/players

# Create a log directory, until we can change this to output to the docker logs
RUN mkdir -p $VME_ROOT/log

# Make sure our entrypoint is executable.
RUN chmod 755 $VME_ROOT/bin/entrypoint.sh

# Clean up the container.
RUN apt-get clean && \
    rm -rf /var/lib/apt/lists/*

EXPOSE 4242/tcp
ENTRYPOINT [ "./bin/entrypoint.sh" ]
