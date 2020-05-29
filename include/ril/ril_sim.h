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
 *   ril_network.h 
 *
 * Project:
 * --------
 *   OpenCPU
 *
 * Description:
 * ------------
 *   The file declares some API functions, which are related to SIM card, including
 *   SIM state, IMSI and CCID.
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
#ifndef __RIL_SIM_H__
#define __RIL_SIM_H__

#include "../../include/ril/ril.h"

/******************************************************************************
* Function:     RIL_SIM_GetSimState
*  
* Description:
*                This function gets the state of SIM card. 
*
* Related AT:
*               "AT+CPIN?".
*
* Parameters:    
*               stat:
*                   [out]SIM card State code, one value of Enum_SIMState.
* Return:  
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
******************************************************************************/
s32 RIL_SIM_GetSimState(s32* state);

/******************************************************************************
* Function:     RIL_SIM_GetIMSI
*  
* Description:
*               This function gets the state of SIM card. 
*
* Related AT:
*               "AT+CIMI".
*
* Parameters:    
*               imsi:
*                   [out]IMSI number, a string of 15-byte.
* Return:  
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
******************************************************************************/
s32 RIL_SIM_GetIMSI(char* imsi);

/******************************************************************************
* Function:     RIL_SIM_GetCCID
*  
* Description:
*               This function gets the CCID of SIM card. 
*
* Related AT:
*               "AT+CCID".
*
* Parameters:    
*               ccid:
*                   [out] CCID number, a string of 20-byte.
* Return:  
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
******************************************************************************/
s32 RIL_SIM_GetCCID(char* ccid);

#endif  //__RIL_SIM_H__

