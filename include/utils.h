/*
 * utils.h
 *
 */

#ifndef INCLUDE_UTILS_H_
#define INCLUDE_UTILS_H_

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Replace occurrence of character in string
 * @param str		[in] input string
 * @param s			[in] Search character
 * @param r			[in] Replace character
 * @return			Final string after replacement (same as input @a str pointer)
 */
char *strreplace(char *str, char s, char r);

/**
 * Case insensitive string search
 * @param str		[in] Input string
 * @param pattern	[in] Search pattern
 * @return			Returns pointer to the beginning of the located substring, NULL if not found.
 */
char *strcasestr(const char *str, const char *pattern);

/**
 * Inverse of gmtime and localtime
 * @param tm		[in] Broken down time structure
 * @return			On  success,  these functions return the calendar time (seconds since the Epoch).
 * 					On error, they return the value (time_t) -1 and set errno to indicate
 * 					the cause of the error.
 */
time_t timegm(struct tm *tm);

/**
 * Sleep for duration in milliseconds
 * @param ms		[in] Sleep duration in ms
 */
void msleep(unsigned long ms);

/**
 * Print buffer utility
 * @param addr			[in] Start address for display
 * @param data			[in] Buffer to display
 * @param width			[in] Data width: 1: 8-bit, 2: 16-bit, 4: 32-bit
 * @param count			[in] Length of data to display
 * @param linelen		[in] Number of values to print per line, 0 for default value of 16
 * @return
 */
int print_buffer(unsigned long addr, const void* data, unsigned int width, unsigned int count, unsigned int linelen);

/**
 * Enable load command line utility to load file on device via Xmodem
 * 
 * Load command usage:
 * 
 *     #~ Load [/path/to/file]
 * 
 * e.g.
 * 
 *     #~ load /fs/test.txt
 *
 * @return				Always returns 0
 */
int load_init(void);

/**
 * Enable wget command line utility to download file from web
 * 
 * File download status will be returned via URC response: @ref URC_FILE_DOWNLOAD_STATUS
 * to URC response handler function.
 * 
 * @see logicrom_init(), urc_handler_f
 *
 * Wget command usage:
 * 
 *     #~ wget [/path/to/file] [URL]
 * 
 * e.g.
 * 
 *     #~ wget /fs/test.txt http://example.com/test.txt
 * 
 *
 * @return				Always returns 0
 */
int wget_init(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_UTILS_H_ */
