GPS Library API
===============

Commands
--------

GPS library exposes two commands to interact with GPS hardware from console.

1. GPSINFO
   
   This command is to get GPS information. This command responds with Following information:

   | Status: active or inactive status of gps hardware
   | Time: parsed Time information from NMEA
   | Date: parsed Date information from NMEA
   | Fix: GPS fix status, 'A' or 'V'
   | Sat: Number of visible satellites
   | Speed: Current speed, This is filtered data parameter after processing
   | Dir: Heading value (filtered)
   | PDOP: Current PDOP value
   | HDOP: Current HDOP value
   | Lat: Latitude value in degree (filtered)
   | Long: Longitude value in degree (filtered)
   | Alt: Altitude data (filtered)
   | ODO: Odometer in meters (calculated)

   To see the above parameters unfiltered, send "raw" argument to GPSINFO command, e.g.:
   
   ``gpsinfo=raw``

2. GPSCMD
   
   Send command to GPS hardware.

   Usage Format:

   ``gpscmd=arg``

   Arg can be following:

   1. COLDSTART: send cold start command to GPS hardware.
   2. HOTSTART: send hot start command to GPS hardware.
   3. WARMSTART: send warm start command to GPS hardware.
   
   It is also possible to send raw command to device in place of argument, e.g.:

   ``gpscmd="PMTK353,1,1,1,0,0"``

   Please make sure to put raw command inside quotes. There is no need to add $ or checksum, it will be added
   based on selected driver.


.. include:: /inc/gpslib.inc

