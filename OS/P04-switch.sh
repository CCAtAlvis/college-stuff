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
