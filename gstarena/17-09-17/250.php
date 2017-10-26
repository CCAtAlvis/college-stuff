<?php
$file = fopen( "250.in", "r" );
$op = fopen( "250.out", "w" );
echo "<pre>";

$ch = (int) fgets($file);

$i = 0;
while( $i < $ch )
{
	$nandm = explode( " ", fgets($file));
	$inp = explode( " ", fgets($file));

	if ( 2 !== count($nandm) )
		array_pop($nandm);

	$nandm[0] = (int)$nandm[0];
	$nandm[1] = (int)$nandm[1];

	if ( $nandm[0] !== count($inp) )
		array_pop($inp);

	for ( $j=0; $j < $nandm[0] ; $j++ )
		$inp[$j] = (int)$inp[$j];

	$maxIndex = getMaxIndex ($inp);
	$temp = [];

	$j = $maxIndex - $nandm[1] + 1;
	for ( $k = $j; $k <= $maxIndex; $k++ )
		$temp[] = $inp[$k];

	sort($temp);

	for ( $j = 0; $j < count($temp); $j++)
	{
		echo $temp[$j] . " ";
		fwrite( $op, $temp[$j] . " ");
	}
	echo "<br>";
	fwrite( $op, "\n");

	$i++;
	$temp = '';
}

function getMaxIndex ($arr)
{
	$max = 0;
	for ( $i=0; $i < count($arr); $i++ )
		if ( $arr[$max] < $arr[$i] )
			$max = $i;

	return $max;
}

echo "</pre>";

fclose( $file );
fclose( $op );
?>