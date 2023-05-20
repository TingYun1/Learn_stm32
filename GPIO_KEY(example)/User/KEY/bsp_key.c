#include "bsp_key.h"

void KEY_GPIO_Init()
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	 
	RCC_APB2PeriphClockCmd(KEY_GPIO_CLK,ENABLE);
	GPIO_InitStruct.GPIO_Pin=KEY_GPIO_Pin;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	
	GPIO_Init(KEY_GPIO_PORT,&GPIO_InitStruct);
}

uint8_t Key_scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON)
	{
		//À… ÷ºÏ≤‚
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON);
		return KEY_ON;
	}
	else return KEY_OFF;
}
