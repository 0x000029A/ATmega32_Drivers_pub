#ifndef HED_MCAL_TIMER0_PRIVATE_H_
#define HED_MCAL_TIMER0_PRIVATE_H_

#define FC_DISABLED     (0)
#define FC_ENABLED      (TCCR0_FOC0)

#define NORMAL          (0)
#define PC_PWM          (TCCR0_WGM00)
#define CTC             (TCCR0_WGM01)
#define FPWM            (TCCR0_WGM00 | TCCR0_WGM01)

#define OC0_DIS         (0)
#define OC0_TGL         (TCCR0_COM00)
#define OC0_CLR         (TCCR0_COM01)
#define OC0_SET         (TCCR0_COM00 | TCCR0_COM01)

#define NO_CLK          (0)
#define NO_PRS          (TCCR0_CS00)
#define DIV_BY_8        (TCCR0_CS01)
#define DIV_BY_64       (TCCR0_CS00 | TCCR0_CS01)
#define DIV_BY_256      (TCCR0_CS02)
#define DIV_BY_1024     (TCCR0_CS00 | TCCR0_CS02)
#define T0_CLK_ON_FALL  (TCCR0_CS01 | TCCR0_CS02)
#define T0_CLCK_ON_RISE (TCCR0_CS00 | TCCR0_CS01 | TCCR0_CS02)

#endif