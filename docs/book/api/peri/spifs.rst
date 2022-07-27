SPI Flash Fileystem API
=======================

SPI Flash when enabled is mounted on VFS path "/sf" with LittleFS filesystem.

Chip Select Selection
^^^^^^^^^^^^^^^^^^^^^

On 4G modules, when hardware chipselect is used for SPI flash, it is recommended
to provide gpio_cs as -1 or GPIO_PIN_MAX. In other cases a GPIO number can be
provided for chipselect.

On 2G modules, only GPIO number is allowed as a valid parameter for chipselect.
Even when hardware chipselect line is used, the corresponding GPIO number must
provided for gpio_cs.


Example Usage
-------------

.. code-block:: c

    #include <spifs.h>

	/* Enable and mount SPIFS */
    /* On 4G module when hardware CS line is used */
	spifs_enable(SPI_PORT_0, -1, 10000000U, SPI_MODE0);

    /* On 4G/2G module with GPIO line as chipselect */
    spifs_enable(SPI_PORT_0, GPIO_1, 10000000U, SPI_MODE0);

    /* Disable and unmount */
    spifs_disable();


API Reference
-------------

.. include:: /inc/spifs.inc
