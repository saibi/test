#!/bin/sh

echo "time $1" >> out.txt
for i in 1 2 3 4 5 6 7 8 9 10
do
	/usr/bin/time -a -o out.txt -f "user %U system %S elapsed %e" $1 
done

echo >> out.txt
