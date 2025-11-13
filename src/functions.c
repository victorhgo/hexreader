#include "functions.h"

void pointerTester(bin *pointer){
    if(pointer == NULL){
        printf("Fatal Error\n");
        PRESS_KEY;
        EXIT_ERR;
    }
}

void printHeader(void) {
    printf("       00 01 02 03 04 05 06 07 08 09\n");
    printf("       -- -- -- -- -- -- -- -- -- --");
}

void pointerPrint(bytes size, bin *pointer){
    for(bytes i = 0; i < size; i++){

        /* For each 10 bytes printed inserts a new line and also show the current line */
        if (i % BYTES_PER_ROW == 0){
            putchar(0x0A);          // Inserts a new line (0x0A)
            printf("%.4lu | ", i);   // Show current line in hex
            
        }

        /* Print the byte */
        printf("%.2X", pointer[i]);
        putchar(0x20); // Separates each byte by a space
    }
}

void displayInfo(bytes size, bin *pointer) {
    printHeader();
    pointerPrint(size, pointer);
}

void printFileInfo(bytes size) {
    printf("\nFile size: %lu bytes\n", size);
}

void runHexReader(int argc, bin *argv[]) {
    /* Validate the parsed filename */
    fileTester(&argc, argv);

    /* Open file in read mode */
    FILE *binaryFile = OPENFILE;
    pointerTester((bin*) binaryFile);

    /* Gets file size */
    bytes sizeBytes = getFileSize(binaryFile);

    /* Loads file into dynamically allocated memory */
    byte *binPointer = loadFileToMemory(binaryFile, sizeBytes);
    pointerTester((bin *)binPointer);

    /* Display formatted output */
    displayInfo(sizeBytes, (bin *)binPointer);

    /* Final infos and closes file */
    printFileInfo(sizeBytes);
    cleanExit(binaryFile, binPointer);
}