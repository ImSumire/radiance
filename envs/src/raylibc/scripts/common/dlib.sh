#!/bin/sh

cc -Og -g \
   -o target/hot/libhot.so \
   radiance/extern.c \
   target/hot/libraylib.so.??? \
   -fPIC -shared -lm
