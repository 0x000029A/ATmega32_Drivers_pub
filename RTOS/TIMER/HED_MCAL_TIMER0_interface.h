#ifndef HED_MCAL_TIMER0_INTERFACE_H_
#define HED_MCAL_TIMER0_INTERFACE_H_

void INIT_TIMER0(void);
void TIMER_callBack0(void (*TIMER_INT_Copy_FUN)(void));

#endif