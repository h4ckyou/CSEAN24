FROM ubuntu:20.04 as chroot

RUN /usr/sbin/useradd --no-create-home -u 1000 user

COPY flag.txt /home/user/
COPY ret2win1 /home/user/
RUN chmod +x /home/user/ret2win1

FROM gcr.io/kctf-docker/challenge@sha256:0f7d757bcda470c3bbc063606335b915e03795d72ba1d8fdb6f0f9ff3757364f

COPY --from=chroot / /chroot

EXPOSE 1337

WORKDIR /chroot/home/user

CMD socat \
      TCP-LISTEN:1337,reuseaddr,fork \
      EXEC:"/chroot/home/user/ret2win1" 
