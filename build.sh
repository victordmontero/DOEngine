#!/usr/bin/bash

# cd build ; make
cmake --build . --parallel $(nproc --ignore=1)