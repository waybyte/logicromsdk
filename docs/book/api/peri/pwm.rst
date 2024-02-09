PWM
===

.. |br| raw:: html

	<br>


4G LTE Module PWM Channel Mapping
---------------------------------

.. note:: PWM Channel 1 on RDA8910 and RDA8955 based modules has limited configurable period and duty cycle.

+--------------+-----------+-----------+----------+----------+----------+----------+
| PWM Channel  |  EC600U   |  EC200U   |  N58     |  N716    |  L610    |  EG915U  |
+==============+===========+===========+==========+==========+==========+==========+
| PWM CH 0     |  Pin 70   |  Pin 135  |  Pin 39  |  Pin 38  |  Pin 135 |  Pin 20  |
+--------------+-----------+-----------+----------+----------+----------+----------+
| PWM CH 1     |  Pin 54   |  Pin 5    |    --    |  Pin 67  |  Pin 5   |  Pin 21  |
+--------------+-----------+-----------+----------+----------+----------+----------+


GSM/NB-IoT Module PWM Channel Mapping
-------------------------------------

RDA8955 based modules
^^^^^^^^^^^^^^^^^^^^^

+--------------+------------+------------+----------+
| PWM Channel  |  M590 Pin  |  MC65 Pin  |  A9 Pin  |
+==============+============+============+==========+
| PWM CH 0     |  Pin 58    |  Pin 25    |  Pin 50  |
+--------------+------------+------------+----------+
| PWM CH 1     |  Pin 59    |  Pin 24    |  Pin 49  |
+--------------+------------+------------+----------+


MT2503/MT6261/MT2625 based modules
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+--------------+-----------+-------------------+-----------+------------+------------+
| PWM Channel  |  M56 Pin  |  MC60 Pin         |  M66 Pin  |  BC20 Pin  |  SIM868    |
|              |           |  |br| MC20(U) Pin |           |            |  Pin       |
+==============+===========+===================+===========+============+============+
| PWM CH 0     |  Pin 12   |  Pin 47           |  Pin 16   |  Pin 47    |  Pin 6     |
+--------------+-----------+-------------------+-----------+------------+------------+
| PWM CH 1     |  Pin 27   |  Pin 28           |  --       |  Pin 3     |  Pin 57    |
+--------------+-----------+-------------------+-----------+------------+------------+
| PWM CH 2     |  --       |  --               |  --       |  Pin 36    |  --        |
+--------------+-----------+-------------------+-----------+------------+------------+
| PWM CH 4     |  --       |  --               |  --       |  Pin 61    |  --        |
+--------------+-----------+-------------------+-----------+------------+------------+


Example Usage
-------------

.. code-block:: c

	#include <hw/pwm.h>

	/* Init PWM */
	pwm_init(PWM_CH0);

	/* configure PWM @ 1Khz 50% duty */
	pwm_config(PWM_CH0, 1000, 50);

	/* start pwm */
	pwm_start(PWM_CH0);

	/* stop PWM */
	pwm_stop(PWM_CH0);

	/* free PWM */
	pwm_free(PWM_CH0);


Application Example
-------------------

.. raw:: html

	<p><i class="fa fa-github"></i> <a href="https://github.com/waybyte/example-pwm" target="_blank">waybyte/example-pwm</a></p>


API Reference
-------------

.. include:: /inc/pwm.inc

.. note:: Please refer header file for actual number of channels available for respective board.

.. include:: /inc/def_pwm.inc
