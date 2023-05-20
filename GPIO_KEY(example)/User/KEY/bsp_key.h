#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32f10x.h"

#define  KEY_GPIO_Pin   GPIO_Pin_0
#define  KEY_GPIO_PORT  GPIOA
#define  KEY_GPIO_CLK   RCC_APB2Periph_GPIOA

#define KEY_ON           1
#define KEY_OFF          0

void KEY_GPIO_Init(void);
uint8_t Key_scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

#endif
