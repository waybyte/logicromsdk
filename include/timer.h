/*
 * timer.h
 *
 */

#ifndef INCLUDE_TIMER_H_
#define INCLUDE_TIMER_H_

#include "../include/task_timer.h"

/**
 * Timer function callback
 * @param id		Timer ID
 * @param arg		User data argument supplied during registration
 */
typedef void (*timercb_f)(int id, void *arg);

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Register a task independent timer
 * @param callback		[in] timer callback function of type timercb_f
 * @param arg			[in] User data pointer passed to callback function
 * @return				On success, returns timer ID registered. On error a negative value is returned
 */
int siwi_timer_register(timercb_f callback, void *arg);

/**
 * Configure timer
 * @param id			[in] Timer ID returned by @c siwi_timer_register()
 * @param ms			[in] Timeout value in miliseconds
 * @param cyclic		[in] TRUE if timer is cyclic, FALSE if single shot timer
 * @return				0 on success, On error a negative value is returned
 */
int siwi_timer_config(int id, unsigned long ms, int cyclic);

/**
 * Free a registered timer
 * @param id			[in] Timer ID returned by @c siwi_timer_register()
 */
void siwi_timer_free(int id);

/**
 * Start a timer
 * @param id			[in] Timer ID returned by @c siwi_timer_register()
 */
void siwi_timer_start(int id);

/**
 * Stop a timer
 * @param id			[in] Timer ID returned by @c siwi_timer_register()
 */
void siwi_timer_stop(int id);

/**
 * Restart a timer
 * @param id			[in] Timer ID returned by @c siwi_timer_register()
 */
void siwi_timer_reset(int id);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_TIMER_H_ */
