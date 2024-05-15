#!/bin/bash 
# cond1 && cond2 || cond3
# AND OR logical operations

read -p "Enter Your age : " age

[[ $age -ge 18 ]] && echo "You are Adult!" || echo "You are Minor :( "