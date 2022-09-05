#!/bin/bash
while read line
do
    echo "$line" | awk "{print \$9,\$5}"
done <<< "$(ls -Hlh $1 | sed "/^t/d")"
