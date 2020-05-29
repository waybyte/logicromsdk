/*
 * des.h
 *
 */

#ifndef INCLUDE_CRYPTO_DES_H_
#define INCLUDE_CRYPTO_DES_H_

/**
 * @name op_mode
 */
#define DES_ENCRYPT     1
#define DES_DECRYPT     0

/**
 * @brief          DES context structure
 */
typedef struct
{
    int mode;                   /*!<  encrypt/decrypt   */
    unsigned long sk[32];       /*!<  DES subkeys       */
}
des_context;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief          DES key schedule (56-bit, encryption)
 *
 * @param ctx      DES context to be initialized
 * @param key      8-byte secret key
 */
void des_setkey_enc( des_context *ctx, unsigned char key[8] );

/**
 * \brief          DES key schedule (56-bit, decryption)
 *
 * @param ctx      DES context to be initialized
 * @param key      8-byte secret key
 */
void des_setkey_dec( des_context *ctx, unsigned char key[8] );

/**
 * @brief          DES-ECB block encryption/decryption
 *
 * @param ctx      DES context
 * @param input    64-bit input block
 * @param output   64-bit output block
 */
void des_crypt_ecb( des_context *ctx,
                    const unsigned char input[8],
                    unsigned char output[8] );

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_CRYPTO_DES_H_ */
