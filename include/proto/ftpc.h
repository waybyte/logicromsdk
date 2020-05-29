/*
 * ftpc.h
 *
 *  Created on: Mar 11, 2017
 *      Author: ajay_
 */

#ifndef INC_FTPC_H_
#define INC_FTPC_H_

/**
 * FTP Errors
 */
enum ftperr_e {
    QL_RET_ERR_RIL_FTP_OPENFAIL = -600,
    QL_RET_ERR_RIL_FTP_CLOSEFAIL = -601,
    QL_RET_ERR_RIL_FTP_SETPATHFAIL = -602,
    QL_RET_ERR_RIL_FTP_SETCFGFAIL = -603,
    QL_RET_ERR_RIL_FTP_RENAMEFAIL = -604,
    QL_RET_ERR_RIL_FTP_SIZEFAIL = -605,
    QL_RET_ERR_RIL_FTP_DELETEFAIL = -606,
    QL_RET_ERR_RIL_FTP_MKDIRFAIL = -607,
};

/**
 * FTP State
 */
enum ftpstate_e {
	FTP_STATE_RDY, /**< FTP Client ready */
	FTP_STATE_BUSY,/**< FTP Client busy */
	FTP_STATE_OPEN,/**< FTP Client is open */
	FTP_STATE_CLOSE/**< FTP Client is closed */
};

/**
 * FTP Storage type
 */
enum ftpstorage_e {
	FTP_LOCAL_UFS,/**< FTP storage internal flash */
	FTP_LOCAL_SD  /**< FTP storage SD Card */
};

/**
 * FTP Commands
 */
enum ftpcmd_e {
	FTP_CMD_OPEN,   /**< Open FTP client: arg: pointer to @ref ftpopen_t, result: NULL */
	FTP_CMD_CLOSE,  /**< Close FTP Client: arg: NULL, result: NULL */
	FTP_CMD_LCD,    /**< Select local directory: arg: ftpstorage_e, result: NULL */
	FTP_CMD_CD,     /**< Change remote directory: arg: pointer to remote directory path, result: NULL */
	FTP_CMD_PWD,    /**< Get current remote directory: arg: NULL, result: buffer pointer to hold remote path */
	FTP_CMD_GET,    /**< Get remote file: arg: Path to file, result: Integer pointer to store filesize */
	FTP_CMD_GETSIZE,/**< Get remote file size: arg: Path to remote file, result: Integer pointer to store filesize */
	FTP_CMD_PUT,    /**< Upload file to FTP server: arg: Local file path, result: Integer pointer to store bytes uploaded */
	FTP_CMD_DELETE, /**< Delete remote file: arg: Remote file path */
	FTP_CMD_RENAME, /**< Rename remote file: arg: pointer to @ref ftprename_t, result: NULL */
	FTP_CMD_MKDIR,  /**< Create remote directory: arg: path to directory, result: NULL */
	FTP_CMD_RMDIR,  /**< Remote remote directory: arg: path to directory, result: NULL */
	FTP_CMD_ASCII,  /**< Change file transfer mode to ASCII: arg: NULL, result: NULL */
	FTP_CMD_BINARY, /**< Change file transfer mode to Binary: arg: NULL, result: NULL */
	FTP_CMD_ACTIVE, /**< Change connection mode to Active: arg: NULL, result: NULL */
	FTP_CMD_PASSIVE,/**< Change connection mode to Passive: arg: NULL, result: NULL */
};

/**
 * Argument for FTP_CMD_OPEN
 */
struct ftpopen_t {
	char *host;				/**< Host name */
	unsigned int port;		/**< FTP port */
	char *user;				/**< FTP Username */
	char *password;			/**< FTP Password */
};

/**
 * Argument for FTP_CMD_RENAME
 */
struct ftprename_t {
	char *oldname;			/**< Old filename */
	char *newname;			/**< New filename */
};

#ifdef __cpluplus
extern "C" {
#endif

/**
 * Initialize FTP Client
 * @return 0 on success, negative value on error
 */
int ftpc_init(void);
/**
 * Reset FTP client state machine
 * @return 0 on success, negative value on error
 */
int ftpc_reset(void);

/**
 * Get status of FTP client
 * @return FTP status ftpstate_e
 */
int ftpc_getstatus(void);

/**
 * Execute FTP command
 * @param cmd		[in] FTP Command ftpcmd_e
 * @param arg		[in] Command argument
 * @param result	[out] Command result
 * @return			0 on success, negative value on error
 */
int ftpc_command(int cmd, void *arg, void *result);

#ifdef __cpluplus
}
#endif

#endif /* INC_FTPC_H_ */
