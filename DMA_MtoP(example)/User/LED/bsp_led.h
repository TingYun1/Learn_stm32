#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"

#define  LED_GPIO_PIN   GPIO_Pin_5
#define  LED_GPIO_PORT  GPIOB
#define  LED_GPIO_CLK   RCC_APB2Periph_GPIOC

#define  ON             1
#define  OFF            0

#define LED(a)          if(a) GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);else GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
void LED_GPIO_Init(void);
#endif

