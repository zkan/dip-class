#!/usr/bin/perl
#
# run the C program
# example ./run.pl (need to run under the demo folder)
#

my $prog = "prog_using_libnetpbm";

my $dir_code = "../code/";
my $dir_input = "../data/input/";
my $dir_output = "../data/output/";

my $input_image1 = $dir_input . "cat.pgm";
my $input_image2 = $dir_input . "cat_lick.pgm";
my $input_image3 = $dir_input . "sea_lion.pgm";

my $output_image1 = $dir_output . "cat_by_libnetpbm.pgm";
my $output_image2 = $dir_output . "cat_lick_by_libnetpbm.pgm";
my $output_image3 = $dir_output . "sea_lion_by_libnetpbm.pgm";

system("rm $output_image1");
system("rm $output_image2");
system("rm $output_image3");

system($dir_code . $prog . " $input_image1 $output_image1");
system($dir_code . $prog . " $input_image2 $output_image2");
system($dir_code . $prog . " $input_image3 $output_image3");

