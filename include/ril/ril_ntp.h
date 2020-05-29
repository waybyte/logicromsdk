/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of Quectel Co., Ltd. 2014
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ril_ntp.h 
 *
 * Project:
 * --------
 *   OpenCPU
 *
 * Description:
 * ------------
 *   The module implements NTP related APIs.
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
#ifndef __RIL_NTP_H__
#define __RIL_NTP_H__
	 
#include "../../include/ril/ril.h"

/*****************************************************************
* Function:     RIL_NTP_START
* 
* Description:
*               This function is used to synchronize time with NTP server.
*
* Parameters:	
*				<server_addr> :  [IN] point to the string which indicates NTP server address.
*				<server_port>: 	 [IN] the NTP server port.
*				<cb_NTPCMD_hdl>: [IN] callback function for NTP URC handle.
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.               
*****************************************************************/
typedef void (* CB_NTPCMD)(const char *strURC);
s32 RIL_NTP_START(u8 *server_addr, u16 server_port, CB_NTPCMD cb_NTPCMD_hdl);

#endif //__RIL_NTP_H__

