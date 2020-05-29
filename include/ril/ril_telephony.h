/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of Quectel Co., Ltd. 2013
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ril_telephony.h 
 *
 * Project:
 * --------
 *   OpenCPU
 *
 * Description:
 * ------------
 *   The file is for telephony. All APIs depend on OpenCPU RIL feature.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 *----------------------------------------------------------------------------
 * 
 ****************************************************************************/
#ifndef __RIL_TELEPHONY_H__
#define __RIL_TELEPHONY_H__

#include "../../include/ril/ril.h"

/******************************************************************************
* Function:     RIL_Telephony_Dial
*  
* Description:
*               This function dials the specified phone number, only support voice call.
*
* Parameters:    
*               type:
*                   [In] Must be 0 , just support voice call.
*               phoneNumber:
*                   [In] Phone number, null-terminated string.
*               result:
*                   [Out] Result for dial, one value of Enum_CallState.
*
* Return:  
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.
******************************************************************************/
s32 RIL_Telephony_Dial(u8 type, char* phoneNumber, s32* result);

/******************************************************************************
* Function:     RIL_Telephony_Dial
*  
* Description:
*               This function answers a coming call.
*
* Parameters:    
*               result:
*                   [Out] Delete flag , which is one value of 'Enum_SMSDeleteFlag'.
*
* Return:  
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.
******************************************************************************/
s32 RIL_Telephony_Answer(s32 *result);

/******************************************************************************
* Function:     RIL_Telephony_Dial
*  
* Description:
*               This function answers a call.
*
* Parameters:    
*               None
*
* Return:  
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.
******************************************************************************/
s32 RIL_Telephony_Hangup(void);

#endif
