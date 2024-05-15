#!/bin/bash

# Take input from user 
echo "What is Your Name : "
read name 
echo "Your name is : $name"


#another way to read user input

# Prompt the user for details
read -p "Enter your name : " name
read -p "Enter your age : " age
read -p "Enter your city : " city

# Print the user details
echo "Name: $name"
echo "Age: $age"
echo "City: $city"
