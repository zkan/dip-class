/*
 *  C program that reads a PGM image, binarizes it, and write the 
 *  binarized PGM image to disk
 *  Autor: Kan Ouivirach (kan@ieee.org)
 *  Credit: www.chasanc.com/index.php/Coding/PGM-Image-Format.html
 *  References:
 *      * http://netpbm.sourceforge.net/doc/pgm.html
 */

#include <stdio.h>
#include "pgm_utils.h"

int main(int argc, char *argv[]) {
    int width = 0;
    int height = 0;
    int max_color;
    int f_start;

    // read the PGM image header
    if(pgm_read_header(argv[1], &width, &height, &max_color, &f_start)) {
        printf("Succesfully read the header!\n\n");
        printf("= PGM image information =\n");
        printf("Width: %d\n", width);
        printf("Height: %d\n", height);
        printf("Max color: %d\n", max_color);
        printf("File pointer is at: %d\n\n", f_start);
    }

    return 1;
}
