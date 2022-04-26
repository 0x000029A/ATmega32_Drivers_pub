#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../LIB/LIB_VRT_BIT_MATH.h"
#include "HED_MCAL_TIMER0_interface.h"
#include "HED_MCAL_TIMER0_register.h"
#include "HED_MCAL_TIMER0_private.h"
#include "HED_MCAL_TIMER0_config.h"

static void (*TIMER0_PTR_FUN)(void) = NULL;

void INIT_TIMER0(void) {
    u8_PRV_MCAL_TIMER_TCCR0 &= ~(TCCR0_WGM00 | TCCR0_WGM01);
    u8_PRV_MCAL_TIMER_TCCR0 |= WG_MODE;

    u8_PRV_MCAL_TIMER_TCCR0 &= ~(TCCR0_COM00 | TCCR0_COM01);
    u8_PRV_MCAL_TIMER_TCCR0 |= COM_MODE;

    #if (WG_MODE == FPWM || WG_MODE == PC_PWM)
        u8_PRV_MCAL_TIMER_TIMSK &= ~TIMSK_OCIE0;

    #else
        u8_PRV_MCAL_TIMER_TIMSK |= TIMSK_OCIE0;
        
    #endif

    //u8_PRV_MCAL_TIMER_OCR0 = OCR_PRELAOD;

    u8_PRV_MCAL_TIMER_TCCR0 &= ~(TCCR0_CS00 | TCCR0_CS01 | TCCR0_CS02);
    u8_PRV_MCAL_TIMER_TCCR0 |= CLK_SLCT;
}
void TIMER0_OCR_PREVAL(u8 COPY_OCR) {
    u8_PRV_MCAL_TIMER_OCR0 = COPY_OCR;
}

void TIMER0_callBack(void (*TIMER_INT_Copy_FUN)(void)) {
    TIMER0_PTR_FUN = TIMER_INT_Copy_FUN;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
    TIMER0_PTR_FUN();
}