#include "stm32f10x.h"

int main()
{
	/*
	//��GPIOB�˿ڵ�ʱ��
	*(unsigned int *)0x40021018|=((1)<<3);
	//����IO��Ϊ���
	*(unsigned int *)0x40010C00|=((1)<<(4*0));
	//����ODR�Ĵ���
	*(unsigned int *)0x40010C0C&=~(1<<0);
	*/
	//��GPIOB�˿ڵ�ʱ��
	RCC_APB2ENR|=((1)<<3);
	//����IO��Ϊ���
	GPIOB_CRL&=~((0x0f)<<(4*0))
	GPIOB_CRL|=((1)<<(4*0));
	//����ODR�Ĵ���
	GPIOB_ODR&=~(1<<0);
}
void SystemInit()
{
	
}

