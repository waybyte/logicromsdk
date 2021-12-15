/*
 * ntpc.h
 *
 */
#ifndef INC_PROTO_NTPC_H
#define INC_PROTO_NTPC_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize NTP client service
 * @return 0 on success, negative value on failure
 */
int ntpclient_init(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_PROTO_NTPC_H */
