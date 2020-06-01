Filesystems
===========

SDK provide in-built filesystem support for various storage device like onboard
flash, external SPI flash and SD Card. Flash filesystems are optimized and with
wear leveling support. This prevents storage media from damaging because of
excessive write/erase operations.

System has internal 315KB of flash available for storage.
There is also provision for RAM filesystem with filesize limit of 1KB per file.
For temporary storage RAM filesystem can be used.

Internal flash is mounted on /fs and ram filesystem is mounted on /ram.
Application can read write files using standard system calls.

See application example for more information.

SPI Flash
=========

.. include:: /inc/spifs.inc
