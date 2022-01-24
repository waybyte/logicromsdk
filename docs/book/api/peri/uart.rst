UART
====

There are three UART port available on module which gets registered on VFS as
device files:

* /dev/ttyS0
* /dev/ttyS1
* /dev/ttyS2

Each device file supports standard system calls for IO operations.

Serial port parameters can be accessed by standard termios API (similar to
linux).

