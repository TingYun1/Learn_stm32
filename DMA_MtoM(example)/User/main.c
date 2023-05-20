#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_dma_mtm.h"
#include "stm32f10x_gpio.h"

#define BUFFER_SIZE    32

extern const uint32_t aSRC_Const_Buffer[BUFFER_SIZE];

/*����DMA����Ŀ��洢��
 *�洢���ڲ���SRAM��
*/
extern uint32_t aDST_Buffer[BUFFER_SIZE];
void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main()
{
	uint8_t status=0;
	LED_GPIO_Init();
	MtM_DMA_Config();

	
	while(DMA_GetFlagStatus(DMA1_FLAG_TC6)==RESET);
	
	status= Buffercmp(aSRC_Const_Buffer,aDST_Buffer,BUFFER_SIZE);
	if(status==1)
	{
		LED(OFF);
	}
	else  LED(OFF);
	while(1)
	{

	}
}



