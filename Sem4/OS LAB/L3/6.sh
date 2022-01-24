#!/bin/bash

# Program to replace all "ex:" with "Example:"
sed -i -e 's/^ex:/Example:/' *.txt       #Replace the ex: in beginning of lines
sed -i -e 's/\. ex:/\. Example:/' *.txt  #Replace the ex: occuring after . 


