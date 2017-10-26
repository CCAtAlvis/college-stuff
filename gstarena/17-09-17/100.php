<?php
$file = fopen( "100.in", "r" );
$op = fopen( "100.out", "w" );
echo "<pre>";

$ch = (int) fgets($file);
$dist = 0;
$road = 0;

$i = 0;
while( $i < $ch )
{
	$inp = explode( " ", fgets($file));

	if ( 3 !== count($inp) )
		array_pop($inp);

	$inp[0] = (int) $inp[0];
	$inp[1] = (int) $inp[1];
	$inp[2] = (int) $inp[2];

	$road = $inp[0];

	if ( 1 === $road )
		$dist += $inp[1];
	else
		$dist += $inp[2];

	if ( $inp[1] > $inp[2] )
		$dist += $inp[2];
	else
		$dist += $inp[1];

	echo "$dist<br>";
	fwrite( $op, $dist);
	fwrite( $op, "\n");

	$i++;
	$dist = 0;
}

echo "</pre>";

fclose( $file );
fclose( $op );
?>