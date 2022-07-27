NTP Client
==========

Logicrom provide NTP client service which can be enabled during
system initialization. Once enabled service will automatically
take care of setting system time when device is ready and GPRS
service is active. The NTP sync interval is 60 minutes.

When NTP client service is enabled, A manual NTP sync command is
added to the console "ntpdate" to sync system time with NTP source
via configured time server.

To change or update NTP server, use system clock management API
(:doc:`Time & Clock Management <../system/libtime>`)


Example Usage
-------------

.. code-block:: c

    #include <proto/ntpc.h>

    /* Initialize NTP client */
    ntpclient_init();


API Reference
-------------

.. include:: /inc/ntpc.inc
