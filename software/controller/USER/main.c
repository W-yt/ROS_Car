/* include */
#include "config.h"
#include "FreeRTOS.h"
#include "task.h"

/* declare */
void vSystemInit(void);
void vDataInit(void);
void vDelayMsForInit(uint16_t t);

int main(void)
{
	/* 系统初始化 */
	vSystemInit();
	
	/* 数据初始化 */
	vDataInit();
	
	/* 创建开始任务 */
	vCreateStartTask();
	
	/* 开启任务调度 */
    vTaskStartScheduler();          
}

/* 系统初始化 */
void vSystemInit(void)
{
	vLedGpioConfig();

	vDelayMsForInit(100);
}

/* 数据初始化 */
void vDataInit(void)
{
	vDelayMsForInit(100);
}

/* 初始化专用粗略延时 */
void vDelayMsForInit(uint16_t t)
{
	int i;
	
	for(i=0;i<t;i++)
	{
		int a=10300;
		
 		while(a--);
	}
}






