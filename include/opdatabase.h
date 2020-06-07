/*
 * opdatabase.h
 *
 */

#ifndef INCLUDE_OPDATABASE_H_
#define INCLUDE_OPDATABASE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get Operator name
 * @param mcc		[in] Mobile country Code
 * @param mnc		[in] Mobile Network Code
 * @return			On success pointer network operator name is returned (Do not free this memory). On error empty string is returned.
 */
const char *get_opname(uint16_t mcc, uint16_t mnc);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_OPDATABASE_H_ */
