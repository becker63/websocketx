#!/bin/bash
while true
do    
    echo
    echo
    echo 
    xdotool getmouselocation|sed 's/x:\(.*\) y:\(.*\) screen:.*/\1, \2/'
    sleep 0.01
    echo
    clear
   
done
