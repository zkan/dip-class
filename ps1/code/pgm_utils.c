#include "pgm_utils.h"

/*
 * PGM binary format
 * | 'P5' | 0Ah | 640 (width) | 20h | 480 (height) | 0Ah | 255 | 0Ah | data |
 * 0Ah - new line
 * 20h - space
 * 255 - number of color intensities
 */

// Credit: http://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
int get_file_size(FILE *fp) {
    int bytes;
    
    fseek(fp, 0, SEEK_END);
    bytes = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    return bytes;
}

int pgm_read_header(char *filename, int *width, int *height, int *max_color, int *f_start) {
    FILE *fp;

    // the number should not be larger than 5 digits
    char ch_width[5], ch_height[5], ch_max_color[5];

    unsigned char ch;
    int i = 0;

    // read a binary file
    if((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "\nERROR! Couldn't open image file\n");
    }

    if(fgetc(fp) == 'P') {
        if(fgetc(fp) == '5') {
            // skip a space
            fgetc(fp);

            ch = fgetc(fp);

            // skip the comment if exists
            if(ch == '#') {
                // break when a new line is found
                while( (fgetc(fp) != 10) && (ftell(fp) < get_file_size(fp)));
                ch = fgetc(fp);
            }

            // get width
            i = 0;
            // break when a blank is found
            while(ch != 32) {
                ch_width[i] = ch;
                ch = fgetc(fp);
                i++;
            }
            // just to make sure that the next char is not garbage
            ch_width[i] = 0;
            *width = atoi(ch_width);
            
            // get height
            i = 0;
            // skip a space
            ch = fgetc(fp);
            // break when a new line is found
            while(ch != 10) {
                ch_height[i] = ch;
                ch = fgetc(fp);
                i++;
            }
            // just to make sure that the next char is not garbage
            ch_height[i] = 0;
            *height = atoi(ch_height);

            // get max_color
            i = 0;
            // skip a new line
            ch = fgetc(fp);
            // break when a new line is found
            while(ch != 10) {
                ch_max_color[i] = ch;
                ch = fgetc(fp);
                i++;
            }
            ch_max_color[i] = 0;
            *max_color = atoi(ch_max_color);

            *f_start = ftell(fp);
        }
        else {
            fprintf(stderr, "\nERROR! This file is not PGM binary format.\n");
            return 0;
        }
    }
    else {
        fprintf(stderr, "\nERROR! This file is a PGM binary format.\n");
        return 0;
    }
    
/*
    printf("filesize: %d\n", get_file_size(fp));
    while(1) {
        printf("%c - ", fgetc(fp));
        i++;
        if(i > 20) {
            break;
        }
    }
//    printf("filesize: %d\n", filesize(fp));
*/
    return 1;
}
