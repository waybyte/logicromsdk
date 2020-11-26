/*
 * sockets.h
 *
 *  Created on: May 15, 2020
 *      Author: ajay_
 */

#ifndef INCLUDE_SYS_SOCKET_H_
#define INCLUDE_SYS_SOCKET_H_

#include <sys/types.h>

#include "../../include/arpa/inet.h"

/**
 * Protocol family unspecified
 */
#define PF_UNSPEC		0

/**
 * Internet address family (TCP, UDP)
 */
#define PF_INET			2

/**
 * Internet address family V6
 */
#define PF_INET6		10

/**
 * BSD address family
 */
#define AF_UNSPEC		PF_UNSPEC

/**
 * Internet address family (TCP, UDP)
 */
#define AF_INET			PF_INET

/**
 * Internet address family V6
 */
#define AF_INET6		PF_INET6

/**
 * Stream socket type (TCP/connection oriented)
 */
#define SOCK_STREAM     1

/**
 * Datagram socket (UDP/connection-less)
 */
#define SOCK_DGRAM      2

/**
 * Socket type non-blocking, This flag can be ORed with socket type to specify non-blocking operation of socket.
 * This is to prevent extra call to fcntl
 */
#define SOCK_NONBLOCK	4

/**
 * TCP protocol
 */
#define IPPROTO_TCP     1

/**
 * UDP protocol
 */
#define IPPROTO_UDP     2

/* Socket options for setsockopt and getsockopt */

/**
 * Socket level
 */
#define SOL_SOCKET        1

/* Socket options, only implemented ones are shown */
#define SO_TYPE			3	/**< Get socket type */
#define SO_SNDBUF		7	/**< Get send buffer size */
#define SO_RCVBUF		8	/**< Get receive buffer size */
#define SO_KEEPALIVE	9	/**< Get/set keep alive status */
#define SO_LINGER		11	/**< get/set @ref linger structure */
#define SO_RCVTIMEO		15	/**< Set/get receive timeout */
#define SO_SNDTIMEO		16	/**< set/get send timeout */
#define SO_CONTIMEO		17	/**< set/get connection timeout */

/* TCP Options */
#define TCP_NODELAY		20	/**< Enable/Disable Nagle algorithm */
#define TCP_MAXSEG		21	/**< Get max segment size */
#define TCP_QUICKACK	22	/**< Get Quickack mode status */

#define IP_TTL			30	/**< Get/Set TTL value */

/**
 * Nonblocking i/o for this operation only
 */
#define MSG_DONTWAIT   0x08

#if !defined(sa_family_t) && !defined(SA_FAMILY_T_DEFINED)
typedef uint8_t sa_family_t;
#endif

#if !defined(socklen_t) && !defined(SOCKLEN_T_DEFINED)
typedef uint32_t socklen_t;
#endif

/*
 * Structure used for manipulating linger option.
 */
struct linger {
	int l_onoff;	/**< option on/off */
	int l_linger;	/**< linger time in seconds */
};

/**
 * IPv4 Socket address structure
 */
struct sockaddr_in {
	uint8_t sin_len;			/**< Length of structure */
	sa_family_t sin_family;		/**< Address family (AF_INET only) */
	in_port_t sin_port;			/**< Port in network byte order */
	struct in_addr sin_addr;	/**< IPv4 address */
	char sin_zero[8];			/**< reserved */
};

struct sockaddr_in6 {
	uint8_t sin6_len;			/**< length of this structure */
	sa_family_t sin6_family;	/**< AF_INET6 */
	in_port_t sin6_port;		/**< Transport layer port # */
	uint32_t sin6_flowinfo;		/**< IPv6 flow information */
	struct in6_addr sin6_addr;	/**< IPv6 address */
	uint32_t sin6_scope_id;		/**< Set of interfaces for scope */
};

/**
 * Generic socket address structure
 */
struct sockaddr {
	unsigned char	sa_len;		/**< total length */
	sa_family_t	sa_family;		/**< address family */
	char		sa_data[14];	/**< actually longer; address value */
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create an endpoint for communnication
 * @param domain			[in] Communication domain, Must be AF_INET
 * @param type				[in] Socket type @ref SOCK_STREAM or @ref SOCK_DGRAM
 * @param protocol			[in] Protocol type, 0 for auto-select
 * @return					On success, a file descriptor for the new socket is returned.  On error, -1 is returned, and errno is set appropriately.
 */
int socket(int domain, int type, int protocol);

/**
 * Initiate a connection socket
 * @param sockfd			[in] Socket file descriptor
 * @param addr				[in] Socket address
 * @param addrlen			[in] Size of @a addr
 * @return					If the connection or binding succeeds, zero is returned.  On error, -1 is returned, and errno is set appropriately.
 */
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

/**
 * Send data on a connected socket
 * @param sockfd			[in] Socket file descriptor
 * @param buf				[in] data buffer to send
 * @param len				[in] size of data to send
 * @param flags				[in] Flags can be @ref MSG_DONTWAIT for non-blocking operation or 0 for no flags
 * @return					On success, return the number of bytes sent.  On error, -1 is returned, and errno is set appropriately.
 */
int send(int sockfd, const void *buf, size_t len, int flags);

/**
 * Send data to node. This function is used to send data on datagram socket.
 * @param sockfd			[in] Socket file descriptor
 * @param buf				[in] data buffer to send
 * @param len				[in] size of data to send
 * @param flags				[in] Flags can be @ref MSG_DONTWAIT for non-blocking operation or 0 for no flags
 * @param dest_addr			[in] Destination socket address
 * @param addrlen			[in] Sizeof @a dest_addr
 * @return					On success, return the number of bytes sent.  On error, -1 is returned, and errno is set appropriately.
 */
int sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen);

/**
 * Receive data from connected socket
 * @param sockfd			[in] Socket file descriptor
 * @param buf				[out] Pointer to buffer to store received data
 * @param len				[in] requested length of data to read
 * @param flags				[in] Flags can be @ref MSG_DONTWAIT for non-blocking operation or 0 for no flags
 * @return					On success, return the number of bytes received.  On error, -1 is returned, and errno is set appropriately.
 */
int recv(int sockfd, void *buf, size_t len, int flags);

/**
 * Receive data from node. This function is used to receive data from datagram socket
 * @param sockfd			[in] Socket file descriptor
 * @param buf				[out] Pointer to buffer to store received data
 * @param len				[in] Requested length of data
 * @param flags				[in] Flags can be @ref MSG_DONTWAIT for non-blocking operation or 0 for no flags
 * @param src_addr			[out] Source address of node
 * @param addrlen			[out] Length of @a src_addr
 * @return					On success, return the number of bytes received.  On error, -1 is returned, and errno is set appropriately.
 */
int recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);

/**
 * Get socket option
 * @param sockfd			[in] Socket file descriptor
 * @param level				[in] Socket API level (@ref SOL_SOCKET only)
 * @param optname			[in] Name of option
 * @param optval			[out] Buffer to store option value
 * @param optlen			[out] length of @a optval buffer, value is updated with actual size of @a optval
 * @return					On success, zero is returned for the standard options.  On error, -1 is returned, and errno is set appropriately.
 */
int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);

/**
 * Set socket option
 * @param sockfd			[in] Socket file descriptor
 * @param level				[in] Socket API level (@ref SOL_SOCKET only)
 * @param optname			[in] Name of option
 * @param optval			[in] buffer containing value of option
 * @param optlen			[in] sizeof @a optval
 * @return					On success, zero is returned for the standard options.  On error, -1 is returned, and errno is set appropriately.
 */
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_SYS_SOCKET_H_ */
