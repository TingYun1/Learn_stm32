#include <stm32f10x.h>
#include "bsp_led.h"
int main()
{
	GPIO_LED_Init();
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);

}



