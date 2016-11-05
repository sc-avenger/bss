#!/bin/bash

#case

#read -p "Enter your operation: " $1 $2 $3

case $2 in
[+]) 
	echo "$1 + $3 = $[ $1 + $3 ]"
	;;
[-]) 
	echo "$1 - $3 = $[ $1 - $3 ]"
	;;
[*]) 
	echo "$1 * $3 = $[ $1 \* $3 ]"
	;;
[/]) 
	echo "$1 / $3 = $[ $1 / $3 ]"
	;;
esac

echo "Go Home."
