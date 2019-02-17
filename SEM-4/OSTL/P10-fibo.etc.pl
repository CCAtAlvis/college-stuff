#!/usr/bin/perl

# factorial of a nunmber
print "enter num to calc fact: ";
$number = <>;
$fact = 1;

for ($i=1; $i<=$number; $i++) {
    $fact *= $i
}
print "factorail of " . $number . " is " . $fact . "\n";

# fibo series
print "fibonacci no upto: ";
$n = <STDIN>;
$a = 0;
$b = 1;

$c = $a + $b;

print "$a \t$b \t$c";

while (1) {
    $a = $b;
    $b = $c;
    $c = $a + $b;

    if ($c>$n) {
        last;
    }

    print "$c \t";
}

print "\n";
