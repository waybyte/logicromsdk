/**
 * @brief Time structure
 * 
 */
struct timeval {
	time_t		tv_sec;		/**< seconds */
	suseconds_t	tv_usec;	/**< and microseconds */
};

/**
 * @brief process time details structure
 * 
 */
struct tms {
    clock_t tms_utime;  /**< user time */
    clock_t tms_stime;  /**< system time */
    clock_t tms_cutime; /**< user time of children */
    clock_t tms_cstime; /**< system time of children */
};

/**
 * @brief Get system time
 * 
 * @param tv Timeval structure to fill
 * @param tz Timezone structure to fill (unused)
 * @return 0 on success, -1 on error
 */
int gettimeofday(struct timeval *tv, struct timezone *tz);

/**
 * @brief Set system time
 * 
 * @param tv Time to set
 * @param tz timezone (unused)
 * @return 0 on success, -1 on error
 */
int settimeofday(const struct timeval *tv, const struct timezone *tz);

/**
 * @brief get process times
 * 
 * @param buf pointer to time structure @ref tms
 * @return On success, clock value in microseconds, On error -1 is returned
 */
clock_t times(struct tms *buf);

/**
 * @brief sleep for a specified number of seconds
 * 
 * @param seconds duration in seconds
 * @return always return 0
 */
unsigned int sleep(unsigned int seconds);

/**
 * @brief suspend execution for microsecond intervals
 * 
 * @note No task yield occurs
 * 
 * @param usec duration in seconds
 * @return always return 0
 */
int usleep(useconds_t usec);

