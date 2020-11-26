/*
 * lib.h
 *
 */

#ifndef INCLUDE_LIB_H_
#define INCLUDE_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Start Firmware Update
 * @param			[in] HTTP URL to download firmware
 * @return			0 on success, negative value on error
 */
int fota_start(const char *in_url);

/**
 * Get OTA status
 * @return			Return 1 if FOTA in progress, 0 otherwise
 */
int ota_in_progress(void);

#ifdef __cplusplus
}
#endif
