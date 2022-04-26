/*
 * gpslib.h
 *
 */

#ifndef INC_GPSLIB_H_
#define INC_GPSLIB_H_

#include <time.h>
#include <hw/gnss.h>
#include <gpsdriver.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Default harsh breaking/deceleration value - 0.55g
 */
#define DEF_HARSHBREAK 0.55
/**
 * @brief Default Harsh acceleration value - 0.43g
 */
#define DEF_OVERACCEL 0.43
/**
 * @brief Default harsh turning speed - 30Km/h
 */
#define DEF_HARSHTURN 30
/**
 * @brief Default overspeed limit - 80Km/h
 */
#define DEF_SPEEDLIMIT 80

/**
 * Geo-fence type
 */
enum geofence_type_e {
	FENCE_TYPE_CIRCLE,/**< Geo-fence of type circle */
	FENCE_TYPE_POLY   /**< Geo-fence of type polygon with more than 2 points */
};

/**
 * GPS library Events
 */
enum gpsevent_e {
	GPS_EVENT_FIRST_FIX,   /**< GPS first fix event after system startup */
	GPS_EVENT_MOTION_STOP, /**< Motion stop event */
	GPS_EVENT_MOTION_START,/**< Motion start event. use @ref gps_get_starttrace
								function to get complete movement trace. */
	GPS_EVENT_HARSHBREAK,  /**< Harsh break detected */
	GPS_EVENT_OVERACCEL,   /**< Harsh/over acceleration detected */
	GPS_EVENT_OVERSPEED,   /**< Over-speed detected */
	GPS_EVENT_SPEED_NORMAL,/**< Speed back to normal, Occurs after over-speed
								is detected */
	GPS_EVENT_COG_CHANGED, /**< Course over ground change event. Occurs during
								turns or on curves */
	GPS_EVENT_HARSHTURN,   /**< Harsh Turning/cornering detected */
	GPS_EVENT_NO_RESPONSE, /**< No response from GPS module */
	GPS_EVENT_GPS_LOST,    /**< GPS fix lost event */
	GPS_EVENT_GPS_LOCKED,  /**< GPS fix acquired event */
	GPS_EVENT_GPS_OK,      /**< GPS response normal, usually comes after
								@ref GPS_EVENT_NO_RESPONSE event when start
								GPS working properly again. */
};

/**
 * GPS Configuration parameter type
 */
enum gpsparam_e {
	GPS_PARAM_HARSHBREAK_LIMIT,  /**< Set threshold for Harsh breaking in
									  g (m/s2). Expects param as float */
	GPS_PARAM_OVERACCEL_LIMIT,   /**< Set threshold for Harsh acceleration in
									  g (m/s2). Expects param as float */
	GPS_PARAM_SPEEDLIMIT,        /**< Set over-speed limit in Km/h, expects
									  param as float */
	GPS_PARAM_TURNINGSPEED_LIMIT,/**< Set harsh turning speed limit in Km/h,
									  expects parameter as float */
	GPS_PARAM_ODOMETER,          /**< Set odometer value in meters */
};

/**
 * GPS point structure
 */
struct point_t {
	double lat;	/**< Latitude in degrees */
	double lng;	/**< Longitude in degrees */
};

/**
 * GPS data structure
 */
struct gpsdata_t {
	char time[7];		/**< GPS UTC time as hhmmss */
	char date[7];		/**< GPS UTC date as ddmmyy */
	char fix;			/**< GPS Fix status 'A' or 'V' */
	int satinview;		/**< Satellites in view and used in current fix */
	float speedkmph;	/**< GPS Speed in Km/h */
	float direction;	/**< Direction/Course over ground in degrees */
	double lat;			/**< Latitude in degree */
	double lng;			/**< Longitude in degree */
	float altitude;		/**< Altitude value in meters */
	double odom;		/**< Odometer value in meteres */
	float hdop,pdop;	/**< HDOP and PDOP values */
};

/**
 * GPS Initial configuration structure
 */
struct gpsconfig_t {
	int baud;			/**< GPS Baudrate */
	float speedlimit;	/**< Over-speed limit in Km/h */
	float harshturn;	/**< Harsh Turning speed limit in Km/h */
	float harshbrk;		/**< Harsh breaking limit in g (m/s2) */
	float overaccel;	/**< Harsh acceleration limit in g (m/s2) */
	/**
	 * GPS event callback function
	 * @param GPS Event see @ref gpsevent_e
	 */
	void (*gps_event_cb)(int);

	/**
	 * GPS parsed data callback
	 * @param GPS Data structure pointer
	 */
	void (*gps_datacallback)(struct gpsdata_t *);

	/**
	 * GPS Raw data callback
	 * @param nmea NMEA data string
	 */
	void (*gps_nmea_cb)(const char *nmea);
};

/**
 * Initialize GPS library and start GPS data handler task\n
 * It is recommended to set GPS driver before calling this function.
 * 
 * @param port			[in] device file where GPS is connected, e.g. /dev/ttyS1
 * @param config		[in] GPS initial configuration, see @ref gpsconfig_t
 * @return				0 on success, negative value on failure
 */
int gpslib_init(char *port, struct gpsconfig_t *config);

/**
 * Send command to GPS. GPS commands format:\n
 * $[command]*[checksum][cr][lf]\n
 * This function expect "command" as cmd parameter. The header, footer and
 * crc value will be calculated internally based on GPS type configured during
 * gps initialization see @ref gpslib_init()
 * @param cmd		[in] GPS command without $ and CRC
 * @return			0 on success, negative value on failure
 */
int gps_send_command(const char *cmd);

/**
 * Reconfigure GPS module. This function may be called if application
 * performs a hardware or software reset to GPS module.
 */
void gpslib_reconfig(void);

/**
 * Get current GPS data structure
 * @param gps		[out] GPS structure to fill
 */
void gps_getdata(struct gpsdata_t *gps);

/**
 * Get movement trace from starting position. This function can be called after
 * @ref GPS_EVENT_MOTION_START event has occurred.
 *
 * GPS library has complex logic to detect movement based on GPS data, which
 * may cause delay in firing motion start event. However GPS library keep track
 * of movement made from the start position to the moment when GPS event is
 * generated. So by calling this function the complete movement trace can be
 * sent to server without missing any point from track.
 * @param gps		[out] GPS data structure to fill
 * @return			0 on success, -1 no more point available in trace.
 */
int gps_get_starttrace(struct gpsdata_t *gps);

/**
 * Set GPS parameter
 * @param type		[in] GPS parameter type, see @ref gpsparam_e
 * @param val		[out] Pointer to GPS parameter value to set
 */
void gps_set_param(int type, void *val);

/**
 * Get GPS parameter
 * @param type		[in] GPS parameter type, see @ref gpsparam_e
 * @param val		[out] GPS parameter value buffer filled on return
 */
void gps_get_param(int type, void *val);

/**
 * Get GPS status
 * @return			Returns 0 if GPS is inactive or not responding
 * 					Returns 1 if GPS is active and running fine.
 */
int gps_getstatus(void);

/**
 * Write data on GPS port
 * @param buf		[in] Buffer with data to send
 * @param len		[in] Length of data in @a buf
 * @return			On success, returns actual number of bytes written or -1 on failure
 * 					errno will be set on failure.
 */
int gps_uart_write(unsigned char *buf, int len);

/**
 * Convert GPS string date time to seconds since Epoch.
 * @param date_in	[in] GPS date in ddmmyy format
 * @param time_in	[in] GPS Time in hhmmss format
 * @return			Time value in seconds since Epoch
 */
time_t gpsmktime(char *date_in, char *time_in);

/**
 * Check if point is within geofence or not
 * @param type				[in] Geofence type, see @ref geofence_type_e
 * @param fence				[in] For polygon type fence, Array of GPS points
 * 								 For Circular fence, pointer to point
 * 								 representing center of circle
 * @param corners_radius	[in] For polygon fence, Number of corners in the fence
 * 								 For circular fence, radius of fence in meters
 * @param point				[in] Input Point/GPS coordinates to test
 * @return					Returns True (1) if point is inside the geofence
 * 							False (0) if point is outside geofence
 * 							-22 if parameters are invalid.
 */
int geofence_check(int type, struct point_t *fence, unsigned int corners_radius, struct point_t *point);

#ifdef __cplusplus
}
#endif

#endif /* INC_GPSLIB_H_ */
