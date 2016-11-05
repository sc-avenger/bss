#!/bin/bash

{
	for ((i=1; i<=100; i+=5))
	do
		sleep 0.5
		echo $i
	done
} | whiptail --gauge "Please wait while this completes.." 6 50 0
