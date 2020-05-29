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
*   ril_location.h 
*
* Project:
* --------
*   OpenCPU
*
* Description:
* ------------
*  
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
#ifndef __RIL_LOCATION_H__
#define __RIL_LOCATION_H__

#include "../../include/ril/ril.h"

// Cell info
typedef struct {
    u16 mcc;
    u16 mnc;
    u32 lac;
    s32 cellId;
    s16 rssi;
    u16 timeAd;
}ST_CellInfo;

// Location info
typedef struct{
    float longitude;
    float latitude;
    //u16 reserved;
}ST_LocInfo;

typedef void(*CB_LocInfo)(s32 result,ST_LocInfo* loc_info);

s32 RIL_GetLocation(CB_LocInfo cb_loc);
s32 RIL_GetLocation_Ex(ST_LocInfo* locinfo);
s32 RIL_GetLocationByCell(ST_CellInfo* cell, CB_LocInfo cb_loc);

#endif  //__RIL_LOCATION_H__

