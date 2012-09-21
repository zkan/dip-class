#ifndef PGM_UTILS_H
#define PGM_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char UCHAR;

/*
 * Note: reading the header needs to be done before getting the data
 */

int pgm_read_header(char *filename, int *width, int *height, int *max_color, int *f_start);
int pgm_get_data(char *filename, int width, int height, int f_start, UCHAR **image_data);
int pgm_write_data(char *filename, int width, int height, int max_color, UCHAR **image_data);

#endif
