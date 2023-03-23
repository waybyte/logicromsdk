.. logicromsdk documentation master file, created by
   sphinx-quickstart on Mon May 25 18:39:44 2020.

Logicrom IoT SDK
================

.. |br| raw:: html

	<br>

Logicrom Software Development Kit is a framework for Wireless IoT development
on 4G LTE Cat.1 (RDA8910, ASR1601, ASR1603), GSM (MT2503, MT6261, RDA8955) and
NBIoT (MT2625) chipsets/modules.

Supported Modules
-----------------

+-------------------+----------+-------------+-----------------------+-----------------+
| Name              | Vendor   | SoC/Chipset | Supported Peripherals | APP RAM / ROM   |
+-------------------+----------+-------------+-----------------------+-----------------+
| EC200U-XX-YY [1]_ | Quectel  | RDA8910     |  UART, USB, SPI, I2C, | 500 KB / 1 MB   |
+-------------------+          |             |  ADC, LCD,            |                 |
| EC600U-XX-YY [1]_ |          |             |  Camera [2]_,         |                 |
+-------------------+          |             |  GNSS [3]_            |                 |
| EC600U-XX-YY [1]_ |          |             |                       |                 |
+-------------------+          |             |                       |                 |
| EG915U-XX-YY [1]_ |          |             |                       |                 |
+-------------------+----------+             |                       |                 |
| N58-CA            | Neoway   |             |                       |                 |
+-------------------+          |             |                       |                 |
| N716-CA           |          |             |                       |                 |
+-------------------+----------+-------------+-----------------------+-----------------+
| EC100N-XX-XX |br| | Quectel  | ASR1603     |  UART, USB, SPI, I2C, | 512 KB / 1 MB   |
+-------------------+          |             |  ADC, LCD [2]_        +-----------------+
| EC200N-CN-AA |br| |          |             |                       | 512 KB / 512 KB |
+-------------------+          |             |                       +-----------------+
| EC600N-CN-AA |br| |          |             |                       | 512 KB / 1 MB   |
+-------------------+          |             |                       +-----------------+
| EG912Y-EU-YY |br| |          |             |                       | 512 KB / 1 MB   |
+-------------------+          |             |                       +-----------------+
| EG915N-EU-YY |br| |          |             |                       | 512 KB / 512 KB |
+-------------------+----------+-------------+-----------------------+-----------------+
| EC100Y-CN-YY |br| | Quectel  | ASR1601     |  UART, USB, SPI, I2C, | 512 KB / 512 KB |
+-------------------+          |             |  ADC, LCD [2]_        +-----------------+
| EC100S-CN-YY |br| |          |             |                       | 512 KB / 1 MB   |
+-------------------+          |             |                       +-----------------+
| EC600S-CN-YY |br| |          |             |                       | 512 KB / 1 MB   |
+-------------------+----------+             |                       +-----------------+
| AC7670C           | SIMCOM   |             |                       | 512 KB / 1 MB   |
+-------------------+----------+-------------+-----------------------+-----------------+
| MC20, MC60, MC20U | Quectel  | MT2503      |  UART, USB, SPI, I2C, | 94 KB / 256 KB  |
+-------------------+----------+             |  ADC, GNSS            |                 |
| SIM868            | SIMCOM   |             |                       |                 |
+-------------------+----------+-------------+-----------------------+                 |
| M66, M26, M56     | Quectel  | MT6261      |  UART, USB, SPI, I2C, |                 |
+-------------------+----------+             |  ADC                  |                 |
| SIM800            | SIMCOM   |             |                       |                 |
+-------------------+----------+-------------+-----------------------+-----------------+
| MC65              | Quectel  | RDA8955     |  UART, USB, SPI, I2C, | 1 MB / 576 KB   |
+-------------------+----------+             |  ADC, GNSS [3]_, LCD  |                 |
| M590              | Neoway   |             |                       |                 |
+-------------------+----------+             |                       |                 |
| A9, A9G           | AiThinker|             |                       |                 |
+-------------------+----------+-------------+-----------------------+-----------------+


.. [1] XX can be CN/AU/EU, YY can be AA/AB/AC
.. [2] Not Supported on logicrom
.. [3] Supported on module with GNSS

Documentation
=============

.. toctree::
   :maxdepth: 2

   Quick Start Guide <book/quick_start>
   API Reference Guide <book/api/index>
   Hardware Reference Guide <book/hw/index>
   Firmware Flashing Guide <book/flashing>
   SDK Examples <book/example>
   Bug Report <book/bugs>

Indices and tables
==================

* :ref:`genindex`

.. * :ref:`modindex`
.. * :ref:`search`

