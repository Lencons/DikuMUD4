FROM ubuntu:latest

COPY vme vme

RUN apt update && apt upgrade -y
WORKDIR /vme

EXPOSE 4242/tcp
ENTRYPOINT [ "./entrypoint.sh" ]