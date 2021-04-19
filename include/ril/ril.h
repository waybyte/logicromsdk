/**
 * ril.h
 */

#ifndef __RIL_H__
#define __RIL_H__

#ifndef _DOXYGEN_
#ifndef FALSE
#define FALSE    0
#endif

#ifndef TRUE
#define TRUE     1
#endif

#ifndef NULL
#define NULL    ((void *) 0)
#endif

#define RIL_MAX_URC_PREFIX_LEN		50	/**< Maximum allowed URC keyword length */
#define PHONE_NUMBER_MAX_LEN		41	/**< Maximum phone number length */

typedef unsigned char       u8;
typedef signed   char       s8;
typedef unsigned short      u16;
typedef          short      s16;
typedef unsigned int        u32;
typedef          int        s32;
typedef unsigned long long  u64;
typedef          long long  s64;
typedef unsigned int        ticks;
#endif

/**
 * System Initialization status
 */
enum sysinitstate_e {
	SYS_STATE_START = 0,/**< System started */
	SYS_STATE_ATOK  = 1,/**< System ready for AT commands */
	SYS_STATE_PHBOK = 2,/**< Device is ready to make/receive calls */
	SYS_STATE_SMSOK = 3 /**< SIM card is ready for SMS */
};

/**
 * Definition for SIM Card State
 */
enum simstate_e {
	SIM_STAT_NOT_INSERTED = 0,/**< SIM card not inserted */
	SIM_STAT_READY,           /**< SIM card ready, no further action required */
	SIM_STAT_PIN_REQ,         /**< ME waiting for SIM PIN */
	SIM_STAT_PUK_REQ,         /**< ME waiting for SIM PUK */
	SIM_STAT_PH_PIN_REQ,      /**< ME waiting for Phone to SIM card (anti-theft) */
	SIM_STAT_PH_PUK_REQ,      /**< ME waiting for SIM PUK (anti-theft) */
	SIM_STAT_PIN2_REQ,        /**< SIM PIN2 request (2, e.g. it is possible to edit the FDN book only if preceding command was acknowledged with +CME ERROR:17) */
	SIM_STAT_PUK2_REQ,        /**< SIM PUK2 request (Possible only if preceding command was acknowledged with error +CME ERROR: 18) */
	SIM_STAT_BUSY,            /**< SIM card busy */
	SIM_STAT_NOT_READY,       /**< SIM card not ready */
	SIM_STAT_UNSPECIFIED      /**< Unknown error */
};

/**
 * Network status
 */
enum networkstate_e {
	NW_STAT_NOT_REGISTERED = 0, /**< Not register to network */
	NW_STAT_REGISTERED,			/**< The normal network state */
	NW_STAT_SEARCHING,			/**< Searching network */
	NW_STAT_REG_DENIED,			/**< The register request is denied */
	NW_STAT_UNKNOWN,			/**< status unknown */
	NW_STAT_REGISTERED_ROAMING	/**< Registered and Roaming state */
};

/**
 * Phone functionality state
 */
enum cfunstate_e {
	CFUN_STATE_0 = 0,/**< Minimal functionality */
	CFUN_STATE_1 = 1,/**< Full functionality */
	CFUN_STATE_4 = 4 /**< Disable phone from both transmit ting and receiv ing RF signals */
};

/**
 * Call status
 */
enum callstatus_e {
	CALL_STATE_ERROR = -1, /**< Error */
	CALL_STATE_OK = 0,     /**< Status OK */
	CALL_STATE_BUSY,       /**< Response "BUSY" */
	CALL_STATE_NO_ANSWER,  /**< Response "NO_ANSWER" */
	CALL_STATE_NO_CARRIER, /**< Response "NO_CARRIER" */
	CALL_STATE_NO_DIALTONE,/**< Response "NO_DIALTONE" */
	CALL_STATE_END         /**< CALL_STATE_END */
};

/**
 * Voltage Indication Type
 */
enum vbattind_e {
	VBATT_UNDER_WRN = 0,/**< Warning: Under voltage */
	VBATT_UNDER_PDN,    /**< Warning: Under voltage power-down */
	VBATT_OVER_WRN,     /**< Warning: Over voltage */
	VBATT_OVER_PDN      /**< Warning: Over voltage power-down */
};

/**
 * URC Codes
 */
enum sysurc_e {
	URC_SYS_BEGIN = 0,
	URC_SYS_INIT_STATE_IND,     /**< Indication for module initialization state during boot stage, parameter value as @ref sysinitstate_e */
	URC_SIM_CARD_STATE_IND,     /**< Indication for SIM card state (state change), parameter value as @ref simstate_e */
	URC_GSM_NW_STATE_IND,       /**< Indication for GSM network state (state change), parameter value as @ref networkstate_e */
	URC_EGPRS_NW_STATE_IND = 3,	/**< Indication for EPS Network registration status, parameter value as @ref networkstate_e */
	URC_GPRS_NW_STATE_IND,      /**< Indication for GPRS network state (state change), parameter value as @ref networkstate_e */
	URC_CFUN_STATE_IND,         /**< Indication for CFUN state, with parameters as one of @ref cfunstate_e */
	URC_COMING_CALL_IND,        /**< Indication for coming call with parameter as @ref callinfo_t */
	URC_CALL_STATE_IND,         /**< Indication for call state (state change), parameter value as @ref callstatus_e */
	URC_NEW_SMS_IND,            /**< Indication for new short message, parameter value as index of incoming SMS */
	URC_MODULE_VOLTAGE_IND,     /**< Indication for abnormal voltage of module supply power, parameter value as @ref vbattind_e */
	URC_ALARM_RING_IND,		    /**< Indication for clock alarm. */
	URC_STKPCI_RSP_IND,			/**< Indication for un-handled STKPCI responses, Only when QSTK is enabled, Parameter value is incoming +STKPCI response as null terminated string */
	URC_RRC_STATUS_IND,			/**< 4GLTE & NBIoT RRC Status update */
	URC_SYS_END = 100,
	/*
	 * System URC definition end
	 */
	URC_END						/**< Unhandled URC response */
};

/**
 * Return code for AT command response process callback function
 * If callback function returns \a RIL_ATRSP_CONTINUE, ril_send_atcommand will continue to block
 * and process incoming response until callback function returns a success or fail response.
 */
enum ril_resp_rc {
	RIL_ATRSP_FAILED   =  -1,/**< AT command response processing failed */
	RIL_ATRSP_SUCCESS  =   0,/**< AT command response processing success */
	RIL_ATRSP_CONTINUE =   1,/**< Continue processing incoming response of AT command */
};

/**
 * RIL Return code
 */
enum ril_rc_e {
	RIL_AT_SUCCESS           =  0,/**< AT Command executed successfully */
	RIL_AT_FAILED            = -1,/**< AT Command execution failed */
	RIL_AT_TIMEOUT           = -2,/**< AT command sent but response timeout */
	RIL_AT_BUSY              = -3,/**< RIL is busy */
	RIL_AT_INVALID_PARAM     = -4,/**< Invalid parameter */
	RIL_AT_UNINITIALIZED     = -5,/**< RIL is not initialized */
};

/**
 * Incoming call phone info
 */
struct callinfo_t {
	s32 type; /**< Type of address with following possible values.\n
				   129: Unknown type (ISDN format number)\n
				   145: International number type (ISDN format) */
	char phoneNumber[PHONE_NUMBER_MAX_LEN]; /**< Phone number as null terminated string */
};

/**
 * URC handler function type
 * @param strURC		Incoming URC line
 * @param reserved		reserved (unused)
 */
typedef void (*urc_handler_f)(const char *strURC, void *reserved);

/**
 * AT command response processing function
 * @param line			Incoming response line
 * @param len			Length of response string
 * @param arg			User argument passed via @ref ril_send_atcommand
 * @return				RIL response return code @ref ril_resp_rc
 */
typedef s32 (*atrsp_callback_f)(char* line, u32 len, void* arg);

/**
 * RIL receive core data callback function
 * @param ptrData		Incoming data from RIL core
 * @param dataLen		Length of incoming data
 * @param reserved		Reserved (unused)
 */
typedef void (*ril_recvcb_f)(u8* ptrData, u32 dataLen, void* reserved);

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Callback variable for user RIL processing function. This variable can be assigned when processing function
 * expects unsolicited data from RIL core.
 */
extern ril_recvcb_f cb_rcvCoreData;

/**
 * Execute and AT command.
 * This function implements sending AT command with the result
 * being returned synchronously. The response of the AT command
 * will be reported to the callback function
 * @param cmd			[in] AT command string
 * @param cb			[in] processing callback function @ref atrsp_callback_f
 * @param arg			[in] User argument passed to callback function
 * @param timeout		[in] Timeout for command execution
 * @param wait			[in] Wait for RIL to be available (TRUE) or not (FALSE). If wait is false, function may return with @ref RIL_AT_BUSY
 * @return				RIL return code @ref ril_rc_e
 */
int ril_send_atcommand(const char *cmd, atrsp_callback_f cb, void *arg, unsigned int timeout, int wait);

/**
 * Send data to RIL core
 * @param data			[in] Pointer to data to be sent
 * @param len			[in] Length of data
 * @return				On success, this function returns actual length of data written, negative code on error
 */
int ril_write_data(const void *data, int len);

/**
 * Attach URC to RIL core
 * @param keyword		[in] URC Keyword
 * @param callback		[in] URC handler function
 * @return				0 on success, negative value on error
 */
int ril_urc_attach(const char *keyword, urc_handler_f callback);

/**
 * Detach URC from RIL core
 * @param keyword		[in] URC keyword
 * @return				0 on success, negative value on error
 */
int ril_urc_detach(const char *keyword);

/**
 * Get exclusive access to Radio interface layer. This lock is only an advisory lock for RIL.
 * @note ril_lock() and ril_unlock() should be called from same task
 * @param wait			[in] 1 to wait for RIL to be available, 0 otherwise
 * @return				0 on success, -EWOULDBLOCK on error or when lock is unavailable
 */
int ril_lock(int wait);

/**
 * Unlock RIL layer
 * @note ril_lock() and ril_unlock() should be called from same task
 */
void ril_unlock(void);

#ifdef __cplusplus
}
#endif

#endif  /* __RIL_H__ */
