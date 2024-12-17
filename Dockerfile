FROM debian:bookworm

# Configure DikuMUD installation variables.
ENV VME_ROOT=/vme

RUN apt-get update && \
    apt-get -y upgrade

# The following packages are included to help managed the operational server.
RUN apt-get install -y inetutils-telnet less vim curl wget

WORKDIR $VME_ROOT

# Copy DikuMUD server binaries and data into the continer.
COPY vme/bin/           bin/
COPY vme/etc/           etc/
COPY vme/include/       include/
COPY vme/lib/           lib/
COPY vme/zones/*.zon    zones/
COPY vme/www/           www/

# Compile the Zone files.
RUN cd zones && \
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
CMD ["./bin/entrypoint.sh"]
