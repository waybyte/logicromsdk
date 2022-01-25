#ifndef __SYS_TERMIOS_H__
#define __SYS_TERMIOS_H__

#include <stdint.h>
#include <sys/types.h>

/*
 * termios::c_cc characters of termios structure @ref termios
 */
#define VEOF                        0           /**< EOF character */
#define VEOL                        1           /**< EOL character */
#define VERASE                      2           /**< ERASE character */
#define VINTR                       3           /**< INTR character */
#define VKILL                       4           /**< KILL character */
#define VMIN                        5           /**< MIN value */
#define VQUIT                       6           /**< QUIT character */
#define VSTART                      7           /**< START character */
#define VSTOP                       8           /**< STOP character */
#define VSUSP                       9           /**< SUSP character */
#define VTIME                      10           /**< TIME value */
#define NCCS                       16			/**< Size of the array c_cc for control characters */

/*
 * termios::c_iflag field of termios structure @ref termios
 */
#define BRKINT      (1u << 0)       /**< Signal interrupt on break. */
#define ICRNL       (1u << 1)       /**< Map CR to NL on input. */
#define IGNBRK      (1u << 2)       /**< Ignore break condition. */
#define IGNCR       (1u << 3)       /**< Ignore CR. */
#define IGNPAR      (1u << 4)       /**< Ignore characters with parity errors. */
#define INLCR       (1u << 5)       /**< Map NL to CR on input. */
#define INPCK       (1u << 6)       /**< Enable input parity check. */
#define ISTRIP      (1u << 7)       /**< Strip character. */
#define IUCLC       (1u << 8)       /**< Map upper-case to lower-case on input (LEGACY). */
#define IXANY       (1u << 9)       /**< Enable any character to restart output. */
#define IXOFF       (1u << 10)      /**< Enable start/stop input control. */
#define IXON        (1u << 11)      /**< Enable start/stop output control. */
#define PARMRK      (1u << 12)      /**< Mark parity errors. */

/*
 * termios::c_oflag field of termios structure @ref termios
 */
#define OPOST       (1u <<  0)       /**< Post-process output */
#define OLCUC       (1u <<  1)       /**< Map lower-case to upper-case on output (LEGACY). */
#define ONLCR       (1u <<  2)       /**< Map NL to CR-NL on output. */
#define OCRNL       (1u <<  3)       /**< Map CR to NL on output. */
#define ONOCR       (1u <<  4)       /**< No CR output at column 0. */
#define ONLRET      (1u <<  5)       /**< NL performs CR function. */
#define OFILL       (1u <<  6)       /**< Use fill characters for delay. */
#define NLDLY       (1u <<  7)       /**< Select newline delays: */
#define   NL0       (0u <<  7)       /**< Newline character type 0. */
#define   NL1       (1u <<  7)       /**< Newline character type 1. */
#define CRDLY       (3u <<  8)       /**< Select carriage-return delays: */
#define   CR0       (0u <<  8)       /**< Carriage-return delay type 0. */
#define   CR1       (1u <<  8)       /**< Carriage-return delay type 1. */
#define   CR2       (2u <<  8)       /**< Carriage-return delay type 2. */
#define   CR3       (3u <<  8)       /**< Carriage-return delay type 3. */
#define TABDLY      (3u << 10)       /**< Select horizontal-tab delays: */
#define   TAB0      (0u << 10)       /**< Horizontal-tab delay type 0. */
#define   TAB1      (1u << 10)       /**< Horizontal-tab delay type 1. */
#define   TAB2      (2u << 10)       /**< Horizontal-tab delay type 2. */
#define   TAB3      (3u << 10)       /**< Expand tabs to spaces. */
#define BSDLY       (1u << 12)       /**< Select backspace delays: */
#define   BS0       (0u << 12)       /**< Backspace-delay type 0. */
#define   BS1       (1u << 12)       /**< Backspace-delay type 1. */
#define VTDLY       (1u << 13)       /**< Select vertical-tab delays: */
#define   VT0       (0u << 13)       /**< Vertical-tab delay type 0. */
#define   VT1       (1u << 13)       /**< Vertical-tab delay type 1. */
#define FFDLY       (1u << 14)       /**< Select form-feed delays: */
#define   FF0       (0u << 14)       /**< Form-feed delay type 0. */
#define   FF1       (1u << 14)       /**< Form-feed delay type 1. */

/**
 * @name CBAUD
 * Baud Rate Selection. Valid values for objects of type speed_t:
 * CBAUD range B0 - B4000000
 * CBAUDEX range is also included in CBAUD for simplicity.
 * CBAUD is a part of c_cflag field @ref termios::c_cflag
 */
#define CBAUD       0x1F			/** Use baud rates defined by B0-B38400 macros. */
#define CBAUDEX     (1u << 4)		/** Use baud rates defined by B57600-B4000000 macros. */
#define BOTHER      CBAUDEX         /** Custom baud rate */
#define B0          0   /** Autobaud */
#define B50         1
#define B75         2
#ifndef ARDUINO
#define B110        3
#endif
#define B134        4
#define B150        5
#define B200        6
#define B300        7
#define B600        8
#define B1200       9
#define B1800      10
#define B2400      11
#define B4800      12
#define B9600      13
#define B19200     14
#define B38400     15
/** CBAUDEX range B57600 - B4000000 */
#define B57600     17
#define B115200    18
#define B230400    19
#define B460800    20
#define B500000    21
#define B576000    22
#define B921600    23
#ifndef ARDUINO
#define B1000000   24
#endif
#define B1152000   25
#define B1500000   26
#define B2000000   27
#define B2500000   28
#define B3000000   29
#define B3500000   30
#define B4000000   31

/*
 * termios::c_cflag control modes of termios structure @ref termios
 */
#define CSIZE      (3u << 8)         /**< Character size: */
#define   CS5      (0u << 8)         /**< 5 bits. */
#define   CS6      (1u << 8)         /**< 6 bits. */
#define   CS7      (2u << 8)         /**< 7 bits. */
#define   CS8      (3u << 8)         /**< 8 bits. */
#define CSTOPB     (1u << 10)        /**< Send two stop bits, else one. */
#define CREAD      (1u << 11)        /**< Enable receiver. */
#define PARENB     (1u << 12)        /**< Parity enable. */
#define PARODD     (1u << 13)        /**< Odd parity, else even. */
#define HUPCL      (1u << 14)        /**< Hang up on last close. */
#define CLOCAL     (1u << 15)        /**< Ignore modem status lines. */

/*
 * termios::c_lflag local modes of termios structure @ref termios
 * @note These flags are unimplemented.
 */
#define ECHO       (1u << 0)        /**< Enable echo. */
#define ECHOE      (1u << 1)        /**< Echo erase character as error-correcting backspace. */
#define ECHOK      (1u << 2)        /**< Echo KILL. */
#define ECHONL     (1u << 3)        /**< Echo NL. */
#define ICANON     (1u << 4)        /**< Canonical input (erase and kill processing). */
#define IEXTEN     (1u << 5)        /**< Enable extended input character processing. */
#define ISIG       (1u << 6)        /**< Enable signals. */
#define NOFLSH     (1u << 7)        /**< Disable flush after interrupt or quit. */
#define TOSTOP     (1u << 8)        /**< Send SIGTTOU for background output. */
#define XCASE      (1u << 9)        /**< Canonical upper/lower presentation (LEGACY). */

/* Attribute Selection constants for use with tcsetattr(): */
#define TCSANOW    0                /**< Change attributes immediately. */
#define TCSADRAIN  1                /**< Change attributes when output has drained. */
#define TCSAFLUSH  2                /**< Change attributes when output has drained; also flush pending input. */

/* Line Control constants for use with tcflush(): */
#define TCIFLUSH    1               /**< Flush pending input. Flush untransmitted output. */
#define TCIOFLUSH   2               /**< Flush both pending input and untransmitted output. */
#define TCOFLUSH    3               /**< Flush untransmitted output. */

/* constants for use with tcflow(): */
#define TCIOFF      0               /**< Transmit a STOP character, intended to suspend input data. */
#define TCION       1               /**< Transmit a START character, intended to restart input data. */
#define TCOOFF      2               /**< Suspend output. */
#define TCOON       3               /**< Restart output. */


typedef uint8_t cc_t;
typedef uint32_t speed_t;
typedef uint16_t tcflag_t;

/**
 * Termios structure
 */
struct termios
{
    tcflag_t c_iflag;    /**< Input modes */
    tcflag_t c_oflag;    /**< Output modes */
    tcflag_t c_cflag;    /**< Control modes */
    tcflag_t c_lflag;    /**< Local modes */
    cc_t     c_cc[NCCS]; /**< Control characters */
    speed_t  c_ispeed;   /**< input baud rate */
    speed_t  c_ospeed;   /**< output baud rate */
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief sets the terminal to something like the "raw" mode:
 * input is available character by character, echoing is disabled, and all special processing of
 * terminal input and output characters is disabled
 * @param termios_p		termios structure
 */
void cfmakeraw(struct termios *termios_p);

/**
 * @brief Extracts the input baud rate from the input structure exactly (without interpretation).
 *
 * @param p input termios structure
 * @return input baud rate
 */
speed_t cfgetispeed(const struct termios *p);

/**
 * @brief Extracts the output baud rate from the input structure exactly (without interpretation).
 *
 * @param p input termios structure
 * @return output baud rate
 */
speed_t cfgetospeed(const struct termios *p);

/**
 * @brief Set input baud rate in the termios structure
 *
 * There is no effect in hardware until a subsequent call of tcsetattr().
 *
 * @param p input termios structure
 * @param sp input baud rate
 * @return 0 when successful, -1 otherwise with errno set
 */
int cfsetispeed(struct termios *p, speed_t sp);

/**
 * @brief Set output baud rate in the termios structure
 *
 * There is no effect in hardware until a subsequent call of tcsetattr().
 *
 * @param p input termios structure
 * @param sp output baud rate
 * @return 0 when successful, -1 otherwise with errno set
 */
int cfsetospeed(struct termios *p, speed_t sp);

/**
 * @brief Set output baud rate in the termios structure
 *
 * There is no effect in hardware until a subsequent call of tcsetattr().
 *
 * @param p input termios structure
 * @param sp output baud rate
 * @return 0 when successful, -1 otherwise with errno set
 */
int cfsetspeed(struct termios *p, speed_t sp);

/**
 * @brief Wait for transmission of output
 *
 * @param fd file descriptor of the terminal
 * @return 0 when successful, -1 otherwise with errno set
 */
int tcdrain(int fd);

/**
 * @brief Suspend or restart the transmission or reception of data
 *
 * @param fd file descriptor of the terminal
 * @param action selects actions to do
 * @return 0 when successful, -1 otherwise with errno set
 */
int tcflow(int fd, int action);

/**
 * @brief Flush non-transmitted output data and non-read input data
 *
 * @param fd file descriptor of the terminal
 * @param select selects what should be flushed
 * @return 0 when successful, -1 otherwise with errno set
 */
int tcflush(int fd, int select);

/**
 * @brief Gets the parameters of the terminal
 *
 * @param fd file descriptor of the terminal
 * @param p output termios structure
 * @return 0 when successful, -1 otherwise with errno set
 */
int tcgetattr(int fd, struct termios *p);

/**
 * @brief Send a break for a specific duration
 *
 * @param fd file descriptor of the terminal
 * @param duration duration of break
 * @return 0 when successful, -1 otherwise with errno set
 */
int tcsendbreak(int fd, int duration);

/**
 * @brief Sets the parameters of the terminal
 *
 * @param fd file descriptor of the terminal
 * @param optional_actions optional actions
 * @param p input termios structure
 * @return 0 when successful, -1 otherwise with errno set
 */
int tcsetattr(int fd, int optional_actions, const struct termios *p);

#ifdef __cplusplus
}
#endif

#endif
