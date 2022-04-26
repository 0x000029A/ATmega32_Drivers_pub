/*
 * SRC_HAL_SSD_program.c
 *
 *  Created on: Sep 5, 2021
 *      Author: User
 */


#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../MCAL/DIO/HED_MCAL_DIO_interface.h"
#include "HED_HAL_SSD_config.h"
#include "HED_HAL_SSD_interface.h"

u8 segnums[10] = {NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9};

u8 u8_SSD_setNumber(u8 COPY_u8_PBC_HAL_SSD_NUM, SSD *COPY_SSD)
{
	u8 LOC_u8_PRV_MCAL_DIO_OpStatus = VALID_u8_DIO;
	switch (COPY_SSD->u8_PBC_HAL_SSD_COM_TYPE)
	{
		case COM_AND:
			setPortStatus_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_PORT, segnums[COPY_u8_PBC_HAL_SSD_NUM]);
			setPortValue_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_PORT, ~segnums[COPY_u8_PBC_HAL_SSD_NUM]);
			break;
		case COM_CTH:
			setPortStatus_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_PORT, segnums[COPY_u8_PBC_HAL_SSD_NUM]);
			setPortValue_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_PORT, segnums[COPY_u8_PBC_HAL_SSD_NUM]);
			break;
		default:
			LOC_u8_PRV_MCAL_DIO_OpStatus = ERROR_u8_DIO;
			break;
	}
	return LOC_u8_PRV_MCAL_DIO_OpStatus;
}

u8 SSD_dispSTATE_u8(SSD *COPY_SSD, u8 COPY_u8_DISP_STATE)
{
	u8 LOC_u8_PRV_MCAL_DIO_OpStatus = VALID_u8_DIO;
	switch (COPY_u8_DISP_STATE)
	{
	case ON:
		switch (COPY_SSD->u8_PBC_HAL_SSD_COM_TYPE)
		{
			case COM_AND:
				setPinStatus_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_ENB_PORT, COPY_SSD->u8_PBC_HAL_SSD_ENB_PIN, OUTPUT_DIO_u8);
				setPinValue_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_ENB_PORT, COPY_SSD->u8_PBC_HAL_SSD_ENB_PIN, HIGH_u8_DIO);
				break;
			case COM_CTH:
				setPinStatus_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_ENB_PORT, COPY_SSD->u8_PBC_HAL_SSD_ENB_PIN, OUTPUT_DIO_u8);
				setPinValue_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_ENB_PORT, COPY_SSD->u8_PBC_HAL_SSD_ENB_PIN, LOW_u8_DIO);
				break;
			default:
				LOC_u8_PRV_MCAL_DIO_OpStatus = ERROR_u8_DIO;
				break;
		}
		break;
	case OFF:
		switch (COPY_SSD->u8_PBC_HAL_SSD_COM_TYPE)
		{
			case COM_AND:
				setPinStatus_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_ENB_PORT, COPY_SSD->u8_PBC_HAL_SSD_ENB_PIN, OUTPUT_DIO_u8);
				setPinValue_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_ENB_PORT, COPY_SSD->u8_PBC_HAL_SSD_ENB_PIN, LOW_u8_DIO);
				break;
			case COM_CTH:
				setPinStatus_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_ENB_PORT, COPY_SSD->u8_PBC_HAL_SSD_ENB_PIN, OUTPUT_DIO_u8);
				setPinValue_DIO_u8(COPY_SSD->u8_PBC_HAL_SSD_ENB_PORT, COPY_SSD->u8_PBC_HAL_SSD_ENB_PIN, HIGH_u8_DIO);
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