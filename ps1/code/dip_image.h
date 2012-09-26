#ifndef DIP_IMAGE_H
#define DIP_IMAGE_H

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

#endif
