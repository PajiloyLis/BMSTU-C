#!/bin/bash

# if [ $# -ne 3 ]; then
#     exit 99
# else
#     if [[ "$1" =~ .*\.txt$ ]]; then
#         if [[ "$2" =~ .*\.txt$ ]]; then
#             [[ "$3" =~ .*\.txt$ ]] || exit 99
#         else
#             exit 99
#         fi
#     else
#         exit 99
#     fi
# fi

path="${0%/*}"

# declare -a args
# read -ra args < "$3"

file_name="$2"
file_name=${file_name#"../data/"}
file_name=${file_name%in.txt}"output.txt"
path="${0%/*}"

valgrind --leak-check=full -q  "$path"/../../app.exe < "$2" > "$file_name"
return_code=$?
if [ $return_code -ne 0 ]; then
    # "$path"/comparator.sh "$2" "${args[1]}" --diff
    exit 0
else
    exit 1
fi
