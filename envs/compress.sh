#!/bin/bash

cd envs

for item in src/*; do
    if [ -d "$item" ]; then  # Check if the item is a directory
        dir=$(basename "$item")
        tar -cJf "$dir.tar.xz" "$item"
        echo "Compressed $dir to envs/$dir.tar.xz"
    fi
done
