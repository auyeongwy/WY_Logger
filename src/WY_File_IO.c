#include "WY_Logger.h"
#include "WY_File_IO.h"


void wy_file_append(const unsigned int p_size, const char * restrict p_content, FILE *p_fp)
{
    fwrite(p_content, 1, p_size, p_fp);
}