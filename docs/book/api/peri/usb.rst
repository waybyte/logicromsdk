USB
===

GSM Module
----------

The 2G GSM modules (MT2503, MT6261, RDA8955) provide a USB 1.1 interface with the
CDC(ACM) profile. The USB port allows the device to interface with a USB host for
communication.

Only the following GSM modules provide USB access:

1. MC20U
2. SIM868
3. M590
4. A9/A9G

The USB serial port is registered as a device file ``/dev/ttyUSB0`` which can be used
as standard UART port.

4G LTE Module
-------------

Both the RDA8910 and ASR160x chipsets provide two USB serial ports for user applications.
The two device files are registered as ``/dev/ttyUSB0`` and ``/dev/ttyUSB1``.

There are no USB-specific APIs for USB serial port access. The device file supports
standard system calls for IO operations and the termios API for serial port parameter
controls.

For access to USB serial ports, refer to the :doc:`UART API <uart>`.

Example Usage
-------------

.. code-block:: c

    #include <unistd.h>
    #include <fcntl.h>
    #include <termios.h>

    /* Open USB Uart */
    int fd = open("/dev/ttyUSB0");

    /* write on USB Uart */
    write(fd, "Test", 4);

    /* read */
    int ret;
    char buf[10];

    ret = read(fd, buf, sizeof(buf));


Application Example
-------------------

.. raw:: html

	<p><i class="fa fa-github"></i> <a href="https://github.com/waybyte/example-uart" target="_blank">waybyte/example-uart</a></p>

API Reference
-------------

.. include:: /inc/usb.inc
