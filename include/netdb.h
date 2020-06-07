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

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_NETDB_H_ */
