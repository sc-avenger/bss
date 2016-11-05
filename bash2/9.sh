#!/bin/bash

read -p "Enter the number of files to be created: " num

for ((i=1; i<=num; i++))
do
	t=$(printf file-"%03d".txt $i)
	touch $t
	
	for ((j=1; j<=i; j++))
	do
		echo $j >> $t
	done
done
