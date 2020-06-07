/*
 * modbus.h
 *
 *  Created on: Oct 27, 2015
 *      Author: ajay_
 */

#ifndef INC_MODBUS_H_
#define INC_MODBUS_H_

#include <stdint.h>

/**
 * Modbus Error codes
 */
enum mb_err_e {
	MB_OK,                   /**< No error. */
	MB_ERR_INVALID_ARG = -1, /**< Invalid argument */
	MB_ERR_NOTSUP = 2,       /**< Mode or Function code not supported */
	MB_ERR_TIMEOUT = -3,     /**< Modbus request timed out */
	MB_ERR_INVALID_DATA = -4,/**< Invalid response received from slave */
	MB_ERR_CRC_FAIL = -5,    /**< Checksum failed, CRC (for RTU) or LRC (for ASCII) */
	MB_ERR_INIT_FAIL = -6,   /**< Fail to initialize port */
};

/**
 * MODBUS function code
 */
enum _mb_func {
	MB_FUNC_INVAL = 0,          /**< Invalid function code */
	MB_FUNC_RD_COIL,            /**< Read coil */
	MB_FUNC_RD_DISC_INPUT,      /**< Read discrete input */
	MB_FUNC_RD_HOLDING,         /**< Read holding register */
	MB_FUNC_RD_INPUT,           /**< Read input register */
	MB_FUNC_WR_COIL,            /**< Write coil */
	MB_FUNC_WR_REG,             /**< Write single holding register */
	MB_FUNC_RD_EXP,             /**< Read exception status */
	MB_FUNC_DIAG,               /**< Diagnostic */
	MB_FUNC_COMM_EVT_COUNT = 11,/**< Get COM event counter */
	MB_FUNC_COMM_EVT_LOG,       /**< Get COM event log */
	MB_FUNC_WR_MUL_COIL = 15,   /**< Write multiple coils */
	MB_FUNC_WR_MUL_REG,         /**< Write multiple holding register */
	MB_FUNC_REP_SERV_ID,        /**< Report slave ID */
	MB_FUNC_RD_FILE_REC = 20,   /**< Read file record */
	MB_FUNC_WR_FILE_REC,        /**< Write file record */
	MB_FUNC_MASK_WR_REG,        /**< Mask write register */
	MB_FUNC_RDWR_MUL_REG,       /**< Read/Write multiple register */
	MB_FUNC_RD_FIFO_Q,          /**< Read FIFO Queue */
};

/**
 * MODBUS operation mode
 */
enum _mb_mode {
	MB_INVALID,/**< Invalid mode */
	MB_ASCII,  /**< MODBUS ASCII */
	MB_RTU,    /**< MODBUS RTU */
};

/**
 * MODBUS direction request flag
 */
enum _mb_dir {
	MB_DIR_RX,/**< Enable read request */
	MB_DIR_TX,/**< Enable write request */
};

/**
 * Read operation structure
 */
struct _mb_read {
	uint32_t start_add;	/**< Start address */
	uint16_t no_regs;	/**< Number of registers (16-bit) to read */
};

/**
 * Write operation structure
 */
struct _mb_write {
	uint32_t wr_add;	/**< Start address */
	uint16_t no_regs;	/**< Number of registers (16-bit) to write. For
							 writing a 32-bit value no_regs = 2 */
	int len;			/**< Length of data in data buffer */
	uint8_t *data;		/**< buffer containing data to write */
};

/**
 * Modbus operation
 */
union mb_op {
	struct _mb_read read;	/**< Read operation, see @ref _mb_read */
	struct _mb_write write;	/**< Write operation, see @ref _mb_write */
};

/**
 * MODBUS request structure
 */
struct modbus_t {
	uint8_t slaveid;			/**< Slave ID */
	uint8_t function;			/**< Function code */
	union mb_op op;				/**< Modbus Operation, see @ref mb_op */
	uint8_t *resp_buf;			/**< Buffer pointer to store MODBUS response.
									 In MODBUS ASCII mode, data will be stored
									 after conversion from ASCII to hex */
	uint16_t resp_buflen;		/**< Length of response buffer, On return this
									 value will be updated with actual number of
									 bytes stored in response buffer */
	uint8_t resp_timeout;		/**< MODBUS response timeout in milliseconds */
	int reserved;				/**< Reserved Unused */
};

/**
 * MODBUS direction control callback function
 * @param dir		Direction request flag @see _mb_dir
 */
typedef void (*mb_dirctl)(int dir);

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize MODBUS
 * @param com		[in] UART device file (e.g. /dev/ttyS1)
 * @param mode		[in] Operation mode @see _mb_mode
 * @param func		[in] Direction control callback function
 * @return			For return value see @ref mb_err_e
 */
int mb_init(char *com, int mode, mb_dirctl func);

/**
 * Perform a MODBUS request
 * @param mbus		[in] Modbus handle from @ref mb_init
 * @return			For return value see @ref mb_err_e
 */
int mb_request(struct modbus_t *mbus);

/* Utility functions */
/**
 * Calculate MODBUS CRC
 * @param msg		[in] Input buffer
 * @param len		[in] Length of data in buffer
 * @return			CRC value
 */
unsigned short mb_crc(unsigned char *msg, int len);

/**
 * Calculate MODBUS LRC
 * @param msg		[in] Input buffer
 * @param len		[in] Length of data in buffer
 * @return			LRC value
 */
unsigned char mb_lrc(unsigned char *msg, int len);

/**
 * MODBUS exception to string
 * @param errnum	[in] Exception code
 * @return			error description as string
 */
char *mb_strerror(uint8_t errnum);

#ifdef __cplusplus
}
#endif

#endif /* INC_MODBUS_H_ */
