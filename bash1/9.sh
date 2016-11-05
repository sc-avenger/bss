#!/bin/bash

#fibo

f=0
s=1
next=0
c=0

read -p "Enter the number of values in the fibo series: " num

while [ $num -ne 0 ]
do
	if [ $c -le 1 ]
	then
		next=$c
		c=$[ $c + 1 ]
	else
		next=$[ $f + $s ]
		f=$s
		s=$next
	fi
echo $next
num=$[ $num - 1 ]
done



