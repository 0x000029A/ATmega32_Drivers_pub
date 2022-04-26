#ifndef HED_HAL_MOTOR_L298_PRIVATE_H_
#define HED_HAL_MOTOR_L298_PRIVATE_H_
#include "../../MCAL/DIO/HED_MCAL_DIO_interface.h"

void L298_CC_void(u8 PORT, u8 INX, u8 INY)
{
	DIO_setPinValue_u8(PORT, INX, HIGH);
	DIO_setPinValue_u8(PORT, INY, LOW);
}

void L298_CCW_void(u8 PORT, u8 INX, u8 INY)
{
	DIO_setPinValue_u8(PORT, INX, LOW);
	DIO_setPinValue_u8(PORT, INY, HIGH);
}

#endif
