/**
 * @file gpsdriver.h
 * @brief GPS Driver interface used by GPS library
 * 
 */
#ifndef INC_GPSDRIVER_H_
#define INC_GPSDRIVER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief GNSS message to enable
 * 
 */
enum gnssmsg_e {
	NMEA_GGA = 1 << 0,
	NMEA_GLL = 1 << 1,
	NMEA_GSA = 1 << 2,
	NMEA_GSV = 1 << 3,
	NMEA_RMC = 1 << 4,
	NMEA_VTG = 1 << 5,
};

/**
 * @brief Module operation mode (if supported)
 * 
 */
enum gnssopmode_e {
	OPMODE_NORMAL,
	OPMODE_SLOW,
};

/**
 * @brief GNSS software reset type
 * 
 */
enum gnssreset_e {
	RESET_HOT,
	RESET_WARM,
	RESET_COLD,
};

/**
 * @brief GPS Driver Structure
 * 
 */
struct gpsdriver_t {
	const char *name; /** Driver Name */
	int command_checksum; /** Command require checksum? 1 - yes, 0 - no */
	const char ** const response_ident; /** List of module specific response identifier */
	int response_ident_count; /** count of \ref gpsdriver_t::response_ident */
	/**
	 * @brief Perform software reset, NULL if not implemented
	 * 
	 * @param type reset type @ref gnssreset_e
	 * @return status, 0 for success
	 */
	int (*restart)(int type);
	/**
	 * @brief Configure GNSS module, NULL if not implemented
	 * 
	 * @param msg_type bitwise ORed value of gnssmsg_e, for messages to be enabled
	 * @param rate_ms output datarate in ms, currently unused (1000ms default)
	 * @param op_mode Operation mode to configure GNSS module for Normal or slow motion operation
	 * @return status, 0 for success
	 */
	int (*config)(unsigned int msg_type, unsigned int rate_ms, int op_mode);
	/**
	 * @brief Setup/change baudrate, called from gpsbaud command handler, NULL if not implemented
	 * 
	 * @param baud baudrate to set
	 * @return status, 0 for success
	 */
	int (*setup_baud)(unsigned int baud);
	/**
	 * @brief callback function for module specific reponse identifiers @ref gpsdriver_t::response_ident\n
	 * NULL if not implemented
	 * 
	 * @param msg response (without checksum)
	 * @return status, 0 for success
	 */
	int (*response_handler)(const char *msg);
	unsigned int reserved; /** must be 0 */
};

/**
 * @brief Set GPS driver to CASIC type\n
 * 
 * This driver is used in following GNSS modules or as integrated GNSS\n
 *   1. Neoway N58 LTE Cat.1\n
 *   2. Neoway G2\n
 *   3. Neoway G7A\n
 * 
 * @return 0 on success
 */
int gps_set_driver_casic(void);

/**
 * @brief Set GPS driver to Quectel L89R2.0 GNSS/IRNSS Module
 * 
 * @return 0 on success
 */
int gps_set_driver_l89r2(void);

/**
 * @brief Set GPS driver to module using MT3333 or MT3339 chipset\n 
 * This driver can be used for following GNSS/GSM Modules\n 
 *   1. Quectel L86
 *   2. Quectel MC60
 *   3. Quectel MC20
 * 
 * @return 0 on success
 */
int gps_set_driver_mt333x(void);

/**
 * @brief GPS driver for SIRF III chipset
 * 
 * @return 0 on success
 */
int gps_set_driver_sirf3(void);

/**
 * @brief GPS driver for STA8090 chipset\n
 * This driver can be used for Quectel L89 IRNSS module.
 * 
 * @note Please do not confuse with L89 and L89R2, check datasheet
 * before using correct driver.
 * 
 * @return int 
 */
int gps_set_driver_stirnss(void);

/**
 * @brief GPS Driver for uc6226 uc6228 chipset\n 
 * This driver can be used for following modules:
 * 
 *   1. Quectel L76C
 *   2. Quectel L26C
 *   3. Quectel BC20 (NB-IoT)
 *   4. Quectel EC200UCN-AA LTE Cat.1 Module
 * 
 * @return 0 on success
 */
int gps_set_driver_uc622x(void);

/**
 * @brief Set custom defined GPS driver
 * 
 * @param driver GPS module driver structure
 * @return 0 on success, negative on failure
 */
int gps_set_driver(const struct gpsdriver_t *driver);

#ifdef __cplusplus
}
#endif

#endif /* INC_GPSDRIVER_H_ */
