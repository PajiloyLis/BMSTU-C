#!/bin/bash

dfs(){
    for file in $1; do
        if [ -f "$file" ] && [[ "$file" =~ .*\.sh$ ]]; then
            echo "$file"
            shellcheck "$file"
        elif [ -d "$file" ]; then
            dfs "$file""/*"
        fi
    done
    return
}

dfs "./*"