#!/bin/bash

n=$#
if [ $n -eq 0 ]
then
    echo "No files provided"
    exit 1
fi
rm -i $*

