#!/bin/bash

# Menu driven shell script
where=$1
shift       #Rotates parameters counter-clockwise
patterns=$1
for ((value=2; value<=$#; value++))
do
    patterns+="\|${!value}"
done

while (true)
do
    echo "1. Search the patterns within the file"
    echo "2. Delete the patterns from the file"
    echo "3. Exit"
    read choice
    case $choice in
        1) grep -i $patterns $where ;;
        2) for i
           do   
               sed -e s/$i//g $where > text.txt
               mv text.txt $where
           done;;
        3) exit 0;;
    esac
done

