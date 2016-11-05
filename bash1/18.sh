#!/bin/bash

#printing time in upper right corner

#t=$(date +%H:%M:%S)

col=$(tput cols)
col=$(( col-9 ))

while :; do
	echo -ne "\033[s"
	tput cup 0 $col
	echo -n "$(date +%H:%M:%S)"
	echo -ne "\033[u"
	sleep 1s
done

