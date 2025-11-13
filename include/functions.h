#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* Includes */
#include<stdio.h>
#include<stdlib.h>

/* Some useful macros */
#define OPENFILE fopen(argv[1], "rb")
#define PRESS_KEY system( "read -n 1 -s -p \"Press any key to continue...\"\n" )
#define EXIT_ERR exit(1);
#define BYTES_PER_ROW 10

/* Type Definitions */
typedef unsigned long int bytes;
typedef char bin;
typedef unsigned char byte;

/* ----------
 * Core - Main Program
 * ----------*/

/**
 * @brief Main HexReader runner function
 * 
 * @param argc Argument count from main
 * @param argv Argument vector from main
 */
void runHexReader(int argc, bin *argv[]);

/**
 * @brief Tests whether the file parsed is valid or not
 */
void fileTester(int *argc, bin *argv[]);

/**
 * @brief Checks if the pointer is NULL
 * if True; prints an error and exits the program.
 * False; continue
 */
void pointerTester(bin *pointer);

/* ------------------
* Utilities for file
*  -----------------*/

/**
 * @brief Get the File Size object
 * 
 * @param file is a pointer to an opened file
 * @return file's size in bytes 
 */
bytes getFileSize(FILE *file);

/**
 * @brief Dynamically allocates memory and loads 
 * the file into this space.
 * 
 * @param file Pointer to an opened file
 * @param size File's size in bytes
 * @return byte* a pointer to dynamically allocated memory
 *               with file's contents. 
 */
byte *loadFileToMemory(FILE *file, bytes size);

/**
 * @brief Closes the file and free allocated memory
 * 
 * @param buffer Allocated memory
 */
void cleanExit(FILE *file, byte *buffer);

/* ----------------
* Prints (displays)
*-----------------*/

/**
 * @brief Prints the file's content buffer in HEX
 * 
 * @param size size in bytes
 * @param pointer points to data buffer.
 */
void pointerPrint(bytes size, bin *pointer);

/**
 * @brief Prints a header for the hex reader with columns from 00 to 09
 */
void printHeader(void);

/**
 * @brief Prints the hex header and file data
 */
void displayHexDump(bytes size, bin *pointer);

/**
 * @brief Prints the file's size
 * 
 * @param size in bytes
 */
void printFileInfo(bytes size);

#endif