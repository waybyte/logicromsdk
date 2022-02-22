/**
 * @file filter.h
 * @brief Filter library to use with ADC
 */

#ifndef INC_FILTER_H_
#define INC_FILTER_H_

#ifdef __cplusplus
extern "C"
{
#endif

typedef void* filter_t;

/**
 * @brief Initialize filter
 * 
 * @param init_val Initial value to set or start with
 * @return filter handle 
 */
filter_t filter_init(float init_val);

/**
 * @brief Update filter and get current estimate value
 * 
 * @param handle filter handle returned by filter_init()
 * @param val measured value
 * @return current estimate value
 */
float filter_update(filter_t handle, float val);

/**
 * @brief Set filter level
 * 
 * Level value range from 0 to 10. 0 means faster update
 * and 10 means slower update when filter is updated
 * 
 * @param handle filter handle returned by filter_init()
 * @param level filter level 0 to 10
 * @return 1 if filter is updated, 0 if no change is made and current level is same as set level
 */
int filter_setlevel(filter_t handle, int level);

/**
 * @brief Get filter level
 * 
 * The return level is from 0 to 10 for preset values of variance_q and estimate error.
 * when custom value is set 11 is returned.
 * 
 * @param handle filter handle returned by filter_init()
 * @return filter level value from 0 to 11
 */
int filter_getlevel(filter_t handle);

/**
 * @brief Set custom q and estimate error values
 * 
 * @param handle filter handle returned by filter_init()
 * @param variance_q Covariance Q value lower the value, slower the response
 * @param est_error Estimate error to start with
 * @return 1 if filter is updated, 0 if no change is made
 */
int filter_setconfig(filter_t handle, float variance_q, float est_error);

/**
 * @brief Get values set for filter
 * 
 * @param handle filter handle returned by filter_init()
 * @param variance_q Covariance Q value
 * @param est_error Estimate error value
 * @return returns 0 always
 */
int filter_getconfig(filter_t handle, float *variance_q, float *est_error);

/**
 * @brief Get error estimate calculated by filter
 * 
 * @param handle filter handle returned by filter_init()
 * @return current measured error estimate
 */
float filter_get_estmate_error(filter_t handle);

/**
 * @brief Get filter gain
 * 
 * @param handle filter handle returned by filter_init()
 * @return current filter gain
 */
float filter_get_gain(filter_t handle);

#ifdef __cplusplus
}
#endif

#endif /* INC_FILTER_H_ */
