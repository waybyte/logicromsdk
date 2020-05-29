/*
 * os_api.h
 *
 */

#ifndef INCLUDE_OS_API_H_
#define INCLUDE_OS_API_H_

#include <stdint.h>

/**
 * @name ev_flags
 * Event flags
 */
#define EVENT_OP_AND 		0				/** All event flags are required */
#define EVENT_OP_OR			1				/** Not all event flags are required */

/**
 * @name ev_wait
 */
#define EVENT_WAIT_SUSPEND	0xFFFFFFFF		/** Suspend task until requested flags are set */
#define EVENT_NO_WAIT		0				/** Do not wait */

/**
 * @typedef os_taskfn_f
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
	int source_taskid;	/**< Filled automatically by os_get_message() */
};

#ifdef __cpluplus
extern "C" {
#endif

/**
 * Reset System
 */
void sys_reset(void);

/**
 * Get Core system version
 * @param verbuf	Buffer to store version (minimum 30)
 * @param len		Length of verbuf
 * @return			Returns length of data stored in verbuf
 */
int sys_get_coreversion(char *verbuf, int len);

/**
 * Task sleep API
 * @param ms		[in] time in milliseconds
 */
void os_sleep(unsigned int ms);

/**
 * Get message from task external queue
 * @param msg		[in] Pointer to OS message structure @ref osmsg_t
 * @return			0 on success, negative value on error
 */
int os_get_message(struct osmsg_t *msg);

/**
 * Send message to a task external queue, Maximum number of messages are 30
 * OS will raise an assert if more than 30 messages are sent to task queue.
 * @param dest_taskid	[in] Destination task id
 * @param message		[in] Message ID
 * @param param1		[in] Parameter 1
 * @param param2		[in] Parameter 2
 * @return				0 on success, negative value on error
 */
int os_send_message(int dest_taskid, uint32_t message, uint32_t param1, uint32_t param2);

/**
 * Create a mutex
 * Mutex created once cannot be destroyed.
 * @param name	[in] Name for mutex (cannot be null)
 * @return		Mutex ID
 */
uint32_t os_create_mutex(const char *name);

/**
 * Take a mutex. If mutex is not available, Task will be suspended until mutex is available.
 * @param mutex		[in] Mutex ID created by os_create_mutex()
 * @return			0 on success, negative value on error
 */
int os_take_mutex(uint32_t mutex);

/**
 * Release a mutex. Once a mutex is released, OS does not yield on waiting task. Task switch happens when executing task is suspended
 * by sleep or waiting on external queue message.
 * @param mutex		[in] Mutex ID created by os_create_mutex()
 * @return			0 on success, negative value on error
 */
int os_give_mutex(uint32_t mutex);

/**
 * Create a semaphore
 * @param name		[in] Name of semaphore (cannot be null), for debugging only.
 * @param val		[in] Initial value of semaphore
 * @return			Semaphore ID
 */
uint32_t os_create_semaphore(const char *name, int val);

/**
 * Take a semaphore. When semaphore is not available and wait is requested, task will be suspended until semaphore is available
 * @param sem		[in] Semaphore ID created by os_create_semaphore()
 * @param wait		[in] TRUE if wait for semaphore to be available, FALSE to return immediately
 * @return			0 on success, negative value on error
 */
int os_take_semaphore(uint32_t sem, int wait);

/**
 * Give a semaphore.
 * @param sem		[in] Semaphore ID created by os_create_semaphore()
 * @return			0 on success, negative value on error
 */
int os_give_semaphore(uint32_t sem);

/**
 * Create event group. Event group has 32 flags represented by each bit of a 32-bit word.
 * @param name		[in] Name of event group (cannot be null).
 * @return			event group ID
 */
uint32_t os_create_eventgroup(const char *name);

/**
 * Set event in event group
 * @param egid			[in] Event group ID
 * @param event_flags	[in] Event flags to set. Each bit represents an event flags
 * @return
 */
int os_eg_setevent(uint32_t egid, uint32_t event_flags);

/**
 * Wait for event flag to set
 * @param egid			[in] Event group id
 * @param event_flags	[in] Requeted flags
 * @return				0 on success, negative value on error
 */
int os_eg_waitevent(uint32_t egid, uint32_t event_flags);

/**
 * Extended function for event flag wait
 * @param egid			[in] Event group ID
 * @param req_flags		[in] Requested flags
 * @param op			[in] Operation type ev_flags
 * @param out_flags		[out] Actual event flags available
 * @param timeout		[in] Timeout in milliseconds or one of the ev_wait flags
 * @return				0 on success, negative value on error
 */
int os_eg_waiteventex(uint32_t egid, uint32_t req_flags, int op, uint32_t *out_flags, uint32_t timeout);

/**
 * Get available stack size of running task
 * @return		Returns size in bytes
 */
uint32_t os_task_getavailstack(void);

/**
 * Get task id of running task
 * @return		Returns task id
 */
uint32_t os_get_currtaskid(void);

/**
 * Create a new OS task, Maximum 10 tasks can be created
 * @param fn			[in] Task function of type os_taskfn_f
 * @param arg			[in] Argument to task function
 * @param suspend		[in] TRUE will suspend the task on creation, FALSE otherwise. Suspended task can be started later by calling os_start_task()
 * @return				On success task ID is returned, -1 on error.
 */
int os_create_task(os_taskfn_f fn, void *arg, int suspend);

/**
 * Start a task created by os_create_task()
 * @param taskid		[in] Task ID
 * @return				0 on success, negative value on error
 */
int os_start_task(int taskid);

/**
 * Disable IRQs
 * @return				IRQ flags
 */
unsigned int disable_irqs(void);

/**
 * Enable IRQs
 * @param flags			[in] IRQ flags from disable_irqs()
 */
void enable_irqs(unsigned int flags);

#ifdef __cpluplus
}
#endif

#endif /* INCLUDE_OS_API_H_ */
