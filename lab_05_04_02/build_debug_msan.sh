#!/bin/bash

path="${0%/*}"
clang -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion -Wextra -Wpedantic -g3 -fsanitize=memory -fPIE -fno-omit-frame-pointer -c "$path"/*.c
clang -g3 -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -o app.exe "$path"/*.o -lm
