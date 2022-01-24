/*
 * netdb.h
 *
 */

#ifndef INCLUDE_NETDB_H_
#define INCLUDE_NETDB_H_

#include <stddef.h>

/**
 * Maximum hostname length
 */
#define HOSTNAME_MAX_LENGTH		255

#define HOST_NOT_FOUND		1		/**< Host not found */
#define TRY_AGAIN			2		/**< Unable to resolve, Try again */
#define NO_RECOVERY			3		/**< Unable to recover from error */
#define NO_DATA				4		/**< Host valid but no response */

/**
 * Host entry structure
 */
struct hostent {
	char *h_name;		/**< Official name of the host. */
	char **h_aliases;	/**< A pointer to an array of pointers to alternative host names */
	int h_addrtype;		/**< Address type (AF_INET only) */
	int h_length;		/**< The length of address in bytes */
	char **h_addr_list;	/**< A pointer to an array of pointers to network addresses (in
							network byte order) for the host, terminated by a null pointer. */
#define h_addr h_addr_list[0]	/**< for backward compatibility */
};

struct addrinfo {
    int               ai_flags;      /* Input flags. */
    int               ai_family;     /* Address family of socket. */
    int               ai_socktype;   /* Socket type. */
    int               ai_protocol;   /* Protocol of socket. */
    socklen_t         ai_addrlen;    /* Length of socket address. */
    struct sockaddr  *ai_addr;       /* Socket address of socket. */
    char             *ai_canonname;  /* Canonical name of service location. */
    struct addrinfo  *ai_next;       /* Pointer to next in list. */
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * errno value can be any of following:
 * @ref HOST_NOT_FOUND
 * @ref TRY_AGAIN
 * @ref NO_RECOVERY
 * @ref NO_DATA
 */
extern int h_errno;

/**
 * Retrieve host IP address from host name.
 * @param name		[in] Hostname
 * @return			return the @ref hostent structure or a null pointer if an error occurs.
 * 					On error, the h_errno variable holds an error number.
 * 					When non-NULL, the return value may point at static data
 */
struct hostent *gethostbyname(const char *name);

/**
 * Thread-safe, reentrant function to retrieve host IP address from host name
 * @param name		[in] Hostname
 * @param ret		[out] Pointer to hostentry structure to fill
 * @param buf		[in] buffer storage to use for filling hostentry structure
 * @param buflen	[in] length of buffer
 * @param result	[out] Hostentry structure pointer
 * @param h_errnop	[out] pointer to store error code
 * @return			0 on success, -1 on error and @a h_errnop will be updated with error code
 */
int gethostbyname_r(const char *name, struct hostent *ret, char *buf,
                size_t buflen, struct hostent **result, int *h_errnop);

/**
 * Translates the name of a service location (for example, a host name) and/or
 * a service name and returns a set of socket addresses and associated
 * information to be used in creating a socket with which to address the
 * specified service. Memory for the result is allocated internally and must
 * be freed by calling lwip_freeaddrinfo()!
 * Due to a limitation in @a gethostbyname, only the first address of a host
 * is returned. Also, service names are not supported (only port numbers)!
 * 
 * @note This API is not available on GSM platforms
 * 
 * @param nodename	[in] descriptive name or address string of the host (may be NULL -> local address)
 * @param servname	[in] port number as string of NULL
 * @param hints		[in,out] structure containing input values that set socktype and protocol
 * @param res		[in,out] pointer to a pointer where to store the result (set to NULL on failure)
 */
int getaddrinfo(const char *nodename,
				const char *servname,
				const struct addrinfo *hints,
				struct addrinfo **res);

/**
 * Frees one or more addrinfo structures returned by @a getaddrinfo, along with
 * any additional storage associated with those structures. If the ai_next
 * field of the structure is not null, the entire list of structures is freed.
 *
 * @note This API is not available on GSM platforms
 * 
 * @param ai		[in] struct @a addrinfo to free
 */
void freeaddrinfo(struct addrinfo *ai);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_NETDB_H_ */
