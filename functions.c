/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/* Defines */
#define OPENFILE fopen("binary.bin", "rb")
#define ERROR_R system( "read -n 1 -s -p \"Press any key to continue...\"" )
#define EXIT_ERR exit(1);

/* typedefs */
typedef unsigned long int bytes;
typedef char bin;
typedef unsigned char byte;

void pointerTester(bin *pointer){
    if(pointer == NULL){
        printf("Fatal Error\n");
        ERROR_R;
        EXIT_ERR;
    }
} /* End pointerTester */

void pointerPrint(bytes size, bin *pointer){

    /* Print bin pointer vector char by char following the file's size */
    for(int i = 0; i < size; i++){

        /* For each 10 bytes printed inserts a new line and also show the current line */
        if (i % 10 == 0){
            putchar(0x0A);          /* Inserts a new line */
            printf("%.4X | ", i);   /* Show current line in hex */
            
        } /* End if */

        /* Print the byte */
        printf("%.2X", pointer[i]);
        putchar(0x20); /* Prints a space to separate each byte */
    } /* End for */

} /* End pointerPrint */