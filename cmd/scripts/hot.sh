#!/bin/sh

cc -Og -g -o target/hot/root src/root.c target/hot/libraylib.so.??? -lltdl -ldl -lm -DRADIANCE_HOT
