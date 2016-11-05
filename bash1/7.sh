#!/bin/bash

#Sum of all digits

read -p "Enter a number: " num

mod=0
sum=0

while [ $num -ne 0 ]
do
	mod=$[ $num % 10 ]
	sum=$[ $sum + $mod ]
	num=$[ $num / 10 ]
done

echo $sum
