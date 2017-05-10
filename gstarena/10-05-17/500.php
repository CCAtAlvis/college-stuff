<?php

$file = fopen("500.in","r");
echo "<pre>";

fgets($file);
$inp = [];
$boys = [];
$girls = [];

while(!feof($file)) {
	$inp[] = fgets($file);
	$boys[] = explode(" ", fgets($file));
	$girls[] = explode(" ", fgets($file));
}

$i = 0;
while(isset($boys[$i])) {
	array_pop($boys[$i]);
	array_pop($girls[$i]);
	$j = 0;
	while(isset($boys[$i][$j])) {
		$boys[$i][$j] = (int)$boys[$i][$j];
		$girls[$i][$j] = (int)$girls[$i][$j];
		$j++;
	}
	$i++;
}


$i = 0;
while(isset($inp[$i])) {
	$t = $i + 1;
	echo "Case #$t: ";
	$quo = 0;

	sort($boys[$i]);
	rsort($girls[$i]);

	$j=0;
	while(isset($boys[$i][$j])) {
		$quo += $boys[$i][$j]*$girls[$i][$j];
		$j++;
	}

	echo $quo . "<br>";
	$i++;
}

?>