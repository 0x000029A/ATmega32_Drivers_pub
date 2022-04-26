/*********************************************************
 0   File Name: HED_MCAL_EXTI_interface.h                0
 x   File Type: Header                                   x
 2       Layer: Microcontroller Abstraction Layer (MCAL) 2
 9      Module: External Interrupt (EXTI)                9
 A  Created on: 21/09/12                                 A
 *      Author: Mahmoud Hashem                           *
 * Description: Defining functions prototypes of EXTI    *
 *              module settings, macros and call back    *
 *              functions using vectors.                 *
 *     Version: v1.0                                     *
 *********************************************************/

#ifndef HED_MCAL_EXTI_INTERFACE_H_
#define HED_MCAL_EXTI_INTERFACE_H_

/* USE IT AS STATE ARGUMENT INPUT
 * Enabling and disabling interrupts macros 
*/
#define INT_ENABLED         1
#define INT_DISABLED        0

/* USE IT AS SENSE ARGUMENT INPUT
 * SC_LOW_LEVEL: The low level of INT1 generates an interrupt request.
 * SC_ON_CHANGE: Any logical change on INT1 generates an interrupt request.
 * SC_FALLING_EDGE: The falling edge of INT1 generates an interrupt request.
 * SC_RISING_EDGE: The rising edge of INT1 generates an interrupt request.
*/
#define SC_LOW_LEVEL        0b00000000
#define SC_ON_CHANGE        0b00000101
#define SC_FALLING_EDGE     0b00001010
#define SC_RISING_EDGE      0b00001111

/* ONLY INTERRUPT 2
 * USE IT AS SENSE ARGUMENT INPUT
 * SC_FALLING_EDGE: The falling edge of INT1 generates an interrupt request.
 * SC_RISING_EDGE: The rising edge of INT1 generates an interrupt request.
*/
#define SC2_FALLING_EDGE    0
#define SC2_RISING_EDGE     1

/**************************************************
 * Arguments:                                     *
 *           SENSE [LOW LEVEL - ON CHANGE -       *
 *                  FALLING EDGE - RISING EDGE]   *
 * 			 STATE [ENABLE - DISABLE]             *
 * Return:                                        *
 *        ERROR: function did not succeed         *
 *        VALID: function succeeded               *
 * Description: Setting interrupt sense and state *
 *              as described above.               *
 **************************************************/
u8 EXTI_INIT_INT0_u8(u8 COPY_u8_PRV_MCAL_EXTI_SENSE, u8 COPY_u8_PRV_MCAL_EXTI_STATE);

/**************************************************
 * Arguments:                                     *
 *           SENSE [LOW LEVEL - ON CHANGE -       *
 *                  FALLING EDGE - RISING EDGE]   *
 * 			 STATE [ENABLE - DISABLE]             *
 * Return:                                        *
 *        ERROR: function did not succeed         *
 *        VALID: function succeeded               *
 * Description: Setting interrupt sense and state *
 *              as described above.               *
 **************************************************/
u8 EXTI_INIT_INT1_u8(u8 COPY_u8_PRV_MCAL_EXTI_SENSE, u8 COPY_u8_PRV_MCAL_EXTI_STATE);

/**************************************************
 * Arguments:                                     *
 *           SENSE [FALLING EDGE - RISING EDGE}   *
 * 			 STATE [ENABLE - DISABLE]             *
 * Return:                                        *
 *        ERROR: function did not succeed         *
 *        VALID: function succeeded               *
 * Description: Setting interrupt sense and state *
 *              as described above.               *
 **************************************************/
u8 EXTI_INIT_INT2_u8(u8 COPY_u8_PRV_MCAL_EXTI_SENSE, u8 COPY_u8_PRV_MCAL_EXTI_STATE);

/************************************************
 * Arguments:                                   *
 *           Pointer to a non-null function     *
 * Return:                                      *
 *        ERROR: function did not succeed       *
 *        VALID: function succeeded             *
 * Description: Call the required function when *
 *              interrupt happen.               *
 ************************************************/
u8 EXTI_CALL_BACK_INT0_u8(void (*COPY_u8_PRV_MCAL_EXTI_INT0)(void));
u8 EXTI_CALL_BACK_INT1_u8(void (*COPY_u8_PRV_MCAL_EXTI_INT1)(void));
u8 EXTI_CALL_BACK_INT2_u8(void (*COPY_u8_PRV_MCAL_EXTI_INT2)(void));

#endif