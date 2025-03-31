#!/bin/bash

gcc -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion -Wextra -Wpedantic -g3 -ftest-coverage -fprofile-arcs -c ./*.c
gcc -lgcov --coverage -o app.exe ./*.o -lm