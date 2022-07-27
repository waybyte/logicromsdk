PWM
===

.. |br| raw:: html

	<br>


4G LTE Module PWM Channel Mapping
---------------------------------

.. note:: PWM Channel 1 on RD8910 based modules has limited configurable period and duty cycle.

+--------------+-----------+-----------+----------+----------+----------+----------+
| PWM Channel  |  EC600U   |  EC200U   |  N58     |  N716    |  L610    |  EG915U  |
+==============+===========+===========+==========+==========+==========+==========+
| PWM CH 0     |  Pin 70   |  Pin 135  |  Pin 39  |  Pin 38  |  Pin 135 |  Pin 20  |
+--------------+-----------+-----------+----------+----------+----------+----------+
| PWM CH 1     |  Pin 54   |  Pin 5    |    --    |  Pin 67  |  Pin 5   |  Pin 21  |
+--------------+-----------+-----------+----------+----------+----------+----------+


GSM/NB-IoT Module PWM Channel Mapping
-------------------------------------

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


Application Example
-------------------

.. raw:: html

	<p><i class="fa fa-github"></i> <a href="https://github.com/waybyte/example-pwm" target="_blank">waybyte/example-pwm</a></p>


API Reference
-------------

.. include:: /inc/pwm.inc

.. note:: Please refer header file for actual number of channels available for respective board.

.. include:: /inc/def_pwm.inc
