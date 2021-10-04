#ifndef INCLUDE_PLAT_DEF_SPI_H_
#define INCLUDE_PLAT_DEF_SPI_H_

/**
 * SPI port list
 */
enum spiport_e {
	SPI_PORT_0, /**< SPI Port 0 */
#ifdef SOC_RDA8910
	SPI_PORT_1, /**< SPI Port 1 */
#endif
};

#endif /* INCLUDE_PLAT_DEF_SPI_H_ */
