/*
 * HED_HAL_LED_program.c
 *
 *  Created on: Sep 5, 2021
 *      Author: User
 */


#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../MCAL/DIO/HED_MCAL_DIO_interface.h"
#include "HED_HAL_LED_interface.h"

u8 turnSTATE_u8_LED(LED * COPY_LED, u8 COPY_u8_MODE_STATE)
{
	u8 LOC_u8_PRV_MCAL_DIO_OpStatus = VALID_u8_DIO;
	switch (COPY_u8_MODE_STATE)
	{
	case ON:
		switch (COPY_LED->u8_PBC_HAL_SSD_CON_TYPE)
		{
			case SINK:
				setPinStatus_DIO_u8(COPY_LED->u8_PBC_HAL_LED_PORT, COPY_LED->u8_PBC_HAL_LED_PIN, INPUT_DIO_u8);
				setPinValue_DIO_u8(COPY_LED->u8_PBC_HAL_LED_PORT, COPY_LED->u8_PBC_HAL_LED_PIN, LOW_u8_DIO);
				break;
			case SOURCE:
				setPinStatus_DIO_u8(COPY_LED->u8_PBC_HAL_LED_PORT, COPY_LED->u8_PBC_HAL_LED_PIN, OUTPUT_DIO_u8);
				setPinValue_DIO_u8(COPY_LED->u8_PBC_HAL_LED_PORT, COPY_LED->u8_PBC_HAL_LED_PIN, HIGH_u8_DIO);
				break;
			default:
				LOC_u8_PRV_MCAL_DIO_OpStatus = ERROR_u8_DIO;
				break;
		}
		break;
	
	case OFF:
		switch (COPY_LED->u8_PBC_HAL_SSD_CON_TYPE)
		{
			case SINK:
				setPinStatus_DIO_u8(COPY_LED->u8_PBC_HAL_LED_PORT, COPY_LED->u8_PBC_HAL_LED_PIN, OUTPUT_DIO_u8);
				setPinValue_DIO_u8(COPY_LED->u8_PBC_HAL_LED_PORT, COPY_LED->u8_PBC_HAL_LED_PIN, HIGH_u8_DIO);
				break;
			case SOURCE:
				setPinStatus_DIO_u8(COPY_LED->u8_PBC_HAL_LED_PORT, COPY_LED->u8_PBC_HAL_LED_PIN, OUTPUT_DIO_u8);
				setPinValue_DIO_u8(COPY_LED->u8_PBC_HAL_LED_PORT, COPY_LED->u8_PBC_HAL_LED_PIN, LOW_u8_DIO);
				break;
			default:
				LOC_u8_PRV_MCAL_DIO_OpStatus = ERROR_u8_DIO;
				break;
		}
		break;
	default:
		LOC_u8_PRV_MCAL_DIO_OpStatus = ERROR_u8_DIO;
		break;
	}
	return LOC_u8_PRV_MCAL_DIO_OpStatus;
}