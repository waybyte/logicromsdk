/*
 * task_timer.h
 *
 */

#ifndef INCLUDE_TASK_TIMER_H_
#define INCLUDE_TASK_TIMER_H_

/**
 * Timer callback function type
 * @param id		Timer ID
 * @param arg		User data argument supplied during registration
 */
typedef void (*timer_callback_f)(int id, void *arg);

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Register a task timer. Task timers can only be created/controlled from parent task.
 * @note Task timer will stop running if task is waiting on a semaphore or mutex or any blocking function call. Please use siwi timers in that case.
 * @param cb		[in] timer callback function of type timer_callback_f
 * @param arg		[in] User data pointer passed to callback function
 * @return			On success, returns timer ID registered. On error a negative value is returned
 */
int task_timer_register(timer_callback_f cb, void *arg);

/**
 * Start Task timer
 * @param tid		[in] Timer ID returned by task_timer_register
 * @param ms		[in] Timeout in ms
 * @param cyclic	[in] TRUE if cyclic or periodic timer, FALSE for one-shot timer
 * @return			0 on Success, On error negative value is returned
 */
int task_timer_start(int tid, unsigned int ms, int cyclic);

/**
 * Stop task timer
 * @param tid		[in] Timer ID returned by task_timer_register
 * @return			0 on Success, On error negative value is returned
 */
int task_timer_stop(int tid);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_TASK_TIMER_H_ */
