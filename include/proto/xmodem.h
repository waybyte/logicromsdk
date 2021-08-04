/*
 * xmodem.h
 *
 */
#ifndef INC_PROTO_XMODEM_H
#define INC_PROTO_XMODEM_H

/**
 * XMODEM Receive
 * @param src		[in] Source serial port device
 * @param dest		[in] Destination filename
 * @param is_binary	[in] 1 if binary transfer, 0 for ASCII
 * @return			0 on success, negative on error
 */
int xmodem_receive(const char *src, const char *dest, int is_binary);

/**
 * XMODEM Send
 * @param src		[in] Source filename
 * @param dest		[in] Destination serial port device
 * @param xmodem_1k	[in] 1 if Xmodem 1K transfer protocol
 * @return			0 on success, negative on error
 */
int xmodem_transmit(const char *src, const char *dest, int xmodem_1k);

#endif /* INC_PROTO_XMODEM_H */
