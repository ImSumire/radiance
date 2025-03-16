#!/bin/sh

cc -Og -g -o target/hot/libhot.so radiance/src/extern.c target/hot/libraylib.so.??? -fPIC -shared -lm
