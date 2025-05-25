#include <reg52.h>
#include "DHT11.h"
#include "LCD1602.h"
#include "send.h"
#include "adc0832.h"
#include "dianji.h"
#include "MatrixKey.h"

unsigned char key_num = 0;
unsigned char display_flag = 7;
unsigned char display_mode = 17;
unsigned char key_val,key_old;
void main()
{	
	UART_Init();
	LCD_Init();
	while(1)
	{
		key_val=MatrixKey();
		key_num=key_val&(key_val^key_old);
		key_old=key_val;
		
		if(key_num!=0){
			key_num--;
       LCD_Init();
		if(key_num!=display_mode)
		{
			display_mode=key_num;
		  UART_SendByte(key_num);
		}
		else if(key_num==display_mode)
		{
			display_flag=key_num;
			
		}
	}
		
			if (display_flag == 0)
			{
				DHT11_Display();
			}
			else if (display_flag == 1)
			{
				ADC0832_Display();
			}
      else if (display_flag == 1)
			{
				ADC0832_Display();
			}
			else if (display_flag == 2)
			{
				name();
			}
			else if (display_flag == 4)
			{
				zz(3);
			}
			else if (display_flag == 5)
			{
				fz(3);
			}
			else if (display_flag == 6)
			{
				kz(3);
			}
			else if (display_flag == 7)
			{
				mz(3);
			}

	}

}