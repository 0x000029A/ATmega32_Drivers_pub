#ifndef HED_HAL_LCD_ILI9486_INTERFACE_H_
#define HED_HAL_LCD_ILI9486_INTERFACE_H_

void ILI9486_INIT_v(void);
void ILI9486_sendCMD_v(u8 command);
void ILI9486_sendDATA_v(u8 DATA);

#endif