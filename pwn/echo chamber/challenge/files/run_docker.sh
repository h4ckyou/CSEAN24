#!/bin/bash

sudo docker build -t echochamber .
sudo docker run -d -p 1337:1337 --rm -it echochamber