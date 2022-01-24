#!/bin/bash

f=$1

touch evenfile.txt 
touch oddfile.txt
sed -n '2~2p' $f > evenfile.txt 
sed -n '1~2p' $f > oddfile.txt 
