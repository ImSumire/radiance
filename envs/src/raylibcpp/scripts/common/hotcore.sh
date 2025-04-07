#!/bin/sh

g++ -Og -g \
    -o target/hot/main \
    src/main.cpp \
    target/hot/libraylib.so.??? \
    -lltdl -ldl -lm \
    -DRADIANCE_HOT
