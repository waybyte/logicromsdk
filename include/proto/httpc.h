/*
 * httpc.h
 *
 */

#ifndef INC_HTTPC_H_
#define INC_HTTPC_H_

#include <sys/time.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Default HTTP client
 */
#define HTTP_CLIENT_DEFAULT	0

/**
 * HTTP supported MIME types
 */
enum http_mimetype_e {
	HTTP_MIME_TYPE_JPEG,   /**< For MIME type image/jpeg */
	HTTP_MIME_TYPE_PNG,    /**< For MIME type image/png */
	HTTP_MIME_TYPE_JSON,   /**< For MIME type application/json */
	HTTP_MIME_TYPE_CSV,    /**< For MIME type text/csv */
	HTTP_MIME_TYPE_TXT,    /**< For MIME type text/plain */
	HTTP_MIME_TYPE_BINARY, /**< For MIME type application/octet-stream */
	HTTP_MIME_TYPE_AMR,    /**< For MIME type audio/amr */
	HTTP_MIME_TYPE_AAC,    /**< For MIME type audio/aac */
	HTTP_MIME_TYPE_WAV,    /**< For MIME type audio/wav */
	HTTP_MIME_TYPE_MPEG,   /**< For MIME type audio/mpeg */
	HTTP_MIME_TYPE_FORM,   /**< For MIME type application/x-www-form-urlencoded */
	HTTP_MIME_TYPE_CUSTOM, /**< For user defined MIME type, must be supplied via custom header argument */
};

/**
 * HTTP Upload status
 */
enum httpup_status_e {
	HTTPUP_STATUS_FAIL,    /**< Upload failed */
	HTTPUP_STATUS_SUCCESS, /**< File uploaded success */
	HTTPUP_STATUS_RECVDATA,/**< File upload response data */
	HTTPUP_SERVER_ERR,     /**< Upload server error */
};

/**
 * HTTP File Upload information structure
 */
struct http_filemeta_t {
	const char *filename; /**< File name (63 char max) to be uploaded with */
	const char *filepath; /**< Complete file path on storage media (255 max) */
	time_t timestamp;     /**< UNIX timestamp to send to server */
	const char *info;     /**< Other supplementary Info e.g. location info etc, This information is sent to server with HTTP form key "info" (127 max) */
	uint8_t mime_type;    /**< MIME type to upload @ref http_mimetype_e for more information */
	const char *mime;     /**< File mime type when mime_type is set to @ref HTTP_MIME_TYPE_CUSTOM, e.g. "text/csv", NULL otherwise */
};

/**
 * HTTP download finished callback
 * @param dl_size		Download size
 * @param reserved		reserved
 * @param error			Error code if any
 */
typedef void (*http_download_cb)(unsigned int dl_size, unsigned int reserved, int error);

/**
 * HTTP Client request argument
 */
struct httparg_t {
	const char *url;					/**< Client URL */
	const char *headers;				/**< Custom headers, can be NULL. if used then header must end with CRLF (\\r\\n) */
	struct ssl_certs_t *certs;			/**< SSL Client certificate */
	const void *submit_data;			/**< Data to send as request body */
	uint16_t submit_len;				/**< Length of data to send */
	uint8_t mime;						/**< MIME type @ref http_mimetype_e */
	uint8_t recv_headers;				/**< if TRUE, HTTP response headers are also stored in response buffer */
	char *resp_buffer;					/**< Pointer to response buffer */
	uint16_t buflen;					/**< Length of response buffer */
	uint16_t timeout;					/**< Timeout in seconds for Read/Write in HTTP and READ in HTTPS, 0 for default 45 sec */
};

/**
 * HTTP Client upload argument
 */
struct httpupload_t {
	const char *url;					/**< Client URL */
	const char *headers;				/**< Custom headers, can be NULL. if used then header must end with CRLF (\\r\\n) */
	const struct http_filemeta_t *meta;	/**< Upload file information @ref http_filemeta_t */
	const struct ssl_certs_t *certs;	/**< SSL Client certificates */
	int recv_headers;					/**< if TRUE, HTTP response headers are also stored in response buffer */
	char *resp_buffer;					/**< Pointer to response buffer */
	uint16_t buflen;					/**< Length of response buffer */
	uint16_t timeout;					/**< Timeout in seconds for Read/Write in HTTP and READ in HTTPS, 0 for default 45 sec */
};

/**
 * HTTP Client download argument
 * 
 */
struct httpdownload_t {
	const char *url;					/**< Client URL */
	const char *headers;				/**< Custom headers, can be NULL. if used then header must end with CRLF (\\r\\n) */
	const char *filepath;				/**< Complete file path on storage media (255 max) */
	const struct ssl_certs_t *certs;	/**< SSL Client certificates */
	http_download_cb callback;			/**< Callback function called after download is finished see @ref http_download_cb */
	uint16_t timeout;					/**< Timeout in seconds for Read/Write in HTTP and READ in HTTPS, 0 for default 45 sec */
};

/**
 * Open a new client
 * @return	On success, returns handle to http client, negative value on error
 */
int httpc_client_open(void);

/**
 * Close a client
 * @param client		[in] Client handle
 * @return				0 on success, negative value on error
 */
int httpc_client_close(int client);

/**
 * Perform HTTP Request
 * @param client		[in] Client handle
 * @param method		[in] HTTP Method e.g. "GET", "POST", "PUT" etc.
 * @param arg			[in] HTTP client argument @ref httparg_t
 * @return				0 on success, If server response is not 2xx then server error code is returned, if any operation issue negative error code will be returned
 */
int httpc_submit(int client, const char *method, struct httparg_t *arg);

/**
 * HTTP file upload. This function will perform a POST with "multipart/form-data" mime on the provided URL. Its a special case of httpc_submit()
 * @param client		[in] Client handle
 * @param arg			[in] HTTP Upload request information struction @ref httpupload_t
 * @return				0 on success, If server response is not 2xx then server error code is returned, if any operation issue negative error code will be returned
 */
int httpc_upload(int client, struct httpupload_t *arg);

/**
 * HTTP file download to local storage
 * @param client		[in] Client handle
 * @param arg			[in] HTTP download request information struction @ref httpdownload_t
 * @return				0 on success, If server response is not 2xx then server error code is returned, if any operation issue negative error code will be returned
 */
int httpc_download(int client, struct httpdownload_t *arg);

/**
 * Enable or disable HTTP client keep-alive function.
 * Keep-alive is enabled by default. If server returns a "connection: close" response then socket will be closed after execution
 * @param client		[in] Client handle
 * @param enable		[in] TRUE or FALSE to enable or disable respectively.
 * @return				0 on success, negative value on error
 */
int httpclient_set_keepalive(int client, int enable);

/**
 * Get current HTTP client keep-alive configuration
 * @param client		[in] Client handle
 * @return				On success, configuration value is returned, negative value on error
 */
int httpclient_get_keepalive(int client);

/**
 * HTTP URL Encode data. Please make sure output buffer is enough to store encoded data
 * @param in_buf	[in] Data to encode
 * @param enc		[out] Buffer to store encoded Data
 * @return			0 on success
 */
int urlencode(const unsigned char *in_buf, char *enc);

/**
 * HTTP URL Decode data. Please make sure output buffer is enough to store decoded data
 * @param in_buf	[in] Input buffer containing encoded data
 * @param dec		[out] Buffere to store decoded data
 * @return			On success length of data stored in output buffer, negative value on error
 */
int urldecode(const char *in_buf, char *dec);

#ifdef __cplusplus
}
#endif

#endif /* INC_HTTPC_H_ */
