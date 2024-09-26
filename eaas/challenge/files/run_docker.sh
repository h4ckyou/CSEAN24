#!/bin/bash

sudo docker build -t eaas .
sudo docker run -d -p 1337:1337 --rm -it eaas