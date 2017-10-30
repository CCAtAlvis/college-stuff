<?php
$file = fopen( "500.in", "r" );
$op = fopen( "500.out", "w");
echo "<pre>";

$ch = (int) fgets($file);

$i = 0;
while($i < $ch)
{
	$sandw = explode(" ", fgets($file));

	if ( 2 !== count($sandw) )
		array_pop($sandw);

	$size = (int) $sandw[0];
	$weight = (int) $sandw[1];

	$inp = [];
	for ( $j = 0; $j < $size; $j++ )
	{
		$inp[$j] = explode( " ", fgets($file));
		if ( count($inp[$j]) >= $size )
			array_pop( $inp[$j] );

		for ( $k = 0; $k < $size; $k++ )
			$inp[$j][$k] = (int) $inp[$j][$k];
	}

	for ( $j = 0; $j < $size ; $j++ )
	{ 
		for ( $k = 0; $k < $size; $k++ )
		{ 
			#
		}
	}

	$i++;
}

echo "</pre>";
?>