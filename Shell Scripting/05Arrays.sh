#!/bin/bash

# Arrays in Shell Scripting 

# Define an array # seperated by an space
MyArray=(1 2 Hello "Hii" 3.14 'e')

# Accessing Array Elements 
echo "Value of 3rd index is : ${MyArray[3]}"
echo "Value of 4th indes is : ${MyArray[4]}"

# Printing all the values of the array
echo "All the values of my arrays are: ${MyArray[*]}"

#Length of array
echo "No of values or Length of MyArray is: ${#MyArray[*]}"

#How to get Specific values from arrays "start:end:stepvalue
echo "values from 1st index of MyArray is: ${MyArray[*]:1}"
echo "3 values from 2nd index of MyArray is: ${MyArray[*]:2:3}"

#How to update an array with new values
MyArray+=("IND_Bank" "BlackRock")
echo "MyArray with new elements: ${MyArray[*]}"
