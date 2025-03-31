#!/bin/bash

./build_debug.sh

for file in ./func_tests/data/*; do
    if [ -f "$file" ] && [[ "$file" =~ .*_in\.txt$ ]]; then
        ./app.exe < "$file" > /dev/null
    fi
done

gcov ./*.c

exit 0