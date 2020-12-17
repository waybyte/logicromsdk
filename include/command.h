/*
 * command.h
 *
 */
#ifndef INC_COMMAND_H
#define INC_COMMAND_H

#include "private/linker_list.h"

/**
 * Maximum number of allowed arguments
 * including commmand
 */
#define CMD_MAX_ARGS 16

/**
 * @enum command_ret_e
 * Command executing return code
 */
enum command_ret_e {
	CMD_RET_SUCCESS,	/**< Command executed successfully */
	CMD_RET_FAILURE,	/**< Command executing failure */
	CMD_RET_PERM,		/**< Command Permission denied */
	CMD_RET_LOGOUT,		/**< Execute session logout */
	CMD_RET_USAGE = -1,	/**< Failure, please report 'usage' error */
};

/**
 * @enum command_src_e
 * Source of command used in @ref cmdinfo_t structure
 */
enum command_src_e {
	CMD_SRC_CONSOLE,  /**< Command source console */
	CMD_SRC_BTCONSOLE,/**< Command source Bluetooth Console */
	CMD_SRC_DBG,      /**< Command source Remote debug console */
	CMD_SRC_SMS,      /**< Command source SMS */
	CMD_SRC_TCP,      /**< Command source TCP */
};

/**
 * @enum command_type_e
 * Command type flags. These flags can be ORed together.
 */
enum command_type_e {
	CMD_TYPE_DEFAULT = 0,         /**< Default command, executing allowed everywhere and can be executed by user and admin. */
	CMD_TYPE_HIDDEN = 1,          /**< Hidden command, Only executed by admin user */
	CMD_ALLOW_SMS = 2,            /**< Command allowed over SMS */
	CMD_ALLOW_TCP = 4,            /**< Command allowed over TCP */
	CMD_ALLOW_DBG = 8,            /**< Command allowed over remote debug */
	CMD_ALLOW_CONSOLE = 0x10,     /**< Command allowed over console */
	CMD_ALLOW_BT_CONSOLE = 0x20,  /**< Command allowed over Bluetooth console */
	CMD_ALLOW_SYS = 0x40,         /**< Command allowed to execute via system API */

	/* Combination Flags */
	CMD_ALLOW_TCP_SMS = 0x6,      /**< Command allowed over TCP and SMS */
	CMD_ALLOW_CONSOLE_ONLY = 0x38,/**< Command allowed over Console only */
	CMD_ALLOW_TCP_SMS_DBG = 0xE,  /**< Command allowed over TCP, SMS and remote console */
};

/**
 * @struct cmdinfo_t
 * Command information structure, passed to command handler function
 */
struct cmdinfo_t {
	int src;		/**< Command source command_src_e */
	void *data;		/**< user data attached to command */
};

/**
 * Command Handler function
 * @param argc		Number of arguments
 * @param argv		Argument list
 * @param info		Command info structure
 * @return			Command return type command_ret_e
 */
typedef int (*cmd_handler_f)(int argc, const char **argv, struct cmdinfo_t *info);

/**
 * Command descriptor structure
 */
typedef struct {
	const char *cmd;	/**< Name of command */
	int min_arg;		/**< Minimum arguments */
	int max_arg;		/**< Maximum arguments */
	cmd_handler_f cmdfn;/**< Command handler function */
	const char *help;	/**< Short help message */
	const char *usage;	/**< Long help message with usage */
	int type;			/**< Command type flags command_type_e */
} cmddesc_t;

/**
 * Add new command
 * @param _name		Name of command
 * @param _minarg	Minimum number of arguments including command (must be >= 1)
 * @param _maxarg	Maximum number of arguments including command (must be >= 1 & <= CMD_MAX_ARGS)
 * @param _cmd		Command handler function
 * @param _help		Short help message
 * @param _usage	Long help message and usage detail
 * @param _type		Command type flag see command_type_e
 */
#define CMD_ADD(_name, _minarg, _maxarg, _cmd, _help, _usage, _type)	\
	ll_entry_el(cmddesc_t, cmdlist, _name) = 		\
	{ #_name, _minarg, _maxarg, _cmd, _help, _usage, _type}

/**
 * Command process callback function
 * @param result	Result of command executing
 * @param info		Command information structure
 * @param arg		User argument
 */
typedef void (*commandproc_cb)(int result, struct cmdinfo_t *info, void *arg);

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Execute command buffer
 *
 * Multiple commands can be separated by ; and will be executed
 * by the built-in parser.
 *
 * @param cmd		[in] String containing list of commands
 * @param len		[in] length of cmd string
 * @param info		[in] Command information structure
 * @param callback	[in] process callback function of type commandproc_cb, called after execution of each command in the list
 * @param arg		[in] Argument passed to callback function
 * @return 0 on success, or != 0 on error. command_ret_e
 */
int command_process(const char *cmd, int len, struct cmdinfo_t *info, commandproc_cb callback, void *arg);

#ifdef __cplusplus
}
#endif

#endif	/* INC_COMMAND_H */
