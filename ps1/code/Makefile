#
#   Author: Kan Ouivirach
# 
CFLAGS = -g -Wall
CC = gcc $(CFLAGS)
PROG = prog prog_using_libnetpbm pgm_image_test
all: $(PROG)

pgm_utils.o: pgm_utils.c pgm_utils.h
	$(CC) -c pgm_utils.c

binarize.o: binarize.c binarize.h dip_image.h
	$(CC) -c binarize.c

prog.o: prog.c dip_image.h
	$(CC) -c prog.c

prog: pgm_utils.o binarize.o prog.o 
	$(CC) pgm_utils.o binarize.o prog.o -o prog

prog_using_libnetpbm.o: prog_using_libnetpbm.c dip_image.h
	$(CC) -c prog_using_libnetpbm.c

prog_using_libnetpbm: binarize.o prog_using_libnetpbm.o
	$(CC) binarize.o prog_using_libnetpbm.o -o prog_using_libnetpbm -lnetpbm

pgm_image_test: pgm_image_test.c pgm_utils.o
	$(CC) pgm_image_test.c pgm_utils.o -o pgm_image_test

clean:
	rm *.o $(PROG)







