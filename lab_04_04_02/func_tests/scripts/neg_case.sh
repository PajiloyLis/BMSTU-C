#!/bin/bash

if [ $# -ne 2 ]; then
    exit 2
else
    [[ "$1" =~ .*\.txt ]] || exit 2
fi

file_name="$2"
file_name=${file_name#"../data/"}
file_name="./""${file_name%.txt}""put.txt"

path="${0%"neg_case.sh"}"
"$path"../../app.exe < "$1" > "$file_name"
return_code=$?
if [ $return_code -ne 0 ]; then
    "$path"comparator.sh "$2" "$file_name"
    exit $?
else
    exit 1
fi
