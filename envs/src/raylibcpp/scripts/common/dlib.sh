#!/bin/sh

DLIB_BANNER="\e[34;1mdlib\e[0m"

printf "$DLIB_BANNER Compiling libhot.so\n"
g++ -Og -g \
    -o target/hot/libhot.so \
    radiance/extern.cpp \
    target/hot/libraylib.so.??? \
    -fPIC -shared -lm
