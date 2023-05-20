#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_led.h"
#include "stm32f10x_gpio.h"
#include "stdio.h"
void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main()
{
	
	//uint8_t arr[5]={1,2,3,4,5};
	//char* str="asdf";
	uint8_t ch;
	
	LED_GPIO_Init();
	USART_Config();
//	Usart_SendByte(DEBUG_USARTx,'A');
//	Usart_SendHalfWord(DEBUG_USARTx,0x56);
	//Usart_SendArr(DEBUG_USARTx,arr,5);
	//Usart_SendStr(DEBUG_USARTx,"ÃÏµÂºÀ\n");
	printf("´®¿ÚUSARTµÄprintf²âÊÔ\n");
	
	while(1)
	{
//	LED(ON);//GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
//	Delay(0xFFFFF);
//	LED(OFF);//GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);
//	Delay(0xFFFFF);
		ch=getchar();
		printf("ch=%c\n",ch);
		if(ch=='1') 
		{
			LED(ON);
		}
		else if(ch=='3')
		{
			LED(OFF);
		}
	}
}



