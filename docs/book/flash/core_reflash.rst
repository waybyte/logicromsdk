MT2503/MT6261 Core Re-Flashing
==============================

It is possible to flash MediaTek based modules directly from IDE. Following is the procedure
to flash Logicrom core via IDE.

Re-Flashing Core via PlatformIO
-------------------------------

1. Open project tasks by clicking PlatformIO icon from left sidebar
2. Under custom tasks, click "Reflash Core Firmware"

.. image:: ../../_static/platformio-ide-flash-core.png
  :class: auto-width
  :group: platformio
  :title: Reflash core option in PlatformIO

3. Reset the target board.
4. Core flashing will start, check progress in terminal windows

.. image:: ../../_static/platformio-ide-flash-core-progress.png
  :class: auto-width
  :group: platformio
  :title: Flash progress in PlatformIO

Re-Flashing Core via Arduino
----------------------------

1. Select Programmer from Tools -> Programmer -> Logicrom Core Flasher
   (MT2503/MT6261)

.. image:: ../../_static/arduino-ide-select-logicrom-flasher.png
  :class: auto-width
  :group: arduino
  :title: Configure programmer in Arduino

1. Select device COM port under Tools -> Port

.. image:: ../../_static/arduino-ide-select-logicrom-flasher-port.png
  :class: auto-width
  :group: arduino
  :title: Set COM port

3. Click Tools -> Burn Bootloader to start flashing.
4. Reset the tartget board, and check flash progress in the output console.

.. image:: ../../_static/arduino-ide-logicrom-flasher-progress.png
  :class: auto-width
  :group: arduino
  :title: Flash progress in Arduino


.. toctree::
  :hidden:

