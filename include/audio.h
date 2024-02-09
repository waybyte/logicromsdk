/**
 * @file audio.h
 * @brief Audio APIs for modules based on RDA8910 chipset.
 * @date 2023-12-15
 *
 */

#ifndef INC_AUDIO_H_
#define INC_AUDIO_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Audio output channel list
 * 
 */
enum audio_out_e {
	AUDIO_OUTPUT_RECEIVER = 0,  /**< receiver */
	AUDIO_OUTPUT_HEADPHONE = 1, /**< headphone */
	AUDIO_OUTPUT_SPEAKER = 2,   /**< speaker */
};

/**
 * @brief Audio input channel list
 * 
 */
enum audio_in_e {
	AUDIO_INPUT_MAINMIC = 0, /**< main mic */
	AUDIO_INPUT_AUXMIC = 1,  /**< auxilary mic */
	AUDIO_INPUT_DUALMIC = 2, /**< dual mic */
	AUDIO_INPUT_HPMIC_L = 3, /**< headphone mic left */
	AUDIO_INPUT_HPMIC_R = 4, /**< headphone mic right */
};

/**
 * @brief Audio playback path select
 * 
 */
enum audio_play_e {
	AUDIO_PLAY_LOCAL = 1, /**< Play to local audio path */
	AUDIO_PLAY_VOICE = 2, /**< Play to uplink remote during voice call */
};

/**
 * @brief Audio recorder path select
 * 
 */
enum audio_rec_e {
	AUDIO_REC_TYPE_MIC = 1, /**< Record from microphone. */
	AUDIO_REC_TYPE_VOICE = 2, /**< Record for voice call. The recorded stream is the mixed with uplink and downlink channels */
};

enum audio_qual_e {
	AUDIO_QUALITY_LOW,    /**< quality low */
	AUDIO_QUALITY_MEDIUM, /**< quality medium */
	AUDIO_QUALITY_HIGH,   /**< quality high */
	AUDIO_QUALITY_BEST,   /**< quality best */
};

/**
 * @brief Audio event callback
 * 
 */
typedef void (*audio_statuscb_f)(int ev);

/**
 * @brief Set output channel for Audio playback
 *
 * @param ch output channel @ref audio_out_e
 * @return 0 for success, error code otherwise
 */
int audio_set_outputchannel(uint32_t ch);

/**
 * @brief Get current output channel @ref audio_out_e
 * 
 * @return output channel
 */
int audio_get_outputchannel(void);

/**
 * @brief Set audio input channel for recording
 * 
 * @param ch input channel value @ref audio_in_e
 * @return 0 for success, error code otherwise
 */
int audio_set_inputchannel(uint32_t ch);

/**
 * @brief Get current input channel for recording @ref audio_in_e
 * 
 * @return audio input channel
 */
int audio_get_inputchannel(void);

/**
 * @brief Set playback volume. Volume level should in [0, 100].
 * 0 is the minimal volume, and 100 is the maximum volume.
 * It is possible that the supported volume levels is not 100.
 * And then the output is the same for multiple vol.
 * 
 * @param vol Volume level between 0 to 100
 * @return 0 for success, error code otherwise
 */
int audio_set_volume(int vol);

/**
 * @brief Get current playback volume level.
 * 
 * @return volume level between 0 to 100
 */
int audio_get_volume(void);

/**
 * @brief Set volume level for voice call between 0 to 100.
 * 0 is the minimal volume, and 100 is the maximum volume.
 * It is possible that the supported volume levels is not 100.
 * And then the output is the same for multiple vol.
 * 
 * @param vol volume level between 0 to 100
 * @return 0 for success, error code otherwise
 */
int audio_set_callvolume(int vol);

/**
 * @brief Get current voice call volume.
 * 
 * @return volume level between 0 to 100
 */
int audio_get_callvolume(void);

/**
 * @brief mute or unmute audio output device. This setting
 * won't be stored, the initial value is always unmute.
 * 
 * @param mute true for mute, false for unmute
 * @return 0 for success, error code otherwise
 */
int audio_set_mute(int mute);

/**
 * @brief check whether audio output device is muted
 * 
 * @return true if mute, false if unmute
 */
int audio_get_mute(void);

/**
 * @brief Play DTMF tone
 * 
 * @param tone DTMF string with valid DTMF characters (0-9,*,#,A,B,C,D)
 * @param duration Duration of DTMF tone in milliseconds, 100 to 1000ms.
 * @param block True to block till playback finishes, false for non-blocking call
 * @param cb Callback function for playback status events
 * @return 0 for success, error code otherwise
 */
int audio_play_dtmf(const char *tone, unsigned duration, int block, audio_statuscb_f cb);

/**
 * @brief Play audio file. Supported audio file types:
 * Raw PCM file
 * Wav file
 * MP3 audio file
 * AMR audio file
 * 
 * @param file Filesystem path of audio file to play
 * @param path Aduio output path @ref audio_play_e
 * @param cb Callback function for playback status events
 * @return 0 for success, error code otherwise
 */
int audio_file_play(const char *file, int path, audio_statuscb_f cb);

/**
 * @brief Pause audio file player
 * 
 * @return 0 for success, error code otherwise
 */
int audio_file_pause(void);

/**
 * @brief Resume audio file player
 * 
 * @return 0 for success, error code otherwise
 */
int audio_file_resume(void);

/**
 * @brief Stop audio file player
 * 
 * @return 0 for success, error code otherwise
 */
int audio_file_stop(void);

/**
 * @brief Start audio recorder.
 * 
 * @param fname Filename to store
 * @param path Audio recorder path @ref audio_rec_e
 * @param quality Audio encoder quality @ref audio_qual_e
 * @param duration duration of recording in ms, 0 for continuous recording until stopped or call ends
 * @param cb Callback function for recorder status events
 * @return 0 for success, error code otherwise
 */
int audio_record_start(const char *fname, int path, int quality, int duration, audio_statuscb_f cb);

/**
 * @brief Pause audio recorder
 * 
 * @return 0 for success, error code otherwise
 */
int audio_record_pause(void);

/**
 * @brief Resume audio recorder
 * 
 * @return 0 for success, error code otherwise
 */
int audio_record_resume(void);

/**
 * @brief Stop audio recorder
 * 
 * @return 0 for success, error code otherwise
 */
int audio_record_stop(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_AUDIO_H_ */
