/***********************************************
 0   File Name: LIB_VRT_BIT_MATH.h             0
 x   File Type: Library                        x
 2       Layer: Vertical                       2
 A  Created on: Aug 31, 2021                   A
 *      Author: Mahmoud Hashem                 *
 * Description: Bitwise and logical operations *
 *     Version: v1.0                           *
 ***********************************************/

/* Header file guard */
#ifndef LIB_VRT_BIT_MATH_H_
#define LIB_VRT_BIT_MATH_H_

#define SET_BIT(REG, BIT) REG |= 1 << BIT    // Setting  bit BIT (0-7) in register REG []
#define CLR_BIT(REG, BIT) REG &= ~(1 << BIT) // Clearing bit BIT (0-7) in register REG []
#define TGL_BIT(REG, BIT) REG ^= 1 << BIT	 // Toggling bit BIT (0-7) in register REG []
#define GET_BIT(REG, BIT) ((REG >> BIT) & 1) // Reading  bit BIT (0-7) in register REG []

#endif /* LIB_VRT_BIT_MATH_H_ */
