/*
 * pwm.h
 *
 */

#ifndef INCLUDE_HW_PWM_H_
#define INCLUDE_HW_PWM_H_

#include <plat/def_pwm.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize PWM channel and setup pin-muxing.
 * This function must be called before calling any other PWM function.
 * @param ch	PWM Channel @ref pwmch_e
 * @return		0 on success, negative value on error
 */
int pwm_init(int ch);

/**
 * Configure PWM channel parameters
 * @param ch		PWM Channel to configure @ref pwmch_e
 * @param freq		PWM Frequency to set
 * @param cycle		PWM Duty cycle
 * @return			0 on success, negative value on error
 */
int pwm_config(int ch, int freq, int cycle);

/**
 * Start PWM output
 * @param ch		PWM Channel to start @ref pwmch_e
 * @return			0 on success, negative value on error
 */
int pwm_start(int ch);

/**
 * Stop PWM output
 * @param ch		PWM Channel to stop @ref pwmch_e
 * @return			0 on success, negative value on error
 */
int pwm_stop(int ch);

/**
 * Release PWM channel and IO function changed to GPIO
 * @param ch		PWM Channel to free @ref pwmch_e
 * @return			0 on success, negative value on error
 */
int pwm_free(int ch);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_HW_PWM_H_ */
