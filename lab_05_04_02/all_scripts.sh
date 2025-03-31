#!/bin/bash

path="${0%/*}"

echo Tests:
if "$path"/build_debug.sh; then
    "$path"/func_tests/scripts/func_tests.sh -v
fi

echo Adress sanitizer
if "$path"/build_debug_asan.sh; then
    "$path"/func_tests/scripts/func_tests.sh
fi

echo Memory sanitizer
if "$path"/build_debug_msan.sh; then
    "$path"/func_tests/scripts/func_tests.sh
fi

echo Undefined behavior sanitizer
if "$path"/build_debug_ubsan.sh; then
    "$path"/func_tests/scripts/func_tests.sh
fi

echo valgrind
if "$path"/build_debug.sh; then
    "$path"/func_tests/scripts/valgrind.sh
fi

echo gcov
"$path"/collect_coverage.sh
