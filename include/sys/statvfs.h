/*
 * statvfs.h
 *
 */

#ifndef INCLUDE_SYS_STATVFS_H_
#define INCLUDE_SYS_STATVFS_H_

#include <sys/types.h>

/**
 * @enum _f_flag_e
 * Definitions for the flag in `f_flag'
 */
enum _f_flag_e {
	ST_RDONLY = 1, /**< Mount read-only */
#define ST_RDONLY       ST_RDONLY
	ST_NOSUID = 2, /**< Ignore suid and sgid bits */
#define ST_NOSUID       ST_NOSUID
	ST_NODEV = 4, /**< Disallow access to device special files. */
# define ST_NODEV       ST_NODEV
	ST_NOEXEC = 8, /**< Disallow program execution. */
# define ST_NOEXEC      ST_NOEXEC
	ST_SYNCHRONOUS = 16, /**< Writes are synced at once. */
# define ST_SYNCHRONOUS ST_SYNCHRONOUS
	ST_MANDLOCK = 64, /**< Allow mandatory locks on an FS. */
# define ST_MANDLOCK    ST_MANDLOCK
	ST_WRITE = 128, /**< Write on file/directory/symlink. */
# define ST_WRITE       ST_WRITE
	ST_APPEND = 256, /**< Append-only file. */
# define ST_APPEND      ST_APPEND
	ST_IMMUTABLE = 512, /**< Immutable file. */
# define ST_IMMUTABLE   ST_IMMUTABLE
	ST_NOATIME = 1024, /**< Do not update access times. */
# define ST_NOATIME     ST_NOATIME
	ST_NODIRATIME = 2048, /**< Do not update directory access times. */
# define ST_NODIRATIME  ST_NODIRATIME
	ST_RELATIME = 4096 /**< Update atime relative to mtime/ctime. */
# define ST_RELATIME    ST_RELATIME
};

/**
 * @struct statvfs
 * Filesystem Information structure
 */
struct statvfs {
	unsigned long f_bsize; /**< file system block size */
	unsigned long f_frsize; /**< fragment size */
	fsblkcnt_t f_blocks; /**< size of fs in f_frsize units */
	fsblkcnt_t f_bfree; /**< free blocks in fs */
	fsblkcnt_t f_bavail; /**< free blocks avail to non-superuser */
	fsfilcnt_t f_files; /**< total file nodes in file system */
	fsfilcnt_t f_ffree; /**< free file nodes in fs */
	fsfilcnt_t f_favail; /**< avail file nodes in fs */
	unsigned long f_fsid; /**< file system id */
	unsigned long f_flag; /**< mount flags */
	unsigned long f_namemax; /**< maximum length of filenames */
};

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Get filesystem statistics
 * The function statvfs() returns information about a mounted filesystem
 * @param path		pathname of any file within the mounted filesystem
 * @param buf		a pointer to a @ref statvfs structure
 * @return			On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.
 */
int statvfs(const char *path, struct statvfs *buf);

/**
 * Get filesystem statistics
 * fstatvfs() returns the same information returned by @ref statvfs about an open file referenced by descriptor.
 * @param fd		File descriptor
 * @param buf		a pointer to a @ref statvfs structure
 * @return			On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.
 */
int fstatvfs(int fd, struct statvfs *buf);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* INCLUDE_SYS_STATVFS_H_ */
