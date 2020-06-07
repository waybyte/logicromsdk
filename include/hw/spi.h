/*
 * spi.h
 *
 */

#ifndef INCLUDE_HW_SPI_H_
#define INCLUDE_HW_SPI_H_

/**
 * Max supported Hardware SPI speed
 */
#define SPI_MAX_SPEED	10000000U

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize SPI Hardware and setup pinmux
 * @param managed_cs	[in] Set it TRUE, if application software manages chip select status, FALSE otherwise
 * @param clock_hz		[in] SPI Clock speed
 * @param mode			[in] SPI Mode (0-3)
 * @return				0 on success, negative on error
 */
int spi_hw_init(int managed_cs, unsigned int clock_hz, int mode);

/**
 * SPI Master harware read
 * @param buf			[out] Pointer to buffer where received data is stored
 * @param len			[in] Data to read
 * @return				Length of data read on success, negative on error
 */
int spi_hw_read(unsigned char *buf, int len);

/**
 * SPI Master write
 * @param buf			[in] Pointer to data buffer to write
 * @param len			[in] Length of data in buffer
 * @return				Length of data written on success, negative on error
 */
int spi_hw_write(const unsigned char *buf, int len);

/**
 * SPI Master write then read
 * @param wrbuf			[in] Pointer to data buffer to write
 * @param wrlen			[in] Length of data to write
 * @param rdbuf			[out] Pointer to buffer to store data
 * @param rdlen			[in] Length of data to read
 * @return				Length of data read on success, negative on error
 */
int spi_hw_writeread(const unsigned char *wrbuf, int wrlen, unsigned char *rdbuf, int rdlen);

/**
 * Set/Change SPI clock speed
 * @param clock_hz		[in] Clock speed in Hz
 */
void spi_hw_setclock(unsigned int clock_hz);

/**
 * Get currently set SPI clock speed
 * @return				Clock speed in Hz
 */
unsigned int spi_hw_getclock(void);

/**
 * Release SPI hardware
 * @return				0 on success, negative on error
 */
int spi_hw_free(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_SPI_H_ */
