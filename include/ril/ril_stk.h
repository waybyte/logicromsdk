/*
 * ril_stk.h
 *
 */

#ifndef INC_RIL_STK_H_
#define INC_RIL_STK_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get SIM toolkit status
 * @return		0 if disabled, 1 if enabled
 */
int stk_status(void);

/**
 * Enable/Disable SIM toolkit
 * @return		RIL return code @ref ril_rc_e
 */
int stk_enable(void);

/**
 * Send envelope command (AT+STKENV)
 * @param env	Envelope data as null terminated string
 * @return		RIL return code @ref ril_rc_e
 */
int stk_send_envelope(const char *env);

/**
 * Send STK response (AT+STKR)
 * @param resp	Response data as null terminated string
 * @return		RIL return code @ref ril_rc_e
 */
int stk_send_response(const char *resp);

#ifdef __cplusplus
}
#endif

#endif /* INC_RIL_STK_H_ */
