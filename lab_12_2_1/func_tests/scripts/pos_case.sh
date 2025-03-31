#!/bin/bash

path="${0%/*}"

declare -a args
read -ra args < "$3"

valgrind --leak-check=full -q "$path"/../../app.exe "${args[@]}"
return_code=$?
if [ $return_code -ne 0 ]; then
    exit 1
else
    "$path"/comparator.sh "$2" "${args[1]}" --diff
    exit $?
fi
