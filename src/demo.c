/**
 * @file demo.c
 * Demonstrates usage of the WY_Logger library.
*/
#include "WY_Logger.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(wy_logger_init(1024) == WY_LOGGER_ERR) { /* Initialises the library. */
        printf("Error initializing WY_Logger library.\n");
        return 0;
    }
    wy_logger_printf("Hello 1"); /* Prints to stdout. */

    
    FILE *fp = fopen("log.txt", "a"); /* Open a file. */
    if(fp == NULL) {
        printf("Error opening log file. Exit demo.\n");
        return 0;
    } 
    wy_logger_fprintf(fp, "Hello 2"); /* Writes to the file. */

    fclose(fp);
    wy_logger_clean(); /* Cleanup before exit. */
    return 0;
}
