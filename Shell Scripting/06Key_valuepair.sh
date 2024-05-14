#!/bin/bash

# How to store the key value pairs in Array

declare -A myArray
myArray=( [name]=Ujjwal [age]=19 [branch]=CSE [city]=Kalyani )

# Accessing array elements using key value pair

echo "My name is : ${myArray[name]}"
echo "My age is : ${myArray[age]}"
echo "My branch is : ${myArray[branch]}"
