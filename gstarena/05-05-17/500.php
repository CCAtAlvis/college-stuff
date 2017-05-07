<?php
$file = fopen("500.in","r");
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
	$c = 0;

	$inp[$i] = str_split($inp[$i]);
	unset($inp[$i][count($inp[$i])-1]);

	while(true) {
		$j = $cpm = 0;
		$current = "";
		$f = 1;
		
		while(isset($inp[$i][$j])) {
			if($inp[$i][$j] != "+") {
				$f = 0;
				break;
			}
			$j++;
		}

		if($f){
			echo $c;
			break;
		}
		
		$j = 0;
		while(isset($inp[$i][$j])) {
			if($current == "") {
				$current = $inp[$i][$j];
			} else if($current == "+" && $inp[$i][$j] == "+") {
				$cpm++;
			} else if($current == "-" && $inp[$i][$j] == "-") {
				$cpm++;
			} else {
				break;
			}
			$j++;
		}

		$j = 0; 
		for($j=0;$j<=$cpm;$j++) {
			if($current == "-")
				$inp[$i][$j] = "+";
			else
				$inp[$i][$j] = "-";
		}
		$c++;
	}

	echo "<br>";
	$i++;
}

?>