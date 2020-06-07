/*
 * msgq.h
 *
 */

#ifndef INCLUDE_MSGQ_H_
#define INCLUDE_MSGQ_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create Task Independent message queue
 * @param qhandle	[out] pointer to store handle to queue
 * @param name		[in] Queue name, for debugging only (cannot be null)
 * @param ele_size	[in] Size of data pushed to queue
 * @return			0 on success, negative value on error
 */
int msgq_create(unsigned int *qhandle, char *name, int ele_size);

/**
 * Push data to queue
 * @param qhandle	[in] Queue handle
 * @param data		[in] Pointer to data. Size of data is fixed when creating message queue see @ref msgq_create
 * @return
 */
int msgq_push(unsigned int  qhandle, void *data);

/**
 * Try to get data from queue. This is a non blocking call.
 * @param qhandle	[in] Queue handle
 * @param data		[out] Pointer to buffer to store data
 * @return			0 on success, negative value on error
 */
int msgq_try_pop(unsigned int qhandle, void *data);

/**
 * Get data from queue. This is a blocking call, Task will be suspended if no data is available in queue.
 * If no timeout is specified task will block until any data is received in queue
 * @param qhandle	[in] Queue handle
 * @param data		[out] Pointer to buffer to store data
 * @param timeout	[in] Timeout value in milliseconds, If 0 task will suspend until new data is received.
 * @return			0 on success, negative value on error
 */
int msgq_pop(unsigned int qhandle, void *data, int timeout);

/**
 * Check message queue empty or not
 * @param qhandle	[in] Queue handle
 * @return			1 if empty, 0 if not empty, negative value on error
 */
int msgq_empty(unsigned int qhandle);

/**
 * Delete message queue
 * @param qhandle	[in] Queue handle
 * @return			0 on success, negative value on error
 */
int msgq_delete(unsigned int qhandle);

#ifdef __cplusplus
}
#endif

#endif /* MSGQ_H_ */
