#ifndef __BSP_EXTI_H
#define __BSP_EXTI_H

#include "stm32f10x.h"

#define  KEY_INT_GPIO_PIN   GPIO_Pin_0
#define  KEY_INT_GPIO_PORT  GPIOA
#define  KEY_INT_GPIO_CLK   RCC_APB2Periph_GPIOA


void EXIT_KEY_Init(void);
static void EXTI_NVIC_Init(void);

#endif

