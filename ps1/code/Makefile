#
#   Author: Kan Ouivirach
# 
CFLAGS = -g -Wall
CC = gcc $(CFLAGS)
PROG = binarize pgm_image_test
all: $(PROG)

pgm_utils.o: pgm_utils.c pgm_utils.h
	$(CC) -c pgm_utils.c

binarize.o: binarize.c
	$(CC) -c binarize.c

binarize: binarize.o pgm_utils.o
	$(CC) binarize.o pgm_utils.o -o binarize

pgm_image_test: pgm_image_test.c pgm_utils.o
	$(CC) pgm_image_test.c pgm_utils.o -o pgm_image_test

clean:
	rm *.o $(PROG)







