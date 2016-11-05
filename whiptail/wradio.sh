#!/bin/bash

a=$(whiptail --title "RadioList" --radiolist "Select Books" 15 78 7 \
"AAP" "CLRS" ON \
"Math" "Gilbert Strang" OFF 3>&1 1>&2 2>&3)

if [ $a = "AAP" ]
then
	echo "You've selected AAP."
else
	echo "You've selected Math."
fi
