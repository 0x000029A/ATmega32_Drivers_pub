#ifndef HED_HAL_LCD_NOKIA5110_INTERFACE_H_
#define HED_HAL_LCD_NOKIA5110_INTERFACE_H_

void NK_5110_INIT_void(void);
void NK_5110_sendCMD_u8(u8 COMMAND);
void NK_5110_sendData_u8(u8 DATA);
void NK_5110_CLR_void();
void NK_5110_RST_void();
void NK_5110_SET_XY_void(u8 X_ADD, u8 Y_ADD);

#endif
