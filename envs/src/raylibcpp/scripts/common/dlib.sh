#!/bin/sh

g++ -Og -g \
    -o target/hot/libhot.so \
    radiance/extern.cpp \
    target/hot/libraylib.so.??? \
    -fPIC -shared -lm
