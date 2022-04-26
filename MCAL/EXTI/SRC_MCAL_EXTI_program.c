/*********************************************************
 0   File Name: HED_MCAL_EXTI_program.c                  0
 x   File Type: Source                                   x
 2       Layer: Microcontroller Abstraction Layer (MCAL) 2
 9      Module: External Interrupt (EXTI)                9
 A  Created on: 21/09/12                                 A
 *      Author: Mahmoud Hashem                           *
 * Description: Functions to manipulate registers        *
 *     Version: v1.0                                     *
 *********************************************************/

#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "HED_MCAL_EXTI_interface.h"
#include "HED_MCAL_EXTI_register.h"
#include "HED_MCAL_EXTI_private.h"
#include "HED_MCAL_EXTI_config.h"

/* Initializing pointer to function for call backs */
void (*PTR_INT0_FUN)(void) = NULL_PTR;
void (*PTR_INT1_FUN)(void) = NULL_PTR;
void (*PTR_INT2_FUN)(void) = NULL_PTR;

u8 EXTI_INIT_INT0_u8(u8 COPY_u8_PRV_MCAL_EXTI_SENSE, u8 COPY_u8_PRV_MCAL_EXTI_STATE)
{
    /* Operation statue variable that returns either error or valid operation */
    u8 LOC_u8_PRV_MCAL_EXTI_OpStatus = VALID;

    /* Checking if all arguments inputs are within the valid inputs */
    if(((COPY_u8_PRV_MCAL_EXTI_SENSE >= SC_LOW_LEVEL) && (COPY_u8_PRV_MCAL_EXTI_SENSE <= SC_RISING_EDGE)) &&
       ((COPY_u8_PRV_MCAL_EXTI_STATE == INT_ENABLED) || (COPY_u8_PRV_MCAL_EXTI_STATE == INT_DISABLED)))
    {
        /* Setting sense control */
        u8_PRV_MCAL_EXTI_MCUCR &= ~(MCUCR_ISC00 | MCUCR_ISC01);
        u8_PRV_MCAL_EXTI_MCUCR |= (COPY_u8_PRV_MCAL_EXTI_SENSE & (MCUCR_ISC00 | MCUCR_ISC01));

        /* Enabling or Disabling the interrupt request */
        u8_PRV_MCAL_EXTI_GICR &= ~GICR_INT0;
        u8_PRV_MCAL_EXTI_GICR |= (GICR_INT0 & COPY_u8_PRV_MCAL_EXTI_STATE);
    }
    else
    {
        LOC_u8_PRV_MCAL_EXTI_OpStatus = ERROR;
    }
    return LOC_u8_PRV_MCAL_EXTI_OpStatus;
}

u8 EXTI_INIT_INT1_u8(u8 COPY_u8_PRV_MCAL_EXTI_SENSE, u8 COPY_u8_PRV_MCAL_EXTI_STATE)
{
    /* Operation statue variable that returns either error or valid operation */
    u8 LOC_u8_PRV_MCAL_EXTI_OpStatus = VALID;

    /* Checking if all arguments inputs are within the valid inputs */
    if(((COPY_u8_PRV_MCAL_EXTI_SENSE >= SC_LOW_LEVEL) && (COPY_u8_PRV_MCAL_EXTI_SENSE <= SC_RISING_EDGE)) &&
       ((COPY_u8_PRV_MCAL_EXTI_STATE == INT_ENABLED) || (COPY_u8_PRV_MCAL_EXTI_STATE == INT_DISABLED)))
    {
        /* Setting sense control */
        u8_PRV_MCAL_EXTI_MCUCR &= ~(MCUCR_ISC10 | MCUCR_ISC11);
        u8_PRV_MCAL_EXTI_MCUCR |= (COPY_u8_PRV_MCAL_EXTI_SENSE & (MCUCR_ISC10 | MCUCR_ISC11));

        /* Enabling or Disabling the interrupt request */
        u8_PRV_MCAL_EXTI_GICR &= ~GICR_INT1;
        u8_PRV_MCAL_EXTI_GICR |= (GICR_INT1 & COPY_u8_PRV_MCAL_EXTI_STATE);
    }
    else
    {
        LOC_u8_PRV_MCAL_EXTI_OpStatus = ERROR;
    }
    return LOC_u8_PRV_MCAL_EXTI_OpStatus;
}

u8 EXTI_INIT_INT2_u8(u8 COPY_u8_PRV_MCAL_EXTI_SENSE, u8 COPY_u8_PRV_MCAL_EXTI_STATE)
{
    /* Operation statue variable that returns either error or valid operation */
    u8 LOC_u8_PRV_MCAL_EXTI_OpStatus = VALID;

    /* Checking if all arguments inputs are within the valid inputs */
    if(((COPY_u8_PRV_MCAL_EXTI_SENSE == SC2_FALLING_EDGE) || (COPY_u8_PRV_MCAL_EXTI_SENSE == SC2_FALLING_EDGE)) &&
       ((COPY_u8_PRV_MCAL_EXTI_STATE == INT_ENABLED) || (COPY_u8_PRV_MCAL_EXTI_STATE == INT_DISABLED)))
    {
        /* Setting sense control */
        u8_PRV_MCAL_EXTI_MCUCR &= ~MCUCSR_ISC2;
        u8_PRV_MCAL_EXTI_MCUCR |= (COPY_u8_PRV_MCAL_EXTI_SENSE & MCUCSR_ISC2);

        /* Enabling or Disabling the interrupt request */
        u8_PRV_MCAL_EXTI_GICR &= ~GICR_INT2;
        u8_PRV_MCAL_EXTI_GICR |= (GICR_INT2 & COPY_u8_PRV_MCAL_EXTI_STATE);
    }
    else
    {
        LOC_u8_PRV_MCAL_EXTI_OpStatus = ERROR;
    }
    return LOC_u8_PRV_MCAL_EXTI_OpStatus;
}

u8 EXTI_CALL_BACK_INT0_u8(void (*COPY_u8_PRV_MCAL_EXTI_INT0)(void))
{
    /* Operation statue variable that returns either error or valid operation */
    u8 LOC_u8_PRV_MCAL_EXTI_OpStatus = VALID;

    if(COPY_u8_PRV_MCAL_EXTI_INT0 == NULL_PTR)
    {
        LOC_u8_PRV_MCAL_EXTI_OpStatus = ERROR;
    }
    else
    {
        PTR_INT0_FUN = COPY_u8_PRV_MCAL_EXTI_INT0;
    }
    return LOC_u8_PRV_MCAL_EXTI_OpStatus;
}

u8 EXTI_CALL_BACK_INT1_u8(void (*COPY_u8_PRV_MCAL_EXTI_INT1)(void))
{
    /* Operation statue variable that returns either error or valid operation */
    u8 LOC_u8_PRV_MCAL_EXTI_OpStatus = VALID;

    if(COPY_u8_PRV_MCAL_EXTI_INT1 == NULL_PTR)
    {
        LOC_u8_PRV_MCAL_EXTI_OpStatus = ERROR;
    }
    else
    {
        PTR_INT1_FUN = COPY_u8_PRV_MCAL_EXTI_INT1;
    }
    return LOC_u8_PRV_MCAL_EXTI_OpStatus;
}

u8 EXTI_CALL_BACK_INT2_u8(void (*COPY_u8_PRV_MCAL_EXTI_INT2)(void))
{
    /* Operation statue variable that returns either error or valid operation */
    u8 LOC_u8_PRV_MCAL_EXTI_OpStatus = VALID;

    if(COPY_u8_PRV_MCAL_EXTI_INT2 == NULL_PTR)
    {
        LOC_u8_PRV_MCAL_EXTI_OpStatus = ERROR;
    }
    else
    {
        PTR_INT2_FUN = COPY_u8_PRV_MCAL_EXTI_INT2;
    }
    return LOC_u8_PRV_MCAL_EXTI_OpStatus;
}

/***** MCU defined vectors to call required function when interrupt happen *****/

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
    PTR_INT0_FUN();
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
    PTR_INT1_FUN();
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
    PTR_INT2_FUN();
}