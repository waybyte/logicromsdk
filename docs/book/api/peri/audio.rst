Audio APIs
==========

.. note:: Audio interface is currently only supported on RDA8910 chipset.

Example Usage
-------------

.. code-block:: c

	#include <audio.h>

	/* Play an MP3 file from sdcard */
	audio_file_play("/sd/file.mp3", AUDIO_PLAY_LOCAL, NULL);

	/* Play an MP3 file from sdcard during call */
	audio_file_play("/sd/file.mp3", AUDIO_PLAY_VOICE, NULL);

    /* set volume */
    audio_set_volume(100);

    /* play DTMF tone */
    audio_play_dtmf("1234", 500, false, NULL);

    /* Record from MIC */
    audio_record_start("/fs/record.amr", AUDIO_REC_TYPE_MIC, AUDIO_QUALITY_MEDIUM, 5000, NULL);

    /* Record voice call */
    audio_record_start("/fs/call_record.amr", AUDIO_REC_TYPE_VOICE, AUDIO_QUALITY_MEDIUM, 0, NULL);


.. Application Example
.. -------------------
.. TODO

API Reference
-------------

.. include:: /inc/audio.inc
