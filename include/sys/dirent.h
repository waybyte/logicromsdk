/*
 * dirent.h
 *
 */

#ifndef INCLUDE_SYS_DIRENT_H_
#define INCLUDE_SYS_DIRENT_H_

#ifndef _DIRENT_H
# error "Never use <sys/dirent.h> directly; include <dirent.h> instead."
#endif

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum _dtype_e
 * File type flags for d_type
 */
enum _dtype_e {
	DT_UNKNOWN = 0,/**< The file type could not be determined */
#define DT_UNKNOWN		DT_UNKNOWN
	DT_FIFO = 1,   /**< FIFO File type */
#define DT_FIFO			DT_FIFO
	DT_CHR = 2,    /**< Special file type: Character device */
#define DT_CHR			DT_CHR
	DT_DIR = 4,    /**< Directory */
#define DT_DIR			DT_DIR
	DT_BLK = 6,    /**< Special file type: Block device */
#define DT_BLK			DT_BLK
	DT_REG = 8,    /**< Regular File type */
#define DT_REG			DT_REG
	DT_LNK = 10,   /**< File is a symbolic link */
#define DT_LNK			DT_LNK
	DT_SOCK = 12,  /**< File is a UNIX domain socket */
# define DT_SOCK		DT_SOCK
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

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_SYS_DIRENT_H_ */
