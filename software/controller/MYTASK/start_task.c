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


/* ��ʼ����ʵ�� 
 * ��ʼ��������ʵ��Ҫ���е���Ч���� ��ɾ������ */
void StartTask( void * pvParameters )
{
	/* ����LED1���� */
	xTaskCreate(( TaskFunction_t	)Led1Task,      	
				( const char *		)"LED1 Strike",     
				( uint16_t			)LED1_TASK_SIZE,    
				( void *			)NULL,              
				( UBaseType_t		)LED1_TASK_PRIO,    
				( TaskHandle_t *	)&Led1Task_Handler);

	/* ����LED2���� */
	xTaskCreate(( TaskFunction_t	)Led2Task,      	
				( const char *		)"LED2 Strike",     
				( uint16_t			)LED2_TASK_SIZE,    
				( void *			)NULL,              
				( UBaseType_t		)LED2_TASK_PRIO,    
				( TaskHandle_t *	)&Led2Task_Handler);

	/* ɾ������ */
	vTaskDelete( StartTask_Handler );
}

/* ������ʼ���� */
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


















