#!/bin/bash

if (whiptail --title "Yes/No" --yesno "Select yes or No" 8 78)
then
	echo "Exit status is $?"
else
	echo "Exit status is $?"
fi
