/*
 * i2c.h
 *
 */

#ifndef INCLUDE_HW_I2C_H_
#define INCLUDE_HW_I2C_H_

#ifdef __cpluplus
extern "C" {
#endif

/**
 * Initialize I2C hardwar and setup pin-mux
 * @param speed_khz		[in] I2C Speed in Khz (must be < 400)
 * @return				0 on success, negative value on error
 */
int i2c_hw_init(int speed_khz);

/**
 * Master send data over I2C slave device
 * Hardware FIFO only support upto 8 bytes at one time for transfer
 * @param address		[in] 7-bit Slave address
 * @param buffer		[in] Pointer to buffer containing data
 * @param len			[in] Length of data to send (must be less than or equal to 8)
 * @return				Length of bytes written on success, negative value on error
 */
int i2c_hw_write(unsigned char address, unsigned char *buffer, int len);

/**
 * Master read data from I2C slave device
 * @param address		[in] 7-bit slave address
 * @param buffer		[out] Pointer to buffer to store data
 * @param len			[in] No. of bytes to read
 * @return				Length of data read from slave on success, negative value on error
 */
int i2c_hw_read(unsigned char address, unsigned char *buffer, int len);

/**
 * Write and Read operation with repeated start.
 * Operation is performed in two transactions separated by repeated start, Each
 * transaction is limited to max fifo length of 8 bytes.
 *
 * @param address		[in] 7-bit slave address
 * @param wrbuf			[in] Pointer to buffer for write operation
 * @param wrlen			[in] Length of data in @a wrbuf
 * @param rdbuf			[out] Pointer to buffer for storing data
 * @param rdlen			[in] No. of bytes to read
 * @return				Length of data read from slave on success, negative value on error
 */
int i2c_hw_rw(unsigned char address, unsigned char *wrbuf, int wrlen, unsigned char *rdbuf, int rdlen);

/**
 * De-Init I2C bus and release GPIO
 * @return				0 on success, negative value on error
 */
int i2c_hw_free(void);

#ifdef __cpluplus
}
#endif

#endif /* INCLUDE_HW_I2C_H_ */
