#!/bin/sh

cc -Og -g -o target/hot/main src/main.c target/hot/libraylib.so.??? -lltdl -ldl -lm -DRADIANCE_HOT
