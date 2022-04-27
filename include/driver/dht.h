/**
 * DHT Temperature & Humidity Sensor library optimized for GSM module
 *
 * DHT Library based on Rob Tillaart's DHTlib
 * ref: https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib
 * version: 0.1.29
 */

#ifndef INC_DRIVER_DHT_H
#define INC_DRIVER_DHT_H

#ifdef __cplusplus
extern "C" {
#endif

#define DHT_LIB_VERSION "0.1.29"

/**
 * DHT err codes
 */
enum dht_err_e {
	DHTLIB_OK,                 /**< DHT Read ok */
	DHTLIB_ERROR_CHECKSUM = -1,/**< Checksum error */
	DHTLIB_ERROR_TIMEOUT = -2, /**< DHT read timeout */
	DHTLIB_ERROR_CONNECT = -3, /**< DHT connection error */
	DHTLIB_ERROR_ACK_L = -4,   /**< DHT ACK signal low error (check connection) */
	DHTLIB_ERROR_ACK_H = -5,   /**< DHT ACK signal high error (check connection) */
};

/**
 * DHT21 read
 */
#define dht_read21(p,h,t)	dht_read(p,h,t)
/**
 * DHT22 read
 */
#define dht_read22(p,h,t)	dht_read(p,h,t)
/**
 * DHT33 read
 */
#define dht_read33(p,h,t)	dht_read(p,h,t)
/**
 * DHT44 read
 */
#define dht_read44(p,h,t)	dht_read(p,h,t)

/**
 * DHT11 Read function
 * @param iohandle		[in] GPIO pin handle returned by @ref gpio_request()
 * @param humidity		[out] Humidity value
 * @param temperature	[out] Temperature value
 * @return				DHT error code @ref dht_err_e
 */
int dht_read11(int iohandle, double *humidity, double *temperature);

/**
 * DHTXX Read function
 * where XX is 21,22,33,44
 * A macro based shorthand is also available for code readability.
 * @see dht_read21
 * @see dht_read22
 * @see dht_read33
 * @see dht_read44
 * @param iohandle		[in] GPIO pin handle @ref gpio_request()
 * @param humidity		[out] Humidity value
 * @param temperature	[out] Temperature value
 * @return				DHT error code @ref dht_err_e
 */
int dht_read(int iohandle, double *humidity, double *temperature);

#ifdef __cplusplus
}
#endif

#endif /* INC_DRIVER_DHT_H */
