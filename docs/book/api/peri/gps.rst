GPS Libaray
===========

.. toctree::
   :maxdepth: 2

MT2503 SoC has on-chip GNSS module supports GPS + GLONASS, Galileo, Beidou
constellations. LOGICROM gps library does all the heavy lifting and make
it easy to use the full capabilities of GNSS module. Some features of gps
library are:

* Most accurate software odometer
* Motion detection based on GPS data
* No postion drift after vehicle stops
* Critical events based on user configuration:

   1. Harsh Acceleration
   2. Harsh Breaking
   3. Harsh turning/cornering
   4. Over speed

* Vehicle turn notification
* GPS status notification

API Reference
-------------

.. include:: /inc/gpslib.inc
