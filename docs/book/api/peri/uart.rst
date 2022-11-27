UART
====

.. |br| raw:: html

	<br>

The UART devices are registered on VFS as device files accessible via startard IO system calls
and termios API.

UART devices are registed under ``/dev/ttySx``, where x is uart number starting from 0.

On both MT6261/MT2503 based GSM modules and RDA8910 based 4G LTE modules, three hardware uart
interfaces are available. On RDA8955 based modules two hardware UARTs are available.

On devices with on-board GNSS (SIM868/N58-CA/EC200U), 2 UARTs are exposed on external pins
whereas 1 UART is connected to GNSS as a dedicated interface.

On modules like MC60/MC20, GNSS port is also exposed on outside pins which provides freedom to
select any UART port to be connected to GNSS module.

So if module has three physical UART interface, the three UART device files will be:

* ``/dev/ttyS0``
* ``/dev/ttyS1``
* ``/dev/ttyS2``

Each device file supports standard system calls for IO operations (open, read, write, close etc.)

Serial port parameters can be accessed by standard termios API (similar to linux).

Example Usage
-------------

.. code-block:: c

    #include <unistd.h>
    #include <fcntl.h>
    #include <termios.h>

    /* Open uart */
    int fd = open("/dev/ttyS0");

    /* Set baudrate */
    tcgetattr(fd, &t);
    cfsetspeed(&t, B9600);
    tcsetattr(fd, TCSANOW, &t);

    /* write on uart */
    write(fd, "Test", 4);

    /* read */
    int ret;
    char buf[10];

    ret = read(fd, buf, sizeof(buf));


Application Example
-------------------

.. raw:: html

	<p><i class="fa fa-github"></i> <a href="https://github.com/waybyte/example-uart" target="_blank">waybyte/example-uart</a></p>


4G LTE Module Pin Mapping
-------------------------

+---------------+-----------+-----------+----------+----------+----------+----------+
| UART Function |  EC600U   |  EC200U   |  N58     |  N716    |  L610    |  EG915U  |
+===============+===========+===========+==========+==========+==========+==========+
| UART0 TXD     |  Pin 32   |  Pin 67   |  Pin 46  |  Pin 59  |  Pin 67  |  Pin 35  |
+---------------+-----------+-----------+----------+----------+----------+----------+
| UART0 RXD     |  Pin 31   |  Pin 68   |  Pin 47  |  Pin 58  |  Pin 68  |  Pin 34  |
+---------------+-----------+-----------+----------+----------+----------+----------+
| UART1 TXD     |  Pin 124  |  Pin 139  |  Pin 69  |  Pin 11  |  Pin 139 |  Pin 27  |
+---------------+-----------+-----------+----------+----------+----------+----------+
| UART1 RXD     |  Pin 123  |  Pin 136  |  Pin 70  |  Pin 12  |  Pin 136 |  Pin 28  |
+---------------+-----------+-----------+----------+----------+----------+----------+
| UART2 TXD     |  Pin 103  |  Pin 82   |  GNSS RX |  Pin 9   |  Pin 82  |  Pin 23  |
+---------------+-----------+-----------+----------+----------+----------+----------+
| UART2 RXD     |  Pin 104  |  Pin 81   |  GNSS TX |  Pin 10  |  Pin 81  |  Pin 22  |
+---------------+-----------+-----------+----------+----------+----------+----------+


GSM Module Pin Mapping
----------------------

RDA8955 based modules
^^^^^^^^^^^^^^^^^^^^^

+---------------+-----------+-----------+----------+
| UART Function |  M590     |  MC65     |  A9      |
+===============+===========+===========+==========+
| UART0 TXD     |  Pin 8    |  Pin 34   |  Pin 54  |
+---------------+-----------+-----------+----------+
| UART0 RXD     |  Pin 7    |  Pin 33   |  Pin 53  |
+---------------+-----------+-----------+----------+
| UART1 TXD     |  Pin 58   |  Pin 25   |  Pin 50  |
+---------------+-----------+-----------+----------+
| UART1 RXD     |  Pin 59   |  Pin 24   |  Pin 49  |
+---------------+-----------+-----------+----------+


MT2503/MT6261/MT2625 based modules
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------+------------------+-----------+-----------------+-----------+------------+
| UART Function |  MC20 Pin        |  M56 Pin  |  MC60 Pin       |  M66 Pin  |  SIM868    |
|               |  |br| MC20U Pin  |           |                 |           |  Pin       |
+===============+==================+===========+=================+===========+============+
| UART0 TXD     |  Pin 34          |  Pin 25   |  Pin 33         |  Pin 17   |  Pin 1     |
+---------------+------------------+-----------+-----------------+-----------+------------+
| UART0 RXD     |  Pin 33          |  Pin 36   |  Pin 34         |  Pin 18   |  Pin 2     |
+---------------+------------------+-----------+-----------------+-----------+------------+
| UART1 TXD     |  Pin 25          |  Pin 41   |  Pin 25         |  Pin 29   |  Pin 22    |
+---------------+------------------+-----------+-----------------+-----------+------------+
| UART1 RXD     |  Pin 24          |  Pin 40   |  Pin 24         |  Pin 28   |  Pin 23    |
+---------------+------------------+-----------+-----------------+-----------+------------+
| UART2 TXD     |  Pin 29          |  Pin 13   |  Pin 29         |  Pin 39   |     --     |
+---------------+------------------+-----------+-----------------+-----------+------------+
| UART2 RXD     |  Pin 30          |  Pin 2    |  Pin 30         |  Pin 38   |     --     |
+---------------+------------------+-----------+-----------------+-----------+------------+


API Reference
-------------

:doc:`Termios Systemcall Support <../system/syscall/termios>` 
