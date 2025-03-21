#!/bin/sh

mkdir -p target/linux
cc -Ofast -o target/linux/release src/main.c -lraylib -lm
