#!/bin/bash

echo enter your age
read age
# or read -p "enter your age: " age
if [[ $age -gt 1000 ]]
then
	echo "you are probalby too old to live"
	echo "you can still live if you decrease your age by " $((age - 1001))
else
	echo "your age is less then 1000 wow"
fi

vehicle=$1
case $vehicle in
"car" )
echo "Rent of $vehicle is 100$";;
"van" )
echo  "Rent of $vehicle is 50$";;
"Bicycle" )
echo "Rent of $vehicle is 20$";;
*)  #wild card that matches any text
  echo "Unknown vehicle";;
esac

