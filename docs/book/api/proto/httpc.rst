HTTP Client
===========

HTTP Client library.

Example Usage
-------------

.. code-block:: c

    #include <proto/httpc.h>

    struct httparg_t arg;
    char buffer[256];
    int ret;

    memset(&arg, 0, sizeof(arg));
    memset(response, 0, sizeof(buffer));
    /* set URL to access */
    arg.url = "http://example.com";
    /* a custom header example, must end with \r\n */
    arg.headers = "custom-header: some_value\r\n";
    /* certificates when using SSL */
    arg.certs = NULL;
    /* receive headers not needed in response */
    arg.recv_headers = 0;
    /* set size of response buffer */
    arg.buflen = sizeof(buffer);
    /* set response buffer pointer */
    arg.resp_buffer = bufer;

    /* run request */
    ret = httpc_submit(HTTP_CLIENT_DEFAULT, "GET", &arg);
    printf("HTTP GET request failed: %d\n", ret);
    if (!ret) {
        printf("HTTP response (%d bytes): %s\n\n", arg.buflen, buffer);
    }


API Reference
-------------

.. include:: /inc/httpc.inc

