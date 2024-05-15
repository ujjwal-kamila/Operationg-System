#!/bin/bash

# Arithmetic Operations 
# Maths calculation 
x=10
y=2

#using let cmd
let mul=$x*$y
echo "Multiplicatiion of $x and $y is : $mul"

let sum=$x+$y
echo "Sum of $x and $y is : $sum"

# use curley brases to directly perform operations
echo "Subtraction of $x and $y is : $(($x-$y))"
echo "Division of $x and $y is : $(($x/$y))"
echo "The square of $x is: $(($x**2))"
echo "The square of $y is: $(($y*$y))"
