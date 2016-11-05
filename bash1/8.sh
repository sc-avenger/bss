#!/bin/bash

#Floyd's Triangle

num=1

for ((i=1; i<=4; i++))
do
	for ((j=1; j<=i; j++))
	do
		echo -ne "$num "
		num=$[ $num + 1 ]
	done
echo
done		
