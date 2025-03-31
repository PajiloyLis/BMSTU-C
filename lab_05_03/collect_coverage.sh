#!/bin/bash

path="${0%/*}"

./build_debug.sh

./func_tests/scripts/func_tests.sh

gcov "$path"/*.c

exit 0