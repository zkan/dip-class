/*
 *  C program that reads a PGM image, binarizes it, and write the 
 *  binarized PGM image to disk
 *  Autor: Kan Ouivirach (kan@ieee.org)
 *  Credit: www.chasanc.com/index.php/Coding/PGM-Image-Format.html
 *  References:
 *      * http://netpbm.sourceforge.net/doc/pgm.html
 *      * http://www.asciitable.com/
 */

#include <stdio.h>
#include "pgm_utils.h"

int main(int argc, char *argv[]) {
    int width;
    int height;
    int max_color;
    int f_start;

    // read the PGM image header
    if(pgm_read_header(argv[1], &width, &height, &max_color, &f_start)) {
        printf("Succesfully read the header!\n");
        printf("Confirm! %s is a PGM image file.\n", argv[1]);
    }

    return 1;
}



