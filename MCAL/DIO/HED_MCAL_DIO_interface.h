/*************************************************************
 0   File Name: HED_MCAL_DIO_interface.h                     0
 x   File Type: Header                                       x
 2       Layer: Microcontroller Abstraction Layer (MCAL)     2
 9      Module: Digital Input/Output (DIO)                   9
 A  Created on: 21/09/04                                     A
 *      Author: Mahmoud Hashem                               *
 * Description: Defining functions prototypes to manipulate  *
 *              registers and pins status and values macros. *
 *     Version: v1.2                                         *
 ************************************************************/

#ifndef HED_MCAL_DIO_INTERFACE_H_
#define HED_MCAL_DIO_INTERFACE_H_

/* Pin direction macros for I/P - O/P operations */
#define OUTPUT      0xFF // Set DDRx pin direction as output
#define INPUT       0x00 // Set DDRx pin direction as input

/* Port direction macros for I/P - O/P operations*/
#define PORT_OUTPUT 0xFF // Set DDRx port direction as output
#define PORT_INPUT  0x00 // Set DDRx port direction as input

/* Pin value macros for +5v - 0v */
#define HIGH        0xFF // Set PORT pin value as high (+5v)
#define LOW         0x00 // Set PORT pin value as low (0v)

/* Port value macros for +5v - 0v */
#define PORT_HIGH   0xFF // Set PORT port value as high (+5v)
#define PORT_LOW    0x00 // Set PORT port value as low (0v)

/* Macros for PORTx index */
#define PORTA_u8    0 // PORTA
#define PORTB_u8    1 // PORTB
#define PORTC_u8    2 // PORTC
#define PORTD_u8    3 // PORTD

/* Macros for each pin binary index */
#define PIN0_u8     0b00000001
#define PIN1_u8     0b00000010
#define PIN2_u8     0b00000100
#define PIN3_u8     0b00001000
#define PIN4_u8     0b00010000
#define PIN5_u8     0b00100000
#define PIN6_u8     0b01000000
#define PIN7_u8     0b10000000

/****************************************************
 * Arguments:                                       *
 *           PORT   [PORTA - PORTB - PORTC - PORTD] *
 * 			 STATUS [PORT_OUTPUT - PORT_INPUT]      *
 * Return:                                          *
 *        ERROR: function did not succeed           *
 *        VALID: function succeeded                 *
 * Description: Setting pin direction as:           *
 * 	           PORT_OUTPUT: DDRx as output (1)      *
 *             PORT_INPUT:  DDRx as input (0)       *
 ****************************************************/
u8 DIO_setPortStatus_u8(u8 COPY_u8_PRV_MCAL_DIO_PORT, u8 COPY_u8_PRV_MCAL_DIO_STATUS);

/****************************************************
 * Arguments:                                       *
 *           PORT   [PORTA - PORTB - PORTC - PORTD] *
 * 			 PIN    [PIN0 - PIN1 - PIN2 - PIN3      *
 *                   PIN4 - PIN5 - PIN7 - PIN8]     *
 * 			 STATUS [OUTPUT - INPUT]                *
 * Return:                                          *
 *        ERROR: function did not succeed           *
 *        VALID: function succeeded                 *
 * Description: Setting pin direction as:           *
 *             OUTPUT: DDRx PINx as output (1)      *
 *             INPUT:  DDRx PINx as input (0)       *
 ****************************************************/
u8 DIO_setPinStatus_u8(u8 COPY_u8_PRV_MCAL_DIO_PORT, u8 COPY_u8_PRV_MCAL_DIO_PIN, u8 COPY_u8_PRV_MCAL_DIO_PORT_STATUS);

/****************************************************
 * Arguments:                                       *
 *           PORT   [PORTA - PORTB - PORTC - PORTD] *
 * 			 VALUE [PORT_HIGH - PORT_LOW]           *
 * Return:                                          *
 *        ERROR: function did not succeed           *
 *        VALID: function succeeded                 *
 * Description: Setting pin direction as:           *
 * 	           PORT_HIGH: PORTx as high (1 : +5v)   *
 *             PORT_LOW:  PORTx as low (0 : 0v)     *
 ****************************************************/
u8 DIO_setPortValue_u8(u8 COPY_u8_PRV_MCAL_DIO_PORT, u8 COPY_u8_PRV_MCAL_DIO_VALUE);

/****************************************************
 * Arguments:                                       *
 *           PORT   [PORTA - PORTB - PORTC - PORTD] *
 * 			 PIN    [PIN0 - PIN1 - PIN2 - PIN3      *
 *                   PIN4 - PIN5 - PIN7 - PIN8]     *
 * 			 VALUE  [HIGH - LOW]                    *
 * Return:                                          *
 *        ERROR: function did not succeed           *
 *        VALID: function succeeded                 *
 * Description: Setting pin direction as:           *
 * 	           HIGH: PORTx PINx as high (1 : +5v)   *
 *             LOW:  PORTx PINx as low (0 : 0v)     *
 ****************************************************/
u8 DIO_setPinValue_u8(u8 COPY_u8_PRV_MCAL_DIO_PORT, u8 COPY_u8_PRV_MCAL_DIO_PIN, u8 COPY_u8_PRV_MCAL_DIO_PIN_VALUE);

/****************************************************
 * Arguments:                                       *
 *           PORT   [PORTA - PORTB - PORTC - PORTD] *
 * 			 PIN    [PIN0 - PIN1 - PIN2 - PIN3      *
 *                   PIN4 - PIN5 - PIN7 - PIN8]     *
 *           PIN VALUE [1 - 0]                      *
 * Return:                                          *
 *        ERROR: function did not succeed           *
 *        VALID: function succeeded                 *
 * Description: Getting port pin value:             *
 * 	           1:  PORTx PINx is high (1 / +5v)     *
 *             0:  PORTx PINx is low (0 / 0v)       *
 ****************************************************/
u8 DIO_getPinValue_u8(u8 COPY_u8_PRV_MCAL_DIO_PORT, u8 COPY_u8_PRV_MCAL_DIO_PIN, u8 *COPY_u8_PRV_MCAL_DIO_PIN_VALUE);

/************************************************
 * Arguments:                                   *
 *           Void                               *
 * Return:                                      *
 *        Void                                  *
 * Description: Disabling pull-ups in the I/O   *
 *              ports even if the DDxn and      *
 *              PORTxn Registers are configured *
 *              to enable the pull-ups.         *
 ************************************************/
void DIO_disablePullUps_void(void);

/************************************************
 * Arguments:                                   *
 *           Void                               *
 * Return:                                      *
 *        Void                                  *
 * Description: Enabling pull-ups in the I/O    *
 ************************************************/
void DIO_enablePullUps_void(void);

#endif