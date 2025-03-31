#!/bin/bash

if [ $# -ne 3 ]; then
    exit 2
else
    if [[ "$1" =~ .*\.txt$ ]]; then
        if [[ "$2" =~ .*\.txt$ ]]; then
            [[ "$3" =~ .*\.txt$ ]] || exit 2
        else
            exit 2
        fi
    else
        exit 2
    fi
fi

file_name="$2"
file_name=${file_name#"../data/"}
file_name="${file_name%.txt}""put.txt"
path="${0%"pos_case.sh"}"

declare -a args
read -a args < "$3"

"$path"../../app.exe "$path""$args" > "$file_name"
return_code=$?
if [ $return_code -ne 0 ]; then
    exit 1
else
    "$path"comparator.sh "$2" "$file_name" --numeric
    exit $?
fi
