Modbus Master
=============

Example Usage
-------------

.. code-block:: c

    #include <proto/modbus.h>

    /* init modbus RTU master, on port UART0  */
    mb_init("/dev/ttyS0", MB_RTU, dirctl);

    /* configure modbus at 115200bps, 8bits, No parity, 1 stopbit*/
    mb_config(115200, "8N1");

    /* send modbus request */
    struct modbus_t mbreq;
    uint8_t buffer[256];

    /* set slave id */
    mbreq.slaveid = 1;
    /* Set function code as Read holding register */
    mbreq.function = MB_FUNC_RD_HOLDING;
    /* set start address to read from */
    mbreq.op.read.start_add = 0x00;
    /* read 1 register */
    mbreq.op.read.no_regs = 1;
    /* configure response buffer */
    mbreq.resp_buf = buffer;
    mbreq.resp_buflen = sizeof(buffer);
    /* set response timeout in milliseconds */
    mbreq.resp_timeout = 1000;
    /* initiate request */
    mb_request(&mbreq);

    /* doing, Modbus transceiver direction control, this function is passed as argument to mb_init() */
    void dirctl(int dir)
    {
        if (dir == MB_DIR_RX) {
            /* receive, control GPIO or something */
        } else {
            /* transmit, change gpio again */
        }
    }


API Reference
-------------

.. include:: /inc/modbus.inc

