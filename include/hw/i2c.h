/*
 * i2c.h
 *
 */

#ifndef INCLUDE_HW_I2C_H_
#define INCLUDE_HW_I2C_H_

#include <plat/def_i2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize I2C hardware and setup pin-mux.
 * Please check hardware guide for I2C pin details.
 * @param port			[in] I2C Port (@ref i2cport_e)
 * @param speed_khz		[in] I2C Speed in Khz (<= 400)
 * @return				0 on success, negative value on error
 */
int i2c_hw_init(int port, int speed_khz);

/**
 * Set I2C master clock speed
 * @param port			[in] I2C Port (@ref i2cport_e)
 * @param speed_khz		[in] I2C Speed in Khz (<= 400)
 * @return				0 on success, negative value on error
 */
int i2c_hw_setspeed(int port, int speed_khz);

/**
 * Master send data over I2C slave device
 * Hardware FIFO only support upto 8 bytes at one time for transfer
 * @param port			[in] I2C Port (@ref i2cport_e)
 * @param address		[in] 7-bit Slave address
 * @param buffer		[in] Pointer to buffer containing data
 * @param len			[in] Length of data to send (must be less than or equal to 8)
 * @return				Length of bytes written on success, negative value on error
 */
int i2c_hw_write(int port, unsigned char address, const void *buffer, int len);

/**
 * Master read data from I2C slave device
 * @param port			[in] I2C Port (@ref i2cport_e)
 * @param address		[in] 7-bit slave address
 * @param buffer		[out] Pointer to buffer to store data
 * @param len			[in] No. of bytes to read
 * @return				Length of data read from slave on success, negative value on error
 */
int i2c_hw_read(int port, unsigned char address, void *buffer, int len);

/**
 * Write and Read operation with repeated start.
 * Operation is performed in two transactions separated by repeated start, Each
 * transaction is limited to max fifo length of 8 bytes.
 *
 * @param port			[in] I2C Port (@ref i2cport_e)
 * @param address		[in] 7-bit slave address
 * @param wrbuf			[in] Pointer to buffer for write operation
 * @param wrlen			[in] Length of data in @a wrbuf
 * @param rdbuf			[out] Pointer to buffer for storing data
 * @param rdlen			[in] No. of bytes to read
 * @return				Length of data read from slave on success, negative value on error
 */
int i2c_hw_writeread(int port, unsigned char address, const void *wrbuf, int wrlen, void *rdbuf, int rdlen);

/**
 * De-Init I2C bus and release GPIO
 * @param port			[in] I2C Port (@ref i2cport_e)
 * @return				0 on success, negative value on error
 */
int i2c_hw_free(int port);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_HW_I2C_H_ */
