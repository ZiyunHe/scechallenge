use strict;
use warnings;
 
my $filename = 'input.txt';
my $max = 0;
my $longest = "";
my $palimax = 0;
my $palilongest = "";

#open file
if (open(my $fh, '<:encoding(UTF-8)', $filename)) {

  #read file
  while (my $row = <$fh>) {
    chomp $row;

    #find longest sentence
    if (length($row) > $max) {
    	$max = length($row);
    	$longest = $row;
    }

    my $temp = $row;
    # lower case & ignore spaces n punctuation
    $row = lc($row);
    $row =~ s/[[:punct:]]//g;
    $row =~ s/\s//g;

    #find palindrome
    if ( $row eq reverse($row) ) {
    	$palimax++;
     	if(length($row) > length($palilongest)) {
     		$palilongest = $temp;
     	}
	}
  }
} else { #if cannot open then warn
  warn "Can't open file '$filename' $!";
}
print "$longest\n";
print "$palimax\n";
print "$palilongest\n"