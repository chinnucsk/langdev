#!/usr/bin/env perl

#	All results are printed immediately
#	To continue a command/expression over several lines, use a trailing '\'

use Term::ReadLine;

$^W= 1;
my $psh_term= new Term::ReadLine 'psh';
$psh_term->ornaments(0);
my $psh_cmd= '';

# use Data::Dumper;
# sub dump { Dumper(@_); }
# print "Use `dump' to run Data::Dumper on an object.\n";

print "\n";
while (defined ($_= $psh_term->readline($psh_cmd ? "Per>> " : "Perl> ")))
{	if (/\\\s*$/)  { $psh_cmd .= "$` "; next; }
	my @rv= eval "$psh_cmd $_";
	my $err= $@;
	$psh_cmd= '';
	$rv= join ", ", map { defined($_) ? $_ : "undef" } @rv;
	my $cnt= $rv =~ tr/\n//;
	if ($cnt > 30) {
	    die unless open OUT, "|less";
	    print OUT $rv;
	    die unless close OUT;
	    print "[$cnt lines sent to less]\n";
	}
	else {
	    print "$rv\n" if length $rv;
	}
	print "$err";
}
print "\n";
