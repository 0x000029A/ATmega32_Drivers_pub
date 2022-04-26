#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../MCAL/DIO/HED_MCAL_DIO_interface.h"
#include "HED_HAL_LCD_ILI9486_config.h"
#include "HED_HAL_LCD_ILI9486_interface.h"
#include "HED_HAL_LCD_ILI9486_private.h"
#include <util/delay.h>

void ILI9486_INIT_v()
{
    DIO_setPinValue_u8(CTRL_PORT, RST_PIN, LOW);
    _delay_us(20);
    DIO_setPinValue_u8(CTRL_PORT, RST_PIN, HIGH);
	DIO_setPinValue_u8(CTRL_PORT, CS_PIN, LOW);
	DIO_setPinValue_u8(CTRL_PORT, RD_PIN, HIGH);
}

void ILI9486_sendCMD_v(u8 command)
{
    DIO_setPinValue_u8(CTRL_PORT, WR_PIN, LOW);
    DIO_setPinValue_u8(CTRL_PORT, RS_PIN, LOW);
    DIO_setPortValue_u8(DATA_PORT, command);
    DIO_setPinValue_u8(CTRL_PORT, WR_PIN, HIGH);
}

void ILI9486_sendDATA_v(u8 DATA)
{
    DIO_setPinValue_u8(CTRL_PORT, WR_PIN, LOW);
    _delay_ms(5);
    DIO_setPinValue_u8(CTRL_PORT, RS_PIN, HIGH);
    DIO_setPortValue_u8(DATA_PORT, DATA);
    DIO_setPinValue_u8(CTRL_PORT, WR_PIN, HIGH);
}