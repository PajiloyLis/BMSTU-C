#!/bin/bash

path="${0%/*}"
gcc -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion -Wextra -Wpedantic -g3 -ftest-coverage -fprofile-arcs -c "$path"/*.c
gcc -lgcov --coverage -o app.exe "$path"/*.o -lm