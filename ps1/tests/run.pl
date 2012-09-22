#!/usr/bin/perl
#
# run the C program
# example: ./run.pl (need to run under the tests folder)
#

my $prog = "pgm_image_test";

my $dir_code = "../code/";
my $dir_output = "../data/output/";
 
my $output_image1 = $dir_output . "cat.pgm";
my $output_image2 = $dir_output . "cat_lick.pgm";
my $output_image3 = $dir_output . "sea_lion.pgm";

print "Test if the output image is actullay in PGM format or not.\n";
system($dir_code . $prog . " $output_image1");
system($dir_code . $prog . " $output_image2");
system($dir_code . $prog . " $output_image3");

