Command Processor and Console
=============================

SDK provide in-built command processor and console with many features like
User authentication and command autocomplete etc.

By default SDK provide system commands and linux like core utility commands.

Available commands
^^^^^^^^^^^^^^^^^^
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
---------------
Command processor APIs can be used to add new commands to the system.

Command Processor API Reference
-------------------------------

.. include:: /inc/command.inc

Console API Reference
---------------------

.. include:: /inc/console.inc

