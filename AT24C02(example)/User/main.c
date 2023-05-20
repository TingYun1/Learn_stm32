#include "stm32f10x.h"
#include "bsp_usart.h"
#include "stm32f10x_gpio.h"
#include "stdio.h"
#include "bsp_IIC.h"




#include "stm32f10x.h"
#include "./led/bsp_led.h"
#include "bsp_usart.h"
#include "bsp_IIC.h"
#include <string.h>

#define  EEP_Firstpage      0x00
uint8_t I2c_Buf_Write[256];
uint8_t I2c_Buf_Read[256];
uint8_t I2C_Test(void);

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{ 
  /* ���ڳ�ʼ�� */
	USART_Config();
	
	printf("\r\n ����һ��I2C����(AT24C02)��д�������� \r\n");

	/* I2C �����(AT24C02)ʼ�� */
	I2C_EE_Init();

	printf("\r\n ����һ��I2C����(AT24C02)��д�������� \r\n");	
	 	 
  //EEPROM ��д����
	if(I2C_Test() ==1)
	{
			printf("\r\n YES\r\n");	
	}
	else
	{
			printf("\r\n NO \r\n");	
	}
  
  while (1)
  {      
  }
}

/**
  * @brief  I2C(AT24C02)��д����
  * @param  ��
  * @retval ��������1���쳣����0
  */
uint8_t I2C_Test(void)
{
	uint16_t i;

	printf("д�������\n\r");
    
	for ( i=0; i<=255; i++ ) //��仺��
  {   
    I2c_Buf_Write[i] = i;

    printf("0x%02X ", I2c_Buf_Write[i]);
    if(i%16 == 15)    
        printf("\n\r");    
   }

  //��I2c_Buf_Write��˳�����������д��EERPOM�� 
	I2C_EE_BufferWrite( I2c_Buf_Write, EEP_Firstpage, 256);
  
  EEPROM_INFO("\n\rд�ɹ�\n\r");
   
   EEPROM_INFO("\n\r����������\n\r");
  //��EEPROM��������˳�򱣳ֵ�I2c_Buf_Read��
	I2C_EE_BufferRead(I2c_Buf_Read, EEP_Firstpage, 256); 
   
  //��I2c_Buf_Read�е�����ͨ�����ڴ�ӡ
	for (i=0; i<256; i++)
	{	
		if(I2c_Buf_Read[i] != I2c_Buf_Write[i])
		{
			EEPROM_ERROR("0x%02X ", I2c_Buf_Read[i]);
			EEPROM_ERROR("����:I2C EEPROMд������������ݲ�һ��\n\r");
			return 0;
		}
    printf("0x%02X ", I2c_Buf_Read[i]);
    if(i%16 == 15)    
        printf("\n\r");
    
	}
  EEPROM_INFO("I2C(AT24C02)��д���Գɹ�\n\r");
  
  return 1;
}
/*
void Delay(uint32_t count)
{
	for(;count!=0;count--);
}
//1.��ʼ��IIC��ص�GPIO
//2.����IIC����Ĺ���ģʽ
//3.��дIICд��EEPROM��Byte write����
//4.��дIIC��ȡEEPROM��RANDOM Read����
//5.ʹ��read��write�������ж�дУ��

//6.��дpage write ��seq read������У��
uint8_t readData[10]={0};
int main()
{
	//LED_GPIO_Init();
	//uint8_t arr[5]={1,2,3,4,5};
//	char* str="asdf";
	USART_Config();
	IIC_Config();

//	Usart_SendByte(DEBUG_USARTx,'A');
//	Usart_SendHalfWord(DEBUG_USARTx,0x56);
	//Usart_SendArr(DEBUG_USARTx,arr,5);
	printf("����һ��IICͨѶʵ��\n");
	//��ʼ��IIC

	EEPROM_Byte_Write(11,0x55);
	
	EEPROM_WaitForWriteEnd();
	
	EEPROM_Read(11,readData,1);
	
	printf("���յ�������Ϊ0x%x\r\n",readData[0]);
	
	
	while(1)
	{
//	LED(ON);//GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
//	Delay(0xFFFFF);
//	LED(OFF);//GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);
//	Delay(0xFFFFF);
	}
}

*/

