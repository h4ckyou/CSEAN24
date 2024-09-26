#!/bin/bash

sudo docker build -t ret2win1 .
sudo docker run -d -p 1337:1337 --rm -it ret2win1
