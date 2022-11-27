Bluetooth
=========

On RDA8910 chipset, BT 4.2 dual mode is available. However Logicrom currently only
support BLE mode of operation as GATT server for Bluetooth CLI operation. More
features will be added in future release.

On MT2503/MT6261 chipset, BT3.0 with EDR can work in BT host and client mode. No BLE
is available.

Currently only SPP profile is supported by SDK.

System create device file ``/dev/bthost0`` for host mode of operation. This file
can be used to perform standard IO operations (open, close, read, write etc.).
SDK also provide api to enable console over bluetooth, If console is enabled
then host operation file will not be available for application.

For client mode of operation device files are created under ``/dev/btclient/``
after Bluetooth device search is performed. Application can initiate pairing
and standard io operation can then be performed via system calls.


Example Usage
-------------

.. code-block:: c

    #include <hw/bluetooth.h>

    /*
     * For 4G Modules
     * 
     * Initialize BT in BLE mode, with CLI enable
     */
    bt_device_init(BT_LE, "Custom Name", TRUE);

    /*
     * For 2G Modules
     * 
     * Initialize BT in classic mode with CLI enable
     */
    bt_device_init(BT_CLASSIC, "Custom Name", TRUE);



API Reference
-------------

.. include:: /inc/bluetooth.inc

