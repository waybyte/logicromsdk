/**
 * @enum _f_flag_e
 * Definitions for the flag in `f_flag'
 */
enum _f_flag_e {
	ST_RDONLY = 1, /**< Mount read-only */
	ST_NOSUID = 2, /**< Ignore suid and sgid bits */
	ST_NODEV = 4, /**< Disallow access to device special files. */
	ST_NOEXEC = 8, /**< Disallow program execution. */
	ST_SYNCHRONOUS = 16, /**< Writes are synced at once. */
	ST_MANDLOCK = 64, /**< Allow mandatory locks on an FS. */
	ST_WRITE = 128, /**< Write on file/directory/symlink. */
	ST_APPEND = 256, /**< Append-only file. */
	ST_IMMUTABLE = 512, /**< Immutable file. */
	ST_NOATIME = 1024, /**< Do not update access times. */
	ST_NODIRATIME = 2048, /**< Do not update directory access times. */
	ST_RELATIME = 4096 /**< Update atime relative to mtime/ctime. */
};

/**
 * @brief Filesystem information structure
 * 
 */
struct statvfs {
    unsigned long  f_bsize;    /* Filesystem block size */
    unsigned long  f_frsize;   /* Fragment size */
    fsblkcnt_t     f_blocks;   /* Size of fs in f_frsize units */
    fsblkcnt_t     f_bfree;    /* Number of free blocks */
    fsblkcnt_t     f_bavail;   /* Number of free blocks for unprivileged users */
    fsfilcnt_t     f_files;    /* Number of inodes */
    fsfilcnt_t     f_ffree;    /* Number of free inodes */
    fsfilcnt_t     f_favail;   /* Number of free inodes for unprivileged users */
    unsigned long  f_fsid;     /* Filesystem ID */
    unsigned long  f_flag;     /* Mount flags */
    unsigned long  f_namemax;  /* Maximum filename length */
};

/**
 * Get filesystem statistics
 * The function returns information about a mounted filesystem
 * @param path		pathname of any file within the mounted filesystem
 * @param buf		a pointer to a @ref statvfs structure
 * @return			On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.
 */
int statvfs(const char *path, struct statvfs *buf);

/**
 * Get filesystem statistics
 * fstatvfs() returns the same information returned by @ref statvfs() about an open file referenced by descriptor.
 * @param fd		File descriptor
 * @param buf		a pointer to a @ref statvfs structure
 * @return			On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.
 */
int fstatvfs(int fd, struct statvfs *buf);
