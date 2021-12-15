/*
 * libtime.h
 *
 */

#ifndef INC_LIBTIME_H_
#define INC_LIBTIME_H_

#define CLKSYNC_SECONDS(x)			x
#define CLKSYNC_MINUTE(x)			(x * 60)

/**
 * Clock status
 */
enum clkstatus_e {
	CLK_STATUS_NOTSYNCED,/**< System clock not synced */
	CLK_STATUS_SYNCED    /**< System clock synced */
};

/**
 * Clock Source priority, for multiple clock sources,
 * highest priority source is selected for sync
 *
 * Following are the library provided clock sources and their
 * priorities:
 * # Network Provider Clock : Low Priority
 * # NTP : Medium Priority
 * # GPS : High Priority
 */
enum clkprio_e {
	CLK_SRC_PRIO_VLOW,   /**< Priority very low */
	CLK_SRC_PRIO_LOW,    /**< Priority low */
	CLK_SRC_PRIO_MED,    /**< Priority medium */
	CLK_SRC_PRIO_HIGH,   /**< Priority high */
	CLK_SRC_PRIO_VHIGH,  /**< Priority Very High */
};

/**
 * Clock synchronization mode select
 */
enum clkmode_e {
	CLOCK_MODE_AUTO,  /**< Auto Sync */
	CLOCK_MODE_MANUAL,/**< Manual Sync */
};

/**
 * Clock Source Structure
 */
struct clocksrc_t {
	const char *name;	/**< Clock Source name */
	int prio;		/**< Clock source priority @a clockprio_e */
	int sync_duration;	/**< Clock sync duration in seconds */
	int (*sync_cb)(void);	/**< Clock source sync callback function */
};

/**
 * Time structure for sync
 */
struct clocktm_t {
    int year;			/**< Year from 0 */
    int month;			/**< Month 1 to 12 */
    int day;			/**< Day 1 to 31 */
    int hour;			/**< Hour 0 to 23 */
    int minute;			/**< Minute 0 to 59 */
    int second;			/**< Second 0 to 59 */
    int reserved;		/**< reserved must be 0 */
};

#ifdef __cplusplus
extern "C" {
#endif

/* Clock source API */
/**
 * Register clock sync source, clock is considered invalid by default
 *
 * @param src	[in] Clock source structure pointer @a clocksrc_t
 * @return	0 on success, negative value on error
 */
int clock_src_register(const struct clocksrc_t *src);

/**
 * Set clock source as valid, after clock source is marked valid
 * system will call @a clocksrc_t::sync_cb after 30s.
 * @param name		[in] Clock source name
 * @param status	[in] 1 for valid, 0 for invalid
 * @return		0 on success, negative on error
 */
int clock_src_setvalid(const char *name, int status);

/**
 * Get clock source valid status
 * @param name		[in] Clock source name
 * @return		returns 1 if valid, 0 if not valid
 */
int clock_src_getvalid(const char *name);

/**
 * Get currently used clock source name for system
 * clock synchronization
 * @return		returns clock source name
 */
const char *clock_getsourcename(void);

/**
 * Get system clock sync status
 * @return		returns @a clkstatus_e
 */
int clock_get_syncstatus(void);

/**
 * Set ntp server address, default is "service.logicrom.com"
 * @param server	[in] NTP server domain or IP
 * @return		return 0 on success, negative on error
 */
int clock_set_ntpserver(const char *server);

/**
 * Get currently configured NTP server address
 * @return		returns NTP server address
 */
const char *clock_get_ntpserver(void);

/**
 * Set clock synchronization mode
 * @param mode		[in] Clock mode @a clkmode_e
 * @return		0 on success, negative on failure
 */
int clock_set_mode(int mode);

/**
 * Get current clock synchronization mode
 * @return		returns @a clockmode_e
 */
int clock_get_mode(void);

/**
 * Update system clock, this function can be called from
 * clock source sync callback to update system time.
 * @param timeval	[in] Time structure with current time information
 * @return		return 0 on success, negative on failure
 */
int clock_sync(struct clocktm_t *timeval);

#ifdef __cplusplus
}
#endif

#endif /* INC_LIBTIME_H_ */
