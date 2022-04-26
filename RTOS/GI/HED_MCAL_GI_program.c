/*********************************************************
 0   File Name: HED_MCAL_GI_program.c                    0
 x   File Type: Source                                   x
 2       Layer: Microcontroller Abstraction Layer (MCAL) 2
 9      Module: External Interrupt (EXTI)                9
 A  Created on: 21/09/13                                 A
 *      Author: Mahmoud Hashem                           *
 * Description: Functions to manipulate registers        *
 *     Version: v1.0                                     *
 *********************************************************/

#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "HED_MCAL_GI_interface.h"
#include "HED_MCAL_GI_register.h"
#include "HED_MCAL_GI_config.h"
#include "HED_MCAL_GI_private.h"

void GI_ENB()
{
    u8_PRV_MCAL_GI_SREG |= I_SREG;
}

void GI_DIS()
{
    u8_PRV_MCAL_GI_SREG &= ~I_SREG;
}