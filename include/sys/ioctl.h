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
 * TODO: Unimplemented
 */
#define FIOASYNC	0x5452

#ifdef __cpluplus
extern "C" {
#endif

/**
 * Perform generic I/O operation command on special files
 * @param fd		[in] File descriptor
 * @param cmd		[in] Command to execute, Argument parameter varies based on command.
 * @return			on success zero is returned, On error, -1 is returned, and errno is set appropriately.
 */
int ioctl(int fd, unsigned long cmd, ...);

#ifdef __cpluplus
}
#endif

#endif /* INCLUDE_SYS_IOCTL_H_ */
