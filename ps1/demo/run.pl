#!/usr/bin/perl
#
# run the C program
#

my $dir_code = "../code/";
my $dir_input = "../data/input/";
my $dir_output = "../data/output/";

my $image_file = $ARGV[0];
my $input_image = $dir_input . $image_file;
my $output_image = $dir_output . $image_file;

my $prog = "binarize";

system("rm $output_image");
system($dir_code . $prog . " $input_image $output_image");

