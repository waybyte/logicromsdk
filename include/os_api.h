/*
 * os_api.h
 *
 */

#ifndef INCLUDE_OS_API_H_
#define INCLUDE_OS_API_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @name ev_flags
 * Event flags
 */
#define EVENT_OP_AND 		0				/**< All event flags are required */
#define EVENT_OP_OR			1				/**< Not all event flags are required */

#define OS_WAIT_FOREVER	(-1U)				/**< Wait indefinitely */

/**
 * Sleep Type
 */
enum sleeptype_e {
	SLEEP_TYPE_NONE,	/**< Sleep disable */
	SLEEP_TYPE_LIGHT,	/**< Light sleep mode */
	SLEEP_TYPE_DEEP,	/**< Deep sleep mode */
};

/**
 * OS Task Function typedef
 * @param arg	User data argument to function
 */
typedef void (*os_taskfn_f)(void *arg);

/**
 * @struct osmsg_t
 * OS message structure for external Queue
 */
struct osmsg_t {
	uint32_t message;	/**< Message ID */
	uint32_t param1;	/**< First parameter */
	uint32_t param2;	/**< Second parameter */
	int source_taskid;	/**< Filled automatically by @ref os_message_get() */
};

/**
 * Reset System
 */
void sys_reset(void);

/**
 * Get Core system version
 * @param verbuf	[in,out] Buffer to store version (minimum 30)
 * @param len		[in] Length of verbuf
 * @return			Returns length of data stored in verbuf
 */
int sys_get_coreversion(char *verbuf, int len);

#if defined(PLATFORM_BC20) || defined(_DOXYGEN_)
/**
 * Set sleep timeout. System will wake up as soon as timeout finishes
 * or an any event occurs.
 * @note only available on NBIoT Platforms
 * @param ms		[in] Sleep timeout in miliseconds
 */
void sys_setsleep_timeout(uint32_t ms);

/**
 * Enter sleep mode
 * @note only available on NBIoT Platforms
 * @param type		[in] Type of sleep @ref sleeptype_e
 */
void sys_setsleep(int type);
#endif

/**
 * Task sleep API
 * @param ms		[in] time in milliseconds
 */
void os_task_sleep(unsigned int ms);

/**
 * Get message from task external queue
 * @param msg		[in] Pointer to OS message structure @ref osmsg_t
 * @return			0 on success, negative value on error
 */
int os_message_get(struct osmsg_t *msg);

/**
 * Send message to a task external queue, Maximum number of messages are 30
 * @note on GSM Platform, an assert is raised if more than 30 messages are sent to task queue.
 * @param dest_taskid	[in] Destination task id
 * @param message		[in] Message ID
 * @param param1		[in] Parameter 1
 * @param param2		[in] Parameter 2
 * @return				0 on success, negative value on error
 */
int os_message_send(int dest_taskid, uint32_t message, uint32_t param1, uint32_t param2);

/**
 * Create a mutex
 * Mutex created once cannot be destroyed.
 * @return		Mutex ID
 */
uint32_t os_mutex_create(void);

/**
 * Take a mutex. If mutex is not available, Task will be suspended until mutex is available.
 * @param mutex		[in] Mutex ID created by @ref os_mutex_create()
 * @return			0 on success, negative value on error
 */
int os_mutex_take(uint32_t mutex);

/**
 * Try to take a mutex. This API is similar to @ref os_mutex_take() with a optional timeout
 * @param mutex		[in] Mutex ID created by @ref os_mutex_create()
 * @param timeout	[in] duration in ms to wait, @ref OS_WAIT_FOREVER for indefinite wait, 0 to return immediately
 * @return			0 on success, negative value on error
 */
int os_mutex_trytake(uint32_t mutex, uint32_t timeout);

/**
 * Release a mutex. Once a mutex is released, OS does not yield on waiting task. Task switch happens when executing task is suspended
 * by sleep or waiting on external queue message.
 * @param mutex		[in] Mutex ID created by @ref os_mutex_create()
 * @return			0 on success, negative value on error
 */
int os_mutex_give(uint32_t mutex);

/**
 * Create a semaphore
 * @param val		[in] Initial value of semaphore
 * @return			Semaphore ID
 */
uint32_t os_semaphore_create(int val);

/**
 * Take a semaphore. When semaphore is not available and wait is requested, task will be suspended until semaphore is available
 * @param sem		[in] Semaphore ID created by @ref os_semaphore_create()
 * @param timeout	[in] duration in ms to timeout, @ref OS_WAIT_FOREVER for indefinite timeout, 0 to return immediately\n
 * 					On GSM platforms, when timeout is non zero API blocks until semaphore is acquired
 * @return			0 on success, negative value on error
 */
int os_semaphore_take(uint32_t sem, int timeout);

/**
 * Give a semaphore.
 * @param sem		[in] Semaphore ID created by @ref os_semaphore_create()
 * @return			0 on success, negative value on error
 */
int os_semaphore_give(uint32_t sem);

/**
 * Create event group. Event group has 32 flags represented by each bit of a 32-bit word.
 * @return			event group ID
 */
uint32_t os_eventgroup_create(void);

/**
 * Set event in event group
 * @param egid			[in] Event group ID
 * @param event_flags	[in] Event flags to set. Each bit represents an event flags
 * @return
 */
int os_eventgroup_setevent(uint32_t egid, uint32_t event_flags);

/**
 * Wait for event flag to set
 * @param egid			[in] Event group id
 * @param event_flags	[in] Requested flags
 * @return				0 on success, negative value on error
 */
int os_eventgroup_waitevent(uint32_t egid, uint32_t event_flags);

/**
 * Extended function for event flag wait
 * @param egid			[in] Event group ID
 * @param req_flags		[in] Requested flags
 * @param op			[in] Operation type ev_flags
 * @param out_flags		[out] Actual event flags available
 * @param timeout		[in] Timeout in milliseconds or @ref OS_WAIT_FOREVER to wait until an event is raised
 * @return				0 on success, negative value on error
 */
int os_eventgroup_waiteventex(uint32_t egid, uint32_t req_flags, int op, uint32_t *out_flags, uint32_t timeout);

/**
 * Get available stack size of running task
 * @return		Returns size in bytes
 */
uint32_t os_task_getavailstack(void);

/**
 * Get task id of running task
 * @return		Returns task id
 */
uint32_t os_task_getid(void);

/**
 * Create a new OS task, Maximum 10 tasks can be created
 * @param fn			[in] Task function of type os_taskfn_f
 * @param arg			[in] Argument to task function
 * @param suspend		[in] TRUE will suspend the task on creation, FALSE otherwise. Suspended task can be started later by calling os_start_task()
 * @return				On success task ID is returned, -1 on error.
 */
int os_task_create(os_taskfn_f fn, void *arg, int suspend);

#if defined(SOC_RDA8910) || defined(PLATFORM_BC20) || defined(_DOXYGEN_)
/**
 * Create a new OS task, with extended parameters
 * @note only available on NBIoT Platforms
 * @param fn			[in] Task function of type os_taskfn_f
 * @param stack			[in] Task stack size in bytes
 * @param arg			[in] Argument to task function
 * @param suspend		[in] TRUE will suspend the task on creation, FALSE otherwise. Suspended task can be started later by calling os_start_task()
 * @return				On success task ID is returned, -1 on error.
 */
int os_task_create_ex(os_taskfn_f fn, uint32_t stack, void *arg, int suspend);

/**
 * Start a task created by @ref os_task_create() /@ref os_task_create_ex()
 * @note only available on NBIoT Platforms
 * @param taskid		[in] Task ID
 * @return				0 on success, negative value on error
 */
int os_task_delete(int taskid);

/**
 * Get OS tick/uptime in milliseconds
 * @return tick counter in milliseconds
 */
uint64_t os_get_tickms(void);

/**
 * Get OS tick/uptime in microseconds
 * @return tick counter in microseconds
 */
uint64_t os_get_tickus(void);
#endif

/**
 * Start a suspended task created by @ref os_task_create()
 * @param taskid		[in] Task ID
 * @return				0 on success, negative value on error
 */
int os_task_start(int taskid);

/**
 * Enter critical section
 * @return				IRQ flags
 */
uint32_t os_enter_critical(void);

/**
 * Exit critical section
 * @param flags			[in] IRQ flags from @ref os_enter_critical()
 */
void os_exit_critical(uint32_t flags);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_OS_API_H_ */
