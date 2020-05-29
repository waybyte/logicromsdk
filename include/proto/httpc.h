/*
 * httpc.h
 *
 */

#ifndef INC_HTTPC_H_
#define INC_HTTPC_H_

/**
 * Indicates data is a header
 */
#define HTTP_RECV_HEADER	2000

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
 * HTTP supported methods
 *
 * Basic support for accessing REST API
 */
enum httpc_method_e {
	HTTP_METHOD_GET,  /**< HTTP Method GET */
	HTTP_METHOD_POST, /**< HTTP Method POST */
	HTTP_METHOD_PUT,  /**< HTTP Method PUT */
	HTTP_METHOD_DELETE/**< HTTP Method DELETE */
};

/**
 * HTTP File Upload information structure
 */
struct http_filemeta_t {
	char *filename; /**< File name (63 char max) to be uploaded with */
	char *filepath; /**< Complete file path on storage media (255 max) */
	long timestamp; /**< File creation UNIX timestamp */
	char *info; /**< Other supplementary Info e.g. location info etc, This information is sent to server with HTTP form key "info" (127 max) */
	int filetype; /**< MIME type to upload http_filetype_e for more information */
};

/**
 * HTTP download finished callback
 * @param dl_size		Download size
 * @param reserved		reserved
 * @param error			Error code if any
 */
typedef void (*http_download_cb)(unsigned int dl_size, unsigned int reserved, int error);

/**
 * HTTP Client get argument
 */
struct _httpc_get_t {
	const char *url;				/**< Client URL */
	const char *headers;			/**< Custom headers */
	struct ssl_certs_t *certs;		/**< SSL client certificates */
	int recv_headers;				/**< if TRUE, HTTP response headers are also stored in response buffer */
	char *resp_buffer;				/**< Pointer to response buffer */
	int buflen;						/**< Length of response buffer */
};

/**
 * HTTP Client post argument
 */
struct _httpc_post_t {
	const char *url;					/**< Client URL */
	const char *header;					/**< Custom headers */
	const unsigned char *submit_data;	/**< Post data */
	int submit_len;						/**< Length of post data */
	int mime;							/**< MIME type http_mimetype_e */
	struct ssl_certs_t *certs;			/**< SSL Client certificate */
	int recv_headers;					/**< if TRUE, HTTP response headers are also stored in response buffer */
	char *resp_buffer;					/**< Pointer to response buffer */
	int buflen;							/**< Length of response buffer */
};

/**
 * HTTP Client upload argument
 */
struct _httpc_up_t {
	const char *url;					/**< Client URL */
	const char *header;					/**< Custom headers */
	struct http_filemeta_t *meta;		/**< Upload file information http_filemeta_t */
	struct ssl_certs_t *certs;			/**< SSL Client certificates */
	char *respbuf;						/**< Pointer to response buffer */
	int buflen;							/**< Length of response buffer */
};

/**
 * HTTP Client argument
 */
typedef union httpc_arg_t {
	struct _httpc_get_t get;			/**< HTTP Get _httpc_get_t for httpc_get */
	struct _httpc_post_t post;			/**< HTTP Post _httpc_post_t for httpc_submit */
	struct _httpc_up_t upload;			/**< HTTP Upload _httpc_up_t for httpc_upload */
} httpc_arg;

#ifdef __cpluplus
extern "C" {
#endif

/**
 * Open a client
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
 * Perform HTTP Get
 * @param client		[in] Client handle
 * @param arg			[in] HTTP client argument httpc_arg_t
 * @return				0 on success, If server response is not 2xx then server error code is returned, if any operation issue negative error code will be returned
 */
int httpc_get(int client, httpc_arg *arg);

/**
 * Perform HTTP Post, Put or Delete
 * @param client		[in] Client handle
 * @param method		[in] HTTP Method httpc_method_e
 * @param arg			[in] HTTP client argument httpc_arg_t
 * @return				0 on success, If server response is not 2xx then server error code is returned, if any operation issue negative error code will be returned
 */
int httpc_submit(int client, int method, httpc_arg *arg);

/**
 * HTTP file upload. This function will perform a POST with "multipart/form-data" mime on the provided URL. Its a special case of httpc_submit
 * @param url			[in] URL to post
 * @param meta			[in] File information structure http_filemeta_t
 * @param respbuf		[out] Response data buffer pointer
 * @param buflen		[out] size of response data, and returns actual data stored in response buffer
 * @return				0 on success, If server response is not 2xx then server error code is returned, if any operation issue negative error code will be returned
 */
int httpc_upload(const char *url, struct http_filemeta_t *meta, char *respbuf, int *buflen);

/**
 * HTTP file download to local storage
 * @param url			[in] URL to download
 * @param filename		[in] path to filename where download file will be saved
 * @param httpc_cb		[in] Callback function called after download is finished see http_download_cb
 * @return				0 on success, If server response is not 2xx then server error code is returned, if any operation issue negative error code will be returned
 */
int httpc_download(const char *url, char *filename, http_download_cb httpc_cb);

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

#ifdef __cpluplus
}
#endif

#endif /* INC_HTTPC_H_ */
