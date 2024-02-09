Filesystems
===========

The SDK provides built-in filesystem support for various storage devices such as
onboard flash, external SPI flash, and SD Card. Flash filesystems are optimized
and equipped with wear leveling support to prevent storage media damage due to
excessive write/erase operations.

The amount of onboard filesystem space varies depending on the chipset used. Below
is the available memory for each chipset:

.. csv-table::
   :header: "Chipset Type", "Internal FS Memory"
   :widths: 20, 20

   "RDA8910", "1.4MB"
   "ASR160x (8M)", "1MB"
   "ASR160x (16M)", "2MB"
   "MT2503/MT6261", "315KB"
   "RDA8955", "952KB"

Additionally, there is provision for RAM filesystem on MT2503/MT6261 with a file size
limit of 1KB per file. RAM filesystems can be used for temporary storage.

The internal flash is mounted on ``/fs``, and the RAM filesystem is mounted on ``/ram``.
Applications can read and write files using standard system calls.

If the system has an SD card connected and initialization is successful, it will be
mounted on ``/sd``. SPI Flash memory can be enabled and will be mounted on ``/sf``.

For more information, refer to the application examples.


Example Usage
-------------

.. code-block:: c

    #include <fcntl.h>
    #include <unistd.h>

    /* open file for read/write */
    int fd = open("/fs/abc.txt", O_RDWR);

    /* write something */
    int bytes_written = write(fd, "test", 4);

    /* read */
    int bytes_read = read(fd, buffer, sizeof(buffer));

    /* close file */
    close(fd);


See Also
--------

:doc:`Supported Standard IO system calls <../system/syscall/stdio>`

:doc:`SD/MMC Driver API <../peri/sdmmc>`

:doc:`SPI Flash Driver API <../peri/spifs>`
