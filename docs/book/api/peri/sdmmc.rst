SD/MMC Driver
=============

Following API only apply to RDA8910 and RDA8955 based modems, On 2G modems
based on MT2503/MT6261 SD card is mounted automatically if detected during
power-up.

Once card is mounted, it is available on VFS path ``/sd``. All standard file
IO operations (open, close, read, write etc.) can be performed.

Example use
-----------

.. code-block:: c

    #include <hw/sdmmc.h>

    /* To Mount SD Card */
    sdmmc_mount(CARD_TYPE_SD);

    /* To Mount EMMC */
    sdmmc_mount(CARD_TYPE_EMMC);

    /* To Unmount card */
    sdmmc_unmount();


Read More
---------

    Standard IO <../system/syscall/stdio>
    Directory <../system/syscall/dirent>
    Fileystem <../system/syscall/statvfs>


API Reference
-------------

.. include:: /inc/sdmmc.inc
