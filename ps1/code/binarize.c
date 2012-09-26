#include "binarize.h"

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
