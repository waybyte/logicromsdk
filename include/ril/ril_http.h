#ifndef __RIL_HTTP_H__
#define __RIL_HTTP_H__

#include "../../include/ril/ril.h"

typedef enum{
    HTTP_ACTION_IDLE = 0,
    HTTP_ACTION_SETRUL,
    HTTP_ACTION_GET_REQ,
    HTTP_ACTION_POST_REQ,
    HTTP_ACTION_READ_RSP,
    HTTP_ACTION_DOWNLOAD_FILE
}Enum_HTTP_Ation;

//
//
// Set http server URL address.
s32 RIL_HTTP_SetServerURL(char* strURL, u16 len);
//
// Send http-get request.
s32 RIL_HTTP_RequestToGet(u32 timeout);
//
// Send http-post request.
s32 RIL_HTTP_RequestToPost(char* strPostMsg, u16 len);
//
// Read response from HTTP server.
s32 RIL_HTTP_ReadResponse(u32 timeout, ril_recvcb_f cb_rcvData);
//
// Downlaod the file from http server to a local file. 
// The http file is specified by the url when calling RIL_HTTP_SetServerURL(). 
typedef void (*CB_HTTP_DwnldFile)(u32 dllSize, u32 cntntLen, s32 errCode);
s32 RIL_HTTP_DownloadFile(char* filePath, u32 size, CB_HTTP_DwnldFile cb);

#endif  //__RIL_HTTP_H__

