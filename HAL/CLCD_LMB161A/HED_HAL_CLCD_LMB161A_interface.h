/*************************************************
 0   File Name: HED_HAL_CLCD_LMB161A_interface.h 0
 x   File Type: Header                           x
 2       Layer: Hardware Abstraction Layer (HAL) 2
 9      Module: LMB161A                          9
 A  Created on: 21/10/29                         A
 *      Author: Mahmoud Hashem                   *
 * Description: Defining functions prototypes    *
 *     Version: v1.0                             *
 *************************************************/

#ifndef HED_HAL_CLCD_LMB161A_INTERFACE_H_
#define HED_HAL_CLCD_LMB161A_INTERFACE_H_

void LMB161A_sendCMD_void(u8 command);
void LMB161A_sendData_void(u8 data);
void LMB161A_sendString_void(const char * string);
void LMB161A_GOTO_void(u8 COPY_u8_X_POS, u8 COPY_u8_Y_POS);
void LMB161A_saveExChar_void(u8 COPY_u8_CUSTOM_CHAR[][8], u8 COPY_u8_BLOCK_NUM, u8 COPY_NUM_OF_BLOCKS);
void LMB161A_dispExChar_void(u8 COPY_u8_BLOCK_NUM);
void LMB161A_dispNum_void(u32 COPY_u32_NUM);
void LMB161A_INIT_void(void);

#endif
