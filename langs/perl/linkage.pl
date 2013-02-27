#!/usr/bin/perl -w

# linkage.pl
# Copyright (C) 2007 Michael Fogus and Minotaur Computing
# 
# This program is free software; you can redistribute it and/or modify 
# it under the terms of the GNU General Public License as published by 
# the Free Software Foundation; either version 2 of the License, or 
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General 
# Public License for more details.
# 
# You should have received a copy of the GNU General Public License along 
# with this program; if not, write to the 
# Free Software Foundation, Inc., 59 
# Temple Place, Suite 330, 
# Boston, MA 02111-1307 
# USA

use HTML::LinkExtor;
use LWP::Simple;
use Getopt::Long;

my $ok_off = 0;
my $help = 0;

GetOptions( 'b' => \$ok_off, 'h' => \$help );


#
# Function: show_help()
#
# Purpose:
# Shows the command flags, breif description, and author info.
#
sub show_help()
{
  my $name = $0;
  my $version = '0.5';
  my $author = 'Michael Fogus';
  my $website = 'http://www.minotaurcomputing.com';
  
	print STDOUT "
$name version $version
A tool for checking broken links within a single HTML page.
Written by $author
$website

Usage: $0 [-h] [-b] url

-h      : Displays this help message
-b      : Show only the bad links\n\n";
}


#
# MAIN
#

if( $help ) {
	show_help();
  	exit 0;
}

my $base_url = shift
	or die "usage: $0 <start_url>\n";

my $parser = HTML::LinkExtor->new( undef, $base_url );
my $html = get( $base_url );

die "Can't fetch $base_url" unless defined( $html );

$parser->parse( $html );

my @links = $parser->links;

print "$base_url: \n";

foreach $linkarray (@links) {
	my @element = @$linkarray;
	my $elt_type = shift @element;

	while( @element ) {
		my ($attr_name, $attr_value) = splice( @element, 0, 2 );

		if( $attr_value->scheme =~ /\b(ftp|https?|file)\b/ ) {
      		if( !$ok_off ) {
        		print "  $attr_value: ", head( $attr_value ) ? "OK" : "BAD", "\n";
      		}
      		else {
        		print "", head( $attr_value ) ? "" : "  $attr_value: BAD\n";
      		}
		}
	}
}
