/*
 * HED_HAL_LED_interface.h
 *
 *  Created on: Sep 5, 2021
 *      Author: User
 */

#ifndef HED_HAL_LED_INTERFACE_H_
#define HED_HAL_LED_INTERFACE_H_

#define SINK   1
#define SOURCE 2

#define ON  1
#define OFF 2

struct LED {
	u8 u8_PBC_HAL_LED_PORT;
	u8 u8_PBC_HAL_LED_PIN;
	u8 u8_PBC_HAL_SSD_CON_TYPE;
};

typedef struct LED LED;

u8 turnSTATE_u8_LED(LED * COPY_LED, u8 COPY_u8_MODE_STATE);


#endif /* HED_HAL_LED_INTERFACE_H_ */
