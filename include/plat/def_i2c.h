#ifndef INCLUDE_PLAT_DEF_I2C_H_
#define INCLUDE_PLAT_DEF_I2C_H_

/**
 * I2C port list
 */
enum i2cport_e {
	I2C_PORT_0, /**< I2C Port 0 */
#ifdef SOC_RDA8910
	I2C_PORT_1, /**< I2C Port 1 */
#endif
};

#endif /* INCLUDE_PLAT_DEF_I2C_H_ */
