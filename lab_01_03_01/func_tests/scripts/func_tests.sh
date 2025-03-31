#!/bin/bash

failed_tests=0
another_mistakes=0
path="${0%"func_tests.sh"}"
for file in "$path"../data/*; do
    if [ -f "$file" ]; then
        if [[ "$file" =~ pos_[0-9]*_in\.txt ]]; then
            "$path"pos_case.sh "$file" "${file%"in.txt"}"out.txt
            return_code=$?
            if [ $return_code -eq  1 ]; then
                failed_tests=$((failed_tests + 1))
		        if [ $# -eq 1 ] && [ "$1" == "-v" ] || [ "$1" == "--verbose" ]; then
                    echo Failed on test "$file"
                fi
            elif [ $return_code -eq 2 ]; then
                another_mistakes=$((another_mistakes + 1))
            fi
        elif [[ "$file" =~ neg_[0-9]*_in\.txt ]]; then
            "$path"neg_case.sh "$file" "${file%"in.txt"}"out.txt
            return_code=$?
            if [ $return_code -eq  1 ]; then
                failed_tests=$((failed_tests + 1))
		        if [ $# -eq 1 ] && [ "$1" == "-v" ] || [ "$1" == "--verbose" ]; then
                    echo Failed on test "$file"
                fi
            elif [ $return_code -eq 2 ]; then
                another_mistakes=$((another_mistakes + 1))
            fi
        fi
    fi
done
if [ $# -eq 1 ] && [ "$1" == "-v" ] || [ "$1" == "--verbose" ]; then
    echo Total tests failed "$failed_tests"
    echo Anoter mistakes while testing "$another_mistakes"
fi
