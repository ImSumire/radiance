#!/bin/bash

cd envs

for item in src/*; do
    if [ -d "$item" ]; then  # Check if the item is a directory
        dir=$(basename "$item")
        
        cd $item
        tar -cJf "../../$dir.tar.xz" . # "$item"
        echo "Compressed $dir to envs/$dir.tar.xz"
        cd ..
    fi
done
