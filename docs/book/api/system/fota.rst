Firmware OTA API
================

Firmware over-the-air update API.

Example Usage
-------------

.. code-block:: c

    #include <fota.h>

    /* Initialize fota and add fota command to console */
    fota_init();

    /* to programatically start fota */
    fota_start("http://url/to/fota/firmware");

    /* To register fota using Logicrom Device management console */
    /*
     * First parameter is application firmware code, a unique code
     * registered on server.
     * 
     * Second parameter is current version of application firmware
     */
    logicrom_fota_register("FWCODE", "1.0.0");


API Reference
-------------

.. include:: /inc/fota.inc

