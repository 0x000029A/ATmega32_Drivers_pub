#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../LIB/LIB_VRT_BIT_MATH.h"
#include "HED_MCAL_ADC_interface.h"
#include "HED_MCAL_ADC_register.h"
#include "HED_MCAL_ADC_private.h"
#include "HED_MCAL_ADC_config.h"

static void (*PTR_ADC_NOTIFI_FUN)(void) = NULL;
static u16 *ADC_READING_PTR = NULL;
static u8 BusyState = IDLE_FUN;


void INIT_ADC() {
    /* setting volrage ref */
    u8_PRV_MCAL_ADC_ADMUX &= ~(ADMUX_REFS1 | ADMUX_REFS0);
    u8_PRV_MCAL_ADC_ADMUX |= ADMUX_REFS_MASK;

    /* Setting reslution */
    u8_PRV_MCAL_ADC_ADMUX &= ~ADMUX_ADLAR;
    u8_PRV_MCAL_ADC_ADMUX |= ADMUX_ADLAR_MASK;

    /* init mux */
    u8_PRV_MCAL_ADC_ADMUX &= ~(ADMUX_MUX0 | ADMUX_MUX1 | ADMUX_MUX2 | ADMUX_MUX3);

    /* setting precaller */
    u8_PRV_MCAL_ADC_ADCSRA &= ~(ADCSRA_ADPS0 | ADCSRA_ADPS1 | ADCSRA_ADPS2);
    u8_PRV_MCAL_ADC_ADCSRA |= ADCSRA_PRESCALER_MASK;
    
    /* setting auto trigger */
    u8_PRV_MCAL_ADC_ADCSRA &= ~ADCSRA_ADATE;
    u8_PRV_MCAL_ADC_ADCSRA |= ADCSRA_ADATE_MASK;
    #if (ADCSRA_ADATE_MASK == ADATE_ENABLED)
        u8_PRV_MCAL_ADC_ADCSRA |= ADCSRA_ADIE;
        u8_PRV_MCAL_ADC_SFIOR |= TRIGGER_SRC_MASK;
        u8_PRV_MCAL_ADC_ADCSRA |= ADCSRA_ADSC;
    #endif
        /* Enabling ADC */
    u8_PRV_MCAL_ADC_ADCSRA |= ADCSRA_ADEN;
}

u8 READ_ADC_SYNCH(u8 COPY_CHANNEL, u16 *COPY_DIGITAL_VAL) {
    u8 LOC_ERROR_STATE = VALID;
    u16 LOC_DIGIT_READ = 0;
    u32 LOC_u32_counter = 0;

    if(BusyState == IDLE_FUN) {
        BusyState = BUSY_FUN;
        u8_PRV_MCAL_ADC_ADMUX &= ~(ADMUX_MUX0 | ADMUX_MUX1 | ADMUX_MUX2 | ADMUX_MUX3);
        u8_PRV_MCAL_ADC_ADMUX |= COPY_CHANNEL;

        u8_PRV_MCAL_ADC_ADCSRA |= ADCSRA_ADSC;

        while((!GET_BIT(u8_PRV_MCAL_ADC_ADCSRA, 4)) && (LOC_u32_counter != COUNTER_TIMER_SYNCH)) {
            LOC_u32_counter++;
        }
        if (LOC_u32_counter == COUNTER_TIMER_SYNCH) {
            LOC_ERROR_STATE = ERROR;
        }
        else {
            u8_PRV_MCAL_ADC_ADCSRA |= ADCSRA_ADIF;

            #if (ADMUX_ADLAR_MASK == RES_8BIT)
                LOC_DIGIT_READ = u8_PRV_MCAL_ADC_ADCH;

            #elif (ADMUX_ADLAR_MASK == RES_10BIT)
                LOC_DIGIT_READ = (u8_PRV_MCAL_ADC_ADCL) | u8_PRV_MCAL_ADC_ADCH << 8;

            #endif

            *COPY_DIGITAL_VAL = LOC_DIGIT_READ;
            BusyState = IDLE_FUN;
        }
    } else {
        LOC_ERROR_STATE = BUSY_FUN;
    }
    return LOC_ERROR_STATE;
}


u8 READ_ADC_ASYNCH(u8 COPY_CHANNEL, u16 *COPY_DIGITAL_VAL, void(*COPY_notifiFun)(void)) {
    u8 LOC_ERROR_STATE = VALID;
    if (BusyState == IDLE_FUN) {
        if (COPY_DIGITAL_VAL == NULL || COPY_notifiFun == NULL) {
            LOC_ERROR_STATE = ERROR;
        } else {
            BusyState = BUSY_FUN;
            u8_PRV_MCAL_ADC_ADMUX &= ~(ADMUX_MUX0 | ADMUX_MUX1 | ADMUX_MUX2 | ADMUX_MUX3);
            u8_PRV_MCAL_ADC_ADMUX |= COPY_CHANNEL;

            u8_PRV_MCAL_ADC_ADCSRA |= ADCSRA_ADSC;

            u8_PRV_MCAL_ADC_ADCSRA |= ADCSRA_ADIE;

            PTR_ADC_NOTIFI_FUN = COPY_notifiFun;
            ADC_READING_PTR = COPY_DIGITAL_VAL;
        }
    } else {
        LOC_ERROR_STATE = BUSY_FUN;
    }

    return LOC_ERROR_STATE;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void) {
    #if (ADMUX_ADLAR_MASK == RES_8BIT)
        *ADC_READING_PTR = u8_PRV_MCAL_ADC_ADCH;

    #elif (ADMUX_ADLAR_MASK == RES_10BIT)
        ADC_READING_PTR = (u8_PRV_MCAL_ADC_ADCL) | u8_PRV_MCAL_ADC_ADCH << 8;

    #endif

    BusyState = IDLE_FUN;

    PTR_ADC_NOTIFI_FUN();

    u8_PRV_MCAL_ADC_ADCSRA &= ~ADCSRA_ADIE;
}
