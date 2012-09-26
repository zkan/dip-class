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
#include <pgm.h>

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


    return 1;
}



