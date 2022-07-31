Command Processor and Command Line Interface
============================================

Logicrom SDK provide in-built command processor and CLI with many features like
user authentication and command autocomplete etc.

By default SDK provide system commands and linux like core utility commands.

Available commands
------------------

+-------------------+--------------------------------------------------------+
| Command           | Description                                            |
+===================+========================================================+
| devinfo           | Get device information                                 |
+-------------------+--------------------------------------------------------+
| sysinfo           | Get system information                                 |
+-------------------+--------------------------------------------------------+
| loglevel          | Set or get current debug loglevel                      |
+-------------------+--------------------------------------------------------+
| reboot            | Reboot system                                          |
+-------------------+--------------------------------------------------------+
| ntpdate           | Get date time information from NTP server              |
+-------------------+--------------------------------------------------------+
| df                | Show information about filesystem                      |
+-------------------+--------------------------------------------------------+
| ls                | List file(s) or directory                              |
+-------------------+--------------------------------------------------------+
| echo              | Display line of text                                   |
+-------------------+--------------------------------------------------------+
| free              | Display free and used memory in the system             |
+-------------------+--------------------------------------------------------+
| cat               | Display file on standard output                        |
+-------------------+--------------------------------------------------------+
| mkdir             | Make directory                                         |
+-------------------+--------------------------------------------------------+
| rm                | Remove file or directory                               |
+-------------------+--------------------------------------------------------+
| mv                | Move file or directory                                 |
+-------------------+--------------------------------------------------------+
| format            | Format device/filesystem                               |
+-------------------+--------------------------------------------------------+
| logout            | Logout current user                                    |
+-------------------+--------------------------------------------------------+
| help              | Get command help                                       |
+-------------------+--------------------------------------------------------+

Optional Commands
^^^^^^^^^^^^^^^^^

Some commands are available only when a module is used or enabled by the
application.

Following is the list of Commands with modules.

+-----------+--------------------------------------+--------------------------------------------------------+
| Command   | Module                               | Description                                            |
+===========+======================================+========================================================+
| wget      |  :doc:`Utility <../utils/index>`     | Download file from web to filesystem                   |
+-----------+--------------------------------------+--------------------------------------------------------+
| load      |  :doc:`Utility <../utils/index>`     | Download file on module via Console (Xmodem)           |
+-----------+--------------------------------------+--------------------------------------------------------+
| dload     |  :doc:`Utility <../utils/index>`     | Download file from module via Console (Xmodem)         |
+-----------+--------------------------------------+--------------------------------------------------------+
| gpsinfo   |  :doc:`GPS <../peri/gps>`            | Get GPS realtime information                           |
+-----------+--------------------------------------+--------------------------------------------------------+
| gpscmd    |  :doc:`GPS <../peri/gps>`            | Send command to GPS module                             |
+-----------+--------------------------------------+--------------------------------------------------------+
| gpsbaud   |  :doc:`GPS <../peri/gps>`            | Change gps baudrate                                    |
+-----------+--------------------------------------+--------------------------------------------------------+
| btman     |  :doc:`Blutooth <../peri/bluetooth>` | Bluetooth manager command                              |
+-----------+--------------------------------------+--------------------------------------------------------+
| spifs     |  :doc:`SPIFS <../peri/spifs>`        | Manage SPI filesystem                                  |
+-----------+--------------------------------------+--------------------------------------------------------+
| fota      |  :doc:`FOTA <fota>`                  | Download firmware over the air                         |
+-----------+--------------------------------------+--------------------------------------------------------+
| rdbg      |  :doc:`Remote DBG <rdbg>`            | Initiate a remote debug session                        |
+-----------+--------------------------------------+--------------------------------------------------------+
| ntpdate   |  :doc:`NTP Client <../proto/ntpc>`   | Get date from NTP server and sync                      |
+-----------+--------------------------------------+--------------------------------------------------------+

Following commands are available on 4G modules only

+-------------------+--------------------------------------------------------+
| Command           | Description                                            |
+===================+========================================================+
| ifconfig          | Get network device information                         |
+-------------------+--------------------------------------------------------+
| ping              | Send ICMP ECHO REQUEST to network host                 |
+-------------------+--------------------------------------------------------+


Custom commands
^^^^^^^^^^^^^^^

Command processor APIs can be used to add new commands to the system.


Command Delimiters
------------------

Command and argument on console are seperated using following delimiters:

* Comma (,)
* Space ( )

Command and only first parameter can also be seperated by an equal (=) symbol. So following
formats for comamnd is valid on console

.. code-block:: bash

	$ command=parameter
	$ command parameter
	$ command,parameter
	# multi parameter commands
	$ command=param1,param2
	$ command=param1 param2
	$ command param1 param2
	$ command,param1,param2

Parameter Escaping
^^^^^^^^^^^^^^^^^^

To escape parameter with comma a quote can be used. For example:

.. code-block:: bash

	$ command="param1,continued",param2

To escape quote, a backslash can be used:

.. code-block:: bash

	$ command="param1,continued with a \"quote\"",param2


Application Example
-------------------

.. raw:: html

	<p><i class="fa fa-github"></i> <a href="https://github.com/waybyte/example-console" target="_blank">waybyte/example-console</a></p>


Command Processor API Reference
-------------------------------

.. include:: /inc/command.inc

Console API Reference
---------------------

.. include:: /inc/console.inc

