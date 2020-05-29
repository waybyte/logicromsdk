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
 *   ril_aud.h 
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
#ifndef __RIL_AUD_H__
#define __RIL_AUD_H__

#include "../../include/ril/ril.h"

typedef enum 
{
     AUD_CHANNEL_NORMAL= 0,
     AUD_CHANNEL_HEADSET,
     AUD_CHANNEL_LOUD_SPEAKER
} Enum_AudChannel;

typedef enum {
    AUD_DATA_FMT_MP3 = 1,
    AUD_DATA_FMT_AMR = 2,
    AUD_DATA_FMT_WAV = 3,
    AUD_DATA_FMT_END
}Enum_AudDataFormat;

typedef enum 
{
    AUD_RECORD_FORMAT_AMR = 0,
    AUD_RECORD_FORMAT_WAV_PCM16,
    AUD_RECORD_FORMAT_WAV_ALAW,
    AUD_RECORD_FORMAT_WAV_ULAW,
    AUD_RECORD_FORMAT_WAV_ADPCM
} Enum_AudRecordFormat;

/* Define volume type.*/
typedef enum {
    VOL_TYPE_MIC      ,   /* microphone attribute */
    VOL_TYPE_SPH      ,   /* MMI can apply to associate volume; speech sound attribute */
    VOL_TYPE_MEDIA    ,   /* MMI can apply to associate volume; As MP3, Wave,... attribute */
    VOL_TYPE_SID      ,   //side tone attribute  
    MAX_VOL_TYPE           
}Enum_VolumeType;


typedef enum{
    AUD_PLAY_IND_OK = 5,            // Playing finished normally
    AUD_PLAY_IND_INTERRUPT = 6,     // Interrupted by other audio tasks
    AUD_PLAY_IND_UNKNOWN_ERROR = 9  // Unknown error
}Enum_AudPlayInd;

/*****************************************************************************
 * FUNCTION
 *   RIL_AUD_RegisterPlayCB
 *
 * DESCRIPTION
 *   This function registers a callback function that will be invoked to 
 *   indicate the playing result.
 *
 *   If you want to get a feedback (end indication or error code) for playing  
 *   when calling APIs "RIL_AUD_PlayFile" and "RIL_AUD_PlayMem". You can call
 *   this API to reguster a callback function before calling playing API.
 *
 * PARAMETERS
 *   errCode       :[OUT] error code for audio playing, which is defined in
 *                       "AT+QAUDPLAY".
 * RETURNS
 *                QL_RET_OK, this function succeeds.
 *                QL_RET_ERR_INVALID_PARAMETER, invlid paramter.
 *****************************************************************************/
typedef void (*RIL_AUD_PLAY_IND)(s32 errCode);
s32 RIL_AUD_RegisterPlayCB(RIL_AUD_PLAY_IND audCB);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_PlayFile
 * DESCRIPTION
 *  This function is used to play audio file.
 * PARAMETERS
 *  filePath       :[in]source file name with filepath
 *  isRepeated     :[in]repeat play mode
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32 RIL_AUD_PlayFile(char* filePath, bool isRepeated);

/*****************************************************************************
 * FUNCTION
 *      RIL_AUD_StopPlay
 * DESCRIPTION
 *      This function is used to stop play audio file.
 * PARAMETERS
 *      void
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32 RIL_AUD_StopPlay(void);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_StartRecord
 * DESCRIPTION
 *  This function is used to start record audio.
 * PARAMETERS
 *  fileName        :[in]source file name
 *  format          :[in]source file format,see Enum_AudRecordFormat
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32 RIL_AUD_StartRecord(char* fileName, Enum_AudRecordFormat format);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_StopRecord
 * DESCRIPTION
 *  This function is used to stop record audio.
 * PARAMETERS
 *  void
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32 RIL_AUD_StopRecord(void);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_GetRecordState
 * DESCRIPTION
 *  This function is used to get audio record state.
 * PARAMETERS
 *         0 Module is not in recording
 *         1 Module is in recording
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32 RIL_AUD_GetRecordState(u8* pState);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_SetVolume
 * DESCRIPTION
 *  This function is used to set the volume level according to the specified volume type.
 * PARAMETERS
 *  volType        :[in] volume type,see Enum_VolumeType
 *  pvolLevel      :[in] volume level.
 * RETURNS
 *  s32    QL_RET_OK means AT execute suceess,see 'Error Code Definition'
 *****************************************************************************/
s32  RIL_AUD_SetVolume(Enum_VolumeType volType, u8 volLevel);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_GetVolume
 * DESCRIPTION
 *  This function is used to get the volume level according to the specified volume type.
 * PARAMETERS
 *  volType        :[in] volume type,see Enum_VolumeType
 *  pVolLevel      :[out] volume level.
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32  RIL_AUD_GetVolume(Enum_VolumeType volType, u8* pVolLevel);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_GetChannel
 * DESCRIPTION
 *  This function is used to get the audio channel.
 * PARAMETERS
 *  pChannel       :[out] audio channel,see Enum_AudChannel
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32 RIL_AUD_GetChannel(Enum_AudChannel *pChannel);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_SetChannel
 * DESCRIPTION
 *  This function is used to set the audio channel.
 * PARAMETERS
 *  audChannel       :[out] audio channel,see Enum_AudChannel
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32 RIL_AUD_SetChannel(Enum_AudChannel audChannel);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_PlayMem
 * DESCRIPTION
 *  This function plays audio resource data with the specified address(hex) 
 *  through the current audio channel.
 *
 * PARAMETERS
 *  mem_addr         :[in] address in memory of audio data
 *  mem_size         :[in] size of audio data
 *  aud_format       :[in] audio data format
 *  repeat           :[in] once play or infinite
 *
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32 RIL_AUD_PlayMem(u32 mem_addr, u32 mem_size, u8 aud_format, bool repeat);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_StopPlayMem
 * DESCRIPTION
 *  This function is used stop play memory audio file.
 * PARAMETERS
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32 RIL_AUD_StopPlayMem(void);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_PlayMemBg
 * DESCRIPTION
 *  This function plays audio resource data with the specified address(hex) IN CALL 
 *  through the current audio channel.
 *
 * PARAMETERS
 *  mem_addr         :[in] address in memory of audio data
 *  mem_size         :[in] size of audio data
 *  aud_format       :[in] audio data format
 *  vol_ul           :[in] volume level for uplink
 *  vol_dl           :[in] volume level for downlink
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32 RIL_AUD_PlayMemBg(u32 mem_addr, u32 mem_size, u8 aud_format, u8 vol_ul, u8 vol_dl);

/*****************************************************************************
 * FUNCTION
 *  RIL_AUD_StopPlayMemBg
 * DESCRIPTION
 *  This function stops playing memory audio data in call.
 * PARAMETERS
 * RETURNS
 *                RIL_AT_SUCCESS, this function succeeds.
 *                Or, please see the definition of Enum_ATSndError.
 *****************************************************************************/
s32 RIL_AUD_StopPlayMemBg(void);

#endif  //__RIL_AUD_H__
