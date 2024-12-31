#!/bin/bash
#
# Container entry point script to run the DikuMUD server.
#

VME_ROOT="${VME_ROOT:-/vme}"
SERVER_CONFIG="$VME_ROOT/etc/container.cfg"
PLAYERS_DIR="$VME_ROOT/data/players"

# Generic 
function log {
    echo "entrypoint: $1"
}

# Start the server and mplex
#
# The server currently needs to be started from the bin directory.
#
# TODO: Something that needs to be looked at.
#
cd bin
$VME_ROOT/bin/vme -s $SERVER_CONFIG -l $VME_ROOT/log/vme.log &
$VME_ROOT/bin/mplex -p 4242 -l $VME_ROOT/log/mplex.log

# keep the container alive.
while true; do sleep 3600 ; done
