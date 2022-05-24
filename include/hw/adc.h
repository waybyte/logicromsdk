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
 * 
 * @note 8910 has 12-bit ADC, whereas MT6261 has 10-bit ADC resolution
 * 
 * @param ch	[in] ADC Channel to read @ref adcch_e
 * @return		ADC raw value, If ADC channel is not configured prior to calling this function, return value is unreliable.
 */
unsigned int adc_read(int ch);

/**
 * @brief Read adc channel value in mV
 * 
 * @param ch    [in] ADC Channel to read @ref adcch_e
 * @return      ADC value in millivolts, If ADC channel is not configured prior to calling this function, return value is unreliable.
 */
unsigned int adc_read_mv(int ch);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_HW_ADC_H_ */
