#ifndef INCLUDE_PLAT_DEF_ADC_H_
#define INCLUDE_PLAT_DEF_ADC_H_

/**
 * ADC channels
 */
enum adcch_e
{
#if defined(PLATFORM_M56) || defined(_DOXYGEN_)
	ADC_CH0, /**< ADC channel 0 - Pin 61 */
	ADC_CH1, /**< ADC channel 1 - Pin 12 */
	ADC_CH2, /**< ADC channel 2 - Pin 3 */
	ADC_CH3, /**< ADC channel 3 - Pin 2 */
	ADC_CH4, /**< ADC channel 4 - Pin 13 */
	ADC_CH5, /**< ADC channel 5 - Pin 33 */
#elif defined(PLATFORM_S20U)
	ADC_CH0, /**< ADC channel 0 - Pin 6 */
	ADC_CH1, /**< ADC channel 1 - Pin 47 */
	ADC_CH2, /**< ADC channel 2 - Pin 66 */
	ADC_CH3, /**< ADC channel 3 - Pin 30 */
	ADC_CH4, /**< ADC channel 4 - Pin 29 */
#elif defined(PLATFORM_BC20)
	ADC_CH0, /**< ADC channel 0 - Pin 6 */
	ADC_CH1, /**< ADC channel 1 - Pin 54 */
#elif defined(PLATFORM_SIM868)
	ADC_CH0, /**< ADC channel 0 - Pin 38 */
#elif defined(PLATFORM_M66)
	ADC_CH0, /**< ADC channel 0 - Pin 9 */
	ADC_CH1, /**< ADC channel 1 - Pin 16 */
	ADC_CH2, /**< ADC channel 2 - Pin 28 */
	ADC_CH3, /**< ADC channel 3 - Pin 29 */
#elif defined(PLATFORM_MC60)
	ADC_CH0, /**< ADC channel 0 - Pin 6 */
	ADC_CH1, /**< ADC channel 1 - Pin 47 */
	ADC_CH2, /**< ADC channel 2 - Pin 28 */
	ADC_CH3, /**< ADC channel 3 - Pin 29 */
#else /* RDA8910 */
	/**
	 * ADC Channel 0
	 * Module | Pin
	 * ------------
	 * EC600  | 19
	 * EC200  | 45
	 * N58    | 89
	 * N716   | 31
	 */
	ADC_CH0,
	/**
	 * ADC Channel 1
	 * Module | Pin
	 * ------------
	 * EC600  | 20
	 * EC200  | 44
	 * N58    | 88
	 * N716   | 30
	 */
	ADC_CH1,
	/**
	 * ADC Channel 2
	 * Module | Pin
	 * ------------
	 * EC600  | 113
	 * EC200  | 43
	 */
	ADC_CH2,
	/**
	 * ADC Channel 3
	 * Module | Pin
	 * ------------
	 * EC600  | 114
	 */
	ADC_CH3,
#endif
};

#endif /* INCLUDE_PLAT_DEF_ADC_H_ */
