/**
 * @file WY_File_IO.h
 * Declares functions for file io.
*/
#ifndef _WY_FILE_IO_H_
#define _WY_FILE_IO_H_

#include <stdio.h>


/**
 * Appends the content to the opened file. 
 * 
 * @param p_size Size of the content to write to the file.
 * @param p_content The content to write to the file.
 * @param p_fp The valid FILE * pointer to write content to.
*/
void wy_file_append(const unsigned int p_size, const char * restrict p_content, FILE *p_fp);

#endif