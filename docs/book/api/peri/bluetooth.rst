Bluetooth
=========

RDA8910
-------

On the RDA8910 chipset, BT 4.2 dual mode is available. However, Logicrom currently only
supports BLE mode of operation as a GATT server and GATT client for connecting other external
BLE devices.

BLE server can be used either in command line interface mode or as a Bluetooth serial port.
When using in BLE serial port mode, a device file is created with the name ``/dev/blehost0``
which supports standard IO calls similar to UART. Refer to the :doc:`UART API <uart>` for
more information.

The SDK offers GATT client interface APIs to facilitate interaction with external BLE devices.
These APIs enable various operations, including:

- **Search**: Discover available BLE devices in the vicinity.

- **Find Services**: Identify services offered by the connected BLE device.

- **Find Characteristics and Descriptors**: Explore specific characteristics and associated descriptors within the discovered services.

- **Read/Write Characteristic**: Retrieve information from or send data to the identified characteristics.

BLE API Reference
-----------------

.. toctree::
   :maxdepth: 2

    Bluetooth LE <bt_le>


MT2503/MT6261
-------------

On MediaTek GSM chipset, BT3.0 with EDR can work in BT host and client mode. Currently, only
the SPP profile is supported by the SDK. BT host supports command line interface mode and
BT serial (SPP) mode. In BT serial mode, a device file with the name ``/dev/bthost0`` is
created to use Bluetooth host as a standard UART interface. Refer to the :doc:`UART API <uart>`
for more information.

For client mode of operation, device files are created under ``/dev/btclient/`` after
Bluetooth device search is performed. The application can initiate pairing, and standard IO operation
can then be performed via system calls.


Bluetooth API Reference
-----------------------

.. toctree::
   :maxdepth: 2

    Bluetooth Classic <bt_classic>


.. note:: Some ASR1603 based module has Bluetooth hardware support but it is not currently supported by Logicrom OpenCPU SDK.


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
