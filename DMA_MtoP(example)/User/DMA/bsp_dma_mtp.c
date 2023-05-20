#include "bsp_dma_mtp.h"

uint8_t SendBuff[SENDBUFF_SIZE];
void USART_Config()
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	USART_InitTypeDef USART_InitStructure; 
	
	//打开GPIO时钟
	RCC_APB2PeriphClockCmd(DEBUG_USART_GPIO_CLK,ENABLE);
	
	//打开外设时钟
	DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK,ENABLE);
	
	//将USART Tx的GPIO配置为推挽复用模式
	GPIO_InitStruct.GPIO_Pin=DEBUG_USART_TX_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT,&GPIO_InitStruct);
	
	//将USART Rx的GPIO配置为浮空输入模式
	GPIO_InitStruct.GPIO_Pin=DEBUG_USART_RX_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT,&GPIO_InitStruct);


   //配置串口的工作参数
   //配置波特率
  USART_InitStructure.USART_BaudRate=DEBUG_USART_BAUDRATE;
	//P配置针数据字长
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	//配置停止位
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	//配置校验位
	USART_InitStructure.USART_Parity=USART_Parity_No;
	//配置硬件流控制
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	//配置工作模式，收发一起
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	//完成串口的初始化配置
	USART_Init(DEBUG_USARTx,&USART_InitStructure);
	
	//串口中断优先级配置
//	NVIC_Configuration();
	
	//使能串口接收中断
	//USART_ITConfig(DEBUG_USARTx,USART_IT_RXNE,ENABLE);
	
	//使能串口
	USART_Cmd(DEBUG_USARTx,ENABLE);
}


int fputc(int ch,FILE *f)
{
	USART_SendData(DEBUG_USARTx,(uint8_t) ch);
	
	while(USART_GetFlagStatus(DEBUG_USARTx,USART_FLAG_TXE)==RESET);
	
	return (ch);
}


void USART_DMA_Config(void)
{
	DMA_InitTypeDef DMA_InitStruct;
	
	RCC_AHBPeriphClockCmd(MTM_DMA_CLK,ENABLE);
	
	DMA_InitStruct.DMA_PeripheralBaseAddr=(uint32_t)USART_DR_ADDRESS;
	DMA_InitStruct.DMA_MemoryBaseAddr=(uint32_t)SendBuff;
	DMA_InitStruct.DMA_DIR=DMA_DIR_PeripheralDST;
	
	DMA_InitStruct.DMA_BufferSize=SENDBUFF_SIZE;
	DMA_InitStruct.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
	DMA_InitStruct.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
	
	DMA_InitStruct.DMA_MemoryInc=DMA_MemoryInc_Enable;
	DMA_InitStruct.DMA_MemoryDataSize=DMA_PeripheralDataSize_Byte;
	DMA_InitStruct.DMA_Mode=DMA_Mode_Normal;
	DMA_InitStruct.DMA_Priority=DMA_Priority_High;
	DMA_InitStruct.DMA_M2M=DMA_M2M_Disable;
	
	DMA_Init(DMA1_Channel7,&DMA_InitStruct);
	
	DMA_ClearFlag(DMA1_FLAG_TC7);
	DMA_Cmd(DMA1_Channel7,ENABLE);
}

