#!/bin/bash

path="${0%/*}"
for file in "$path"/*; do
    if [ -f "$file" ] && [[ "$file" =~ .c.gcov$ ]]; then
        rm "$file"
    fi
done

for file in "$path"/*; do
    if [ -f "$file" ] && [[ "$file" =~ .gcda$ ]]; then
        rm "$file"
    fi
done

for file in "$path"/*; do
    if [ -f "$file" ] && [[ "$file" =~ .gcno$ ]]; then
        rm "$file"
    fi
done

for file in "$path"/*; do
    if [ -f "$file" ] && [[ "$file" =~ .o$ ]]; then
        rm "$file"
    fi
done

for file in "$path"/*; do
    if [ -f "$file" ] && [[ "$file" =~ .exe$ ]]; then
        rm "$file"
    fi
done

for file in "$path"/func_tests/data/*; do
    if [ -f "$file" ] && [[ "$file" =~ _output.txt$ ]]; then
        rm "$file"
    fi
done

for file in "$path"/*; do
    if [ -f "$file" ] && [[ "$file" =~ .bin$ ]]; then
        rm "$file"
    fi
done

for file in "$path"/func_tests/data/*; do
    if [ -f "$file" ] && [[ "$file" =~ .bin$ ]]; then
        rm "$file"
    fi
done