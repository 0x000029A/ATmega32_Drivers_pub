/*************************************************
 0   File Name: SRC_HAL_CLCD_LMB161A_program.c   0
 x   File Type: Source                           x
 2       Layer: Hardware Abstraction Layer (HAL) 2
 9      Module: LMB161A                          9
 A  Created on: 21/10/29                         A
 *      Author: Mahmoud Hashem                   *
 * Description: Functions bodies                 *
 *     Version: v1.0                             *
 *************************************************/

#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../MCAL/DIO/HED_MCAL_DIO_interface.h"
#include "HED_HAL_CLCD_LMB161A_config.h"
#include "HED_HAL_CLCD_LMB161A_interface.h"
#include "util/delay.h"
#include "stdlib.h"

void LMB161A_sendCMD_void(u8 command)
{
	DIO_setPinValue_u8(CTRL_PORT, RS_PIN | RW_PIN, LOW);
	DIO_setPortValue_u8(COMM_PORT, command);
	DIO_setPinValue_u8(CTRL_PORT, EN_PIN, HIGH);
	_delay_ms(2);
	DIO_setPinValue_u8(CTRL_PORT, EN_PIN, LOW);
}

void LMB161A_sendData_void(u8 data)
{
	DIO_setPinValue_u8(CTRL_PORT, RS_PIN, HIGH);
	DIO_setPinValue_u8(CTRL_PORT, RW_PIN, LOW);
	DIO_setPortValue_u8(COMM_PORT, data);
	DIO_setPinValue_u8(CTRL_PORT, EN_PIN, HIGH);
	_delay_ms(2);
	DIO_setPinValue_u8(CTRL_PORT, EN_PIN, LOW);
}

void LMB161A_sendString_void(const char * string)
{
	u8 i = 0;
	while (string[i] != '\0')
	{
		LMB161A_sendData_void(string[i]);
		i++;
	}
}

void LMB161A_GOTO_void(u8 COPY_u8_X_POS, u8 COPY_u8_Y_POS)
{
	u8 LOC_CLCD_ADD;
	if (COPY_u8_X_POS == 0)
	{
		LOC_CLCD_ADD = COPY_u8_Y_POS;
	}
	else if (COPY_u8_X_POS == 1)
	{
		LOC_CLCD_ADD = COPY_u8_Y_POS + 0x40;
	}
	LMB161A_sendCMD_void(0x80 + LOC_CLCD_ADD);
}

void LMB161A_saveExChar_void(u8 COPY_u8_CUSTOM_CHAR[][8], u8 COPY_u8_BLOCK_NUM, u8 COPY_NUM_OF_BLOCKS)
{
	u8 i, j;
	u8 localaddress = 0;
	for (i = 0; i < COPY_NUM_OF_BLOCKS; i++)
	{
		localaddress = COPY_u8_BLOCK_NUM * 8;
		LMB161A_sendCMD_void(localaddress + 64);
		for (j = 0; j < 8; j++)
		{
			LMB161A_sendData_void(COPY_u8_CUSTOM_CHAR[i][j]);
		}
		COPY_u8_BLOCK_NUM++;
	}
}

void LMB161A_dispExChar_void(u8 COPY_u8_BLOCK_NUM)
{
	LMB161A_sendData_void(COPY_u8_BLOCK_NUM);
}

void LMB161A_dispNum_void(u32 COPY_u32_NUM)
{
	u32 buffer[33];
	itoa (COPY_u32_NUM, buffer, 10);
	LMB161A_sendString_void(buffer);
}

void LMB161A_INIT_void()
{
	_delay_ms(40);
	DIO_setPortStatus_u8(COMM_PORT, PORT_HIGH);
	DIO_setPinStatus_u8(CTRL_PORT, RS_PIN | EN_PIN | RW_PIN, OUTPUT);
	LMB161A_sendCMD_void(CLCD_FUNC_SET);
	_delay_us(50);
	LMB161A_sendCMD_void(CLCD_DISP_CTRL);
	_delay_us(50);
	LMB161A_sendCMD_void(0x01);
	_delay_ms(2);
}