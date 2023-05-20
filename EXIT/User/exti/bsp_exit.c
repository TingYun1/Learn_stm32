#include "bsp_exit.h"

static void EXTI_NVIC_Init(void)
{
	//3.配置中断优先级
	NVIC_InitTypeDef NVIC_InitStruct;
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);        //分组
	NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;  //主优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;         //子优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	
	 NVIC_Init(&NVIC_InitStruct);
}

void EXIT_KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//配置中断优先级
	EXTI_NVIC_Init();
	
	 //1.初始化GPIO
	RCC_APB2PeriphClockCmd(KEY_INT_GPIO_CLK,ENABLE);
	GPIO_InitStruct.GPIO_Pin=KEY_INT_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(KEY_INT_GPIO_PORT,&GPIO_InitStruct);
	
	
	//2.初始化EXTI
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO ,ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
	
	EXTI_InitStruct.EXTI_Line=EXTI_Line0;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	
	EXTI_Init(&EXTI_InitStruct);
}

