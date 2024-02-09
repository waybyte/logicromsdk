/*
 * storage.h
 *
 */

#ifndef INC_STORAGE_H_
#define INC_STORAGE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Storage media
 */
enum storage_media_e {
	STORAGE_MEDIA_FS,   /**< Storage media internal flash memory */
	STORAGE_MEDIA_SPIFS,/**< Storage media external SPI Flash */
	STORAGE_MEDIA_SD    /**< Storage media SD card */
};

/**
 * Storage read/write mode
 */
enum storage_mode_e {
	STORAGE_MODE_FIFO,/**< First-in First-out mode */
	STORAGE_MODE_LIFO,/**< Last-in First-out mode (not supported yet) */
};

/**
 * Action to be taken when storage full or reached reserve size
 */
enum storage_action_e {
	STORAGE_ONFULL_DELETE,/**< Delete oldest data */
	STORAGE_ONFULL_STOP,  /**< Stop further storage */
};

/**
 * Storage Configuration Structure
 */
struct storagecfg_t {
	uint8_t media;		  /**< Storage Media @ref storage_media_e */
	uint8_t parts;		  /**< Number of Storage partition */
	uint8_t mode;		  /**< Storage mode @ref storage_mode_e */
	uint8_t on_full;	  /**< Action to be taken when storage is full @ref storage_action_e */
	uint8_t compression;  /**< 1 to enable compression, 0 for no compression */
	uint8_t reserved;	  /**< reserved for future use */
	uint32_t packet_sz;	  /**< Approximate Average data packet size, this parameter is only used for storage estimation. does not limit data size for read/write */
	uint32_t max_storage; /**< Maximum number/count of data packets to store, storage full status is based on either max_storage is reached or storage memory <= resvd_mem */
	uint32_t reserved_mem;/**< Amount to reserved memory to keep in storage media, 16Kb minimum */
};

/**
 * Initialize storage management library. This function must be called before
 * calling any storage function.
 * @param cfg			[in] Storage configuration
 * @return				0 on success, negative value on error
 */
int storage_init(const struct storagecfg_t *cfg);

/**
 * Save data to storage partition
 *
 * @param part			[in] Partition index, starting from 0
 * @param buffer		[in] Buffer to store
 * @param len			[in] Length of data in buffer
 * @return				0 on success, negative value on error
 */
int storage_save(int part, const void *buffer, int len);

/**
 * Read data from storage partition
 *
 * @param part			[in] Partition index, starting from 0
 * @param buffer		[out] Pointer to buffer where data is stored
 * @param len			[out] Size of buffer, on return actual size read is updated
 * @return				0 on success, negative value on error. @a len is updated with actual data read from storage
 */
int storage_read(int part, void *buffer, int *len);

/**
 * Red data from storage partition indexed. This function can be used to read multiple packets at once.
 * The reading index is 0 based. In FIFO mode 0 points to first packet and in LIFO mode 0 points to last packet.
 * e.g in FIFO mode reading an indexed packet of index 2 will return third packet stored in FIFO order.
 *
 * @param part			[in] Partition index, starting from 0
 * @param index			[in] Index to read
 * @param buffer		[out] Pointer to buffer where data is stored
 * @param len			[out] Size of buffer, on return actual size read is updated
 * @return				0 on success, negative value on error. @a len is updated with actual data read from storage
 */
int storage_read_indexed(int part, int index, void *buffer, int *len);

/**
 * Delete data from storage partition
 *
 * @param part			[in] Partition index, starting from 0
 * @param count			[in] Number of packets to delete
 * @return				0 on success, negative value on error
 */
int storage_delete(int part, int count);

/**
 * Get storage status
 *
 * @param part			[in] Partition index, starting from 0
 * @return				TRUE if offline is pending, FALSE if not data is available
 */
int storage_available(int part);

/**
 * Get storage data count available in partition
 *
 * @param part			[in] Partition index, starting from 0
 * @return				available count
 */
int storage_getcount(int part);

/**
 * Delete data in storage partion
 *
 * @param part			[in] Partition index, starting from 0
 * @return				0 on success, negative on error
 */
int storage_clear(int part);

/**
 * Delete all data
 * 
 * @return int 
 */
int storage_clear_all(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_STORAGE_H_ */
