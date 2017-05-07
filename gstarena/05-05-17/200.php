<?php
$file = fopen("200.in","r");
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
	$one = (int)$inp[$i][0];
	$two = (int)$inp[$i][1];
	$three = (int)$inp[$i][2];
	$sum = $one + $two + $three - 180;
	if($one && $two && $three && !$sum)
		$ans = "YES";
	echo $ans . "<br>";
	$i++;
}

?>