#!/bin/sh

CLEAN_BANNER="\e[34;1mclean\e[0m"

printf "$CLEAN_BANNER Cleaning target/..."
rm -rf target
printf " Done.\n"
