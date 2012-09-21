#include "pgm_utils.h"

/*
 * PGM binary format
 * | 'P5' | 0Ah | 640 (width) | 20h | 480 (height) | 0Ah | 255 | 0Ah | data |
 * 0Ah/10d - new line
 * 20h/32d - space
 * 255     - number of color intensities
 */
 
/*
 * Credit: http://www.jb.man.ac.uk/~slowe/cpp/itoa.html
 * Ansi C "itoa" based on Kernighan & Ritchie's "Ansi C"
 * with slight modification to optimize for specific architecture:
 */
void strreverse(char* begin, char* end) {
	char aux;
	
	while(end>begin)
		aux=*end, *end--=*begin, *begin++=aux;
}
	
void itoa(int value, char* str, int base) {
	static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char* wstr=str;
	int sign;
	div_t res;
	
	// Validate base
	if(base<2 || base>35) { *wstr='\0'; return; }
	
	// Take care of sign
	if((sign=value) < 0) value = -value;
	
	// Conversion. Number is reversed.
	do {
		res = div(value, base);
		*wstr++ = num[res.rem];
	} while(value = res.quot);

	if(sign<0) *wstr++='-';
	
    *wstr='\0';
	
	// Reverse string
	strreverse(str,wstr-1);	
}

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
    int file_size;

    // read a binary file
    if((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "\nERROR! Couldn't open image file\n");
    }

    file_size = get_file_size(fp);

    if(fgetc(fp) == 'P') {
        if(fgetc(fp) == '5') {
            // skip a space
            fgetc(fp);

            ch = fgetc(fp);

            // skip the comment if exists
            if(ch == '#') {
                // break when a new line is found
                while( (fgetc(fp) != 10) && (ftell(fp) < file_size));
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
        fprintf(stderr, "\nERROR! This file is not a PGM binary format.\n");
        return 0;
    }
    
    fclose(fp);

    return 1;
}

int pgm_get_data(char *filename, int width, int height, int f_start, UCHAR **image_data) {
    FILE *fp;
    UCHAR ch;
    int i, j;
    
    // read a binary file
    if((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "\nERROR! Couldn't open image file\n");
    }
    fseek(fp, f_start, SEEK_SET);

    // read the data into matrix
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            ch = fgetc(fp);
            image_data[i][j] = (UCHAR)ch;
        }
    }

    fclose(fp);

    return 1;
}

int pgm_write_data(char *filename, int width, int height, int max_color, UCHAR **image_data) {
    FILE *fp;
    char str[128];
    int i, j;

    // write a binary file to disk
    if((fp = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "\nERROR! Couldn't open image file\n");
    }

    // write the header
    fputc('P', fp);
    fputc('5', fp);
    // add a new line
    fputc(10, fp);

    // fwrite(str, 1, strlen(str), fp);
    // -- write strlen(str) data element, each of which is 1 byte long
    // fwrite(str, strlen(str), 1, fp);
    // -- write 1 data element which is 1 byte long

    // write some comment to the file
    strcpy(str, "# Created by Kan Ouivirach");
    fwrite(str, strlen(str), 1, fp);
    // add a new line
    fputc(10, fp);

    // width will be written to file
    itoa(width, str, 10);
    fwrite(str, strlen(str), 1, fp);
    // add a space
    fputc(32, fp);

    // height will be written to file
    itoa(height, str, 10);
    fwrite(str, strlen(str), 1, fp);
    // add a new line
    fputc(10, fp);

    // max_color will be written to file
    itoa(max_color, str, 10);
    fwrite(str, strlen(str), 1, fp);
    // add a new line
    fputc(10, fp);

    // finally, we put the data
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            fputc(image_data[i][j], fp);
        }
    }
    
    fclose(fp);

    return 1;
}

