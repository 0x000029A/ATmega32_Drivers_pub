/**********************************************************
 0   File Name: HED_HAL_CLCD_LMB161A_config.h             0
 x   File Type: Header                                    x
 2       Layer: Hardware Abstraction Layer (HAL)          2
 9      Module: LMB161A                                   9
 A  Created on: 21/10/29                                  A
 *      Author: Mahmoud Hashem                            *
 * Description: Pre-build configuration of LMB161A module *
 *     Version: v1.0                                      *
 **********************************************************/

#ifndef HED_HAL_CLCD_LMB161A_CONFIG_H_
#define HED_HAL_CLCD_LMB161A_CONFIG_H_

/* Define the port used for RS, R/W, E pins */
#define CTRL_PORT PORTC
#define RS_PIN PIN0
#define RW_PIN PIN1
#define EN_PIN PIN2

#define COMM_PORT PORTD

/*
 * Function Set
 * ************
 * Font Size - Bit 2:
 * 5*8:  0
 * 5*11: 1
 * ******************
 * Line Mode - Bit 3:
 * 1 line:  0
 * 2 lines: 1
 * **********
 */
#define CLCD_FUNC_SET (0b00111100)

/* Display Control
 * ***************
 * Cursor Blinking - Bit 0:
 * OFF: 0
 * ON:  1
 * ONLY WORKS WHEN CURSOR DISPLAYING IS ON
 * ***************************************
 * Cursor Displaying - Bit 1:
 * OFF: 0
 * ON: 1
 * *********************
 * Display Mode - Bit 2:
 * OFF: 0
 * ON:  1
 */
#define CLCD_DISP_CTRL  (0b00001100)

/***********************************************************/

/* Positioning
 * if your CLCD
 */

#define u8_CLCD_NEXT_POS 0x40

#endif
