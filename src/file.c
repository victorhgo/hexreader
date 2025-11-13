#include "functions.h"

void fileTester(int *argc, bin *argv[]){
    if (*argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        EXIT_ERR;
    }
}

byte *loadFileToMemory(FILE *file, bytes size) {

    /* Allocates the memory for the file */
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
    bytes size = ftell(file);
    rewind(file);
    return size;
}

void cleanExit(FILE *file, byte *buffer) {
    if (file) fclose(file);
    if (buffer) free(buffer);
    PRESS_KEY;
}