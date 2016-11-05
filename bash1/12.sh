#!/bin/bash

#str palindrome

read -p "Enter a string: " str

len=0
i=1
len=$(echo $str | wc -c)
len=$[ $len - 1 ]
hlen=$[ $len / 2 ]

while [ $i -le $hlen ]
do
	c1=$(echo $str | cut -c$i)
	c2=$(echo $str | cut -c$len)

	if [ $c1 != $c2 ]
	then
		echo "NOT a palindrome."
		exit
	fi	

	i=$[ $i + 1 ]
	len=$[ $len - 1 ]
done

echo "Palindrome."
