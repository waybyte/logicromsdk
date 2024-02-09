/*
 * network.h
 *
 */

#ifndef INCLUDE_NETWORK_H_
#define INCLUDE_NETWORK_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Network state
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
 * @brief Network type
 * 
 */
enum nettype_e {
	NET_TYPE_UNKNOWN,	/**< Unknown network type, applicable to net_gettype() */
	NET_TYPE_AUTO = 0,	/**< Autoselect network type, applicable to net_settype() */
	NET_TYPE_GSM,		/**< Network type 2G/GSM */
	NET_TYPE_LTE,		/**< Network type 4G LTE */
};

/**
 * Network parameter structure
 */
struct netparam_t {
	uint8_t simstate;	/**< SIM CPIN status @ref simstate_e */
	uint8_t creg;		/**< GSM status @ref networkstate_e */
	uint8_t cgreg;		/**< EPS Network (4G/NB-Iot)/GPRS status @ref networkstate_e */
	uint8_t state;		/**< Internal state (for debugging) */
	uint8_t signal; 	/**< Signal level\n
							 For GSM; RSSI Value - 0:-113dBm or less to 31:-55dBm or more,\n
							 For 4G/NB-IoT; RSRP Value - 0:-140dBm or less to 97:-44dBm or more,\n
							 99: Not detectable */
	uint8_t mode;		/**< Network mode @ref nettype_e */
	const char *apn;	/**< Currently used APN as null terminted string */
};

/**
 * Get Network parameters
 * @param param		[out] Pointer to parameter structure filled on return see @ref netparam_t
 * @return			always return 0
 */
int network_getparam(struct netparam_t *param);

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
 * Get network status.
 * If socket descriptor is provided, extended network status will be provided with socket status
 * @param sockfd	[in] Socket descriptor (optional, 0 if not used)
 * @return			network status see @ref _net_state
 */
int network_getstatus(int sockfd);

/**
 * Get status of network, if its ready or not for IP data transmission
 * @deprecated since v1.0.0
 *
 * @return			returns 1 if network ready, 0 otherwise
 */
__attribute__((__deprecated__)) int network_isready(void);

/**
 * Get status of network, if its ready or not for IP data transmission
 *
 * @return			returns 1 if network ready, 0 otherwise
 */
int network_isdataready(void);

/**
 * Reset and restart network
 */
void network_reset(void);

#if !defined(PLATFORM_BC20) || defined(_DOXYGEN_)
/**
 * Enable/Disable GPRS. GPRS is enabled by default
 * @deprecated since v1.0.0
 * @param enable	[in] 1 to enable, 0 to disable
 * @return			0 on success, negative value on error
 */
__attribute__((__deprecated__)) int network_gprsenable(int enable);

/**
 * Enable/Disable data services. Data service is enabled by default
 * @param enable	[in] 1 to enable, 0 to disable
 * @return			0 on success, negative value on error
 */
int network_dataenable(int enable);

/**
 * Get GPRS enable/disable status
 * @deprecated since v1.0.0
 * @return			GPRS status
 */
__attribute__((__deprecated__)) int network_isgprsenable(void);

/**
 * Get Data service enable/disable status
 * @return			service status
 */
int network_isdataenable(void);

/**
 * Get IP address assigned to module
 * @return			IP Address octets
 */
unsigned char *network_getlocalip(void);
#endif

/**
 * Get currently used APN
 * @return			currently used APN
 */
const char *network_getcurrapn(void);

/**
 * Get current network type GSM/LTE
 * 
 * @return network type value @ref nettype_e
 */
uint8_t network_gettype(void);

/**
 * @brief Set current network type
 * 
 * @param type Network type @ref nettype_e
 * @return 0 on success, negative on failure
 */
int network_settype(int type);

/**
 * Setup Network status LED. Attach GPIO line managed by network
 * thread for status LED.
 * 
 * IO Drive Logic: Positive (1 - High, 0 - Low)
 * 
 * LED Timings in milliseconds (On Time/Off Time):
 * 
 * No Sim: 250/3000
 * No Network/Searching: 50/500
 * GSM/GPRS Registered: 50/1000
 * Socket Connecting: 500/500
 * Network Idle: 50/2000
 * Data Sending: 100/100
 * Unknow error: 50/50
 * 
 * @param gpionum	[in] GPIO Number to use
 * @return			0 on success, negative value on error
 */
int network_setup_statusled(int gpionum);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_NETWORK_H_ */
