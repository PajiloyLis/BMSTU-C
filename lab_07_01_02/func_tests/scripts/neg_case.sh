#!/bin/bash

if [ $# -ne 3 ]; then
    exit 99
else
    if [[ "$1" =~ .*\.txt$ ]]; then
        if [[ "$2" =~ .*\.txt$ ]]; then
            [[ "$3" =~ .*\.txt$ ]] || exit 99
        else
            exit 99
        fi
    else
        exit 99
    fi
fi

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
