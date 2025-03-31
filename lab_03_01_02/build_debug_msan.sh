#!/bin/bash

clang -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion -Wextra -Wpedantic -g3 -fsanitize=memory -fPIE -fno-omit-frame-pointer -c ./*.c
clang -g3 -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -o app.exe ./*.o -lm
