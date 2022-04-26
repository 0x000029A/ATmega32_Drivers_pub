#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../MCAL/DIO/HED_MCAL_DIO_interface.h"
#include "../../MCAL/SPI/HED_MCAL_SPI_interface.h"
#include "HED_HAL_LCD_NOKIA5110_config.h"
#include "HED_HAL_LCD_NOKIA5110_interface.h"
#include "HED_HAL_LCD_NOKIA5110_private.h"
#include "util/delay.h"

void NK_5110_RST_void() {
	DIO_setPinValue_u8(CTRL_PORT, RES_PIN, LOW);
	_delay_ms(110);
	DIO_setPinValue_u8(CTRL_PORT, RES_PIN, HIGH);
}

void NK_5110_CLR_void()
{
	SPI_SS_ENB_void();
	DIO_setPinValue_u8(CTRL_PORT, DC_PIN, HIGH);
	u16 i = 0;
	for (; i <= 503; i++) {
		SPI_MASTER_TRANSMIT(0x00);
	}
	DIO_setPinValue_u8(CTRL_PORT, DC_PIN, LOW);
	SPI_SS_DIS_void();
}

void NK_5110_sendCMD_u8(u8 COMMAND) {
	SPI_SS_ENB_void();
	DIO_setPinValue_u8(CTRL_PORT, DC_PIN, LOW);
	SPI_MASTER_TRANSMIT(COMMAND);
	DIO_setPinValue_u8(CTRL_PORT, DC_PIN, HIGH);
	SPI_SS_DIS_void();
}

void NK_5110_sendData_u8(u8 DATA) {
	SPI_SS_ENB_void();
	DIO_setPinValue_u8(CTRL_PORT, DC_PIN, HIGH);
	SPI_MASTER_TRANSMIT(DATA);
	DIO_setPinValue_u8(CTRL_PORT, DC_PIN, LOW);
	SPI_SS_DIS_void();
}

void NK_5110_INIT_void() {
	DIO_setPinStatus_u8(CTRL_PORT, RES_PIN | DC_PIN, OUTPUT);
	DIO_setPinValue_u8(CTRL_PORT, RES_PIN | DC_PIN, HIGH);

	NK_5110_RST_void();

	NK_5110_sendCMD_u8(0x21); // Function set: PD = 0, V = 1, extended instruction set (H = 1)
	NK_5110_sendCMD_u8(0xC0); // Set Bias
	NK_5110_sendCMD_u8(0x07); // set Vop
	NK_5110_sendCMD_u8(0x13); // function set, h = 0
	NK_5110_sendCMD_u8(0x20);
	NK_5110_sendCMD_u8(0x0C);
}

void NK_5110_SET_XY_void(u8 X_ADD, u8 Y_ADD) {
	NK_5110_sendCMD_u8(0x40 + Y_ADD);
	NK_5110_sendCMD_u8(0x80 + X_ADD);
}
