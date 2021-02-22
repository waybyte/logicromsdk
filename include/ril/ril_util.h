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
 *   ril_tuil.h 
 *
 * Project:
 * --------
 *   OpenCPU
 *
 * Description:
 * ------------
 *   The file is for some useful definitions and APIs in common.
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
#ifndef __RIL_UTIL_H__
#define __RIL_UTIL_H__

#include "../../include/ril/ril.h"

typedef enum {
    CHAR_0 = '0',
    CHAR_9 = '9',
    CHAR_A = 'A',
    CHAR_F = 'F',
    END_OF_STR = '\0'
}Enum_Char;
#define IS_NUMBER(alpha_char)   \
    (((alpha_char >= CHAR_0) && (alpha_char <= CHAR_9) ) ? 1 : 0)

extern s32  ril_strprefixmatch(const char* str, const char *prefix);
extern u8 ril_hexstrtoint(u8 *str, u32 *val);
extern char* ril_strtoupper(char* str);

/******************************************************************************
* Function:     ril_findstring
*  
* Description:
*                This function is used to match string within a specified length.
*                This function is very much like strstr.
*
* Parameters:    
*                line:  
*                    [in]The address of the string.
*                len:   
*                    [in]The length of the string.
*                str:   
*                    [in]The specified item which you want to look for in the string.
*
* Return:  
                The function returns a pointer to the located string,
                or a  null  pointer  if  the specified string is not found.
******************************************************************************/
extern char* ril_findstring(char *line, u32 len,char *str);

/******************************************************************************
* Function:     ril_findline
*  
* Description:
*                This function is used to find the specified character line by line.
*                for example,if you want to find "OK", In fact, we think that you are
*                looking for <CR><LF>OK<CR><LF>,<CR>OK<CR> or <LF>OK<LF>.
*
*
* Parameters:    
*                line:  
*                    [in]The address of the string.
*                len:   
*                    [in]The length of the string.
*                str:   
*                    [in]The specified item which you want to look for in the string.
*
* Return:  
                The function returns a pointer to the located string,
                or a  null  pointer  if  the specified string is not found.
******************************************************************************/
extern char* ril_findline(char *line, u32 len,char *str);

/******************************************************************************
* Function:     Default_atRsp_callback
*
* Description:
*                This function is a default RIL AT response handler can be used
*                to check basic responses like OK, ERROR and CME ERROR etc.
*
* Parameters:
*                line:
*                    [in]response string from RIL layer
*                len:
*                    [in]length of response
*                userdata:
*                    [in]Not used, can be NULL
*
* Return:
                The function returns return code used by RIL layer
                RIL_ATRSP_SUCCESS for OK
                RIL_ATRSP_FAILED for Error or CME Error
                RIL_ATRSP_CONTINUE otherwise
******************************************************************************/
extern s32 Default_atRsp_callback(char* line, u32 len, void* userdata);

#endif
