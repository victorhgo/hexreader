#include "functions.h"

void parseArgs(int argc, bin *argv[], bin **filename, int *showAscii) {
    /* Default: don't display ASCII characters */    
    *showAscii = 0;
    *filename = NULL;

    /* Tests whether a file name was provided or not*/
    if (argc < 2) {
        /* no filename provided */
        printf("Usage: %s <filename> -option \n\t"
               "-ascii  -a\t"
               "-- display ASCII table\n", argv[0]);
        EXIT_ERR;
    }

    /* Locate file and check if ascii flag was entered */
    for (int i = 1; i < argc; ++i) {
        /* Note usage on strcmp() for further reference
         *  int strcmp ( const char * str1, const char * str2 )
         *  Compares str1 to str2 character by character
         *  Returns 0 if they're equal, otherwise a diff value
         */
        if (strcmp(argv[i], "-ascii") == 0 || strcmp(argv[i], "-a") == 0) {
            *showAscii = 1; // Sets flag to 1 - true
        } else {
            if (!*filename){
                /* If no arg is passed for flags*/
                *filename = argv[i];
            }
        }
    }
}

byte *loadFileToMemory(FILE *file, bytes size) {

    /* Allocates the memory for the file into buffer pointer */
    byte *buffer = (byte *) malloc(size);
    pointerTester((bin *)buffer);

    /* Stores each byte in memory */
    for (bytes i = 0; i < size; i++) {
        int c = fgetc(file);
        if (c == EOF) break;
        buffer[i] = (byte)c;
    }

    return buffer;
}

bytes getFileSize(FILE *file){

    fseek(file, 0, SEEK_END);

    /* Stores the filesize */
    bytes size = ftell(file);
    
    rewind(file);
    
    return size;
}

void cleanExit(FILE *file, byte *buffer) {
    /* File is open */
    if (file){
        /* Closes file*/
        fclose(file);
    }
    /* There's data in the buffer */
    if (buffer){
        /* Free buffer*/
        free(buffer);
    }
}