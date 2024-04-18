#include "WY_Logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include "WY_File_IO.h"


static unsigned int m_max_buffer_size; /**< Max logging buffer size. */
static unsigned int m_current_buffer_size = 0; /**< Current size in logging buffer. */
static char *m_buffer; /**< The buffer for logging. */
static unsigned int m_time_offset = 0;

/**
 * Sets the current system date and time in the logging buffer. 
 */
static inline void wy_logger_settime();


int wy_logger_init(const unsigned int p_max_size, const unsigned int p_time_offset)
{
    if((p_max_size < WY_LOGGER_MIN_SIZE) || (p_max_size > WY_LOGGER_MAX_SIZE)) /* Set a minimum and maximum size accepted for the logging buffer. */
        return WY_LOGGER_ERR;

    if((m_buffer = malloc(p_max_size)) != NULL) {        
        m_max_buffer_size = p_max_size;
        m_time_offset = p_time_offset * 60;
        return WY_LOGGER_OK;
    }
    else
        return WY_LOGGER_ERR;
}


void wy_logger_clean()
{
    if(m_buffer!=NULL) {
        free(m_buffer);
        m_buffer = NULL;
        m_max_buffer_size = 0;
    }
}


void wy_logger_printf(const char *restrict const p_format, ...)
{
    va_list args;
    //m_current_buffer_size = 0; // wy_logger_settime() alreday sets m_current_buffer_size.

    wy_logger_settime(); /* Set the system date and time in the buffer. */
    va_start(args, p_format);
    m_current_buffer_size += vsnprintf(m_buffer+m_current_buffer_size, m_max_buffer_size-m_current_buffer_size, p_format, args); /* Append the message to the buffer. */
    va_end(args);

    printf("%s\n", m_buffer);
}


void wy_logger_fprintf(FILE * const p_fp, const char *restrict const p_format, ...)
{
    va_list args;
    //m_current_buffer_size = 0; // wy_logger_settime() alreday sets m_current_buffer_size.

    wy_logger_settime(); /* Set the system date and time in the buffer. */
    va_start(args, p_format);
    m_current_buffer_size += vsnprintf(m_buffer+m_current_buffer_size, m_max_buffer_size-m_current_buffer_size, p_format, args); /* Append the message to the buffer. */
    va_end(args);

    m_buffer[m_current_buffer_size++] = '\n'; /* Because of how vsnprintf() works there is always at least one available byte at the end. */
    wy_file_append(m_current_buffer_size, m_buffer, p_fp);
}


void wy_logger_notime_fprintf(FILE * const p_fp, const char *restrict const p_format, ...)
{
    va_list args;
    m_current_buffer_size = 0;

    va_start(args, p_format);
    m_current_buffer_size += vsnprintf(m_buffer+m_current_buffer_size, m_max_buffer_size-m_current_buffer_size, p_format, args); /* Append the message to the buffer. */
    va_end(args);

    m_buffer[m_current_buffer_size++] = '\n'; /* Because of how vsnprintf() works there is always at least one available byte at the end. */
    wy_file_append(m_current_buffer_size, m_buffer, p_fp);
}



static inline void wy_logger_settime()
{
    struct timespec ts;

    timespec_get(&ts, TIME_UTC); /* Set to UTC. */
    ts.tv_sec += m_time_offset; /* Add the timezone offset. */
    m_current_buffer_size = (unsigned int)strftime(m_buffer, m_max_buffer_size, "[%F %T", gmtime(&ts.tv_sec)); /* Get current date and time. */
    m_current_buffer_size += snprintf(m_buffer+m_current_buffer_size, m_max_buffer_size-m_current_buffer_size, ".%06ld]: ", ts.tv_nsec/1000); /* Fill in the nanoseconds. */
}