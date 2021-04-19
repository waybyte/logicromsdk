#ifndef INCLUDE_PLAT_DEF_GPIO_H_
#define INCLUDE_PLAT_DEF_GPIO_H_

/**
 * @enum gpioname_e GPIO List
 * Each GPIO can be configured for alternate function via Pinmux APIs, Check "See Also" section for more information
 */
enum gpioname_e
{
#if defined(PLATFORM_M56) || defined(_DOXYGEN_)
	GPIO_0,	 /**< Pin 12 */
	GPIO_1,	 /**< Pin 17 */
	GPIO_2,	 /**< Pin 24 */
	GPIO_3,	 /**< Pin 23 */
	GPIO_4,	 /**< Pin 26 */
	GPIO_5,	 /**< Pin 59 */
	GPIO_6,	 /**< Pin 4 */
	GPIO_7,	 /**< Pin 15 */
	GPIO_8,	 /**< Pin 27 */
	GPIO_9,	 /**< Pin 16 */
	GPIO_10, /**< Pin 78 */
	GPIO_11, /**< Pin 86 */
	GPIO_12, /**< Pin 87 */
	GPIO_13, /**< Pin 76 */
	GPIO_14, /**< Pin 77 */
	GPIO_15, /**< Pin 75 */
	GPIO_16, /**< Pin 44 */
	GPIO_17, /**< Pin 49 */
	GPIO_18, /**< Pin 88 */
	GPIO_19, /**< Pin 45 */
	GPIO_20, /**< Pin 3 */
	GPIO_21, /**< Pin 1 */
	GPIO_22, /**< Pin 53 */
	GPIO_23, /**< Pin 48 */
	GPIO_24, /**< Pin 28 */
	GPIO_25, /**< Pin 89 */
	GPIO_26, /**< Pin 36 */
	GPIO_27, /**< Pin 25 */
	GPIO_28, /**< Pin 40 */
	GPIO_29, /**< Pin 41 */
	GPIO_30, /**< Pin 2 */
	GPIO_31, /**< Pin 13 */
	GPIO_32, /**< Pin 62 */
	GPIO_33, /**< Pin 65 */
	GPIO_34, /**< Pin 64 */
	GPIO_35, /**< Pin 27 */
	GPIO_36, /**< Pin 66 - Input Only */
	GPIO_37, /**< Pin 60 - Input Only */
	GPIO_38, /**< Pin 19 */
	GPIO_39, /**< Pin 29 */
	GPIO_40, /**< Pin 30 */
	GPIO_41, /**< Pin 34 */
	GPIO_42, /**< Pin 35 */
	GPIO_43, /**< Pin 52 */
	GPIO_44, /**< Pin 58 */
	GPIO_45, /**< Pin 69 */
	GPIO_46, /**< Pin 70 */
	GPIO_47, /**< Pin 71 */
	GPIO_48, /**< Pin 80 */
	GPIO_49, /**< Pin 81 */
	GPIO_50, /**< Pin 82 */
	GPIO_51, /**< Pin 31 */
#elif defined(PLATFORM_S20U)
	GPIO_0,	 /**< Pin 47 */
	GPIO_1,	 /**< Pin 37 */
	GPIO_2,	 /**< Pin 35 */
	GPIO_3,	 /**< Pin 36 */
	GPIO_4,	 /**< Pin 38 */
	GPIO_5,	 /**< Pin 39 */
	GPIO_6,	 /**< Pin 59 */
	GPIO_7,	 /**< Pin 61 */
	GPIO_8,	 /**< Pin 62 */
	GPIO_9,	 /**< Pin 60 */
	GPIO_10, /**< Pin 3 */
	GPIO_11, /**< Pin 4 */
	GPIO_12, /**< Pin 7 */
	GPIO_13, /**< Pin 8 */
	GPIO_14, /**< Pin 9 */
	GPIO_15, /**< Pin 10 */
	GPIO_16, /**< Pin 13 */
	GPIO_17, /**< Pin 46 */
	GPIO_18, /**< Pin 55 */
	GPIO_19, /**< Pin 63 */
	GPIO_20, /**< Pin 66 */
	GPIO_21, /**< Pin 56 */
	GPIO_22, /**< Pin 57 */
	GPIO_23, /**< Pin 58 */
	GPIO_24, /**< Pin 64 */
	GPIO_25, /**< Pin 65 */
	GPIO_26, /**< Pin 33 */
	GPIO_27, /**< Pin 34 */
	GPIO_28, /**< Pin 24 */
	GPIO_29, /**< Pin 25 */
	GPIO_30, /**< Pin 30 */
	GPIO_31, /**< Pin 29 */
	GPIO_32, /**< Pin 19 */
	GPIO_33, /**< Pin 21 */
	GPIO_34, /**< Pin 20 */
	GPIO_35, /**< Pin 28 */
	GPIO_36, /**< Pin 67 - Input Only */
#elif defined(PLATFORM_BC20)
	GPIO_0,	 /**< Pin 2 */
	GPIO_1,	 /**< Pin 3 */
	GPIO_2,	 /**< Pin 4 */
	GPIO_3,	 /**< Pin 6 */
	GPIO_4,	 /**< Pin 7 */
	GPIO_5,	 /**< Pin 8 */
	GPIO_6,	 /**< Pin 9 */
	GPIO_7,	 /**< Pin 10 */
	GPIO_8,	 /**< Pin 24 */
	GPIO_9,	 /**< Pin 25 */
	GPIO_10, /**< Pin 28 */
	GPIO_11, /**< Pin 29 */
	GPIO_12, /**< Pin 30 */
	GPIO_13, /**< Pin 33 */
	GPIO_14, /**< Pin 34 */
	GPIO_15, /**< Pin 35 */
	GPIO_16, /**< Pin 36 */
	GPIO_17, /**< Pin 38 */
	GPIO_18, /**< Pin 39 */
	GPIO_19, /**< Pin 47 */
	GPIO_20, /**< Pin 54 */
	GPIO_21, /**< Pin 57 */
	GPIO_22, /**< Pin 58 */
	GPIO_23, /**< Pin 59 */
	GPIO_24, /**< Pin 60 */
	GPIO_25, /**< Pin 61 */
	GPIO_26, /**< Pin 62 */
	GPIO_27, /**< Pin 63 */
	GPIO_28, /**< Pin 67 */
	GPIO_29, /**< Pin 68 */
#elif defined(PLATFORM_SIM868)
	GPIO_0,	 /**< Pin 1 */
	GPIO_1,	 /**< Pin 2 */
	GPIO_2,	 /**< Pin 3 */
	GPIO_3,	 /**< Pin 4 */
	GPIO_4,	 /**< Pin 5 */
	GPIO_5,	 /**< Pin 6 */
	GPIO_6,	 /**< Pin 7 */
	GPIO_7,	 /**< Pin 14 */
	GPIO_8,	 /**< Pin 15 */
	GPIO_9,	 /**< Pin 16 */
	GPIO_10, /**< Pin 17 */
	GPIO_11, /**< Pin 22 */
	GPIO_12, /**< Pin 23 */
	GPIO_13, /**< Pin 29 */
	GPIO_14, /**< Pin 41 */
	GPIO_15, /**< Pin 42 */
	GPIO_16, /**< Pin 46 */
	GPIO_17, /**< Pin 47 */
	GPIO_18, /**< Pin 48 */
	GPIO_19, /**< Pin 49 */
	GPIO_20, /**< Pin 50 */
	GPIO_21, /**< Pin 51 */
	GPIO_22, /**< Pin 52 */
	GPIO_23, /**< Pin 53 */
	GPIO_24, /**< Pin 54 */
	GPIO_25, /**< Pin 55 */
	GPIO_26, /**< Pin 57 */
	GPIO_27, /**< Pin 58 */
	GPIO_28, /**< Pin 64 */
	GPIO_29, /**< Pin 65 */
#elif defined(PLATFORM_M66)
	GPIO_0,	 /**< Pin 16 */
	GPIO_1,	 /**< Pin 19 */
	GPIO_2,	 /**< Pin 20 */
	GPIO_3,	 /**< Pin 21 */
	GPIO_4,	 /**< Pin 22 */
	GPIO_5,	 /**< Pin 23 */
	GPIO_6,	 /**< Pin 28 */
	GPIO_7,	 /**< Pin 29 */
	GPIO_8,	 /**< Pin 30 */
	GPIO_9,	 /**< Pin 31 */
	GPIO_10, /**< Pin 32 */
	GPIO_11, /**< Pin 33 */
	GPIO_12, /**< Pin 15 */
	GPIO_13, /**< Pin 17 */
	GPIO_14, /**< Pin 18 */
	GPIO_15, /**< Pin 25 */
	GPIO_16, /**< Pin 38 */
	GPIO_17, /**< Pin 39 */
#else /* For MC60/MC20 */
	GPIO_0,	 /**< Pin 47 */
	GPIO_1,	 /**< Pin 37 */
	GPIO_2,	 /**< Pin 35 */
	GPIO_3,	 /**< Pin 36 */
	GPIO_4,	 /**< Pin 38 */
	GPIO_5,	 /**< Pin 39 */
	GPIO_6,	 /**< Pin 59 */
	GPIO_7,	 /**< Pin 61 */
	GPIO_8,	 /**< Pin 62 */
	GPIO_9,	 /**< Pin 60 */
	GPIO_10, /**< Pin 7 */
	GPIO_11, /**< Pin 8 */
	GPIO_12, /**< Pin 9 */
	GPIO_13, /**< Pin 11 */
	GPIO_14, /**< Pin 12 */
	GPIO_15, /**< Pin 10 */
	GPIO_16, /**< Pin 57 */
	GPIO_17, /**< Pin 58 */
	GPIO_18, /**< Pin 63 */
	GPIO_19, /**< Pin 64 */
	GPIO_20, /**< Pin 65 */
	GPIO_21, /**< Pin 46 */
	GPIO_22, /**< MC60 - Pin 34, MC20 - Pin 33 */
	GPIO_23, /**< MC60 - Pin 33, MC20 - Pin 34 */
	GPIO_24, /**< Pin 24 */
	GPIO_25, /**< Pin 25 */
	GPIO_26, /**< Pin 30 */
	GPIO_27, /**< Pin 29 */
	GPIO_28, /**< Pin 19 */
	GPIO_29, /**< Pin 21 */
	GPIO_30, /**< Pin 20 */
	GPIO_31, /**< Pin 28 */
#endif
	GPIO_PIN_MAX,
};

#endif /* INCLUDE_PLAT_DEF_GPIO_H_ */
