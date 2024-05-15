#!/bin/bash

read -p "Enter Your Marks : " marks

# we can also use curly braces intead of double bracket
# make space before brackets
if [[ $marks -gt 40 ]]
then 
     echo "You are PASS"
else
     echo "You are FAIL!!!"
fi #for end the loop use fi 


# even odd problem in bash 
read -p "Enter the number : " num
if (( (($num % 2)) == 0 ))
then 
    echo "$num is an Even Number "
else
    echo "$num is an Odd Number"
fi