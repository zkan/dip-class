# Digital Image Processing class at AIT

- [Course's Web site](http://vgl-ait.org/cis/courses/59)
- [Markdown: Syntax](http://daringfireball.net/projects/markdown/syntax)
- [GitHub Flavored Markdown - Live Preview](http://tmpvar.com/markdown.html)

## Problem Set 1 (ps1)

We implement a C program to

1. read PGM file from disk;
2. convert PGM data structure to our format;
3. binarize it (0-127 -> 0 and 128-255 -> 1);
4. convert back to PGM format;
5. write to disk.

**Note:** our image format is 

    typedef struct {
      int width;
      int height;
      tPixelType pixelType;
      tpPixel pPixel;
    } tImage;

    typedef enum {
      GRAY8 = 1, 
      FLOAT1 = 2, 
      RGB = 3
    } tPixelType;

This is a nice [tutorial](http://www.chasanc.com/index.php/Coding/PGM-Image-Format.html) that explains how to read and write to disk the PGM binary format. This [reference](http://fossies.org/dox/URT3.1a/dir_73a3a88a177516bb9d1c7678b440c77f.html) is also good if you want to use [Libnetpbm](http://netpbm.sourceforge.net/doc/libnetpbm.html).

## Tools 
We can use Netpbm to convert a PNG image to PGM image. Just run 
the following command.

    $ pngtopnm cat.png | ppmtopgm > cat.pgm

To use Libnetpbm, we need to install a package `libnetpbm10-dev` 
(version 10 is the newest at this moment). We can then use `#include <pgm.h>` 
in the code. When compile, we need to link the library. Simply add `-lnetpbm`. 

## Problem Set 2 (ps2) 

...


