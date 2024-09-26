#!/bin/bash

sudo docker build -t seeql .
sudo docker run -d -p 1337:1337 --rm -it seeql
