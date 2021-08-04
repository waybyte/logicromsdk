/**
 * @file modem.h
 * Modem operation APIs
 */

#ifndef INCLUDE_MODEM_H
#define INCLUDE_MODEM_H

#include <stdint.h>
#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Maximum recvieve SMS size
 */
#define SMS_RECV_MAX_SZ 160
#define PH_NUM_MAX_SZ	21

/**
 * Modem error code
 */
enum mderror_e
{
	MD_SUCCESS = 0,			   /**< success */
	MD_ERR_FAILED = -1,		   /**< faiure, unknown cause */
	MD_ERR_TIMEOUT = -2,	   /**< operation timeout */
	MD_ERR_BUSY = -3,		   /**< modem busy */
	MD_ERR_INVALID_PARAM = -4, /**< Invalid parameter */
	MD_ERR_NOMEM = -5,		   /**< No memory available */
	MD_ERR_NOTALLOWED = -6,	   /**< Operation not allowed */
};

/**
 * SMS Status
 */
enum sms_status_e
{
	SMS_STATUS_UNREAD,
	SMS_STATUS_READ,
	SMS_STATUS_UNSENT,
	SMS_STATUS_SENT,
	SMS_STATUS_ALL,
};

/**
 * SMS delete mode
 */
enum sms_delmode_e
{
	SMS_DEL_INDEXED = 0,		  /**< Single message by index */
	SMS_DEL_READ = 1,			  /**< Already read messages */
	SMS_DEL_READ_SENT = 2,		  /**< Read and sent messages */
	SMS_DEL_READ_SENT_UNSENT = 3, /**< Read ,sent and unsent messages */
	SMS_DEL_ALL = 4,			  /**< All messages in current storage */
};

/**
 * SMS Information structure
 */
struct md_smsinfo_t
{
	int status;	  /**< SMS type GSM 03.40 TP-Message-Type-Indicator (@ref sms_status_e) */
	struct tm ts; /**< receive time in UTC */
	char oa_num[PH_NUM_MAX_SZ + 1]; /**< Sender's number */
	char sca_num[PH_NUM_MAX_SZ + 1];	/**< Sender's SMS service center number */
	char text[SMS_RECV_MAX_SZ + 1]; /**< SMS Text */
};

/**
 * Cell information structure
 */
struct __cellinfo_t
{
	uint16_t mcc;	 /**< Mobile Country code */
	uint16_t mnc;	 /**< Mobile Network code */
	uint32_t lac;	 /**< Location Area code */
	uint32_t cellid; /**< Cell ID */
	uint16_t bcch;	 /**< Absolute Radio Frequency Channel Number of Broadcast Control Channel BCCH */
	uint16_t bsic;	 /**< Base station identity code */
	int dbm;		 /**< Receive signal level in dBm unit */
	int16_t c1;		 /**< C1 value */
	int16_t c2;		 /** C2 value */
};

/**
 * Serving and Neighboring cell information
 */
struct md_cellinfo_t
{
	struct __cellinfo_t cell;	  /**< Serving Cell information */
	int ncell_count;			  /**< Number of valid neighboring cell available in ncell */
	struct __cellinfo_t ncell[6]; /**< Neighboring cell information */
};

/**
 * SMS Send API
 * 
 * @param num		[in] Sender's number
 * @param sms_text	[in] message to send
 * @param ref		[out] GSM 03.40 TP-Message-Reference
 * @return 			0 on success, error otherwise (@ref mderror_e)
 */
int md_sms_send(const char *num, const char *sms_text, unsigned int *ref);

/**
 * SMS Read
 * 
 * @param index		[in] Index in the storage to read from
 * @param smsinfo	[out] SMS Information structure returned after successful read
 * @return 			0 on success, error otherwise (@ref mderror_e)
 */
int md_sms_read(unsigned index, struct md_smsinfo_t *smsinfo);

/**
 * Delete SMS
 * 
 * @param index		[in] Index in the storage to read from
 * @param mode		[in] SMS delete mode (@ref sms_delmode_e)
 * @return 			0 on success, error otherwise (@ref mderror_e)
 */
int md_sms_delete(int index, int mode);

/**
 * Set modem CFUN state
 * 
 * @param cfun		[in] CFUN value to set
 * @param rst		[in] reset after setting cfun value
 * @return 			0 on success, error otherwise (@ref mderror_e)
 */
int md_cfun_set(int cfun, int rst);

/**
 * Get modem CFUN state
 * @return 			CFUN status on success, negative value as error (@ref mderror_e)
 */
int md_cfun_get(void);

/**
 * Initiate a call
 * This is a non-blocking call, If operation is success
 * Call status will be retured as URC response.
 * 
 * @param phonenum	[in] Number to call
 * @return 			0 on success, error otherwise (@ref mderror_e)
 */
int md_call_dial(const char *phonenum);

/**
 * Answer a call
 * 
 * @return 			0 on success, error otherwise (@ref mderror_e)
 */
int md_call_answer(void);

/**
 * End a call
 * 
 * @return 			0 on success, error otherwise (@ref mderror_e)
 */
int md_call_hangup(void);

/**
 * Get IMEI
 * 
 * @param imei_buf	[out] Buffer to store IMEI (optional, can be NULL)
 * @param len		[in] Size of @a imei_buf
 * @return			Buffer containing IMEI
 */
const char *md_get_imei(char *imei_buf, int len);

/**
 * Get IMSI
 * 
 * @param imsi_buf	[out] Buffer to store IMSI (min  16, optional, can be NULL)
 * @param len		[in] Size of @a imsi_buf
 * @return			Buffer containing IMSI
 */
const char *md_get_imsi(char *imsi_buf, int len);

/**
 * Get CCID
 * 
 * @param ccid_buf	[out] Buffer to store CCID (min 20, optional, can be NULL)
 * @param len		[in] Size of @a ccid_buf
 * @return			Buffer containing IMSI
 */
const char *md_get_ccid(char *ccid_buf, int len);

/**
 * Get Current operator name
 * 
 * @param opbuf		[out] Buffer to store name (optional, can be NULL)
 * @param len		[in] Size of @a opbuf
 * @return			Buffer containing operator name
 */
const char *md_get_operatorname(char *opbuf, int len);

/**
 * Get service provider name from SIM
 * 
 * @param spn_buf	[out] Buffer to store SPN (optional, can be NULL)
 * @param len		[in] Size of @a spn_buf
 * @return			Buffer containing SPN
 */
const char *md_get_simprovider(char *spn_buf, int len);

/**
 * Get MSISDN (Own number) from SIM
 * This API may not work and is SIM dependent
 * 
 * @param num		[out] Buffer to store MSISDN (optional, can be NULL)
 * @param len		[in] Length of @a num
 * @return			Buffer containing MSISDN (own number)
 */
const char *md_get_sim_phonenum(char *num, int len);

/**
 * Get serving and neighboring cell information
 * 
 * @param info		[out] Information structure to be filled
 * @return 			0 on success, error otherwise (@ref mderror_e)
 */
int md_get_cellinfo(struct md_cellinfo_t *info);

/**
 * Get battery status
 * 
 * @param capacity	[out] Battery capacity in percentage (0 - 100%)
 * @param voltage	[out] Battery voltage in millivolts
 * @return 			0 on success, error otherwise (@ref mderror_e)
 */
int md_getbatt_status(uint32_t *capacity, uint32_t *voltage);

/**
 * Store in NVM memory
 * @note MT2503/MT6261 only support max 50 byte NVM storage per index
 * 
 * @param index		[in] NVM index (1 - 8)
 * @param data		[in] data to store
 * @param len		[in] Length of @a data
 * @return 			0 on success, error otherwise (@ref mderror_e)
 */
int md_nvm_store(int index, const void *data, int len);

/**
 * Read from NVM memory
 * @note MT2503/MT6261 only support max 50 byte NVM storage per index
 * 
 * @param index		[in] NVM index (1 - 8)
 * @param data		[out] Buffer to store read data
 * @param len		[in] Length of buffer @a data
 * @return 			success length of actual data is returned, error otherwise (@ref mderror_e)
 */
int md_nvm_read(int index, void *data, int len);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_MODEM_H */
