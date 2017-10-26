<?php
$file = fopen("200.in","r");
echo "<pre>";

$ch = fgets($file);
$ipCount = [];
$inp = [];
$op = [];

while(!feof($file))
{
	$ipCount[] = (int)fgets($file);
	$inp[] = explode(" ", fgets($file));
}

$i = 0;
while(isset($inp[$i]))
{
	if ( $ipCount[$i] !== count($inp[$i]) )
		array_pop($inp[$i]);

	sort($inp[$i]);
	$i++;
}

$i = 0;
while(isset($inp[$i]))
{
	for ( $j = 0; $j < count($inp[$i]); $j++)
		if($j == 0)
			echo $inp[$i][$j];
		else
			echo " " . $inp[$i][$j];
	echo "<br>";
	$i++;
}

echo "</pre>";
?>