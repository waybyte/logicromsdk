#ifndef INCLUDE_PLAT_DEF_PWM_H_
#define INCLUDE_PLAT_DEF_PWM_H_

#if defined(SOC_RDA8910) || defined(_DOXYGEN_)
/**
 * PWM Channel 1 - Fixed Period in milliseconds
 * @note Only for Platform with RDA8910 SoC
 */
enum pwm1_prd_e {
	PWM1_PRD_125MS,
	PWM1_PRD_250MS,
	PWM1_PRD_500MS,
	PWM1_PRD_1000MS,
	PWM1_PRD_1500MS,
	PWM1_PRD_2000MS,
	PWM1_PRD_2500MS,
	PWM1_PRD_3000MS,
};
#elif defined(SOC_RDA8955)
/**
 * PWM Channel 1 - Fixed Period in milliseconds
 * @note Only for Platform with RDA8955 SoC
 */
enum pwm1_prd_e {
	PWM1_PRD_125MS,
	PWM1_PRD_250MS,
	PWM1_PRD_500MS,
	PWM1_PRD_750MS,
	PWM1_PRD_1000MS,
	PWM1_PRD_1250MS,
	PWM1_PRD_1500MS,
	PWM1_PRD_1750MS,
};
#endif

#if defined(SOC_RDA8910) || defined(SOC_RDA8955) || defined(_DOXYGEN_)
/**
 * PWM Channel 1 - Fixed On-time/Duty cycle in milliseconds
 * @note Only for Platform with RDA8910 or RDA8955 SoC
 */
enum pwm1_duty_e {
    PWM1_DUTY_UNDEFINE,
    PWM1_DUTY_15_6MS,
    PWM1_DUTY_31_2MS,
    PWM1_DUTY_46_9MS,
    PWM1_DUTY_62_5MS,
    PWM1_DUTY_78_1MS,
    PWM1_DUTY_93_7MS,
    PWM1_DUTY_110MS,
    PWM1_DUTY_125MS,
    PWM1_DUTY_141MS,
    PWM1_DUTY_156MS,
    PWM1_DUTY_172MS,
    PWM1_DUTY_187MS,
    PWM1_DUTY_203MS,
    PWM1_DUTY_219MS,
    PWM1_DUTY_234MS
};
#endif

/**
 * PWM Channels
 */
enum pwmch_e
{
#if defined(PLATFORM_BC20) || defined(_DOXYGEN_)
	PWM_CH0, /**< PWM Channel 0 - Pin 47 */
	PWM_CH1, /**< PWM Channel 1 - Pin 3 */
	PWM_CH2, /**< PWM Channel 2 - Pin 36 */
	PWM_CH3, /**< PWM Channel 3 - Pin 61 */
#elif defined(PLATFORM_M66)
	PWM_CH0, /**< PWM Channel 0 - Pin 16 */
#elif defined(PLATFORM_M56)
	PWM_CH0, /**< PWM Channel 0 - Pin 12 */
	PWM_CH1, /**< PWM Channel 1 - Pin 27 */
#elif defined(PLATFORM_SIM868)
	PWM_CH0, /**< PWM Channel 0 - Pin 6 */
	PWM_CH1, /**< PWM Channel 1 - Pin 57 */
#elif defined(PLATFORM_MC60)
	PWM_CH0, /**< PWM Channel 0 - Pin 47 */
	PWM_CH1, /**< PWM Channel 1 - Pin 28 */
#elif defined(SOC_RDA8955)
	/**
	 * PWM Channel 0
	 * This channel supports variable frequency and duty cycle
	 * Module | Pin
	 * ------------
	 * M590   | 58
	 * MC65   | 25
	 * A9     | 50
	 */
	PWM_CH0,
	/**
	 * PWM Channel 1
	 * This channel supports fixed frequency and duty cycle.
	 * Please refer @ref pwm1_prd_e and @ref pwm1_duty_e
	 * for possible values
	 * Module | Pin
	 * ------------
	 * M590   | 59
	 * MC65   | 24
	 * A9     | 49
	 */
	PWM_CH1,
#elif defined(SOC_ASR160X)
	PWM_CH0_IO8,
	PWM_CH0_IO31,
	PWM_CH1_IO9,
	PWM_CH1_IO32,
	PWM_CH2_IO6,
	PWM_CH2_IO8,
	PWM_CH2_IO10,
	PWM_CH3_IO7,
	PWM_CH3_IO9,
	PWM_CH3_IO11,
#else
	/**
	 * PWM Channel 0
	 * This channel supports variable frequency and duty cycle
	 * Module | Pin
	 * ------------
	 * EC600  | 70
	 * EC200  | 135
	 * N58    | 39
	 * N716   | 38
	 * L610   | 135
	 * EG915  | 20
	 */
	PWM_CH0,
	/**
	 * PWM Channel 1
	 * This channel supports fixed frequency and duty cycle.
	 * Please refer @ref pwm1_prd_e and @ref pwm1_duty_e
	 * for possible values
	 * Module | Pin
	 * ------------
	 * EC600  | 54
	 * EC200  | 5
	 * N58    | NA
	 * N716   | 67
	 * L610   | 5
	 * EG915  | 21
	 */
	PWM_CH1,
#endif
};

#endif /* INCLUDE_PLAT_DEF_PWM_H_ */
