#!/bin/sh

bin/vme -s etc/server.cfg -l log/vme.log &
bin/mplex -p 4242 -l log/mplex.log
