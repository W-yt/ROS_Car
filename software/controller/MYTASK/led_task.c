#include "config.h"

/* define */


/* extern */
extern TaskHandle_t StartTask_Handler;
extern TaskHandle_t Led1Task_Handler;
extern TaskHandle_t Led2Task_Handler;


/* LED1����ʵ�� */
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
		
		/* ȡ��16�κ� ����Led2���� */
		if(( Led1TaskCnt >= 16 )&&( Led2DeleteFlag == 0 ))
		{
			/* ��Led1������ ����Led2���� */
			vTaskDelete( Led2Task_Handler );
			
			/* ��¼Led2����Ľ��� �����ظ��������� */
			Led2DeleteFlag = 1;
		}
		vTaskDelay(500);
	}
}

/* LED2����ʵ�� */
void Led2Task( void * pvParameters )
{
	while(1)
	{
//		LED2_TOGGLE;
		
		vTaskDelay(500);
	}
}


/* END */
