# COMP1927 14s2 - Assignment 1 Makefile

CC=gcc
CFLAGS=-Wall -Werror

run_sal : run_sal.o allocator.o

run_sal.o : run_sal.c allocator.h

allocator.o : allocator.c allocator.h

clean :
	rm -f run_sal *.o
