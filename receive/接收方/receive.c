#include <reg52.h>

#define SEG_DATA_Port	P0

unsigned char NixieTable[]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
void UART_Init(void)
{
	SCON=0x50;
	PCON |= 0x80;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TL1 = 0xF3;
	TH1 = 0xF3;
	ET1 = 0;
	TR1 = 1;
	EA=1;
	ES=1;
}


void Nixie_Data_Out(unsigned char num)
{
	SEG_DATA_Port = NixieTable[num];
}

void Nixie_Display(unsigned char num)
{
	Nixie_Data_Out(num);
}


unsigned char key_num = 0;

void main()
{
	UART_Init();
	P1=0xFF;
	while(1)
	{
		if(key_num!=16)
		{
			Nixie_Display(key_num);
			key_num=16;
		}
	}
}

void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		key_num = SBUF;
		SBUF=16;
		RI=0;
	}
}