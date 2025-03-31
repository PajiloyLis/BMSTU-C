#!/bin/bash

path="${0%/*}"
gcc -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion -Wextra -Wpedantic -g3 -fsanitize=address -fno-omit-frame-pointer -c "$path"/*.c
gcc -g3 -fsanitize=address -fno-omit-frame-pointer -o app.exe "$path"/*.o -lm