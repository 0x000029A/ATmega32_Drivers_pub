#ifndef HED_RTOS_STACK_INTERFACE_H_
#define HED_RTOS_STACK_INTERFACE_H_

void RTOS_start_void(void);
u8 RTOS_createTask_void(u8 COPY_u8_RTOS_STACK_PRIORITY, u16 COPY_u8_RTOS_STACK_PERIODICITY, void (*COPY_u8_RTOS_STACK_TASK_FUN)(void));
void RTOS_suspendTask(u8 id);
void RTOS_resumeTask(u8 id);
void RTOS_deleteTask(u8 id);

#endif
