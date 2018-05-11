#!usr/bin/perl

# display content of file
open(DATA, "<P10-file1.txt") or die "cannot open file $!\n";
@lines = <DATA>;
print @lines;
close(DATA);

# copy data into another file
open(DATA1,"<P10-file1.txt") or die "cannot open the file $!\n";
open(DATA2,">P10-file2.txt");

while (<DATA1>) {
    print DATA2 $_;
}

close(DATA1);
close(DATA2);
