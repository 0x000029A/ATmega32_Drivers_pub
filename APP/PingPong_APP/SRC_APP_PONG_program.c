/*
 * SRC_APP_PONG_program.c
 *
 *  Created on: Feb 6, 2022
 *      Author: User
 */
#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../HAL/LCD_NOKIA5110/HED_HAL_LCD_NOKIA5110_interface.h"
#include "HED_APP_PONG_config.h"
#include "HED_APP_PONG_private.h"
#include "HED_APP_PONG_interface.h"

void ui_init() {
	NK_5110_SET_XY_void(82, 0);
	NK_5110_sendData_u8(0xFF);
	NK_5110_sendData_u8(0xFF);
	NK_5110_SET_XY_void(0, 0);
	NK_5110_sendData_u8(0xFF);
	NK_5110_sendData_u8(0xFF);
}

void movepad(u8 player, u8 direction)
{
	static u8 yaxis1 = 0, yaxis2 = 0;
	if (player == 1)
	{
		if(direction == UP)
		{
			if (yaxis1 != 0)
			{
				NK_5110_SET_XY_void(0, yaxis1);
				NK_5110_sendData_u8(0x00);
				NK_5110_sendData_u8(0x00);
				yaxis1--;
				NK_5110_SET_XY_void(0, yaxis1);
				NK_5110_sendData_u8(0xFF);
				NK_5110_sendData_u8(0xFF);
			}
		}
		else if (direction == DOWN)
		{
			if (yaxis1 != 6)
			{
				NK_5110_SET_XY_void(0, yaxis1);
				NK_5110_sendData_u8(0x00);
				NK_5110_sendData_u8(0x00);
				yaxis1++;
				NK_5110_SET_XY_void(0, yaxis1);
				NK_5110_sendData_u8(0xFF);
				NK_5110_sendData_u8(0xFF);
			}
		}
	}
	else if (player == 2)
	{
		if(direction == UP)
		{
			if (yaxis2 != 0)
			{
				NK_5110_SET_XY_void(82, yaxis2);
				NK_5110_sendData_u8(0x00);
				NK_5110_sendData_u8(0x00);
				yaxis2--;
				NK_5110_SET_XY_void(82, yaxis2);
				NK_5110_sendData_u8(0xFF);
				NK_5110_sendData_u8(0xFF);
			}
		}
		else if (direction == DOWN)
		{
			if (yaxis2 != 6)
			{
				NK_5110_SET_XY_void(82, yaxis2);
				NK_5110_sendData_u8(0x00);
				NK_5110_sendData_u8(0x00);
				yaxis2++;
				NK_5110_SET_XY_void(82, yaxis2);
				NK_5110_sendData_u8(0xFF);
				NK_5110_sendData_u8(0xFF);
			}
		}
	}
}
