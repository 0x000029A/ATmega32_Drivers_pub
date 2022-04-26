#ifndef HED_MCAL_TIMER1_CONFIG_H_
#define HED_MCAL_TIMER1_CONFIG_H_

#define FORCE_COMA   FC1A_DISABLED
#define FORCE_COMB   FC1B_DISABLED

#define OCR1A_PRELAOD 250
#define OCR1B_PRELAOD 250

/*--------------+---------------------------------------+-----------+-------------------+-----------------------+
 | Mode         |   Timer/Counter Mode of Operation     |   TOP     |   Update of OCR1x |   TOV1 Flag Set on    |
 | -------------+---------------------------------------+-----------+-------------------+-----------------------+
 | MODE0A/B     |   Normal                              |   0xFFFF  |   Immediate       |   MAX                 |
 | MODE1A/B     |   PWM, Phase Correct, 8-bit           |   0x00FF  |   TOP             |   BOTTOM              |
 | MODE2A/B     |   PWM, Phase Correct, 9-bit           |   0x01FF  |   TOP             |   BOTTOM              |
 | MODE3A/B     |   PWM, Phase Correct, 10-bit          |   0x03FF  |   TOP             |   BOTTOM              |
 | MODE4A/B     |   CTC                                 |   OCR1A   |   Immediate       |   MAX                 |
 | MODE5A/B     |   Fast PWM, 8-bit                     |   0x00FF  |   BOTTOM          |   TOP                 |
 | MODE6A/B     |   Fast PWM, 9-bit                     |   0x01FF  |   BOTTOM          |   TOP                 |
 | MODE7A/B     |   Fast PWM, 10-bit                    |   0x03FF  |   BOTTOM          |   TOP                 |
 | MODE8A/B     |   PWM, Phase and Frequency Correct    |   ICR1    |   BOTTOM          |   BOTTOM              |
 | MODE9A/B     |   PWM, Phase and Frequency Correct    |   OCR1A   |   BOTTOM          |   BOTTOM              |
 | MODE10A/B    |   PWM, Phase Correct                  |   ICR1    |   TOP             |   BOTTOM              |
 | MODE11A/B    |   PWM, Phase Correct                  |   OCR1A   |   TOP             |   BOTTOM              |
 | MODE12A/B    |   CTC                                 |   ICR1    |   Immediate       |   MAX                 |
 | MODE13A/B    |   Reserved                            |   -       |   -               |   -                   |
 | MODE14A/B    |   Fast PWM                            |   ICR1    |   BOTTOM          |   TOP                 |
 | MODE15A/B    |   Fast PWM                            |   OCR1A   |   BOTTOM          |   TOP                 |
 +--------------+---------------------------------------+-----------+-------------------+-----------------------*/
#define WGA_MODE     MODE14A
#define WGB_MODE     MODE14B

/* Compare Match Output Mode (non-PWM Mode)
 * OC1A/OC1B_DIS    Normal port operation, OC1A/OC1B disconnected.
 * OC1A/OC1B_TGL    Toggle OC1A/OC1B on compare match
 * OC1A/OC1B_CLR    Clear OC1A/OC1B on compare match (Set output to low level)
 * OC1A/OC1B_SET    Set OC1A/OC1B on compare match (Set output to high level)
 * ************************************
 * Compare Match Output Mode (Fast PWM)
 * OC1A/OC1B_DIS    Normal port operation, OC1A/OC1B disconnected.
 * OC1A/OC1B_TGL    WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
                    For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.
 * OC1A/OC1B_CLR    Clear OC1A/OC1B on compare match, set OC1A/OC1B at BOTTOM, (non-inverting mode)
 * OC1A/OC1B_SET    Set OC1A/OC1B on compare match, clear OC1A/OC1B at BOTTOM, (inverting mode)
 * **********************************************************************
 * Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 * OC1A/OC1B_DIS    Normal port operation, OC1A/OC1B disconnected.
 * OC1A/OC1B_TGL    WGM13:0 = 9 or 14: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
                    For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.
 * OC1A/OC1B_CLR    Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare match when downcounting.
 * OC1A/OC1B_SET    Set OC1A/OC1B on compare match when upcounting. Clear OC1A/OC1B on compare match when downcounting.
 * **************************
 * eg., OC1A_CLR, or OC1B_TGL
 */
#define COM1A_MODE    OC1A_CLR
#define COM1B_MODE    OC1B_DIS

/* Timer/Counter Mode of Operation
 * NO_CLK           No clock source (Timer/Counter stopped).
 * DIV_BY_1         clk same as source (No prescaling)
 * DIV_BY_8         clk/8 (From prescaler)
 * DIV_BY_64        clk/64 (From prescaler)
 * DIV_BY_256       clk/256 (From prescaler)
 * DIV_BY_1024      clk/1024 (From prescaler)
 * T0_CLK_ON_FALL   External clock source on T1 pin. Clock on falling edge.
 * T0_CLCK_ON_RISE  External clock source on T1 pin. Clock on rising edge.
 */
#define CLK_SLCT    DIV_BY_8

#endif