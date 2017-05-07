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
	echo "Case #". $t .": ";
	$n = $inp[$i];
	$s = 0;
	while($n) {
		$t = $n%10;
		$n /= 10;
		$s += $t;
	}
	echo $s;
    echo "<br>";
  $i++;
}
?>
