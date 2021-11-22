/*
    FreeRTOS V9.0.0 - Copyright (C) 2016 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.
*/


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* ���MDK������������ */
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
	#include <stdint.h>
	extern uint32_t SystemCoreClock;
#endif


/* FreeRTOS �������� */

/* 1->RTOSʹ����ռʽ������; 0->RTOSʹ��Э��ʽ��������ʱ��Ƭ��
 * FreeRTOS ���Ѳ��ٸ��¶�Э��ʽ���ȵ�֧�� */
#define configUSE_PREEMPTION							( 1 )

/* 1->ʹ��ʱ��Ƭ����(Ĭ��) */
#define configUSE_TIME_SLICING							( 1 )		

/* ����FreeRTOS��MCU��ѡ����Ӳ�����ַ�ʽ������һ��Ҫִ�е�����
 * 1->Ӳ����ʽ ; 0->�����ʽ
 * �����ʽЧ�ʽϵ� ���ǿ���֧������MCU �����ȼ���Ŀ������
 * Ӳ����ʽЧ�ʸ� ��һ��ǿ���޶����������ȼ���ĿΪ32
 * MCU(��STM32)��Ӳ������ǰ����ָ�� �����ʹ�õ�MCUû����ЩӲ��ָ��Ļ��˺�Ӧ������Ϊ0��*/
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	        ( 1 )                       

/* 1->ʹ�ܵ͹���ticklessģʽ; 0->����ϵͳ���ģ�tick���ж�һֱ����
 * �����͹���ģʽ���ܻᵼ�����س������� ��Ϊ������˯����*/
#define configUSE_TICKLESS_IDLE							( 0 )   

/* д��ʵ�ʵ�CPU�ں�ʱ��Ƶ�� Ҳ����CPUָ��ִ��Ƶ�� (ͨ����ΪFclk) FclkΪ����CPU�ں˵�ʱ���ź� 
 * CPU��ƵΪ XX MHz ����ָ�����ʱ���ź� ��Ӧ��1/Fclk��ΪCPUʱ������*/
#define configCPU_CLOCK_HZ						 ( SystemCoreClock )

/* RTOSϵͳ�����жϵ�Ƶ��(��һ���жϵĴ���) ÿ���ж�RTOS�������������� */
#define configTICK_RATE_HZ					     (( TickType_t )1000)

/* ��ʹ�õ�������ȼ� */
#define configMAX_PRIORITIES					  		( 32 )

/* ��������ʹ�õĶ�ջ��С */
#define configMINIMAL_STACK_SIZE				 ((unsigned short)128)
  
/* ���������ַ�����󳤶� */
#define configMAX_TASK_NAME_LEN							( 16 )

/* ϵͳ���ļ�����������������(��MCUλ����Ӧ)
 * 1->16λ�޷�������; 0->32λ�޷������� */
#define configUSE_16_BIT_TICKS							( 0 )                     

/* �����������CPUʹ��Ȩ������ͬ���ȼ����û�����ʹ�� */
#define configIDLE_SHOULD_YIELD							( 1 )           

/* ���ö��� */
#define configUSE_QUEUE_SETS							( 0 )   

/* ��������֪ͨ����(Ĭ�Ͽ���) */
#define configUSE_TASK_NOTIFICATIONS 				    ( 1 )

/* ʹ�û����ź��� */
#define configUSE_MUTEXES						    	( 0 )    

/* ʹ�õݹ黥���ź��� */ 
#define configUSE_RECURSIVE_MUTEXES						( 0 )   

/* ʹ�ü����ź��� */
#define configUSE_COUNTING_SEMAPHORES					( 0 )

/* ����ע����ź�������Ϣ���и��� */
#define configQUEUE_REGISTRY_SIZE						( 10 )                    

/* 1->��������2������:
 * configUSE_APPLICATION_TASK_FAGF()
 * xTaskCallApplicationTaskHook() */
#define configUSE_APPLICATION_TASK_TAG		  			( 0 )                      


/* FreeRTOS �ڴ������������ */

/* ֧�ֶ�̬�ڴ����� */
#define configSUPPORT_DYNAMIC_ALLOCATION  	      		( 1 )    
/* ֧�־�̬�ڴ� */
#define configSUPPORT_STATIC_ALLOCATION					( 0	)
/* ϵͳ�ѵĴ�С �����ڴ溯�����Ӷ�(����)�������ڴ� */
#define configTOTAL_HEAP_SIZE					 ((size_t)(17*1024))


/* FreeRTOS HOOK����������� */

/* 1->ʹ�ÿ���HOOK��Idle Hook�����ڻص�������; 0->���Կ���HOOK
 * ����HOOK��һ������ ���û���ʵ�� ������:void vApplicationIdleHook( void )
 * ���������ÿ�������������ڶ��ᱻ����
 * �����Ѿ�ɾ����RTOS���� ������������ͷŷ�������ǵĶ�ջ�ڴ� ��˱��뱣֤����������Ա�CPUִ��
 * ʹ�ÿ���HOOK����CPU����ʡ��ģʽ�Ǻܳ�����
 * �����Ե��û������������������API����*/
#define configUSE_IDLE_HOOK								( 0 )      

/* 1->ʹ��ʱ��ƬHOOK��Tick Hook��; 0->����ʱ��ƬHOOK
 * ʱ��ƬHOOK��һ������ ���û���ʵ�� ������:void vApplicationTickHook( void )
 * ʱ��Ƭ�жϿ��������Եĵ���
 * ��������ǳ���С ���ܴ���ʹ�ö�ջ
 * ���ܵ����ԡ�FromISR" �� "FROM_ISR����β��API����
 * xTaskIncrementTick��������xPortSysTickHandler�жϺ����б����õ�
 * ���vApplicationTickHook()����ִ�е�ʱ�����̲ܶ���*/
#define configUSE_TICK_HOOK								( 0 )	           

/* ʹ���ڴ�����ʧ��HOOK���� */
#define configUSE_MALLOC_FAILED_HOOK					( 0 ) 

/*
 * ʹ�ö�ջ�����⹦��(һ�������ʹ��)
 * ���ʹ�ô˹��� �û������ṩһ��ջ���HOOK����
 * ���ʹ�õĻ���ֵ����Ϊ1����2 (������ջ�����ⷽ��) */
#define configCHECK_FOR_STACK_OVERFLOW					( 0 )


/* FreeRTOS ����ʱ�������״̬�ռ�������� */

/* ��������ʱ��ͳ�ƹ���(����ʹ��) */
#define configGENERATE_RUN_TIME_STATS		 	       	( 0 )                     
            
/* ���ÿ��ӻ����ٵ��� */
#define configUSE_TRACE_FACILITY				      	( 0 ) 

/* ���configUSE_TRACE_FACILITYͬʱΪ1ʱ���������3������
 * prvWriteNameToBuffer()
 * vTaskList()
 * vTaskGetRunTimeStats()*/
#define configUSE_STATS_FORMATTING_FUNCTIONS			( 1 )                      


/* FreeRTOS Э��������� */

/* ����Э�� ����Э���Ժ��������ļ�croutine.c */
#define configUSE_CO_ROUTINES 			          		( 0 )

/* Э�̵���Ч���ȼ���Ŀ */
#define configMAX_CO_ROUTINE_PRIORITIES       			( 2 )                   


/* FreeRTOS �����ʱ��������� */

/* ���������ʱ�� */
#define configUSE_TIMERS				            	( 0 )                              

/* �����ʱ�����ȼ� */
#define configTIMER_TASK_PRIORITY		      ( configMAX_PRIORITIES-1 )        

/* �����ʱ�����г��� */
#define configTIMER_QUEUE_LENGTH		        		( 10 )                              

/* �����ʱ�������ջ��С */
#define configTIMER_TASK_STACK_DEPTH	    ( configMINIMAL_STACK_SIZE*2 )    


/* ��ѡ�����ĺ�������(1:���� 0:������)
�»��ߺ�����Ŀ�꺯���ĺ����� */
#define INCLUDE_vTaskPrioritySet		1
#define INCLUDE_uxTaskPriorityGet		1
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	1
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1
#define INCLUDE_eTaskGetState		    1
#define INCLUDE_xTimerPendFunctionCall  0


/* FreeRTOS �ж�������� */

#ifdef __NVIC_PRIO_BITS
	#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       		4  
#endif

/* �ж�������ȼ� */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			15

/* ϵͳ�ɹ��������ж����ȼ� */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	5

#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
	
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }
	
#define vPortSVCHandler 				SVC_Handler
#define xPortPendSVHandler 				PendSV_Handler
#define xPortSysTickHandler 			SysTick_Handler


#endif /* FREERTOS_CONFIG_H */

