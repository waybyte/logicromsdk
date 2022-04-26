/**
 * @file gnss.h
 * @brief Onchip GNSS driver for Neoway N58 and Quectel EC200 modules
 * 
 */
#ifndef INCLUDE_HW_GNSS_H
#define INCLUDE_HW_GNSS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(PLATFORM_EC200U) || defined(PLATFORM_N58)
#define GNSS_PORT "/dev/ttyS2"
#define GNSS_BAUD gnss_hw_baudrate()
#endif

/**
 * @brief Set on-board GNSS chip power on/off
 * This function has no effect on module without GNSS feature
 * 
 * @param on_off 1 for On, 0 for off
 * @return 0 on success, -ve on failure
 */
int gnss_hw_power(int on_off);

/**
 * @brief Get GNSS chip power status
 * 
 * @return 1 if powered on, 0 if powered off
 */
int gnss_hw_status(void);

/**
 * @brief Get GNSS chip NMEA port baudrate
 * 
 * @return baudrate value
 */
uint32_t gnss_hw_baudrate(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_HW_GNSS_H */
