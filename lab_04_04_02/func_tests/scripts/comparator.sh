#!/bin/bash

if [ $# -ne 2 ]; then
    exit 2
fi

diff -B "$1" "$2" > /dev/null
return_code=$?
if [ $return_code -eq 0 ]; then
    exit 0
else
    exit 1
fi