# Building and Running Docker containers
This explains how to build the containers and then run them. 
Setup of the Docker host is not contained in this doc and is left to the reader.

It also assumes you have run the appropriate cmake and make steps to build the binaries
and that the server executable is built with static libraries e.g "cmake -DDIKU_STATIC=1"

### Build the container
The Dockerfile should be in the same directory as this README file.
Make sure this directory is your current working directory.
Run the following command:
```
docker build -t dikumud:1.0 .
```

You can confirm the image was built by doing
```
docker image ls
```

### Create the persistent Docker Volume
A persistent volume is required to store volatile data despite the container lifecycle.
What is stored in this volume is player data and server configuration
  TODO: clean up the directories and make sure all volatile data is saved here (etc/zonefiles for example)

Run the following command to create the volume:
```
docker volume create dikumud-vol
```

The name of the volume <dikumud-vol> is referenced in docker-compose.yml so if it's changed 
it needs to be updated under the 'volumes:' directive there

Now you need to move existing data into this newly created volume.
Where your docker vlumes are stored may differe depending on your setup.
```
mv vme/etc /var/lib/docker/volumes/dikumud-vol/_data
mv vme/lib /var/lib/docker/volumes/dikumud-vol/_data
```
Note: Some new data may be created in vme/etc if the vme binary is built again.
      This will need to be copied into the Docker Volume after a build
  TODO: Figure out how to get new data built into the right place to be packaed into a container.

### Run the Docker Container
Again in the same working directory as this README file should be the docker-compose.yml file.
Make sure this directory is the current working directory.

Start the Container using docker-compose
```
docker-compose up -d
```
You can also use the standard docker-compose commands <start|stop|down>

The server should now be connectable on port 4242 on the same IP as the Docker host.

##### Host and Container Networking
The container is set to use host networking, if your Docker is setup to use Ingress services
and private networking then you'll need to modiy the docker-compose.yml file accordingly.
