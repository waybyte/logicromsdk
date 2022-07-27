SPI
===

.. |br| raw:: html

	<br>

Logicrom SPI driver provide complete access to SPI hardware in master mode of
operation. GSM Modules based on MT2503/MT6261 exposes one SPI port, whereas
RDA8910 provide 2 ports.

Chip Select Control
-------------------

MT2503/MT6261
^^^^^^^^^^^^^

Chip select (CS) line on GSM module doubles as GPIO. SPI driver provide option to
let SPI controller Control CS line per transaction basis or CS line can be controlled
by application using GPIO APIs.

RDA8910
^^^^^^^

SPI controller on LTE module has dedicated CS line which cannot be used as GPIO, However
driver provide API to manually control the CS pin when its not configured to be controlled
by SPI controller.

Example Usage
-------------

.. code-block:: c

	#include <hw/spi.h>

	/*
	 * Init SPI Port
	 * 
	 * Hardware controlled CS not used
	 * SPI Mode 0
	 * 10Mhz speed
	 * Chip select polarity low
	 */
	spi_hw_init(SPI_PORT_0, false, 10000000U, SPI_MODE0, SPI_CSPOL_LOW);

	/* spi transfer */
	spi_hw_transfer(SPI_PORT_0, write_buf, read_buf, length);

	/* spi write only */
	spi_hw_transfer(SPI_PORT_0, write_buf, NULL, length);

	/* spi read only */
	spi_hw_transfer(SPI_PORT_0, NULL, read_buf, length);

	/* release SPI port */
	spi_hw_free(SPI_PORT_0);


Application Example
-------------------

.. raw:: html

	<p><i class="fa fa-github"></i> <a href="https://github.com/waybyte/example-spi" target="_blank">waybyte/example-spi</a></p>


4G LTE Module SPI Port Mapping
------------------------------

SPI Port 0
^^^^^^^^^^

+---------+-----------+-----------+----------+----------+----------+----------+
| SPI Pin |  EC600U   |  EC200U*  |  N58     |  N716    |  L610    |  EG915U  |
+=========+===========+===========+==========+==========+==========+==========+
| MISO    |  Pin 1    |  Pin 40   |  Pin 84  |  Pin 6   |  Pin 40  |  Pin 26  |
+---------+-----------+-----------+----------+----------+----------+----------+
| MOSI    |  Pin 4    |  Pin 37   |  Pin 87  |  Pin 7   |  Pin 37  |  Pin 25  |
+---------+-----------+-----------+----------+----------+----------+----------+
| CLK     |  Pin 3    |  Pin 38   |  Pin 86  |  Pin 5   |  Pin 38  |  Pin 64  |
+---------+-----------+-----------+----------+----------+----------+----------+
| CS      |  Pin 2    |  Pin 39   |  Pin 85  |  Pin 4   |  Pin 39  |  Pin 88  |
+---------+-----------+-----------+----------+----------+----------+----------+

.. note::  SPI Port 0 is not available on EC200U with integrated GNSS


SPI Port 1
^^^^^^^^^^

+---------+-----------+-----------+----------+----------+----------+----------+
| SPI Pin |  EC600U   |  EC200U   |  N58     |  N716    |  L610    |  EG915U  |
+=========+===========+===========+==========+==========+==========+==========+
| MISO    |  Pin 60   |  Pin 25   |  Pin 78  |  Pin 102 |  Pin 25  |  Pin 7   |
+---------+-----------+-----------+----------+----------+----------+----------+
| MOSI    |  Pin 59   |  Pin 24   |  Pin 80  |  Pin 101 |  Pin 24  |  Pin 6   |
+---------+-----------+-----------+----------+----------+----------+----------+
| CLK     |  Pin 61   |  Pin 27   |  Pin 50  |  Pin 99  |  Pin 27  |  Pin 4   |
+---------+-----------+-----------+----------+----------+----------+----------+
| CS      |  Pin 58   |  Pin 26   |  Pin 90  |  Pin 100 |  Pin 26  |  Pin 5   |
+---------+-----------+-----------+----------+----------+----------+----------+


GSM/NB-IoT Module SPI Port Mapping
----------------------------------

GSM (MT2503, MT6261) and NB-IoT (MT2625) chipset supported modules expose only one
I2C port. Following is the pin mapping for SPI Port 0.

+---------+-----------+-------------------+-----------+------------+------------+
| SPI Pin |  M56 Pin  |  MC60 Pin         |  M66 Pin  |  BC20 Pin  |  SIM868    |
|         |           |  |br| MC20(U) Pin |           |            |  Pin       |
+=========+===========+===================+===========+============+============+
| MISO    |  Pin 15   |  Pin 61           |  Pin 31   |  Pin 61    |  Pin 41    |
+---------+-----------+-------------------+-----------+------------+------------+
| MOSI    |  Pin 16   |  Pin 60           |  Pin 33   |  Pin 60    |  Pin 42    |
+---------+-----------+-------------------+-----------+------------+------------+
| CLK     |  Pin 18   |  Pin 62           |  Pin 32   |  Pin 62    |  Pin 7     |
+---------+-----------+-------------------+-----------+------------+------------+
| CS      |  Pin 4    |  Pin 59           |  Pin 30   |  Pin 59    |  Pin 5     |
+---------+-----------+-------------------+-----------+------------+------------+


API Reference
-------------

.. include:: /inc/spi.inc
.. include:: /inc/def_spi.inc

