/*
 * sdmmc.h
 *
 */

#ifndef INCLUDE_HW_SDMMC_H_
#define INCLUDE_HW_SDMMC_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Card Type
 * 
 */
enum cardtype_e {
    CARD_TYPE_EMMC, /**< Card is EMMC, (5.0 supported) */
    CARD_TYPE_SD,   /**< Card is SD or MMC type */
};

/**
 * @brief Mount an SD card
 * 
 * To support SD card hotplug, Use GPIO for SD card detection
 * Unmount SD card when card is removed and mount again when
 * card is inserted.
 * 
 * On success, SD card is mounted on VFS at path: "/sd"
 * 
 * @param type card type @ref cardtype_e
 * @return 0 on success, negative on error 
 */
int sdmmc_mount(uint8_t type);

/**
 * @brief Unmount SD card
 * 
 * @return 0 on success, negative on error
 */
int sdmmc_unmount(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_HW_SDMMC_H_ */
