/*
 * crc.h
 *
 */

#ifndef INCLUDE_CRYPTO_CRC_H_
#define INCLUDE_CRYPTO_CRC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Calculate CRC32 checksum
 * Polynomial used: 0x04C11DB7
 * @param buf		[in] Input data buffer
 * @param size		[in] Size of data
 * @return			CRC32 checksum
 */
unsigned int crc32(const void *buf, int size);

/**
 * Calculate CRC-16 checksum
 * Polynomial: 0x1021, x^16 + x^12 + x^5 + 1
 * @param buf		[in] Input data buffer
 * @param size		[in] Size of data
 * @return			CRC16 Checksum
 */
unsigned short crc16_ccitt(const unsigned char *buf, int size);

/**
 * Calculate CRC-16 checksum
 * Polynomial: 0x8408, 1 + x^5 + x^12 + x^16 + 1
 * @param buf		[in] Input data buffer
 * @param size		[in] Size of data
 * @return			CRC16 Checksum
 */
unsigned short crc16_mcrf4xx(const unsigned char *buf, int size);

/**
 * Calculate CRC-8 checksum
 * @param buf		[in] Input data buffer
 * @param size		[in] Size of data
 * @return			CRC8 Checksum
 */
unsigned char crc8(const unsigned char *buf, int size);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_CRYPTO_CRC_H_ */
