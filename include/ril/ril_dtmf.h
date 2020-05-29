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
*   ril_dtmf.h 
*
* Project:
* --------
*   OpenCPU
*
* Description:
* ------------
*   The module defines the information, and APIs related to DTMF.
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
#ifndef __RIL_DTMF_H__
#define __RIL_DTMF_H__

#include "../../include/ril/ril.h"

/***********************************************************************
 * ENUM TYPE DEFINITIONS
************************************************************************/
typedef enum 
{
    RIL_DETThreshold_Min = 1,
    RIL_DETThreshold_100MS,     // Configure 1400Hz or 2300Hz detection threshold, duration of which is 100ms
    RIL_DETThreshold_400MS,     // Configure 1400Hz and 2300Hz 400ms detection threshold
    RIL_DETThreshold_DTMF,      // Configure DTMF detection threshold
    RIL_DETThreshold_Max = 5
} Enum_ToneDet_Mode;

typedef enum 
{
    RIL_WDTMF_VOLUME0 = 0, // uplink or downlink channel of the volume
    RIL_WDTMF_VOLUME1,
    RIL_WDTMF_VOLUME2,
    RIL_WDTMF_VOLUME3,
    RIL_WDTMF_VOLUME4,
    RIL_WDTMF_VOLUME5,
    RIL_WDTMF_VOLUME6,
    RIL_WDTMF_VOLUME7
} Enum_WDTMF_Vomume;


/****************************************************
* DTMF detection function definition         
****************************************************/
/*****************************************************************
* Function:     RIL_ToneDet_Open
* 
* Description:
*               This function is used to Open DTMF detect.
*
* Parameters:
*               cb_ToneDet_hdl:      
*                   [IN] call back function to handle DTMF detected.
*               dtmfCode:      
*                   [OUT] detected DTMF tone code corresponding ASSCII.
*               timems:      
*                   [OUT] persistence time of the tone, unit is ms.
*                             only when <dtmfCode> is 69(1400Hz) or 70(1400Hz) <timems> is available, otherwise it will always be -1.
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.                
*****************************************************************/
typedef void (* CB_ToneDet)( s32 dtmfCode, s32 timems );
s32 RIL_ToneDet_Open( CB_ToneDet cb_ToneDet_hdl );

/*****************************************************************
* Function:     RIL_ToneDet_Close
* 
* Description:
*               The function is used to close DTMF detect.
*
* Parameters:
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.                
*****************************************************************/
s32 RIL_ToneDet_Close(void);

/*****************************************************************
* Function:     RIL_ToneDet_Set
* 
* Description:
*               This function is used to set DTMF detection.
*
* Parameters:
*                <mode>:
*                       [IN] 2-4, select which threshold to set.
*                <pause>:
*                       [IN] prefix pause number.
*                <low>:
*                       [IN] low threshold value.
*                <high>:
*                       [IN] high threshold value.
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.                            
*****************************************************************/
s32 RIL_ToneDet_Set( Enum_ToneDet_Mode mode, u32 pause, u32 low, u32 high );

/*****************************************************************
* Function:     RIL_ToneDet_Get
* 
* Description:
*               This function is used to get settings of DTMF detection.
*
* Parameters:
*                <mode>:
*                       [IN] 2-4, select which threshold to get.
*                <low>:
*                       [IN] low threshold value.
*                <high>:
*                       [IN] high threshold value.
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.                              
*****************************************************************/
s32 RIL_ToneDet_Get( Enum_ToneDet_Mode mode, u32 *low, u32 *high );

/****************************************************
* DTMF send  functions definition        
****************************************************/
/*****************************************************************
* Function:     RIL_WDTMF_Send
* 
* Description:
*               This function is used to play DTMF tone during the call.
*
* Parameters:
*                ul_volume:
*                     [IN] 0-7, uplink channel of the volume.
*                dl_volume:
*                     [IN] 0-7, downlink channel of the volume, recommended to be set as 0.
*                dtmfStr:
*                     [IN] this string consists of DTMF tone strings, Duration of each DTMF tone(unit is ms) and Mute time (unit is ms).
*                              example:  "0A5,50,50,3,100,50"-->0A5 is DTMF tone strings, continuancetime 50ms, mute time 50ms;
*                                               The rest of the three Numbers is the same meaning as before. the total lenth of dtmfStr must be less than 400.
*                cb_WDTMF_hdl:
*                     [IN] callback function for QWDTMF URC handle.
*                result:
*                     [OUT] Indicate status of sending DTMF. 
*                                If <result> is 5, it means sending DTMF successfully;
*                                If <result> is not 5, it means sending DTMF unsuccessfully;
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.               
*****************************************************************/
typedef void (* CB_WDTMF)( s32 result );
s32 RIL_WDTMF_Send( Enum_WDTMF_Vomume ul_volume, Enum_WDTMF_Vomume dl_volume, u8 *dtmfStr, CB_WDTMF cb_WDTMF_hdl );


#endif  //__RIL_DTMF_H__

