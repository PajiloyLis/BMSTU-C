#!/bin/bash

if [ $# -ne 3 ]; then
    exit -100
else
    if [[ "$1" =~ .*\.txt$ ]]; then
        if [[ "$2" =~ .*\.txt$ ]]; then
            [[ "$3" =~ .*\.txt$ ]] || exit -100
        else
            exit -100
        fi
    else
        exit -100
    fi
fi

file_name="$2"
file_name=${file_name#"../data/"}
file_name="${file_name%.txt}""put.txt"
path="${0%"neg_case.sh"}"

declare -a args
read -a args < "$3"

"$path"../../app.exe "$path""${args[@]}" > "$file_name"
return_code=$?
if [ $return_code -ne 0 ]; then
    "$path"comparator.sh "$2" "$file_name" --diff
    exit $?
else
    exit 1
fi
