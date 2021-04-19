/*
 * adc.h
 *
 */

#ifndef INCLUDE_HW_ADC_H_
#define INCLUDE_HW_ADC_H_

#include <plat/def_adc.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Configure ADC channel and setup pin-muxing
 * @param ch	[in] ADC Channel to use @ref adcch_e
 * @return		0 on success, negative error otherwise
 */
int adc_config(int ch);

/**
 * Read ADC Channel
 * @param ch	[in] ADC Channel to read @ref adcch_e
 * @return		12-bit ADC value, If ADC channel is not configured prior to calling this function, return value is unreliable.
 */
unsigned int adc_read(int ch);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_HW_ADC_H_ */
