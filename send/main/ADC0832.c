# include <intrins.h>
#include "ADC0832.h"
#include "LCD1602.h"


sbit ADC0832_CS = P3^2;
sbit ADC0832_CLK = P3^3;
sbit ADC0832_DI = P3^4;
sbit ADC0832_DO = P3^4;

void ADC0832_Init(void)
{
	ADC0832_CS = 1;
	ADC0832_CLK = 0;
	ADC0832_DI = 1;
}

unsigned char ADC0832_receive(void)
{
	int i;
	unsigned char result_h, result_l; 
	ADC0832_Init();
	ADC0832_CS = 0;//启动片选
	ADC0832_CLK = 1;
	ADC0832_CLK = 0;//启动转换(第一个脉冲，初始化时DI始终为高，满足要求)
	 
	ADC0832_DI = 1;
	ADC0832_CLK = 1;
	ADC0832_CLK = 0;
	ADC0832_DI = 0;
	ADC0832_CLK = 1;
	ADC0832_CLK = 0;//选择单端输入，通道0

	ADC0832_DO = 1;//准备接受数据

	for(i = 0;i < 8; i++)
	{
		ADC0832_CLK = 1;
	 	ADC0832_CLK = 0;
		result_h <<= 1;
		if(ADC0832_DO == 1)	result_h += 1;
	}
	for(i = 0;i < 8; i++)
	{			
		result_l >>= 1;
		if(ADC0832_DO == 1)	result_l |= 0x80;
		ADC0832_CLK = 1;
	 	ADC0832_CLK = 0;

	}
	ADC0832_CLK = 1;
	ADC0832_DO = 1;
	ADC0832_CS = 1;//恢复正常状态
	if(result_l == result_h ) 
	return result_h;
}

void ADC0832_Display(void)
{ 
	
	unsigned char ad_result;
	unsigned char VShow[16] = {"voltage:      V "};
	ad_result =  ADC0832_receive() * 500 / 255;
	VShow[9] = ad_result / 100 + '0';
	VShow[10] = '.';
	VShow[11] = ad_result / 10 % 10 + '0';
	VShow[12] = ad_result % 10 + '0';
	LCD_print(0,1,VShow);
}
