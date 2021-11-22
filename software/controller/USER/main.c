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
	/* ϵͳ��ʼ�� */
	vSystemInit();
	
	/* ���ݳ�ʼ�� */
	vDataInit();
	
	/* ������ʼ���� */
	vCreateStartTask();
	
	/* ����������� */
    vTaskStartScheduler();          
}

/* ϵͳ��ʼ�� */
void vSystemInit(void)
{
	vLedGpioConfig();

	vDelayMsForInit(100);
}

/* ���ݳ�ʼ�� */
void vDataInit(void)
{
	vDelayMsForInit(100);
}

/* ��ʼ��ר�ô�����ʱ */
void vDelayMsForInit(uint16_t t)
{
	int i;
	
	for(i=0;i<t;i++)
	{
		int a=10300;
		
 		while(a--);
	}
}






