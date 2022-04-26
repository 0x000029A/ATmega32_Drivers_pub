#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../LIB/LIB_VRT_BIT_MATH.h"
#include "HED_MCAL_TIMER1_interface.h"
#include "HED_MCAL_TIMER1_register.h"
#include "HED_MCAL_TIMER1_private.h"
#include "HED_MCAL_TIMER1_config.h"

static void (*TIMER1_PTR6_CAPT_FUN)(void) = NULL;
static void (*TIMER1_PTR7_COMPA_FUN)(void) = NULL;
static void (*TIMER1_PTR8_COMPB_FUN)(void) = NULL;
static void (*TIMER1_PTR9_OVF_FUN)(void) = NULL;

void INIT_TIMER1(void) {
    u8_PRV_MCAL_TIMER_TCCR1A &= ~(TCCR1A_COM1A1 | TCCR1A_COM1A0 | TCCR1A_COM1B1 | TCCR1A_COM1B0);
    u8_PRV_MCAL_TIMER_TCCR1A |= COM1A_MODE | COM1B_MODE;

    u8_PRV_MCAL_TIMER_TCCR1A &= ~(TCCR1A_WGM11 | TCCR1A_WGM10);
    u8_PRV_MCAL_TIMER_TCCR1B &= ~(TCCR1B_WGM12 | TCCR1B_WGM13);
    u8_PRV_MCAL_TIMER_TCCR1A |= WGA_MODE;
    u8_PRV_MCAL_TIMER_TCCR1B |= WGB_MODE;

    u8_PRV_MCAL_TIMER_TCCR1B &= ~(TCCR1B_CS10 | TCCR1B_CS11 | TCCR1B_CS12);
    u8_PRV_MCAL_TIMER_TCCR1B |= CLK_SLCT;
}

void TIMER1_setOCR(u16 Copy_OCR_VALUE)
{
    u16_PRV_MCAL_TIMER_OCR1A = Copy_OCR_VALUE;
}

void TIMER1_setICR(u16 Copy_ICR_VALUE)
{
    u16_PRV_MCAL_TIMER_ICR1 = Copy_ICR_VALUE;
}

void TIMER1_CAPT_callBack(void (*TIMER1_INT6_CAPT_Copy_FUN)(void))
{
    TIMER1_PTR6_CAPT_FUN = TIMER1_INT6_CAPT_Copy_FUN;
}

void TIMER1_COMPA_callBack(void (*TIMER1_INT7_COMPA_Copy_FUN)(void))
{
    TIMER1_PTR7_COMPA_FUN = TIMER1_INT7_COMPA_Copy_FUN;
}

void TIMER1_COMPB_callBack(void (*TIMER1_INT8_COMPB_Copy_FUN)(void))
{
    TIMER1_PTR8_COMPB_FUN = TIMER1_INT8_COMPB_Copy_FUN;
}

void TIMER1_OVF_callBack(void (*TIMER1_INT9_OVF_Copy_FUN)(void))
{
    TIMER1_PTR9_OVF_FUN = TIMER1_INT9_OVF_Copy_FUN;
}

void __vector_6 (void)
{
    TIMER1_PTR7_COMPA_FUN();
}

void __vector_7 (void)
{
    TIMER1_PTR7_COMPA_FUN();
}

void __vector_8 (void)
{
    TIMER1_PTR8_COMPB_FUN();
}

void __vector_9 (void)
{
    TIMER1_PTR9_OVF_FUN();
}