Data Storage Management API
===========================

SDK provide simple APIs to manage data storage. The  storage APIs can be
used to store data on storage media during unavailability of network or for
logging purpose.

Example Usage
-------------

.. code-block:: c

    #include <storage.h>

    struct storagecfg_t config;

    /* configure data storage */
    /* set storage media */
    config.media = STORAGE_MEDIA_FS; /* internal flash */
    /* set virtual partitions */
    config.parts = 1; /* single partition */
    /* storage mode */
    config.mode = STORAGE_MODE_FIFO; /* FIFO style */
    /* action on storage full */
    config.on_full = STORAGE_ONFULL_DELETE; /* delete oldest */
    /* compression mode */
    config.compression = false; /* no compression, sometimes better when using binary */
    /* storage packet size, only used for estimation */
    config.packet_sz = 64; /* approx data per packet */
    /* maximum storage limit */
    config.max_storage = 1000; /* maximum storage in terms of data packets */
    /* reserved memory */
    config.reserved_mem = 16 * 1024; /* minimum amount of memory to keep in storage */
    /* init storage */
    storage_init(&config);

    /* save a packet in data storage partiton 1 */
    storage_save(1, &data_packet, sizeof(data_packet));

    /* retrive packet from storage partition 1 */
    int packet_len;

    packet_len = sizeof(data_packet);
    storage_read(1, &data_packet, &packet_len);

    /* read multiple packets from storage 1 */
    for (int i = 0; i < 10; i++) {
        int packet_len = sizeof(data_packet[i]);
        storage_read_indexed(1, i, &data_packet[i], &packet_len);
    }

    /* delete 5 packets from storage partition 1 */
    storage_delete(1, 5);

    /* check if data available in partition 1 */
    if (storage_available(1)) {
        printf("Data available in storage\n");
    } else {
        printf("No data available\n");
    }

    /* get count of data available */
    printf("Storage 1 has %d packets\n", storage_getcount(1));

    /* delete all data in parition 1 */
    storage_clear(1);

    /* clear all data in all partitions */
    storage_clear_all();


API Reference
-------------

.. include:: /inc/storage.inc

