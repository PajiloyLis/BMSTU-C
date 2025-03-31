#!/bin/bash

gcc -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion -Wextra -Wpedantic -O3 -c ./*.c
gcc -o app.exe ./*.o -lm