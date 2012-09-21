#!/usr/bin/perl
#
# run the C program
# ex: perl run.pl cat.pgm
#

my $dir_code = "../code/";
my $dir_input = "../data/input/";
my $dir_output = "../data/output/";

my $image_file = $ARGV[0];
my $input_image = $dir_input . $image_file;
my $output_image = $dir_output . $image_file;

my $prog = "pgm_image_test";

print "Test if the output image is actullay in PGM format or not.\n";
system($dir_code . $prog . " $output_image");

