#!/bin/bash

sudo docker build -t basics .
sudo docker run -d -p 1337:1337 --rm -it basics
