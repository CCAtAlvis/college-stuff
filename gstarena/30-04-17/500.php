<?php
$file = fopen("500.in","r");
echo "<pre>";

$ch = fgets($file);
$inp = [];

while(!feof($file)) {
	$inp[] = fgets($file);
}

$digits = [];

$i = 0;
while(isset($inp[$i])) {
	for($j=0;$j<10;$j++)
		$digit[$j] = 0;

	$t = $i + 1;
	echo "Case #". $t .": ";
	$n = $inp[$i];
	$s = $sp = 0;
	$f = $t = 1;
	while(true) {
		$f = 1;
		$s = $t * $inp[$i];
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
    echo "<br>";
	$i++;
}
?>