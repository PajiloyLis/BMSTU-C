#!/bin/bash

for file in ./*; do
    if [ -f "$file" ] && [[ "$file" =~ .c.gcov$ ]]; then
        rm "$file"
    fi
done

for file in ./*; do
    if [ -f "$file" ] && [[ "$file" =~ .gcda$ ]]; then
        rm "$file"
    fi
done

for file in ./*; do
    if [ -f "$file" ] && [[ "$file" =~ .gcno$ ]]; then
        rm "$file"
    fi
done

for file in ./*; do
    if [ -f "$file" ] && [[ "$file" =~ .o$ ]]; then
        rm "$file"
    fi
done

for file in ./*; do
    if [ -f "$file" ] && [[ "$file" =~ .exe$ ]]; then
        rm "$file"
    fi
done

for file in ./func_tests/data/*; do
    if [ -f "$file" ] && [[ "$file" =~ _output.txt$ ]]; then
        rm "$file"
    fi
done