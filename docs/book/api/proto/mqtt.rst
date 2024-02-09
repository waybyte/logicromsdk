MQTT Client
===========

MQTT Client library.

Example Usage
-------------

.. code-block:: c

    #include <proto/mqttclient.h>

    mqtt_client_t *client = NULL;
    char client_id[32];

    /* set a client ID */
    strcpy(client_id, "1234567890");
    /* init new mqtt client */
    client = mqtt_lease();
    /* configure host */
    mqtt_set_host(client, "broker.example.com");
    /* configure port */
    mqtt_set_port(client, "1883");
    /* set client id */
    mqtt_set_client_id(client, client_id);
    /* configure session clean */
    mqtt_set_clean_session(client, 1);
    /* connect to broker */
    mqtt_connect(client);
    /* topic subscribe */
    mqtt_subscribe(client, "topic1", QOS0, topic1_handler);

    /* publish message */
    mqtt_message_t msg;
    memset(&msg, 0, sizeof(msg));
    /* set payload */
    msg.payload = "Test";
    /* set QOS value */
    msg.qos = 0;
    /* publish */
    mqtt_publish(client, "topic2", &msg);


API Reference
-------------

.. include:: /inc/mqttclient.inc

