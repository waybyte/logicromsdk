/**
 * @brief open and possibly create a file
 * 
 * read more: man 2 open
 * 
 * @param path file path
 * @param flags flags
 * @param ... 
 * @return return file descriptor on success, -1 on failure 
 */
int open (const char *path, int flags, ...);

/**
 * @brief Close a file descriptor
 * 
 * read more: man 2 close

 * @param fd file descritor
 * @return return file descriptor on success, -1 on failure 
 */
int close(int fd);

/**
 * @brief read from a file descriptor
 * 
 * @param fd file descriptor
 * @param buf buffer to store read data
 * @param count number of bytes to read
 * @return zero or number of bytes read on success, -1 on failure
 */
ssize_t read(int fd, void *buf, size_t count);

/**
 * @brief write to file descriptor
 * 
 * @param fd file description
 * @param buf buffer to write
 * @param count number of bytes to write
 * @return On success, the number of bytes written is returned.  On error, -1 is returned
 */
ssize_t write(int fd, const void *buf, size_t count);

/**
 * @brief synchronize a file's in-core state with storage device
 * 
 * @param fd file descriptor
 * @return On success, these system calls return zero.  On error, -1 is returned
 */
int fsync(int fd);

/**
 * @brief test whether a file descriptor refers to a terminal
 * 
 * @param fd file descriptor
 * @return returns 1 if fd is an open file descriptor referring to a terminal; otherwise 0 is returned 
 */
int isatty(int fd);

/**
 * @brief reposition read/write file offset
 * 
 * @param fd file descriptor
 * @param offset offset value
 * @param whence SEEK_SET, SEEK_CUR, SEEK_END
 * @return resulting offset location on success, -1 on error
 */
off_t lseek(int fd, off_t offset, int whence);

/**
 * @brief truncate a file to a specified length
 * 
 * @param fd file descriptor
 * @param length new length
 * @return On success, zero is returned.  On error, -1 is returned
 */
int ftruncate(int fd, off_t length);

/**
 * @brief get file status
 * 
 * @param fd file descriptor
 * @param statbuf pointer to stat structure
 * @return On success, zero is returned.  On error, -1 is returned
 */
int fstat(int fd, struct stat *statbuf);

/**
 * @brief delete a file
 * 
 * @param pathname path to file
 * @return On success, zero is returned.  On error, -1 is returned
 */
int unlink(const char *pathname);

/**
 * @brief change the name
 * 
 * @param oldpath path to old file
 * @param newpath path to new file
 * @return On success, zero is returned.  On error, -1 is returned
 */
int rename(const char *oldpath, const char *newpath);

/**
 * @brief check user's permissions for a file
 * 
 * @param pathname path to file
 * @param mode the accessibility check(s) to be performed
 * @return On success, zero is returned.  On error, -1 is returned
 */
int access(const char *pathname, int mode);

/**
 * @brief create a directory
 * 
 * @param pathname path to directory
 * @param mode mode for the new directory
 * @return zero on success, or -1 if an error occurred
 */
int mkdir(const char *pathname, mode_t mode);

/**
 * @brief delete a directory
 * 
 * @param pathname path to directory
 * @return On success, zero is returned.  On error, -1 is returned
 */
int rmdir(const char *pathname);

/**
 * @brief manipulate file descriptor
 * 
 * more details check: man 2 fcntl
 * 
 * Supported commmands: F_GETFL, F_SETFL, F_GETLK, F_SETLK, F_SETLKW
 * 
 * @param fd file descriptor
 * @param cmd operation to performed
 * @param ... argument
 * @return On success, zero is returned.  On error, -1 is returned
 */
int fcntl(int fd, int cmd, ... /* arg */ );

/**
 * @brief apply, test or remove a POSIX lock on an open file            
 * 
 * @param fd File descriptor
 * @param cmd operation to perform
 * @param len unimplemented, only complete file locking possible
 * @return On success, zero is returned.  On error, -1 is returned
 */
int lockf(int fd, int cmd, off_t len);

/**
 * @brief apply or remove an advisory lock on an open file
 * 
 * @param fd File descriptor
 * @param operation operation to perform: LOCK_SH, LOCK_EX, LOCK_UN
 * @return On success, zero is returned.  On error, -1 is returned
 */
int flock(int fd, int operation);

/**
 * @brief returns current task id
 * 
 * @return returns taskid of current task
 */
pid_t getpid(void);

