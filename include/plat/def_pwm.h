#ifndef INCLUDE_PLAT_DEF_PWM_H_
#define INCLUDE_PLAT_DEF_PWM_H_

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
#else
	PWM_CH0, /**< PWM Channel 0 - Pin 47 */
	PWM_CH1, /**< PWM Channel 1 - Pin 28 */
#endif
};

#endif /* INCLUDE_PLAT_DEF_PWM_H_ */
