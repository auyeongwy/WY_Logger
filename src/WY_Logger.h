/**
 * @file WY_Logger.h
 * Main API header file for the WY_Logger library. For usage, refer to demo.c.
*/
#ifndef _WY_LOGGER_H_
#define _WY_LOGGER_H_

#include <stdio.h>

#define WY_LOGGER_ERR -1 /**< Denotes error status. */
#define WY_LOGGER_OK 0 /**< Denotes OK status. */


/**
 * Initialises the WY_Logger library for logging to stdout. Must be called before calling any other WY_Logger API. wy_logger_clean() must be called to deallocate and clear up. 
 * @param p_max_size Sets the max size of the logging buffer. Must be at least 128.
 * @return WY_LOGGER_OK if no error. Else WY_LOGGER_ERR.
*/
int wy_logger_init(const unsigned int p_max_size);


/**
 * Prints to log using the printf() format. The logged output will be limited by the max size defined by wy_logger_init().
 * @param p_format Follows the printf() format.
 * @param ... Args following the printf() format. 
 */
void wy_logger_printf(const char *restrict const p_format, ...);


/**
 * Prints to a log file using the fprintf() format. The logged output will be limited by the max size defined by wy_logger_init().
 * @param p_fp A valid FILE* pointer to an opened file.
 * @param p_format Follows the fprintf() format.
 * @param ... Args following the fprintf() format.
 */
void wy_logger_fprintf(FILE * const p_fp, const char *restrict const p_format, ...);


/**
 * Deallocates and cleans the buffers used by WY_Logger library. To use the API again, wy_logger_init() must be called again. 
 */
void wy_logger_clean();


#endif