/*
 * sha.h
 *
 */

#ifndef INCLUDE_CRYPTO_SHA_H_
#define INCLUDE_CRYPTO_SHA_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Calculate SHA1 hash
 * @param input		[in] Input data buffer
 * @param ilen		[in] Input data length
 * @param output	[out] Output buffer to store SHA1 hash
 */
void sha1(const unsigned char *input, int ilen, unsigned char output[20]);

/**
 * @brief Calculate sha256 hash
 * 
 * @param input [in] Input data buffer
 * @param ilen [in] Input data length
 * @param output [out] Output buffer to store hash
 */
void sha256(const unsigned char *input, int ilen, unsigned char output[32]);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_CRYPTO_SHA_H_ */
