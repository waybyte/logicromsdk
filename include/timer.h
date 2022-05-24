/*
 * timer.h
 *
 */

#ifndef INCLUDE_TIMER_H_
#define INCLUDE_TIMER_H_

#include "task_timer.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Timer function callback
 * @param id		Timer ID
 * @param arg		User data argument supplied during registration
 */
typedef void (*timercb_f)(int id, void *arg);

/**
 * Register a task independent timer
 * @param callback		[in] timer callback function of type timercb_f
 * @param arg			[in] User data pointer passed to callback function
 * @return				On success, returns timer ID registered. On error a negative value is returned
 */
int timer_register(timercb_f callback, void *arg);

/**
 * Configure timer
 * @param id			[in] Timer ID returned by @c timer_register()
 * @param ms			[in] Timeout value in miliseconds
 * @param cyclic		[in] TRUE if timer is cyclic, FALSE if single shot timer
 * @return				0 on success, On error a negative value is returned
 */
int timer_config(int id, unsigned long ms, int cyclic);

/**
 * Start a timer
 * @param id			[in] Timer ID returned by @c timer_register()
 * @return				0 on success, On error a negative value is returned
 */
int timer_start(int id);

/**
 * Stop a timer
 * @param id			[in] Timer ID returned by @c timer_register()
 * @return				0 on success, On error a negative value is returned
 */
int timer_stop(int id);

/**
 * Restart a timer
 * @param id			[in] Timer ID returned by @c timer_register()
 * @return				0 on success, On error a negative value is returned
 */
int timer_reset(int id);

/**
 * Free a registered timer
 * @param id			[in] Timer ID returned by @c timer_register()
 * @return				0 on success, On error a negative value is returned
 */
int timer_free(int id);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_TIMER_H_ */
