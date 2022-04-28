Filesystems
===========

SDK provide in-built filesystem support for various storage device like onboard
flash, external SPI flash and SD Card. Flash filesystem are optimized and with
wear leveling support. This prevents storage media from damaging because of
excessive write/erase operations.

For GSM systems, internal 315KB of flash memory available for storage. There is
also provision for RAM filesystem with file size limit of 1KB per file, for
temporary storage RAM filesystem can be used.

Internal flash is mounted on /fs and ram filesystem is mounted on /ram.
Application can read write files using standard system calls.

If system has SD card connected and initialization is success, it will be mounted
on /sd.

SPI Flash memory can be enabled and will be mounted on /sf.

See application example for more information.

See Also
--------

:doc:`Supported Standard IO system calls <../system/syscall/stdio>`

:doc:`SD/MMC Driver API <../peri/sdmmc>`

:doc:`SPI Flash Driver API <../peri/spifs>`
