/*
 * ril_stk.h
 *
 */

#ifndef INC_RIL_STK_H_
#define INC_RIL_STK_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief STK Command type
 * 
 */
enum stk_cmd_e {
    STK_CMD_INVALID = 0,        /**< Invalid command */
    STK_CMD_REFRESH = 0x01,     /**< Refresh command */
    STK_CMD_CALL_SETUP = 0x10,  /**< Call setup */
    STK_CMD_SEND_USSD = 0x12,   /**< Send USSD */
    STK_CMD_SEND_SMS = 0x13,    /**< Send SMS */
    STK_CMD_DISPLAY_TEXT = 0x21,/**< Display test */
    STK_CMD_GET_INPUT = 0x23,   /**< Get user input */
    STK_CMD_SELECT_ITEM = 0x24, /**< Select menu item */
    STK_CMD_SETUP_MENU = 0x25,  /**< Setup menu */
};

/**
 * Get SIM toolkit status
 * @return		0 if disabled, 1 if enabled
 */
int stk_status(void);

/**
 * Enable/Disable SIM toolkit
 * @return		RIL return code @ref ril_rc_e
 */
int stk_enable(void);

/**
 * @brief Get current proactive command and qualifier ID
 * 
 * @param cmd   current TLK command id (@ref stk_cmd_e) (hex)
 * @param qual  Qualifier value (hex) (optional)
 * @return      RIL return code @ref ril_rc_e
 */
int stk_get_currcommand(uint8_t *cmd, uint8_t *qual);

/**
 * Send envelope command (AT+STKENV) to open menu items
 * 
 * @param menu_id	Menu ID to open (hex)
 * @return		    RIL return code @ref ril_rc_e
 */
int stk_open_menu(uint8_t menu_id);

/**
 * Select menu item (AT+STKR)
 * 
 * @param item_id	Item id from menu (hex)
 * @return		    RIL return code @ref ril_rc_e
 */
int stk_select_item(uint8_t item_id);

/**
 * @brief Terminate current proactive session
 * 
 * @return RIL return code @ref ril_rc_e
 */
int stk_terminate_session(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_RIL_STK_H_ */
