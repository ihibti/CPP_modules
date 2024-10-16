#!/bin/bash

# Iterate over all subdirectories and run `make fclean` if a Makefile exists
for dir in */; do
    if [ -f "$dir/Makefile" ]; then
        echo "Cleaning in $dir...";
        make -C "$dir" fclean;
    fi;
done
