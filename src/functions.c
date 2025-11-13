#include "functions.h"

void pointerTester(bin *pointer){
    /* If pointing to NULL, then file not successfully loaded */
    if(pointer == NULL){
        printf("Fatal Error!\n");
        PRESS_KEY;
        EXIT_ERR;
    }
}

void runHexReader(int argc, bin *argv[]) {

    /* Pointer to store filename and int to store the showAscii flag 
     * showAscii - 1 if specified, 0 otherwise
     */
    bin *filename;
    int showAscii;

    parseArgs(argc, argv, &filename, &showAscii);

    /* Open the file in read binary mode and checks whether file is valid*/
    FILE *binaryFile = fopen(filename, "rb");
    pointerTester((bin*) binaryFile);

    /* Get file size */
    bytes sizeBytes = getFileSize(binaryFile);

    /* Load file contents */
    byte *binPointer = loadFileToMemory(binaryFile, sizeBytes);
    pointerTester((bin *)binPointer);

    /* Display formatted output (with optional ASCII column) */
    displayInfo(sizeBytes, (bin *)binPointer, showAscii);

    /* Print summary and cleanup */
    printFileInfo(sizeBytes);
    cleanExit(binaryFile, binPointer);
}