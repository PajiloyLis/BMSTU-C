#!/bin/bash

path="${0%/*}"
gcc -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion -Wextra -Wpedantic -O3 -c "$path"/*.c
gcc -o app.exe "$path"/*.o -lm