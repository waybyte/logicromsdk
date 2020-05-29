/*
 * lib.h
 *
 */

#ifndef INCLUDE_LIB_H_
#define INCLUDE_LIB_H_

/**
 * Library URC events
 */
enum {
	URC_FILE_DOWNLOAD_STATUS = 500,/**< File download status event see @ref wget_init */
	URC_FOTA_STARTED,              /**< FOTA start event */
	URC_FOTA_FINISHED,             /**< FOTA file download finished */
	URC_FOTA_FAILED,               /**< FOTA failed */
	URC_DEV_REBOOT_REQUEST,        /**< System reboot requested (generated if reboot command is executed) */
};

/**
 * Debug Log levels
 */
enum loglevel_e {
	/* Library Debug levels */
	DBG_OFF = 0,                 /**< Default loglevel, equivalent to printf */
	DBG_INFO,                    /**< Log level info */
	DBG_NETWORK,                 /**< Network layer debug level */

	/* User application Debug levels must start at DBG_USER_START */
	DBG_LIB_END = 23,
	DBG_USER_START = DBG_LIB_END,/**< Start of Application log levels */
};

#ifdef __cpluplus
extern "C" {
#endif

/**
 * Unsolicited response handler callback
 * @param urc_code			URC code
 * @param urc_param			URC parameter
 */
typedef void (*urc_callback_f)(unsigned int urc_code, unsigned int urc_param);

/**
 * Initialize SDK library
 * @param stdio			[in] STDIO port (e.g. /dev/ttyUSB0), can be NULL if STDIO is not required
 * @param handler		[in] Function pointer for handling unsolicited responses @ref urc_callback_f
 */
void siwilib_init(const char *stdio, urc_callback_f handler);

/**
 * Get device serial number
 * @return		Serial number of device. Buffer is statically allocated, do not free
 */
const char *siwi_getserial(void);

/**
 * Get SDK library version
 * @return		Library version string.
 */
const char *get_siwilib_version(void);

/**
 * Set system time-zone in +/-HH:MM format (e.g. +5:30)
 * @param tz	[in] Timezone value
 */
void system_settz(char *tz);

/**
 * Get current time-zone
 * @param tz	[out] Buffer to store timezone
 * @param size	[in] Size of buffer
 */
void system_gettz(char *tz, int size);

/**
 * Debug printf with debug level.
 * Can be used to print messages at specific loglevel
 * e.g. debug(DBG_INFO, "Hello\n");
 * Message will be printing if loglevel is set to 1
 *
 * @param level		[in] Debug level
 * @param fmt		[in] String format
 * @return			Number of bytes printed
 */
int debug(int level, const char *fmt, ...);

/**
 * Get OTA status
 * @return			Return 1 if FOTA in progress, 0 otherwise
 */
int ota_in_progress(void);

#ifdef __cpluplus
}
#endif

#endif /* INCLUDE_LIB_H_ */
