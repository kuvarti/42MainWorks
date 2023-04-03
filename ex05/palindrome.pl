#!/usr/bin/perl

use strict;
use warnings;

# Prompt user for input
print "Please enter a string: ";
my $input = <STDIN>;
chomp($input);

# Check if the input is a palindrome
if ($input eq reverse($input)) {
    print "Input is a palindrome!\n";
} else {
    print "Input is not a palindrome.\n";
}
