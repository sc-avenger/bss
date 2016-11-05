#!/bin/bash

#getopts

if [ $# -eq 0 ]
then
	echo "Right number of parameters."
fi

while getopts cd opt
do
	case "$opt" in
		c)clear;;
		d)ls;;
		*)echo "Go Home."
	esac
done

