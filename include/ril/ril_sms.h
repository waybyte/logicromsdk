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
 *   ril_sms.h 
 *
 * Project:
 * --------
 *   OpenCPU SDK
 *
 * Description:
 * ------------
 *   The file is for SMS RIL function. All APIs depend on OpenCPU RIL feature.
 *
 * Author:
 * -------
 * -------
 *  Designed by     :   Vicent GAO
 *  Coded    by     :   Vicent GAO
 *  Tested   by     :   Vicent GAO
 *============================================================================
 *             HISTORY
 *----------------------------------------------------------------------------
 * 2013/11/19    Vicent GAO      This file is created by ROTVG00006-P01
 * 2015/06/02    Vicent GAO      Add support for read/send con-sms by ROTVG00006-P05
 ****************************************************************************/
#ifndef __RIL_SMS_H__
#define __RIL_SMS_H__

#include "../../include/ril/ril.h"

#define LIB_SMS_PHONE_NUMBER_MAX_LEN   (20)   //Unit is: one character
#define LIB_SMS_USER_DATA_MAX_LEN      (160)  //Unit is: one character
#define LIB_SMS_PDU_BUF_MAX_LEN     (180)


/***********************************************************************
 * MACRO CONSTANT DEFINITIONS
************************************************************************/
#define SMS_MEM_CHAR_LEN  4

#define RIL_SMS_PHONE_NUMBER_MAX_LEN    (LIB_SMS_PHONE_NUMBER_MAX_LEN + 2) //It may contain '+' at the first position and will contain '\0' at the end.
#define RIL_SMS_TEXT_DATA_MAX_LEN       (4 * LIB_SMS_USER_DATA_MAX_LEN)
#define RIL_SMS_TIME_STAMP_STR_MAX_LEN  (22) //It will contain '\0' at the end.

/***********************************************************************
 * ENUM TYPE DEFINITIONS
************************************************************************/
//Warning:Please NOT-CHANGE this enum's value
typedef enum {
    RIL_SMS_STORAGE_TYPE_SM = 0,
    RIL_SMS_STORAGE_TYPE_ME = 1,
    RIL_SMS_STORAGE_TYPE_MT = 2,
} Enum_RIL_SMS_StorageType;

//Warning:Please NOT-CHANGE this enum's value
typedef enum 
{
    RIL_SMS_DEL_INDEXED_MSG = 0, /* Single message by index */
    RIL_SMS_DEL_READ_MSG = 1,         /* Already read messages */
    RIL_SMS_DEL_READ_SENT_MSG = 2,   /* Read and sent messages */
    RIL_SMS_DEL_READ_SENT_UNSENT_MSG = 3, /* Read ,sent and unsent messages */
    RIL_SMS_DEL_ALL_MSG = 4,/* All messages in current storage */
} Enum_RIL_SMS_DeleteFlag;

typedef enum
{
    RIL_SMS_STATUS_TYPE_REC_UNREAD = 0,
    RIL_SMS_STATUS_TYPE_REC_READ = 1,
    RIL_SMS_STATUS_TYPE_STO_UNSENT = 2,
    RIL_SMS_STATUS_TYPE_STO_SENT = 3,

    RIL_SMS_STATUS_TYPE_INVALID = 0xFF
} Enum_RIL_SMS_StatusType;

typedef enum
{
    LIB_SMS_PDU_TYPE_DELIVER = 0x00,
    LIB_SMS_PDU_TYPE_SUBMIT = 0x01,
    LIB_SMS_PDU_TYPE_STATUS_REPORT = 0x02,
    LIB_SMS_PDU_TYPE_RESERVED = 0x03,

    LIB_SMS_PDU_TYPE_INVALID = 0xFF,
} LIB_SMS_PDUTypeEnum;

typedef enum
{
    LIB_SMS_DCS_ALPHA_DEFAULT = 0,
    LIB_SMS_DCS_ALPHA_8BIT_DATA = 1,
    LIB_SMS_DCS_ALPHA_UCS2 = 2,

    LIB_SMS_DCS_ALPHA_INVALID = 0xFF
} LIB_SMS_DCSAlphaEnum;

/***********************************************************************
 * STRUCT TYPE DEFINITIONS
************************************************************************/
typedef struct
{
    u8 msgType;
    u16 msgRef;
    u8 msgSeg;
    u8 msgTot;
} ST_RIL_SMS_Con;

typedef struct
{
    bool conPres; //FALSE: This is a normal SMS. TRUE: This is a concatenate SMS
    ST_RIL_SMS_Con con;
} ST_RIL_SMS_SendExt;

typedef struct 
{
    u8 alpha; //It's value is same as 'LIB_SMS_DCSAlphaEnum'
    char oa[RIL_SMS_PHONE_NUMBER_MAX_LEN];
    char scts[RIL_SMS_TIME_STAMP_STR_MAX_LEN];

    bool conPres; //FALSE: This is a normal SMS. TRUE: This is a concatenate SMS
    ST_RIL_SMS_Con con;

    u8 data[RIL_SMS_TEXT_DATA_MAX_LEN];
    u32 length;
} ST_RIL_SMS_DeliverParam;

typedef struct 
{
    u8 alpha; //It's value is same as 'LIB_SMS_DCSAlphaEnum'
    char da[RIL_SMS_PHONE_NUMBER_MAX_LEN];

    bool conPres; //FALSE: This is a normal SMS. TRUE: This is a concatenate SMS
    ST_RIL_SMS_Con con;

    u8 data[RIL_SMS_TEXT_DATA_MAX_LEN];
    u32 length;
} ST_RIL_SMS_SubmitParam;

typedef struct
{
    u8 mr;
    char ra[RIL_SMS_PHONE_NUMBER_MAX_LEN];
    char scts[RIL_SMS_TIME_STAMP_STR_MAX_LEN];
    char dt[RIL_SMS_TIME_STAMP_STR_MAX_LEN];
} ST_RIL_SMS_StatusReportParam;

typedef struct {
    u8 status;     // It's value is same as 'Enum_RIL_SMS_StatusType'
    u8 type;       // It's value is same as 'LIB_SMS_PDUTypeEnum'

    char sca[RIL_SMS_PHONE_NUMBER_MAX_LEN];

    union
    {
        ST_RIL_SMS_DeliverParam deliverParam;            //Parameters for MSG_TYPE_DELIVER 
        ST_RIL_SMS_SubmitParam submitParam;              //Parameters for MSG_TYPE_SUBMIT 
        ST_RIL_SMS_StatusReportParam statusReportParam; //Parameters for MSG_TYPE_STATUS_REPORT
    } param;
} ST_RIL_SMS_TextInfo;

typedef struct {
    u8   status;  // It's value is same as 'Enum_RIL_SMS_StatusType'
    u32  length;
    char data[LIB_SMS_PDU_BUF_MAX_LEN * 2]; // The PDU string
} ST_RIL_SMS_PDUInfo;

typedef struct
{
    char* pduString;
    u32   pduLen;
    u32 mr;
}ST_RIL_SMS_SendPDUInfo;

/***********************************************************************
 * OTHER TYPE DEFINITIONS
************************************************************************/
//NOTE: This enum ONLY in send/read/write text message.
typedef enum
{
    LIB_SMS_CHARSET_GSM = 0,  //See 3GPP TS 23.038 Clause '6.2.1 GSM 7 bit Default Alphabet'
    LIB_SMS_CHARSET_HEX = 1,
    LIB_SMS_CHARSET_UCS2 = 2,
    LIB_SMS_CHARSET_IRA = 3,
    LIB_SMS_CHARSET_8859_1 = 4,

    //==> Warning: Please add new charset upper this line!
    LIB_SMS_CHARSET_INVALID = 0xFF
} LIB_SMS_CharSetEnum;

/***********************************************************************
 * RIL SMS API define
************************************************************************/

/******************************************************************************
* Function:     RIL_SMS_GetStorage
*  
* Description:
*               Get SMS storage info
*
* Parameters:    
*               <pCurrMem>:
*                   [In] The pointer of current SMS storage type,same as: 'Enum_RIL_SMS_SMSStorage'
*               <pUsed>:
*                   [In] The pointer of used count in SMS storage
*               <pTotal>
*                   [In] The pointer of total count in SMS storage
*
* Return:  
*               RIL_ATRSP_CONTINUE: Need to wait later AT response
*               RIL_ATRSP_SUCCESS:  AT command run SUCCESS.
*               RIL_ATRSP_FAILED:   AT command run FAIL!
*               OTHER VALUES:       This function works FAIL!
* NOTE:
*               1. If you DONOT want to get <pUsed>,pTotal value,please set it to NULL.
******************************************************************************/
extern s32 RIL_SMS_GetStorage(u8* pCurrMem, u32* pUsed,u32* pTotal);

/******************************************************************************
* Function:     RIL_SMS_SetStorage
*  
* Description:
*               Set SMS storage
*
* Parameters:    
*               <storage>:
*                   [In] SMS storage,same as 'Enum_RIL_SMS_SMSStorage'
*
* Return:  
*               RIL_ATRSP_SUCCESS:  This function works SUCCESS.
*               RIL_ATRSP_CONTINUE: Need to wait later AT response
*               RIL_ATRSP_SUCCESS:  AT command run SUCCESS.
*               RIL_ATRSP_FAILED:   AT command run FAIL!
*               OTHER VALUES:       This function works FAIL!
* NOTE:
*               1. If you DONOT want to get <pUsed>,pTotal value,please set it to NULL.
******************************************************************************/
extern s32 RIL_SMS_SetStorage(Enum_RIL_SMS_StorageType eStorage,u32* pUsed,u32* pTotal);

/******************************************************************************
* Function:     RIL_SMS_ReadSMS_PDU
*  
* Description:
*               Read a PDU SMS
*
* Parameters:    
*               <index>:
*                   [In] The SMS index in current SMS storage
*               <pduInfo>:
*                   [In] The pointer of 'ST_RIL_SMS_PDUInfo' data
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
extern s32 RIL_SMS_ReadSMS_PDU(u32 uIndex, ST_RIL_SMS_PDUInfo* pPDUInfo);

/******************************************************************************
* Function:     RIL_SMS_ReadSMS_Text
*  
* Description:
*               Read a TEXT SMS
*
* Parameters:    
*               <uIndex>:
*                   [In] The SMS index in current SMS storage
*               <eCharset>:
*                   [In] Character set enum value
*               <pTextInfo>
*                   [In] The pointer of TEXT SMS info
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
extern s32 RIL_SMS_ReadSMS_Text(u32 uIndex, LIB_SMS_CharSetEnum eCharset,ST_RIL_SMS_TextInfo* pTextInfo);

/******************************************************************************
* Function:     RIL_SMS_SendSMS_PDU
*  
* Description:
*               This function is used to send PDU message
*
* Parameters:    
*               <pPDUStr>:
*                   [In] The pointer of PDU string
*               <uPDUStrLen>:
*                   [In] The length of PDU string
*               <pMsgRef>
*                   [Out] The pointer of message reference number
*
* Return:  
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.
* Note:
*                1. If you DONOT want to get <pMsgRef> value,please set it to NULL.
******************************************************************************/
extern s32 RIL_SMS_SendSMS_PDU(char* pPDUStr,u32 uPDUStrLen,u32 *pMsgRef);

/******************************************************************************
* Function:     RIL_SMS_SendSMS_Text
*  
* Description:
*               This function is used to send TEXT message
*
* Parameters:    
*               <pNumber>:
*                   [In] The pointer of phone number
*               <uNumberLen>:
*                   [In] The length of phone number
*               <eCharset>
*                   [In] CharSet,it's value is same as 'LIB_SMS_CharSetEnum'
*               <pMsg>
*                   [In] The pointer of message content
*               <uMsgLen>
*                   [In] The length of message content
*               <pMsgRef>
*                   [Out] The pointer of message reference number
*
* Return:  
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.
* Note:
*                1. If you DONOT want to get <pMsgRef> value,please set it to NULL.
******************************************************************************/
extern s32 RIL_SMS_SendSMS_Text(char* pNumber, u8 uNumberLen, LIB_SMS_CharSetEnum eCharset, u8* pMsg, u32 uMsgLen,u32 *pMsgRef);

/******************************************************************************
* Function:     RIL_SMS_SendSMS_Text_Ext
*  
* Description:
*               This function is used to send TEXT message witch external info
*
* Parameters:    
*               <pNumber>:
*                   [In] The pointer of phone number
*               <uNumberLen>:
*                   [In] The length of phone number
*               <eCharset>
*                   [In] CharSet,it's value is same as 'LIB_SMS_CharSetEnum'
*               <pMsg>
*                   [In] The pointer of message content
*               <uMsgLen>
*                   [In] The length of message content
*               <pMsgRef>
*                   [Out] The pointer of message reference number
*               <pExt>
*                   [In]  The pointer of 'ST_RIL_SMS_SendExt' data
*                         + conPres  con-SMS present or not
*                         + con      'ST_RIL_SMS_Con' data
*
* Return:  
*                RIL_AT_SUCCESS,send AT successfully.
*                RIL_AT_FAILED, send AT failed.
*                RIL_AT_TIMEOUT,send AT timeout.
*                RIL_AT_BUSY,   sending AT.
*                RIL_AT_INVALID_PARAM, invalid input parameter.
*                RIL_AT_UNINITIALIZED, RIL is not ready, need to wait for MSG_ID_RIL_READY
*                                      and then call Ql_RIL_Initialize to initialize RIL.
* Note:
*                1. If you DONOT want to get <pMsgRef> value,please set it to NULL.
*                2. If you want to send normal SMS, you can set <pExt> to NULL.
******************************************************************************/
extern s32 RIL_SMS_SendSMS_Text_Ext(char* pNumber, u8 uNumberLen, LIB_SMS_CharSetEnum eCharset, u8* pMsg, u32 uMsgLen,u32 *pMsgRef,ST_RIL_SMS_SendExt *pExt);

/******************************************************************************
* Function:     RIL_SMS_DeleteSMS
*  
* Description:
*               This function deletes SMS messages in current SMS storage.
*
* Parameters:    
*               index:
*                   [In] The index number of SMS message.
*               flag:
*                   [In] Delete flag , which is one value of 'Enum_RIL_SMS_DeleteFlag'.
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
extern s32 RIL_SMS_DeleteSMS(u32 uIndex,Enum_RIL_SMS_DeleteFlag eDelFlag);

#endif  //#ifndef __RIL_SMS_H__

