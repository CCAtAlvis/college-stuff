<?php
$file = fopen("100.in","r");
echo "<pre>";

$ch = fgets($file);
$inp = [];
$rev = [];


while(!feof($file)) {
	$inp[] = (float)fgets($file);
}

$i = 0;
while(isset($inp[$i])) {
	$str = (string)$inp[$i];
	$str = strrev($str);
	$rev[$i] = (float)$str;
	$i++;
}

$i = 0;
while(isset($inp[$i])) {
	$t = $i + 1;
	echo "Case #$t: ";
	$ans = $inp[$i];
	if($rev[$i] > $inp[$i])
		$ans = $rev[$i];
	echo $ans . "<br>";
	$i++;
}

?>