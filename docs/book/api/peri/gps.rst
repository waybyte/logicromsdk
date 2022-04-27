GPS Library
===========

.. toctree::
   :maxdepth: 2

Logicrom gps library does all the heavy lifting and makes it easy to use
and interface any GNSS module. Features of gps library:

* Accurate software odometer
* Motion detection based on GPS data
* No position drift after vehicle stops
* Critical events based on user configuration:

   1. Harsh Acceleration
   2. Harsh Breaking
   3. Harsh turning/cornering
   4. Over speed

* Vehicle turn notification
* GPS status notification

GPS Library also provide ready drivers for well known external modules and on-board
GNSS chips.

Following are the supported chipset or modules:

1. Quectel L89 R2.0 IRNSS Module
2. Modules compatible with CASIC GNSS recevier protocol

   * Neoway N58 LTE Cat.1
   * Neoway G2
   * Neoway G7A
   * AT6558

3. Mediatek MT333x chipset

   * Quectel L86
   * Quectel L76
   * Quectel MC60
   * Quectel MC20

4. SIRF Star III type chipset
5. STMicro STA8090 based IRNSS modules

   * Quectel L89

6. Unicore UC6226/UC6228 type chipset

   * Quectel L76C
   * Quectel L26C
   * Quectel BC20 (NB-IoT)
   * Quectel EC200UCN-AA LTE Cat.1 Module


GPS Library API
---------------

.. include:: /inc/gpslib.inc

GPS Driver Interface API
------------------------

.. include:: /inc/gpsdriver.inc

GNSS Hardware API
-----------------

.. note:: For Neoway N58 and Quectel EC200U modules only.

.. include:: /inc/gnss.inc
