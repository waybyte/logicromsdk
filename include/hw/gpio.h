/*
 * gpio.h
 *
 */

#ifndef INCLUDE_HW_GPIO_H_
#define INCLUDE_HW_GPIO_H_

/**
 * GPIO Callback function prototype
 * @param handle
 * @param pin
 * @param level
 */
typedef void (*gpio_callback_f)(int handle, int pin, int level);

/**
 * @enum gpio_level_e
 * GPIO Level
 */
enum gpio_level_e {
	GPIO_LEVEL_LOW,	/**< GPIO Low level */
	GPIO_LEVEL_HIGH	/**< GPIO High level */
};

/**
 * @enum gpio_conf_e
 * GPIO Configuration Flags
 *
 * Flags can be ORed together to configure a GPIO.
 */
enum gpio_conf_e {
	GPIO_FLAG_INPUT		= 0x00,	/**< Configure gpio as input */
	GPIO_FLAG_OUTPUT	= 0x01,	/**< Configure gpio as Output */
	GPIO_FLAG_DEFHIGH	= 0x02,	/**< Set default state to high during @ref gpio_request */
	GPIO_FLAG_DEFLOW	= 0x00,	/**< Set default state to low during @ref gpio_request */
	GPIO_FLAG_PULLUP	= 0x04,	/**< Enable weak pullup */
	GPIO_FLAG_PULLDOWN	= 0x08,	/**< Enable weak pulldown */
	GPIO_FLAG_PULLSTRG	= 0x10,	/**< This flag when combined with @ref GPIO_FLAG_PULLUP/@ref GPIO_FLAG_PULLDOWN enables strong pull-up/pull-down respectively. */
};

/**
 * @enum gpio_trigger_e
 * GPIO Trigger Levels
 */
enum gpio_trigger_e {
	GPIO_TRIG_LOW = 1,/**< Trigger High -> Low level transition */
	GPIO_TRIG_HIGH,   /**< Trigger Low -> High level transition */
	GPIO_TRIG_BOTH    /**< Trigger on change of either level */
};

/**
 * @enum gpioname_e GPIO List
 * Each GPIO can be configured for alternate function via Pinmux APIs, Check "See Also" section for more information
 * @note GPIO number after GPIO37 are available only with S56 GSM Module
 */
enum gpioname_e {
	GPIO_1,
	GPIO_2,
	GPIO_3,
	GPIO_4,
	GPIO_5,
	GPIO_6,
	GPIO_7,
	GPIO_8,
	GPIO_9,
	GPIO_10,
	GPIO_11,
	GPIO_12,
	GPIO_13,
	GPIO_14,
	GPIO_15,
	GPIO_16,
	GPIO_17,
	GPIO_18,
	GPIO_19,
	GPIO_20,
	GPIO_21,
	GPIO_22,
	GPIO_23,
	GPIO_24,
	GPIO_25,
	GPIO_26,
	GPIO_27,
	GPIO_28,
	GPIO_29,
	GPIO_30,
	GPIO_31,
	GPIO_32,
	GPIO_33,
	GPIO_34,
	GPIO_35,
	GPIO_36,
	GPIO_37,
	/* S56 Module, Extra GPIO */
	GPIO_38,
	GPIO_39,
	GPIO_40,
	GPIO_41,
	GPIO_42,
	GPIO_43,
	GPIO_44,
	GPIO_45,
	GPIO_46,
	GPIO_47,
	GPIO_48,
	GPIO_49,
	GPIO_50,
	GPIO_51,
	GPIO_52,
	GPIO_PIN_MAX,
};

#ifdef __cpluplus
extern "C" {
#endif

/**
 * Request a GPIO
 * @param ioname	name of GPIO from @ref gpioname_e
 * @param flags		ORed list of gpio initialization flags @ref gpio_conf_e
 * @return			On success returns handle which can be used with other gpio APIs
 * on failure negative error code is returned
 */
int gpio_request(unsigned int ioname, int flags);

/**
 * Free a previously requested gpio
 * @param handle	Handle to gpio object returned by @ref gpio_request
 * @return	0 on success, negative error code on failure
 */
int gpio_free(int handle);

/**
 * Read input GPIO value
 * @param handle	Handle to gpio object returned by @ref gpio_request
 * @return	input gpio level @ref gpio_level_e
 */
int gpio_read(int handle);

/**
 * Write output GPIO pin
 * @param handle	Handle to gpio object returned by @ref gpio_request
 * @param value		gpio level to set @ref gpio_level_e
 * @return		0 on success, negative value on failure
 */
int gpio_write(int handle, int value);

/**
 * Set or change gpio direction
 * @param handle	Handle to gpio object returned by @ref gpio_request
 * @param dir		New gpio configuration, ORed list of GPIO flags @ref gpio_conf_e
 * @return		0 on success, negative value on failure
 */
int gpio_setdir(int handle, int dir);

/**
 * Enable GPIO trigger
 *
 * GPIO driver provide slow trigger option without debounce support to check and confirm
 * active trigger. On active trigger, callback function is called with state of gpio.
 * Triggers are only possible on gpio configured as inputs.
 * If input level changes after first transition is detected and deounce time,
 * internal debounce timer is reset for resampling of IO state.
 * @param handle		Handle to gpio object returned by @ref gpio_request
 * @param fn			Callback function of type @ref gpio_callback_f
 * @param trigger_time	Debounce time or trigger delay
 * @param flags			Type of trigger requested @ref gpio_trigger_e
 * @return				0 on success, negative error code on failure
 */
int gpio_settrigger(int handle, gpio_callback_f fn, int trigger_time, int flags);

/**
 * Disable GPIO trigger
 * @param handle		Handle to gpio object returned by @ref gpio_request
 * @return				0 on success, negative error code on failure
 */
int gpio_trigger_disable(int handle);

/**
 * Assign user specific data or application context to GPIO object
 * @param handle	Handle to gpio object returned by @ref gpio_request
 * @param arg		pointer to user data
 * @return			0 on success, negative value on failure
 */
int gpio_setuserdata(int handle, void *arg);

/**
 * Get user specific data or application context assigned to gpio object by gpio_setuserdata function
 * @param handle	Handle to gpio object returned by @ref gpio_request
 *
 * @return			pointer to user data if data is assigned, NULL otherwise
 */
void *gpio_getuserdata(int handle);

#ifdef __cpluplus
}
#endif

#endif /* INCLUDE_HW_GPIO_H_ */
