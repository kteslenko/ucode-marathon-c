#!/bin/bash
while read line
do
    if [[ "${line,,}" == "redpill "* ]]; then
        echo "$line"
    fi
done < $1
