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
| cat               | Display file on standard output                        |
+-------------------+--------------------------------------------------------+
| mkdir             | Make directory                                         |
+-------------------+--------------------------------------------------------+
| rm                | Remove file or directory                               |
+-------------------+--------------------------------------------------------+
| mv                | Move file or directory                                 |
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

*TODO: optional command list to be added*

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

