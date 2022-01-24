#!/bin/bash
# Script to check for a prime number

read input
for((i=2;i<input;i++))
do
    if [ $[ $input % $i ] == 0 ]; then
        echo "It is not a prime number"
        exit 1;
    fi
done
echo "It is a prime number"
exit 0
