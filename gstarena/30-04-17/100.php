<?php
$file = fopen("100.in","r");
echo "<pre>";

$ch = fgets($file);
$inp = [];

while(!feof($file)) {
	$inp[] = fgets($file);
}

$i = 0;
while(isset($ch[$i])) {
$t = $i + 1;
  echo "Case #". $t .": ";
  if ($ch[$i] == 'B' || $ch[$i] == 'b')
    printf("BattleShip");

  if ($ch[$i] == 'C' || $ch[$i] == 'c')
      printf("Cruiser");

  if ($ch[$i] == 'D' || $ch[$i] == 'd')
    printf("Destroyer");

  if ($ch[$i] == 'F' || $ch[$i] == 'f')
    printf("Frigate");

    echo "<br>";
  $i++;
}
?>
