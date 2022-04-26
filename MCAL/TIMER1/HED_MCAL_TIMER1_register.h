#ifndef HED_MCAL_TIMER1_REGISTER_H_
#define HED_MCAL_TIMER1_REGISTER_H_

/*************************
 * 16-bit Timer/Counter1 *
 *************************/

#define u8_PRV_MCAL_TIMER_TCCR1A    *((volatile u8*)0x4F)
#define TCCR1A_COM1A1               (0b10000000)
#define TCCR1A_COM1A0               (0b01000000)
#define TCCR1A_COM1B1               (0b00100000)
#define TCCR1A_COM1B0               (0b00010000)
#define TCCR1A_FOC1A                (0b00001000)
#define TCCR1A_FOC1B                (0b00000100)
#define TCCR1A_WGM11                (0b00000010)
#define TCCR1A_WGM10                (0b00000001)

#define u8_PRV_MCAL_TIMER_TCCR1B    *((volatile u8*)0x4E)
#define TCCR1B_ICNC1                (0b10000000)
#define TCCR1B_ICES1                (0b01000000)
#define TCCR1B_RES                  (0b00100000)
#define TCCR1B_WGM13                (0b00010000)
#define TCCR1B_WGM12                (0b00001000)
#define TCCR1B_CS12                 (0b00000100)
#define TCCR1B_CS11                 (0b00000010)
#define TCCR1B_CS10                 (0b00000001)

#define u16_PRV_MCAL_TIMER_TCNT1    *((volatile u16*)0x4C)
/*#define u8_PRV_MCAL_TIMER_TCNT1H    *((volatile u8*)0x4D)
#define u8_PRV_MCAL_TIMER_TCNT1L    *((volatile u8*)0x4C)*/

#define u16_PRV_MCAL_TIMER_OCR1A    *((volatile u16*)0x4A)
/*#define u8_PRV_MCAL_TIMER_OCR1AH    *((volatile u8*)0x4B)
#define u8_PRV_MCAL_TIMER_OCR1AL    *((volatile u8*)0x4A)*/

#define u16_PRV_MCAL_TIMER_OCR1B    *((volatile u16*)0x48)
/*#define u8_PRV_MCAL_TIMER_OCR1BH    *((volatile u8*)0x49)
#define u8_PRV_MCAL_TIMER_OCR1BL    *((volatile u8*)0x48)*/

#define u16_PRV_MCAL_TIMER_ICR1     *((volatile u16*)0x46)
/*#define u8_PRV_MCAL_TIMER_ICR1H     *((volatile u8*)0x47)
#define u8_PRV_MCAL_TIMER_ICR1L     *((volatile u8*)0x46)*/

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