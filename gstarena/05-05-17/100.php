<?php
$file = fopen("100.in","r");
echo "<pre>";

$ch = fgets($file);
$inp = [];

while(!feof($file)) {
	$inp[] = fgets($file);
}

$i = 0;
while(isset($inp[$i])) {
	$t = $i + 1;
	echo "Case #$t: ";
	$ans = "NO";
	$inp[$i] = explode(" ", $inp[$i]);
	if(((int)$inp[$i][0] + (int)$inp[$i][2])/2 == (int)$inp[$i][1])
		$ans = "YES";
	echo $ans . "<br>";
	$i++;
}

?>