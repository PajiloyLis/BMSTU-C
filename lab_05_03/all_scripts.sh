#!/bin/bash

echo Tests:
if ./build_release.sh; then
    ./func_tests/scripts/func_tests.sh -v
fi

echo Adress sanitizer
if ./build_debug_asan.sh; then
    ./func_tests/scripts/func_tests.sh
fi

echo Memory sanitizer
if ./build_debug_msan.sh; then
    ./func_tests/scripts/func_tests.sh
fi

echo Undefined behavior sanitizer
if ./build_debug_ubsan.sh; then
    ./func_tests/scripts/func_tests.sh
fi

echo gcov
./collect_coverage.sh
