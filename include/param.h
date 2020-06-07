/*
 * param.h
 *
 */

#ifndef INCLUDE_PARAM_H_
#define INCLUDE_PARAM_H_

/**
 * Shorthand macro for parameter saving
 */
#define PARAM_SAVE(x)			param_save(#x, &x, sizeof(x))

/**
 * Shorthand macro for parameter saving securely
 */
#define PARAM_SECURE_SAVE(x)	param_secure_save(#x, &x, sizeof(x))

/**
 * Shorthand macro for parameter loading
 */
#define PARAM_LOAD(x)			param_load(#x, &x, sizeof(x))

/**
 * Shorthand macro for parameter loading securely
 */
#define PARAM_SECURE_LOAD(x)	param_secure_load(#x, &x, sizeof(x))

/**
 * Shorthand macro for remove/reset a parameter
 */
#define PARAM_RESET(x)			param_reset(#x)

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Save parameter to memory
 * @param name		[in] Name of parameter must be unique
 * @param parm		[in] pointer to parameter value (data to store)
 * @param size		[in] Size of parameter
 * @return			0 on success, negative value on error
 */
int param_save(const char *name, void *parm, int size);

/**
 * Save parameter securely to memory
 * @param name		[in] Name of parameter must be unique
 * @param parm		[in] pointer to parameter value (data to store)
 * @param size		[in] size of parameter
 * @return			0 on success, negative value on error
 */
int param_secure_save(const char *name, void *parm, int size);

/**
 * Load/Read parameter from memory
 * @param name		[in] Name of parameter to read
 * @param parm		[out] pointer to buffer where read value of parameter will be stored
 * @param size		[in] size of parameter buffer
 * @return			0 on success, negative value on error
 */
int param_load(const char *name, void *parm, int size);

/**
 * Load/Read parameter securely from memory
 * @param name		[in] Name of parameter to read
 * @param parm		[out] pointer to buffer where read value of parameter will be stored
 * @param size		[in] size of parameter buffer
 * @return			0 on success, negative value on error
 */
int param_secure_load(const char *name, void *parm, int size);

/**
 * Reset a parameter. This will remove parameter from memory
 * @param name		[in] Name of parameter
 * @return			0 on success, negative value on error
 */
int param_reset(const char *name);

/**
 * Remove all parameters from memory.
 * @return			0 on success, negative value on error
 */
int param_factoryreset(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_PARAM_H_ */
