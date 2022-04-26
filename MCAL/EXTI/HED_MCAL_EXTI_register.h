/*********************************************************
 0   File Name: HED_MCAL_EXTI_register.h                 0
 x   File Type: Header                                   x
 2       Layer: Microcontroller Abstraction Layer (MCAL) 2
 9      Module: External Interrupt (EXTI)                9
 A  Created on: 21/09/12                                 A
 *      Author: Mahmoud Hashem                           *
 * Description: EXTI registers' addresses and bits       *
 *     Version: v1.0                                     *
 *********************************************************/

#ifndef HED_MCAL_EXTI_REGISTER_H_
#define HED_MCAL_EXTI_REGISTER_H_

#define u8_PRV_MCAL_EXTI_GICR   *((volatile u8*)0x5B)
#define GICR_INT0               0b01000000
#define GICR_INT1               0b10000000
#define GICR_INT2               0b00100000

#define u8_PRV_MCAL_EXTI_GIFR   *((volatile u8*)0x5A)

#define u8_PRV_MCAL_EXTI_MCUCR  *((volatile u8*)0x55)
#define MCUCR_ISC00             0b00000001
#define MCUCR_ISC01             0b00000010
#define MCUCR_ISC10             0b00000100
#define MCUCR_ISC11             0b00001000

#define u8_PRV_MCAL_EXTI_MCUCSR *((volatile u8*)0x54)
#define MCUCSR_ISC2              0b01000000

#endif