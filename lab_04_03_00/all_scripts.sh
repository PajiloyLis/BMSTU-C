#!/bin/bash

function do_tests {
    for file in ./func_tests/data/*; do
        if [ -f "$file" ] && [[ "$file" =~ .*_in\.txt$ ]]; then
            ./app.exe < "$file" > /dev/null
        fi
    done
}

echo Tests:
if ./build_debug.sh; then
    ./func_tests/scripts/func_tests.sh -v
fi

echo Adress sanitizer
if ./build_debug_asan.sh; then
    do_tests
fi

echo Memory sanitizer
if ./build_debug_msan.sh; then
    do_tests
fi

echo Undefined behavior sanitizer
if ./build_debug_ubsan.sh; then
    do_tests
fi

echo gcov
./collect_coverage.sh
