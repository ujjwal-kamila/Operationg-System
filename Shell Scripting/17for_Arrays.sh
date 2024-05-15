#!/bin/bash
myArray=( 1 2 3 Hello Hi 3.14 Ujjwal 'A' )

#for array length
length=${#myArray[*]}
echo "The length of the array is : $length"

#for arithemetic operation use double curly braces"(())""
for(( i=0;i<length;i++ ))
do
    echo "Value of array is ${myArray[$i]}"
done