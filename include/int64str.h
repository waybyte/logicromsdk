/*
 * int64str.h
 *
 */

#ifndef INCLUDE_INT64STR_H_
#define INCLUDE_INT64STR_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Convert 64-bit signed integer to string.
 * newlib-nano does not provide support for printing %lld (long long int).
 * This function can be used to convert 64-bit number to string.
 *
 * @note This function is not thread-safe. It is recommended to store the value in a different buffer to prevent overwrite.
 *
 * @param value		[in] 64-bit signed value
 * @return			Buffer pointer to converted string. This string is statically allocated, please do not free.
 */
const char *i64toa(int64_t value);

/**
 * Convert 64-bit signed integer to string.
 * newlib-nano does not provide support for printing %llu (unsigned long long int).
 * This function can be used to convert 64-bit number to string.
 *
 * @note This function is not thread-safe. It is recommended to store the value in a different buffer to prevent overwrite.
 *
 * @param value		[in] 64-bit unsigned integer
 * @return			Buffer pointer to converted string. This string is statically allocated, please do not free.
 */
const char *ui64toa(uint64_t value);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_INT64STR_H_ */
