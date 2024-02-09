Core Firmware Flashing
======================

Tools Required
--------------

Following are the list of tools that can be used to flash Logicrom core firmware:

+-----------------+---------------------------+----------------------------------------------------------------------------------------------------------------------------------+
| SoC / Chipset   | Flashtool                 | Download Link                                                                                                                    |
+-----------------+---------------------------+----------------------------------------------------------------------------------------------------------------------------------+
| RDA8910         | Logicrom Flasher          | `Logicrom Flasher v25.20.39.1 <https://waybyte.in/tools/Logicrom_Flasher_Setup_v25.20.39.1.exe>`_                                |
|                 +---------------------------+----------------------------------------------------------------------------------------------------------------------------------+
|                 | QFlash                    | `QFlash_V5.0 <https://github.com/SoCXin/ASR1601/releases/download/1.0.0/QFlash_V5.0.zip>`_                                       |
+-----------------+---------------------------+----------------------------------------------------------------------------------------------------------------------------------+
| ASR1601/ASR1603 | Aboot                     | `aboot-tools-2020.11.20-win-x64 <https://github.com/SoCXin/ASR1601/releases/download/1.0.0/aboot-tools-2020.11.20-win-x64.exe>`_ |
|                 +---------------------------+----------------------------------------------------------------------------------------------------------------------------------+
|                 | QFlash                    | `QFlash_V5.0 <https://github.com/SoCXin/ASR1601/releases/download/1.0.0/QFlash_V5.0.zip>`_                                       |
+-----------------+---------------------------+----------------------------------------------------------------------------------------------------------------------------------+
| RDA8955         | Coolwatcher               | `cooltools RDA8955 <https://www.openluat.com/Product/file/rda8955/cooltools.7z>`_                                                |
|                 +---------------------------+----------------------------------------------------------------------------------------------------------------------------------+
|                 | Firmware Update tool [1]_ | `firmwarw_tool_v2.1 <https://docs.ai-thinker.com/_media/gprs/tools/firmwarw_tool_v2.1.7z>`_                                      |
+-----------------+---------------------------+----------------------------------------------------------------------------------------------------------------------------------+
| MT2593/MT6261   | Logicrom GSM Flasher      | `Logicrom GSM Flasher v2.1.0 <https://waybyte.in/tools/Logicrom_GSM_Flasher_Setup_v2.1.0.exe>`_                                  |
|                 +---------------------------+----------------------------------------------------------------------------------------------------------------------------------+
|                 | IDE Flashing              | :doc:`MT2503/MT6261 Core Re-Flashing <core_reflash>`                                                                             |
+-----------------+---------------------------+----------------------------------------------------------------------------------------------------------------------------------+

.. [1] use **fpupgrade.exe** only. **DO NOT** use fpdownload.exe, it will erase all calibration and IMEI information.


Core Firmware Download
----------------------

Logicrom core firmware for supported modules can be downloaded from github
page: https://github.com/waybyte/logicrom_core

.. list-table::
    :widths: 25 75
    :header-rows: 1

    * - Module Name
      - Latest Core
    * - RDA8955
      - `Logicrom_rda8955_core_v0.4.0.lod <https://github.com/waybyte/logicrom_core/blob/master/2G_RDA8955/Logicrom_rda8955_core_v0.4.0.lod>`_
    * - A7670C
      - `Logicrom_ASR1601_A7670C_v0.4.0.zip <https://github.com/waybyte/logicrom_core/blob/master/A7670C/Logicrom_ASR1601_A7670C_v0.4.0.zip>`_
    * - A7672E
      - `Logicrom_ASR1603_A7672E_v0.4.0_VOLTE.zip <https://github.com/waybyte/logicrom_core/blob/master/A7672E/Logicrom_ASR1603_A7672E_v0.4.0_VOLTE.zip>`_
    * - EC100N-CN
      - `Logicrom_ASR1603_EC100NCN_v0.4.0.zip <https://github.com/waybyte/logicrom_core/blob/master/EC100N-CN/Logicrom_ASR1603_EC100NCN_v0.4.0.zip>`_
    * - EC100Y-CN-AA
      - `Logicrom_ASR1601_EC100YCN_v0.4.0.zip <https://github.com/waybyte/logicrom_core/blob/master/EC100Y-CN-AA/Logicrom_ASR1601_EC100YCN_v0.4.0.zip>`_
    * - EC200N-CN-AA
      - `Logicrom_ASR1603_EC200NCN_v0.4.0.zip <https://github.com/waybyte/logicrom_core/blob/master/EC200N-CN-AA/Logicrom_ASR1603_EC200NCN_v0.4.0.zip>`_
    * - EC200N-CN-LA
      - `Logicrom_ASR1603_EC200NCNLA_v0.4.0.zip <https://github.com/waybyte/logicrom_core/blob/master/EC200N-CN-LA/Logicrom_ASR1603_EC200NCNLA_v0.4.0.zip>`_
    * - EC200S-CN-AB
      - `Logicrom_ASR1601_EC200SCNAB_v0.4.0.zip <https://github.com/waybyte/logicrom_core/blob/master/EC200S-CN-AB/Logicrom_ASR1601_EC200SCNAB_v0.4.0.zip>`_
    * - EC200U-CN-AA
      - `EC200UCN-AA_LOGICROM_v0.4.0_VoLTE.pac <https://github.com/waybyte/logicrom_core/blob/master/EC200U-CN-AA/EC200UCN-AA_LOGICROM_v0.4.0_VoLTE.pac>`_
    * - EC200U-CN-AB
      - `EC200UCN-AB_LOGICROM_v0.4.0_VoLTE.pac <https://github.com/waybyte/logicrom_core/blob/master/EC200U-CN-AA/EC200UCN-AB_LOGICROM_v0.4.0_VoLTE.pac>`_
    * - EC200U-EU
      - `EC200UEU_LOGICROM_v0.4.0_VoLTE.pac <https://github.com/waybyte/logicrom_core/blob/master/EC200U-EU/EC200UEU_LOGICROM_v0.4.0_VoLTE.pac>`_
    * - EC600N-CN-AA
      - `Logicrom_ASR1603_EC600NCN_v0.4.0.zip <https://github.com/waybyte/logicrom_core/blob/master/EC600N-CN-AA/Logicrom_ASR1603_EC600NCN_v0.4.0.zip>`_
    * - EC600S-CN
      - `Logicrom_ASR1601_EC600SCN_v0.4.0.zip <https://github.com/waybyte/logicrom_core/blob/master/EC600S-CN/Logicrom_ASR1601_EC600SCN_v0.4.0.zip>`_
    * - EC600U-CN
      - `EC600UCN-LB_LOGICROM_v0.4.0_VoLTE.pac <https://github.com/waybyte/logicrom_core/blob/master/EC600U-CN/EC600UCN-LB_LOGICROM_v0.4.0_VoLTE.pac>`_
    * - EG912Y-EU
      - `Logicrom_ASR1603_EG912YEU_v0.4.0.zip <https://github.com/waybyte/logicrom_core/blob/master/EG912Y-EU/Logicrom_ASR1603_EG912YEU_v0.4.0.zip>`_
    * - EG915N-EU
      - `Logicrom_ASR1603_EG915NEU_v0.4.0.zip <https://github.com/waybyte/logicrom_core/blob/master/EG915N-EU/Logicrom_ASR1603_EG915NEU_v0.4.0.zip>`_
    * - EG915U-EU
      - `EG915UEU-AB_LOGICROM_v0.4.0_VoLTE.pac <https://github.com/waybyte/logicrom_core/blob/master/EG915U-EU/EG915UEU-AB_LOGICROM_v0.4.0_VoLTE.pac>`_
    * - L610-CN
      - `L610-CN-00_LOGICROM_v0.4.0_VoLTE.pac <https://github.com/waybyte/logicrom_core/blob/master/L610-CN/L610-CN-00_LOGICROM_v0.4.0_VoLTE.pac>`_
    * - N58-CA
      - `N58-CA_LOGICROM_v0.4.0_VoLTE.pac <https://github.com/waybyte/logicrom_core/blob/master/N58-CA/N58-CA_LOGICROM_v0.4.0_VoLTE.pac>`_
    * - N716-CA
      - `N716-CA_LOGICROM_v0.4.0_VoLTE.pac <https://github.com/waybyte/logicrom_core/blob/master/N716-CA/N716-CA_LOGICROM_v0.4.0_VoLTE.pac>`_


Put Device in Bootloader Mode
-----------------------------

In order to start flashing, module must be put in Bootloader mode. The procedure for entering bootloader is different for all chipset.
Following are the steps for modules based on their chipset type.

RDA8910/UIS8910
^^^^^^^^^^^^^^^

- **AT Command Method**

  1. Open USB AT command port
  2. Check port is working, by entering "AT" and modem should respond "OK".
  3. | Enter AT command to put module is USB download:
     | For other vendors and Logicrom core: AT^FORCEDND
     | For Quectel, boot mode command is: AT+QDOWNLOAD=1

- **Force USB Boot Hardware Method**

  1. Locate USB_BOOT and VDD_EXT pin from hardware reference manual of module.
  2. Connect USB_BOOT with VDD_EXT directly or via resistor.
  3. Reset module, it should now be in USB boot mode.

To check if device is in boot mode or not, open Device Manager. There should
be a USB serial port with name "SPRD U2S Diag". If you do not see the port in
device manager, There could be two possibilities:

1. Device is not in USB boot, Follow any of the two steps mentioned above.
2. If you do see a serial port device but with name "USB Serial Device". You can
   also verify the device by checking its VID/PID (1728/4D11). Right click on the
   device and update driver.


ASR1601/ASR1603
^^^^^^^^^^^^^^^

- **Reboot Method**

  ASR chipset runs bootloader before starting core. If bootloader has not damaged or
  corrupted, simplest way is to start flashing software and reboot the device.

- **Force USB Boot Hardware Method**

  If you happen to damage your device bootloader, you can put device in USB boot mode
  using hardware method.

  1. Locate USB_BOOT and VDD_EXT/VDD_1V8 pin from hardware reference manual of module.
  2. Connect USB_BOOT with VDD_EXT/VDD_1V8 directly or via resistor.
  3. Reset module, it should now be in USB boot mode.


RDA8955
^^^^^^^

There is no special method, just connect HOST_UART or DBG_UART of module with PC and run
flashing software.


MT2503/MT6261
^^^^^^^^^^^^^

There is no special method, just reset the device and flashing should start. If you are using
USB flashing make sure correct driver is installed and you should see device named
"MediaTek USB Port" in device manager.

.. toctree::
  :hidden:

