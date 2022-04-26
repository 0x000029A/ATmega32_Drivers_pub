/*********************************************************
 0   File Name: HED_MCAL_GI_interface.h                  0
 x   File Type: Header                                   x
 2       Layer: Microcontroller Abstraction Layer (MCAL) 2
 9      Module: General Interrupt (GI)                   9
 A  Created on: 21/09/13                                 A
 *      Author: Mahmoud Hashem                           *
 * Description: Enable & DIsable of GI functions         *
 *     Version: v1.0                                     *
 *********************************************************/

#ifndef HED_MCAL_GI_INTERFACE_H_
#define HED_MCAL_GI_INTERFACE_H_

/*******************************************
 * Arguments:                              *
 *           Void                          *
 * Return:                                 *
 *        Void                             *
 * Description: Enabling general interrupt *
 *******************************************/
void GI_ENB(void);

/********************************************
 * Arguments:                               *
 *           Void                           *
 * Return:                                  *
 *        Void                              *
 * Description: Disabling general interrupt *
 ********************************************/
void GI_DIS(void);

#endif