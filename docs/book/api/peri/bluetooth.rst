Bluetooth
=========

SiWi GSM module supports BT3.0 with EDR can work in BT host and client mode.

Currently only SPP profile is supported by SDK.

System create device file /dev/bthost0 for host mode of operation. This file
can be used to perform standard IO operations (open, close, read, write etc.).
SDK also provide api to enable console over bluetooth, If console is enabled
then host operation file will not be available for application.

For client mode of opeartion device files are created under /dev/btclient/
after Bluetooth device search is performed. Application can initiate pairing
and standard io operation can then be performed via system calls.

API Reference
-------------

.. .. include:: /inc/bluetooth.inc

