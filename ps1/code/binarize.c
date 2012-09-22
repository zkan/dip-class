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
#include "pgm_utils.h"

typedef unsigned char UCHAR;

typedef enum {
    GRAY8  = 1, 
    FLOAT1 = 2, 
    RGB    = 3
} tPixelType;

typedef struct {
    int width;
    int height;
    tPixelType pixelType;
    UCHAR *pPixel;
} tImage;

void binarize(tImage *img, int threshold) {
    int i, j;

    for(i = 0; i < img->height; i++) {
        for(j = 0; j < img->width; j++) {
            if(img->pPixel[i * img->width + j] < threshold) {
                img->pPixel[i * img->width + j] = 0;
            }
            else {
                img->pPixel[i * img->width + j] = 255;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int width = 0;
    int height = 0;
    int max_color;
    int f_start;
    UCHAR *image_data;
    int i, j;
    int threshold = 127;

    // read the PGM image header
    if(pgm_read_header(argv[1], &width, &height, &max_color, &f_start)) {
        printf("Succesfully read the header!\n\n");
        printf("= PGM image information =\n");
        printf("Width: %d\n", width);
        printf("Height: %d\n", height);
        printf("Max color: %d\n", max_color);
        printf("File pointer is at: %d\n\n", f_start);

        image_data = (UCHAR *)malloc(height * width * sizeof(UCHAR));
        if(pgm_get_data(argv[1], width, height, f_start, image_data)) {
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

            binarize(&img, threshold);

            // write binarized PMG image to disk
            if(pgm_write_data(argv[2], img.width, img.height, max_color, img.pPixel)) {
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



