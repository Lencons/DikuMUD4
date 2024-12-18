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


# Create player data directories if they don't exist.
log "Checking player data directories: $PLAYERS_DIR"
for dir in a b c d e f g h i j k l m n o p q r s t u v w x y z 0 1 2 3 4 5 6 7 8 9; do
    if [ ! -d "$PLAYERS_DIR/$dir" ]; then
        log "Creating player hash directory: $PLAYERS_DIR/$dir"
        mkdir -p $PLAYERS_DIR/$dir
    fi
done


# Start the server and mplex
#
# The server currently needs to be started from the bin directory. Something that needs
# to be looked at.
cd bin
$VME_ROOT/bin/vme -s $VME_ROOT/etc/server.cfg -l $VME_ROOT/log/vme.log &
$VME_ROOT/bin/mplex -p 4242 -l $VME_ROOT/log/mplex.log

# keep the container alive.
while true; do sleep 3600 ; done
