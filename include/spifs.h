/*
 * spifs.h
 *
 */

#ifndef INC_SPIFS_H_
#define INC_SPIFS_H_

#include <hw/spi.h>

/**
 * SPI Flash status
 */
enum sfstat_e {
	SF_STAT_NOTENABLED,/**< SPI Flash not enabled (Either not found or Initialization error) */
	SF_STAT_ENABLED,   /**< SPI Flash enabled but not mounted (Filesystem mount issue, Try spifs_enable() again */
	SF_STAT_MOUNTED,   /**< SPI Flash enabled and filesystem is mounted successfully */
};

/**
 * Enable SPI Flash and mount LFS filesystem
 * @param gpio_cs		[in] GPIO number connected to SPI chip select
 * @param speed_hz		[in] SPI Speed in Hz (max 10MHz)
 * @param mode			[in] SPI mode
 * @param byte_order	[in] SPI byte order, see
 * @return				0 on success, negative value on failure
 */
int spifs_enable(int gpio_cs, unsigned long speed_hz, int mode, int byte_order);

/**
 * Disable SPI Flash and unmount LFS filesystem
 * @return			0 on success, negative value on failure
 */
int spifs_disable(void);

/**
 * Get status of SPI Flash
 * @return			SPI Flash status see @ref sfstat_e
 */
int spifs_getstatus(void);

#endif /* INC_SPIFS_H_ */
