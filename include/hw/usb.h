/*
 * adc.h
 *
 */

#ifndef INCLUDE_HW_USB_H_
#define INCLUDE_HW_USB_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get USB cable connect status
 * 
 * @return 1 if connected, 0 if unconnected
 */
int usb_is_connected(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_HW_USB_H_ */
