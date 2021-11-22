#include "config.h"

/* define */


/* extern */
extern TaskHandle_t StartTask_Handler;
extern TaskHandle_t Led1Task_Handler;
extern TaskHandle_t Led2Task_Handler;


/* LED1任务实现 */
void Led1Task( void * pvParameters )
{
	static uint8_t Led1TaskCnt = 0;
	static uint8_t Led2DeleteFlag = 0;
		
	while(1)
	{
//		LED1_TOGGLE;

		if( Led1TaskCnt < 16 )
		{
			Led1TaskCnt++;
		}
		
		/* 取反16次后 结束Led2任务 */
		if(( Led1TaskCnt >= 16 )&&( Led2DeleteFlag == 0 ))
		{
			/* 在Led1任务中 结束Led2任务 */
			vTaskDelete( Led2Task_Handler );
			
			/* 记录Led2任务的结束 避免重复结束出错 */
			Led2DeleteFlag = 1;
		}
		vTaskDelay(500);
	}
}

/* LED2任务实现 */
void Led2Task( void * pvParameters )
{
	while(1)
	{
//		LED2_TOGGLE;
		
		vTaskDelay(500);
	}
}


/* END */
