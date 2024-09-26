#!/bin/bash

sudo docker build -t mybox .
sudo docker run -d -p 1337:1337 --rm -it mybox
