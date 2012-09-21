# Digital Image Processing class at AIT

You can visit the [course's Web site](http://vgl-ait.org/cis/courses/59).

## Problem Set 1 (ps1)

Netpbm to convert a PNG image to PGM image

    $ pngtopnm cat.png | ppmtopgm > cat.pgm

To use Libnetpbm, we need to install a package `libnetpbm10-dev` (version 10 is the newest at this moment). We can then use `#include <pgm.h>`


