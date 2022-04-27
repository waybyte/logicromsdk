/*
 * xmodem.h
 *
 */
#ifndef INC_PROTO_XMODEM_H
#define INC_PROTO_XMODEM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Serial port configuration
 * 
 */
struct xmodem_port_t {
	const char *port;	/**< Serial port device name e.g. "/dev/ttyS1" */
	uint32_t speed;		/**< Baudrate value e.g. 115200 */
	uint8_t data_bits;	/**< Data bits: 8,7,6 or 5 */
	uint8_t parity;		/**< Parity: 'E' - Even, 'O' - Odd, or 'N' - None */
	uint8_t stop_bits;	/**< Stop bits: 1 or 2 */
};

/**
 * XMODEM Receive
 * @param src		[in] Source serial port device @ref xmodem_port_t
 * @param dest		[in] Destination filename
 * @param is_binary	[in] 1 if binary transfer, 0 for ASCII
 * @return			0 on success, negative on error
 */
int xmodem_receive(const struct xmodem_port_t *src, const char *dest, int is_binary);

/**
 * XMODEM Send
 * @param src		[in] Source filename
 * @param dest		[in] Destination serial port device @ref xmodem_port_t
 * @param xmodem_1k	[in] 1 if Xmodem 1K transfer protocol
 * @return			0 on success, negative on error
 */
int xmodem_transmit(const char *src, const struct xmodem_port_t *dest, int xmodem_1k);

#ifdef __cplusplus
}
#endif

#endif /* INC_PROTO_XMODEM_H */
