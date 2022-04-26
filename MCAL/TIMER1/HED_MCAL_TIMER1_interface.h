#ifndef HED_MCAL_TIMER1_INTERFACE_H_
#define HED_MCAL_TIMER1_INTERFACE_H_

void INIT_TIMER1(void);

void TIMER1_CAPT_callBack(void (*TIMER1_INT6_CAPT_Copy_FUN)(void));
void TIMER1_COMPA_callBack(void (*TIMER1_INT7_COMPA_Copy_FUN)(void));
void TIMER1_COMPB_callBack(void (*TIMER1_INT8_COMPB_Copy_FUN)(void));
void TIMER1_OVF_callBack(void (*TIMER1_INT9_OVF_Copy_FUN)(void));

void TIMER1_setOCR(u16 Copy_OCR_VALUE);
void TIMER1_setICR(u16 Copy_ICR_VALUE);

void __vector_6 (void) __attribute__((signal));
void __vector_7 (void) __attribute__((signal));
void __vector_8 (void) __attribute__((signal));
void __vector_9 (void) __attribute__((signal));

#endif