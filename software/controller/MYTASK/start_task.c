/* include */
#include "config.h"
#include "start_task.h"
#include "led_task.h"

/* define */
#define START_TASK_PRIO		1
#define START_TASK_SIZE		128

TaskHandle_t StartTask_Handler;

#define LED1_TASK_PRIO		1
#define LED1_TASK_SIZE		128

TaskHandle_t Led1Task_Handler;

#define LED2_TASK_PRIO		1
#define LED2_TASK_SIZE		128

TaskHandle_t Led2Task_Handler;


/* 起始任务实现 
 * 起始任务即启动实际要运行的有效任务 后删除自身 */
void StartTask( void * pvParameters )
{
	/* 创建LED1任务 */
	xTaskCreate(( TaskFunction_t	)Led1Task,      	
				( const char *		)"LED1 Strike",     
				( uint16_t			)LED1_TASK_SIZE,    
				( void *			)NULL,              
				( UBaseType_t		)LED1_TASK_PRIO,    
				( TaskHandle_t *	)&Led1Task_Handler);

	/* 创建LED2任务 */
	xTaskCreate(( TaskFunction_t	)Led2Task,      	
				( const char *		)"LED2 Strike",     
				( uint16_t			)LED2_TASK_SIZE,    
				( void *			)NULL,              
				( UBaseType_t		)LED2_TASK_PRIO,    
				( TaskHandle_t *	)&Led2Task_Handler);

	/* 删除自身 */
	vTaskDelete( StartTask_Handler );
}

/* 创建起始任务 */
void vCreateStartTask( void )
{
	xTaskCreate(( TaskFunction_t	)StartTask,      	
				( const char *		)"SystemStart",     
				( uint16_t			)START_TASK_SIZE,    
				( void *			)NULL,              
				( UBaseType_t		)START_TASK_PRIO,    
				( TaskHandle_t *	)&StartTask_Handler);
}


/* END */


















