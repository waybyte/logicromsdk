/*
 * network.h
 *
 */

#ifndef INCLUDE_NETWORK_H_
#define INCLUDE_NETWORK_H_

/**
 * Network status
 */
enum _net_state {
	NET_STATE_INVALID,       /**< Network status unknown/invalid */
	NET_STATE_NO_NETWORK,    /**< Network status no signal */
	NET_STATE_GSM,           /**< Network status GSM registered */
	NET_STATE_GPRS,          /**< Network status GPRS registered */
	NET_STATE_SOC_CONNECTING,/**< Network status socket connection in progress */
	NET_STATE_SOC_CONNECTED, /**< Network status socket connected */
	NET_STATE_SOC_SENDING    /**< Network status sending data over socket */
};

/**
 * Network parameter structure
 */
struct netparam_t {
	int simstate;		/**< SIM CPIN status @ref Enum_SIMState */
	int creg;			/**< CREG GSM status @ref Enum_NetworkState */
	int cgreg;			/**< CGREG GPRS status @ref Enum_NetworkState */
	int state;			/**< Internal state (for debugging) */
	int atgprs;			/**< Internal state of GPRS (for debugging) */
	unsigned char csq;	/**< Signal strength RSSI value (0:-113dBm or less to 31:-55dBm or more, 99: Not detectable) */
	const char *apn;	/**< Currently used APN as null terminted string */
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get Network parameters
 * @param param		[out] Pointer to parameter structure filled on return see @ref netparam_t
 * @return			always return 0
 */
int network_getparam(struct netparam_t *param);

/**
 * Get network status.
 * If socket descriptor is provided, extended network status will be provided with socket status
 * @param sockfd	[in] Socket descriptor (optional, 0 if not used)
 * @return			network status see @ref _net_state
 */
int network_getstatus(int sockfd);

/**
 * Get APN configuration stored in memory
 * @param apn		[out] Access point name (APN)
 * @param user		[out] APN user (optional, can be null)
 * @param pwd		[out] APN Password (optional, can be null)
 * @return			0 on success, negative value on error
 */
int network_getapn(char *apn, char *user, char *pwd);

/**
 * Configure APN and store in memory. New setting will be applied only after reboot
 * @param apn		[in] Access point name (APN)
 * @param user		[in] APN user (optional, can be null)
 * @param pwd		[in] APN password (optional, can be null)
 * @return			0 on success, negative value on error
 */
int network_setapn(const char *apn, const char *user, const char *pwd);

/**
 * Get DNS servers
 * @param pri		[out] Primary DNS server
 * @param sec		[out] Secondary DNS server
 * @return			0 on success, negative value on error
 */
int network_getdns(char *pri, char *sec);

/**
 * Set DNS servers
 * @param pri		[in] Primary DNS server to set
 * @param sec		[in] Secondary DNS server to set
 * @return			0 on success, negative value on error
 */
int network_setdns(const char *pri, const char *sec);

/**
 * Reset DNS servers to network default
 * @return			0 on success, negative value on error
 */
int network_resetdns(void);

/**
 * Enable/Disable GPRS. GPRS is enabled by default
 * @param enable	[in] 1 to enable, 0 to disable
 * @return			0 on success, negative value on error
 */
int network_gprsenable(int enable);

/**
 * Get GPRS enable/disable status
 * @return			GPRS status
 */
int network_isgprsenable(void);

/**
 * Get currently used APN
 * @return			currently used APN (Do not free the buffer)
 */
const char *network_getcurrapn(void);

/**
 * Get module IMEI
 * @param imei_buf	[out] Buffer to store IMEI (optional, can be null)
 * @param len		[in] length of buffer
 * @return			IMEI buffer. If \a imei_buf is not provided then a Statically allocated buffer is returned, do not free.
 */
const char *get_imei(char *imei_buf, int len);

/**
 * Get IMSI value
 * @param imsi_buf	[out] Buffer to store IMSI (optional, can be null)
 * @param len		[in] length of buffer
 * @return			IMSI buffer. If \a imsi_buf is not provided then a Statically allocated buffer is returned, do not free.
 */
const char *get_imsi(char *imsi_buf, int len);

/**
 * Get SIM ICCID
 * @param ccid_buf	[out] Buffer to store CCID value (optional, can be null)
 * @param len		[in] length of buffer
 * @return			buffer containing ICCID. If \a ccid_buf is not provided then a Statically allocated buffer is returned, do not free.
 */
const char *get_ccid(char *ccid_buf, int len);

/**
 * Get current operator name
 * @param opbuf		[out] Buffer to store operator name (optional, can be null)
 * @param len		[in] length of \a opbuf
 * @return			buffer containing operator name. If \a opbuf is not provided then a Statically allocated buffer is returned, do not free.
 */
const char *get_operatorname(char *opbuf, int len);

/**
 * Get Service Provider Name from SIM card
 * @param spn_buf	[out] Buffer to store SPN (optional, can be null)
 * @param len		[in] length of \a spn_buf
 * @return			Buffer containing SPN. If \a spn_buf is not provided then a Statically allocated buffer is returned, do not free.
 */
const char *get_simprovider(char *spn_buf, int len);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_NETWORK_H_ */
