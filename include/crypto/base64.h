/*
 * base64.h
 *
 */

#ifndef INCLUDE_CRYPTO_BASE64_H_
#define INCLUDE_CRYPTO_BASE64_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * BASE64 Encode a buffer
 * @param input		[in] Input buffer
 * @param inlen		[in] Size of data in input buffer
 * @param output	[out] Output buffer to store encoded data
 * @param outsize	[in] size of output buffer
 * @return			On success, this function returns size of encoded data, and negative value on error
 */
int base64_encode(const unsigned char* input, int inlen, unsigned char *output, int outsize);

/**
 * BASE64 decode
 * @param input		[in] Input encoded data
 * @param inlen		[in] Length of input data
 * @param output	[out] Output buffer to store decoded data
 * @param outsize	[in] Size of output buffer
 * @return			On success, this function returns size of encoded data, and negative value on error
 */
int base64_decode(const unsigned char* input, int inlen, unsigned char *output, int outsize);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_CRYPTO_BASE64_H_ */
