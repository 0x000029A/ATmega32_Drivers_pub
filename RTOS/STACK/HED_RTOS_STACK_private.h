#ifndef HED_RTOS_STACK_PRIVATE_H_
#define HED_RTOS_STACK_PRIVATE_H_

typedef struct
{
	u8 activated;
    u16 periodicity;
    u16 firstDelay;
    void (*taskFun)(void);
} TASK;

static void SCHEDULER_void(void);

#endif
