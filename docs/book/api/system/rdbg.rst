Remote Console/Debugging
========================

Logicrom provide in-built remote debugging console that runs over a TCP socket.

A remote console session can be initiated by sending *rdbg* command. Device
opens up a TCP socket to the server and port provided in the command. When
device is connected to server, it sends a message describing its identity
in following format

::

    $RDBG,[UID],[IMEI]#[CR][LF]


Where UID is device unique ID, and IMEI is module's IMEI.

After the identity string, login prompt is shown. Once logged in, complete
command line interface is available for device interaction.


Example Usage
--------------

To add remote debug command to system:

.. code-block:: c

    #include <remotedbg.h>

    remote_debug_enable();

Command Line Usage
^^^^^^^^^^^^^^^^^^

.. code-block:: bash

    # Initate remote debug
    $ rdbg=<IP/domain>,<port>

    # close remote session
    $ rdbg=close


API Reference
-------------

.. include:: /inc/remotedbg.inc
