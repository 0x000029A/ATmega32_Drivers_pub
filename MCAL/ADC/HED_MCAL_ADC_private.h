#ifndef HED_MCAL_ADC_PRIVATE_H_
#define HED_MCAL_ADC_PRIVATE_H_

#define AREF                (0b00000000)
#define AVCC                (0b01000000)
#define IREF                (0b11000000)

#define RES_8BIT            (0b00100000)
#define RES_10BIT           (0b00000000)

#define ADC0_SIGNLE         (0b00000000)
#define ADC1_SIGNLE         (0b00000001)
#define ADC2_SIGNLE         (0b00000010)
#define ADC3_SIGNLE         (0b00000011)
#define ADC4_SIGNLE         (0b00000100)
#define ADC5_SIGNLE         (0b00000101)
#define ADC6_SIGNLE         (0b00000110)
#define ADC7_SIGNLE         (0b00000111)

#define P_ADC0_N_ADC0_10x   (0b00001000)
#define P_ADC1_N_ADC0_10x   (0b00001001)
#define P_ADC0_N_ADC0_200x  (0b00001010)
#define P_ADC1_N_ADC0_200x  (0b00001011)
#define P_ADC2_N_ADC2_10x   (0b00001100)
#define P_ADC3_N_ADC2_10x   (0b00001101)
#define P_ADC2_N_ADC2_200x  (0b00001110)
#define P_ADC3_N_ADC2_200x  (0b00001111)
#define P_ADC0_N_ADC1_1x    (0b00010000)
#define P_ADC1_N_ADC1_1x    (0b00010001)
#define P_ADC2_N_ADC1_1x    (0b00010010)
#define P_ADC3_N_ADC1_1x    (0b00010011)
#define P_ADC4_N_ADC1_1x    (0b00010100)
#define P_ADC5_N_ADC1_1x    (0b00010101)
#define P_ADC6_N_ADC1_1x    (0b00010110)
#define P_ADC7_N_ADC1_1x    (0b00010111)
#define P_ADC0_N_ADC2_1x    (0b00011000)
#define P_ADC1_N_ADC2_1x    (0b00011001)
#define P_ADC2_N_ADC2_1x    (0b00011010)
#define P_ADC3_N_ADC2_1x    (0b00011011)
#define P_ADC4_N_ADC2_1x    (0b00011100)
#define P_ADC5_N_ADC2_1x    (0b00011101)
#define VBG_1_22            (0b00011110)
#define GND_0V              (0b00011111)

#define DIV_BY_2            (0b00000000)
#define DIV_BY_4            (0b00000010)
#define DIV_BY_8            (0b00000011)
#define DIV_BY_16           (0b00000100)
#define DIV_BY_32           (0b00000101)
#define DIV_BY_64           (0b00000110)
#define DIV_BY_128          (0b00000111)

#define ADATE_ENABLED       (ADCSRA_ADATE)
#define ADATE_DISABLED      (0b00000000)

#define FREE_RUN            (0b00000000)
#define ANALOG_COMP         (0b00100000)
#define EXTI_REQ_0          (0b00000000)
#define TIM_CNT0_CM         (0b00000000)
#define TIM_CNT0_OV         (0b00000000)
#define TIM_CNT1_CM_B       (0b00000000)
#define TIM_CNT1_OV         (0b00000000)
#define TIM_CNT1_CE         (0b00000000)

#define RES_8BIT_256        256
#define RES_10BIT_1024      1024

#endif