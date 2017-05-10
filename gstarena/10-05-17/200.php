<?php
$file = fopen("200.in","r");
echo "<pre>";

fgets($file);
$inp = [];
$val = [];

while(!feof($file)) {
	$inp[] = fgets($file);
	$val[] = explode(" ", fgets($file));
}

fclose($file);

$i = 0;
while(isset($inp[$i])) {
	$inp[$i] = explode(" ",$inp[$i]);
	$inp[$i][0] = (int)$inp[$i][0];
	$inp[$i][1] = (int)$inp[$i][1];
	$i++;
}

$i = 0;
while(isset($val[$i])) {
	array_pop($val[$i]);
	$j = 0;
	while(isset($val[$i][$j])) {
		$val[$i][$j] = (int)$val[$i][$j];
		$j++;
	}
	$i++;
}

$i = 0;
while(isset($inp[$i])) {
	$j = $i + 1;
	echo "Case #$j: ";
	$sat = 0;
	$unsat = 0;

	$j = 0;
	while(isset($val[$i][$j])) {
		if($val[$i][$j] <= ($inp[$i][0] + 5) && $val[$i][$j] >= ($inp[$i][0] - 5))
			$sat++;
		else
			$unsat++;

		$j++;
	}

	echo "$sat $unsat<br>";
	$i++;
}

?>