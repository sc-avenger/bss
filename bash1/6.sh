#!/bin/bash

#Reverse

read -p "Enter a number: " num

mod=0
rev=0

while [ $num -ne 0 ]
do
	mod=$[ $num % 10 ]
	rev=$[ $rev * 10 + $mod ]
	num=$[ $num / 10 ]
done

echo $rev
