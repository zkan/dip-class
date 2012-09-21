#ifndef PGM_UTILS_H
#define PGM_UTILS_H

#include <stdio.h>
#include <stdlib.h>

int pgm_read_header(char *filename, int *width, int *height, int *max_color, int *f_start);

#endif
