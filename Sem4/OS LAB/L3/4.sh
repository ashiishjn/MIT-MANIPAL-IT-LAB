#!/bin/bash
echo "Gross = Basics + TA + 10% of Basics"
echo "Enter Basics:"
read basics
echo "Enter TA"
read TA
echo `echo "$basics*1.1 + $TA" | bc -l ` #Using Piping
echo `bc -l <<< "$basics*1.1 + $TA"`     #Using Streams
