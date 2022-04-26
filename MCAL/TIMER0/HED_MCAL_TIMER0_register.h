#ifndef HED_MCAL_TIMER0_REGISTER_H_
#define HED_MCAL_TIMER0_REGISTER_H_

/*********************************
 * 8-bit Timer/Counter0 with PWM *
 *********************************/

#define u8_PRV_MCAL_TIMER_TCCR0     *((volatile u8*)0x53)
#define TCCR0_FOC0                  (0b10000000)
#define TCCR0_WGM00                 (0b01000000)
#define TCCR0_COM01                 (0b00100000)
#define TCCR0_COM00                 (0b00010000)
#define TCCR0_WGM01                 (0b00001000)
#define TCCR0_CS02                  (0b00000100)
#define TCCR0_CS01                  (0b00000010)
#define TCCR0_CS00                  (0b00000001)

#define u8_PRV_MCAL_TIMER_TCNT0     *((volatile u8*)0x52)

#define u8_PRV_MCAL_TIMER_OCR0      *((volatile u8*)0x5C)

/********************
 * Mutual Registers *
 ********************/
#define u8_PRV_MCAL_TIMER_TIMSK     *((volatile u8*)0x59)
#define TIMSK_OCIE2                 (0b10000000)
#define TIMSK_TOIE2                 (0b01000000)
#define TIMSK_TICIE1                (0b00100000)
#define TIMSK_OCIE1A                (0b00010000)
#define TIMSK_OCIE1B                (0b00001000)
#define TIMSK_TOIE1                 (0b00000100)
#define TIMSK_OCIE0                 (0b00000010)
#define TIMSK_TOIE0                 (0b00000001)

#define u8_PRV_MCAL_TIMER_TIFR      *((volatile u8*)0x58)
#define TIFR_OCF2                   (0b10000000)
#define TIFR_TOV2                   (0b01000000)
#define TIFR_ICF1                   (0b00100000)
#define TIFR_OCF1A                  (0b00010000)
#define TIFR_OCF1B                  (0b00001000)
#define TIFR_TOV1                   (0b00000100)
#define TIFR_OCF0                   (0b00000010)
#define TIFR_TOV0                   (0b00000001)

#define u8_PRV_MCAL_TIMER_SFIOR     *((volatile u8*)0x50)
#define SFIOR_PSR2                  (0b00000010)
#define SFIOR_PSR10                 (0b00000001)

#endif