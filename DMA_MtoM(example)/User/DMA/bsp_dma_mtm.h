#ifndef __BSP_DMA_H
#define __BSP_DMA_H

#include "stm32f10x.h"

#define MTM_DMA_CLK     RCC_AHBPeriph_DMA1

void MtM_DMA_Config(void);
uint8_t Buffercmp(const uint32_t* pBuffer,uint32_t* pBuffer1,uint16_t BufferLength);
#endif

