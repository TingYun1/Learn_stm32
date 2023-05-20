#ifndef __BSP_RCCCLKCONFIG_H
#define __BSP_RCCCLKCONFIG_H

#include "stm32f10x.h"
#include "core_cm3.h"

void HSE_SetSysClk(uint32_t RCC_PLLMul_x);
void MCO_GPIO_Config(void);
void HSI_SetSysClk(uint32_t RCC_PLLMul_x);
#endif
