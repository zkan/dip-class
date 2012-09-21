#
#   Author: Kan Ouivirach
# 
CFLAGS = -g -Wall
CC = gcc $(CFLAGS)
PROG = binarize
all: $(PROG)

binarize.o: binarize.c
	$(CC) -c binarize.c

binarize: binarize.o
	$(CC) binarize.o -o binarize

clean:
	rm *.o $(PROG)







