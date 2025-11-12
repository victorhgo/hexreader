/* main.c */

/* includes */
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

/* main function */
int main(int argc, char *argv[]){
    
    FILE *binaryFile;

    /* This pointer will point to the binary file */
    byte *binPointer;

    /* Will store the file's size (in bytes)*/
    bytes sizeBytes = 0;

    /* This character variable will store each character */
    int character,
            i = 0; /* Increment */

    /* Open the file in binary read mode and test it */
    binaryFile = OPENFILE;

    pointerTester((bin*) binaryFile);

    /* A more elegant way to verify the file size, saving a lot of processing time */

    /* Using fseek() to point the binaryFile pointer to the end of the file */
    fseek(binaryFile, 0, SEEK_END);

    /* Then using ftell() to obtains the current position of binaryFile pointer and storing it into sizeBytes */
    sizeBytes = ftell(binaryFile);

    /* At last, returns the pointers to the file's beginning */
    rewind(binaryFile);

    /* Now we can store all the content from file into the binPointer pointer
        - Dynamic Memory Allocation - sizeBytes * sizeof(char) to allocate a space that is
    the amount of sizeBytes times the size of char (for portability)
    
    Then casting (unsigned char *) to make it compatible for binPointer */
    binPointer = (byte *) malloc(sizeBytes * sizeof(char));

    /* Test the memory allocation */
    pointerTester((bin *) binPointer);

    /* Stores the content of file into the pointer */

    /* To fill the dynamically allocated vector binPointer */
    while((character = fgetc(binaryFile)) != EOF){
        /* if i <= numByte keep storing the char into binPointer[i] */
        if(i <= sizeBytes){
            binPointer[i] = (byte) character;
        } /* end if */

        i++;
    } /* End while */

    /* Display the vector in the right format 00 to 09 then new line */
    printf("       00 01 02 03 04 05 06 07 08 09\n");
    printf("       -- -- -- -- -- -- -- -- -- --");

    pointerPrint(sizeBytes, (bin *)binPointer);

    /* Prints the file size (in bytes)*/
    printf("\nFile size: %lu bytes\n", sizeBytes);

    /* Closes the file and free allocated memory for binPointer */
    fclose(binaryFile);
    free(binPointer);

    system( "read -n 1 -s -p \"Press any key to continue...\"" );

    return 0;

} /* End main*/