/*
 * inet.h
 *
 *  Created on: May 15, 2020
 *      Author: ajay_
 */

#ifndef INCLUDE_ARPA_INET_H_
#define INCLUDE_ARPA_INET_H_

#include <sys/types.h>

/* Address to accept any incoming messages.  */
#define INADDR_ANY			((in_addr_t) 0x00000000)
/* Address to send to all hosts.  */
#define INADDR_BROADCAST	((in_addr_t) 0xffffffff)
/* Address indicating an error return.  */
#define INADDR_NONE			((in_addr_t) 0xffffffff)

/**
 * IPv4 Address structure.
 */
struct in_addr {
	in_addr_t s_addr;	/**< IPv4 address binary format */
};

#ifdef __cpluplus
extern "C" {
#endif

/**
 * Convert IPv4 numbers-and-dots notation into binary data in network byte order.
 * @param cp		[in] Host address string
 * @return			address in network byte order
 */
in_addr_t inet_addr(const char *cp);

/**
 * Converts the Internet host address string (from the IPv4 numbers-and-dots notation) into binary form
 * @param cp		[in] Host address string
 * @param addr		[out] Address structure point to store converted address
 * @return			returns 1 if the supplied string was successfully interpreted, or 0 if the string is invalid (errno is not set on error).
 */
int inet_aton(const char *cp, struct in_addr *addr);

/**
 * Converts the Internet host address given in network byte order, to a string in IPv4 dotted-decimal notation.
 * @param in		[in] Address structure to convert
 * @return			string containing IPv4 address in dotted-decimal notation. The string is returned in a statically allocated buffer, which subsequent calls will overwrite.
 */
char *inet_ntoa(struct in_addr in);

/**
 * Converts the 32-bit unsigned integer from host byte order to network byte order
 * @param x			[in] 32-bit data
 * @return			network byte order 32-bit data
 */
uint32_t htonl(uint32_t x);

/**
 * Converts the unsigned short integer from host byte order to network byte order
 * @param x			[in] 16-bit data
 * @return			network byte order 16-bit data
 */
uint16_t htons(uint16_t x);

/**
 * Converts the 32-bit unsigned integer from network byte order to host byte order
 * @param x			[in] 32-bit data
 * @return			Host byte order 32-bit data
 */
uint32_t ntohl(uint32_t x);

/**
 * Converts the unsigned short integer from network byte order to host byte order.
 * @param x			[in] 16-bit data
 * @return			Host byte order 16-bit data
 */
uint16_t ntohs(uint16_t x);

#ifdef __cpluplus
}
#endif

#endif /* INCLUDE_ARPA_INET_H_ */
