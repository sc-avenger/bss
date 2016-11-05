#!/bin/bash

#real number calc

read -p "Enter two numbers: " a b

c=$( echo "scale=4; $a + $b" | bc )
echo $c
