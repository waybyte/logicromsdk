I2C
===
.. |br| raw:: html

	<br>

I2C driver provide access to hardware I2C bus controller and currently only support
bus communication in master mode.

.. note:: MT2503/MT6261 has a buffer limitation of maximum 8 byte read/write in single
	transaction. Writing more than 8 byte require multiple read/write operation.

I2C Driver Usage
----------------

.. code-block:: c

	#include <hw/i2c.h>

	/* initialize I2C port */
	i2c_hw_init(I2C_PORT_0, 100);

	/* i2c write */
	i2c_hw_write(I2C_PORT_0, 0x20, write_buf, length);

	/* i2c read */
	i2c_hw_read(I2C_PORT_0, 0x20, read_buf, length);

	/* i2c write then read */
	i2c_hw_writeread(I2C_PORT_0, 0x20, write_buf, wr_len, read_buf, rd_len);

	/* release i2c bus */
	i2c_hw_free(I2C_PORT_0);


Application Example
-------------------

.. raw:: html

	<p><i class="fa fa-github"></i> <a href="https://github.com/waybyte/example-i2c" target="_blank">waybyte/example-i2c</a></p>


4G LTE Module I2C Port Mapping
------------------------------

I2C Port 0
^^^^^^^^^^

+---------+-----------+-----------+----------+----------+----------+----------+
| I2C Pin |  EC600U   |  EC200U   |  N58     |  N716    |  L610    |  EG915U  |
+=========+===========+===========+==========+==========+==========+==========+
| SCL     |  Pin 11   |  Pin 41   |  Pin 59  |  Pin 122 |  Pin 41  |  Pin 103 |
+---------+-----------+-----------+----------+----------+----------+----------+
| SDA     |  Pin 12   |  Pin 42   |  Pin 58  |  Pin 121 |  Pin 42  |  Pin 114 |
+---------+-----------+-----------+----------+----------+----------+----------+

I2C Port 1
^^^^^^^^^^

+---------+-----------+-----------+----------+----------+----------+----------+
| I2C Pin |  EC600U   |  EC200U   |  N58     |  N716    |  L610    |  EG915U  |
+=========+===========+===========+==========+==========+==========+==========+
| SCL     |  Pin 57   |  Pin 141  |  Pin 82  |  Pin 71  |  Pin 141 |  Pin 40  |
+---------+-----------+-----------+----------+----------+----------+----------+
| SDA     |  Pin 56   |  Pin 142  |  Pin 81  |  Pin 70  |  Pin 142 |  Pin 41  |
+---------+-----------+-----------+----------+----------+----------+----------+



GSM/NB-IoT Module I2C Port Mapping
----------------------------------

GSM (MT2503, MT6261) and NB-IoT (MT2625) chipset supported modules expose only one
I2C port. Following is the pin mapping for SCL and SDA:

+---------+-----------+-------------------+-----------+------------+------------+
| I2C Pin |  M56 Pin  |  MC60 Pin         |  M66 Pin  |  BC20 Pin  |  SIM868    |
|         |           |  |br| MC20(U) Pin |           |            |  Pin       |
+=========+===========+===================+===========+============+============+
| SCL     |  Pin 24   |  Pin 35           |  Pin 20   |  Pin 58    |  Pin 65    |
+---------+-----------+-------------------+-----------+------------+------------+
| SDA     |  Pin 23   |  Pin 36           |  Pin 21   |  Pin 63    |  Pin 64    |
+---------+-----------+-------------------+-----------+------------+------------+


API Reference
-------------

.. include:: /inc/i2c.inc
.. include:: /inc/def_i2c.inc

