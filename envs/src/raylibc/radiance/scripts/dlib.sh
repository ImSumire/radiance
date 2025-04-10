#!/bin/sh

DLIB_BANNER="\e[34;1m dlib\e[0m"

printf "$DLIB_BANNER Compiling libhot.so...\n"
cc -Og -g \
   -o target/hot/libhot.so \
   radiance/extern.c \
   target/hot/libraylib.so.?.?.? \
   -fPIC -shared -lm
