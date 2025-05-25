#include <reg52.h>
#include "LCD1602.h"
#include "DHT11.h"


unsigned char DHT11_Tem[4];
unsigned char DHT11_Hmd[4];

void DHT11_delay_us(unsigned char n)
{
    while(--n);
}
unsigned int DHT11_delay_ms(unsigned int z)
{
   unsigned int i,j;
   for(i=z;i>0;i--)
      for(j=110;j>0;j--);
	return 1;
}
void DHT11_start(void)
{
   Data=1;
   DHT11_delay_us(2);
   Data=0;
   DHT11_delay_ms(30);   
   Data=1;
   DHT11_delay_us(30);
}
unsigned char DHT11_rec_byte(void)      
{
   unsigned char i,dat=0;
  for(i=0;i<8;i++)    
   {          
      while(!Data);   
      DHT11_delay_us(8);    
      dat<<=1;           
      if(Data==1)    
         dat+=1;
      while(Data);     
    }  
    return dat;
}
void DHT11_receive(void)     
{
    unsigned char R_H,R_L,T_H,T_L,RH,RL,TH,TL,revise; 
    DHT11_start();
    if(Data==0)
    {
        while(Data==0);       
        DHT11_delay_us(40);  
        R_H=DHT11_rec_byte();      
        R_L=DHT11_rec_byte();     
        T_H=DHT11_rec_byte();     
        T_L=DHT11_rec_byte();    
        revise=DHT11_rec_byte(); 
        DHT11_delay_us(25);    
        if((R_H+R_L+T_H+T_L)==revise)      
        {
            RH=R_H;
            RL=R_L;
            TH=T_H;
            TL=T_L;
        }  
        DHT11_Tem[0]='0'+(RH/10);
        DHT11_Tem[1]='0'+(RH%10);
				DHT11_Tem[2]=' ';
				DHT11_Tem[3]=' ';
        DHT11_Hmd[0]='0'+(TH/10);
        DHT11_Hmd[1]='0'+(TH%10); 
		    DHT11_Hmd[2]=' ';
    }
}



void DHT11_Display(void)
{
  //LCD_Init();
	DHT11_receive();
	LCD_ShowString(0, 2, "sd:");
	LCD_ShowString(1, 2, "wd:");
	LCD_ShowString(0, 10,DHT11_Tem);
	LCD_ShowString(0, 13,"%   ");
	LCD_ShowString(1, 10,DHT11_Hmd);
  LCD_ShowString(1, 12," C   ");
}