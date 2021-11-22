/**
  ******************************************************************************
  * @file    led.c
  * @author  Wu
  * @version V0.0
  * @date    3-September-2019
  * @brief   This file config the led to work status.				
  *
  ******************************************************************************
  */
#include "config.h"

/* 
  * LED GPIO ≈‰÷√ 
  */
void vLedGpioConfig( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);

	LED1_OFF;	
	LED2_OFF;
}


/* END */
