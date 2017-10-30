<?php
$file = fopen("100.in","r");
$op = fopen("100.out","w");
echo "<pre>";

$ch = (int) fgets($file);
$dif1 = 0;
$dif2 = 0;
$dif = 0;

$i = 0;
while( $i < $ch )
{
    $no = ( int ) fgets( $file );
    $inp = explode(" ", fgets($file));

    if ( $no !== count($inp) )
        array_pop($inp);

    for ( $j = 0 ; $j < $no; $j++ )
        $inp[$j] = (int) $inp[$j];

    $dif1 = $inp[1] - $inp[0];
    $dif2 = $inp[2] - $inp[1];
    
    if ( $dif1 == $dif2 )
    {
        $dif = $dif1;
        $num = $inp[2];
        for ( $j = 3; $j <= $no - 1; $j++ ) 
        {
            $num = $num + $dif;
            if ( $num != $inp[$j] )
            {
                echo $inp[$j] . "<br>";
                fwrite($op, $inp[$j]);
                fwrite($op, "\n");
                break;
            }
        }
    }
    else
    {
        if ( $dif1 ===  $inp[3] - $inp[2] )
        {
            echo $inp[2] . "<br>";
            fwrite($op, $inp[2]);
            fwrite($op, "\n");
        }
        else if ( $dif2 === $inp[3] - $inp[2] )
        {
            echo $inp[0] . "<br>";
            fwrite($op, $inp[0]);
            fwrite($op, "\n");
        }
        else
        {
            echo $inp[1] . "<br>";
            fwrite($op, $inp[1]);
            fwrite($op, "\n");
        }
    }
    
    $dif1 = 0;
    $dif2 = 0;
    $dif = 0;
    $i++;
}


?>