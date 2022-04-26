/*********************************************************
 0   File Name: SRC_MCAL_DIO_program.c                   0
 x   File Type: Source                                   x
 2       Layer: Microcontroller Abstraction Layer (MCAL) 2
 9      Module: Digital Input/Output (DIO)               9
 A  Created on: 21/09/04                                 A
 *      Author: Mahmoud Hashem                           *
 * Description: Functions to manipulate registers        *
 *              and pins status and values.              *
 *     Version: v1.0                                     *
 *********************************************************/

#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "HED_MCAL_DIO_register.h"
#include "HED_MCAL_DIO_interface.h"
#include "HED_MCAL_DIO_config.h"
#include "HED_MCAL_DIO_private.h"

static volatile u8* GLB_PRV_MCAL_DIO_PORTS_ARR[4] = {u8_PRV_MCAL_DIO_PORTA, u8_PRV_MCAL_DIO_PORTB, u8_PRV_MCAL_DIO_PORTC, u8_PRV_MCAL_DIO_PORTD};

static volatile u8* GLB_PRV_MCAL_DIO_DDRS_ARR[4] = {u8_PRV_MCAL_DIO_DDRA, u8_PRV_MCAL_DIO_DDRB, u8_PRV_MCAL_DIO_DDRC, u8_PRV_MCAL_DIO_DDRD};

static volatile u8* GLB_PRV_MCAL_DIO_PINS_ARR[4] = {u8_PRV_MCAL_DIO_PINA, u8_PRV_MCAL_DIO_PINB, u8_PRV_MCAL_DIO_PINC, u8_PRV_MCAL_DIO_PIND};

u8 DIO_setPortStatus_u8(u8 COPY_u8_PRV_MCAL_DIO_PORT, u8 COPY_u8_PRV_MCAL_DIO_STATUS)
{
	/* Operation statue variable that returns either error or valid operation */
	u8 LOC_u8_PBC_MCAL_DIO_OpStatus = VALID;

	/* Checking if all arguments inputs are within the valid inputs */
	if (((COPY_u8_PRV_MCAL_DIO_PORT >= PORTA_u8) &&
	    (COPY_u8_PRV_MCAL_DIO_PORT <= PORTD_u8)) &&
		((COPY_u8_PRV_MCAL_DIO_STATUS >= PORT_INPUT) &&
		(COPY_u8_PRV_MCAL_DIO_STATUS <= PORT_OUTPUT)))
	{
		/* Setting PORTx as the input STATUS */
		*GLB_PRV_MCAL_DIO_DDRS_ARR[COPY_u8_PRV_MCAL_DIO_PORT] = COPY_u8_PRV_MCAL_DIO_STATUS;
	}
	else
	{
		/* Some inputs are not valid so operation did not succeed */
		LOC_u8_PBC_MCAL_DIO_OpStatus = ERROR;
	}
	/* Returning operation status */
	return LOC_u8_PBC_MCAL_DIO_OpStatus;
}

u8 DIO_setPinStatus_u8(u8 COPY_u8_PRV_MCAL_DIO_PORT, u8 COPY_u8_PRV_MCAL_DIO_PIN, u8 COPY_u8_PRV_MCAL_DIO_PORT_STATUS)
{
	/* Operation statue variable that returns either error or valid operation */
	u8 LOC_u8_PBC_MCAL_DIO_OpStatus = VALID;

	/* Checking if all arguments inputs are within the valid inputs */
	if (((COPY_u8_PRV_MCAL_DIO_PORT >= PORTA_u8) &&
	    (COPY_u8_PRV_MCAL_DIO_PORT <= PORTD_u8)) &&
		((COPY_u8_PRV_MCAL_DIO_PIN >= PORT_INPUT) &&
		(COPY_u8_PRV_MCAL_DIO_PIN <= PORT_OUTPUT)))
	{
		/* Assigning STATUS value to PORTx PINx by ANDing it with the pin.
		   So if STATUS is output (1) the result would be 1
		   If input it would be 0
		*/
		*GLB_PRV_MCAL_DIO_DDRS_ARR[COPY_u8_PRV_MCAL_DIO_PORT] &= ~COPY_u8_PRV_MCAL_DIO_PIN;
		*GLB_PRV_MCAL_DIO_DDRS_ARR[COPY_u8_PRV_MCAL_DIO_PORT] |= (COPY_u8_PRV_MCAL_DIO_PIN & COPY_u8_PRV_MCAL_DIO_PORT_STATUS);
	}
	else
	{
		LOC_u8_PBC_MCAL_DIO_OpStatus = ERROR;
	}
	return LOC_u8_PBC_MCAL_DIO_OpStatus;
}

u8 DIO_setPortValue_u8(u8 COPY_u8_PRV_MCAL_DIO_PORT, u8 COPY_u8_PRV_MCAL_DIO_VALUE)
{
	/* Operation statue variable that returns either error or valid operation */
	u8 LOC_u8_PBC_MCAL_DIO_OpStatus = VALID;

	/* Checking if all arguments inputs are within the valid inputs */
	if (((COPY_u8_PRV_MCAL_DIO_PORT >= PORTA_u8) &&
	    (COPY_u8_PRV_MCAL_DIO_PORT <= PORTD_u8)) &&
		((COPY_u8_PRV_MCAL_DIO_VALUE >= PORT_LOW) &&
		(COPY_u8_PRV_MCAL_DIO_VALUE <= PORT_HIGH)))
	{
		/* Setting PORTx as the input VALUE */
		*GLB_PRV_MCAL_DIO_PORTS_ARR[COPY_u8_PRV_MCAL_DIO_PORT] = COPY_u8_PRV_MCAL_DIO_VALUE;
	}
	else
	{
		LOC_u8_PBC_MCAL_DIO_OpStatus = ERROR;
	}
	return LOC_u8_PBC_MCAL_DIO_OpStatus;
}

u8 DIO_setPinValue_u8(u8 COPY_u8_PRV_MCAL_DIO_PORT, u8 COPY_u8_PRV_MCAL_DIO_PIN, u8 COPY_u8_PRV_MCAL_DIO_PIN_VALUE)
{
	/* Operation statue variable that returns either error or valid operation */
	u8 LOC_u8_PBC_MCAL_DIO_OpStatus = VALID;

	/* Checking if all arguments inputs are within the valid inputs */
	if (((COPY_u8_PRV_MCAL_DIO_PORT >= PORTA_u8) &&
	    (COPY_u8_PRV_MCAL_DIO_PORT <= PORTD_u8)) &&
		((COPY_u8_PRV_MCAL_DIO_PIN >= PORT_LOW) &&
		(COPY_u8_PRV_MCAL_DIO_PIN <= PORT_HIGH)))
	{
		/* Assigning PIN VALUE value to PORTx PINx by ANDing it with the pin.
		   So if PIN VALUE is high (1) the result would be 1
		   If low it would be 0
		*/
		*GLB_PRV_MCAL_DIO_PORTS_ARR[COPY_u8_PRV_MCAL_DIO_PORT] &= ~COPY_u8_PRV_MCAL_DIO_PIN;
		*GLB_PRV_MCAL_DIO_PORTS_ARR[COPY_u8_PRV_MCAL_DIO_PORT] |= (COPY_u8_PRV_MCAL_DIO_PIN & COPY_u8_PRV_MCAL_DIO_PIN_VALUE);
	}
	else
	{
		LOC_u8_PBC_MCAL_DIO_OpStatus = ERROR;
	}
	return LOC_u8_PBC_MCAL_DIO_OpStatus;
}

u8 DIO_getPinValue_u8(u8 COPY_u8_PRV_MCAL_DIO_PORT, u8 COPY_u8_PRV_MCAL_DIO_PIN, u8 *COPY_u8_PRV_MCAL_DIO_PIN_VALUE)
{
	/* Operation statue variable that returns either error or valid operation */
	u8 LOC_u8_PBC_MCAL_DIO_OpStatus = VALID;

	/* Checking if all arguments inputs are within the valid inputs */
	if (((COPY_u8_PRV_MCAL_DIO_PORT >= PORTA_u8) &&
	    (COPY_u8_PRV_MCAL_DIO_PORT <= PORTD_u8)) &&
		((COPY_u8_PRV_MCAL_DIO_PIN >= PIN0_u8) &&
		(COPY_u8_PRV_MCAL_DIO_PIN <= PIN7_u8)))
	{
		/* ANDing the PIN register value with pin so if it 1 the PIN VALUE is high otherwise is low */
		if ((*GLB_PRV_MCAL_DIO_PINS_ARR[COPY_u8_PRV_MCAL_DIO_PORT]) & COPY_u8_PRV_MCAL_DIO_PIN)
		{
			*COPY_u8_PRV_MCAL_DIO_PIN_VALUE = 1;
		}
		else
		{
			*COPY_u8_PRV_MCAL_DIO_PIN_VALUE = 0;
		}
	}
	else
	{
		LOC_u8_PBC_MCAL_DIO_OpStatus = ERROR;
	}
	return LOC_u8_PBC_MCAL_DIO_OpStatus;
}

void DIO_disablePullUps_void()
{
	u8_PRV_MCAL_DIO_SFIOR |= SFIOR_PUD;
}

void DIO_enablePullUps_void()
{
	u8_PRV_MCAL_DIO_SFIOR &= ~SFIOR_PUD;
}
