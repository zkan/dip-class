#include <stdio.h>
#include <pgm.h>

int main(int argc, char *argv[]) {
    FILE *f;
    char c;

    f = fopen(argv[1], "rb");
    if(fgetc(f) == 'P') {
        if(fgetc(f) == '5') {
            printf("OK, this file is in binary PGM format.\n");
        }
    }

    return 1;
}
