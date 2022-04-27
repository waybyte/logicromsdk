/**
 * @file imu_sensor.h
 * @brief IMU Sensor fusion library
 * 
 */

#ifndef INC_HW_IMU_SENSOR_H_
#define INC_HW_IMU_SENSOR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Sensor has accelerometer
 */
#define SENSOR_CAP_ACCEL 1
/**
 * Sensor has Gyroscope
 */
#define SENSOR_CAP_GYRO 2
/**
 * Sensor has Magnetometer
 * @note Not implemented yet
 */
#define SENSOR_CAP_MAG 4

/**
 * Calibration start event
 * 
 * On this event sensor can be prepared for calibration
 * with fast data rate for reading
 */
#define SENSOR_CAL_START 1
/**
 * Calibration end event
 * 
 * After this event the offset values can be saved to flash
 * or any storage media
 */
#define SENSOR_CAL_END 0

/**
 * @brief Sensor type for callbacks
 * 
 */
enum imusentype_e {
	SEN_TYPE_ACCEL, /**< Accelerometer */
	SEN_TYPE_GYRO,  /**< Gyroscope */
	SEN_TYPE_MAG,   /**< Magnetometer */
};

/**
 * @brief Events generated by sensor fusion library based
 * on configured thresholds.
 * 
 */
enum imuevent_e
{
	IMU_EVENT_MOTION_ACTIVE = 1, /**< Motion detected event */
	IMU_EVENT_MOTION_INACTIVE,	 /**< Motion inactive event */
	IMU_EVENT_TILT_ACTIVE,		 /**< Tilt detect event */
	IMU_EVENT_TILT_INACTIVE,	 /**< Tilt inactive event, sensor returned to normal position */
	IMU_EVENT_HARSH_ACCEL,		 /**< Harsh acceleration event */
	IMU_EVENT_HARSH_BREAK,		 /**< Harsh breaking event */
	IMU_EVENT_HARSH_TURN,		 /**< Harsh turning event */
};

/**
 * @brief IMU event callback function type
 * 
 * @param event current event @ref imuevent_e
 */
typedef void (*imu_eventcb_f)(int event);

/**
 * @brief IMU configuration structure
 * 
 * acceleration threshold values provided are in unit of g\n
 * e.g. a value of 0.5 is 0.5g = 9.8 x 0.5 = 4.9m/s2
 * 
 * when configuration is not provided, below are the default threshold values\n
 * 
 * 		static_threshold = 0.01g
 * 		motion_detect_threshold = 0.02g
 * 		harsh_accel_threshold = 0.43g
 * 		harsh_break_threshold = 0.55g
 * 		harsh_turn_threshold = 0.47g
 * 		tilt_angle = 45 degrees
 * 		alpha_coff = 0.4
 * 		sample_ms = 20ms
 */
struct imuconf_t {
	float static_threshold;		   /**< acceleration value below which sensor is considered static */
	float motion_detect_threshold; /**< acceleration greater than or equal to this generates motion active event */
	float harsh_accel_threshold;   /**< acceleration threshold for harsh acceleration */
	float harsh_break_threshold;   /**< deceleration threshold for harsh breaking event */
	float harsh_turn_threshold;	   /**< acceleration threshold while turning */
	float tilt_angle;			   /**< Tilt threshold angle in degree */
	float alpha_coff;			   /**< Alpha coefficient, currently not used */
	int sample_ms;				   /**< Data sample rate in miliseconds. lower the better, 20ms is optimal. */
};

/**
 * @brief IMU Sensor structure
 * 
 * This structure defines the sensor interface used by sensor fusion
 * library.
 * 
 */
struct imu_sensor_t {
	int capability; /**< Sensor capability: @ref SENSOR_CAP_ACCEL, @ref SENSOR_CAP_GYRO, @ref SENSOR_CAP_MAG  */

	/**
	 * @brief Sensor initialization callback
	 * 
	 * @return return 0 for success and non zero for error
	 */
	int (*init)(void);

	/**
	 * @brief Read sensor data callback
	 * 
	 * When sensor type is Accelerometer, @a x, @a y, and @a z respresents
	 * acceleration in x, y and z axis respectively in m/s2
	 * 
	 * When sensor type is Gyroscope, @a x, @a y, and @a z respresents
	 * rotation around x, y and z axis respectively in degree/s.
	 * 
	 * @param type Sensor type @ref imusentype_e
	 * @param x Sensor value in x axis
	 * @param y sensor value in y axis
	 * @param z sensor value in z axis
	 * @return return 0 for success and non zero for error
	 */
	int (*read)(int type, float *x, float *y, float *z);

	/**
	 * @brief Read sensor raw data
	 * 
	 * This callback is made during calibration process and expect sensor raw
	 * data to calculate offset values.
	 * 
	 * For accelerometer, raw data should remove any gravity component from
	 * it. e.g. If sensor is placed flat, gravity is along z axis; hence it is
	 * expected that z is raw data of sensor without gravity.
	 * 
	 * @param type Sensor type @ref imusentype_e
	 * @param x raw value of sensor's x-axis
	 * @param y raw value of sensor's y-axis
	 * @param z raw value of sensor's z-axis
	 * @return return 0 for success and non zero for error
	 */
	int (*read_raw)(int type, int32_t *x, int32_t *y, int32_t *z);

	/**
	 * @brief Read sensor offset values
	 * 
	 * This callback is called from calibration routine to get offset values for
	 * specified sensor type.
	 * 
	 * @param type Sensor type @ref imusentype_e
	 * @param x sensor's x-axis offset
	 * @param y sensor's y-axis offset
	 * @param z sensor's z-axis offset
	 * @return return 0 for success and non zero for error
	 */
	int (*get_offset)(int type, int32_t *off_x, int32_t *off_y, int32_t *off_z);

	/**
	 * @brief Set sensor current offset values
	 * 
	 * This callback is called from calibration routine to set currently measured offset
	 * values for specified sensor type.
	 * 
	 * @param type Sensor type @ref imusentype_e
	 * @param x sensor's x-axis offset
	 * @param y sensor's y-axis offset
	 * @param z sensor's z-axis offset
	 * @return return 0 for success and non zero for error
	 */
	int (*set_offset)(int type, int32_t off_x, int32_t off_y, int32_t off_z);

	/**
	 * @brief Calibration status callback
	 * 
	 * This callback is called before start of calibration process with
	 * status as SENSOR_CAL_START to prepare sensor for calibration. This means
	 * setting highest data sample rate.
	 * 
	 * Once calibration is finished, this callback is again called with status
	 * as SENSOR_CAL_END to notify calibration finish. Settings of sensor can be
	 * reverted to normal data sampling rate.
	 * 
	 * @param status Calibration status
	 * @return return 0 for success and non zero for error
	 */
	int (*calib_status)(int status);
};

/**
 * @brief Initialize IMU library
 * 
 * @param config IMU configuration structure (@ref imuconf_t), can be null for default configuration
 * @param callback Event callback function, can be null if callback not required
 * @return return 0 on success, -1 on failure
 */
int imu_init(struct imuconf_t *config, imu_eventcb_f callback);

/**
 * @brief Add new sensor to sensor fusion library
 * 
 * @param sensor Sensor definition structure @ref imu_sensor_t
 * @return return sensor handle on success, negative value on failure (refer errno.h)
 */
int imu_add_sensor(const struct imu_sensor_t *sensor);

/**
 * @brief Change/set IMU configuration
 * 
 * @param config configuration structure, can be null to load default configuration
 * @return return 0 on success, -1 on failure
 */
int imu_setconfig(struct imuconf_t *config);

/**
 * @brief Change/Set event callback function
 * 
 * @param callback callback function pointer, can be null to disable callbacks
 * @return return 0 on success, -1 on failure
 */
int imu_setevent_callback(imu_eventcb_f callback);

/**
 * @brief Get current acceleration value in g
 * 
 * @param ax acceleration value on x-axis
 * @param ay acceleration value on y-axis
 * @param az acceleration value on z-axis
 * @return return 0 on success, -1 on failure
 */
int imu_get_accel(float *ax, float *ay, float *az);

/**
 * @brief Get linear acceleration value without gravity component with real
 * frame of reference. Values are in unit of g.
 * 
 * @param ax acceleration value on x-axis
 * @param ay acceleration value on y-axis
 * @param az acceleration value on z-axis
 * @return return 0 on success, -1 on failure
 */
int imu_get_linearaccel(float *ax, float *ay, float *az);

/**
 * @brief Get acceleration magnitude without gravity component with direction
 * positivity value represents acceleration and negative value represent
 * deceleration.
 * 
 * @param force Value of force magnitude in unit of g
 * @return return 0 on success, -1 on failure
 */
int imu_get_netaccel(float *force);

/**
 * @brief Get current gyroscope reading in deg/s
 * 
 * @param gx gyro value on x-axis
 * @param gy gyro value on y-axis
 * @param gz gyro value on z-axis
 * @return return 0 on success, -1 on failure
 */
int imu_get_gyro(float *gx, float *gy, float *gz);

/**
 * @brief Get Euler angles: Yaw, Pitch and roll.
 * When gyro sensor is not available, yaw value is always 0.
 * 
 * @param yaw Value of yaw angle in degree
 * @param pitch value of pitch in degree
 * @param roll value of roll in degree
 * @return return 0 on success, -1 on failure
 */
int imu_get_ypr(float *yaw, float *pitch, float *roll);

/**
 * @brief Get IMU library status,
 * 
 * @return return 1 when library is ready, else return 0
 */
int imu_is_ready(void);

/**
 * @brief Get motion status
 * 
 * @return returns 1 when motion active and 0 otherwise
 */
int imu_is_motionactive(void);

/**
 * @brief This function initiates sensor calibration
 * 
 * @param handle Sensor handle returned by imu_add_sensor()
 * @return return 0 on success, negative value on failure (refer errno.h)
 */
int imu_calibrate_sensor(int handle);

/**
 * @brief This function sets zero position of sensor placement, used for detection
 * of tilt, motion etc. Once set zero position is stored inside flash memory.
 * 
 * @return return 0 on success, -1 on failure
 */
int imu_calibrate_position(void);

/**
 * @brief Set library debug level to print sensor values
 * 
 * @b Level @b 0: No debug prints (default)
 * 
 * @b Level @b 1: Prints acceleration and Euler angles in following format\n
 * 	IMU: samplerate, accx, accy, accz, acc magnitude, average acceleration, yaw, pitch, roll
 * 
 * @b Level @b 2: Prints raw acceleration data and acceleration data in real frame of reference\n
 * in following format\n
 * 	IMU: samplerate, accx, accy, accz, acc_realx, acc_realy, acc_realz
 * 
 * @b Level @b 3: Prints gryo data in degree/s\n
 * 	IMU: samplerate, gyrox, gyroy, gyroz\n
 * 
 * @b Level @b 4: Print Quaternion value for teapot demo data in following format\n
 * 	IMU: samplerate, w, x, y, z\n
 * 
 * @param level debug level from 0 to 4
 */
void imu_set_debuglevel(int level);

/**
 * @brief Add GPS as sensor
 * If system uses GPS then imu library can use gps to validate some events
 * 
 * @return return sensor handle on success, negative value on failure (refer errno.h)
 */
int imu_add_gpssensor(void);

/**
 * @brief Enable or disable imu assistance to GPS algorithm for trip start/stop detection
 * 
 * @param enable 1 to enable, 0 to disable
 * 
 * @return return 0 on success, -1 on failure
 */
int imu_gps_motionassist(int enable);

#ifdef __cplusplus
}
#endif

#endif /* INC_HW_IMU_SENSOR_H_ */
