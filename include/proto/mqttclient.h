/**
 * mqtt.h
 *
 * This file has been derived from mqttclient library by jiejie.
 */
/*
 * @Author: jiejie
 * @Github: https://github.com/jiejieTop
 * @Date: 2019-12-09 21:31:25
 * @LastEditTime : 2022-06-11 22:45:02
 * @Description: the code belongs to jiejie, please keep the author information and source code according to the license.
 */
#ifndef _INC_PROTO_MQTTCLIENT_H_
#define _INC_PROTO_MQTTCLIENT_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MQTT_TOPIC_LEN_MAX 64

/**
 * @brief MQTT error codes
 * 
 */
typedef enum mqtt_error {
	MQTT_SSL_CERT_ERROR                                     = -0x001C,      /* cetr parse failed */
	MQTT_SOCKET_FAILED_ERROR                                = -0x001B,      /* socket fd failed */
	MQTT_SOCKET_UNKNOWN_HOST_ERROR                          = -0x001A,      /* socket unknown host ip or domain */
	MQTT_SET_PUBLISH_DUP_FAILED_ERROR                       = -0x0019,      /* mqtt publish packet set udp bit failed */
	MQTT_CLEAN_SESSION_ERROR                                = -0x0018,      /* mqtt clean session error */
	MQTT_ACK_NODE_IS_EXIST_ERROR                            = -0x0017,      /* mqtt ack list is exist ack node */
	MQTT_ACK_HANDLER_NUM_TOO_MUCH_ERROR                     = -0x0016,      /* mqtt ack handler number is too much */
	MQTT_RESUBSCRIBE_ERROR                                  = -0x0015,      /* mqtt resubscribe error */
	MQTT_SUBSCRIBE_ERROR                                    = -0x0014,      /* mqtt subscribe error */
	MQTT_SEND_PACKET_ERROR                                  = -0x0013,      /* mqtt send a packet */
	MQTT_SERIALIZE_PUBLISH_ACK_PACKET_ERROR                 = -0x0012,      /* mqtt serialize publish ack packet error */
	MQTT_PUBLISH_PACKET_ERROR                               = -0x0011,      /* mqtt publish packet error */
	MQTT_RECONNECT_TIMEOUT_ERROR                            = -0x0010,      /* mqtt try reconnect, but timeout */
	MQTT_SUBSCRIBE_NOT_ACK_ERROR                            = -0x000F,      /* mqtt subscribe, but not ack */
	MQTT_NOT_CONNECT_ERROR                                  = -0x000E,      /* mqtt not connect */
	MQTT_SUBSCRIBE_ACK_PACKET_ERROR                         = -0x000D,      /* mqtt subscribe, but ack packet error */
	MQTT_UNSUBSCRIBE_ACK_PACKET_ERROR                       = -0x000C,      /* mqtt unsubscribe, but ack packet error */
	MQTT_PUBLISH_ACK_PACKET_ERROR                           = -0x000B,      /* mqtt pubilsh ack packet error */
	MQTT_PUBLISH_ACK_TYPE_ERROR                             = -0x000A,      /* mqtt pubilsh ack type error */
	MQTT_PUBREC_PACKET_ERROR                                = -0x0009,      /* mqtt pubrec packet error */
	MQTT_BUFFER_TOO_SHORT_ERROR                             = -0x0008,      /* mqtt buffer too short */
	MQTT_NOTHING_TO_READ_ERROR                              = -0x0007,      /* mqtt nothing to read */
	MQTT_SUBSCRIBE_QOS_ERROR                                = -0x0006,      /* mqtt subsrcibe qos error */
	MQTT_BUFFER_OVERFLOW_ERROR                              = -0x0005,      /* mqtt buffer overflow */
	MQTT_CONNECT_FAILED_ERROR                               = -0x0004,      /* mqtt connect failed */
	MQTT_MEM_NOT_ENOUGH_ERROR                               = -0x0003,      /* mqtt memory not enough */
	MQTT_NULL_VALUE_ERROR                                   = -0x0002,      /* mqtt value is null */
	MQTT_FAILED_ERROR                                       = -0x0001,      /* failed */
	MQTT_SUCCESS_ERROR                                      = 0x0000        /* success */
} mqtt_error_t;

/**
 * @brief MQTT QOS Level
 * 
 */
typedef enum mqtt_qos {
	QOS0 = 0,	/**< Quality of Service level 0: message delivery at most once */
	QOS1 = 1,	/**< Quality of Service level 1: message delivery at least once */
	QOS2 = 2,	/**< Quality of Service level 2: message delivery exactly once */
	SUBFAIL = 0x80
} mqtt_qos_t;

/**
 * @brief MQTT Message payload information structure
 * 
 */
typedef struct mqtt_message {
	mqtt_qos_t          qos;		/**< Quality of service see @ref mqtt_qos_t */
	uint8_t             retained;	/**< flag for retained message */
	uint8_t             dup;		/**< flag indicating duplicate message */
	uint16_t            id;			/**< Message identifier */
	size_t              payloadlen;	/**< Payload length */
	void                *payload;	/**< Payload data */
} mqtt_message_t;

/**
 * @brief MQTT Message data structure
 * 
 */
typedef struct message_data {
	char                topic_name[MQTT_TOPIC_LEN_MAX];	/**< Topic name */
	mqtt_message_t      *message;	/**< pointer to message payload */
} message_data_t;

/**
 * @brief mqtt_client forward definition
 * 
 */
typedef struct mqtt_client mqtt_client_t;

/**
 * @brief incoming message intercept handler
 * 
 */
typedef void (*interceptor_handler_t)(void* client, message_data_t* msg);

/**
 * @brief Incoming message handler for assigned topic
 * 
 */
typedef void (*message_handler_t)(void* client, message_data_t* msg);

/**
 * @brief Reconnection hook, this function is called before reconnection
 * 
 */
typedef void (*reconnect_handler_t)(void* client, void* reconnect_date);

/**
 * @brief Set MQTT broker client id
 * 
 * @param client MQTT client handle
 * @param id Client ID to set
 * @return client id or NULL when error
 */
const char *mqtt_set_client_id(mqtt_client_t *client, const char *id);

/**
 * @brief Set MQTT broker username
 * 
 * @param client MQTT client handle
 * @param username Username to set
 * @return username or NULL when error
 */
const char *mqtt_set_user_name(mqtt_client_t *client, const char *username);

/**
 * @brief Set MQTT broker client ID
 * 
 * @param client MQTT client handle
 * @param password Password to set
 * @return password or NULL when error
 */
const char *mqtt_set_password(mqtt_client_t * client, const char *password);

/**
 * @brief Set MQTT broker host name
 * 
 * @param client MQTT client handle
 * @param host hostname to set
 * @return hostname on success or NULL
 */
const char *mqtt_set_host(mqtt_client_t *client, const char *host);

/**
 * @brief Set MQTT broker port
 * 
 * @param client MQTT client handle
 * @param port Port to set
 * @return Port value or NULL when error
 */
const char *mqtt_set_port(mqtt_client_t *client, const char *port);

/**
 * @brief Set CA certificate
 * 
 * @param client MQTT client handle
 * @param ca CA certificate in PEM format
 * @return pointer to CA or NULL when error
 */
const char *mqtt_set_ca(mqtt_client_t *client, const char *ca);

/**
 * @brief Set custom user argument passed to reconnect hook handler
 * 
 * @param client MQTT client handle
 * @param arg User argument
 * @return user argument on success or NULL for error
 */
void *mqtt_set_reconnect_data(mqtt_client_t *client, void *arg);

/**
 * @brief Set keep alive interval, default 30s
 * 
 * @param client MQTT client handle
 * @param ka Keep alive interval in seconds
 * @return current set value on success or 0 otherwise
 */
uint16_t mqtt_set_keep_alive_interval(mqtt_client_t *client, uint16_t ka);

/**
 * @brief Enable or disable LWT message, default 0
 * 
 * @param client MQTT client handle
 * @param will_flag Will flag, 1 to enable, 0 to disable
 * @return current value of will flag
 */
uint32_t mqtt_set_will_flag(mqtt_client_t *client, uint32_t will_flag);

/**
 * @brief Enable or disable MQTT clean session flag, default 0
 * 
 * @param client MQTT client handle
 * @param clean_session clean session flag value, 0 - persistent session, 1 - non-persistent session
 * @return current value of clean sesson flag
 */
uint32_t mqtt_set_clean_session(mqtt_client_t *client, uint32_t clean_session);

/**
 * @brief Change MQTT version, default 4 (for MQTT 3.1.1)
 * 
 * @param client MQTT client handle
 * @param version version value
 * @return current version value
 */
uint32_t mqtt_set_version(mqtt_client_t *client, uint32_t version);

/**
 * @brief Set MQTT command timeout value, default 20000ms
 * 
 * @param client MQTT client handle
 * @param timeout Timeout value in milliseconds
 * @return current set timeout value
 */
uint32_t mqtt_set_cmd_timeout(mqtt_client_t *client, uint32_t timeout);

/**
 * @brief set MQTT read payload buffer size, default 1024 bytes
 * 
 * @param client MQTT client handle
 * @param bufsz size of buffer in bytes
 * @return current size on success, 0 on error
 */
uint32_t mqtt_set_read_buf_size(mqtt_client_t *client, uint32_t bufsz);

/**
 * @brief Set MQTT write payload buffer size, default 1024 bytes
 * 
 * @param client MQTT client handle
 * @param bufsz size of buffer in bytes
 * @return current size on success, 0 on error
 */
uint32_t mqtt_set_write_buf_size(mqtt_client_t *client, uint32_t bufsz);

/**
 * @brief Set MQTT reconnect duration, default 1000ms
 * 
 * @param client MQTT client handle
 * @param duration reconnect duration in millisecond
 * @return current duration on success or 0 on error
 */
uint32_t mqtt_set_reconnect_try_duration(mqtt_client_t *client, uint32_t duration);

/**
 * @brief Set MQTT socket reconnect hook
 * 
 * @param client MQTT client handle
 * @param fn handler function to set
 * @return handler function value on success, NULL on error
 */
reconnect_handler_t mqtt_set_reconnect_handler(mqtt_client_t *client, reconnect_handler_t fn);

/**
 * @brief Set MQTT incoming message interceptor hook
 * 
 * @param client MQTT client handle
 * @param fn handler function to set
 * @return handler function value on success, NULL on error
 */
interceptor_handler_t mqtt_set_interceptor_handler(mqtt_client_t *client, interceptor_handler_t fn);

/**
 * @brief Allocate and init a new MQTT client handle
 * 
 * @note only single MQTT connection is allowed on MT6261/MT2503 SoC
 * 
 * @return MQTT client handle
 */
mqtt_client_t *mqtt_lease(void);

/**
 * @brief release previously allocated MQTT client by @ref mqtt_lease() 
 * 
 * @param c MQTT client handle
 * @return 0 on success, error code otherwise @ref mqtt_error_t
 */
int mqtt_release(mqtt_client_t* c);

/**
 * @brief Connect to MQTT broker
 * 
 * @param c MQTT client handle
 * @return 0 on success, error code otherwise @ref mqtt_error_t
 */
int mqtt_connect(mqtt_client_t* c);

/**
 * @brief Disconnect from MQTT broker
 * 
 * @param c MQTT client handle
 * @return 0 on success, error code otherwise @ref mqtt_error_t
 */
int mqtt_disconnect(mqtt_client_t* c);

/**
 * @brief Subscribe to a topic
 * 
 * @param c MQTT client handle
 * @param topic_filter Topic name
 * @param qos Quality of service @ref mqtt_qos_t
 * @param msg_handler incoming message handler
 * @return 0 on success, error code otherwise @ref mqtt_error_t
 */
int mqtt_subscribe(mqtt_client_t* c, const char* topic_filter, mqtt_qos_t qos, message_handler_t msg_handler);

/**
 * @brief Unsubscribe a topic
 * 
 * @param c MQTT client handle
 * @param topic_filter topic name
 * @return 0 on success, error code otherwise @ref mqtt_error_t
 */
int mqtt_unsubscribe(mqtt_client_t* c, const char* topic_filter);

/**
 * @brief Publish a message
 * 
 * @param c MQTT client handle
 * @param topic_filter topic name
 * @param msg Message to send @ref mqtt_message_t
 * @return 0 on success, error code otherwise @ref mqtt_error_t
 */
int mqtt_publish(mqtt_client_t* c, const char* topic_filter, mqtt_message_t* msg);

/**
 * @brief Set/change LWT options, this call will enable will flag if disabled
 * 
 * @param c MQTT client handle
 * @param topic topic name
 * @param qos Quality of service @ref mqtt_qos_t
 * @param retained retained flag
 * @param message LWT message
 * @return 0 on success, error code otherwise @ref mqtt_error_t
 */
int mqtt_set_will_options(mqtt_client_t* c, char *topic, mqtt_qos_t qos, uint8_t retained, char *message);

#ifdef __cplusplus
}
#endif

#endif /* _INC_PROTO_MQTTCLIENT_H_ */
