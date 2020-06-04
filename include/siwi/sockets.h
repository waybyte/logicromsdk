/*
 * sockets.h
 *
 */

#ifndef INCLUDE_SIWI_SOCKETS_H_
#define INCLUDE_SIWI_SOCKETS_H_

#define SOC_WRITE_TO_DEFAULT	45

/**
 * Socket Type
 */
enum sock_type_e {
	SOCK_TYPE_TCP,/**< TCP socket */
	SOCK_TYPE_UDP /**< UDP Datagram socket */
};

/**
 * Socket status
 */
enum sock_status_e {
	SOCK_STA_NOGPRS,      /**< No GPRS available */
	SOCK_STA_CONNECTED,   /**< Socket is connected */
	SOCK_STA_DISCONNECTED,/**< Socket is disconnected */
};

/**
 * Socket status callback events
 */
enum sock_events_e {
	SOCK_EV_CONNECTED = 1,/**< Socket connect event. This event will also come in case of UDP when socket is ready. */
	SOCK_EV_DISCONNECTED, /**< Socket disconnect event. This event will also come in case of UDP when socket is not ready to send or receive after a network failure */
	SOCK_EV_RELEASED,     /**< Socket is freed. */
	SOCK_EV_CONN_FAILED,  /**< TCP connection to server failed. */
	SOCK_EV_WRITE_FAILED, /**< TCP socket write failed. Either write timeout has occurred or network error. */
	SOCK_EV_READ_FAILED,  /**< TCP socket read failed. */
	SOCK_EV_GPRS_FAILED,  /**< GPRS bearer failed. */
};

/**
 * SSL version
 */
enum ssl_ver_e {
	SSL_VER_DEFAULT,              /**< Default SSL version (TLS 1.2) */
	TLS_VER_1V2 = SSL_VER_DEFAULT,/**< TLS v1.2 */
	TLS_VER_1V1,                  /**< TLS v1.1 */
	TLS_VER_1V0,                  /**< TLS v1.0 */
	SSL_VER_3V0,                  /**< SSL v3 */
};

/**
 * SSL certificate input type
 */
enum ssl_type_e {
	SSL_TYPE_BUFFER,/**< certificate provided as a buffer */
	SSL_TYPE_FILE   /**< certificate provided as a filename */
};

/**
 * Socket callback structure
 */
struct socket_callback_t {
	/**
	 * Socket status callback
	 * @param sockid	Socket ID
	 * @param event		Socket event see @ref sock_events_e
	 * @param error		Error code in case of error events
	 * @return			Always return 0, return value is unused
	 */
	int (*status_callback)(int sockid, int event, int error);
	/**
	 * Socket data receive callback
	 * @param sockid	Socket ID
	 * @param buf		buffer containing receive data
	 * @param len		Length of data
	 * @return			Always return 0, return value is unused
	 */
	int (*recv_callback)(int sockid, const void *buf, int len);
	/**
	 * Socket transmit callback
	 * @param sockid	Socket ID
	 * @param result	0 if data sent successfully, -1 if failed
	 * @param buf		buffer containing data which was sent
	 * @param len		length of data
	 * @param arg		user argument passed during send
	 * @return			Always return 0, return value is unused
	 */
	int (*xmit_callback)(int sockid, int result, const void *buf, int len, void *arg);
};

/**
 * Socket configuration option
 */
struct sockopt_t {
	char server_ip[100];	/**< IP/Domain name of server */
	int port;				/**< Server port to connect */
	const struct socket_callback_t *handlers;	/**< socket callback functions see @ref socket_callback_t */
	unsigned char autoconnect;		/**< Auto-connect server on disconnection. 1 for auto-connect, When 0 socket_open must be called to reconnect to server */
	void *arg;				/**< user data to associate with socket */
};

/**
 * SSL Socket configuration
 */
struct ssl_sockopt_t {
	char server_ip[100];	/**< IP/Domain name of server */
	int port;				/**< SSL server port */
	int (*status_callback)(int sockid, int status);	/**< SSL socket status callback */
	void *arg;				/**< user data to associate with socket */
};

/**
 * SSL client certificates
 */
struct ssl_certs_t {
	int cert_type;			/**< Input type see @ref ssl_type_e */
	const void *cert;		/**< filename/buffer containing certificate (Only PEM format supported) */
	int cert_len;			/**< Length of certificate in case buffer is provided */
	int pkey_type;			/**< Input type see @ref ssl_type_e */
	const void *privatekey;	/**< filename/buffer containing private key (Only PEM format supported) */
	int privatekey_len;		/**< Length of private key in case buffer is provided */
};

#ifdef __cpluplus
extern "C" {
#endif

/* Normal Socket */
/**
 * Request a socket
 * @param type		[in] Socket type see @ref sock_type_e
 * @return			Socket ID on success, negative value on error
 */
int socket_request(int type);

/**
 * Set socket options
 * @param id		[in] Socket ID
 * @param opts		[in] socket option sturcture see @ref sockopt_t
 * @return			0 on success, negative value on error
 */
int socket_setopt(int id, struct sockopt_t *opts);

/**
 * Open a socket. socket options must be configured before calling this function.
 * This is a non blocking function, connection status will be returned via status callback
 * @param id		[in] Socket ID
 * @return			0 on success, negative value on error
 */
int socket_open(int id);

/**
 * Close a socket. This is a non-blocking function, status will be returned via status callback
 * @param id		[in] Socket ID
 * @return			0 on success, negative value on error
 */
int socket_close(int id);

/**
 * Send data
 * @param id		[in] Socket ID
 * @param buf		[in] Data to send
 * @param len		[in] Length of data
 * @param timeout	[in] Timeout in seconds, 0 for default timeout (45s)
 * @param arg		[in] User data argument, This argument will be passed to transmit callback function
 * @return			0 on success, negative value on error
 */
int socket_send(int id, const void *buf, int len, int timeout, void *arg);

/**
 * Get socket status
 * @param id		[in] Socket ID
 * @return			returns @ref sock_status_e, on error negative value is returned
 */
int socket_getstatus(int id);

/**
 * Set user data associated with socket
 * @param id		[in] Socket ID
 * @param arg		[in] User data pointer
 * @return			0 on success, negative value on error
 */
int socket_setuserdata(int id, void *arg);

/**
 * Get user data associated with socket
 * @param id		[in] Socket ID
 * @return			On success returns user data associated
 */
void *socket_getuserdata(int id);

/**
 * Release socket. If socket is not closed it will be closed first.
 * @param id		[in] Socket ID
 * @return			0 on success, negative value on error
 */
int socket_free(int id);

/* SSL Sockets */
/**
 * Request an SSL socket.
 * @param ssl_version	[in] SSL version @ref ssl_ver_e
 * @param certs			[in] SSL client certificate and private key. NULL if not used
 * @return				On success SSL socket ID is returned, On error negative value is returned
 */
int ssl_socket_request(int ssl_version, struct ssl_certs_t *certs);

/**
 * Configure SSL socket
 * @param id			[in] Socket ID
 * @param opts			[in] socket configuration see @ref ssl_sockopt_t
 * @return				0 on success, negative value on error
 */
int ssl_socket_setopt(int id, struct ssl_sockopt_t *opts);

/**
 * Open SSL socket connection
 * @param id			[in] Socket ID
 * @return				0 on success, negative value on error
 */
int ssl_socket_open(int id);

/**
 * Close SSL socket
 * @param id			[in] Socket ID
 * @return				0 on success, negative value on error
 */
int ssl_socket_close(int id);

/**
 * Send data on SSL socket. This is a blocking call
 * @param id			[in] Socket ID
 * @param buf			[in] Data to send
 * @param len			[in] Length of data
 * @param timeout		[in] Timeout in seconds, 0 for default (45s)
 * @return				returns number of bytes sent successfully, on error negative value is returned
 */
int ssl_socket_send(int id, const void *buf, int len, int timeout);

/**
 * Read data from SSL socket. This is a blocking call
 * @param id			[in] Socket ID
 * @param buf			[out] Buffer pointer to store data
 * @param len			[in] Length data to read
 * @param timeout		[in] Timeout in seconds, If 0 function will block until data is received or interrupted by error
 * @return				returns number of bytes read, on error negative value is returned
 */
int ssl_socket_read(int id, void *buf, int len, int timeout);

/**
 * Get socket status
 * @param id			[in] Socket ID
 * @return				returns @ref sock_status_e, on error negative value is returned
 */
int ssl_socket_getstatus(int id);

/**
 * Get last error code
 * @param id			[in] Socket iD
 * @return				error code
 */
int ssl_socket_geterror(int id);

/**
 * Get user data associated with socket see @ref ssl_sockopt_t
 * @param id			[in] Socket ID
 * @return				user data pointer
 */
void *ssl_socket_getuserdata(int id);

/**
 * Release SSL socket
 * @param id			[in] Socket ID
 * @return				0 on success, negative value on error
 */
int ssl_socket_free(int id);

#ifdef __cpluplus
}
#endif

#endif /* INCLUDE_SIWI_SOCKETS_H_ */
