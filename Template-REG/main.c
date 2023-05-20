#include "stm32f10x.h"

int main()
{
	/*
	//打开GPIOB端口的时钟
	*(unsigned int *)0x40021018|=((1)<<3);
	//配置IO口为输出
	*(unsigned int *)0x40010C00|=((1)<<(4*0));
	//控制ODR寄存器
	*(unsigned int *)0x40010C0C&=~(1<<0);
	*/
	//打开GPIOB端口的时钟
	RCC_APB2ENR|=((1)<<3);
	//配置IO口为输出
	GPIOB_CRL&=~((0x0f)<<(4*0))
	GPIOB_CRL|=((1)<<(4*0));
	//控制ODR寄存器
	GPIOB_ODR&=~(1<<0);
}
void SystemInit()
{
	
}

