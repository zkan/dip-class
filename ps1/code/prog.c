/*
 *  C program that reads a PGM image, binarizes it, and write the 
 *  binarized PGM image to disk
 *  Autor: Kan Ouivirach (kan@ieee.org)
 *  Credit: www.chasanc.com/index.php/Coding/PGM-Image-Format.html
 *  References:
 *      * http://netpbm.sourceforge.net/doc/pgm.html
 *      * http://en.wikipedia.org/wiki/Netpbm_format
 *      * http://www.asciitable.com/
 */

#include <stdio.h>
#include "dip_image.h"
#include "pgm_utils.h"
#include "binarize.h"

int main(int argc, char *argv[]) {
    int width = 0;
    int height = 0;
    int max_color;
    int f_start;
    UCHAR *image_data;
    int i, j;
    int threshold = 127;

    int c;
    extern char *optarg;
    extern int optind;

    while((c = getopt(argc, argv, "t:")) != EOF) {
        switch( c ) {
            case 't':
                sscanf(optarg, "%d", &threshold);
                break;
		}
	}

//    printf("argc: %d\n", argc);
//    printf("optind: %d\n", optind);
//    printf("threshold: %d\n", threshold);

    // optind -- index in argv of the first argv-element that is not an option
    if((argc - optind) != 2) {
        fprintf(stderr, "Usage error\n");
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        fprintf(stderr, "Option:\n");
        fprintf(stderr, "-t <threshold>\n");

        exit(1);
    }

    // read the PGM image header
    if(pgm_read_header(argv[optind], &width, &height, &max_color, &f_start)) {
        printf("Succesfully read the header!\n\n");
        printf("= PGM image information =\n");
        printf("Width: %d\n", width);
        printf("Height: %d\n", height);
        printf("Max color: %d\n", max_color);
        printf("File pointer is at: %d\n\n", f_start);

        image_data = (UCHAR *)malloc(height * width * sizeof(UCHAR));
        if(pgm_get_data(argv[optind], width, height, f_start, image_data)) {
            printf("Succesfully get the PGM image data!\n\n");

            tImage img;
            img.width = width;
            img.height = height;
            img.pixelType = GRAY8;
            img.pPixel = (UCHAR *)malloc(height * width * sizeof(UCHAR));

            // copy data to our format
            for(i = 0; i < height; i++) {
                for(j = 0; j < width; j++) {
                    img.pPixel[i * width + j] = image_data[i * width + j];
                }
            }

            img = binarize(img, threshold);

            // write binarized PMG image to disk
            if(pgm_write_data(argv[optind + 1], img.width, img.height, max_color, img.pPixel)) {
                printf("Succesfully write the binarized PGM image to disk!\n\n");
            }

            // free memory
            free(img.pPixel);
        }

        // free memory
        free(image_data);
    }

    return 1;
}



