#!/bin/bash
# Getting values from a file name.txt


FILE="/d/Ujjwal/name.txt"

for name in $(cat $FILE)
do
    echo "Name is : ${name}"
done