#!/bin/bash

read -p "Enter Your Marks(1-100) : " marks

# Add space before brackets
if [[ $marks -ge 80 ]]; 
then
    echo "1st Division😊"

elif [[ $marks -ge 60 ]]; 
then
    echo "2nd Division✌️"

elif [[ $marks -ge 35 ]]; 
then
    echo "3rd Division😒"
    
else
    echo "You are FAIL😭!!!"
fi