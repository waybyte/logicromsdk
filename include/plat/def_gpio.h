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
#elif defined(PLATFORM_MC60)
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
#else /* RDA8910 */
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 61
	 * EC200  | 27
	 * N58    | 50
	 * N716   | 99
	 * L610   | 27
	 */
	GPIO_0,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 58
	 * EC200  | 26
	 * N58    | 90
	 * N716   | 100
	 * L610   | 26
	 */
	GPIO_1,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 59
	 * EC200  | 24
	 * N58    | 80
	 * N716   | 101
	 * L610   | 24
	 */
	GPIO_2,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 60
	 * EC200  | 25
	 * N58    | 78
	 * N716   | 102
	 * L610   | 25
	 */
	GPIO_3,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 69
	 * EC200  | 13
	 * N58    | 96
	 * N716   | 54
	 * L610   | 13
	 */
	GPIO_4,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 70
	 * EC200  | 135
	 * N58    | 39
	 * N716   | 38
	 * L610   | 135
	 */
	GPIO_5,
	GPIO_6, /**< Unavailable on any module */
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 118
	 * EC200  | 133
	 * N58    | 25
	 * N716   | 89
	 * L610   | 133
	 */
	GPIO_7,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 99
	 * EC200  | 134
	 * N58    | NA
	 * N716   | NA
	 * L610   | 134
	 */
	GPIO_8,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 98
	 * EC200  | 132
	 * N58    | 2
	 * N716   | 45
	 * L610   | 132
	 */
	GPIO_9,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 95
	 * EC200  | 131
	 * N58    | 79
	 * N716   | 32
	 * L610   | 131
	 */
	GPIO_10,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 119
	 * EC200  | 130
	 * N58    | 83
	 * N716   | 21
	 * L610   | 130
	 */
	GPIO_11,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 100
	 * EC200  | 129
	 * N58    | 13
	 * N716   | 22
	 * L610  | 129
	 */
	GPIO_12,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 54
	 * EC200  | 5
	 * N58    | NA
	 * N716   | 67
	 * L610   | 5
	 */
	GPIO_13,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 57
	 * EC200  | 141
	 * N58    | 82
	 * N716   | 71
	 * L610   | 141
	 */
	GPIO_14,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 56
	 * EC200  | 142
	 * N58    | 81
	 * N716   | 70
	 * L610   | 142
	 */
	GPIO_15,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 11
	 * EC200  | 41
	 * N58    | 59
	 * N716   | 122
	 * L610   | 41
	 */
	GPIO_16,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 12
	 * EC200  | 42
	 * N58    | 58
	 * N716   | 121
	 * L610   | 42
	 */
	GPIO_17,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 120
	 * EC200  | 61
	 * N58    | 54
	 * N716   | 115
	 * L610   | 61
	 */
	GPIO_18,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 16
	 * EC200  | 62
	 * N58    | 60
	 * N716   | 65
	 * L610   | 62
	 */
	GPIO_19,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 10
	 * EC200  | 63
	 * N58    | 61
	 * N716   | 106
	 * L610   | 63
	 */
	GPIO_20,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 14
	 * EC200  | 66
	 * N58    | 55
	 * N716   | 116
	 * L610   | 66
	 */
	GPIO_21,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 15
	 * EC200  | 6
	 * N58    | 56
	 * N716   | 114
	 * L610   | 6
	 */
	GPIO_22,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 13
	 * EC200  | 23
	 * N58    | 57
	 * N716   | 117
	 * L610   | 23
	 */
	GPIO_23,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 48
	 * EC200  | 33
	 * N58    | 5
	 * N716   | 52
	 * L610   | 33
	 */
	GPIO_24,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 39
	 * EC200  | 31
	 * N58    | 7
	 * N716   | 47
	 * L610   | 31
	 */
	GPIO_25,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 40
	 * EC200  | 30
	 * N58    | 8
	 * N716   | 48
	 * L610   | 30
	 */
	GPIO_26,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 49
	 * EC200  | 29
	 * N58    | 3
	 * N716   | 50
	 * L610   | 29
	 */
	GPIO_27,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 50
	 * EC200  | 28
	 * N58    | 4
	 * N716   | 51
	 * L610   | 28
	 */
	GPIO_28,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 53
	 * EC200  | 1
	 * N58    | 23
	 * N716   | 87
	 * L610   | 1
	 */
	GPIO_29,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 52
	 * EC200  | 2
	 * N58    | 22
	 * N716   | 86
	 * L610   | 2
	 */
	GPIO_30,
	/**
	 * Module | Pin
	 * ------------
	 * EC600  | 51
	 * EC200  | 4
	 * N58    | 24
	 * N716   | 88
	 * L610   | 4
	 */
	GPIO_31,
#endif
	GPIO_PIN_MAX,
};

#endif /* INCLUDE_PLAT_DEF_GPIO_H_ */
