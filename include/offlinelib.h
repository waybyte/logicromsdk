/*
 * offline.h
 *
 */

#ifndef INC_OFFLINE_H_
#define INC_OFFLINE_H_

#include <stdint.h>

/**
 * Offline Storage media
 */
enum offline_media_e {
	OFFLINE_MEDIA_UFS,  /**< Storage media internal flash */
	OFFLINE_MEDIA_SPIFS,/**< Storage media external SPI Flash */
	OFFLINE_MEDIA_SD    /**< Storage media SD card */
};

/**
 * Offline read/write mode
 */
enum offline_mode_e {
	OFFLINE_MODE_FIFO,/**< First-in First-out mode */
	OFFLINE_MODE_LIFO,/**< Last-in First-out mode (not supported yet) */
};

#ifdef __cpluplus
extern "C" {
#endif

/**
 * Initialize Offline storage library. This function must be called before
 * calling any offline library function. It is recommended to call this
 * function in @c user_main() during system initialization.
 * @return				0 on success, negative value on error
 */
int offline_init(void);

/**
 * Configure offline media. Once configured offline library will use parameter
 * storage to look for offline configuration. If a previously stored
 * configuration is found, it will be loaded. If no configuration is found and
 * offline library is not configured previously then default storage is
 * configured as internal flash.
 * @param media			[in] Storage type see @ref offline_media_e
 * @param max_storage	[in] Maximum storage capacity
 * @param resvd_mem		[in] Reserved storage memory
 * @param mode			[in] offline mode see @ref offline_mode_e
 * @param avg_pkt_sz	[in] Average packet size (a rough estimate) to plan storage method
 * @return				0 on success, negative value on error
 */
int offline_config(int media, uint32_t max_storage, uint32_t resvd_mem, int mode, int avg_pkt_sz);

/**
 * Save data to offline storage
 * @param buffer		[in] Buffer to store
 * @param len			[in] Length of data in buffer
 * @return				0 on success, negative value on error
 */
int save_offline(uint8_t *buffer, int len);

/**
 * Read data from offline storage
 * @param buffer		[out] Pointer to buffer where data is stored
 * @param len			[out] Size of buffer, on return actual size read is updated
 * @return				0 on success, negative value on error. @a len is updated with actual data read from storage
 */
int read_offline(uint8_t *buffer, int *len);

/**
 * Red data from offline storage indexed. This function can be used to read multiple packets at once.
 * The reading index is 0 based. In FIFO mode 0 points to first packet and in LIFO mode 0 points to last packet.
 * e.g in FIFO mode reading an indexed packet of index 2 will return third packet stored in FIFO order.
 *
 * @param index			[in] Index to read
 * @param buffer		[out] Pointer to buffer where data is stored
 * @param len			[out] Size of buffer, on return actual size read is updated
 * @return				0 on success, negative value on error. @a len is updated with actual data read from storage
 */
int read_offline_indexed(int index, uint8_t *buffer, int *len);

/**
 * Delete one packet from offline storage
 * @return				0 on success, negative value on error
 */
int offline_delete_packet(void);

/**
 * Delete multiple packets from offline storage
 * @param count			[in] Number of packets to delete
 * @return				0 on success, negative value on error
 */
int offline_delete_packets(int count);

/**
 * Reset offline storage
 * @param force			[in] if false normal reet is performed, if true force delete is performed which may take time depending on amount files on storage media
 * @return				0 on success, negative on error
 */
int reset_offline(int force);

/**
 * Get offline storage count
 * @param out_count		[out] Pointer to store available count, can be NULL if count not required
 * @return				TRUE if offline is pending, FALSE if not data is avilable
 */
int is_offline_pending(int *out_count);

#ifdef __cpluplus
}
#endif

#endif /* INC_OFFLINE_H_ */
