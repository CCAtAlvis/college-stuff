<?php
$file = fopen("q2-250.in","r");
echo "<pre>";

$ch = (int)fgets($file);
$inp = [];
$op = [];

$i = 0;
while ($i < $ch )
{
	$inp[$i] = [];
	for ($j=0; $j < 4; $j++)
		$inp[$i][$j] = fgets($file);

	$i++;
}


$i = 0;
$rm = 0;
$barca = 0;
$search = '';

while (isset($inp[$i]))
{
	for ($j=0; $j < 4; $j++)
	{
		$inp[$i][$j] = split(" ", $inp[$i][$j]);
		$inp[$i][$j][1] = (int)$inp[$i][$j][1];
	}

	for ($j = 0; $j < 4; $j++)
	{
		switch ($inp[$i][$j][0])
		{
			case 'Barcelona' :
				$search = 'Eibar';
				for ($k = 0; $k < 4; $k++)
				{
					if ($inp[$i][$k][0] === $search)
					{
						if ($inp[$i][$k][1] >= $inp[$i][$j][1])
							//barca looses
							$barca = 0;
						else
							//barca wins or draw
							$barca = 1;
						break;
					}
				}
				break;

			case 'RealMadrid' :
				$search = 'Malaga';
				for ($k = 0; $k < 4; $k++)
				{
					if ($inp[$i][$k][0] === $search)
					{
						if ($inp[$i][$k][1] > $inp[$i][$j][1])
							//rm looses
							$rm = 0;
						else
							//rm wins or draw
							$rm = 1;
						break;
					}
				}
				break;

			default:
				break;
		}
	}

	if ($rm === 0 && $barca === 1)
		$op[$i] = 'Barcelona';
	else
		$op[$i] = 'RealMadrid';

	$i++;
	$rm = 0;
	$barca = 0;
}

$i = 0;
while (isset($op[$i])) {
	echo "$op[$i]<br>";
	$i++;
}
?>