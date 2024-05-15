#!/bin/bash 
# for two conditions true false

read -p "what is your age : " age
read -p "what is your Country : " country


# AND operator
if [[ $age -ge 18 ]] && [[ $country == India ]]
then 
    echo "You can Vote "
else 
    echo "You can't vote "
fi



read -p "what is your Cgpa : " cgpa
read -p "Do You pass in Interview : " qulaified


# AND operator
if [[ $cgpa -ge 8 ]] || [[ $qulaified == yes ]]
then 
    echo "You can get the Job "
else 
    echo "You can't get the Job "
fi
