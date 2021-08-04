/*
 * md5.h
 *
 */

#ifndef INCLUDE_CRYPTO_MD5_H_
#define INCLUDE_CRYPTO_MD5_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Calculate MD5 Checksum
 * @param input			[in] Input data
 * @param ilen			[in] Length of input data
 * @param output		[out] Output buffer to store md5 hash
 */
void md5_hash(const void *input, int ilen, unsigned char output[16]);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_CRYPTO_MD5_H_ */
