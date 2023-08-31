FROM ubuntu:latest

COPY vme vme

WORKDIR /vme
RUN [ -d etc ] && mv etc etc.bak
RUN [ -d lib ] && mv lib lib.bak
RUN ln -s /mnt/etc etc && ln -s /mnt/lib lib
RUN chmod 755 entrypoint.sh

EXPOSE 4242/tcp
#ENTRYPOINT [ "./entrypoint.sh" ]
ENTRYPOINT [ "bash", "-c", "while true ; do sleep 600 ; done" ]