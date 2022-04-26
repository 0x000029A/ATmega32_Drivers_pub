#ifndef HED_MCAL_TIMER0_CONFIG_H_
#define HED_MCAL_TIMER0_CONFIG_H_

#define FORCE_COM   FC_DISABLED

#define OCR_PRELAOD 125

/* Timer/Counter Mode of Operation
 * NRM              Normal
 * PC_PWM           Phase Correct PWM
 * CTC              CTC
 * FPWM             Fast PWM
 */
#define WG_MODE     CTC

/* Compare Match Output Mode (non-PWM Mode)
 * OC0_DIS          Normal port operation, OC0 disconnected
 * OC0_TGL          Toggle OC0 on compare match
 * OC0_CLR          Clear OC0 on compare match
 * OC0_SET          Set OC0 on compare match
 * ***************************************
 * Compare Match Output Mode (Fast PWM)
 * OC0_DIS          Normal port operation, OC0 disconnected
 * OC0_TGL          Reserved
 * OC0_CLR          Clear OC0 on compare match, set OC0 at BOTTOM, (nin-inverting mode)
 * OC0_SET          Set OC0 on compare match, clear OC0 at BOTTOM, (inverting mode)
 * ********************************
 * Compare Match Output Mode (Phase Correct PWM)
 * OC0_DIS          Normal port operation, OC0 disconnected
 * OC0_TGL          Reserved
 * OC0_CLR          Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
 * OC0_SET          Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.
 */
#define COM_MODE    OC0_CLR

/* Timer/Counter Mode of Operation
 * NO_CLK           No clock source (Timer/Counter stopped).
 * NO_PRS           clk same as source (No prescaling)
 * DIV_BY_8         clk/8 (From prescaler)
 * DIV_BY_64        clk/64 (From prescaler)
 * DIV_BY_256       clk/256 (From prescaler)
 * DIV_BY_1024      clk/1024 (From prescaler)
 * T0_CLK_ON_FALL   External clock source on T0 pin. Clock on falling edge.
 * T0_CLCK_ON_RISE  External clock source on T0 pin. Clock on rising edge.
 */
#define CLK_SLCT    DIV_BY_64

#endif