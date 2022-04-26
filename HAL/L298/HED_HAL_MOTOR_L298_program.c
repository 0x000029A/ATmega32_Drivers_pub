#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../MCAL/DIO/HED_MCAL_DIO_interface.h"
#include "HED_HAL_MOTOR_L298_config.h"
#include "HED_HAL_MOTOR_L298_interface.h"
#include "HED_HAL_MOTOR_L298_private.h"
#include "util/delay.h"

void L298_INIT_void(void)
{
	DIO_setPortStatus_u8(CTRL_PORT, PORT_OUTPUT);
}

void L298_FORWARD_void()
{
	while (1)
	{
		DIO_setPinValue_u8(CTRL_PORT, ENA2_PIN | ENB2_PIN, LOW);
		DIO_setPinValue_u8(CTRL_PORT, ENA1_PIN | ENB1_PIN, HIGH);

		DIO_setPinValue_u8(CTRL_PORT, IN1_PIN, HIGH);
		DIO_setPinValue_u8(CTRL_PORT, IN2_PIN, LOW);

		DIO_setPinValue_u8(CTRL_PORT, IN3_PIN, HIGH);
		DIO_setPinValue_u8(CTRL_PORT, IN4_PIN, LOW);

		_delay_ms(30);

		DIO_setPinValue_u8(CTRL_PORT, ENA1_PIN | ENB1_PIN, LOW);
		DIO_setPinValue_u8(CTRL_PORT, ENA2_PIN | ENB2_PIN, HIGH);

		DIO_setPinValue_u8(CTRL_PORT, IN1_PIN, LOW);
		DIO_setPinValue_u8(CTRL_PORT, IN2_PIN, HIGH);

		DIO_setPinValue_u8(CTRL_PORT, IN3_PIN, LOW);
		DIO_setPinValue_u8(CTRL_PORT, IN4_PIN, HIGH);

		_delay_ms(30);
	}
}

void L298_BACKWARD_void()
{

}

void L298_RIGHT_void()
{

}

void L298_LEFT_void()
{

}

void L298_SPEED_UP_void()
{

}

void L298_SLOW_UP_void()
{

}
