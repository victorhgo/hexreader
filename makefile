# Makefile for binReader
# by Victor Correa

# use the gcc compiler
CC = gcc

# including the -I. flag so gcc can look into the current directory for
# the header.h file
CFLAGS = -I.

binReader: main.o functions.o
	$(CC) -o binReader main.o functions.o
