# Building and Running Docker containers

This explains how to build the containers and then run them. Setup of the Docker host is not contained in this doc and is left to the reader.

It also assumes you have run the appropriate cmake and make steps to build the binaries and that the server executable is built with static libraries e.g "cmake -DDIKU_STATIC=1"

## Build the container

There are two Docker image builds provided providing a minimal production image (`Dockerfile`) designed just to run the DikuMUD server with the minimum resources. The test image (`Dockerfile.test`) provides a compelte Ubuntu environment with additional tools to test and interactively work with the DikuMUD server.

The production image is created with the following Docker command. This will create local image with the tag `local`:

```bash
docker build -t dikumud:local .
```

You can confirm images was built by doing:

```bash
docker image ls
```

The container can then be launched within Docker to test that it is operational with the following command (updating the image digest tag depending on if `local` or `local-test` is required):

```bash
docker run -p 4242:4242 -d dikumud:local
```

This will start a container with the currnt `local` image and serve the DikuMUD service on port 4242. A connection can then be made to the DikuMUD server on the localhost as port 4242 (`telnet localhost 4242`), or a shell can be started within the running container and connect to the localhost port 4242:

```bash
docker exec -it <CONTAINER ID> bash
```

## Launch server environments

When a more substancial instance of the DikuMUD server is required where persistent storage is required for zone files, or character data Docker-Compose scripts are provided.

### Create the persistent Docker Volume

A persistent volume is required to store volatile data independent of the container lifecycle.
What is stored in this volume is player data and server configuration
  TODO: clean up the directories and make sure all volatile data is saved here (etc/zonefiles for example)

Run the following command to create the volume:
```bash
docker volume create dikumud-vol
```

The name of the volume <dikumud-vol> is referenced in docker-compose.yml so if it's changed 
it needs to be updated under the 'volumes:' directive there

Now you need to move existing data into this newly created volume.
Where your docker volumes are stored may differ depending on your setup.

```bash
mv vme/etc /var/lib/docker/volumes/dikumud-vol/_data
mv vme/lib /var/lib/docker/volumes/dikumud-vol/_data
```

Note: Some new zone or player ability data may be created in vme/etc if the vme binary is built again.
      This will need to be copied into the Docker Volume after a build
TODO: Figure out how to get new data built into the right place to be packaged into a container.

### Run the Docker Container

Again in the same working directory as this README file should be the docker-compose.yml file.
Make sure this directory is the current working directory.

Start the Container using docker-compose
```
docker-compose up -d
```
You can also use the standard docker-compose commands <start|stop|down>

The server should now be connectable on port 4242 on the same IP as the Docker host.

### Host and Container Networking

The container is set to use host networking, if your Docker is setup to use Ingress services
and private networking then you'll need to modiy the docker-compose.yml file accordingly.
