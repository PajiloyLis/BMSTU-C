#!/bin/bash

if ! [[ "$3" == "--diff" && $# -eq 3 || "$3" == "--numeric" &&  $# -eq 3 || "$3" == "--word" && $# -eq 4 ]]; then
    exit 2
fi

if [ "$3" == "--numeric" ]; then
    # Reading first file
    declare -a first_seq
    cnt=0
    while read -r str || [[ -n "$str" ]]; do
        str=$(echo "$str" | tr -d '\r\n')
        for word in $str; do
            if [[ "$word" =~ ^([-+]?[0-9]+[.]?[0-9]*|[-+]?[0-9]*[.]?[0-9]+)$ ]]; then
                first_seq[$cnt]=$word
                cnt=$((cnt+1))
            fi
        done
    done < "$1"
    # Reading second file
    declare -a second_seq
    cnt=0
    while read -r str || [[ -n "$str" ]]; do
        str=$(echo "$str" | tr -d '\r\n')
        for word in $str; do
            if [[ "$word" =~ ^([-+]?[0-9]+[.]?[0-9]*|[-+]?[0-9]*[.]?[0-9]+)$ ]]
            then
                second_seq[$cnt]=$word
                cnt=$((cnt+1))
            fi
        done
    done < "$2"

    # Comparison of two sequences
    if [ ${#first_seq[@]} -ne ${#second_seq[@]} ]; then
        exit 1
    else
        for i in "${!first_seq[@]}"; do
            if [ ! \( "${first_seq[$i]}" == "${second_seq[$i]}" \) ]; then
                exit 1
            fi
        done
        exit 0
    fi
elif [ "$3" == "--word" ]; then
    # Reading first file
    first_val=""
    found=0
    while read -r str || [[ -n "$str" ]]; do
        str=$(echo "$str" | tr -s '\r\n' ' ')
        if [ $found -eq 0 ]; then
            if echo "$str" | grep -q "$4"; then
                found=1
                first_val="${str##*"$4"}"
            fi
        else
            first_val="$first_val""$str" 
        fi
    done < "$1"
    first_val=$(echo "$first_val" | tr -s '\r\n' ' ')
    # Reading second file
    second_val=""
    found=0
    while read -r str || [[ -n "$str" ]]; do
        str=$(echo "$str" | tr -s '\r\n' ' ')
        if [ $found -eq 0 ]; then
            if echo "$str" | grep -q "$4"; then
                found=1
                second_val="${str##*"$4"}"
            fi
        else
            second_val="$second_val""$str" 
        fi
    done < "$2"
    second_val=$(echo "$second_val" | tr -s '\r\n' ' ')
    # Comparison of two strings
    if [ ! \( "$first_val" == "$second_val" \) ]; then
        exit 1
    else
        exit 0
    fi
elif [ "$3" == "--diff" ]; then
    diff -BZy "$1" "$2" > /dev/null
    return_code=$?
    if [ $return_code -eq 0 ]; then
        exit 0
    else
        exit 1
    fi
fi
