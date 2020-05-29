/*
 * ril_qeng.h
 *
 *  Created on: May 28, 2018
 *      Author: ajay_
 */

#ifndef SRC_LIB_RIL_INC_RIL_QENG_H_
#define SRC_LIB_RIL_INC_RIL_QENG_H_

#include "../../include/ril/ril.h"

/**
 * Cell information structure
 */
struct _cellinfo_t {
	u16 mcc;		/**< Mobile country code */
	u16 mnc;		/**< Mobile network code */
	u16 lac;		/**< Location area code */
	u16 cellid;		/**< Cell ID */
	u16 bcch;		/**< Absolute Radio Frequency Channel Number o of Broadcast Cont rol Channel */
	u16 bsic;		/**< Base station identity code */
	int dbm;		/**< Receive signal level in d dBm unit */
	u16 c1;			/**< C1 value */
	u16 c2;			/**< C2 value */
};

/**
 * Serving and Neighboring cell information structure
 */
struct cellinfo_t {
	struct _cellinfo_t cell;		/**< Serving cell information */
	int ncell_count;				/**< Number of neighboring cell site (max 6) */
	struct _cellinfo_t ncell[6];	/**< Information of each cell site */
};

/**
 * Start capturing cell information
 * @return		0 on success, negative value on error @ref ril_rc_e
 */
s32 RIL_QENG_Start(void);

/**
 * Stop cell information capture
 * @return		0 on success, negative value on error @ref ril_rc_e
 */
s32 RIL_QENG_Stop(void);

/**
 * Get current cell information
 * @param cellinfo		[out] Cell information structure @ref cellinfo_t
 * @param timeout		[in] Timeout for operation in milliseconds
 * @return				0 on success, negative value on error @ref ril_rc_e
 */
s32 RIL_QENG_GetCellinfo(struct cellinfo_t *cellinfo, int timeout);

#endif /* SRC_LIB_RIL_INC_RIL_QENG_H_ */
