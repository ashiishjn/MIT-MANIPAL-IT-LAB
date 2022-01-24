#!/bin/bash

#Script to find the factorial of a number
counter=$1 
factorial=1
while [ $counter -gt 0 ] #while counter > 0
do
   factorial=$(( $factorial * $counter ))
   counter=$(( $counter - 1 ))
done
echo $factorial
