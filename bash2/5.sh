#!/bin/bash

a=$(cat /proc/cpuinfo | grep -m 1 "bogomips")
b=$(cat /proc/cpuinfo | grep -m 1 "cpu cores")
c=$(cat /proc/cpuinfo | grep -m 1 "model name")
d=$(cat /proc/cpuinfo | grep -m 1 "cpu MHz")
echo $a 
echo $b 
echo $c 
echo $d 
