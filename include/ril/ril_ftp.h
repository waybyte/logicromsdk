
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
 *   ril_ftp.h 
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
#define __RIL_FTP_H__

#include "../../include/ril/ril.h"

typedef void (*CallBack_Ftp_Upload)(s32 result,s32 size);
typedef void (*CallBack_Ftp_Download)(s32 result,s32 size);

typedef struct{
char *prefix;
s32 data;
}ST_AT_ftpParam;

typedef enum
{
    FTP_STATUS_IDLE = 0,           //No FTP service.   
    FTP_STATUS_OPENING,         //Opening an FTP service.   
    FTP_STATUS_OPENED,	         //The FTP service is opened and idle.   
    FTP_STATUS_WORKING,   	 //Sending FTP commands to the FTP server and receiving response from the FTP server to start data transfer.
    FTP_STATUS_TRANSFER,  	 //Transferring data between the module and the FTP server.   
    FTP_STATUS_CLOSING,    	 //Closing the FTP service.   
    FTP_STATUS_CLOSED     	 //The FTP service is closed
    
}ENUM_FTP_STATUS;

s32 RIL_FTP_QFTPOPEN(u8* hostName, u32 port,u8* userName,u8* password, bool mode);

s32 RIL_FTP_QFTPCLOSE(void);

s32 RIL_FTP_QFTPPUT(u8* fileName, u32 fileSize, u32 timeOut, CallBack_Ftp_Upload ftpPut_CB);

s32 RIL_FTP_QFTPGET(u8* fileName, u32 fileSize,CallBack_Ftp_Download ftpGet_CB);

s32 RIL_FTP_QFTPPATH(u8* pathName);

s32 RIL_FTP_QFTPCFG(u8 type, u8* value);

s32 RIL_FTP_QFTPSTAT(s32* state);

s32 RIL_FTP_QFTPLEN(s32* len);

s32 RIL_FTP_QFTPRENAME(u8* sourcName, u8* targetName);

s32 RIL_FTP_QFTPSIZE(u8* fileName, u32* fileSize);

s32 RIL_FTP_QFTPDELETE(u8* fileName);

s32 RIL_FTP_QFTPMKDIR(u8* pathName);

s32 RIL_FTP_QFTPRMDIR(u8* pathName);

s32 RIL_FTP_QIDEACT(void);

#endif


