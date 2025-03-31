#!/bin/bash

gcc -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion -Wextra -Wpedantic -g3 -fsanitize=address -fno-omit-frame-pointer -c ./*.c
gcc -g3 -fsanitize=address -fno-omit-frame-pointer -o app.exe ./*.o -lm