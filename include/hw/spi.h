/*
 * spi.h
 *
 */

#ifndef INCLUDE_HW_SPI_H_
#define INCLUDE_HW_SPI_H_

/**
 * Max supported Hardware SPI speed (default)
 */
#define SPI_MAX_SPEED	10000000U

/**
 * SPI Modes to configure clock polarity and clock phase.
 *
 * For more information see https://en.wikipedia.org/wiki/Serial_Peripheral_Interface#Clock_polarity_and_phase
 */
enum spi_mode_e {
	SPI_MODE0,/**< Mode 0 (default): CPOL = 0, CPHA = 0 */
	SPI_MODE1,/**< Mode 1: CPOL = 0, CPHA = 1 */
	SPI_MODE2,/**< Mode 2: CPOL = 1, CPHA = 0 */
	SPI_MODE3,/**< Mode 3: CPOL = 1, CPHA = 1 */
};

/**
 * SPI byte order to configure shit in/out order of data byte.
 */
enum spi_byteorder_e {
	SPI_BYTE_MSB_FIRST,/**< MSB sent first (default) */
	SPI_BYTE_LSB_FIRST,/**< LSB sent first */
};

/**
 * Chip select mode configures how chip select line is de-asserted during a
 * transaction. It only used when hardware chip select is used during
 * initialization. See @ref spi_hw_init
 */
enum spi_csmode_e {
	SPI_CSMODE_TRANSACTION,/**< CS line de-asserted between each transaction.
								This is default behavior of CS line. */
	SPI_CSMODE_BYTE,       /**< CS line de-asserted after each byte in a
								transaction */
};

/**
 * Chip select polarity flags
 */
enum spi_cspol_e {
	SPI_CSPOL_LOW, /**< Chip select is active low (default) */
	SPI_CSPOL_HIGH,/**< Chip select is active high */
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize SPI Hardware and setup pinmux
 * @param int hardware_cs	[in] Set it TRUE, if application hardware chip
 * 								 select is used and hardware controls chip
 * 								 select status, FALSE otherwise
 * @return					0 on success, negative on error
 */
int spi_hw_init(int hardware_cs);

/**
 * Set/Change SPI clock speed. Default speed is @ref SPI_MAX_SPEED
 * @param clock_hz			[in] Clock speed in Hz
 * @return					0 on success, negative value on error
 */
int spi_hw_setclock(unsigned long clock_hz);

/**
 * Configure SPI clock mode
 * @param mode				[in] SPI mode, see @ref spi_mode_e
 * @return					0 on success, negative value on error
 */
int spi_hw_setmode(int mode);

/**
 * Configure SPI byte shift order
 * @param byte_order		[in] SPI byte order, see @ref spi_byteorder_e
 * @return					0 on success, negative value on error
 */
int spi_hw_setbyteorder(int byte_order);

/**
 * Configure chip-select line. Only needed when hardware_cs is used
 * @param cs_mode			[in] Chip select mode, see @ref spi_csmode_e
 * @param cs_pol			[in] Chip select polarity, see @ref spi_cspol_e
 * @return					0 on success, negative value on error
 */
int spi_hw_setcsmode(int cs_mode, int cs_pol);

/**
 * Perform SPI transaction
 * @param wrbuf				[in] Pointer to data buffer to write, can be NULL
 * 								 if only read operation to be performed
 * @param rdbuf				[out] Pointer to buffer to store data, can be NULL
 * 								  if only write operation to be performed
 * @param length			[in] Length of data to read/write
 * @return					Length of data read/write on success, negative on error
 */
int spi_hw_transfer(const unsigned char *wrbuf, unsigned char *rdbuf, int length);

/**
 * Release SPI hardware
 * @return					0 on success, negative on error
 */
int spi_hw_free(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_SPI_H_ */
