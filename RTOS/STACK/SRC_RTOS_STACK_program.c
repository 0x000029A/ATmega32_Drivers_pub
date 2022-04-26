#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../TIMER/HED_MCAL_TIMER0_interface.h"
#include "../GI/HED_MCAL_GI_interface.h"
#include "HED_RTOS_STACK_register.h"
#include "HED_RTOS_STACK_private.h"
#include "HED_RTOS_STACK_interface.h"
#include "HED_RTOS_STACK_config.h"

TASK systemTasks[TASKS_NUM] = {{NULL_PTR}};

void RTOS_start_void()
{
	TIMER0_callBack0(&SCHEDULER_void);
	GI_ENB();
	INIT_TIMER0();
}

u8 RTOS_createTask_void(u8 COPY_u8_RTOS_STACK_PRIORITY, u16 COPY_u8_RTOS_STACK_PERIODICITY, COPY_u8_RTOS_STACK_FIRST_DELAY, void (*COPY_u8_RTOS_STACK_TASK_FUN)(void))
{
	u8 LOC_u8_PBC_MCAL_DIO_OpStatus = VALID;
	if (systemTasks[COPY_u8_RTOS_STACK_PRIORITY].taskFun == NULL_PTR)
	{
		systemTasks[COPY_u8_RTOS_STACK_PRIORITY].activated = 1;
		systemTasks[COPY_u8_RTOS_STACK_PRIORITY].periodicity = COPY_u8_RTOS_STACK_PERIODICITY;
		systemTasks[COPY_u8_RTOS_STACK_PRIORITY].firstDelay = COPY_u8_RTOS_STACK_FIRST_DELAY;
		systemTasks[COPY_u8_RTOS_STACK_PRIORITY].taskFun = COPY_u8_RTOS_STACK_TASK_FUN;
	}
	else
	{
		LOC_u8_PBC_MCAL_DIO_OpStatus = ERROR;
	}
	return LOC_u8_PBC_MCAL_DIO_OpStatus;
}

static void SCHEDULER_void()
{
	u8 taskCounter;
	for(taskCounter = 0; taskCounter < TASKS_NUM; taskCounter++)
	{
		if(systemTasks[taskCounter].activated == 1)
		{
			if(systemTasks[taskCounter].firstDelay == 0)
			{
				if(systemTasks[taskCounter].taskFun != NULL_PTR)
				{
					systemTasks[taskCounter].taskFun();
					systemTasks[taskCounter].firstDelay = systemTasks[taskCounter].periodicity - 1;
				}
				else
				{
					systemTasks[taskCounter].firstDelay--;
				}
			}
			else
			{

			}
		}
		else
		{

		}
	}
}

void RTOS_deleteTask(u8 id)
{
	systemTasks[id].taskFun = NULL_PTR;
}

void RTOS_suspendTask(u8 id)
{
	systemTasks[id].activated = 0;
}

void RTOS_resumeTask(u8 id)
{
	systemTasks[id].activated = 1;
}
