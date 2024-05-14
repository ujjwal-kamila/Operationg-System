#/bin/bash
#Constant variables 
readonly COLLEGE="MAKAUT"

echo "My College name is $COLLEGE "

# Gives an error 
COLLEGE="MAKAUT,WB"

# prints same as 3rd line 
echo "My College is $COLLEGE"


readonly PLACE="KALYANI"
echo "My currenet location is $PLACE"

#this will also gives an error 
PLACE="GOPIBALLAVPUR"

# prints same place as KALYANI
echo "My current location is $PLACE"
