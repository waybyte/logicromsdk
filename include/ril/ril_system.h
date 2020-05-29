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
 *   ril_system.h 
 *
 * Project:
 * --------
 *   OpenCPU
 *
 * Description:
 * ------------
 *   The file is for OpenCPU RIL sytem definitions and APIs.
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
#ifndef __RIL_SYSTEM_H__
#define __RIL_SYSTEM_H__

#include "../../include/ril/ril.h"

typedef struct
{
    s32 capacity;
    s32 voltage;
}ST_SysPower;

/*****************************************************************
* Function:     RIL_QuerySysInitStatus 
* 
* Description:
*               Queries the initializing status of module.
*
* Parameters:       
*               SysInitStatus
*                   [Out] system init status.
*               0/1/2/3, the init status value, one value of "Enum_SysInitState".
*               Please refer to "AT+QINISTAT" in ATC document for the meanings.
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.
*****************************************************************/
s32 RIL_QuerySysInitStatus(s32* SysInitStatus);

/*****************************************************************
* Function:     RIL_GetPowerSupply 
* 
* Description:
*               This function queries the battery balance, and the battery voltage.
*
* Parameters:
*               capacity:      
*                   [out] battery balance, a percent, ranges from 1 to 100.
*
*               voltage:       
*                   [out] battery voltage, unit in mV
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.
*****************************************************************/
s32 RIL_GetPowerSupply(u32* capacity, u32* voltage);

/*****************************************************************
* Function:     ril_store_securedata
* 
* Description:
*              This function can be used to store some critical user data 
*              to prevent them from losing.
*
*              Note:
*              1.
*              OpenCPU has designed 13 blocks of system storage space to 
*              backup critical user data. Developer may specify the first
*              parameter index [1-13] to specify different storage block. 
*              Among the storage blocks, 1~8 blocks can store 50 bytes for 
*              each block, 9~12 blocks can store 100 bytes for each block, 
*              and the 13th block can store 500 bytes.
*
*              2.
*              User should not call this API function frequently, which is not
*              good for life cycle of flash.
*
* Parameters:
*              index:
*               [in]  the index of the secure data block. The range is: 1~13.
*              
*               pData: 
*                   [in] The data to be backed up. In 1~8 groups, every group can 
*                   save 50 bytes at most. In 9~12 groups, every group can save 
*                   100 bytes at most. If index is 13, the user data can save 500 bytes at most.
*
*               len:
*                   [in] The length of the user data. When the index is (1~8), 
*                   then len<=50. When the index is (9~12), then len<=100. 
*                   When the index is 13, then len<=500.
* Return:        
*               QL_RET_OK, this function succeeds.
*               QL_RET_ERR_PARAM, invalid paramter.
*               QL_RET_ERR_GET_MEM, the heap memory is no enough.
*               ......
*****************************************************************/
s32 ril_store_securedata(u8 index , u8* pData, u32 len);

/*****************************************************************
* Function:     ril_read_securedata
* 
* Description:
*              This functin reads secure data which is previously 
*              stored by Ql_SecureData_Store.
* Parameters:
*               index:
*                   [in] The index of the secure data block. The range is: 1~13.
*
*               len:
*                   [in] The length of the user data. When the index is (1~8), 
*                   then len<=50. When the index is (9~12), then len<=100. 
*                   When the index is 13, then len<=500.
* Return:        
*               If this function succeeds, the real read length is returned.
*               QL_RET_ERR_PARAM, invalid paramter.
*               QL_RET_ERR_GET_MEM, the heap memory is no enough.
*               Ql_RET_ERR_UNKOWN, unknown error.
*****************************************************************/
s32 ril_read_securedata(u8 index, u8* pBuffer, u32 len);

/*****************************************************************
* Function:     RIL_GetIMEI 
* 
* Description:
*               Retrieves the IMEI number of module.
*
* Parameters:       
*               imei:
*                   [Out] buffer to store the imei number. The length 
*                         of buffer should be at least 15-byte.
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.
*****************************************************************/
s32 RIL_GetIMEI(char* imei);

#endif  //__RIL_SYSTEM_H__

