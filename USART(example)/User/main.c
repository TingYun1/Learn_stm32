#include "stm32f10x.h"
#include "bsp_usart.h"
#include "stm32f10x_gpio.h"
#include "stdio.h"
void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main()
{
	//LED_GPIO_Init();
	//uint8_t arr[5]={1,2,3,4,5};
	char* str="asdf";
	USART_Config();
//	Usart_SendByte(DEBUG_USARTx,'A');
//	Usart_SendHalfWord(DEBUG_USARTx,0x56);
	//Usart_SendArr(DEBUG_USARTx,arr,5);
	Usart_SendStr(DEBUG_USARTx,"�ϵº�\n");
	printf("����USART��printf����\n");
	
	putchar("p");
	while(1)
	{
//	LED(ON);//GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
//	Delay(0xFFFFF);
//	LED(OFF);//GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);
//	Delay(0xFFFFF);
	}
}



