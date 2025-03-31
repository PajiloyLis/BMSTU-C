#!/bin/bash

path="${0%/*}"

"$path"/build_debug.sh

"$path"/func_tests/scripts/func_tests.sh

gcov "$path"/*.c

exit 0