/*
 * HED_APP_PONG_interface.h
 *
 *  Created on: Feb 6, 2022
 *      Author: User
 */
#ifndef ATMEGA32L_APP_PINGPONG_APP_HED_APP_PONG_INTERFACE_H_
#define ATMEGA32L_APP_PINGPONG_APP_HED_APP_PONG_INTERFACE_H_

#define UP		1
#define DOWN	0

void ui_init(void);
void movepad(u8 player, u8 direction);

#endif
