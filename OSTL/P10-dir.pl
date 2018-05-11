#!/usr/bin/perl
# display all files in dir
$dir = "*";
my @files = glob($dir);

foreach (@files) {
    # print "jjj\n".@files;
    print $_."\n";
}
print "\n\n";

# display all python source files in dir
$dir = "*.py";
my @files = glob($dir);

foreach (@files) {
    print $_."\n";
}
print "\n\n";

# display all files in /home
$dir = "/home/cc/Desktop/*";
my @files = glob($dir);

foreach (@files) {
    print $_."\n";
}
print "\n\n";

opendir(DIR, ".") or die "Could not open the directory, $!";
while ($file = readdir DIR) {
    print "$file\n";
}
closedir DIR;
