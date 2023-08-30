FROM ubuntu:latest

COPY vme vme

WORKDIR /vme
RUN [ -d etc ] && mv etc etc.bak
RUN [ -d lib ] && mv lib lib.bak
RUN ln -s /mnt/etc etc && ln -s /mnt/lib lib

EXPOSE 4242/tcp
ENTRYPOINT [ "./entrypoint.sh" ]