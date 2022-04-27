/*
 * arc4.h
 *
 */

#ifndef INCLUDE_CRYPTO_ARC4_H_
#define INCLUDE_CRYPTO_ARC4_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief ARC4 context structure
 */
typedef struct
{
    int x;                      /*!< permutation index */
    int y;                      /*!< permutation index */
    unsigned char m[256];       /*!< permutation table */
}
arc4_context;

/**
 * @brief          ARC4 key schedule
 *
 * @param ctx      ARC4 context to be initialized
 * @param key      the secret key
 * @param keylen   length of the key
 */
void arc4_setup( arc4_context *ctx, unsigned char *key, int keylen );

/**
 * @brief          ARC4 cipher function
 *
 * @param ctx      ARC4 context
 * @param buf      buffer to be processed
 * @param buflen   amount of data in buf
 */
void arc4_crypt( arc4_context *ctx, unsigned char *buf, int buflen );

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_CRYPTO_ARC4_H_ */
