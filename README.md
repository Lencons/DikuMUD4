# DikuMUD Goes Forth

Our version of DikuMUD III using HTML, websockets and live Discord integrated but built for fun.

Pre-requisites:
* gcc/g++
* flex/bison (sudo apt-get install bison flex)
* boost devel (sudo apt-get install libboost-all-dev)
* OpenSSL devel (sudo apt-get install libssl-dev)
* Rapidjson devel (sudo apt-get install rapidjson-dev)
* Debian users look here for flex: https://github.com/Seifert69/DikuMUD3/issues?q=70

Optional:

* Doxygen (sudo apt-get install doxygen graphviz dia mscgen)
   
How to build & launch (using the new cmake)

1. First build the binaries:

See [CMake](README_cmake.md)* for more details.

```bash
cd dikumud4/
cmake .
make all -j8
make test # optionally run the unit tests
```

*Code documentation will be generated in docs/ after the build completes. [docs/index.html](docs/index.html)*

2. Now you're ready to launch, open four tabs in shell:
* gcc/g++
* flex/bison (sudo apt-get install bison flex)
* boost devel (sudo apt-get install libboost-all-dev)
* OpenSSL devel (sudo apt-get install libssl-dev)
* Rapidjson devel (sudo apt-get install rapidjson-dev)

```bash
cd ../bin/
./vme # tab1
tail -f vme.log # tab2
./mplex -w -p 4280 # tab3
tail -f mplex.log #tab4
```

You can also launch a telnet mplex using e.g. `mplex -p 4242` And then `telnet localhost 4242`. You can run several mplex'ers to the server, some supporting telnet some support web sockets.

3. To open the client

```bash
cd ../www/client/
firefox index.html
```

Set the host to your fqdn or localhost and set the port to match mplex (4280 if you used that). And you'll see the welcome screen in Firefox.

4) Connect with a player named 'Papi' to create your first god character. 
   This value is configurable in vme/etc/server.cfg 

## Docker build/run/test

Prerequisites:

* Install Docker Desktop
* Increase the memory available to docker if the build cannot complete 
  (docker Preferences->Resources->Advanced->Memory)

### Build the docker image (building the mud from source in the process)

```console
DOCKER_BUILDKIT=1 docker build . -t dikumud3
```

### Run the mud in a new container, binding the port to localhost

```console
docker run -d -p 4280:4280 -p 80:80 dikumud3
```

Then you can point a webbrowser at http://localhost - and connect to the MUD. If you have a be server running already, try `-p 8080:80` instead and connect to http://localhost:8080

#### Persist data between builds/instances

Create a volume to store mud data

```console
docker volume create muddata
```

Mount the volume when you start a container instance

```console
docker run -d -p 4280:4280 -p 80:80 -v muddata:/dikumud3/vme/lib -v dikumud3
```

Create a bash shell into the container then so you can rebuild/restart vme mplex etc

```console
docker exec -it $(docker ps -q -f ancestor=dikumud3) bash
```
#### Stop container

```console
docker stop $(docker ps -q -f ancestor=dikumud3)
```

### Docker Example Workflow

Note running docker in the foreground (without the `-d` switch)

1. Create volume to persist mud data: `docker volume create muddata`
2. Build the container: `DOCKER_BUILDKIT=1 docker build . -t dikumud3`
3. Run the container: `docker run -d -p 4280:4280 -p 80:80 -v muddata:/dikumud3/vme/lib -v dikumud3`
4. Visit http://localhost
5. Create "Papi" user or other
6. Enter MUD and save user
7. Exit MUD
8. Make code changes
9. Build locally (can be skipped)
9. Stop container: CTRL-C or `docker stop $(docker ps -q -f ancestor=dikumud3)`
10. Rebuild container: `DOCKER_BUILDKIT=1 docker build . -t dikumud3`
11. Run the container: `docker run -d -p 4280:4280 -p 80:80 -v muddata:/dikumud3/vme/lib -v dikumud3`
12. Visit http://localhost
13. Oh no - it coredumped with my change (ﾉ｀Д´)ﾉ
14. Start shell in container: `docker exec -it $(docker ps -q -f ancestor=dikumud3) bash`
15. (in container) run vme in debug `cd /dikumud3/vme/bin; gdb vme`
16. etc


### Errors

If the above gives an error like below, it may be because your distro sets `DOCKER_CONTENT_TRUST`. This stops docker from executing images that have not been digitally signed by the creator. You can disable the check by setting the env to zero.

```
[user@localhost]$ docker run -d -p 4280:4280 dikumud3
docker: you are not authorized to perform this operation: server returned 401.
See 'docker run --help'.
[user@localhost]$ env | grep DOCKER
32:DOCKER_CONTENT_TRUST=1
[user@localhost]$ DOCKER_CONTENT_TRUST=0 docker run -d -p 4280:4280 dikumud3
```

## Docker Compose

Alternative to docker, you may use docker-compose.

1. Build the image
```console
docker-compose build
```

2. Modify the docker-compose.yaml file to your needs, there are two variables you may set:
   - WS_HOST: The host the websocket server will bind to.  By default, it is set to localhost.
   - WS_PORT: The port the websocket server will bind to.  By default, it is set to 4280.

For example in `docker-compose.yaml`:

```diff
version: '3.8'

services:
  dikumud3:
    build:
      context: .
      dockerfile: Dockerfile
    ports:
-      - "4280:4280"
+      - "34280:4280"
      - "80:80"
    environment:
-      - WS_HOST=localhost
-      - WS_PORT=4280
+      - WS_HOST=ws.example.com
+      - WS_PORT=34280
    volumes:
      - ./vme/lib:/dikumud3/vme/lib
```

3. Modify the volume mounts to your needs.  By default, it is set to the current directory for persisting the mud data.

4. Run the container

```console
docker-compose up
```

- Optionally, run it in detached mode with: `docker-compose up -d`

5. For development, you can rebuild the container when you make changes by running:

```console
docker-compose up -d --build
```

6. When finished, stop the container with:

```console
docker-compose down
```
