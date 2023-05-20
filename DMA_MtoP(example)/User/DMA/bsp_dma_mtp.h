#ifndef __BSP_DMA_H
#define __BSP_DMA_H

#include "stm32f10x.h"
#include <stdio.h>

#define DEBUG_USARTx                 USART2
#define DEBUG_USART_CLK              RCC_APB1Periph_USART2
#define DEBUG_USART_APBxClkCmd       RCC_APB1PeriphClockCmd
#define DEBUG_USART_BAUDRATE         115200


#define DEBUG_USART_GPIO_CLK        (RCC_APB2Periph_GPIOA)
#define DEBUG_USART_GPIO_APBxClkCmd  RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT     GPIOA
#define DEBUG_USART_TX_GPIO_PIN      GPIO_Pin_2
#define DEBUG_USART_RX_GPIO_PORT     GPIOA
#define DEBUG_USART_RX_GPIO_PIN      GPIO_Pin_3

#define MTM_DMA_CLK                  RCC_AHBPeriph_DMA1
#define USART_DR_ADDRESS             (USART2_BASE+0x04)

#define SENDBUFF_SIZE                5000

void USART_Config(void);
void USART_DMA_Config(void);

#endif
