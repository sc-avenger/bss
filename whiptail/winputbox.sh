#!/bin/bash

color=$(whiptail --title "Input Box" --inputbox "Enter your fav color:" 8 78 Blue 3>&1 1>&2 2>&3)

exitstatus=$?

if [ $exitstatus -eq 0 ]
then
	echo "You've selected Okay and color entered is $color ."
else
	echo "You've cancelled."
fi
