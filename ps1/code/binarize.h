/*
 *  Function that 
 *      - takes a grayscale image and binarize it with the input threshold
 *      - returns the binarized image
 *  The image format is defined in the header file dip_image.h.
 */

#ifndef BINARIZE_H
#define BINARIZE_H

#include "dip_image.h"

tImage binarize(tImage img, int threshold);

#endif
