#ifndef HED_MCAL_ADC_REGISTER_H_
#define HED_MCAL_ADC_REGISTER_H_

#define u8_PRV_MCAL_ADC_ADMUX   *((volatile u8*)0x27)
#define ADMUX_REFS1             (0b10000000)
#define ADMUX_REFS0             (0b01000000)
#define ADMUX_ADLAR             (0b00100000)
#define ADMUX_MUX4              (0b00010000)
#define ADMUX_MUX3              (0b00001000)
#define ADMUX_MUX2              (0b00000100)
#define ADMUX_MUX1              (0b00000010)
#define ADMUX_MUX0              (0b00000001)

#define u8_PRV_MCAL_ADC_ADCSRA  *((volatile u8*)0x26)
#define ADCSRA_ADEN             (0b10000000)
#define ADCSRA_ADSC             (0b01000000)
#define ADCSRA_ADATE            (0b00100000)
#define ADCSRA_ADIF             (0b00010000)
#define ADCSRA_ADIE             (0b00001000)
#define ADCSRA_ADPS2            (0b00000100)
#define ADCSRA_ADPS1            (0b00000010)
#define ADCSRA_ADPS0            (0b00000001)

#define u8_PRV_MCAL_ADC_SFIOR   *((volatile u8*)0x50)
#define SFIOR_ADTS2             (0b10000000)
#define SFIOR_ADTS1             (0b01000000)
#define SFIOR_ADTS0             (0b00100000)

#define u8_PRV_MCAL_ADC_ADCH    *((volatile u8*)0x25)
#define u8_PRV_MCAL_ADC_ADCL    *((volatile u8*)0x24)



#endif