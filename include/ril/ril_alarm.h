/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of Quectel Co., Ltd. 2014
*
*****************************************************************************/
/**
 * File has been taken and modified from OpenCPU SDK
 * With permission from Quectel Co. Ltd.
 */
#ifndef __RIL_ALARM_H__
#define __RIL_ALARM_H__

#include "../../include/ril/ril.h"

/**
 * RIL Time structure
 */
typedef struct {
    s32 year;		/**< Year YYYY format */
    s32 month;		/**< Month 1 - 12 */
    s32 day;		/**< Day 1 - 31 */
    s32 hour;		/**< Hour 0 - 23 */
    s32 minute;		/**< Minute 0 - 59 */
    s32 second;		/**< Seconds 0 - 59 */
    s32 timezone;	/**< Timezone value in increments of a quarter of an hour, for example: 22 indicates "+5:30" */
} ST_Time;

/*****************************************************************
* Function:     RIL_Alarm_Create
* 
* Description:
*               Set and start the alarm with the specified date and time.
*
* Parameters:
*               dateTime:  [in] Pointer to the ST_Time
*               mode:[in]
*                               0: start alarm only one time.
*                               1: repeat alarm every day.
*                               2: repeat alarm every week.
*                               3: repeat alarm every month.
* Return:        
*               QL_RET_OK indicates this function successes.
*               QL_RET_ERR_PARAM indicates parameter error.
*               QL_RET_ERR_INVALID_TIMER indicates invalid timer.
*****************************************************************/
s32 RIL_Alarm_Create(ST_Time* dateTime, u8 mode);

/*****************************************************************
* Function:     RIL_Alarm_Query
* 
* Description:
*               Query the current setting of the clock alarm.
*
* Parameters:
*               dateTime:  [out] Pointer to the ST_Time
* Return:        
*               QL_RET_OK indicates this function successes.
*               QL_RET_ERR_PARAM indicates parameter error.
*               QL_RET_ERR_INVALID_TIMER indicates invalid timer.
*****************************************************************/
s32 RIL_Alarm_Query(ST_Time* dateTime);

/*****************************************************************
* Function:     RIL_Alarm_Remove
* 
* Description:
*               Remove the alarm.
*
* Parameters:
*
* Return:        
*               QL_RET_OK indicates this function successes.
*               QL_RET_ERR_PARAM indicates this function fail.
*****************************************************************/
s32 RIL_Alarm_Remove(void);

#endif	//__RIL_ALARM_H__
