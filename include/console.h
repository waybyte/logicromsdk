/*
 * console.h
 *
 */

#ifndef INC_CONSOLE_H
#define INC_CONSOLE_H

#ifdef __cpluplus
extern "C" {
#endif

/**
 * CLI authentication return code
 */
enum cli_auth_rc {
	AUTH_FAIL, /**< Authentication failed */
	AUTH_USER, /**< Authentication success with user credentials */
	AUTH_ADMIN,/**< Authentication success with admin credentials */
};

/**
 * CLI Authentication function
 * @param user		Username entered on console.\n
 * 					For Remote debug console this value is "rdbg".\n
 * 					For Bluetooth console this value is "btcli".
 * @param pass		Password
 * @return			Authentication return code, see @ref cli_auth_rc
 */
typedef int (*cliauth_f)(const char *user, const char *pass);

/**
 * Set Authentication function
 * @param fn		Pointer to auth function of type @ref cliauth_f
 * @return			0 on success, negative value on error
 */
int cli_set_authfn(cliauth_f fn);

#ifdef __cpluplus
}
#endif

#endif /* INC_CONSOLE_H */
