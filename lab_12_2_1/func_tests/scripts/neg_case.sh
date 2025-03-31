#!/bin/bash

path="${0%/*}"

declare -a args
read -ra args < "$3"

valgrind --leak-check=full -q  "$path"/../../app.exe "${args[@]}"
return_code=$?
if [ $return_code -ne 0 ]; then
    # "$path"/comparator.sh "$2" "${args[1]}" --diff
    exit 0
else
    exit 1
fi
