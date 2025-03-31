#!/bin/bash

path="${0%/*}"
for file in "$path"/../data/*; do
    if [ -f "$file" ]; then
        if [[ "$file" =~ [0-9]*_args\.txt ]]; then
            echo "$file"
            "$path"/pos_case.sh "${file%"args.txt"}"in.txt "${file%"args.txt"}"out.txt "$file"
            file_name="$file"
            file_name=${file_name#"../data/"}
            file_name=${file_name%args.txt}"output.txt"

            declare -a args
            read -ra args < "$file"

            valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck "$path"/../../app.exe "${args[@]}" < "${file%"args.txt"}"in.txt > "$file_name"
        fi
    fi
done
