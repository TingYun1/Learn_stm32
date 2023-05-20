#include "bsp_usart.h"
#include "stdio.h"

//static void NVIC_Configuration(void)
//{
//	NVIC_InitTypeDef NVIC_InitStructure;
//	
//	//Ƕ�������жϿ�������ѡ��
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//	
//	//����USART�ж�Դ
//	NVIC_InitStructure.NVIC_IRQChannel=DEBUG_USART_IRQ;
//	//�������ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
//	//�����ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
//	//ʹ���ж�
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	//��ʼ������NVIC
//	NVIC_Init(&NVIC_InitStructure);
//}
void USART_Config()
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	USART_InitTypeDef USART_InitStructure; 
	
	//��GPIOʱ��
	RCC_APB2PeriphClockCmd(DEBUG_USART_GPIO_CLK,ENABLE);
	
	//������ʱ��
	DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK,ENABLE);
	
	//��USART Tx��GPIO����Ϊ���츴��ģʽ
	GPIO_InitStruct.GPIO_Pin=DEBUG_USART_TX_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT,&GPIO_InitStruct);
	
	//��USART Rx��GPIO����Ϊ��������ģʽ
	GPIO_InitStruct.GPIO_Pin=DEBUG_USART_RX_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT,&GPIO_InitStruct);


   //���ô��ڵĹ�������
   //���ò�����
  USART_InitStructure.USART_BaudRate=DEBUG_USART_BAUDRATE;
	//�����������ֳ�
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	//����ֹͣλ
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	//����У��λ
	USART_InitStructure.USART_Parity=USART_Parity_No;
	//����Ӳ��������
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	//���ù���ģʽ���շ�һ��
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	//��ɴ��ڵĳ�ʼ������
	USART_Init(DEBUG_USARTx,&USART_InitStructure);
	
//	//�����ж����ȼ�����
//	NVIC_Configuration();
//	
//	//ʹ�ܴ��ڽ����ж�
//	USART_ITConfig(DEBUG_USARTx,USART_IT_RXNE,ENABLE);
	
	//ʹ�ܴ���
	USART_Cmd(DEBUG_USARTx,ENABLE);
}


//����һ���ֽ�
void Usart_SendByte(USART_TypeDef* pUSARTx,uint8_t data)
{
	USART_SendData(pUSARTx,data);
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE)==RESET);
}


//���������ֽڵ�����
void Usart_SendHalfWord(USART_TypeDef* pUSARTx,uint16_t data)
{
	uint8_t temp_h,temp_l;
	
	temp_h=(data&0xff00) >> 8;
	temp_l=(data&0xff);
	USART_SendData(pUSARTx,temp_h);
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE)==RESET);
	USART_SendData(pUSARTx,temp_l);
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE)==RESET);
}

//����8λ���ݵ�����
void Usart_SendArr(USART_TypeDef* pUSARTx,uint8_t* arr,uint8_t num)
{
	uint8_t i;
	for(i=0;i<num;i++)
	{
		Usart_SendByte(pUSARTx,arr[i]);
	  
	}
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);
}

//�����ַ���
void Usart_SendStr(USART_TypeDef* pUSARTx,char* str)
{
	while(*str!='\0')
	{
		Usart_SendByte(pUSARTx,*str);
		str++;
	}
}
//�ض���printf
int fputc(int ch,FILE *f)
{
	USART_SendData(DEBUG_USARTx,(uint8_t) ch);
	
	while(USART_GetFlagStatus(DEBUG_USARTx,USART_FLAG_TXE)==RESET);
	
	return (ch);
}

//�ض���printf
int fgetc(FILE *f)
{
	
	while(USART_GetFlagStatus(DEBUG_USARTx,USART_FLAG_RXNE)==RESET);
	
	return (int)USART_ReceiveData(DEBUG_USARTx);
}

