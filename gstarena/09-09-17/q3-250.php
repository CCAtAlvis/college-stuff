<?php
$file = fopen("q3-250.in","r");
echo "<pre>";

$ch = (int)fgets($file);
$inp = [];
$op = [];
$sum1 = $sum2 = 0;
$max1 = $max2 = 0;

$i = 0;
while ($i < $ch )
{
	$inp[$i] = [];
	for ($j=0; $j < 3; $j++)
		$inp[$i][$j] = fgets($file);

	$inp[$i][0] = (int)$inp[$i][0];

	$inp[$i][1] = split(" ", $inp[$i][1]);	
	if ($inp[$i][0] !== count($inp[$i][1]))
		array_pop($inp[$i][1]);

	$inp[$i][2] = split(" ", $inp[$i][2]);	
	if ($inp[$i][0] !== count($inp[$i][2]))
		array_pop($inp[$i][2]);

	for ($j = 0; $j < $inp[$i][0]; $j++)
	{
		$inp[$i][1][$j] = (int)$inp[$i][1][$j];
		$inp[$i][2][$j] = (int)$inp[$i][2][$j];
	}

	for ($j = 0; $j < $inp[$i][0]; $j++)
	{
		$sum1 += $inp[$i][1][$j];
		if ($max1 < $inp[$i][1][$j])
			$max1 = $inp[$i][1][$j];

		$sum2 += $inp[$i][2][$j];
		if ($max2 < $inp[$i][2][$j])
			$max2 = $inp[$i][2][$j];	
	}

	if ($sum1 > $sum2)
	{
		$op[$i] = "A $max1";
	}
	else
	{
		$op[$i] = "B $max2";
	}

	$sum1 = $sum2 = 0;
	$max1 = $max2 = 0;
	$i++;
}

$i = 0;
while (isset($op[$i])) {
	echo "$op[$i]<br>";
	$i++;
}

?>