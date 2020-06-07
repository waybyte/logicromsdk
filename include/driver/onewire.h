/*
 * OneWire library based optimized for GSM Module
 *
 * This library is based on:
 * https://github.com/PaulStoffregen/OneWire
 *
 * All credit goes to the owners
 */
#ifndef OneWire_h
#define OneWire_h

#include <inttypes.h>

#define OW_ADDR_LEN	8

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Register OneWire bus
 * @param pin		[in] IO pin number @ref gpioname_e
 * @return			On success, returns handle to OneWire Bus object. On error returns negative value.
 */
int OneWire(uint8_t pin);

/**
 * Perform a 1-Wire reset cycle. Returns 1 if a device responds
 * with a presence pulse.  Returns 0 if there is no device or the
 * bus is shorted or otherwise held low for more than 250uS
 * @param handle	[in] OneWire bus handle
 * @return
 */
uint8_t ow_reset(int handle);

/**
 * Issue a 1-Wire ROM select command (0x55), you do the reset first.
 * @param handle	[in] OneWire bus handle
 * @param rom		[in] ROM address to select
 */
void ow_select(int handle, const uint8_t rom[8]);

/**
 * Issue a 1-Wire ROM skip command (0xCC), to address all on bus.
 * @param handle	[in] OneWire bus handle
 */
void ow_skip(int handle);

/**
 * Write a byte. If 'power' is one then the wire is held high at
 * the end for parasitically powered devices. You are responsible
 * for eventually depowering it by calling @ref ow_depower() or doing
 * another read or write.
 * @param handle	[in] OneWire bus handle
 * @param val		[in] Input byte
 * @param power		[in] Power state after write
 */
void ow_write(int handle, uint8_t val, uint8_t power);

/**
 * Write multiple bytes on OneWire bus
 * @param handle	[in] OneWire bus handle
 * @param buf		[in] Buffer containing data to send
 * @param count		[in] Length of data in buffer
 * @param power		[in] Power state after write @see ow_write()
 */
void ow_write_bytes(int handle, const uint8_t *buf, uint16_t count, uint8_t power);

/**
 * Read one byte from OneWire
 * @param handle	[in] OneWire bus handle
 * @return			Read byte
 */
uint8_t ow_read(int handle);

/**
 * Read multiple bytes from OneWire bus
 * @param handle	[in] OneWire bus handle
 * @param buf		[out] Buffer to store data
 * @param count		[in] length of data to read
 */
void ow_read_bytes(int handle, uint8_t *buf, uint16_t count);

/**
 * Write one bit on bus. The bus is always left powered at the end
 * @see ow_write
 * @param handle	[in] OneWire bus handle
 * @param v			[in] Bit value
 */
void ow_write_bit(int handle, uint8_t v);

/**
 * Read one bit from bus
 * @param handle	[in] OneWire bus handle
 * @return			Bit value read
 */
uint8_t ow_read_bit(int handle);

/**
 * Stop forcing power onto the bus. You only need to do this if
 * you used the 'power' flag to @ref ow_write() or used a @ref ow_write_bit() call
 * and aren't about to do another read or write. You would rather
 * not leave this powered if you don't have to, just in case
 * someone shorts your bus.
 * @param handle	[in] OneWire bus handle
 */
void ow_depower(int handle);

/**
 * Clear the search state so that if will start from the beginning again.
 * @param handle	[in] OneWire bus handle
 */
void ow_reset_search(int handle);

/**
 * Setup the search to find the device type 'family_code' on the next call
 * to search(*newAddr) if it is present.
 * @param handle		[in] OneWire bus handle
 * @param family_code	[in] Family code to search
 */
void ow_target_search(int handle, uint8_t family_code);

/**
 * Perform a Normal search on OneWire bus (0xF0)
 * Look for the next device. Returns 1 if a new address has been
 * returned. A zero might mean that the bus is shorted, there are
 * no devices, or you have already retrieved all of them.  It
 * might be a good idea to check the CRC to make sure you didn't
 * get garbage.  The order is deterministic. You will always get
 * the same devices in the same order.
 * @param handle	[in] OneWire bus handle
 * @param newAddr	[out] Buffer to store address of newly found device
 * @return			returns true if new address found, false if not found
 */
uint8_t ow_search(int handle, uint8_t *newAddr);

/**
 * Perform a conditional search on OneWire bus (0xEC)
 * @see ow_search
 * @param handle	[in] OneWire bus handle
 * @param newAddr	[out] Buffer to store address of newly found device
 * @return			returns true if new address found, false if not found
 */
uint8_t ow_search_cond(int handle, uint8_t *newAddr);

/**
 * Compute a Dallas Semiconductor 8 bit CRC, these are used in the
 * ROM and scratchpad registers.
 * @param addr		[in] Input buffer to calculate CRC on
 * @param len		[in] Length of input data
 * @return			CRC value
 */
uint8_t ow_crc8(const uint8_t *addr, uint8_t len);

/**
 *  Compute the 1-Wire CRC16 and compare it against the received CRC.
 *  Example usage (reading a DS2408):
 *  	// Put everything in a buffer so we can compute the CRC easily.
 *  	uint8_t buf[13];
 *  	buf[0] = 0xF0;    // Read PIO Registers
 *  	buf[1] = 0x88;    // LSB address
 *  	buf[2] = 0x00;    // MSB address
 *  	ow_write_bytes(handle, net, buf, 3);    // Write 3 cmd bytes
 *  	ow_read_bytes(handle net, buf+3, 10);  // Read 6 data bytes, 2 0xFF, 2 CRC16
 *  	if (!ow_check_crc16(buf, 11, &buf[11])) {
 *  		// Handle error.
 *  	}
 *
 * @param input			[in] Array of bytes to checksum.
 * @param len			[in] How many bytes to use.
 * @param inverted_crc	[out] The two CRC16 bytes in the received data.
 * 							  This should just point into the received data,
 * 							  *not* at a 16-bit integer.
 * @param crc			[in] The crc starting value (0 if not used)
 * @return				True, if the CRC matches.
 */
uint8_t ow_check_crc16(const uint8_t* input, uint16_t len, const uint8_t* inverted_crc, uint16_t crc);

/**
 * Compute a Dallas Semiconductor 16 bit CRC.  This is required to check
 * the integrity of data received from many 1-Wire devices.  Note that the
 * CRC computed here is *not* what you'll get from the 1-Wire network,
 * for two reasons:
 * 	1) The CRC is transmitted bitwise inverted.
 * 	2) Depending on the endian-ness of your processor, the binary
 * representation of the two-byte return value may have a different
 * byte order than the two bytes you get from 1-Wire.
 *
 * @param input		[in] Array of bytes to checksum.
 * @param len		[in] How many bytes to use.
 * @param crc		[in] The crc starting value (0 if not used)
 * @return			The CRC16, as defined by Dallas Semiconductor.
 */
uint16_t ow_crc16(const uint8_t* input, uint16_t len, uint16_t crc);

#ifdef __cplusplus
}
#endif

#endif
