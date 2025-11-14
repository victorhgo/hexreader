#include "functions.h"

/* Improved way ot printing the hex header */
void printHeader(void) {
    printf("        ");
    /* Prints from 00 to 09 HEX*/
    for (int i = 0; i < 10; i++){
        printf("%02X ", i);
    }
    printf("\n------- -----------------------------");
    printf("\n");
}

/* changelog. Added the showAscii option */
void pointerPrint(bytes size, bin *pointer, int showAscii) {
    const int bytesPerLine = 10; // 00 to 09 in HEX

    for (bytes i = 0; i < size; i++) {
        /* Prints HEX offset at the beginning of each line */
        if (i % bytesPerLine == 0)
            printf("%06lX  ", i); // format 000000 HEX

        /* Prints hex byte */
        printf("%02X ", (byte)pointer[i]); // 00 format

        /* At end of line or end of file */
        if ((i + 1) % bytesPerLine == 0 || i + 1 == size) {
            /* Padding if the last line is incomplete */
            int padding = bytesPerLine - ((i + 1) % bytesPerLine);

            if (padding != bytesPerLine) {
                for (int p = 0; p < padding; p++) {
                    printf("   ");
                }
            }

            /* ASCII column - only if flag -ascii specified */
            if (showAscii) {
                printAscii(bytesPerLine, i, pointer);
            }

            printf("\n");
        }
    }
}

void printAscii(int bytesPerLine, bytes iterator, bin *pointer){
    /* Print right next to the HEX representation of data */
    printf(" | ");

    /* Only prints exactly what was displayed on the HEX part */
    bytes start = (iterator / bytesPerLine) * bytesPerLine;

    for (bytes i = start; i <= iterator; i++) {
        byte ch = (byte)pointer[i];

        /* Note on isprint() function:
            * It will checks if the given character can be printed
            * If yes, print it, otherwise puts a . in place
            * This function is really useful when dealing with binary format
            */
        printf("%c", isprint(ch) ? ch : '.');
    }
}

// Added the showAscii option
void displayInfo(bytes size, bin *pointer, int showAscii) {
    printHeader();
    pointerPrint(size, pointer, showAscii);
}

void printFileInfo(bytes size) {
    printf("\nFile size: %lu bytes\n", size);
}