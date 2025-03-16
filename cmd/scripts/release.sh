#!/bin/sh

cc -Ofast -o target/linux/release src/root.c -lraylib -lm
