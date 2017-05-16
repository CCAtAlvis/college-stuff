<?php
$file = fopen("500.in","r");
echo "<pre>";

$ch = fgets($file);
$inp = [];

while(!feof($file)) {
	$inp[] = fgets($file);
    fgets($file);
}

$i = 0;
while (isset($inp[$i])) {
    $inp[$i] = explode(" ", $inp[$i]);
    $i++;
}

$i = 0;
while (isset($inp[$i])) {
    $inp[$i][0] = (int)$inp[$i][0];
    $inp[$i][1] = (int)$inp[$i][1];
    $i++;
}

//print_r($inp);

$i = 0;
while(isset($inp[$i])) {
    $t = $i + 1;
	echo "Case #". $t .": ";
    $path =  $inp[$i][1] - $inp[$i][0] + 1;
    echo $path;
    echo "<br>";
    $i++; 
}

?>