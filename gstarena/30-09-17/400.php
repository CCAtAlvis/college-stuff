<?php
$file = fopen( "400.in", "r" );
$op = fopen( "400.out", "w" );
echo "<pre>";

$ch = (int) fgets($file);

$i = 0;
while ( $i < $ch )
{
    $no = ( int ) fgets( $file );

    $inp = [];
    for ( $j = 0; $j < $no; $j++ )
        $inp[$j] = explode(" ", fgets($file));


    // j:rows
    for ( $j = 0; $j < $no; $j++ )
    {
        // first and most important condition
        // if any of diagonal most elements are '.' then break right away
        if ( "." === $inp[0][ $no-1 ] || "." ===  $inp[ $no-1 ][0] )
        {
            $inp[ $no-1 ][0] = ".";
            break;
        }

        if ( $no !== count( $inp[$j] ) )
            array_pop( $inp[$j] );

        // k:colms
        for ( $k = $no - 1; $k >= 0; $k-- )
        {
            // echo $j."&nbsp; &nbsp; &nbsp; ".$k."<br>";
            // first condition
            // if the element is '.' then skip is right away
            if ( '.' === $inp[$j][$k] )
            {
                continue;
            }

            // is first (zeroth) row
            if ( 0 === $j )
            {
                // check elements only to the right

                // is last colm
                if ( $no - 1 === $k )
                {
                    // check only the top element
                    // but here nothing to check
                    // its the top most element
                }
                else
                {
                    // check all elements i.e to top, right and top-right
                    // but with above constrains, check only the right elements
                    if ( "." === $inp[$j][$k + 1] )
                    {
                        $inp[$j][$k] = ".";
                    }
                }
            }
            else
            {
                // check all elements i.e to top, right and top-right
                if ( $no - 1 === $k )
                {
                    // check only the top element
                    if ( "." === $inp[$j - 1][$k] )
                    {
                        $inp[$j][$k] = ".";
                    }
                }
                else
                {
                    // check all elements i.e to top, right and top-right
                    if ( "." === $inp[$j][$k + 1] && "." === $inp[$j - 1][$k] && "." === $inp[$j - 1][$k + 1] )
                    {
                        $inp[$j][$k] = ".";
                    }
                }
            }
        }
    }

    if ( "." === $inp[ $no - 1 ][0] )
    {
        echo "NO<br>";
        fwrite($op, "NO\n");
    }
    else if ( "#" === $inp[ $no - 1 ][0] )
    {
        echo "YES<br>";
        fwrite($op, "YES\n");
    }

    $i++;
}

fclose($file);
fclose($op);

?>