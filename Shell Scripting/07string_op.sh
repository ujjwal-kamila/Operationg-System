#!/bin/bash

#String Operation 

myVar="Hey Buddy , How are You ?"

myVarLength=${#myVar}
# printing the length of the variable 
echo "Lenght of the myVar is $myVarLength"

# printing uppercase

echo "Upper case is : ${myVar^^}"

# printing lower case
echo "Lower case is : ${myVar,,}"

#To Replace a string
newVar=${myVar/Buddy/Ujjwal}
echo "New var is :--- $newVar"

# To slice a string 
echo "After slicing :- ${myVar:0:9}"