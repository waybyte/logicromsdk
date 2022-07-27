GPS Library
===========

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


Application Example
-------------------

.. raw:: html

	<p><i class="fa fa-github"></i> <a href="https://github.com/waybyte/example-gps" target="_blank">waybyte/example-gps</a></p>


API Reference
-------------

.. toctree::
   :maxdepth: 1

   GNSS Hardware <gnss/gnss_hardware>
   GPS Library <gnss/gps_lib>
   GPS Driver <gnss/gps_driver>
