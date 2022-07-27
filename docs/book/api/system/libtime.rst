System Clock Management
=======================

Logicrom provide system clock management using a time library with support
for multiple time sources to sync system clock. Each time source has a priority
predefined by the library.

Available time sources based on priority:

* Network service provider (lowest priority)
* NTP Service (available when enabled)
* GPS Time (highest priority, available when gps library is used)

A custom time source can also be added using time source API.


API Reference
-------------

.. include:: /inc/libtime.inc
