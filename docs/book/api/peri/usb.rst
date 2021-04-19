USB
===

MT2503 chipset provide USB 1.1 interface with CDC(ACM) profile. USB port
can be used to interface device with a USB host for communication.

SDK registers USB serial port as a device file /dev/ttyUSB0 which supports
standard system calls for IO operations and termios API for serial port
parameter controls.

There are no USB specific APIs.

