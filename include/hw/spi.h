/*
 * spi.h
 *
 */

#ifndef INCLUDE_HW_SPI_H_
#define INCLUDE_HW_SPI_H_

#include <plat/def_spi.h>

#ifdef __cplusplus
extern "C" {
#endif

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
enum spi_bitorder_e {
	SPI_MSB_FIRST,/**< MSB sent first (default) */
	SPI_LSB_FIRST,/**< LSB sent first */
};

/**
 * Chip select polarity flags
 */
enum spi_cspol_e {
	SPI_CSPOL_LOW, /**< Chip select is active low (default) */
	SPI_CSPOL_HIGH,/**< Chip select is active high */
};

/**
 * Initialize SPI Hardware and setup pinmux
 * @param port				[in] SPI Port Number (@ref spiport_e)
 * @param hardware_cs		[in] Set it TRUE, if application hardware chip
 * 								 select is used and hardware controls chip
 * 								 select status, FALSE otherwise
 * @param clock				[in] SPI Clock speed in Hz
 * @param mode				[in] SPI Mode (@ref spi_mode_e)
 * @param cs_pol			[in] Chip select Polarity (@ref spi_cspol_e)
 * @return					0 on success, negative on error
 */
int spi_hw_init(int port, int hardware_cs, int clock, int mode, int cs_pol);

/**
 * Set/Change SPI clock speed. Default speed is 10MHz
 * @param port				[in] SPI Port Number (@ref spiport_e)
 * @param clock_hz			[in] Clock speed in Hz
 * @return					0 on success, negative value on error
 */
int spi_hw_setclock(int port, unsigned long clock_hz);

/**
 * Configure SPI clock mode
 * @param port				[in] SPI Port Number (@ref spiport_e)
 * @param mode				[in] SPI mode, see @ref spi_mode_e
 * @return					0 on success, negative value on error
 */
int spi_hw_setmode(int port, int mode);

/**
 * Configure SPI bit shift order
 * @param port				[in] SPI Port Number (@ref spiport_e)
 * @param bit_order			[in] SPI bit shit order, see @ref spi_bitorder_e
 * @return					0 on success, negative value on error
 */
int spi_hw_setbitorder(int port, int bit_order);

/**
 * Configure chip-select line. Only needed when hardware_cs is used
 * @param port				[in] SPI Port Number (@ref spiport_e)
 * @param cs_pol			[in] Chip select polarity, see @ref spi_cspol_e
 * @return					0 on success, negative value on error
 */
int spi_hw_setcsmode(int port, int cs_pol);

/**
 * Perform SPI transaction
 * @param port				[in] SPI Port Number (@ref spiport_e)
 * @param wrbuf				[in] Pointer to data buffer to write, can be NULL
 * 								 if only read operation to be performed
 * @param rdbuf				[out] Pointer to buffer to store data, can be NULL
 * 								  if only write operation to be performed
 * @param length			[in] Length of data to read/write
 * @return					Length of data read/write on success, negative on error
 */
int spi_hw_transfer(int port, const unsigned char *wrbuf, unsigned char *rdbuf, int length);

/**
 * Release SPI hardware
 * @param port				[in] SPI Port Number (@ref spiport_e)
 * @return					0 on success, negative on error
 */
int spi_hw_free(int port);

#if defined(SOC_RDA8910) || defined(_DOXYGEN_)
/**
 * Control SPI HW CS line.
 * 
 * This function can be used to control chip select line of
 * SPI controller (which is not mapped as GPIO) when HW SPI
 * is used.
 * 
 * @note This function is only available on platforms with RDA8910 SoC.
 * 
 * @param port				[in] SPI Port Number (@ref spiport_e)
 * @param level				[in] chip select level (0 - low, 1 - high)
 * @return					0 on success, negative on error
 */
int spi_hw_cscontrol(int port, int level);
#endif

#ifdef __cplusplus
}
#endif

#endif /* INC_SPI_H_ */
