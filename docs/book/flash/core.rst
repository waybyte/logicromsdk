Core Firmware Flashing
======================

Logicrom core firmware can be downloaded from github page for supported
modules. Following are the list of tools that can be used for core firmware:

+-----------------+----------------------+---------------+
| SoC / Chipset   | Flashtool            | Download Link |
+-----------------+----------------------+---------------+
| RDA8910         | QFlash               |               |
|                 +----------------------+---------------+
|                 | Logicrom Flasher     |               |
+-----------------+----------------------+---------------+
| ASR1601/ASR1603 | Aboot                |               |
|                 +----------------------+---------------+
|                 | Adownload            |               |
+-----------------+----------------------+---------------+
| RDA8955         | QFlash               |               |
|                 +----------------------+---------------+
|                 | Coolwatcher          |               |
+-----------------+----------------------+---------------+
| MT2593/MT6261   | QFlash               |               |
|                 +----------------------+---------------+
|                 | Logicrom GSM Flasher |               |
+-----------------+----------------------+---------------+

Core Firmware Download
----------------------

Logicrom core firmware for supported modules can be downloaded from github
page: https://github.com/waybyte/logicrom_core


Core Firmware Re-flash
----------------------

Currently core re-flashing of MT2503 & MT6261 based devices is possible and
it's only supported on windows platform due to vendor limitation.

Re-Flashing Core via PlatformIO
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1. Open project tasks by clicking PlatformIO icon from left sidebar
2. Under custom tasks, click "Reflash Core Firmware"

.. image:: ../../_static/platformio-ide-flash-core.png

3. Core flashing will start, check progress in terminal windows

.. image:: ../../_static/platformio-ide-flash-core-progress.png

Re-Flashing Core via Arduino
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1. Select Programmer from Tools -> Programmer -> Logicrom Core Flasher
   (MT2503/MT6261)

.. image:: ../../_static/arduino-ide-select-logicrom-flasher.png

1. Select device COM port under Tools -> Port

.. image:: ../../_static/arduino-ide-select-logicrom-flasher-port.png

3. Click Tools -> Burn Bootloader to start flashing. Check flash progress in
   the output console

.. image:: ../../_static/arduino-ide-logicrom-flasher-progress.png

