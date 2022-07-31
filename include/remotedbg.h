/*
 * remotedbg.h
 *
 */

#ifndef INCLUDE_REMOTEDBG_H_
#define INCLUDE_REMOTEDBG_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize and enable Remote debugging
 * 
 * This will also add rdbg command to firmware
 * 
 * Usage of rdbg:
 * 
 * rdbg=[IP],[Port]
 * 
 * Where IP can be domain name or IP of server to connect
 * Port is server port to connect
 *
 * Once connected, remote server will be greeted with device parameter
 * message in following format
 * 
 * $RDBG,[Module UID],[IMEI]#[CR][LF]
 * 
 * and followed by a login prompt.
 */
void remote_debug_enable(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_REMOTEDBG_H_ */
