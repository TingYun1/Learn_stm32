#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "stm32f10x_gpio.h"
void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main()
{
	LED_GPIO_Init();
	KEY_GPIO_Init();
	while(1)
	{
		if(Key_scan(KEY_GPIO_PORT,KEY_GPIO_Pin)==KEY_ON)
		{
			LED_TOGGLE
		}
//		else
//		{
//			LED(OFF);
//		}
//	LED(ON);//GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
//	Delay(0xFFFFF);
//	LED(OFF);//GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);
//	Delay(0xFFFFF);
	}
}



