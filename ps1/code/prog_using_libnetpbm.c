/*
 *  C program that reads a PGM image, binarizes it, and write the 
 *  binarized PGM image to disk using Libnetpbm
 *  Autor: Kan Ouivirach (kan@ieee.org)
 *  References:
 *      * http://netpbm.sourceforge.net/doc/pgm.html
 *      * http://en.wikipedia.org/wiki/Netpbm_format
 *      * http://www.asciitable.com/
 *      * http://fossies.org/dox/URT3.1a/dir_73a3a88a177516bb9d1c7678b440c77f.html
 */

#include <stdio.h>
#include <pgm.h>
#include "dip_image.h"
#include "binarize.h"

int main(int argc, char *argv[]) {
    FILE *fp, *fp_out;
    gray maxval;
    int format;
    int width = 0;
    int height = 0;
    int i, j;
    gray **pgm_data;
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

    // all PGM programs must call pgm_init() just after invocation, 
    // before they process their arguments.
    pgm_init(&argc, argv);

    // PBM function for reading, which is almost equivalent 
    // to f = fopen(filename, "rb");
    fp = pm_openr(argv[optind]);

    // read the PGM image header
    pgm_readpgminit(fp, &width, &height, &maxval, &format);

    printf("Succesfully read the header!\n\n");
    printf("= PGM image information =\n");
    printf("Width: %d\n", width);
    printf("Height: %d\n", height);
    printf("Max color: %d\n", maxval);
//    printf("Format: %c\n\n", PGM_FORMAT_TYPE(format));

    // close then open file again for reading data
    fclose(fp);
    fp = pm_openr(argv[optind]);
    
    pgm_data = pgm_readpgm(fp, &width, &height, &maxval);
    
    printf("Succesfully get the PGM image data!\n\n");

    tImage img;
    img.width = width;
    img.height = height;
    img.pixelType = GRAY8;
    img.pPixel = (UCHAR *)malloc(width * height * sizeof(UCHAR));

    // copy data to our format
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            img.pPixel[i * width + j] = pgm_data[i][j];
        }
    }

    img = binarize(img, threshold);

    // convert back to the pgm format
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            pgm_data[i][j] = img.pPixel[i * width + j];
        }
    }

    fp_out = pm_openw(argv[optind + 1]);

    // forceplain is a logical value that tells pgm_writepgminit() to 
    // write a header for a plain PGM format file, as opposed to a raw 
    // PGM format file.
    // 1 -> not a binary format
    int forceplain = 0;
    pgm_writepgm(fp_out, pgm_data, width, height, maxval, forceplain);
    
    printf("Succesfully write the binarized PGM image to disk!\n\n");

    free(img.pPixel);
    fclose(fp);
    fclose(fp_out);

    return 1;
}



