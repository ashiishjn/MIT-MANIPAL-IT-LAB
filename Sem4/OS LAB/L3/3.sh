#!/bin/bash 
echo "Replacing .txt -> .text"
result=`find . -depth -name *.txt`
for i in $result 
do
    mv $i ${i%.txt}.text
done
