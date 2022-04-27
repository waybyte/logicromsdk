/**
 * @file display.h
 * @brief display driver header file
 * 
 */
#ifndef INCLUDE_HW_DISPLAY_H_
#define INCLUDE_HW_DISPLAY_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Display Controller Layers
 */
enum disp_layer_e {
	DISPLAY_LAYER0, 	/**< Base/bottom layer */
	DISPLAY_LAYER1, 	/**< Middle layer */
	DISPLAY_LAYER2,		/**< Top layer */
	DISPLAY_LAYER_VIDEO,/**< Video layer, shown above all graphics layers */
};

/**
 * @brief LCD controller supported output format
 */
enum lcd_outfmt_e {
	LCD_OUT_FMT_8BIT_RGB332 = 0,
	LCD_OUT_FMT_8BIT_RGB444 = 1,
	LCD_OUT_FMT_8BIT_RGB565 = 2,
	LCD_OUT_FMT_16BIT_RGB332 = 4,
	LCD_OUT_FMT_16BIT_RGB444 = 5,
	LCD_OUT_FMT_16BIT_RGB565 = 6,
};

/**
 * @brief LCD controler SPI interface line mode
 */
enum lcd_spi_linemode_e {
	LCD_SPI_4WIRE,
	LCD_SPI_3WIRE,
	LCD_SPI_4WIRE_START_BYTE,
	LCD_SPI_3WIRE_2LANE,
};

/**
 * @brief Direction transform
 */
enum lcd_dir_e {
    LCD_DIR_NORMAL,							/**< normal direction */
    LCD_DIR_YINV,							/**< Y is inverted */
    LCD_DIR_XINV,							/**< X is inverted */
    LCD_DIR_YINV_XINV,						/**< both Y and X are inverted */
    LCD_DIR_EXCHG,							/**< X-Y are swapped */
    LCD_DIR_EXCHG_YINV,						/**< X-Y are swapped, Y is inverted */
    LCD_DIR_EXCHG_XINV,						/**< X-Y are swapped, X is inverted */
    LCD_DIR_EXCHG_XINV_YINV,				/**< X-Y are swapped, both X and Y are inverted */
    LCD_DIR_ROTATE_0 = LCD_DIR_NORMAL,		/**< alias for rotate 0 degree */
    LCD_DIR_ROTATE_90 = LCD_DIR_EXCHG_XINV,	/**< alias for rotate 90 degree */
    LCD_DIR_ROTATE_180 = LCD_DIR_YINV_XINV,	/**< alias for rotate 180 degree */
    LCD_DIR_ROTATE_270 = LCD_DIR_EXCHG_YINV,/**< alias for rotate 270 degree */
};

/**
 * @brief Input buffer color format
 * 
 * RGB565 and ARGB8888 format for layer0, 1 and 2
 * YUV formats are for video layer
 */
enum disp_infmt_e {
	/** RGB565 in little endian, [15:11] R, [10:5] G, [4:0] B */
	LCD_IN_FMT_RGB565,
	/** ARGB8888 in little endian, [31:24] A, [23:16] R, [15:8] G, [7:0] B */
	LCD_IN_FMT_ARGB8888,
	/** UYVY pixel-packed format */
	LCD_IN_FMT_YUV422_UYVY,
	/** YUYV pixel-packed format */
	LCD_IN_FMT_YUV422_YUYV,
	/** IYUV planar format */
	LCD_IN_FMT_YUV420_IYUV,
};

/**
 * @brief An area
 *
 * Area with (w == 0 || h == 0) is nul or invalid area.
 */
struct lcd_area_t {
	uint16_t x; /** Top left position x coordinate */
	uint16_t y; /** Top left position y coordinate */
	uint16_t w; /** Width of area */
	uint16_t h; /** height of area */
};

/**
 * @brief LCD driver operations
 * 
 */
struct lcd_ops_t {
	/**
	 * @brief Initialization
	 */
	void (*init)(void);
	/**
	 * @brief Setup lcd controller area for display data transfer
	 * 
	 * @param x0 top left corner x coordinate
	 * @param y0 top left corner y coordinate
	 * @param x1 bottom right corner x coordinate
	 * @param y1 bottom right corner y coordinate
	 */
	void (*prepare)(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
	/**
	 * @brief Set LCD controller direction
	 * 
	 * @note This function is currently unused (can be set to NULL), Please set LCD direction\n
	 * during initialization of LCD controller.
	 * 
	 * @param dir direction transform to set @ref lcd_dir_e
	 */
	void (*set_direction)(int dir);
};

/**
 * @brief LCD Driver structure
 */
struct lcd_drv_t {
	uint32_t reset_delay_us;/** Reset delay in microseconds */
	uint32_t init_delay_us;	/** Delay in microseconds before driver init is called */
	uint16_t io_level_mv;	/** LCD IO Level in millivolts, 0 for default 1800mV, max 3200mV */
	uint16_t width;			/** Width of LCD panel */
	uint16_t height;		/** Height of LCD panel */
	uint16_t bg_color;		/** Default background color */
	uint8_t output_format;	/** LCD output pixel format @ref lcd_outfmt_e */
	uint8_t in_format;		/** Input data format for Base layer 0 @ref disp_infmt_e */
	uint8_t spi_linemode;	/** LCD controller SPI interface @ref lcd_spi_linemode_e */
	uint8_t cs_polarity;	/** Chip select line polarity, 0 - active low, 1 - active high */
	uint8_t te_enable;		/** Enable tearing effect signal detect (FMARK), - TRUE to enable, FALSE to disable */
	uint8_t te_polarity;	/** TE polarity (unused), positive edge default */
	uint16_t te_delay;		/** TE detect delay */
	uint32_t spi_freq;		/** SPI frequency in Hz */
	struct lcd_ops_t ops;	/** SPI driver operations, @ref lcd_ops_t */
};

/**
 * @brief Display layer configuration
 */
struct layer_cfg_t {
	uint8_t format;			/** input data format @ref disp_infmt_e */
	uint8_t alpha;			/** blending alpha, 0 for transparent */
	uint8_t key_en;			/** whether to enable color key */
	uint8_t key_mask;		/** key color mask */
	uint16_t key_color;		/** key color in RGB565 */
	struct lcd_area_t area; /** layer area size */
};

/**
 * @brief Initialize onchip display controller and LCD controller
 * 
 * @param lcd LCD driver structure @ref lcd_drv_t
 * @return 0 for success, negative for error
 */
int display_init(const struct lcd_drv_t *lcd);

/**
 * @brief Enable or disable sleep
 * 
 * @note display flush is needed after wakeup from sleep
 * 
 * @param enable TRUE to enable sleep, FALSE to disable
 * @return 0 for success, negative for error
 */
int display_sleep(uint8_t enable);

/**
 * @brief Setup display layer
 * 
 * @note Layer 0 is setup by default during initialization with size of LCD panel
 * 
 * @param layer Layer to setup @ref disp_layer_e
 * @param cfg Layer configuration @ref layer_cfg_t
 * @return 0 for success, negative for error
 */
int display_layer_setup(int layer, const struct layer_cfg_t *cfg);

/**
 * @brief Get display layer configuration, If layer is not setup
 * @a cfg will be filled with valid default values and area set to invalid
 * 
 * @param layer Layer number @ref disp_layer_e
 * @param cfg Layer configuration pointer to fill
 * @return 0 for success, negative for error
 */
int display_layer_getcfg(int layer, struct layer_cfg_t *cfg);

/**
 * @brief Get display layer buffer.
 * Image data written on buffer will be sent to display on flush
 * 
 * @param layer Layer number @ref disp_layer_e
 * @return buffer pointer on success, NULL on error
 */
void *display_layer_getbuffer(int layer);

/**
 * @brief Enable or disable display layer
 * 
 * @param layer Layer number @ref disp_layer_e
 * @param en TRUE to enable, FALSE to disable layer
 * @return 0 for success, negative for error
 */
int display_layer_enable(int layer, uint8_t en);

/**
 * @brief Delete a display layer
 * 
 * @note Base Layer 0 cannot be deleted
 * 
 * @param layer Layer number @ref disp_layer_e
 * @return 0 for success, negative for error
 */
int display_layer_delete(int layer);

/**
 * @brief Flush blended display layers on LCD
 * 
 * @param area area to update, NULL for complete update
 * @param sync TRUE - to wait for operation to complete, FALSE - do not wait
 * @return 0 for success, negative for error
 */
int display_flush(const struct lcd_area_t *area, uint8_t sync);

/**
 * @brief Send command to LCD controller
 * 
 * @param cmd command to write
 * @return 0 for success, negative for error
 */
int display_write_cmd(uint16_t cmd);

/**
 * @brief Send data to LCD controller
 * 
 * @param data data to write
 * @return 0 for success, negative for error
 */
int display_write_data(uint16_t data);

/**
 * @brief Read data from LCD controller, e.g. LCD controller ID
 * 
 * @param cmd Read command for LCD controller
 * @param data data buffer to store read data
 * @param len length of data to read (max 4 bytes)
 * @return 0 for success, negative for error
 */
int display_read_data(uint16_t cmd, uint8_t *data, unsigned len);

/**
 * @brief Wait for transfer to complete, this is blocking call
 */
void display_wait_transfer(void);

/**
 * @brief Enable/disable display backlight (if supported by hardware)
 * 
 * @param enabled TRUE to enable, FALSE disable
 */
void display_backlight_enable(uint8_t enabled);

/**
 * @brief Clear display. This function disable all display layers and
 * set display background to default as in config
 * 
 * @param sync TRUE - to wait for operation to complete, FALSE - do not wait
 * @return 0 for success, negative for error
 */
int display_clear(uint8_t sync);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_HW_DISPLAY_H_ */
