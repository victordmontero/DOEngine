#!/usr/bin/bash

# cd build ; make
cmake --build build -j $(nproc --ignore=1)