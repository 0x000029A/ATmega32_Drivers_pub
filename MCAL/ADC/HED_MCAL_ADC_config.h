#ifndef HED_MCAL_ADC_CONFIG_H_
#define HED_MCAL_ADC_CONFIG_H_

#define REF_VOLT                5

/*
 * AREF: AREF, Internal Vref turned off
 * AVCC: AVCC with external capacitor at AREF pin
 * IREF: Internal 2.56V Voltage Reference with external capacitor at AREF pin
 */
#define ADMUX_REFS_MASK         AVCC

/*
 * LEFT_ADJUST: Left adjust
 * RIGHT_ADJUST: Right adjust
 */
#define ADMUX_ADLAR_MASK        RES_8BIT

#define ADMUX_MUX_MASK          ADC0_SIGNLE

#define ADCSRA_PRESCALER_MASK   DIV_BY_128

#define ADCSRA_ADATE_MASK       ADATE_DISABLED

#define TRIGGER_SRC_MASK        FREE_RUN

#define COUNTER_TIMER_SYNCH     50000

#endif