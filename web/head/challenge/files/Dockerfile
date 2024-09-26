FROM ubuntu:20.04 as chroot

RUN /usr/sbin/useradd --no-create-home -u 1000 user

COPY flag.txt /home/user/
COPY app.py /home/user/
RUN chmod +x /home/user/app.py

FROM gcr.io/kctf-docker/challenge@sha256:0f7d757bcda470c3bbc063606335b915e03795d72ba1d8fdb6f0f9ff3757364f

RUN pip3 install flask

COPY --from=chroot / /chroot

EXPOSE 1337

CMD python3 /chroot/home/user/app.py
