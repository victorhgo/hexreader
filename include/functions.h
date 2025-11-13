#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* Includes */
#include<stdio.h>
#include<stdlib.h>

/* isprint() - Checks if the given character can be printed */
#include<ctype.h>

/* strcmp() - To compare two strings*/
#include<string.h>

/* Some useful macros */
#define PRESS_KEY system( "read -n 1 -s -p \"Press any key to continue...\"\n" )
#define EXIT_ERR exit(1);

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
 * @brief Parse arguments on command line with optional flag
 *        Syntax: ./../HexReader <filename> -ascii or -a
 * @param argc Argument count from main
 * @param argv Argument vector from main
 * @param filename a pointer to the filename
 * @param showAscii flag to display ascii characters:
 *                  set to 1 if True, 0 otherwise
 */
void parseArgs(int argc, bin *argv[], bin **filename, 
               int *showAscii);

/**
 * @brief Checks if the pointer is NULL
 * if True; prints an error and exits the program.
 * False; continue
 */
void pointerTester(bin *pointer);

/* ------------------
* Utilities for file reading
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
 *               with file's contents. (buffer)
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
void pointerPrint(bytes size, bin *pointer, int showAscii);

/**
 * @brief Helper function to print an ASCII table right next to 
 *        the HexReader if showAscii is specified
 * @param bytesPerLine const int declared on pointerPrint
 * @param iterator iterator from pointerPrint
 * @param pointer points to data buffer
 */
void printAscii(int bytesPerLine, bytes iterator, bin *pointer);

/**
 * @brief Prints a header for the hex reader with columns from 00 to 09
 */
void printHeader(void);

/**
 * @brief Prints the file's size
 * 
 * @param size in bytes
 */
void printFileInfo(bytes size);

/**
 * @brief  Display formatted output with optional ASCII column
 * 
 * @param size file size in bytes
 * @param pointer points to data buffer
 * @param showAscii flag to whether display ASCII column or not
 */
void displayInfo(bytes size, bin *pointer, int showAscii);

#endif