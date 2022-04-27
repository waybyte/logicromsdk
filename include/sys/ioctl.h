/*
 * ioctl.h
 *
 */

#ifndef INCLUDE_SYS_IOCTL_H_
#define INCLUDE_SYS_IOCTL_H_

/* Implemented for sockets only as of now */

/**
 * Get output queue size (not sent + not acked)
 * This command expects unsigned long
 */
#define TIOCOUTQ	0x5411
#define SIOCOUTQ	TIOCOUTQ

/**
 * Get number of bytes available to read
 * This command expects unsigned long
 */
#define FIONREAD	0x541B
#define SIOCINQ		FIONREAD

/**
 * Set Blocking or non-blocking IO
 * This command expects integer with 1 or 0
 */
#define FIONBIO		0x5421

/**
 * Set ASYNC IO operation
 * 
 * TODO: Unimplemented
 */
#define FIOASYNC	0x5452

/**
 * Get Next character in read buffer
 * without removing it. Multiple call to
 * ioctl will result in same character unless
 * read() is called
 * expects int *
 */
#define TIOCPEEK	0x545C
/**
 * Get data from read buffer without removing it.
 * expects struct @ref iopeek_t *
 */
#define TIOCPEEKBUF	0x545D

/**
 * Peek structure
 */
struct iopeek_t {
	void *buf;	/** Buffer pointer to store read data */
	int len;	/** Length of buffer, on return this is updated with actual bytes read */
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Perform generic I/O operation command on special files
 * @param fd		[in] File descriptor
 * @param cmd		[in] Command to execute, Argument parameter varies based on command.
 * @return			on success zero is returned, On error, -1 is returned, and errno is set appropriately.
 */
int ioctl(int fd, unsigned long cmd, ...);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_SYS_IOCTL_H_ */
