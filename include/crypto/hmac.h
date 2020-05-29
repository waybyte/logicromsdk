/*
 * hmac.h
 *
 */

#ifndef INCLUDE_CRYPTO_HMAC_H_
#define INCLUDE_CRYPTO_HMAC_H_

#ifdef __cpluplus
extern "C" {
#endif

/**
 * Calculate HMAC-SHA256 Hash
 * @param key		[in] Input key
 * @param keySz		[in] Key size
 * @param data		[in] Data buffer
 * @param dlen		[in] Data length
 * @param hash		[out] Output hash buffer
 * @return			0 on success, negative value on error
 */
int HmacSHA256_encode(const unsigned char* key, unsigned int keySz,
		const unsigned char *data, unsigned int dlen, unsigned char hash[32]);

#ifdef __cpluplus
}
#endif

#endif /* INCLUDE_CRYPTO_HMAC_H_ */
