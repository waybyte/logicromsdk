/*
 * bluetooth.h
 *
 */

#ifndef INC_HW_BLUETOOTH_H_
#define INC_HW_BLUETOOTH_H_

#ifndef PLATFORM_BC20
/**
 * @note Bluetooth is only available on GSM platforms.
 */

/**
 * Maximum length for BT device name
 */
#define BTDEV_NAME_LEN_MAX                     56 /* 18 * 3 + 2 */

/**
 * Bluetooth error code
 */
enum bterr_e {
	BT_ERR_NONE = 0,    /**< No error */
	BT_ERR_ARG = -1,    /**< Invalid argument */
	BT_ERR_OPFAIL = -2, /**< Fail to perform operation */
	BT_ERR_BUSY = -3,   /**< Hardware busy */
	BT_ERR_NODEV = -4,  /**< No device found */
	BT_ERR_SCAN = -5,   /**< BT Scan error */
	BT_ERR_PAIR = -6,   /**< BT Pair error */
	BT_ERR_TIMEOUT = -7,/**< BT operation timeout */
};

/**
 * Device list selection to access driver's device list
 */
enum devtype_e {
	DEV_TYPE_SEARCH,/**< Searched device list */
	DEV_TYPE_PAIRED /**< Paired device list */
};

/**
 * Bluetooth device information structure
 */
struct btdevinfo_t {
	char name[BTDEV_NAME_LEN_MAX];	/**< Name of device */
	unsigned char addr[6];			/**< Hardware address of device */
};

/**
 * Initialize Bluetooth hardware
 * @param name			[in] Name of device shown to other bluetooth device while searching
 * @param use_btcli		[in] Bluetooth console select (1 to enable, 0 to disable).
 * 							 When enabled, /dev/bthost0 device file will not be available
 * 							 to the application.
 * @return				For return value see @ref bterr_e
 */
int bt_device_init(const char *name, int use_btcli);

/**
 * Turn on/off bluetooth hardware. Bluetooth is enabled by default when device is initialized.
 * @param on_off		[in] TRUE (1) to turn on or FLASE (0) to turn off
 * @return				For return value see @ref bterr_e
 */
int bt_device_power(int on_off);

/**
 * Reset bluetooth hardware. Equivalent to turn off and then turn on.
 * @return				For return value see @ref bterr_e
 */
int bt_device_reset(void);

/**
 * Change display name of device
 * @param name			[in] Device name
 * @return				For return value see @ref bterr_e
 */
int bt_device_setname(const char *name);

/**
 * Perform a bluetooth scan. This is a blocking function.
 * @param timeout		[in] Timeout value in seconds
 * @return				For return value see @ref bterr_e
 */
int bt_device_scan(unsigned int timeout);

/**
 * Cancel scan operation. calling this function will interrupt @ref bt_device_scan()
 * @return				For return value see @ref bterr_e
 */
int bt_device_scancancel(void);

/**
 * Get device list count
 * @param type			[in] Device list selection, see @ref devtype_e
 * @return				On success, returns available device count in the list.
 * 						On error, negative value is returned, see @ref bterr_e
 */
int bt_device_getcount(int type);

/**
 * Get bluetooth device information.
 * This function can be called to get list of devices after a scan is performed
 * or to get list of paired devices.
 *
 * @param idx			[in] 0 base index, referring to the list
 * @param type			[in] Device list selection, see @ref devtype_e
 * @param out_devinfo	[out] Device information structure to fill
 * @return				On success, returns 0 and @a out_devinfo is updated with
 * 						device information. On failure negative value is returned
 * 						see @ref bterr_e
 */
int bt_device_getdevinfo(int idx, int type, struct btdevinfo_t *out_devinfo);

/**
 * Pair a device.
 * @param name			[in] Name of device to pair with
 * @param passcode		[in] Pair passcode/Pin. Can be NULL if auto-generated passcode
 * 							 is supported by device.
 * @return				For return value see @ref bterr_e
 */
int bt_device_pair(const char *name, const char *passcode);

/**
 * Unpair a device
 * @param name			[in] Name of device to unpair
 * @return				For return value see @ref bterr_e
 */
int bt_device_unpair(const char *name);

/**
 * Unpair all paired devices
 * @return				For return value see @ref bterr_e
 */
int bt_device_unpairall(void);

#endif /* PLATFORM_BC20 */

#endif /* INC_HW_BLUETOOTH_H_ */
