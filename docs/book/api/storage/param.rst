Parmeter Storage API
====================

Parameter storage library can be used to store system configuration. API uses
internal flash for parameter storage.

Example Usage
-------------

.. code-block:: c

    #include <param.h>

    /* save parameter */
    param_save("param_name", &param, sizeof(param));

    /* load parameter from storage */
    param_load("param_name", &param, sizeof(param));

    /* delete a parameter from storage */
    param_reset("param_name");

    /* shorthand version for save, load and delete parameter */
    PARAM_SAVE(param);
    PARAM_LOAD(param);
    PARAM_RESET(param);


API Reference
-------------

.. include:: /inc/param.inc

