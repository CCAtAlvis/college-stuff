<?php
$digit = [10];
for($j=0;$j<10;$j++)
	$digit[$j] = 0;
echo "<pre>";

$n = 10;
$s = $sp = 0;
$f = $t = 1;
while($t < 16) {
	$f = 1;
	$s = $t * $n;
	$num = $s;
	if($s == $sp) {
		$s = "INSOMNIA";
		break;
	}

	while($num) {
		$j = $num%10;
		$num /= 10;
		$digit[$j] = 1;
	}
print_r($digit);
echo "<br><br><br>";

	for($j=0;$j<10;$j++)
		if($digit[$j] != 1) {
			$f = 0;
			break;
		}

	if($f == 1)
		break;

	$t++;
	$sp = $s;
}
echo $s;
?>