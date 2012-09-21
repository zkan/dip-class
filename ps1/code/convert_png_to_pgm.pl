#!/usr/bin/perl
#
# convert a PNG image to PGM image
#

my $input_image = $ARGV[0];
my $output_image = substr($input_image, 0, -4);
#print $output_image . "\n";

system('pngtopnm ' . $input_image . ' | ppmtopgm > ' . $output_image . '.pgm');

