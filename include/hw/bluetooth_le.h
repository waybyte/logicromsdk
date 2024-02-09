/**
 * @file bluetooth_le.h
 * @brief Bluetooth LE client APIs for modules based on RDA8910 chipset
 * @date 2023-12-15
 * 
 */

#ifndef INC_AUDIO_H_
#define INC_AUDIO_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _DOXYGEN_
#define __BLE_PACKED__
#else
#define __BLE_PACKED__ __attribute__((packed))
#endif

/* BLE UUID lenths */
#define BLE_UUID_LEN_16 2 /**< UUID16 lenth in bytes */
#define BLE_UUID_LEN_32 4 /**< UUID32 lenth in bytes */
#define BLE_UUID_LEN_128 16 /**< UUID128 lenth in bytes */
#define SIZE_OF_BDADDR 6 /**< Size of Dluetooth device address in bytes */

enum ble_addr_type_e {
	BLE_ADDR_TYPE_PUBLIC, /**< Public Device Address */
	BLE_ADDR_TYPE_RANDOM, /**< Random Device Address */
};

/**
 * @brief Scan event list
 * 
 */
enum scan_event_e {
	BLE_CLIENT_SCAN_DONE,
	BLE_CLIENT_SCAN_EVENT,
};

/**
 * @brief BLE Client status callback events
 * 
 */
enum ble_client_event_e {
	BLE_CLIENT_LINK_DISCONNECT,
	BLE_CLIENT_LINK_CONNECTED,
	BLE_CLIENT_SEARCH_SERVICE,
	BLE_CLIENT_SEARCH_SERVICE_COMPLETE,
	BLE_CLIENT_CFG_MTU,
    BLE_CLIENT_READ_EVENT,
    BLE_CLIENT_READ_BLOB_EVENT,
    BLE_CLIENT_READ_MULTI_EVENT,
    BLE_CLIENT_WRITE_EVENT,
    BLE_CLIENT_WRITE_WITH_RESP_EVENT,
    BLE_CLIENT_NOTIFY_EVENT,
    BLE_CLIENT_SVC_REFRESH_COMPLETE,
};

/**
 * @brief BLE device write types
 * 
 */
enum ble_write_type_e {
    BLE_WRITE_TYPE_NO_RESP,
    BLE_WRITE_TYPE_WITH_RESP,
    BLE_WRITE_TYPE_SIGNED,
};

/**
 * @brief BLE connection status error code
 * 
 */
enum ble_conn_status_e {
    BLE_CLIENT_CONN_UNKNOWN = 0,                      /**< Gatt connection unknown */               /* relate to BTA_GATT_CONN_UNKNOWN in bta/bta_gatt_api.h */
    BLE_CLIENT_CONN_L2C_FAILURE = 1,                  /**< General L2cap failure  */                /* relate to BTA_GATT_CONN_L2C_FAILURE in bta/bta_gatt_api.h */
    BLE_CLIENT_CONN_TIMEOUT = 0x08,                   /**< Connection timeout  */                   /* relate to BTA_GATT_CONN_TIMEOUT in bta/bta_gatt_api.h */
    BLE_CLIENT_CONN_TERMINATE_PEER_USER = 0x13,       /**< Connection terminate by peer user  */    /* relate to BTA_GATT_CONN_TERMINATE_PEER_USER in bta/bta_gatt_api.h */
    BLE_CLIENT_CONN_TERMINATE_LOCAL_HOST = 0x16,      /**< Connection terminated by local host */    /* relate to BTA_GATT_CONN_TERMINATE_LOCAL_HOST in bta/bta_gatt_api.h */
    BLE_CLIENT_CONN_FAIL_ESTABLISH = 0x3e,            /**< Connection fail to establish  */         /* relate to BTA_GATT_CONN_FAIL_ESTABLISH in bta/bta_gatt_api.h */
    BLE_CLIENT_CONN_LMP_TIMEOUT = 0x22,               /**< Connection fail for LMP response tout */ /* relate to BTA_GATT_CONN_LMP_TIMEOUT in bta/bta_gatt_api.h */
    BLE_CLIENT_CONN_CONN_CANCEL = 0x0100,             /**< L2CAP connection cancelled  */           /* relate to BTA_GATT_CONN_CONN_CANCEL in bta/bta_gatt_api.h */
    BLE_CLIENT_CONN_NONE = 0x0101                     /**< No connection to cancel  */              /* relate to BTA_GATT_CONN_NONE in bta/bta_gatt_api.h */
};

/**
 * @brief ATT success code and error codes
 */
enum {
    BLE_ATT_OK                     =   0x0,                    /* relate to BTA_GATT_OK in bta/bta_gatt_api.h */
    BLE_ATT_ERR_INVALID_HANDLE         =   0x01,   /* 0x0001 */    /* relate to BTA_GATT_INVALID_HANDLE in bta/bta_gatt_api.h */
    BLE_ATT_ERR_READ_NOT_PERMIT        =   0x02,   /* 0x0002 */    /* relate to BTA_GATT_READ_NOT_PERMIT in bta/bta_gatt_api.h */
    BLE_ATT_ERR_WRITE_NOT_PERMIT       =   0x03,   /* 0x0003 */    /* relate to BTA_GATT_WRITE_NOT_PERMIT in bta/bta_gatt_api.h */
    BLE_ATT_ERR_INVALID_PDU            =   0x04,   /* 0x0004 */    /* relate to BTA_GATT_INVALID_PDU in bta/bta_gatt_api.h */
    BLE_ATT_ERR_INSUF_AUTHENTICATION   =   0x05,   /* 0x0005 */    /* relate to BTA_GATT_INSUF_AUTHENTICATION in bta/bta_gatt_api.h */
    BLE_ATT_ERR_REQ_NOT_SUPPORTED      =   0x06,   /* 0x0006 */    /* relate to BTA_GATT_REQ_NOT_SUPPORTED in bta/bta_gatt_api.h */
    BLE_ATT_ERR_INVALID_OFFSET         =   0x07,   /* 0x0007 */    /* relate to BTA_GATT_INVALID_OFFSET in bta/bta_gatt_api.h */
    BLE_ATT_ERR_INSUF_AUTHORIZATION    =   0x08,   /* 0x0008 */    /* relate to BTA_GATT_INSUF_AUTHORIZATION in bta/bta_gatt_api.h */
    BLE_ATT_ERR_PREPARE_Q_FULL         =   0x09,   /* 0x0009 */    /* relate to BTA_GATT_PREPARE_Q_FULL in bta/bta_gatt_api.h */
    BLE_ATT_ERR_NOT_FOUND              =   0x0a,   /* 0x000a */    /* relate to BTA_GATT_NOT_FOUND in bta/bta_gatt_api.h */
    BLE_ATT_ERR_NOT_LONG               =   0x0b,   /* 0x000b */    /* relate to BTA_GATT_NOT_LONG in bta/bta_gatt_api.h */
    BLE_ATT_ERR_INSUF_KEY_SIZE         =   0x0c,   /* 0x000c */    /* relate to BTA_GATT_INSUF_KEY_SIZE in bta/bta_gatt_api.h */
    BLE_ATT_ERR_INVALID_ATTR_LEN       =   0x0d,   /* 0x000d */    /* relate to BTA_GATT_INVALID_ATTR_LEN in bta/bta_gatt_api.h */
    BLE_ATT_ERR_ERR_UNLIKELY           =   0x0e,   /* 0x000e */    /* relate to BTA_GATT_ERR_UNLIKELY in bta/bta_gatt_api.h */
    BLE_ATT_ERR_INSUF_ENCRYPTION       =   0x0f,   /* 0x000f */    /* relate to BTA_GATT_INSUF_ENCRYPTION in bta/bta_gatt_api.h */
    BLE_ATT_ERR_UNSUPPORT_GRP_TYPE     =   0x10,   /* 0x0010 */    /* relate to BTA_GATT_UNSUPPORT_GRP_TYPE in bta/bta_gatt_api.h */
    BLE_ATT_ERR_INSUF_RESOURCE         =   0x11,   /* 0x0011 */    /* relate to BTA_GATT_INSUF_RESOURCE in bta/bta_gatt_api.h */

    BLE_ATT_ERR_NO_RESOURCES           =   0x80,   /* 0x80 */    /* relate to BTA_GATT_NO_RESOURCES in bta/bta_gatt_api.h */
    BLE_ATT_ERR_INTERNAL_ERROR         =   0x81,   /* 0x81 */    /* relate to BTA_GATT_INTERNAL_ERROR in bta/bta_gatt_api.h */
    BLE_ATT_ERR_WRONG_STATE            =   0x82,   /* 0x82 */    /* relate to BTA_GATT_WRONG_STATE in bta/bta_gatt_api.h */
    BLE_ATT_ERR_DB_FULL                =   0x83,   /* 0x83 */    /* relate to BTA_GATT_DB_FULL in bta/bta_gatt_api.h */
    BLE_ATT_ERR_BUSY                   =   0x84,   /* 0x84 */    /* relate to BTA_GATT_BUSY in bta/bta_gatt_api.h */
    BLE_ATT_ERR_ERROR                  =   0x85,   /* 0x85 */    /* relate to BTA_GATT_ERROR in bta/bta_gatt_api.h */
    BLE_ATT_ERR_CMD_STARTED            =   0x86,   /* 0x86 */    /* relate to BTA_GATT_CMD_STARTED in bta/bta_gatt_api.h */
    BLE_ATT_ERR_ILLEGAL_PARAMETER      =   0x87,   /* 0x87 */    /* relate to BTA_GATT_ILLEGAL_PARAMETER in bta/bta_gatt_api.h */
    BLE_ATT_ERR_PENDING                =   0x88,   /* 0x88 */    /* relate to BTA_GATT_PENDING in bta/bta_gatt_api.h */
    BLE_ATT_ERR_AUTH_FAIL              =   0x89,   /* 0x89 */    /* relate to BTA_GATT_AUTH_FAIL in bta/bta_gatt_api.h */
    BLE_ATT_ERR_MORE                   =   0x8a,   /* 0x8a */    /* relate to BTA_GATT_MORE in bta/bta_gatt_api.h */
    BLE_ATT_ERR_INVALID_CFG            =   0x8b,   /* 0x8b */    /* relate to BTA_GATT_INVALID_CFG in bta/bta_gatt_api.h */
    BLE_ATT_ERR_SERVICE_STARTED        =   0x8c,   /* 0x8c */    /* relate to BTA_GATT_SERVICE_STARTED in bta/bta_gatt_api.h */
    BLE_ATT_ERR_ENCRYPTED_MITM         =   BLE_ATT_OK,          /* relate to BTA_GATT_ENCRYPED_MITM in bta/bta_gatt_api.h */
    BLE_ATT_ERR_ENCRYPTED_NO_MITM      =   0x8d,   /* 0x8d */    /* relate to BTA_GATT_ENCRYPED_NO_MITM in bta/bta_gatt_api.h */
    BLE_ATT_ERR_NOT_ENCRYPTED          =   0x8e,   /* 0x8e */    /* relate to BTA_GATT_NOT_ENCRYPTED in bta/bta_gatt_api.h */
    BLE_ATT_ERR_CONGESTED              =   0x8f,   /* 0x8f */    /* relate to BTA_GATT_CONGESTED in bta/bta_gatt_api.h */
    BLE_ATT_ERR_DUP_REG                =   0x90,   /* 0x90 */    /* relate to BTA_GATT_DUP_REG in bta/bta_gatt_api.h */
    BLE_ATT_ERR_ALREADY_OPEN           =   0x91,   /* 0x91 */    /* relate to BTA_GATT_ALREADY_OPEN in bta/bta_gatt_api.h */
    BLE_ATT_ERR_CANCEL                 =   0x92,   /* 0x92 */    /* relate to BTA_GATT_CANCEL in bta/bta_gatt_api.h */
    /* 0xE0 ~ 0xFC reserved for future use */
    BLE_ATT_ERR_STACK_RSP              =   0xe0,   /* 0xe0 */    /* relate to BTA_GATT_STACK_RSP in bta/bta_gatt_api.h */
    BLE_ATT_ERR_APP_RSP                =   0xe1,   /* 0xe1 */    /* relate to BTA_GATT_APP_RSP in bta/bta_gatt_api.h */
    //Error caused by customer application or stack bug
    BLE_ATT_ERR_UNKNOWN_ERROR          =   0xef,   /* 0xef */    /* relate to BTA_GATT_UNKNOWN_ERROR in bta/bta_gatt_api.h */
    BLE_ATT_ERR_CCC_CFG_ERR            =   0xfd,   /* 0xFD Client Characteristic Configuration Descriptor Improperly Configured */    /* relate to BTA_GATT_CCC_CFG_ERR in bta/bta_gatt_api.h */
    BLE_ATT_ERR_PRC_IN_PROGRESS        =   0xfe,   /* 0xFE Procedure Already in progress */  /* relate to BTA_GATT_PRC_IN_PROGRESS in bta/bta_gatt_api.h */
    BLE_ATT_ERR_OUT_OF_RANGE           =   0xff,   /* 0xFF Attribute value out of range */    /* relate to BTA_GATT_OUT_OF_RANGE in bta/bta_gatt_api.h */
};

/**
 * @brief BLE UUID structure
 * 
 */
typedef struct {
	uint16_t len; /**< UUID length, 16bit, 32bit or 128bit */
	union {
		uint16_t uuid16;                   /**< 16bit UUID */
		uint32_t uuid32;                   /**< 32bit UUID */
		uint8_t uuid128[BLE_UUID_LEN_128]; /**< 128bit UUID */
	} uuid;                                /**< UUID */
} __BLE_PACKED__ ble_uuid_t;

/**
 * @brief BLE service characteristic structure
 * 
 */
struct ble_char_t {
    uint16_t handle;		/**< characteristic handle */
    uint16_t value_handle;	/**< value handle */
    uint8_t property;		/**< property */
    ble_uuid_t uuid;		/**< UUID */
    uint8_t desc_count;		/**< descriptor count */
};

/**
 * @brief BLE service characteristic descriptor structure
 * 
 */
struct ble_chardesc_t {
    uint16_t handle;	/**< descriptor handle */
    ble_uuid_t uuid;	/**< descriotor UUID */
};

/**
 * @brief BLE scanning parameter structure
 * 
 */
struct ble_scan_params_t {
	uint8_t scan_type;				/*!< Scan type */
	uint8_t own_addr_type;			/*!< Owner address type */
	uint8_t scan_filter_policy;		/*!< Scan filter policy */
	/**
	 * Scan interval. This is defined as the time interval from
	 * when the Controller started its last LE scan until it
	 * begins the subsequent LE scan.
	 * 
	 * Range: 0x0004 to 0x4000
	 * Default: 0x0010 (10 ms)
	 * Time = N * 0.625 msec
	 * Time Range: 2.5 msec to 10.24	seconds
	 */
	uint16_t scan_interval;

	/**
	 * Scan window. The duration of the LE scan. LE_Scan_Window
	 * shall be less than or equal to LE_Scan_Interval
	 * 
	 * Range: 0x0004 to 0x4000
	 * Default: 0x0010 (10 ms)
	 * Time = N * 0.625 msec
	 * Time Range: 2.5 msec to 10240 msec
	 */
	uint16_t scan_window;
};

/**
 * @brief BLE Scan result structure
 * 
 */
typedef struct {
	uint8_t bd_addr[SIZE_OF_BDADDR];	/**< Bluetooth device address which has been searched */
	char name[30];						/**< Name of Bluetooth device if found in ADV response */
	int rssi;							/**< Searched device's RSSI */
	uint8_t adv_data[31];				/**< Received advertisement data */
	uint8_t scan_rsp[31];				/**< Received scan response data */
	uint8_t adv_data_len;				/**< Adv data length */
	uint8_t scan_rsp_len;   			/**< Scan response length */
	uint8_t flag;           			/**< Advertising data flag bit */
	uint8_t addr_type;      			/**< Ble device address type */
	uint8_t event_type;					/**< BLE event type */
	int num_resps;						/**< Scan result number */
	uint8_t has_name;					/**< BLE device name is found and valid */
} ble_scan_result_t;

/**
 * @brief Gatt client callback parameters union
 */
typedef union {
	/**
	 * @brief Gatt client callback param of @ref BLE_CLIENT_LINK_CONNECTED
	 */
	struct ble_client_connect_evt_t {
		char name[31];					/**< Name of device */
		uint8_t addr[SIZE_OF_BDADDR];	/**< Remote bluetooth device address */
		uint16_t handle;				/**< Connection id */
		uint16_t mtu;					/**< MTU size */
	} connect;

	/**
	 * @brief Gatt client callback param of @ref BLE_CLIENT_LINK_DISCONNECT
	 */
	struct ble_client_disconnect_evt_t {
		char name[31];					/**< Name of device */
		uint8_t addr[SIZE_OF_BDADDR];	/**< Remote bluetooth device address */
		uint16_t handle;				/**< Connection id */
		uint16_t reason;				/**< The reason of gatt connection close */
	} disconnect;

	/**
	 * @brief Gatt client callback param of @ref BLE_CLIENT_SEARCH_SERVICE_COMPLETE
	 */
	struct gattc_search_cmpl_evt_param {
		uint16_t conn_id;					/**< Connection id */
		uint8_t searched_service_source;	/**< The source of the service information */
	} search_cmpl;

	/**
	 * @brief Gatt client callback param of @ref BLE_CLIENT_SEARCH_SERVICE
	 */
	struct gattc_search_res_evt_param {
		uint16_t conn_id;				/**< Connection id */
		uint16_t start_handle;			/**< Service start handle */
		uint16_t end_handle;			/**< Service end handle */
		ble_uuid_t uuid;				/**< Service id, include service uuid and other information */
		uint8_t is_primary;				/**< True if this is the primary service */
	} search_res;

	/**
	 * @brief Gatt client callback param of @ref BLE_CLIENT_READ_EVENT,
	 * @ref BLE_CLIENT_READ_MULTI_EVENT
	 */
	struct gattc_read_char_evt_param {
		uint8_t status;					/**< Operation status */
		uint16_t conn_id;				/**< Connection id */
		uint16_t handle;				/**< Characteristic handle */
		uint16_t value_len;				/**< Characteristic value length */
		uint8_t *value;					/**< Characteristic value */
	} read;

	/**
	 * @brief Gatt client callback param of @ref BLE_CLIENT_WRITE_EVENT,
	 * @ref BLE_CLIENT_WRITE_WITH_RESP_EVENT
	 */
	struct gattc_write_evt_param {
		uint8_t status;					/**< Operation status */
		uint16_t conn_id;				/**< Connection id */
		uint16_t handle;				/**< The Characteristic or descriptor handle */
		uint16_t offset;				/**< The prepare write offset, this value is valid only when prepare write */
	} write;

	/**
	 * @brief Gatt client callback param of @ref BLE_CLIENT_NOTIFY_EVENT
	 */
	struct gattc_notify_evt_param {
		uint16_t conn_id;				/**< Connection id */
		uint16_t handle;				/**< The Characteristic or descriptor handle */
		uint16_t value_len;				/**< Notify attribute value */
		uint8_t *value;					/**< Notify attribute value */
		uint8_t is_notify;				/**< True means notify, false means indicate */
	} notify;

	/**
	 * @brief Gatt client callback param of @ref BLE_CLIENT_SVC_REFRESH_COMPLETE
	 */
	struct gattc_dis_srvc_cmpl_evt_param {
		uint8_t status;					/**< Operation status */
		uint16_t conn_id;				/**< Connection id */
	} refresh_cmpl;

} ble_client_cb_param_t;             /**< GATT client callback parameter union type */

/**
 * @brief BLE scan result callback type
 * 
 * @sa ble_scan_result_t
 * 
 */
typedef void (*ble_scan_cb_f)(int event, ble_scan_result_t *arg);

/**
 * @brief BLE client event callback type
 * 
 * @sa ble_client_cb_param_t
 * 
 */
typedef void (*ble_client_cb_f)(int event, ble_client_cb_param_t *arg);

/**
 * @brief Setup BLE client event callback
 * 
 * @param cb Callback function to set, see @ref ble_client_cb_f
 * @return For return value see @ref bterr_e
 */
int ble_client_setcallback(ble_client_cb_f cb);

/**
 * @brief Start BLE device scan
 * 
 * @param duration duration of scan in seconds, default 10s
 * @param cb scan callback function see @ref ble_scan_cb_f
 * @return For return value see @ref bterr_e
 */
int ble_client_start_scan(int duration, ble_scan_cb_f cb);

/**
 * @brief Stop BLE scanning
 * 
 * @return For return value see @ref bterr_e
 */
int ble_client_stop_scan(void);

/**
 * @brief Get count of devices found during scanning
 * 
 * @return device count
 */
int ble_client_get_scancount(void);

/**
 * @brief Get scanned device information
 * 
 * @param idx index value from 0 to scan count - 1
 * @param res pointer to @ref ble_scan_result_t structure
 * @return For return value see @ref bterr_e
 */
int ble_client_get_scanresult(int idx, ble_scan_result_t *res);

/**
 * @brief Connect to BLE device. Once connection is initiated, A client callback event
 * is generated with @ref BLE_CLIENT_LINK_CONNECTED or
 * @ref BLE_CLIENT_LINK_DISCONNECT for connection and disconnection
 * respectively.
 * 
 * @param addr_type The type of peer device address, from scan result or @ref ble_addr_type_e
 * @param bd_addr Address of BLE device
 * @return For return value see @ref bterr_e
 */
int ble_client_connect(uint8_t addr_type, uint8_t *bd_addr);

/**
 * @brief Cancel and ongoing BLE connection initiated by @ref ble_client_connect()
 * 
 * @param bd_addr Address of BLE device
 * @return For return value see @ref bterr_e
 */
int ble_client_connect_cancel(uint8_t *bd_addr);

/**
 * @brief Get BLE client connection handle using address
 * 
 * @param bd_addr BLE device address
 * @return connection handle on success or -1 for error
 */
uint16_t ble_client_get_connhandle(uint8_t *bd_addr);

/**
 * @brief Disconnect from BLE device
 * 
 * @param handle connection handle
 * @return For return value see @ref bterr_e
 */
int ble_client_disconnect(uint16_t handle);

/**
 * @brief Refresh or discover BLE client services
 * 
 * @param handle connection handle
 * @return For return value see @ref bterr_e
 */
int ble_client_refresh_service(uint16_t handle);

/**
 * @brief Search BLE service by UUID
 * 
 * @param handle connection handle
 * @param svc_uuid service UUID to search for
 * @return For return value see @ref bterr_e
 */
int ble_client_search_service(uint16_t handle, ble_uuid_t *svc_uuid);

/**
 * @brief Get characteristic count for a BLE service pointed by @a svc_uuid
 * 
 * @param handle connection handle
 * @param svc_uuid service UUID
 * @param count returns characteristic count in this pointer
 * @return For return value see @ref bterr_e
 */
int ble_client_get_characteristic_count(uint16_t handle, ble_uuid_t *svc_uuid, int *count);

/**
 * @brief Get BLE service characteristics list
 * 
 * @param handle connection handle
 * @param svc_uuid service UUID
 * @param char_list buffer to store characteristics list (must be >= count * sizeof(struct ble_char_t))
 * @return For return value see @ref bterr_e
 */
int ble_client_get_characteristics(uint16_t handle, ble_uuid_t *svc_uuid, struct ble_char_t *char_list);

/**
 * @brief Get BLE service characteristic count by characteristic handle
 * 
 * @param handle connection handle
 * @param svc_uuid service UUID
 * @param start_handle start handle value
 * @param end_handle end handle value
 * @param count total count of characteristics found is returned in this buffer
 * @return For return value see @ref bterr_e
 */
int ble_client_get_characteristic_count_by_handle(uint16_t handle, ble_uuid_t *svc_uuid, uint16_t start_handle, uint16_t end_handle, int *count);

/**
 * @brief Get BLE service characteristics list by handle
 * 
 * @param handle service handle
 * @param svc_uuid service UUID
 * @param start_handle start handle value
 * @param end_handle end handle value
 * @param char_list buffer to store characteristics list (must be >= count * sizeof(struct ble_char_t))
 * @return For return value see @ref bterr_e
 */
int ble_client_get_characteristic_by_handle(uint16_t handle, ble_uuid_t *svc_uuid, uint16_t start_handle, uint16_t end_handle, struct ble_char_t *char_list);

/**
 * @brief Get BLE service characteristic by UUID pointed by @a char_uuid
 * 
 * @param handle connection handle
 * @param svc_uuid service UUID
 * @param char_uuid characteristic UUID
 * @param char_buffer buffer to store characteristic
 * @return For return value see @ref bterr_e
 */
int ble_client_get_characteristic_by_uuid(uint16_t handle, ble_uuid_t *svc_uuid, ble_uuid_t *char_uuid, struct ble_char_t *char_buffer);

/**
 * @brief Get BLE characteristic descriptors
 * 
 * @param handle connection handle
 * @param char_handle characteristic handle
 * @param desc_list buffer to store descriptor list, must be >= desc_count * sizeof(ble_chardesc_t)
 * @return For return value see @ref bterr_e
 */
int ble_client_get_descriptors(uint16_t handle, uint16_t char_handle, struct ble_chardesc_t *desc_list);

/**
 * @brief Get BLE characteristic descriptors handle
 * 
 * @param handle connection handle
 * @param char_handle characteristic handle
 * @param desc_uuid characteristic descriptor UUID
 * @param out_handle buffer to store descriptor handle
 * @return For return value see @ref bterr_e
 */
int ble_client_get_descriptor_handle(uint16_t handle, uint16_t char_handle, ble_uuid_t *desc_uuid, uint16_t *out_handle);

/**
 * @brief Read BLE device characteristic by handle. This will generate event callback with
 * @ref BLE_CLIENT_READ_EVENT event ID
 * 
 * @param handle connection handle
 * @param char_handle characteristic handle
 * @return For return value see @ref bterr_e
 */
int ble_client_read_char_by_handle(uint16_t handle, uint16_t char_handle);

/**
 * @brief Read BLE device characteristic by handle. This will generate event callback with
 * @ref BLE_CLIENT_READ_EVENT event ID
 * 
 * @param handle connection handle
 * @param start_handle start handle
 * @param end_handle end handle
 * @param uuid characteristic UUID to read
 * @return For return value see @ref bterr_e
 */
int ble_client_read_char_by_uuid(uint16_t handle, uint16_t start_handle, uint16_t end_handle, ble_uuid_t *uuid);

/**
 * @brief Read multiple BLE device characteristics by handle. This will generate event callback with
 * @ref BLE_CLIENT_READ_MULTI_EVENT event ID
 * 
 * @param handle connection handle
 * @param handles list of characteristic handles
 * @param count handle count
 * @return For return value see @ref bterr_e
 */
int ble_client_read_multiple_char(uint16_t handle, uint16_t *handles, int count);

/**
 * @brief Write BLE device characteristic by handle. On success, this function will generate
 * event callback with @ref BLE_CLIENT_WRITE_EVENT or @ref BLE_CLIENT_WRITE_WITH_RESP_EVENT
 * event ID.
 * 
 * @param handle connection handle
 * @param char_handle characteristic handle
 * @param value buffer to write
 * @param len lenth of data to write
 * @param type write type see @ref ble_write_type_e
 * @return For return value see @ref bterr_e
 */
int ble_client_write_char(uint16_t handle, uint16_t char_handle, void *value, uint16_t len, uint8_t type);

/**
 * @brief Write BLE device characteristic descriptor by handle. On success, this function will
 * generate event callback with @ref BLE_CLIENT_WRITE_EVENT.
 * 
 * @param handle connection handle
 * @param desc_handle characteristic descriptor handle
 * @param value buffer to write
 * @param len lenth of data to write
 * @return For return value see @ref bterr_e
 */
int ble_client_write_char_descr(uint16_t handle, uint16_t desc_handle, void *value, uint16_t len);

/**
 * @brief Do prepare write for BLE device characteristic
 * 
 * @param handle connection handle
 * @param char_handle characteristic handle
 * @param offset offset of write value
 * @param value buffer to write
 * @param value_len length of data to write
 * @return For return value see @ref bterr_e
 */
int ble_client_prepare_write(uint16_t handle, uint16_t char_handle, uint16_t offset, void *value, uint16_t value_len);

/**
 * @brief Execute a prepare write sequence
 * 
 * @param handle connection handle 
 * @param offset offset of write value
 * @return For return value see @ref bterr_e
 */
int ble_client_execute_write(uint16_t handle, uint16_t offset);

/**
 * @brief Enable/disable notification or indication
 * 
 * @param handle connection handle 
 * @param char_handle service characteristic handle
 * @param notify_indicate 1 for notify, 2 for indicate
 * @return For return value see @ref bterr_e
 */
int ble_client_configure_notify(uint16_t handle, uint16_t char_handle, uint16_t notify_indicate);

/**
 * @brief Set scan parameters
 * 
 * @param scan_params scan parameter structure, see @ref ble_scan_params_t
 * @return For return value see @ref bterr_e
 */
int ble_client_set_scan_params(struct ble_scan_params_t *scan_params);

/**
 * @brief Print BLE device information pointed by @a addr
 * 
 * @param addr BLE device address to print
 * @return For return value see @ref bterr_e
 */
int ble_client_print_devinfo_byaddr(uint8_t *addr);

/**
 * @brief Print BLE device information identified by name
 * 
 * @param name Name of BLE device
 * @return For return value see @ref bterr_e
 */
int ble_client_print_devinfo_byname(const char *name);

/**
 * @brief Print BLE device information identified by connection handle
 * 
 * @param handle connection handle
 * @return For return value see @ref bterr_e
 */
int ble_client_print_devinfo_byhandle(uint16_t handle);

#ifdef __cplusplus
}
#endif

#endif /* INC_AUDIO_H_ */
