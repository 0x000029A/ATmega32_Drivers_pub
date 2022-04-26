/*********************************************************
 0   File Name: HED_MCAL_DIO_register.h                  0
 x   File Type: Header                                   x
 2       Layer: Microcontroller Abstraction Layer (MCAL) 2
 9      Module: Digital Input/Output (DIO)               9
 A  Created on: 21/09/04                                 A
 *      Author: Mahmoud Hashem                           *
 * Description: DIO registers' addresses and bits        *
 *     Version: v1.1                                     *
 *********************************************************/

#ifndef HED_MCAL_DIO_REGISTER_H_
#define HED_MCAL_DIO_REGISTER_H_

/* Defining PORTx registers' addresses [PORTA - PORTB - PORTC - PORTD] */
#define u8_PRV_MCAL_DIO_PORTA   ((volatile u8*)0x3B)
#define u8_PRV_MCAL_DIO_PORTB   ((volatile u8*)0x38)
#define u8_PRV_MCAL_DIO_PORTC   ((volatile u8*)0x35)
#define u8_PRV_MCAL_DIO_PORTD   ((volatile u8*)0x32)

/* Defining DDRx registers' addresses [DDRA - DDRB - DDRC - DDRD] */
#define u8_PRV_MCAL_DIO_DDRA    ((volatile u8*)0x3A)
#define u8_PRV_MCAL_DIO_DDRB    ((volatile u8*)0x37)
#define u8_PRV_MCAL_DIO_DDRC    ((volatile u8*)0x34)
#define u8_PRV_MCAL_DIO_DDRD    ((volatile u8*)0x31)

/* Defining PINx registers' addresses [PINA - PINB - PINC - PIND] */
#define u8_PRV_MCAL_DIO_PINA    ((volatile u8*)0x39)
#define u8_PRV_MCAL_DIO_PINB    ((volatile u8*)0x36)
#define u8_PRV_MCAL_DIO_PINC    ((volatile u8*)0x33)
#define u8_PRV_MCAL_DIO_PIND    ((volatile u8*)0x30)

/* SFIOR Register */
#define u8_PRV_MCAL_DIO_SFIOR   *((volatile u8*)0x50)
#define SFIOR_PUD               0b00000100

#endif