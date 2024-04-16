/**
 * @file demo.c
 * Demonstrates usage of the WY_Logger library.
*/
#include "WY_Logger.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(wy_logger_init(1024, 480) == WY_LOGGER_ERR) { /* Initialises the library with a output buffer of 1024 and timezone of UTC+0800. */
        printf("Error initializing WY_Logger library.\n");
        return 0;
    }
    wy_logger_printf("Hello %d", 1); /* Prints to stdout. */
    wy_logger_printf("Hello %d", 2);

    
    FILE *fp = fopen("log.txt", "a"); /* Open a file. */
    if(fp == NULL) {
        printf("Error opening log file. Exit demo.\n");
        return 0;
    } 
    wy_logger_fprintf(fp, "Hello %d", 3); /* Writes to the file. */
    wy_logger_fprintf(fp, "Hello %d", 4);
    wy_logger_notime_fprintf(fp, "Hello %d", 5); /* Writes to the file without timestamp. */
    wy_logger_notime_fprintf(fp, "Hello %d", 6); 
    wy_logger_fprintf(fp, "Hello %d", 7);


    fclose(fp);
    wy_logger_clean(); /* Cleanup before exit. */
    return 0;
}
