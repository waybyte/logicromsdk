/*
 * fota.h
 *
 */

#ifndef INCLUDE_FOTA_H_
#define INCLUDE_FOTA_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Add fota command to CLI
 * 
 * Usage:
 * fota=[url]
 * 
 * @return returns 0
 */
int fota_init(void);

/**
 * Start Firmware Update
 * @param in_url	[in] HTTP URL to download firmware
 * @return			0 on success, negative value on error
 */
int fota_start(const char *in_url);

/**
 * Get OTA status
 * @return			Return 1 if FOTA in progress, 0 otherwise
 */
int fota_in_progress(void);

/**
 * @brief Register with Logicrom FOTA server for automatic firmware
 * updates via Device management console. Automatic firmware update
 * is checked once a day on Waybyte server. This function also enable
 * core firmware update checks.
 * 
 * This function also add additional options in "fota" command
 * 
 * To check update on server\n
 * fota=check
 * 
 * To force download firmware\n
 * fota=download
 * 
 * To manually update firmware\n
 * fota=update
 *
 * @param code		Firmware code to identify application
 * @param ver		current firmware version
 * @return			return 0 on success, negative value on failure
 */
int logicrom_fota_register(const char *code, const char *ver);

/**
 * @brief Set fota check interval
 * 
 * @param hours interval value in hours
 * @return return 0 on success, negative value on error
 */
int fota_set_interval(int hours);

/**
 * @brief Get current fota check interval
 * 
 * @return return fota interval in hours
 */
int fota_get_interval(void);

#ifdef __cplusplus
}
#endif
#endif	/* INCLUDE_FOTA_H_ */

