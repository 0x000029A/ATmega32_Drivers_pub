/*
 * HED_HAL_SSD_interface.h
 *
 *  Created on: Sep 5, 2021
 *      Author: User
 */

#ifndef HED_HAL_SSD_INTERFACE_H_
#define HED_HAL_SSD_INTERFACE_H_

#define COM_AND 0
#define COM_CTH 1

#define ON  1
#define OFF 2

struct SSD {
	u8 u8_PBC_HAL_SSD_COM_TYPE;
	u8 u8_PBC_HAL_SSD_PORT;
	u8 u8_PBC_HAL_SSD_ENB_PORT;
	u8 u8_PBC_HAL_SSD_ENB_PIN;
};

typedef struct SSD SSD;

u8 u8_SSD_setNumber(u8 COPY_u8_PBC_HAL_SSD_NUM, SSD *COPY_SSD);
u8 SSD_dispSTATE_u8(SSD *COPY_SSD, u8 COPY_u8_DISP_STATE);

#endif /* HED_HAL_SSD_INTERFACE_H_ */
