/*
 * aes.h
 *
 */

#ifndef INCLUDE_CRYPTO_AES_H_
#define INCLUDE_CRYPTO_AES_H_

#include <stdint.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * AES block decrypt
 * @param out		[out] Output buffer to store decrypted data
 * @param in		[in] Input buffer containing encrypted data
 * @param inSz		[in] Size of data in input buffer
 * @param key		[in] Key buffer
 * @param iv		[in] IV buffer
 * @return			0 on success, negative value on error
 */
int aes_cbc_decrypt(uint8_t* out, const uint8_t* in, size_t inSz,
		const uint8_t* key, uint8_t* iv);

/**
 * Encrypt a data buffer
 * @param out		[out] Output buffer to store encrypted data
 * @param in		[in] Input data buffer
 * @param inSz		[in] Size of input data
 * @param key		[in] Key buffer
 * @param iv		[in] IV buffer
 * @return			0 on success, negative value on error
 */
int aes_cbc_encrypt(uint8_t* out, const uint8_t* in, size_t inSz,
		const uint8_t* key, uint8_t* iv);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_CRYPTO_AES_H_ */
