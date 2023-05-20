#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

#define LED_GPIO_PORT         GPIOB
#define LED_GPIO_CLK_ENABLE   (RCC->APB2ENR|=((1)<<3))
#define LED_GPIO_PIN           GPIO_Pin_0

void Delay(uin32_t count)
{
	for(;count!=0;conut--);
}
int main()
{
	GPIO_InitTypeDef* GPIO_InitStructure;
	/*
		//��GPIOC�˿ڵ�ʱ��
		*(unsigned int *)0x40021018|=((1)<<4);
		//����IO��Ϊ���
		*(unsigned int *)0x40011004|=((1)<<(4*5));
		//����ODR�Ĵ���
		*(unsigned int *)0x4001100C&=(1<<13);
	*/
	
	/*
	//��GPIOB�˿ڵ�ʱ��
	RCC_APB2ENR|=((1)<<3);
	//����IO��Ϊ���
	GPIOB_CRL&=~((0x0f)<<(4*0));
	GPIOB_CRL|=((1)<<(4*0));
	//����ODR�Ĵ���
	GPIOB_ODR&=~(1<<0);
	*/
	
	/*
	//��GPIOB�˿ڵ�ʱ��
	RCC->APB2ENR|=((1)<<3);
	//����IO��Ϊ���
	GPIOB->CRL&=~((0x0f)<<(4*0));
	GPIOB->CRL|=((1)<<(4*0));
	//����ODR�Ĵ���
	GPIOB->ODR&=~(1<<0);
	*/
	
	
	LED_GPIO_CLK_ENABLE;
	
	GPIO_InitStructure->GPIO_Pin=LED_GPIO_PIN;
	GPIO_InitStructure->GPIO_Mode=GPIO_Mode_Out_pp;
	GPIO_InitStructure->GPIO_Speed=GPIO_Speed_50MHZ;
	GPIO_Init(LED_GPIO_PORT,GPIO_InitStructure);
	
	while(1)
	{
		GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
		Delay(0xFFFF);
		GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);
		Delay(0xFFFF);
	}
}
void SystemInit()
{
	
}

