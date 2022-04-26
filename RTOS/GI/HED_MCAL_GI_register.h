/*********************************************************
 0   File Name: HED_MCAL_GI_register.h                   0
 x   File Type: Header                                   x
 2       Layer: Microcontroller Abstraction Layer (MCAL) 2
 9      Module: General Interrupt (GI)                   9
 A  Created on: 21/09/13                                 A
 *      Author: Mahmoud Hashem                           *
 * Description: GI registers' addresses and bits         *
 *     Version: v1.0                                     *
 *********************************************************/

#ifndef HED_MCAL_GI_REGISTER_H_
#define HED_MCAL_GI_REGISTER_H_

#define u8_PRV_MCAL_GI_SREG     *((volatile u8*)0x5F)
#define I_SREG                  0b10000000

#endif