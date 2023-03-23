*****************
Quick Start Guide
*****************

This document is intended to help users setup software development environment
for application development on 4G LTE, GSM and NB-IoT modules using Logicrom
software development kit.

Getting Hardware Ready
======================

Logicrom is supported on 4G LTE Cat.1 modules and 2G GSM modules. Select a
module of your choice from the list provided on the main page.

Download the core firmware for selected module from our github page here:
https://github.com/waybyte/example-os

If you do not find your module on the list, Do let us know we will try to
add it to the list.

Follow the :doc:`flashing guide <flash/core>` and Flash the core firmware
on the device.

Activate Logicrom Core
----------------------

To run applications on logicrom SDK, device needs to Activate. A personal
license is Free to use without any feature restrictions. Following are steps
to accquire a license for your device.

1. Register account on `waybyte.in <https://waybyte.in/register>`_
2. Click on `Register Free Device <https://waybyte.in/devices/register>`_ from left menu
3. Enter device details (IMEI and Module type) and register
4. Put a valid SIM card in device
5. Turn on the device, It should accquire the license\
   If device fail to do so, run "getlic" command from device console Port
   (USB Port 0 or Main UART) to try again.

Getting Software Ready
======================

Setup IDE
---------

Logicrom is supported by both PlatformIO IDE and Arduino IDE. Users can select
IDE of their choice though our recommendation is to go with PlatformIO.

Follow the installation guide to setup the IDE.


.. toctree::
   :maxdepth: 1

   Installing Logicrom on Arduino IDE <quick_start/setup_arduino>
   Installing Logicrom on PlatformIO <quick_start/setup_platformio>

Building & Flashing Application
-------------------------------

.. toctree::
   :maxdepth: 1

   Creating Project in PlatformIO using Logicrom SDK <quick_start/logicrom>
   Creating Project in PlatformIO using Arduino Framework <quick_start/arduino>

Follow the :doc:`application flashing guide <flash/application>` to upload
application on the device.


Need Help?
==========

Need help in installation or setup?
Drop an email @ support[at]waybyte.in or Post issues on our GitHub
page @ https://github.com/waybyte/platform-logicrom/issues

