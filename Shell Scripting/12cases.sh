#!/bin/bash 

echo "Provide an option "
echo "a) for Print date "
echo "b) for list of scripts "
echo "c) to check the current location "


read choice

case $choice in 
    a)
        echo "Today's date is " 
        date
        echo ""Ending..;;
    b)ls;;
    c)pwd;;
    *)echo "please provide a valid value "
esac