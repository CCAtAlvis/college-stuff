<?php
$file = fopen("200.in","r");
echo "<pre>";

$ch = fgets($file);
$inp = [];

while(!feof($file)) {
	$inp[] = fgets($file);
}

$i = 0;
while (isset($inp[$i])) {
    $inp[$i] = explode(" ", $inp[$i]);
    $i++;
}

$i = 0;
while (isset($inp[$i])) {
    $j = 0;
    while ($j <= 2) {
        $inp[$i][$j] = (int)$inp[$i][$j];
        $j++;
    }
    $i++;
}

$i = 0;
while(isset($inp[$i])) {
    $t = $i + 1;
	echo "Case #". $t .": ";
    $common = $inp[$i][1] + $inp[$i][2] - $inp[$i][0];
    echo $common;
    echo "<br>";
    $i++; 
}

?>