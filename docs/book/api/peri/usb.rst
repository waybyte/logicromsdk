USB
===

2G GSM modules (MT2503, MT6261, RDA8955) provide USB 1.1 interface with
CDC(ACM) profile. USB port can be used to interface device with a USB host
for communication.

Only Following GSM module provide USB Access:

1. MC20U
2. SIM868
3. M590
4. A9

USB serial port is registered as a device file ``/dev/ttyUSB0`` which supports
standard system calls for IO operations and termios API for serial port
parameter controls.

There are no USB specific APIs.

Refer UART documentation for access to serial ports

:doc:`UART API <uart>`

Application Example
-------------------

.. raw:: html

	<p><i class="fa fa-github"></i> <a href="https://github.com/waybyte/example-uart" target="_blank">waybyte/example-uart</a></p>

