#!/bin/bash

#Wordcount Script

case $1 in
	-linecount)
            wc "$2" -l;;
	-wordcount)
			wc "$2" -w;;
	-charcount)
			wc "$2" -c;;
	*);;
esac
