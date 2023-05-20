#include "stm32f10x.h"
#include "bsp_led.h"
#include "core_cm3.h"
#include "bsp_systick.h"
#include "stm32f10x_gpio.h"
void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main()
{
	LED_GPIO_Init();
	while(1)
	{
	LED(ON);//GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
	SysTick_Delay_ms(1000);
	LED(OFF);//GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);
	SysTick_Delay_ms(1000);
	}
}


//static __INLINE uint32_t SysTick_Config(uint32_t ticks)
//{ 
//	//判断tick的值是否大于2^24-1，如果大于则不符合规则
//  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* Reload value impossible */
//  
//	//初始化reload寄存器的值
//  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
//	
//	//配中断优先级,配置为15，优先级为最低
//  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M0 System Interrupts */
//	//配置counter计数器的值为0
//  SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */

		//配置systick的时钟为72M
    //使能中断
		//使能systick
//  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
//                   SysTick_CTRL_TICKINT_Msk   | 
//                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
//  return (0);                                                  /* Function successful */
//}




