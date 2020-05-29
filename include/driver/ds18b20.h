/*
 * ds18b20.h
 *
 */

#ifndef INCLUDE_DRIVER_DS18B20_H_
#define INCLUDE_DRIVER_DS18B20_H_

#include <inttypes.h>

/**
 * Sensor type
 */
enum senstype_e {
	UNKNOWN_DEV,/**< Device found but type is unknown */
	DS18S20,    /**< Sensor type DS18S20 */
	DS18B20,    /**< Sensor type DS18B20 */
	DS1822,     /**< Sensor type DS1822 */
};

#ifdef __cpluplus
extern "C" {
#endif

/**
 * Perform a one wire search for DS18x20 Sensor
 * @param ow_handle		[in] OneWire bus handle @ref OneWire()
 * @param newAddr		[out] Buffer to store newly found OneWire sensor
 * @return				On success, sensor type is returned @ref senstype_e, On error negative value is returned
 */
int ow_18x20_search(int ow_handle, uint8_t *newAddr);

/**
 * Read DS18x20 sensor
 * @param ow			[in] OneWire bus handle @ref OneWire()
 * @param addr			[in] Sensor ROM Address
 * @param temperature	[out] Sensor temperature value
 * @return				On success 0 is returned, negative value on error
 */
int ow_18x20_read(int ow, uint8_t *addr, float *temperature);

#ifdef __cpluplus
}
#endif

#endif /* INCLUDE_DRIVER_DS18B20_H_ */
