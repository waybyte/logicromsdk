/**
 * @enum _dtype_e
 * File type flags for d_type
 */
enum _dtype_e {
	DT_UNKNOWN = 0,/**< The file type could not be determined */
	DT_FIFO = 1,   /**< FIFO File type */
	DT_CHR = 2,    /**< Special file type: Character device */
	DT_DIR = 4,    /**< Directory */
	DT_BLK = 6,    /**< Special file type: Block device */
	DT_REG = 8,    /**< Regular File type */
	DT_LNK = 10,   /**< File is a symbolic link */
	DT_SOCK = 12,  /**< File is a UNIX domain socket */
};

/**
 * Directory entry structure
 */
struct dirent {
	ino_t			d_ino;		/**< inode number (Unused) */
	off_t			d_off;		/**< offset to the next dirent (unused) */
	unsigned long	d_reclen;	/**< length of this record */
	unsigned char	d_type;		/**< type of file @ref _dtype_e */
	char			d_name[256];/**< filename */
};

/**
 * Directory stream pointer type
 */
typedef void DIR;

/**
 * @brief Open a directory
 * @param name	[in] Directory path to open
 * @return a pointer to the directory stream.  On error, NULL is returned, and errno is set appropriately.
 */
DIR *opendir(const char *name);

/**
 * @brief Read a directory
 * @param dirp	[in] directory stream provided by @ref opendir
 * @return On success, a pointer to a dirent structure. (This structure may be statically allocated; do not attempt to free it.)
 */
struct dirent *readdir(DIR *dirp);

/**
 * @brief return current location in directory stream. This function may not supported by all filesystem drivers
 * @param dirp	[in] directory stream provided by @ref opendir
 * @return On success, function returns the current location in the directory stream.  On error, -1 is returned, and errno is set appropriately
 */
long telldir(DIR *dirp);

/**
 * @brief reset directory stream. This function may not supported by all filesystem drivers
 * @param dirp	[in] directory stream provided by @ref opendir
 */
void rewinddir(DIR *dirp);

/**
 * @brief set the position of the next @ref readdir call in the directory stream. This function may not supported by all filesystem drivers
 * @param dirp	[in] directory stream provided by @ref opendir
 * @param loc	[in] a value returned by a previous call to @ref telldir
 */
void seekdir(DIR *dirp, long loc);

/**
 * @brief Close a directory
 * @param dirp	[in] directory stream provided by @ref opendir
 * @return 0 on success.  On error, -1 is returned, and errno is set appropriately.
 */
int closedir(DIR *dirp);
