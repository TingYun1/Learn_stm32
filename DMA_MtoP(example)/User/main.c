#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_dma_mtp.h"
#include "stm32f10x_gpio.h"

extern uint8_t SendBuff[SENDBUFF_SIZE];
void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main()
{
	LED_GPIO_Init();
	for(uint16_t i=0;i<SENDBUFF_SIZE;i++)
	{
		SendBuff[i]='P';
	}
	USART_DMA_Config();
	
	USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
	while(1)
	{
//	LED(ON);//GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
//	Delay(0xFFFFF);
//	LED(OFF);//GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);
//	Delay(0xFFFFF);
	}
}



