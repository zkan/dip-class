#
#   Author: Kan Ouivirach
# 
CFLAGS = -g -Wall
CC = gcc $(CFLAGS)
PROG = binarize
all: $(PROG)

pgm_utils.o: pgm_utils.c pgm_utils.h
	$(CC) -c pgm_utils.c

binarize.o: binarize.c
	$(CC) -c binarize.c

binarize: binarize.o pgm_utils.o
	$(CC) binarize.o pgm_utils.o -o binarize

clean:
	rm *.o $(PROG)







