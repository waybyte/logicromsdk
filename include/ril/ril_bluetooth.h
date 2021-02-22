/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of Quectel Co., Ltd. 2015
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ril_bluetooth.h 
 *
 * Project:
 * --------
 *   OpenCPU
 *
 * Description:
 * ------------
 *   The API functions defined in this file are used for managing Bluetooth 
 *   devices and services. 
 *
 * Author:
 * -------
 * -------
 *  Designed by     :   Stanley YONG
 *  Coded    by     :   Stanley YONG
 *  Tested   by     :   

 *  
 *============================================================================
 *             HISTORY
 *----------------------------------------------------------------------------
 * 
 ****************************************************************************/
#ifndef __RIL_BLUETOOTH_H__
#define __RIL_BLUETOOTH_H__

#include "../../include/ril/ril.h"

#define   BT_OFF  (0)
#define   BT_ON   (1)
#define   BT_NAME_LEN       56 /* 18 * 3 + 2 */
#define   BT_ADDR_LEN       13
#define   BT_PIN_LEN        7
#define   MAX_BT_DEV_CNT    30
#define   MAX_BT_SCAN_CNT   20
#define   MAX_BT_SCAN_COD   255
#define   MAX_BT_SCAN_TIMEOUT   255
#define   MAX_BT_PAIRED_CNT 10




// SPP connection mode
typedef enum{
    BT_SPP_CONN_MODE_AT = 0,    // AT command mode
    BT_SPP_CONN_MODE_BUF,       // Buffer Access Mode (default mode)
    BT_SPP_CONN_MODE_TRANS      // Transparent Access Mode
}Enum_BT_SPP_ConnMode;

// Bluetooth profile Id
typedef enum{
    BT_PROFILE_SPP = 0,
    BT_PROFILE_OBEX_PBA_CLIENT,
    BT_PROFILE_OBEX_PBA_PROFILE,
    BT_PROFILE_OBEX_OBJECT_PUSH_SERVICE,
    BT_PROFILE_OBEX_OBJECT_PUSH_CLIENT,
    BT_PROFILE_HF_PROFILE,
    BT_PROFILE_HFG_PROFILE,
    BT_PROFILE_END
}Enum_BTProfileId;


typedef enum{
    BT_INVISIBLE= 0,
    BT_VISIBLE_FOREVER,
    BT_VISIBLE_TIMEOUT,
    BT_VISIBLE_END

}Enum_VisibleMode;


// Definitions for Bluetooth device status
typedef enum{ 
    BT_STATUS_INITIAL,    // 0 Initial on
    BT_STATUS_DEACTIVATING,   // 1 Deactivating
    BT_STATUS_ACTIVATING, // 2 Activating
    BT_STATUS_IDLE = 5, // 5 Idle
    BT_STATUS_SCANNING,   //6 Scanning
    BT_STATUS_SCANRESINDICATE,// 7 Scan result indicate
    BT_STATUS_CANCELSCAN,  // 8 Scan cancelling
    BT_STATUS_INITPAIRING, // 9 Initiate pairing
    BT_STATUS_CONNECTING = 12, //12 Connecting
    BT_STATUS_UNPAIRING,  // 13 Un-pairing
    BT_STATUS_DELPAIRED,  // 14 Deleting paired device
    BT_STATUS_DELALL,    // 15 Deleting all
    BT_STATUS_DISCONNECT,  // 16 Disconnecting
    BT_STATUS_NUMERICCONFIRM = 19,   //19 Numeric Confirm
    BT_STATUS_NUMERICCONFIRMRSP,  //20 Numeric Confirm Response
    BT_STATUS_CONACCEPTCONFIRMIND = 25, //25  connect accept confirm indication
    BT_STATUS_SERVICEREFRESHING, //26 service refreshing
    BT_STATUS_DEVICENAMESET, //29 device name setting
    BT_STATUS_AUTHSET,//30 authentication setting
    BT_STATUS_RELEASEALLCONN,//31 release all connection
    BT_STATUS_ACTIVATEPROFILE = 36 ,//activating profiles
    DEV_STATE_END
}Enum_BTDevStatus;

typedef enum{
    MSG_NONE = 0,
    MSG_BT_SCAN_IND,        // Scanning indication
    MSG_BT_PAIR_IND,
    MSG_BT_PAIR_CNF_IND,
    MSG_BT_RECV_IND,
    
    MSG_BT_PAIR_REQ,
    MSG_BT_CONN_REQ,
    MSG_BT_DISCONN_IND,

    MSG_BT_SPP_CONN_IND,
	MSG_BT_SPP_CONNACPT_IND,
    MSG_BT_VISIBLE_IND,
    
}Enum_BTMsg;


/* Bluetooth device address struct */
typedef struct
{
    u32 lap;    /* Lower Address Part 00..23 */
    u8  uap;    /* upper Address Part 24..31 */
    u16 nap;    /* Non-significant    32..47 */
} ST_BT_Addr;


typedef unsigned int BT_DEV_HDL;

typedef struct{
    BT_DEV_HDL devHdl;
    char name[BT_NAME_LEN];
    char addr[BT_ADDR_LEN];
}ST_BT_BasicInfo;

// for internal use
typedef struct{
    ST_BT_BasicInfo btDevice;
    s32 devId;  
    s32 pairId;     // -1, not paired
    s32 connId;     // -1, not connected
    s32 profileId;  //-1,no profile
    s32 reserved;
}ST_BT_DevInfo;

typedef enum{
    BT_ERROR_NONE = 0,
    BT_ERROR_VISIBLE_TIMEOUT,
    BT_ERROR_SCAN,
    BT_ERROR_END
}Enum_BT_ErrorCode;


typedef enum{
    URC_BT_NONE = 0,
    URC_BT_INVISIBLE,
    URC_BT_SCAN_FINISHED,
    URC_BT_SCAN_FOUND,
    URC_BT_NEED_PASSKEY,
    URC_BT_NO_NEED_PASSKEY,
    URC_BT_PAIR_CNF_SUCCESS,
    URC_BT_PAIR_CNF_FAIL,
    URC_BT_CONN_SUCCESS,
    URC_BT_CONN_FAIL,
    URC_BT_CONN_REQ,
    URC_BT_DISCONNECT_PASSIVE,
    URC_BT_DISCONNECT_POSITIVE,
    URC_BT_DATA_RECIEVE,
    URC_BT_END
}Enum_BT_URCCode;









typedef void (*CALLBACK_BT_IND)(s32 event, s32 errCode, void* param1, void* param2); 

//below apis can be used to manage the table
s32 BT_DevMngmt_GetDeviceId(const u32 hdl);
s32 BT_DevMngmt_GetPairedId(const u32 hdl);
s32 BT_DevMngmt_GetConnId(const u32 hdl);
s32 BT_DevMngmt_GetProfileId(const u32 hdl);
char * BT_DevMngmt_GetDevName(const u32 hdl);
char * BT_DevMngmt_GetDevAddr(const u32 hdl);












/*****************************************************************
* Function:     RIL_BT_Switch
* 
* Description:
*               Turn on /off bluetooth
*
* Parameters:
*               on_off [in] :  0 --- off ,1 ----- on
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_Switch(u8 on_off);

/*****************************************************************
* Function:     RIL_BT_GetPwrState
* 
* Description:
*               query current bluetooth power state
*
* Parameters:
*               p_on_off [out] :  0 --- off ,1 ----- on
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_GetPwrState(s32 *p_on_off);


/*****************************************************************
* Function:     RIL_BT_Initialize
* 
* Description:
*               bluetooth initialization after power on ,register callback and update paired info
*
* Parameters:
*               cb: callback to be registered
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_Initialize(CALLBACK_BT_IND cb);



/*****************************************************************
* Function:     RIL_BT_SetName
* 
* Description:
*               set the name of bluetooth
*
* Parameters:
*               name [in] :  bluetooth name to set
*               len  [in] :  length of bluetooth name,max length 56 bytes
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_SetName(char *name,u8 len);


/*****************************************************************
* Function:     RIL_BT_GetName
* 
* Description:
*               get the name of bluetooth
*
* Parameters:
*               name    [out] :  bluetooth name to get
                len     [in]  :  sizeof of param 1
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_GetName(char *name/*char addr[BT_NAME_LEN]*/,u8 len);






/*****************************************************************
* Function:     RIL_BT_GetLocalAddr
* 
* Description:
*               get the device address of bluetooth
*
* Parameters:
*               ptrAddr    [out] :  bluetooth addr to get ,length is fixed 13 bytes including '\0'
                len        [in]  :  sizeof param 1
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/

s32 RIL_BT_GetLocalAddr(char* ptrAddr/*char addr[BT_ADDR_LEN]*/,u8 len);




/*****************************************************************
* Function:     RIL_BT_SetVisble
* 
* Description:
*               set the bluetooth to be viewed or not
*
* Parameters:
*               mode    [in] : visible mode 0 :invisble 1: visible forever 2.visibility temporary on ,see Enum_VisibleMode
*               timeout [in] : when mode is set to 2 ,this param decide during which time bluetooth can be found by others
*                              unit second,can be 1-255 ,after timout ,MSG_BT_INVISIBLE will be triggered,other mode is ignored
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/

s32 RIL_BT_SetVisble(Enum_VisibleMode mode,u8 timeout);



/*****************************************************************
* Function:     RIL_BT_GetVisble
* 
* Description:
*               get the current bluetooth visble mode
*
* Parameters:
*               mode    [out] : visible mode 0 :invisble 1: visible forever 2.visibility temporary on ,see Enum_VisibleMode
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/

s32 RIL_BT_GetVisble(s32 *mode);





/*****************************************************************
* Function:     RIL_BT_StartScan
* 
* Description:
*               start scan the around bt devices
*
* Parameters:
*              
*               @maxDevCount: 0-20, default 20
*               @CoD: 0-255, default 0
*               @timeout: unit in second. 1-255, default 60s
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/

s32 RIL_BT_StartScan(u16 maxDevCount, u16 CoD, u16 timeout);


/*****************************************************************
* Function:     RIL_BT_GetDevListInfo
* 
* Description:
*               get current bt devices info

                ADDR    DEVID    HANDLER    PAIRID   CONNID   PROFILE  NAME
*
* Parameters:
*              
*              void
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/

s32 RIL_BT_GetDevListInfo(void);


/*****************************************************************
* Function:     RIL_BT_GetDevListPointer
* 
* Description:
*               get the dev list pointer ,then you can use it to get items of the list
                before you use the pointer ,RIL_BT_GetDevListInfo can help you see valid
                items to operate
*
* Parameters:
*              
*              void
* Return:        
*               the pointer to dev list
                ST_BT_DevInfo ** ptr;
                ptr = RIL_BT_GetDevListPointer();
                ptr[i]->btDevice.devHdl

*****************************************************************/

ST_BT_DevInfo ** RIL_BT_GetDevListPointer(void);


/*****************************************************************
* Function:     RIL_BT_StopScan
* 
* Description:
*               stop the scan process
*
* Parameters:
*               void
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_StopScan(void);


/*****************************************************************
* Function:     RIL_BT_QueryState
* 
* Description:
*               query current bluetooth state and update paired items
*
* Parameters:
*               status [out] : current BT status see Enum_BTDevStatus
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_QueryState(s32 *status);



/*****************************************************************
* Function:     RIL_BT_PairReq
* 
* Description:
*               request to pair a bt device ,for paired items ,ignore this step ,directly to connect
*
* Parameters:
*               hdlDevice :[in]  the bt handler to pair
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_PairReq(BT_DEV_HDL hdlDevice);



/*****************************************************************
* Function:     RIL_BT_PairConfirm
* 
* Description:
*               confirm to pair 
*
* Parameters:
*               accept :[in]  whether to accpect the pair request--- 0 :reject 1:accept
*               pincode :[in]  the passkey used to pair
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_PairConfirm(u8 accept, char* pinCode);




/*****************************************************************
* Function:     RIL_BT_Unpair
* 
* Description:
*               unpair a paired bt device
*
* Parameters:
*               hdlDevice :[in]  the bt handler to unpair
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_Unpair(BT_DEV_HDL hdlDevice);



/*****************************************************************
* Function:     RIL_BT_GetSupportedProfile
* 
* Description:
*               returns the profiles suppoerted both by the local device and the other side device,for paired items
*
* Parameters:
*               hdlDevice :[in]  the bt handler to get support profile
                profile_support :[out] the supported profile get for both sides ,see Enum_BTProfileId
                len :[in] the array length
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_GetSupportedProfile(BT_DEV_HDL hdlDevice,s32 *profile_support,u8 len);





/*****************************************************************
* Function:     RIL_BT_ConnReq
* 
* Description:
*               request to connect a paired bt device
*
* Parameters:
*               hdlDevice :[in]  the bt handler to connect
*               profileId :[in]  profile type when connect ,see Enum_BTProfileId
*               mode      :[in]  connect type ,see Enum_BT_SPP_ConnMode
*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_ConnReq(BT_DEV_HDL hdlDevice, u8 profileId, u8 mode);


/*****************************************************************
* Function:     RIL_BT_SPP_DirectConn
* 
* Description:
*               use addr to make a direct connect ,so you don't need to scan or concern the paring process
*               only support SPP connection
*
* Parameters:
*               btMacAddr :[in]  the bt addr to connect
*               mode      :[in]  connect type ,see Enum_BT_SPP_ConnMode
*               pinCode :  [in]  pairkey

*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_SPP_DirectConn(char* btMacAddr, u8 mode, char* pinCode);


/*****************************************************************
* Function:     RIL_BT_ConnAccept
* 
* Description:
*               accept to connect
*
* Parameters:
*               accept      :[in]  0--reject 1---accept
                mode        :[in]  connect type ,see Enum_BT_SPP_ConnMode

*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_ConnAccept(u8 accept , u8 mode);


/*****************************************************************
* Function:     RIL_BT_Disconnect
* 
* Description:
*               disconnect a bt connection
*
* Parameters:
*               hdlDevice :[in]  the handler to disconnect

*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_Disconnect(BT_DEV_HDL hdlDevice);


/*****************************************************************
* Function:     RIL_BT_SPP_Send
* 
* Description:
*               send data in SPP mode
*
* Parameters:
*               hdlDevice :[in]  the handler to send
                ptrData   :[in]  the ptr to data to be sent
                lenToSend :[in]  the length of data to be sent

*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
    s32 RIL_BT_SPP_Send(BT_DEV_HDL hdlDevice, u8* ptrData, u32 lenToSend,u32* actualSend);



/*****************************************************************
* Function:     RIL_BT_SPP_Read
* 
* Description:
*               read data in SPP mode
*
* Parameters:
*               hdlDevice :[in]  the handler to read
                ptrBuffer   :[in]  the ptr to store the readed data
                lenToRead :[in]  the length of data to read
                actualReadlen: [out] the actually length readed

*
* Return:        
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*****************************************************************/
s32 RIL_BT_SPP_Read(BT_DEV_HDL hdlDevice, u8* ptrBuffer, u32 lenToRead ,u32 *actualReadlen);


const char *pf_name[BT_PROFILE_END + 1];

#endif	//__RIL_BLUETOOTH_H__

