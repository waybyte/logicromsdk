Analog to Digital Converter
===========================

.. |br| raw:: html

	<br>

There are 10-bit analog ports available on GSM modules based on MT6261 or
MT2503. Input voltage range from 0-2.8v gives digital output of 0-1023. On
RDA8955 based modules, Input voltage range is from 0-1.8v gives digital
output of 0 - 1023.

However analog ports on NBIoT module are 12-but and input voltage range
from 0-1.4v with digital output of 0-4095.

Example Usage
-------------

.. code-block:: c

	#include <hw/adc.h>

	/* init ADC */
	adc_config(ADC_CH0);

	/* ADC Read raw */
	raw_value = adc_read(ADC_CH0);

	/* ADC Read voltage in millivolts */
	mv_value = adc_read_mv(ADC_CH0);

Application Example
-------------------

.. raw:: html

	<p><i class="fa fa-github"></i> <a href="https://github.com/waybyte/example-adc" target="_blank">waybyte/example-adc</a></p>


4G LTE Module ADC Channel Mapping
---------------------------------

+--------------+-----------+-----------+----------+----------+----------+----------+
| ADC Channel  |  EC600U   |  EC200U   |  N58     |  N716    |  L610    |  EG915U  |
+==============+===========+===========+==========+==========+==========+==========+
| ADC CH 0     |  Pin 19   |  Pin 45   |  Pin 89  |  Pin 31  |  Pin 45  |  Pin 24  |
+--------------+-----------+-----------+----------+----------+----------+----------+
| ADC CH 1     |  Pin 20   |  Pin 44   |  Pin 88  |  Pin 30  |  Pin 44  |  Pin 2   |
+--------------+-----------+-----------+----------+----------+----------+----------+
| ADC CH 2     |  Pin 133  |  Pin 43   |    --    |    --    |  Pin 43  |    --    |
+--------------+-----------+-----------+----------+----------+----------+----------+
| ADC CH 3     |  Pin 114  |    --     |    --    |    --    |    --    |    --    |
+--------------+-----------+-----------+----------+----------+----------+----------+


GSM/NB-IoT Module ADC Channel Mapping
-------------------------------------

RDA8955 based modules
^^^^^^^^^^^^^^^^^^^^^

+--------------+------------+------------+----------+
| ADC Channel  |  M590 Pin  |  MC65 Pin  |  A9 Pin  |
+==============+============+============+==========+
| ADC CH 0     |  Pin 16    |  Pin 6     |  Pin 15  |
+--------------+------------+------------+----------+
| ADC CH 1     |  Pin 17    |  Pin 47    |  Pin 16  |
+--------------+------------+------------+----------+


MT2503/MT6261/MT2625 based modules
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+--------------+------------------+-----------+-----------------+-----------+------------+------------+
| ADC Channel  |  MC20U Pin       |  M56 Pin  |  MC60 Pin       |  M66 Pin  |  BC20 Pin  |  SIM868    |
|              |                  |           |  |br| MC20 Pin  |           |            |  Pin       |
+==============+==================+===========+=================+===========+============+============+
| ADC CH 0     |  Pin 6           |  Pin 61   |  Pin 6          |  Pin 9    |  Pin 6     |  Pin 38    |
+--------------+------------------+-----------+-----------------+-----------+------------+------------+
| ADC CH 1     |  Pin 47          |  Pin 12   |  Pin 47         |  Pin 16   |  Pin 54    |  --        |
+--------------+------------------+-----------+-----------------+-----------+------------+------------+
| ADC CH 2     |  Pin 66          |  Pin 3    |  Pin 28         |  Pin 28   |  --        |  --        |
+--------------+------------------+-----------+-----------------+-----------+------------+------------+
| ADC CH 3     |  Pin 30          |  Pin 2    |  Pin 29         |  Pin 29   |  --        |  --        |
+--------------+------------------+-----------+-----------------+-----------+------------+------------+
| ADC CH 4     |  Pin 29          |  Pin 13   |  --             |  --       |  --        |  --        |
+--------------+------------------+-----------+-----------------+-----------+------------+------------+
| ADC CH 5     |  --              |  Pin 33   |  --             |  --       |  --        |  --        |
+--------------+------------------+-----------+-----------------+-----------+------------+------------+


.. include:: /inc/adc.inc

.. note:: Please refer header file for actual number of channels available for respective board.

.. include:: /inc/def_adc.inc
