/*
 * opdatabase.h
 *
 * @note These APIs are only available on GSM & LTE Platforms
 */

#ifndef INCLUDE_OPDATABASE_H_
#define INCLUDE_OPDATABASE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PLATFORM_BC20

/**
 * Get Operator name from operator database
 * @param mcc		[in] Mobile country Code
 * @param mnc		[in] Mobile Network Code
 * @param long_name [in] Select long or short operator name, 1 for Long, 0 for short
 * @return			On success pointer network operator name is returned. On error empty string is returned.
 */
const char *opdb_get_operatorname(uint16_t mcc, uint16_t mnc, int long_name);
#endif

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_OPDATABASE_H_ */
